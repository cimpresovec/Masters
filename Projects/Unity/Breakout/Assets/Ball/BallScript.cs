using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallScript : MonoBehaviour
{

	[SerializeField] private float maxSpeed;
	[SerializeField] private AudioClip blipAudioClip = null, blopAudioClip = null;
	private Rigidbody rb;
	private AudioSource audioSource;
	public Transform pad;
	public GameGlobals gameGlobals;

	private bool blip = true;
	private bool holding = true;
	private bool shootBall = false;

	private void Start () {
		rb = GetComponent<Rigidbody>();
		audioSource = GetComponent<AudioSource>();
	}

	// Update is called once per frame
	private void Update ()
	{
		if (!holding) return;
		shootBall = Input.GetKey(KeyCode.Space);
	}

	private void FixedUpdate()
	{
		if (holding)
		{
			rb.MovePosition(pad.position + new Vector3(0, 1.2f, 3));
			if (shootBall)
			{
				holding = false;
				shootBall = false;
				rb.velocity = new Vector3(0, 0, 1) * maxSpeed;
			}
		}
		else
		{
			if (transform.position.z < -40)
			{
				gameGlobals.numberOfLives--;
				if (gameGlobals.numberOfLives >= 0)
				{
					holding = true;
				}

				rb.velocity = Vector3.zero;
			}
		}
	}


	private void OnCollisionEnter(Collision other)
	{
		playBounceSound();
		if (other.gameObject.CompareTag("Brick"))
		{
			other.gameObject.GetComponent<BrickScript>().gotHit(other);
			
			//We want nice bounces of bricks, no weird direction changes
			if (Math.Abs(other.contacts[0].normal.x) < Math.Abs(other.contacts[0].normal.z))
			{
				rb.velocity = new Vector3(-other.relativeVelocity.x, 0, other.relativeVelocity.z).normalized * maxSpeed;
			}
			else
			{
				rb.velocity = new Vector3(other.relativeVelocity.x, 0, -other.relativeVelocity.z).normalized * maxSpeed;
			}
			gameGlobals.score += 10;
			return;
		}
		if (!other.gameObject.CompareTag("Pad")) return;

		//More control of ball direction from the pad
		ContactPoint contract = other.contacts[0];
		rb.velocity = new Vector3(contract.normal.x * 2, 0, 1).normalized * maxSpeed;
	}

	private void playBounceSound()
	{
		audioSource.PlayOneShot(blip ? blipAudioClip : blopAudioClip);
		blip = !blip;
	}
}
