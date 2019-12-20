/**********************************************
//Program Project: Tic Tac Toe 
//This is a sample code that will give you 
//and example of what is expected of your final
//programming project. This program uses only 
//what you will know by the midterm. 
***********************************************/
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;


const int rows = 10;
const int elements = 10;
int maxships = 10;
int matrix[rows][elements];

struct Game
{
	string board;
	int currentPlayer;
	char tokens[2];
};

void Rules()
{
cout << "+--------------------+" << endl;
cout << "| BATTLESHIPS        |" << endl;
cout << "+--------------------+" << endl;
cout << "| BY                 |" << endl;
cout << "+--------------------+" << endl;
cout << "| DANIEL ST. VINCENT |"<< endl;
cout << "+--------------------+" << endl << endl;

cout << "The game battleship is a solo guessing game between \n"; 
cout << "you and the clock. You will be assisted with an unlimited amount\n";
cout << "Afterwards, they will take turns drawing their\n";
cout << "missile(Chances) to attempt to shink(guess) the coordinates of all ten battleships.\n";
cout << "The battleships are laid out randomly on a grid with 100 possibles locations.\n";
cout << "You, as the player, will have to guess the coordinates by entering in two digits,\n";
cout << "One on the Y-axis for columns and one and the X-axis for rows, with space in between \n";
cout << "like so. See the example below for more details. If that coordinate is correct and \n";
cout << "you hit a battleship, you will see (Shink my battleship) displayed on the screen, and if\n";
cout << "the coordinate is incorrect, you will see (missed, please try again) display across the screen.\n\n";

  cout << "    C O L U M N S ----->  " << endl << endl;
  cout << "  0 1 2 3 4 5 6 7 8 9 10  " << endl;
  cout << "R 0 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "O 1 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "W 2 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "S 3 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "| 4 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "| 5 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "V 6 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "  7 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "  8 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << "  9 0 0 0 0 0 0 0 0 0 0   " << endl;
  cout << " 10 0 0 0 0 0 0 0 0 0 0   " << endl << endl;
	cout << "Press any key to continue\n";
    getchar();
}

void Initialize(Game& game)
{
	game.board = "*********";
	game.currentPlayer = 0;
	game.tokens[0] = 'X';
	game.tokens[1] = 'O';
}

void Display(Game& game,bool flag)
{
    string stage = (flag)?("Beginning of Turn"):("End of Turn");
	cout << "\n" << stage << "\nCurrent Player: Player " << (game.currentPlayer + 1) << "\n\n";
	char value;
	for(int i = 0;i < 9;i += 1)
	{
		value = game.board[i];	

        if(i % 3 == 0)
        {
            cout << " ";
        }

        if(value == '*')
        {
            cout << " ";
        }
        else
        {
            cout << value;
        }
        
		if((i + 1) % 3 != 0)
        {
            cout << " | ";
        }
        else
        {
            if(i != 8)
            {
                cout << "\n-----------\n";
            }
            else 
            {
                cout << "\n\n";
            }
        }
	}
}

bool HorizontalWinner(Game& game)
{
	string bd = game.board;

	for(int x = 0;x < 3;x += 1)
	{
		if(bd[3*x] == bd[3*x + 1] && bd[3*x] == bd[3*x + 2] && bd[3*x] != '*')
		{
			return true;
		}
	}
	return false;
}

bool VerticalWinner(Game& game)
{
	string bd = game.board;

	for(int y = 0;y < 3;y += 1)
	{
		if(bd[y] == bd[3 + y] && bd[y] == bd[6 + y] && bd[y] != '*')
		{
			return true;
		}
	}
	return false;
}

bool DiagonalWinner(Game& game)
{
	string bd = game.board;
	bool dd = (bd[0] == bd[4] && bd[0] == bd[8] && bd[0] != '*');
	bool id = (bd[2] == bd[4] && bd[2] == bd[6] && bd[2] != '*');

	return (dd || id);
}

bool Winner(Game& game)
{
	return (HorizontalWinner(game) || VerticalWinner(game) || DiagonalWinner(game));
}

bool HasMove(Game& game)
{
	string bd = game.board;

	for(int i = 0;i < 9;i += 1)
	{
		if(bd[i] == '*')
		{
			return true;
		}
	}
	return false;
}

bool CanPlay(Game& game)
{
	return (HasMove(game) && !Winner(game));
}

bool ValidCoordinate(Game& game,int x,int y)
{
    bool loc = ((x >= 1 && x <= 3) && (y >= 1 && y <= 3));

    if(loc)
    {
        int coor = 3 * (x - 1) + (y - 1);
        return (game.board[coor] == '*');
    }
    return false;
}

void SetValue(Game& game,int x,int y)
{
    int idx = 3 * (x - 1) + (y - 1);
    game.board[idx] = game.tokens[game.currentPlayer];
}

void NextPlayer(Game& game)
{
    game.currentPlayer = (game.currentPlayer + 1) % 2;
}

void MakeMove(Game& game)
{
    int x, y;

    while(true)
    {
        cout << "Enter inout cordinates: ";
        cin >> x >> y;

        if(ValidCoordinate(game,x,y))
        {
            SetValue(game,x,y);
            break;
        }
    } 
}




void PlayGame()
{
    Game game;

    Rules();
    Initialize(game);

    while(CanPlay(game))
    {
        Display(game,true);
        MakeMove(game);
        Display(game,false);
        NextPlayer(game);
    }

    if(Winner(game))
    {
        cout << "Player " << ((game.currentPlayer + 1) % 2 + 1) << " won\n";
    }
    else
    {
        cout << "Game is a draw\n";
    }
}


void Clear()
{
  for(int i=0; i < rows; i++)
  {
for(int j=0; j < elements; j++)
                {
                        matrix[i][j] = 0;
                }
        }
}
 
void Show()
{
        for(int i=0; i < rows; i++)
        {
                for(int j=0; j < elements; j++)
                {
                        cout << matrix[i][j] << " ";
                }
                cout << endl;
                
        }
}
 
int NumberOfShips()
{
        int c = 0;
 
        for(int i=0; i < rows; i++)
        {
                for(int j=0; j < elements; j++)
                {
                        if(matrix[i][j] == 1)
                                c++;
                }
        }
 
        return c;
}
 
void SetShips()
{
        int s = 0;
        while(s < maxships)
        {
                int x = rand() % rows;
                int y = rand() % elements;
                if(matrix[x][y] != x)
                {
                        s++;
                        matrix[x][y] = 1;
                }
        }
}
 
bool Attack(int x,int y)
{
  Show();
        if(matrix[x][y] == 1)
        {
                matrix[x][y] = 2;
                return true;
        }
        
        return false;
}


int main()
{
    PlayGame();
    return 0;
}	