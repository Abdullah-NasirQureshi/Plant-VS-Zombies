#include "ScoreBoard.h"


int ScoreBoard::Lives =3;
int ScoreBoard::Score =0;

ScoreBoard::ScoreBoard()
{
	Lives = 3;
	Score = 0;
}
int ScoreBoard::getLives()
{
	return Lives;
}
int ScoreBoard::getScore()
{
	return Score;
}
void ScoreBoard::setLives(int x)
{
	Lives = x;
}
void ScoreBoard::setScore(int x)
{
	Score = x;
}