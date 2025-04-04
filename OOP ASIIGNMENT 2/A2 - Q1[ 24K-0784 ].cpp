#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int id;
      public:
    Person(string n,int i) :name(n),id(i){}
    virtual void display() const{
        cout<<"Name: "<< name <<", ID: "<<id<<endl;
    }
    virtual ~Person(){}
};

class Student :public Person {
    double semesterFee;
public:
    Student(string n,int i,double fee):Person(n,i),semesterFee(fee) {}
    void display() const override {
        cout << "Student - ";
        Person::display();
        cout << "Semester Fee: " << semesterFee << endl;
    }
};

class Teacher : public Person {
    double monthlySalary;
public:
    Teacher(string n,int i,double salary):Person(n, i), monthlySalary(salary) {}
    void display() const override {
        cout << "Teacher - ";
        Person::display();
        cout << "Monthly Salary: " << monthlySalary << endl;
    }
};

class Route {
    string pickup;
    string dropoff;
public:
    Route(string p, string d) : pickup(p), dropoff(d) {}
    void display() const {
        cout << "Route: " << pickup << " to " << dropoff << endl;
    }
    bool operator==(const Route& r) const {
        return (pickup == r.pickup && dropoff == r.dropoff);
    }
};

class TransportationSystem {
    vector<Person*> users;
    vector<Route> routes;
public:
    void addUser(Person* p) {
        users.push_back(p);
    }
    void addRoute(const Route& r) {
        routes.push_back(r);
    }
    void displayUsers() const {
        for (auto u : users)
            u->display();
    }
    void displayRoutes() const {
        for (const auto& r : routes)
            r.display();
    }
    ~TransportationSystem() {
        for (auto u : users)
            delete u;
    }
};

int main() {
    TransportationSystem system;
    
    // Adding user
    system.addUser(new Student("Alice", 101, 5000));
    system.addUser(new Teacher("Dr. Smith", 201, 20000));
    
    // Adding routes
    Route r1("Stop A", "Stop B");
    Route r2("Stop A", "Stop B");
    system.addRoute(r1);
    system.addRoute(Route("Stop C", "Stop D"));
    
    // Displaying
    cout << "Users in the system:\n";
    system.displayUsers();
    cout << "\nRoutes in the system:\n";
    system.displayRoutes();
    
    // Checking operator overloading
    if (r1 == r2) {
        cout << "Routes r1 and r2 are the same." << endl;
    } else {
        cout << "Routes r1 and r2 are different." << endl;
    }
    
    return 0;
}

