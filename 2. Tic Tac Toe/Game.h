#pragma once

#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>


class Game
{

private:

	char board[3][3];

public:

	Game();
	void Play();
	void CreateBoard();
	void DrawBoard() const;
	void PlayerMove();
	void RandomComputerMove();
	void BestComputerMove();
	void CheckWin(std::string player) const;
	void CheckDraw() const;
	int MinMax(char currentPostion[3][3], int depth, bool maximizingPlayer);
	int EvaluateBoard() const;
	bool CheckIfBoardIsFull() const;
};

