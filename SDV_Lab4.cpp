#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"
#include <crtdbg.h>
#define MEMORY_LEAK_LINE -1

void Withdraw(BaseAccount*);
void Deposit(BaseAccount*);

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
    userChecking->Deposit(1000);
    userSavings->Deposit(1000);

    //menu system
    int accountSelect;
    std::string userAccounts[4] = { "Checking", "Savings", "Credit", "Quit"};
    std::string accountOptions[4] = { "Check Balance", "Deposit", "Withdraw", "Main Menu"};
    std::cout << "Which account would you like to access?\n";
    Helper::PrintMenu(userAccounts, 4);
    std::cin >> accountSelect;
    do {
        switch (accountSelect)
        {
        case (1): //Case for Checking Account
        {
            std::cout << "-----------Checking--------------\n";
            int menuSelect;
            Helper::PrintMenu(accountOptions, 4);
            std::cout << "---------------------------------\n";
            std::cin >> menuSelect;
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
                std::cout << "Your current balance is: $" << userBalance << std::endl;
                break;
            }
            case (2)://Checking Deposit 
                // - ask for how much to deposit, get input, call Deposit() on userChecking and put in input, call GetBalance() and output new balance
            {
                float depositAmount;
                std::cout << "How much would you like to deposit?\n";
                std::cin >> depositAmount;
                Helper::ClearIgnoreBuffer();
                userChecking->Deposit(depositAmount);
                float userBalance = userChecking->GetBalance();
                std::cout << "$" << depositAmount << " deposited. Your new balance is: $" << userBalance << std::endl;
                break;
            }
            case (3)://Checking Withdrawal
                // - ask for how much to withdraw, get input, call Withdraw() on userChecking and put in input, call GetBalance() and output new balance
            {
                float withdrawAmount;
                std::cout << "How much would you like to withdraw?\n";
                std::cin >> withdrawAmount;
                Helper::ClearIgnoreBuffer();
                userChecking->Withdraw(withdrawAmount);
                float userBalance = userChecking->GetBalance();
                std::cout << "$" << withdrawAmount << " withdrawn. Your new balance is: $" << userBalance << std::endl;
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
                float userBalance = userSavings->GetBalance();
                std::cout << "Your current balance is: $" << userBalance << std::endl;
                break;
            }
            case (2)://Savings Deposit
            {
                float depositAmount;
                std::cout << "How much would you like to deposit?\n";
                std::cin >> depositAmount;
                userSavings->Deposit(depositAmount);
                float userBalance = userSavings->GetBalance();
                std::cout << "$" << depositAmount << " deposited. Your new balance is: $" << userBalance << std::endl;
                break;
            }
            case (3)://Savings Withdrawal
            {
                float withdrawAmount;
                std::cout << "How much would you like to withdraw?\n";
                std::cin >> withdrawAmount;
                userSavings->Withdraw(withdrawAmount);
                float userBalance = userSavings->GetBalance();
                std::cout << "$" << withdrawAmount << " withdrawn. Your new balance is: $" << userBalance << std::endl;
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
            Helper::PrintMenu(accountOptions, 4);
            std::cout << "-----------Credit--------------\n";
            std::cin >> menuSelect;
            switch (menuSelect)
            {
            case (1)://Credit Balance
            {
                float userBalance = userCredit->GetBalance();
                std::cout << "Your current balance is: $" << userBalance << std::endl;
                break;
            }
            case (2)://Credit deposit
            {
                float depositAmount;
                std::cout << "How much would you like to deposit?\n";
                std::cin >> depositAmount;
                userCredit->Deposit(depositAmount);
                float userBalance = userCredit->GetBalance();
                std::cout << "$" << depositAmount << " deposited. Your new balance is: $" << userBalance << std::endl;
                break;
            }
            case (3)://Credit Withdrawal
            {
                float withdrawAmount;
                std::cout << "How much would you like to withdraw?\n";
                std::cin >> withdrawAmount;
                userCredit->Withdraw(withdrawAmount);
                float userBalance = userCredit->GetBalance();
                std::cout << "$" << withdrawAmount << " withdrawn. Your new balance is: $" << userBalance << std::endl;
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
    }while (accountSelect < 4);

    //delete accounts to free up memory
    delete userChecking;
    delete userSavings;
    delete userCredit;
}

