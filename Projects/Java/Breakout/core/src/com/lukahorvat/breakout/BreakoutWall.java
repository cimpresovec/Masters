package com.lukahorvat.breakout;

import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Rectangle;

public class BreakoutWall {
    private Rectangle collisionRectangle;

    public BreakoutWall(Rectangle rect)
    {
        collisionRectangle = new Rectangle(rect);
    }

    public void render(SpriteBatch batch, AssetManager manager) {
        batch.setColor(Color.BLUE);
        batch.draw(manager.get("wall.png", Texture.class), collisionRectangle.x, collisionRectangle.y, collisionRectangle.width, collisionRectangle.height);
        batch.setColor(Color.WHITE);
    }

    public Rectangle getCollisionRectangle() {
        return collisionRectangle;
    }
}
