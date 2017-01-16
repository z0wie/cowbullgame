#pragma once
#include <string>

using int32 = int;
using FString = std::string;

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const; // Return number of tries used.
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: Make a more rich return value.
	bool CheckGuessValidity(FString); // TODO: Make a more rich return value.
	// TODO: Provide a method for counting bulls and cows, and increasing turn #.


private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;

};
