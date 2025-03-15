/*
* game.cpp
*
* Aidan Yung
* 3/15/2025
*
* Rewriting guessing.c to cpp
* 
* TODO: Change sorting to just be modified insertion sort
*/

#include <iostream>

using namespace std;

#define LEADERBOARD_FILE "guessing_leaderboard.bin"

class Player
{
public:
		Player() {}
		Player(string name, int guesses) : name(name), guesses(guesses) {};
		string getName() const { return name; }
		int getGuesses() const { return guesses; }
private:
	string name;
	int guesses;
};

class LeaderBoard
{
public:
	LeaderBoard() {}
	void InsertPlayer(Player player) {
		for (int i = 0; i < NUM_LEADERS; i++) {
			if (leaders[i] == NULL || leaders[i].getGuesses() > player.getGuesses())
			{
				leaders[i] = player;
			}
		}
	};

	const Player& getPlayer(int index) { return leaders[index]; }
private:
	static const int NUM_LEADERS = 5;
	Player leaders[NUM_LEADERS] = {Player()};
};

// Checks cleans input for handling later. optionCount is the size of the array or number of options
bool verifyInput(char* stringItems[], int optionCount, char* input) {
	for (int i = 0; i < optionCount; i++) {
		if (strcmp(stringItems[i], input) == 0) {
			return true;
		}
	}
	return false;
}

// Takes input and action for quit dialogue
bool determineContinue() {
	char inputChar[40];
	cout << "Press 'q' to quit, press any key to continue:\n" << endl;
	int charCt = scanf(" %39s", &inputChar);
	inputChar[39] = '\0'; //redundancy
	while (getchar() != '\n'); // clear buffer
	// Returns true for anything that isn't "q"
	return (strcmp(inputChar, "q") != 0);
}


// Easier print function to auto format
void printPlayer(Player p1, int place)
{
	cout << (place + 1) << ". " << p1.getName() << " made " << p1.getGuesses() << " guesses\n" << endl;
}

// Gets the leaderboard file
FILE* openLeaderboardFile()
{
	FILE* fp = NULL;

	fp = fopen(LEADERBOARD_FILE, "rb+");

	if (fp == NULL)
	{
		// For first time execution
		fp = fopen(LEADERBOARD_FILE, "wb+");
		if (fp == NULL)
		{
			fprintf(stderr, "File creation failed.\n");
			exit(1);
		}
	}

	return fp;
}

// get past game records into list for usage
int readLeaderboardRecords(FILE* fp, Player* playerList, int recordCt)
{
	for (int recordIndex = 0; recordIndex < recordCt; recordIndex++)
	{
		fread(&playerList[recordIndex], sizeof(Player), 1, fp);
	}
}

// stores top 5
void writeLeaderboardRecords(FILE* fp, Player* playerList, int recordCt)
{
	fp = fopen(LEADERBOARD_FILE, "wb");

	if (recordCt > 5)
	{
		recordCt = 5;
	}

	if (fp == NULL)
	{
		fprintf(stderr, "Failed to save leaderboard\n");
		free(playerList);
		exit(1);
	}

	for (int i = 0; i < recordCt; i++)
	{
		fwrite(&playerList[i], sizeof(Player), 1, fp);
	}
}

// Displays results
void displayLeaderboardResults(Player p1, Player* playerList, int* recordCt)
{
	// Add player to leaderboard
	playerList[*recordCt] = p1;
	(*recordCt)++;

	// Display leaderboard
	cout << "----------\nLeaderboard:\n" << endl;

	// New leaderboard
	if (*recordCt == 0)
	{
		printPlayer(p1, 1);
	}
	else
	{
		// Existing leaderboard
		for (int i = 0; i < *recordCt; i++)
		{
			if (i == 5)
			{
				cout << "----- Knocked Out -----\n" << endl;
			}

			printPlayer(playerList[i], i);
		}
	}

	// Ending
	cout << "----------\n" << endl;
}

// Handles displaying leaderboard and storing information
void finishingProcedures(Player p1)
{
	Player playerList[6];

	if (playerList == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}

	FILE* fp = openLeaderboardFile();

	fseek(fp, 0, SEEK_END);

	int fSize = ftell(fp);
	int recordCt = fSize / sizeof(Player);
	rewind(fp);
	readLeaderboardRecords(fp, playerList, recordCt);

	fclose(fp);

	// Safety check to make sure current count is not above 5
	if (recordCt > 6)
	{
		recordCt = 6;
	}

	displayLeaderboardResults(p1, playerList, &recordCt);
	writeLeaderboardRecords(fp, playerList, recordCt);

	fclose(fp);
	free(playerList);
}

// Get player username
string getName() {
	cout << "Enter your name: \n" << endl;
	string name;
	cin >> name;
	cin.clear(); //clear buffer

	return name;
}


// Gets guess from player
int GetGuess()
{
	int guess;
	while (true)
	{
		cout << "Guess a value between 10 and 100: ";

		if (cin >> guess)
		{
			if (guess >= 10 && guess <= 100)
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return guess;
			}
		}
		else
		{
			cin.clear();
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. ";
	}
}


// Guessing game
int PlayGuessingGame()
{
	int guessCt = 0;

	// Generate a random number between 10 and 100 and find its square root
	srand((unsigned int)time(NULL)); // Seed rand with current time
	int numberToGuess = rand() % 91 + 10;
	double squareRoot = sqrt(numberToGuess);
	cout << squareRoot  << " is the square root of what number?\n" << endl;
	bool done = false;
	while (!done)
	{
		guessCt++;
		int guess = GetGuess();
		if (guess < numberToGuess)
			cout << "Too low, guess again: " << endl;
		else if (guess > numberToGuess)
			cout << "Too high, guess again: " << endl;
		else
			done = true;
	}
	cout << "You got it, baby!\n" << endl;

	return guessCt;
}

// Play round function packages everything together
void playRound()
{
	string name = getName();
	int score = PlayGuessingGame();

	Player p1(name, score);

	finishingProcedures(p1);
}


int main()
{
	bool continueGame = true;
	cout << "Welcome to the Guessing Game!\n" << endl;

	// Initial quit question as seen in example before going into the loop
	continueGame = determineContinue();

	while (continueGame) {
		playRound();
		continueGame = determineContinue();
	}

	cout << "Goodbye!\n" << endl;
	return 0;
}
