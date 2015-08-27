#ifndef snake_Included
#define snake_Included
using namespace std;

struct pointT{
	int row, col;
};

string GetLine() {
	string result;
	getline (cin, result);
	return result;
}

struct gameT{
	vector<string> world;
	int numRows, numCols;

	deque<pointT> snake;
	int dx, dy;

	int numEaten;
};

void OpenUserFile (ifstream& input);

void InitializeGame (gameT& game);

void InitializeGame (gameT& game);

pointT MakePoint (int row,int col);

void LoadWorld (gameT& game, ifstream& input);

void RunSimulation (gameT& game);

void Pause();
void PrintWorld(gameT& game);

void DisplayResult (gameT& game);
void PerformAI (gameT& game);
pointT GetNextPosition (gameT& game,int dx,int dy);

bool Crashed(pointT headPos, gameT& game);
bool InWorld (pointT& pt, gameT& game);
bool RandomChance (double probability);
bool MoveSnake(gameT& game);
void PlaceFood(gameT& game);
#endif