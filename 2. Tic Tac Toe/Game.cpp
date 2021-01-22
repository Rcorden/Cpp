#include "Game.h"

Game::Game()
{
	Play();
}

void Game::Play()
{
	CreateBoard();
	DrawBoard();

	while (true)
	{
		PlayerMove();
		BestComputerMove();
		//RandomComputerMove();
	}
}

void Game::CreateBoard()
{
	char count = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			board[i][x] = count;
			count++;
		}
	}
}

void Game::DrawBoard() const
{
	//system("cls");
	std::cout << "\n\n\tTic Tac Toe\n\n";

	std::cout << "Player 1 (X)  -  Computer (O)" << std::endl << std::endl;
	std::cout << std::endl;

	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << std::endl;

	std::cout << "     |     |     " << std::endl << std::endl;
}

void Game::PlayerMove()
{
	int col, row, move;
	bool validMove = false;

	std::cout << "Pick a board postion: " << "\n";

	while (!validMove)
	{
		while (!(std::cin >> move))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}

		move = move - 1;
		col = move % 3;
		row = move / 3;

		if (board[row][col] != 'X' && board[row][col] != 'O')
		{
			validMove = true;

			std::cout << "Player picks: " << move + 1 << "\n";
			board[row][col] = 'X';

			CheckWin("Player");
			CheckDraw();
		}
		else
		{
			std::cout << "Invalid input.  Try again: ";
		}
	}
}

void Game::RandomComputerMove()
{
	int col=0, row=0, move=0;
	bool validMove = false;

	while (!validMove)
	{
		srand(time(0));
		move = (rand() % 9) + 1;
		move = move - 1;
		col = move % 3;
		row = move / 3;

		if (board[row][col] != 'X' && board[row][col] != 'O')
		{
			validMove = true;

			std::cout << "Computer picks: " << move + 1 << "\n";
			board[row][col] = 'O';

			CheckWin("Computer");
			CheckDraw();
		}
	}
	DrawBoard();
}

void Game::BestComputerMove()
{
	int bestValue = 1000, moveValue, row, col, bestMove;

	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[i][x] != 'X' && board[i][x] != 'O')
			{
				char temp = board[i][x];
				board[i][x] = 'O';
				moveValue = MinMax(board, 0, true);
				board[i][x] = temp;

				if (moveValue < bestValue)
				{
					bestMove = board[i][x]-'0';
					bestValue = moveValue;
				}
			}
		}
	}

	bestMove = bestMove - 1;
	col = bestMove % 3;
	row = bestMove / 3;

	std::cout << "Computer picks: " << bestMove + 1 << "\n";
	board[row][col] = 'O';
	CheckWin("Computer");
	CheckDraw();
	DrawBoard();
}

void Game::CheckDraw() const
{
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[i][x] == 'X' || board[i][x] == 'O')
			{
				counter++;
			}
		}
	}

	if (counter == 9)
	{
		DrawBoard();
		std::cout << "DRAW GAME" << "\n";
		exit(0);
	}
}

void Game::CheckWin(std::string player) const
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			DrawBoard();
			std::cout << player << " wins" << "\n";
			exit(0);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x])
		{
			DrawBoard();
			std::cout << player << " wins" << "\n";
			exit(0);
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		DrawBoard();
		std::cout << player << " wins" << "\n";
		exit(0);
	}

	if ((board[2][0] == board[1][1] && board[1][1] == board[0][2]))
	{
		DrawBoard();
		std::cout << player << " wins" << "\n";
		exit(0);
	}
}

int Game::MinMax(char currentPostion[3][3], int depth, bool maximizingPlayer)
{
	int score = EvaluateBoard();

	if (score == 10)
	{
		return score;
	}
	if (score == -10)
	{
		return score;
	}
	if (CheckIfBoardIsFull())
	{
		return 0;
	}

	if (maximizingPlayer)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (board[i][x] != 'X' && board[i][x] != 'O')
				{
					char temp = board[i][x];
					board[i][x] = 'X';
					best = std::max(best, MinMax(board, depth + 1, !maximizingPlayer));
					board[i][x] = temp;

				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (board[i][x] != 'X' && board[i][x] != 'O')
				{
					char temp = board[i][x];
					board[i][x] = 'O';
					best = std::min(best, MinMax(board, depth + 1, !maximizingPlayer));
					board[i][x] = temp;

				}
			}
		}
		return best;
	}
}

int Game::EvaluateBoard() const
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
	}
	for (int x = 0; x < 3; x++)
	{
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x])
		{
			if (board[0][x] == 'X')
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}

	if ((board[2][0] == board[1][1] && board[1][1] == board[0][2]))
	{
		if (board[2][0] == 'X')
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}

	return 0;
}

bool Game::CheckIfBoardIsFull() const
{
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[i][x] == 'X' || board[i][x] == 'O')
			{
				counter++;
			}
		}
	}

	if (counter == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}