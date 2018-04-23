using System.Collections;
using System.Collections.Generic;
using System.Resources;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameHandlerScript : MonoBehaviour
{
	public static GameHandlerScript instance = null;
	public GameGlobals gameGlobals;

	private void Awake()
	{
		if (instance == null)
		{
			instance = this;
		}
		else if (instance != this)
		{
			Destroy(gameObject);
		}
		DontDestroyOnLoad(gameObject);
	}

	// Update is called once per frame
	private void Update () {
		//Screen aspect handling
		Camera.main.aspect = 16f / 9f;
	}
}
