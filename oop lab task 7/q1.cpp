#include <iostream>
using namespace std;
class Account
{
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string accountNumber, double balance, string accountHolderName, string accountType) : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType) {};
    string getAccountNumber()
    {
        return accountNumber;
    }
    string getAccountHolderName()
    {
        return accountHolderName;
    }
    double getBalance()
    {
        return balance;
    }
    string getAccountType()
    {
        return accountType;
    }
    void getAccountInfo()
    {
        cout << "account Number:" << accountNumber << endl;
        cout << "balance:" << balance << endl;
        cout << "account holder Name:" << accountHolderName << endl;
        cout << "account type:" << accountType << endl;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "amount:" << amount << " added successfully" << endl;
    }
    virtual void withdraw(double amount)
    {
        if (balance <= 0)
        {
            cout << "insufficent balance";
            return;
        }
        balance -= amount;
        cout << "amount:" << amount << " deducted successfully" << endl;
    }
    virtual void calculateInterest() = 0;
    virtual void printStatement()
    {
        cout << "account Number:" << accountNumber << endl;
        cout << "balance:" << balance << endl;
        cout << "account holder Name:" << accountHolderName << endl;
        cout << "account type:" << accountType << endl;
    }
};
class SavingsAccount : public Account
{
public:
    double interestRate;
    double minimumBalance;
    SavingsAccount(string accountNumber, double balance, string accountHolderName, string accountType, double interestRate, double minimumBalance) : Account(accountNumber, balance, accountHolderName, accountType), interestRate(interestRate), minimumBalance(minimumBalance) {};
    void calculateInterest() override
    {
        double interest = balance * interestRate;
        balance += interest;
        cout << "new balance:" << balance << endl;
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << "interest rate:" << interestRate << endl;
        cout << "minimum balance:" << minimumBalance << endl;
    }
    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
            cout << "amount withdrawn succesfully" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
};
class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(string accountNumber, double balance, string accountHolderName, string accountType, double overdraftLimit) : Account(accountNumber, balance, accountHolderName, accountType), overdraftLimit(overdraftLimit) {};
    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout << "amount withdrawn succesfully" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
    void calculateInterest() override
    {
        cout << "checking account deosnt require interest" << endl;
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << "overdraft limit:" << overdraftLimit << endl;
    }
};
class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    string maturityDate;
    bool flag;

public:
    FixedDepositAccount(string accountNumber, double balance, string accountHolderName, string accountType, double fixedInterestRate, string maturityDate) : Account(accountNumber, balance, accountHolderName, accountType), fixedInterestRate(fixedInterestRate), maturityDate(maturityDate) {};

    void withdraw(double amount) override
    {
        if (flag)
        {
            if (balance >= amount)
            {
                balance -= amount;
                cout << "amount withdrawn successfully" << endl;
            }
            else
            {
                cout << "fixed deposit account has insufficent funds" << endl;
            }
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << " fixed interest rate:" << fixedInterestRate << endl;
        cout << "maturity Date:" << maturityDate << endl;
    }
    void calculateInterest() override
    {
        if (flag)
        {
            double interest = balance * fixedInterestRate;
            balance += interest;
            cout << "interest:" << interest << endl;
            cout << "new balance:" << balance << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
    void changeFlag()
    {
        flag = true;
        cout << "marked" << endl;
    }
};
int main()
{
    SavingsAccount savings("S123", 2000.0, "Alice", "savings", 0.05, 500.0);
    CheckingAccount checking("C456", 1000.0, "Bob", "checking", 200.0);
    FixedDepositAccount fixedDeposit("F789", 5000.0, "Charlie", "fixed", 0.07, "30/12/2025");

    savings.printStatement();
    savings.deposit(500);
    savings.calculateInterest();
    savings.withdraw(1800);
    savings.printStatement();

    checking.printStatement();
    checking.withdraw(1200);
    checking.deposit(300);
    checking.printStatement();

    fixedDeposit.printStatement();
    fixedDeposit.withdraw(1000);
    fixedDeposit.changeFlag();
    fixedDeposit.withdraw(1000);
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}
