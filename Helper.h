#pragma once
#include <iostream>

namespace Helper 
{
	//Declare Methods here-----------------------------------------------------------------------
	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0);//TODO: Exits after 1 reattempt with incorrect input
	int PrintMenu(const std::string* menuOptions[]); //Done
	void ClearIgnoreBuffer(); //Done
	void PrintInteger(int* valueToPrint); //Done
	int GenerateRandomNumber(const int* minRange = 0, const int* maxRange=0); //Done

	//GetValidatedInt----------------------------------------------------------------------------------
	int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange)
	{
		int userInput;
		std::cout << strMessage;
		std::cin >> userInput;
		if (userInput <= INT32_MAX && userInput >= INT32_MIN)//TODO: Verify correct way of determining limits and definition of a legal integer
		{
			std::cin.clear();
			if (nMinimumRange == 0 && nMaximumRange == 0)//allows for any legal integer (no min or max range)
			{
				return userInput;
			}
			if (userInput >= nMinimumRange && userInput <= nMaximumRange)//if user input is within the range of min and max
			{
				return userInput;
			}
			else//loop back to get input again
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Please try again: ";
				std::cin >> userInput;
			}
		}
		else//loop back to get input again
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please try again: ";
			std::cin >> userInput;
		}
	}
	

	//PrintMenu-------------------------------------------------------------------------
	void PrintMenu(const std::string menuOptions[], size_t menuLength)
	{
		for (size_t i = 0; i < menuLength; i++)
		{
			std::cout << i + 1 << ". " << menuOptions[i] << std::endl;
		}

	}
	//----------------------------------------------------------------------------------

	//ClearIgnoreBuffer-----------------------------------------------------------------
	void ClearIgnoreBuffer()
	{
		std::cin.ignore();
		std::cin.clear();
	}
	//----------------------------------------------------------------------------------

	//PrintInteger----------------------------------------------------------------------
	void PrintInteger(const unsigned int valueToPrint)
	{
		int menuChoice;
		std::cout << "Which format would you like your number to be printed in?\n1. Binary\n2. Hex\n3. Oct\n";
		std::cin >> menuChoice;
		switch (menuChoice)
		{
		case(1)://Print Binary
		{
			const int numBits = sizeof(valueToPrint) * 8;//convert bytes to bits
			for (int i = numBits - 1; i >= 0; --i)//loop through bits of _bit starting at most significant bit
			{
				std::cout << ((valueToPrint >> i) & 1);//shift the bit to the least significant bit and output the bit at
				//position "i"
			}
			std::cout << std::endl;
			break;
		}
		case(2):
		{
			std::cout << std::hex << valueToPrint << std::dec << std::endl; //use the standard library hex to swap output to hex format then manually swap back to decimal after printing
			break;
		}
		case(3):
		{
			std::cout << std::oct << valueToPrint << std::oct << std::endl; //use the standard library oct to swap output then manually swap back to decimal
			break;
		}
		default:
			std::cout << "That is not an option, please try again: ";
			std::cin >> menuChoice;
			break;
		}
	}

	//GenerateRandomNumber--------------------------------------------------------------------------
	int GenerateRandomNumber(const int minRange = 0, const int maxRange=0)
	{
		int newNum = rand() % maxRange + minRange;//random number between 0 and 100
		return newNum;
	}
}