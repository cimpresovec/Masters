using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelCreatorScript : MonoBehaviour
{

	public GameObject brickPrefab;
	// Use this for initialization
	void Start () {
		for (float z = 0; z < 20; z += 3.5f)
		{
			for (float x = 0; x <= 65; x += 5.5f)
			{
				Instantiate(brickPrefab, transform.position + new Vector3(x, 0, z), Quaternion.identity, transform);
			}
		}
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
