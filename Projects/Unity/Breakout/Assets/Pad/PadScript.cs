using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PadScript : MonoBehaviour {

	[SerializeField]
	private float horizontalSpeed;

	private Rigidbody rb;

	private Vector3 velocity;
	// Use this for initialization
	private void Start ()
	{
		rb = GetComponent<Rigidbody>();
		velocity = new Vector3(0, 0, 0);
	}
	
	// Update is called once per frame
	private void FixedUpdate () 
	{
		velocity.x = 0;
		if (Input.GetKey(KeyCode.LeftArrow)) velocity.x += -horizontalSpeed;
		if (Input.GetKey(KeyCode.RightArrow)) velocity.x += horizontalSpeed;

		var position = transform.position;
		position = position + velocity * Time.deltaTime;
		//Position clamping
		position.x = Mathf.Min(position.x, 35);
		position.x = Mathf.Max(position.x, -35);

		rb.MovePosition(position);
//		transform.position = position;
	}
}
