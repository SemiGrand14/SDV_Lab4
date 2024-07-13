#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"//add in helper file
#include <crtdbg.h>
#define MEMORY_LEAK_LINE 1

void Withdraw(BaseAccount* userAccount, float amount);
void Deposit(BaseAccount* userAccount, float amount);

int main()
{
	// include memory leak detection ( needs to be at top of main )
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // set block of memory to find memory leak
	_CrtDumpMemoryLeaks();

	std::cout << "Accounts initializing...";

	//initialize all instances of accounts with new
	CheckingAccount* userChecking = new CheckingAccount();
	SavingsAccount* userSavings = new SavingsAccount();
	CreditAccount* userCredit = new CreditAccount();

	//Start checking and savings with $1000
	std::cout << "\nCongratulations, your recent investment in DogeCoin paid off! Your checking and savings accounts each have $1000.\n";
	Deposit(userChecking, 1000);
	Deposit(userSavings, 1000);

	//menu system
	int accountSelect;
	std::string userAccounts[4] = { "Checking", "Savings", "Credit", "Quit" };
	std::string accountOptions[4] = { "Check Balance", "Deposit", "Withdraw", "Main Menu" };
	std::cout << "Which account would you like to access?\n";
	Helper::PrintMenu(userAccounts, 4);//print main menu
	std::cin >> accountSelect;//take user input
	do {//start menu loop
		switch (accountSelect)//switch for different accounts
		{
		case (1): //Case for Checking Account
		{
			std::cout << "-----------Checking--------------\n";
			int menuSelect;
			Helper::PrintMenu(accountOptions, 4);//print account options
			std::cout << "---------------------------------\n";
			std::cin >> menuSelect;//take input
			switch (menuSelect)
			{

				//TODO: CHECKING ACCOUNT ITEMS:
				// Show Balance - done
				// Deposit Cash - done
				// Withdraw Cash - done

			case (1)://Checking Balance 
				//- call GetBalance() on userChecking and print it to the screen
			{
				float userBalance = userChecking->GetBalance();
				std::cout << "Your current balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (2)://Checking Deposit 
				// - ask for how much to deposit, get input, call Deposit(), call GetBalance() and output new balance
			{
				float depositAmount;
				std::cout << "How much would you like to deposit?\n";
				std::cin >> depositAmount;
				Helper::ClearIgnoreBuffer();
				Deposit(userChecking, depositAmount);
				float userBalance = userChecking->GetBalance();
				std::cout << "\033[32m$" << depositAmount << "\033[0m deposited. Your new balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (3)://Checking Withdrawal
				//  call Withdraw(), call GetBalance() and output new balance
			{
				float withdrawAmount;
				std::cout << "How much would you like to withdraw?\n";
				std::cin >> withdrawAmount;//amount to withdraw
				Helper::ClearIgnoreBuffer();//cin.clear and cin.ingnore
				float userBalance = userChecking->GetBalance();//get balance of current account
				if (userBalance != 0)//if the user has money in the account
				{
					Withdraw(userChecking, withdrawAmount);//call withdraw
					float userBalance = userChecking->GetBalance();//get new balance and print
					Helper::TextColorChange("31");
					std::cout << "$" << withdrawAmount<< "\033[0m withdrawn. Your new balance is: \033[32m$" << userBalance << std::endl;
					Helper::TextFormattingReset();
				}
				else//if they don't have money in account
				{
					std::cout << "\033[31m$0\033[0m" << 0 << " withdrawn. Your new balance is: \033[32m$" << userBalance << std::endl;
					Helper::TextFormattingReset();
				}

				break;
			}
			case (4)://Return to main menu
			{
				Helper::ClearScreen();//clears screen
				Helper::PrintMenu(userAccounts, 4);//print main menu
				std::cin >> accountSelect;//get input
				break;
			}
			default:
				break;
			}
			break;
		}
		case (2): //Case for Savings Account

			//TODO: CHECKING ACCOUNT ITEMS:
				// Show Balance - done
				// Deposit Cash - done
				// Withdraw Cash - done

		{
			int menuSelect;
			std::cout << "-----------Savings--------------\n";
			Helper::PrintMenu(accountOptions, 4);
			std::cout << "--------------------------------\n";
			std::cin >> menuSelect;
			switch (menuSelect)
			{
			case (1)://Savings Balance
			{
				float userBalance = userSavings->GetBalance();//get balance and print for current account
				std::cout << "Your current balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (2)://Savings Deposit
			{
				float depositAmount;
				std::cout << "How much would you like to deposit?\n";
				std::cin >> depositAmount;//get input for amount to deposit
				Deposit(userSavings, depositAmount);//add money to account
				float userBalance = userSavings->GetBalance();//get new balance and print
				std::cout << "\033[32m$" << depositAmount << "\033[0m deposited. Your new balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (3)://Savings Withdrawal
			{
				float withdrawAmount;
				std::cout << "How much would you like to withdraw?\n";
				std::cin >> withdrawAmount;//get input
				float userBalance = userSavings->GetBalance();//check balance first
				if (userBalance != 0)//if the user has money in the account
				{
					Withdraw(userSavings, withdrawAmount);//call withdraw
					float userBalance = userSavings->GetBalance();//get new balance and print
					std::cout << "\033[31m$" << withdrawAmount << "\033[0m withdrawn. Your new balance is: \033[32m$" << userBalance << std::endl;
					Helper::TextFormattingReset();
				}
				else//if they don't have money in account
				{
					std::cout << "\033[31m$" << 0 << "\033[0m withdrawn. Your new balance is: \033[32m$" << userBalance << std::endl;
					Helper::TextFormattingReset();
				}
				break;
			}
			case (4)://Return to main menu
			{
				Helper::ClearScreen();
				Helper::PrintMenu(userAccounts, 4);
				std::cin >> accountSelect;
				break;
			}
			default:
				break;
			}
			break;
		}
		case (3): //Case for Credit Account
		{
			//TODO: Credit ACCOUNT ITEMS:
				// Show Balance - done
				// Deposit Cash - done
				// Withdraw Cash - done

			int menuSelect;
			std::cout << "-----------Credit--------------\n";
			Helper::PrintMenu(accountOptions, 4);//print menu
			std::cout << "-----------Credit--------------\n";
			std::cin >> menuSelect;//get input
			switch (menuSelect)//start account options switch
			{
			case (1)://Credit Balance
			{
				float userBalance = userCredit->GetBalance();//get balance for current account and print
				std::cout << "Your current balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (2)://Credit deposit
			{
				float depositAmount;
				std::cout << "How much would you like to deposit?\n";
				std::cin >> depositAmount;//get input
				Deposit(userCredit, depositAmount);//call Deposit for current account
				float userBalance = userCredit->GetBalance();//get new balance and print
				std::cout << "\033[32m$" << depositAmount << "\033[0m deposited. Your new balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (3)://Credit Withdrawal - you spending money on card. Balance goes up as you make withdrawals.
			{
				float withdrawAmount;
				std::cout << "How much would you like to withdraw?\n";
				std::cin >> withdrawAmount; //get input
				Withdraw(userCredit, withdrawAmount); //call Withdraw() for current account
				float userBalance = userCredit->GetBalance(); //get new balance and print
				std::cout << "\033[31m$" << withdrawAmount << "\033[0m withdrawn. Your new balance is: \033[32m$" << userBalance << std::endl;
				Helper::TextFormattingReset();
				break;
			}
			case (4)://Return to main menu
			{
				Helper::ClearScreen();
				Helper::PrintMenu(userAccounts, 4);
				std::cin >> accountSelect;
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	} while (accountSelect < 4);//loop so long as the input is less than 4

	//delete accounts to free up memory
	delete userChecking;
	delete userSavings;
	delete userCredit;
}
void Withdraw(BaseAccount* userAccount, float amount) // BaseAccount pointer for selected user account and ammount to withdraw as parameters
{
	userAccount->Withdraw(amount); //pass the selected account point to the withdraw function
}
void Deposit(BaseAccount* userAccount, float amount) //same as Withdraw()
{
	userAccount->Deposit(amount);
}

