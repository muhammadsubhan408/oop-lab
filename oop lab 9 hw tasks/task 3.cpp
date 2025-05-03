#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    float salary;

public:
    virtual void getdata() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();
    }

    virtual void displaydata() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    virtual void bonus() {
        cout << "Generic Person Bonus: " << salary * 0.05 << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getdata() {
        cout << "Enter Admin details:" << endl;
        Person::getdata();
    }

    void displaydata() {
        cout << "Admin:"<<endl;
        Person::displaydata();
    }

    void bonus() {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
public:
    void getdata() {
        cout << "Enter Account details:" << endl;
        Person::getdata();
    }

    void displaydata() {
        cout << "Account: "<<endl;
        Person::displaydata();
    }

    void bonus() {
        cout << "Account Bonus: " << salary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() {
        cout << "Enter Master Employee details:" << endl;
        Person::getdata();
    }

    void displaydata() {
        cout << "Master:"<<endl;
        Person::displaydata();
    }

    void bonus() {
        cout << "Master Bonus: " << salary * 0.15 << endl;
    }
};

int main() {
    Person* emp;

    Master m;
    emp = &m;

    emp->getdata();
    emp->displaydata();
    emp->bonus();

    return 0;
}
