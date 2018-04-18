package com.lukahorvat.breakout;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Camera;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.viewport.StretchViewport;
import com.badlogic.gdx.utils.viewport.Viewport;

enum GameScreens
{
    STATE_NULL,
    STATE_MAINMENU,
    STATE_LEVEL,
    STATE_TITLE,
    STATE_EXIT
}

public abstract class GameScreen extends InputAdapter implements Screen {
    private GameScreens nextGameScreen = GameScreens.STATE_NULL;
    AssetManager assetManager;
    Game game;
    SpriteBatch batch;
    Viewport viewport;
    Camera camera;

    //Global data
    static int numberOfLives = 3;
    static int score = 0;
    static int currentLevel = 1;

    GameScreen(AssetManager manager, Game game)
    {
        this.assetManager = manager;
        this.game = game;
        this.batch = new SpriteBatch();
        camera = new OrthographicCamera();
        viewport = new StretchViewport(1280, 720, camera);
        viewport.apply();
        camera.position.set(camera.viewportWidth / 2, camera.viewportHeight / 2, 0);

        Gdx.input.setInputProcessor(this);
    }

    @Override
    public void resize(int width, int height) {
        viewport.update(width, height);
        camera.position.set(camera.viewportWidth / 2, camera.viewportHeight / 2, 0);
    }

    void setNextGameScreen(GameScreens screen)
    {
        this.nextGameScreen = screen;
    }

    public GameScreens getNextGameScreen()
    {
        return nextGameScreen;
    }

    @Override
    public void render(float delta) {
        this.changeScreen();
    }

    void changeScreen()
    {
        GameScreen nextScreen = null;
        Screen currentScreen = game.getScreen();

        switch (nextGameScreen)
        {
            case STATE_MAINMENU:
            {
                nextScreen = new MainMenuScreen(assetManager, game);
                break;
            }
            case STATE_LEVEL:
            {
                nextScreen = new LevelScreen(assetManager, game);
                break;
            }
            case STATE_EXIT:
            {
                if (currentScreen != null)
                {
                    currentScreen.dispose();
                }
                Gdx.app.exit();
                break;
            }
        }

        if (nextScreen != null) {
            game.setScreen(nextScreen);
        }

        if (currentScreen != null)
        {
            currentScreen.dispose();
        }
    }

    @Override
    public void dispose() {

    }

    @Override
    public void hide() {

    }

    @Override
    public void show() {

    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }
}
