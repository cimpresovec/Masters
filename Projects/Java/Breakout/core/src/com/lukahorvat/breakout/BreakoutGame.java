package com.lukahorvat.breakout;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.audio.Music;
import com.badlogic.gdx.audio.Sound;
import com.badlogic.gdx.graphics.Texture;

public class BreakoutGame extends Game {
	Screen currentScreen;
	AssetManager assetManager;

	@Override
	public void create () {
		//Load assets
		assetManager = new AssetManager();
		assetManager.load("pad.png", Texture.class);
		assetManager.load("wall.png", Texture.class);
		assetManager.load("ball.png", Texture.class);
		assetManager.load("brick.png", Texture.class);
		assetManager.load("breakout.png", Texture.class);
		assetManager.load("logo.png", Texture.class);
		assetManager.load("menuFiller1.png", Texture.class);
		assetManager.load("menuFiller2.png", Texture.class);
		assetManager.load("playButton.png", Texture.class);
		assetManager.load("exitButton.png", Texture.class);
		assetManager.load("blip.wav", Sound.class);
        assetManager.load("blop.wav", Sound.class);
        assetManager.load("Wild_Pogo.ogg", Music.class);
		assetManager.finishLoading();

        assetManager.get("Wild_Pogo.ogg", Music.class).setLooping(true);
        assetManager.get("Wild_Pogo.ogg", Music.class).play();

		//Initial scene
		currentScreen = new TitleScreen(assetManager, this);
		setScreen(currentScreen);
	}

	@Override
	public void dispose() {
		super.dispose();
		assetManager.clear();
	}
}
