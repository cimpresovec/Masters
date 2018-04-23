using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class TextUpdaterScript : MonoBehaviour
{

	public GameGlobals gameGlobals;

	public TextMeshProUGUI livesText;
	public TextMeshProUGUI scoreText;
	public TextMeshProUGUI levelText;
	public TextMeshProUGUI gameOverText;

	private void Awake()
	{
		gameOverText.gameObject.SetActive(false);
	}

	private void Update ()
	{
		livesText.text = "Lives: " + (gameGlobals.numberOfLives < 0? 0 : gameGlobals.numberOfLives);
		scoreText.text = "Score " + gameGlobals.score;
		levelText.text = "Level " + gameGlobals.currentLevel;

		if (gameGlobals.numberOfLives < 0)
		{
			gameOverText.gameObject.SetActive(true);
		}
	}
}
