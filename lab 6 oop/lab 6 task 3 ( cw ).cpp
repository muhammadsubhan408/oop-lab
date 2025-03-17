#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
protected:
    int id;
    string name;
public:
    Employee(int empId,const string& empName):id(empId), name(empName){}
    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() = default; // Virtual destructor for proper cleanup
};

class IOrderTaker {
public:
    virtual void takeOrder(const string& order)=0; // Pure virtual function
    virtual ~IOrderTaker()=default;
};

class IOrderPreparer {
public:
    virtual void prepareOrder(const string& order)=0; // Pure virtual function
    virtual ~IOrderPreparer()=default;
};



class IBiller {
public:
    virtual void generateBill(const string& order) = 0; // Pure virtual function
    virtual ~IBiller()=default;
};


class Waiter:public Employee,public IOrderTaker {
public:
    Waiter(int empId, const string& empName):Employee(empId, empName) {}

    void takeOrder(const string& order) override {
        cout <<"Waiter "<<name<<" is taking order: "<< order << endl;
    }

    void display() const override {
        cout << "Waiter - ";
        Employee::display();
    }
};


class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, const string& empName) : Employee(empId, empName) {}

    void prepareOrder(const string& order) override {
        cout << "Chef " << name << " is preparing order: " << order << endl;
    }

    void display() const override {
        cout << "Chef - ";
        Employee::display();
    }
};


class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, const string& empName) : Employee(empId, empName) {}

    void generateBill(const string& order) override {
        cout << "Cashier " << name << " is generating bill for order: " << order << endl;
    }

    void display() const override {
        cout << "Cashier - ";
        Employee::display();
    }
};


class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, const string& empName) : Employee(empId, empName) {}

    void takeOrder(const string& order) override {
        cout << "Manager " << name << " is taking order: " << order << endl;
    }

    void generateBill(const string& order) override {
        cout << "Manager " << name << " is generating bill for order: " << order << endl;
    }

    void display() const override {
        cout << "Manager - ";
        Employee::display();
    }
};



class Menu {
protected:
    string name;
    double baseCost;

public:
    Menu(const string& menuName, double cost) : name(menuName), baseCost(cost) {}

    virtual double calculateTotalCost() const {
        return baseCost;
    }

    virtual void display() const {
        cout << "Menu: " << name << ", Base Cost: $" << baseCost << endl;
    }

    virtual ~Menu() = default;
};



class FoodMenu : public Menu {
public:
    FoodMenu(const string& menuName, double cost) : Menu(menuName, cost) {}

    double calculateTotalCost() const override {
        // Apply a 10% service charge for food
        return baseCost * 1.10;
    }

    void display() const override {
        cout << "Food ";
        Menu::display();
    }
};



class BeverageMenu : public Menu {
public:
    BeverageMenu(const string& menuName, double cost) : Menu(menuName, cost) {}

    double calculateTotalCost() const override {
        // Apply a 15% tax for beverages
        return baseCost * 1.15;
    }

    void display() const override {
        cout << "Beverage ";
        Menu::display();
    }
};



int main() {
    // Create employees
    Waiter waiter(1, "John Doe");
    Chef chef(2, "Jane Smith");
    Cashier cashier(3, "Alice Johnson");
    Manager manager(4, "Bob Brown");

    // Create menus
    FoodMenu foodMenu("Pizza", 10.0);
    BeverageMenu beverageMenu("Coffee", 5.0);

    // Display employees
    waiter.display();
    chef.display();
    cashier.display();
    manager.display();

    // Demonstrate roles
    waiter.takeOrder("Pizza");
    chef.prepareOrder("Pizza");
    cashier.generateBill("Pizza");

    // Manager can take orders and generate bills
    manager.takeOrder("Coffee");
    manager.generateBill("Coffee");

    // Display menus and calculate total costs
    foodMenu.display();
    cout << "Total Cost: $" << foodMenu.calculateTotalCost() << endl;

    beverageMenu.display();
    cout << "Total Cost: $" << beverageMenu.calculateTotalCost() << endl;

    return 0;
}
