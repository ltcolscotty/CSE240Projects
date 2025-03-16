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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#define LEADERBOARD_FILE "guessing_leaderboard.bin"

class Player {
public:
	Player() {};
	Player(string name, int guesses) : name(name), guesses(guesses) {};

	string getName() const { return name; }
	int getGuesses() const { return guesses; }

	// into binary format
	void serialize(FILE* file) const {
		size_t len = name.size();
		fwrite(&len, sizeof(size_t), 1, file);
		fwrite(name.c_str(), sizeof(char), len, file);
		fwrite(&guesses, sizeof(int), 1, file);
	}

	// out of binary format
	void deserialize(FILE* file) {
		// Read string length
		size_t len;
		if (fread(&len, sizeof(size_t), 1, file) != 1) return;

		// Read string data
		char* buffer = new char[len + 1];
		fread(buffer, sizeof(char), len, file);
		buffer[len] = '\0';
		name = buffer;
		delete[] buffer;

		fread(&guesses, sizeof(int), 1, file);
	}

private:
	string name;
	// set to INT_MAX to make guess ordering easier
	int guesses = INT_MAX;
};

class LeaderBoard {
public:
	LeaderBoard() {
		loadFromFile();
	}

	// insert in order
	void InsertPlayer(Player player) {
		// Find insertion position
		int insertPos = NUM_LEADERS;
		for (int i = 0; i < NUM_LEADERS; ++i) {
			if (player.getGuesses() < leaders[i].getGuesses()) {
				insertPos = i;
				break;
			}
		}

		if (insertPos >= NUM_LEADERS) return;

		// Shift players down
		for (int i = NUM_LEADERS - 1; i > insertPos; --i) {
			leaders[i] = leaders[i - 1];
		}

		leaders[insertPos] = player;
		saveToFile();
	}

	// display leaderboard
	void display() const {
		cout << "\n----------\nLeaderboard:" << endl;
		for (int i = 0; i < NUM_LEADERS; ++i) {
			if (leaders[i].getGuesses() == INT_MAX) continue;
			cout << (i + 1) << ". " << leaders[i].getName()
				<< " - " << leaders[i].getGuesses() << " guesses" << endl;
		}
		cout << "----------\n" << endl;
	}

private:
	static const int NUM_LEADERS = 5;
	Player leaders[NUM_LEADERS];

	// --- File IO stuff ---

	void loadFromFile() {
		FILE* fp = fopen(LEADERBOARD_FILE, "rb");
		if (!fp) return;

		for (int i = 0; i < NUM_LEADERS; ++i) {
			if (feof(fp)) break;
			leaders[i].deserialize(fp);
		}
		fclose(fp);
	}

	void saveToFile() {
		FILE* fp = fopen(LEADERBOARD_FILE, "wb");
		if (!fp) {
			perror("Failed to save leaderboard");
			return;
		}

		for (int i = 0; i < NUM_LEADERS; ++i) {
			leaders[i].serialize(fp);
		}
		fclose(fp);
	}
};

// Takes input and action for quit dialogue
bool determineContinue() {
	char inputChar;
	cout << "Press 'q' to quit, press any key to continue:" << endl;
	cin >> inputChar;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return (inputChar != 'q');
}


// Easier print function to auto format
void printPlayer(Player p1, int place)
{
	cout << (place + 1) << ". " << p1.getName() << " made " << p1.getGuesses() << " guesses\n" << endl;
}

// Read file
FILE* openLeaderboardFile(const char* mode) {
	FILE* fp = fopen(LEADERBOARD_FILE, mode);
	if (!fp) {
		perror("Leaderboard file error");
		exit(EXIT_FAILURE);
	}
	return fp;
}

// Handles displaying leaderboard and storing information
void finishingProcedures(Player p1) {
	LeaderBoard board;
	board.InsertPlayer(p1);
	board.display();
}

// Get player username
string getName() {
	cout << "Enter your name: " << endl;
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
		cout << "Guess a value between 10 and 100: " << endl;

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
	int numberToGuess = rand() % 91 + 10;
	double squareRoot = sqrt(numberToGuess);
	cout << squareRoot  << " is the square root of what number?" << endl;
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
	cout << "You got it, baby!" << endl;

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
	srand(time(NULL));
	bool continueGame = true;
	cout << "Welcome to the Guessing Game!" << endl;

	continueGame = determineContinue();

	while (continueGame) {
		playRound();
		continueGame = determineContinue();
	}

	cout << "Goodbye!" << endl;
	return 0;
}
