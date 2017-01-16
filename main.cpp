/*
This is the console executable that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction.  For game logic, see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;  // Instantiate a new game.

// The entry point for the application.
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0; // Exit the application.
}



void PrintIntro()
{
	// Introduce the game.
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;;
	std::cout << std::endl;;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Max Tries: " << MaxTries << std::endl;

	// Loop for the number of turns asking for guesses.
	// TODO: Change from FOR to WHILE loop once we are validating tries.

	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();  // TODO: Make loop to check validity of guess.

		// Submit valid guess to the game.
		// Return number of bulls and cows.

		std::cout << "Your guess: " << Guess << std::endl;;
		std::cout << std::endl;;
	}

	// TODO: Summarize game.
}

FText GetGuess()
{
	// Get a guess from the user.
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;;
	return (Response[0] == 'Y') || (Response[0] == 'y');
}
