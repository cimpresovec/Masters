package com.lukahorvat.breakout;

import com.badlogic.gdx.*;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.GlyphLayout;
import com.badlogic.gdx.graphics.g2d.freetype.FreeTypeFontGenerator;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

import java.awt.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class LevelScreen extends GameScreen
{
    private BreakoutPad pad;
    private List<BreakoutWall> walls;
    private List<BreakoutBrick> bricks;
    private BreakoutBall ball;
    private BitmapFont font;


    public LevelScreen(AssetManager manager, Game game)
    {
        super(manager, game);

        //Font
        FreeTypeFontGenerator generator = new FreeTypeFontGenerator(Gdx.files.internal("DejaVuSansMono.ttf"));
        FreeTypeFontGenerator.FreeTypeFontParameter parameter = new FreeTypeFontGenerator.FreeTypeFontParameter();
        parameter.size = 30;
        font = generator.generateFont(parameter);
        font.setColor(Color.BLACK);
        generator.dispose();

        //Objects
        pad = new BreakoutPad();
        ball = new BreakoutBall();
        ball.setAssetManager(assetManager);

        //Walls
        walls = new ArrayList<BreakoutWall>();
        walls.add(new BreakoutWall(new Rectangle(0, 80, 10, 640)));
        walls.add(new BreakoutWall(new Rectangle(0, 710, 1280, 10)));
        walls.add(new BreakoutWall(new Rectangle(1270, 80, 10, 640)));

        //Bricks
        bricks = new ArrayList<BreakoutBrick>();
        for (int y = 590; y > 300; y -= 50)
            for (int x = 50; x < 1250; x += 100)
            {
                bricks.add(new BreakoutBrick(new Vector2(x, y)));
            }
//        bricks.add(new BreakoutBrick(new Vector2(50, 50)));

        InputMultiplexer inputMultiplexer = new InputMultiplexer();
        inputMultiplexer.addProcessor(this);
        inputMultiplexer.addProcessor(pad);
        inputMultiplexer.addProcessor(ball);
        Gdx.input.setInputProcessor(inputMultiplexer);
    }

    @Override
    public boolean keyDown(int keycode) {
        if (keycode == Input.Keys.ESCAPE)
        {
            this.setNextGameScreen(GameScreens.STATE_MAINMENU);
            return true;
        }
        return false;
    }

    @Override
    public void show() {

    }

    @Override
    public void render(float deltaTime) {
        //Logic handling
        pad.handleLogic(deltaTime);

        //Ball movement
        ball.startMoving(deltaTime);
        ball.checkCollisionAgainstWalls(walls);
        ball.checkCollisionAgainstBricks(bricks);
        ball.checkCollisionAgainstPlayer(pad);
        numberOfLives = ball.finishMoving(numberOfLives);

        //Brick handling
        Iterator itr = bricks.iterator();
        while (itr.hasNext())
        {
            BreakoutBrick brick = (BreakoutBrick)itr.next();
            if (brick.shouldDestroy())
            {
                itr.remove();
                score += 10;
            }
        }
        if (bricks.size() == 0)
        {
            currentLevel++;
            this.setNextGameScreen(GameScreens.STATE_LEVEL);
        }

        //Rendering
        Gdx.gl.glClearColor(1, 1, 1, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        batch.setProjectionMatrix(camera.combined);
        batch.begin();

        GlyphLayout layout = new GlyphLayout();
        layout.setText(font, "Lives: " + (numberOfLives < 0? 0 : numberOfLives));
        font.draw(batch, layout, 10, layout.height + 10);

        layout.setText(font, "Score: " + score);
        font.draw(batch, layout, 1270 - layout.width, layout.height + 10);

        layout.setText(font, "Level " + currentLevel);
        font.draw(batch, layout, 640 - layout.width / 2, layout.height + 10);

        pad.render(batch, assetManager);
        ball.render(batch, assetManager);
        for (BreakoutWall wall : walls)
        {
            wall.render(batch, assetManager);
        }
        for (BreakoutBrick brick : bricks)
        {
            brick.render(batch, assetManager);
        }

        if (numberOfLives < 0)
        {
            layout.setText(font, "GAME OVER");
            font.draw(batch, layout, 640 - layout.width / 2, layout.height + 200);
        }

        batch.end();

        super.render(deltaTime);
    }

    @Override
    public void dispose() {

    }
}
