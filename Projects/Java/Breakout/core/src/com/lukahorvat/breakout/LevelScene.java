package com.lukahorvat.breakout;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class LevelScene implements Screen
{
    SpriteBatch batch;
    BreakoutPad pad;
    AssetManager assetManager;

    public LevelScene(AssetManager assetManager)
    {
        this.assetManager = assetManager;
        batch = new SpriteBatch();
        pad = new BreakoutPad();

        InputMultiplexer plexer = new InputMultiplexer();
        plexer.addProcessor(pad);
        Gdx.input.setInputProcessor(plexer);
    }

    @Override
    public void show() {

    }

    @Override
    public void render(float delta) {
        //Logic handling
        pad.handleLogic(delta);

        //Rendering
        Gdx.gl.glClearColor(1, 1, 1, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        batch.begin();
        pad.render(batch, assetManager);
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
