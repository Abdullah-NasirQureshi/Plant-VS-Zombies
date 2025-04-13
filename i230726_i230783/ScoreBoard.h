#pragma once

class ScoreBoard
{
	

public:
	static int Lives;
	static int Score;
	ScoreBoard();
	int getLives();
	int getScore();
	void setLives(int x);
	void setScore(int x);
};

