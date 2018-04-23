using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuScript : MonoBehaviour {
	
	public GameGlobals gameGlobals;

	public void switchSceneToLevel()
	{
		gameGlobals.currentLevel = 1;
		gameGlobals.numberOfLives = 3;
		gameGlobals.score = 0;
		SceneManager.LoadScene("LevelScene", LoadSceneMode.Single);
	}

	public void exitGame()
	{
		Application.Quit();
	}
}
