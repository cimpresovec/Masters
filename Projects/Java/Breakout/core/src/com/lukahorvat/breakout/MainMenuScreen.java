package com.lukahorvat.breakout;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.math.Vector3;

import java.awt.*;

public class MainMenuScreen extends GameScreen {
    Rectangle playButton = new Rectangle(640 - 150, 300, 300, 100);
    Rectangle exitButton = new Rectangle(640 - 150, 100, 300, 100);

    MainMenuScreen(AssetManager manager, Game game) {
        super(manager, game);
    }

    @Override
    public void show() {

    }

    @Override
    public boolean keyDown(int keycode) {
        if (keycode == Input.Keys.ESCAPE) {
            this.setNextGameScreen(GameScreens.STATE_EXIT);
            return true;
        }
        if (keycode == Input.Keys.ENTER) {
            this.setNextGameScreen(GameScreens.STATE_LEVEL);
            currentLevel = 1;
            numberOfLives = 3;
            score = 0;
            return true;
        }
        return false;
    }

    @Override
    public boolean touchDown(int screenX, int screenY, int pointer, int button) {
        if (playButton.contains(camera.unproject(new Vector3(screenX, screenY, 0)).x, camera.unproject(new Vector3(screenX, screenY, 0)).y))
        {
            setNextGameScreen(GameScreens.STATE_LEVEL);
            currentLevel = 1;
            numberOfLives = 3;
            score = 0;
            return true;
        }
        if (exitButton.contains(camera.unproject(new Vector3(screenX, screenY, 0)).x, camera.unproject(new Vector3(screenX, screenY, 0)).y))
        {
            setNextGameScreen(GameScreens.STATE_EXIT);
            return true;
        }
        return false;
    }

    @Override
    public void render(float delta) {

        //Rendering
        Gdx.gl.glClearColor(1, 1, 1, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        batch.setProjectionMatrix(camera.combined);
        batch.begin();
        batch.draw(assetManager.get("breakout.png", Texture.class), 1280 / 2 - 800 / 2, 720 - 230, 800, 200);
        batch.draw(assetManager.get("menuFiller1.png", Texture.class), 100, 120, 180, 200);
        batch.draw(assetManager.get("menuFiller2.png", Texture.class), 1000, 100, 250, 250);
        batch.draw(assetManager.get("playButton.png", Texture.class), playButton.x, playButton.y , playButton.width, playButton.height);
        batch.draw(assetManager.get("exitButton.png", Texture.class), exitButton.x, exitButton.y, exitButton.width, exitButton.height);
        batch.end();

        super.render(delta);
    }
}
