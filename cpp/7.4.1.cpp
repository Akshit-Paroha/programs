#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;

public:
    Account(double initialBalance)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
        }
    }

    void displayBalance()
    {
        cout << "Current Balance: rs." << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate) : Account(0)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
        }
        interestRate = rate;
    }

    void applyInterest()
    {
        balance += (balance * interestRate / 100);
        cout << "Interest applied at rate of " << interestRate << "%." << endl;
    }
};

class CheckingAccount : public Account
{
private:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double fee) : Account(0)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
        }
        transactionFee = fee;
    }

    void withdraw(double amount)
    {
        if (amount + transactionFee <= balance)
        {
            balance -= (amount + transactionFee);
            cout << "rs. " << amount << " withdrawn. Transaction fee: $" << transactionFee << endl;
        }
        else
        {
            cout << "Insufficient balance for withdrawal!" << endl;
        }
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "rs." << amount << " deposited successfully." << endl;
    }
};

int main()
{
    SavingsAccount savings(1000, 5);
    savings.displayBalance();
    savings.applyInterest();
    savings.displayBalance();

    CheckingAccount checking(500, 2);
    checking.displayBalance();
    checking.deposit(200);
    checking.displayBalance();
    checking.withdraw(100);
    checking.displayBalance();

    return 0;
}
