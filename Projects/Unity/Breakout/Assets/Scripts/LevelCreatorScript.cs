using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LevelCreatorScript : MonoBehaviour
{

	public GameObject brickPrefab;
	public GameGlobals gameGlobals;

	private int numberOfBricks = 0;
	// Use this for initialization
	void Start () {
		for (float z = 0; z < 20; z += 3.5f)
		{
			for (float x = 0; x <= 65; x += 5.5f)
			{
				numberOfBricks++;
				var brick = Instantiate(brickPrefab, transform.position + new Vector3(x, 0, z), Quaternion.identity, transform);
				brick.GetComponent<BrickScript>().levelCreatorScript = this;
			}
		}
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.Escape))
		{
			SceneManager.LoadScene("MainMenuScene", LoadSceneMode.Single);
		}
	}
	

	public void reduceTheNumberOfBricks()
	{
		numberOfBricks--;

		if (numberOfBricks <= 0)
		{
			gameGlobals.currentLevel++;
			SceneManager.LoadScene("LevelScene", LoadSceneMode.Single);
		}
	}
}
