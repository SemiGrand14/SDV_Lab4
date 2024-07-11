#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"

int main()
{
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
    std::string userAccounts[3] = { "Checking", "Savings", "Credit" };
    std::string accountOptions[3] = { "Check Balance", "Deposit", "Withdraw" };
    std::cout << "Which account would you like to access?\n";
    Helper::PrintMenu(userAccounts, 3);
    std::cin >> accountSelect;
    switch (accountSelect)
    {
    case (1): //Case for Checking Account
    {
        int menuSelect;
        Helper::PrintMenu(accountOptions, 3);
        std::cin >> menuSelect;
        switch (menuSelect)
        {
        case (1):
        {
            userChecking->GetBalance();
            break;
        }
        case (2):
        {
            float depositAmount;
            std::cout << "How much would you like to deposit?\n";
            std::cin >> depositAmount;
            userChecking->Deposit(depositAmount);
            break;
        }
        case (3):
        {
            break;
        }
        default:
            break;
        }
        break;
    }
    case (2): //Case for Savings Account
    {
        int menuSelect;
        Helper::PrintMenu(accountOptions, 3);
        std::cin >> menuSelect;
        switch (menuSelect)
        {
        case (1):
        {
            break;
        }
        case (2):
        {
            break;
        }
        case (3):
        {
            break;
        }
        default:
            break;
        }
        break;
        break;
    }
    case (3): //Case for Credit Account
    {
        int menuSelect;
        Helper::PrintMenu(accountOptions, 3);
        std::cin >> menuSelect;
        switch (menuSelect)
        {
        case (1):
        {
            break;
        }
        case (2):
        {
            break;
        }
        case (3):
        {
            break;
        }
        default:
            break;
        }
        break;
        break;
    }
    default:
        break;
    }

    //delete accounts to free up memory
    delete userChecking;
    delete userSavings;
    delete userCredit;
}

