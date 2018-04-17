package com.lukahorvat.breakout;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.math.Interpolation;

public class TitleScreen extends GameScreen {
    private float timer = 0;
    private float alpha = 0;

    TitleScreen(AssetManager manager, Game game) {
        super(manager, game);
    }

    @Override
    public boolean keyDown(int keycode) {
        this.setNextGameScreen(GameScreens.STATE_MAINMENU);
        return true;
    }

    @Override
    public void render(float delta) {
        //Logic handling

        //Simple animation
        timer += delta;
        if (timer < 1)
        {
            alpha = Interpolation.sineOut.apply(0, 1, timer);
        }
        else if (timer < 3)
        {
            alpha = Interpolation.sineOut.apply(1, 0, (timer - 1) / 2);
        }
        else
        {
            this.setNextGameScreen(GameScreens.STATE_MAINMENU);
        }

        //Rendering
        Gdx.gl.glClearColor(1, 1, 1, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        batch.setProjectionMatrix(camera.combined);
        batch.begin();
        batch.setColor(1, 1, 1, alpha);
        batch.draw(assetManager.get("logo.png", Texture.class),
                1280 / 2 - assetManager.get("logo.png", Texture.class).getWidth() / 2,
                720 / 2 - assetManager.get("logo.png", Texture.class).getHeight() / 2);
        batch.end();

        super.render(delta);
    }
}
