#include <iostream>

using namespace std;

const int GameScreenWidth = 12;
const int GameScreenDepth = 12;

const char character = 'X';

char GameScreen[GameScreenWidth][GameScreenDepth];
int xPos;		// x and y position of character in gamescreen
int yPos;

void FillGameScreen();
void ShowGameScreen();

void MoveLeft();
void MoveRight();
void MoveUp();
void MoveDown();

int main()
{
	char background;   // put the background object (a char) in here while the character is over it
	int xPosPrev;		// the last position of the character - used to restore the background object (a char)
	int yPosPrev;
	// output the gamescreen
	FillGameScreen();

	xPos = 3;
	yPos = 3;

	xPosPrev = xPos;
	yPosPrev = yPos;
	background = GameScreen[yPos][xPos];		// Get the background

	GameScreen[yPos][xPos] = character;		// Show character
	ShowGameScreen();


	char keypress;
	do
	{
		cin >> keypress;						// not ideal as user has to press enter, but it will do for now

		GameScreen[yPos][xPos] = char(177);	// restore the background object

		switch (keypress)						// Get new X and Y positions
		{
		case '6':
			MoveLeft();
			break;
		case '8':
			MoveRight();
			break;
		case '2':
			MoveUp();
			break;
		case '4':
			MoveDown();
			break;
		default:
			break;
		}
		background = GameScreen[yPos][xPos];		// store background
		GameScreen[yPos][xPos] = character;			// place character
		ShowGameScreen();							// schow game screen
	} while (keypress != 'Q');

	// read in a character
	// Move the object in the array
	// while the input key != Q
	// 6 = Left, 8 = right, 4 = down, 2 = up


	system("PAUSE");
	return 0;
}

void FillGameScreen()
{
	int rowCount;
	int colCount;

	for (rowCount = 0; rowCount < GameScreenDepth; rowCount++)
	{
		for (colCount = 0; colCount < GameScreenWidth; colCount++)
		{
			GameScreen[rowCount][colCount] = char(177);
		}
	}
}

void ShowGameScreen()
{
	// Clear Screen
	system("CLS");
	int rowCount;
	int colCount;
	cout << "Use 2,4,6,8 and <enter> to move 'X'" << endl << endl;
	for (rowCount = 0; rowCount < GameScreenDepth; rowCount++)
	{
		for (colCount = 0; colCount < GameScreenWidth; colCount++)
		{
			cout << GameScreen[rowCount][colCount];
		}
		cout << endl;
	}

}

void MoveLeft()
{
	if (xPos > 0)
		xPos--;
}

void MoveRight()
{
	if (xPos < GameScreenDepth - 1)
		xPos++;
}

void MoveUp()
{

	if (yPos >0)
		yPos--;
}

void MoveDown()
{

	if (yPos< GameScreenDepth - 1)
		yPos++;
}
