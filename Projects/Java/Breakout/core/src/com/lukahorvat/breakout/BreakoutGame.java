package com.lukahorvat.breakout;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class BreakoutGame extends Game {
	Screen currentScreen;
	AssetManager assetManager;

	@Override
	public void create () {
		assetManager = new AssetManager();
		assetManager.load("pad.png", Texture.class);
		assetManager.finishLoading();
		currentScreen = new LevelScene(assetManager);
		setScreen(currentScreen);
	}

	@Override
	public void dispose() {
		super.dispose();
		assetManager.clear();
	}
}
