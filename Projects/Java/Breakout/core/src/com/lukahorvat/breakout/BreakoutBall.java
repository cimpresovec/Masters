package com.lukahorvat.breakout;

import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.audio.Sound;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Circle;
import com.badlogic.gdx.math.Intersector;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

import java.util.List;

public class BreakoutBall extends InputAdapter {
    private Vector2 position = new Vector2(500, 50);
    private Vector2 expectedPosition = new Vector2();
    private float radius = 10;
    private Vector2 velocity;
    private float maxSpeed = 500;
    private boolean holding = true, soundEffectBlip = true;
    private AssetManager assetManager;

    public BreakoutBall()
    {
        velocity = new Vector2(0, 10).nor().scl(maxSpeed);
    }

    public void setAssetManager(AssetManager assetManager) {
        this.assetManager = assetManager;
    }

    void playSoundEffect()
    {
        if (soundEffectBlip) assetManager.get("blip.wav", Sound.class).play();
        else assetManager.get("blop.wav", Sound.class).play();
        soundEffectBlip = !soundEffectBlip;
    }

    public void startMoving(float deltaTime)
    {
        expectedPosition.x = position.x + velocity.x * deltaTime;
        expectedPosition.y = position.y + velocity.y * deltaTime;
    }

    public void checkCollisionAgainstWalls(List<BreakoutWall> walls)
    {
        for (BreakoutWall wall : walls)
        {
            if (Intersector.overlaps(new Circle(expectedPosition, radius), wall.getCollisionRectangle()))
            {
                //Check collision direction by moving back on one axis and rechecking
                float previusX = expectedPosition.x;
                expectedPosition.x = position.x;
                if (Intersector.overlaps(new Circle(expectedPosition, radius), wall.getCollisionRectangle()))
                {
                    expectedPosition.y = position.y;
                    expectedPosition.x = previusX;
                    velocity.y = -velocity.y;
                } //Horizontal movement
                else
                {
                    velocity.x = -velocity.x;
                }

                this.playSoundEffect();
            }
        }
    }

    public void checkCollisionAgainstBricks(List<BreakoutBrick> bricks)
    {
        for (BreakoutBrick brick : bricks)
        {
            //Code duplication with walls, TODO refactor out
            if (Intersector.overlaps(new Circle(expectedPosition, radius), brick.getCollisionRectangle()))
            {
                brick.destroy();

                //Check collision direction by moving back on one axis and rechecking
                float previousX = expectedPosition.x;
                expectedPosition.x = position.x;
                if (Intersector.overlaps(new Circle(expectedPosition, radius), brick.getCollisionRectangle()))
                {
                    expectedPosition.y = position.y;
                    expectedPosition.x = previousX;
                    velocity.y = -velocity.y;
                } //Horizontal movement caused the collision
                else
                {
                    velocity.x = -velocity.x;
                }

                this.playSoundEffect();
            }
        }
    }

    public void checkCollisionAgainstPlayer(BreakoutPad pad)
    {
        if (holding)
        {
            this.moveWithPad(pad);
            return;
        }

        Rectangle padCollisionRectangle = pad.getCollisionRectangle();
        if (Intersector.overlaps(new Circle(expectedPosition, radius), padCollisionRectangle))
        {
            expectedPosition.y = position.y;

            //Control direction based on hit location
            float horizontalDifference = position.x - (padCollisionRectangle.x + padCollisionRectangle.width / 2);
            horizontalDifference /= (padCollisionRectangle.width);

            velocity.x = horizontalDifference * maxSpeed * 2; //Prefer horizontal over vertical movement
            velocity.y = -velocity.y;
            velocity = velocity.nor().scl(maxSpeed);

            expectedPosition.y = padCollisionRectangle.y + padCollisionRectangle.height + radius;
            this.playSoundEffect();
        }
    }

    private void moveWithPad(BreakoutPad pad) {
        Rectangle padCollisionRectangle = pad.getCollisionRectangle();
        expectedPosition.x = padCollisionRectangle.x + padCollisionRectangle.width / 2;
        expectedPosition.y = padCollisionRectangle.y + padCollisionRectangle.height + radius;
    }

    @Override
    public boolean keyDown(int keycode) {
        if (keycode == Input.Keys.SPACE)
        {
            holding = false;
            return true;
        }
        return false;
    }

    public int finishMoving(int numberOfLives)
    {
        position.set(expectedPosition);
        return this.checkOutOfBounds(numberOfLives);
    }

    private int checkOutOfBounds(int numberOfLives)
    {
        if (numberOfLives < 0) return numberOfLives;

        if (position.y < 0)
        {
            numberOfLives--;
            if (numberOfLives >= 0) holding = true;
        }

        return numberOfLives;
    }

    public void render(SpriteBatch batch, AssetManager manager) {
        batch.setColor(Color.ORANGE);
        batch.draw(manager.get("ball.png", Texture.class), position.x - radius, position.y - radius, radius * 2, radius * 2);
        batch.setColor(Color.WHITE);
    }
}
