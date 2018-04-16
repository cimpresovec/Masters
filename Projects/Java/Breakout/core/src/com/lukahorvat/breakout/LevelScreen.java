package com.lukahorvat.breakout;

import com.badlogic.gdx.*;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class LevelScreen extends InputAdapter implements Screen
{
    private SpriteBatch batch;
    private AssetManager assetManager;

    private BreakoutPad pad;
    private List<BreakoutWall> walls;
    private List<BreakoutBrick> bricks;
    private BreakoutBall ball;


    public LevelScreen(AssetManager assetManager)
    {
        this.assetManager = assetManager;
        batch = new SpriteBatch();

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
            //TODO Implement transition
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
        ball.finishMoving();

        //Brick handling
        Iterator itr = bricks.iterator();
        while (itr.hasNext())
        {
            BreakoutBrick brick = (BreakoutBrick)itr.next();
            if (brick.shouldDestroy())
            {
                itr.remove();
            }
        }

        //Rendering
        Gdx.gl.glClearColor(1, 1, 1, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        batch.begin();
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
        batch.end();
    }

    @Override
    public void resize(int width, int height) {

    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void hide() {

    }

    @Override
    public void dispose() {

    }
}
