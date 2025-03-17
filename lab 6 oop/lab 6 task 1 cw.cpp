#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum,double initialBalance = 0)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    virtual void display() const {
        cout << "Account " << accountNumber << ": Balance = $" << balance << endl;
    }

    virtual ~BankAccount() = default; // Virtual destructor for proper cleanup
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double initialBalance = 0, double rate = 0.01)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        cout << "Interest applied: $" << interest << endl;
    }

    void display() const override {
        cout << "Savings ";
        BankAccount::display();
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double initialBalance = 0, double limit = 100)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
            if (balance < 0) {
                cout << "ALERT: Overdraft limit reached!" << endl;
            }
        } else {
            cout << "Withdrawal denied. Insufficient funds or invalid amount." << endl;
        }
    }

    void display() const override {
        cout << "Checking ";
        BankAccount::display();
    }
};


class BusinessAccount : public BankAccount {
private:
    double taxRate;

public:
    BusinessAccount(const string& accNum, double initialBalance = 0, double rate = 0.1)
        : BankAccount(accNum, initialBalance), taxRate(rate) {}

    void deposit(double amount) override {
        if (amount > 0) {
            double tax = amount * taxRate;
            double netAmount = amount - tax;
            balance += netAmount;
            cout << "Deposited $" << amount << ". Tax withheld: $" << tax
                 << ". Net deposit: $" << netAmount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void display() const override {
        cout << "Business ";
        BankAccount::display();
    }
};

class User {
protected:
    string name;

public:
    User(const string& userName) : name(userName) {}

    virtual void performAction(BankAccount& account) = 0; // Pure virtual function

    virtual ~User() = default; // Virtual destructor for proper cleanup
};


class Customer : public User {
public:
    Customer(const string& userName) : User(userName) {}

    void performAction(BankAccount& account) override {
        cout << "Customer " << name << " is performing actions on account." << endl;
        account.deposit(100);
        account.withdraw(50);
    }
};


class Manager : public User {
public:
    Manager(const string& userName) : User(userName) {}

    void performAction(BankAccount& account) override {
        cout << "Manager " << name << " is performing actions on account." << endl;
        account.deposit(500);
        account.withdraw(250);
    }
};
