using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Data", menuName = "Data/GameGlobals")]
public class GameGlobals : ScriptableObject
{
    public int numberOfLives;
    public int score;
    public int currentLevel;
}
