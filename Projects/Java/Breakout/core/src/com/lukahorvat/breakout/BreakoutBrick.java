package com.lukahorvat.breakout;

import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.MathUtils;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

public class BreakoutBrick {
    private Rectangle collisionRectangle = new Rectangle(0, 0, 80, 30);
    private Color color;
    private boolean _shouldDestroy = false;

    public BreakoutBrick(Vector2 position)
    {
        collisionRectangle.x = position.x;
        collisionRectangle.y = position.y;
        color = new Color(MathUtils.random(),MathUtils.random(),MathUtils.random(),1);
    }

    public void render(SpriteBatch batch, AssetManager manager) {
        batch.setColor(color);
        batch.draw(manager.get("brick.png", Texture.class), collisionRectangle.x, collisionRectangle.y, collisionRectangle.width, collisionRectangle.height);
        batch.setColor(Color.WHITE);
    }

    public Rectangle getCollisionRectangle() {
        return collisionRectangle;
    }

    public void destroy() {
        _shouldDestroy = true;
    }

    public boolean shouldDestroy()
    {
        return _shouldDestroy;
    }
}
