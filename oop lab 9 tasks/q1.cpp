#include<iostream>
#include<string>
using namespace std;

class Wallet{
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    const double maxDailyDeposit = 5000.0;
    const double maxDailyWithdraw = 3000.0;

public:
    Wallet(){
        balance = 0.0;
        dailyDepositTotal = 0.0;
        dailyWithdrawTotal = 0.0;
    }
    bool deposit(double amount){
        if(amount <= 0){
            cout << "Deposit must be positive." << endl;
            return false;
        }
        if(dailyDepositTotal + amount > maxDailyDeposit){
            cout << "Deposit exceeds daily limit." << endl;
            return false;
        }
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposited: $" << amount << ". Balance: $" << balance << endl;
        return true;
    }

    bool withdraw(double amount){
        if(amount <= 0){
            cout << "Withdrawal must be positive." << endl;
            return false;
        }
        if(dailyWithdrawTotal + amount > maxDailyWithdraw){
            cout << "Withdrawal exceeds daily limit." << endl;
            return false;
        }
        if(amount > balance){
            cout << "Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrew: $" << amount << ". Balance: $" << balance << endl;
        return true;
    }

    double getBalance(){
        return balance;
    }
};

class User{
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string username){
        userID = id;
        name = username;
    }

    void deposit(double amount){
        cout << name << ": ";
        wallet.deposit(amount);
    }

    void withdraw(double amount){
        cout << name << ": ";
        wallet.withdraw(amount);
    }

    void showBalance(){
        cout << name << ": Balance is $" << wallet.getBalance() << endl;
    }
};

int main(){
    User alice("001", "Alice");
    User bob("002", "Bob");

    cout << "Alice's Transactions:" << endl;
    alice.deposit(1000);
    alice.deposit(4500);
    alice.withdraw(500);
    alice.withdraw(3000);
    alice.showBalance();

    cout << "\nBob's Transactions:" << endl;
    bob.deposit(2500);
    bob.withdraw(200);
    bob.withdraw(3000);
    bob.showBalance();




    return 0;
}

