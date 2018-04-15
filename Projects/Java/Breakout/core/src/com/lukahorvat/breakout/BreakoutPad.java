package com.lukahorvat.breakout;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

public class BreakoutPad extends InputAdapter {

    private Rectangle renderRectangle;
    private float horizontalSpeed = 500;
    private Vector2 velocity = new Vector2(0, 0);
    private boolean keyLeft = false, keyRight = false, keyShoot = false;

    public BreakoutPad()
    {
        renderRectangle = new Rectangle(1280 / 2, 55, 150, 30);
    }

    @Override
    public boolean keyDown(int keycode) {
        if (keycode == Input.Keys.LEFT)
        {
            keyLeft = true;
            return true;
        }
        else if (keycode == Input.Keys.RIGHT)
        {
            keyRight = true;
            return true;
        }
        return false;
    }

    @Override
    public boolean keyUp(int keycode) {
        if (keycode == Input.Keys.LEFT)
        {
            keyLeft = false;
            return true;
        }
        else if (keycode == Input.Keys.RIGHT)
        {
            keyRight = false;
            return true;
        }
        return false;
    }

    public void handleLogic(float deltaTime)
    {
        velocity.set(0, 0);
        if (keyLeft) velocity.x += -horizontalSpeed;
        if (keyRight) velocity.x += horizontalSpeed;

        renderRectangle.x += velocity.x * deltaTime;

        renderRectangle.x = Math.min(renderRectangle.x, 1280 - renderRectangle.width);
        renderRectangle.x = Math.max(renderRectangle.x, 0);
    }

    public void render(SpriteBatch batch, AssetManager manager) {
        batch.setColor(Color.RED);
        batch.draw(manager.get("pad.png", Texture.class), renderRectangle.x, renderRectangle.y, renderRectangle.width, renderRectangle.height);
    }
}
