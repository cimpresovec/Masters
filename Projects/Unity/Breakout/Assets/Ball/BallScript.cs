using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallScript : MonoBehaviour
{

	[SerializeField] private float maxSpeed;
	[SerializeField] private AudioClip blipAudioClip = null, blopAudioClip = null;
	private Vector3 velocity;
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
		velocity = new Vector3();
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
			rb.MovePosition(pad.position + new Vector3(0, 0.2f, 3));
			if (shootBall)
			{
				holding = false;
				shootBall = false;
				velocity = new Vector3(0, 0, 1) * maxSpeed;
			}
		}
		else
		{
			//Movement
			RaycastHit hit;
			var moveVector = velocity * Time.deltaTime;
			if (rb.SweepTest(moveVector, out hit, moveVector.magnitude))
			{
				playBounceSound();
				if (Mathf.Abs(hit.normal.x) > Mathf.Abs(hit.normal.z))
				{
					velocity.x = -velocity.x;
				}
				else
				{
					velocity.z = -velocity.z;
				}

				//Brick handling
				if (hit.collider.CompareTag("Brick"))
				{
					if (hit.collider.gameObject.GetComponent<BrickScript>().gotHit(hit))
					{
						gameGlobals.score += 10;	
					}
				}
				
				//Pad handling
				if (hit.collider.CompareTag("Pad"))
				{
					velocity = new Vector3(hit.normal.x * 2, 0, 1).normalized * maxSpeed;
				}
			}
			rb.MovePosition(rb.position + moveVector);
			
			if (transform.position.z < -40)
			{
				gameGlobals.numberOfLives--;
				if (gameGlobals.numberOfLives >= 0)
				{
					holding = true;
				}

				velocity = Vector3.zero;
			}
		}
	}

	private void playBounceSound()
	{
		audioSource.PlayOneShot(blip ? blipAudioClip : blopAudioClip);
		blip = !blip;
	}
}
