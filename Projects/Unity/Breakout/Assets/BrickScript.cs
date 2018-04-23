using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BrickScript : MonoBehaviour
{

	public LevelCreatorScript levelCreatorScript;

	public void gotHit(Collision other)
	{
		other.collider.attachedRigidbody.isKinematic = false;
		other.collider.isTrigger = true;
		other.collider.attachedRigidbody.AddForceAtPosition(-other.relativeVelocity * 10, other.contacts[0].point);
		other.collider.attachedRigidbody.AddForce(new Vector3(0, 500, 0));
		
		levelCreatorScript.reduceTheNumberOfBricks();
	}
}
