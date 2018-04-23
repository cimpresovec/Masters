using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraScript : MonoBehaviour
{

	public Transform followTarget;

	public Vector3 distanceVector;
	// Use this for initialization
	void Start ()
	{
		distanceVector = transform.position - followTarget.position;
	}
	
	// Update is called once per frame
	void Update ()
	{
		var targetPosition = followTarget.position + distanceVector;
		transform.position = Vector3.Lerp(transform.position, targetPosition, 0.1f);
	}
}
