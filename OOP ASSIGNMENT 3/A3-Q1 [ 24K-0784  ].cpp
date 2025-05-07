#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class PaymentException : public exception {
public:
    const char* what() const noexcept override {
        return "Payment processing failed.";
    }
};

class Payment {
    double amount;
    bool paymentStatus;

public:
    Payment(double amount) : amount(amount), paymentStatus(false) {}

    void processPayment() {
        if (amount <= 0) {
            throw PaymentException();
        }
        paymentStatus = true;
        cout << "Payment of amount " << amount << " has been processed." << endl;
    }

    bool getPaymentStatus() const {
        return paymentStatus;
    }
};

class Person {
protected:
    string name;
    int ID;
    string cardNumber;
    bool paymentStatus;

public:
    Person(string name, int ID, string cardNumber)
        : name(name), ID(ID), cardNumber(cardNumber), paymentStatus(false) {}

    virtual void payFees(Payment& payment) = 0;
    virtual void showDetails() const = 0;
    bool getPaymentStatus() const {
        return paymentStatus;
    }
    string getName() const {
        return name;
    }
    int getID() const {
        return ID;
    }
};

class Student : public Person {
public:
    Student(string name, int ID, string cardNumber)
        : Person(name, ID, cardNumber) {}

    void payFees(Payment& payment) override {
        try {
            payment.processPayment();
            paymentStatus = true;
            cout << "Student " << name << " has paid semester fees." << endl;
        } catch (const PaymentException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void showDetails() const override {
        cout << "Student ID: " << ID << ", Name: " << name << ", Card: " << cardNumber
             << ", Payment: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
    }
};

class Teacher : public Person {
public:
    Teacher(string name, int ID, string cardNumber)
        : Person(name, ID, cardNumber) {}

    void payFees(Payment& payment) override {
        try {
            payment.processPayment();
            paymentStatus = true;
            cout << "Teacher " << name << " has paid monthly fees." << endl;
        } catch (const PaymentException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void showDetails() const override {
        cout << "Teacher ID: " << ID << ", Name: " << name << ", Card: " << cardNumber
             << ", Payment: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
    }
};

class Staff : public Person {
public:
    Staff(string name, int ID, string cardNumber)
        : Person(name, ID, cardNumber) {}

    void payFees(Payment& payment) override {
        try {
            payment.processPayment();
            paymentStatus = true;
            cout << "Staff member " << name << " has paid monthly fees." << endl;
        } catch (const PaymentException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void showDetails() const override {
        cout << "Staff ID: " << ID << ", Name: " << name << ", Card: " << cardNumber
             << ", Payment: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
    }
};

class Stop {
    int stopID;
    string stopName;
    string location;

public:
    Stop(int stopID, string stopName, string location)
        : stopID(stopID), stopName(stopName), location(location) {}

    void getStopDetails() const {
        cout << "Stop ID: " << stopID << ", Stop Name: " << stopName << ", Location: " << location << endl;
    }
};

class Route {
    int routeID;
    string routeName;
    vector<Stop> stops;

public:
    Route(int routeID, string routeName)
        : routeID(routeID), routeName(routeName) {}

    void addStop(const Stop& stop) {
        stops.push_back(stop);
        cout << "Stop added to " << routeName << endl;
    }

    void getAllStops() const {
        for (const auto& stop : stops) {
            stop.getStopDetails();
        }
    }

    string getRouteName() const {
        return routeName;
    }

    bool operator==(const Route& other) const {
        return routeID == other.routeID;
    }
};

class Bus {
    int busID;
    Route route;
    vector<Person*> passengers;

public:
    Bus(int busID, Route route) : busID(busID), route(route) {}

    void assignRoute(Route& newRoute) {
        route = newRoute;
        cout << "Bus " << busID << " assigned to route " << newRoute.getRouteName() << endl;
    }

    void tapCard(Person& person) {
        if (person.getPaymentStatus()) {
            passengers.push_back(&person);
            cout << person.getName() << " has tapped in." << endl;
        } else {
            cout << person.getName() << " has not paid and cannot enter." << endl;
        }
    }

    void viewAttendance() const {
        for (const auto& passenger : passengers) {
            passenger->showDetails();
        }
    }
};

void writeStudentToFile(const Student& s) {
    ofstream file("students.bin", ios::binary | ios::app);
    if (!file) {
        cerr << "Could not open students.bin for writing." << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    file.close();
}

int main() {
    cout << "FAST's Transportation System\n\n";

    Student student1("John Smith", 101, "12345");
    Teacher teacher1("Alice Brown", 201, "54321");
    Staff staff1("Bob White", 301, "67890");

    Payment p1(200), p2(150), p3(150);
    student1.payFees(p1);
    teacher1.payFees(p2);
    staff1.payFees(p3);

    Stop stop1(1, "Main Street", "Location A");
    Stop stop2(2, "University Road", "Location B");

    Route route1(1, "Route A");
    route1.addStop(stop1);
    route1.addStop(stop2);

    Bus bus1(101, route1);
    bus1.assignRoute(route1);

    bus1.tapCard(student1);
    bus1.tapCard(teacher1);
    bus1.tapCard(staff1);

    cout << "\nBus Attendance:\n";
    bus1.viewAttendance();

    Route route2(1, "Route A");
    if (route1 == route2) {
        cout << "Route 1 and Route 2 are the same!" << endl;
    } else {
        cout << "Route 1 and Route 2 are different." << endl;
    }

    return 0;
}
