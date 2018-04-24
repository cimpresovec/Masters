using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BrickScript : MonoBehaviour
{

	public LevelCreatorScript levelCreatorScript;

	public bool gotHit(RaycastHit other)
	{
		if (other.collider.isTrigger) return false;
		other.collider.attachedRigidbody.isKinematic = false;
		other.collider.isTrigger = true;
		other.collider.attachedRigidbody.AddForceAtPosition(-other.normal * 100, other.point);
		other.collider.attachedRigidbody.AddForce(new Vector3(0, 500, 0));
		
		levelCreatorScript.reduceTheNumberOfBricks();
		return true;
	}
}
