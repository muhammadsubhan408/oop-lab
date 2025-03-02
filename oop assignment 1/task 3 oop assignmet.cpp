#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string userID;
    string name;
    int age;
    string licenseType;
    string contactInfo;

public:
    User() {}

    User(string id,string n,int a,string license,string contact) 
        : userID(id),name(n),age(a),licenseType(license),contactInfo(contact) {}

    void updateDetails(string newName, int newAge,string newLicense, string newContact) {
        name=newName;
        age=newAge;
        licenseType=newLicense;
        contactInfo=newContact;
    }

    string getLicenseType() { return licenseType; }

    void displayUserInfo() {
        cout << "User ID: " << userID << ", Name: " << name 
             << ", Age: " << age << ", License: " << licenseType 
             << ", Contact: " << contactInfo << endl;
    }
};

// Vehicle class
class Vehicle {
private:
    string model;
    double rentalPrice;
    string requiredLicense;

public:
    Vehicle() {} 

    Vehicle(string m, double price, string license) 
        : model(m), rentalPrice(price), requiredLicense(license) {}

    bool isEligible(string userLicense) {
        return (userLicense == requiredLicense || 
               (userLicense == "Intermediate" && requiredLicense != "Full") ||
               (userLicense == "Full"));
    }

    void displayVehicle() {
        cout << "Model: " << model << ", Price per day: $" << rentalPrice 
             << ", Required License: " << requiredLicense << endl;
    }

    string getModel() { return model; }
};

// Rental System
class RentalSystem {
private:
    User** users;
    Vehicle** vehicles;
    int userCount;
    int vehicleCount;

public:
    RentalSystem() {
        userCount = 0;
        vehicleCount = 0;
        users = new User*[100]; 
        vehicles = new Vehicle*[100]; 
    }

    void addUser(string id, string name, int age, string license, string contact) {
        users[userCount++] = new User(id, name, age, license, contact);
    }

    void addVehicle(string model, double price, string license) {
        vehicles[vehicleCount++] = new Vehicle(model, price, license);
    }

    void displayVehicles() {
        cout << "\nAvailable Vehicles:\n";
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->displayVehicle();
        }
    }

    void rentVehicle(string userID, string model) {
        User* user = nullptr;
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getLicenseType() == userID) {
                user = users[i];
                break;
            }
        }

        if (!user) {
            cout << "User not found!\n";
            return;
        }

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getModel() == model) {
                if (vehicles[i]->isEligible(user->getLicenseType())) {
                    cout << "Vehicle rented successfully!\n";
                    return;
                } else {
                    cout << "You are not eligible to rent this vehicle.\n";
                    return;
                }
            }
        }
        cout << "Vehicle not found!\n";
    }

    ~RentalSystem() {
        for (int i = 0; i < userCount; i++) delete users[i];
        for (int i = 0; i < vehicleCount; i++) delete vehicles[i];
        delete[] users;
        delete[] vehicles;
    }
};

int main() {
    RentalSystem system;
    
    system.addUser("U001", "Alice", 25, "Full", "1234567890");
    system.addUser("U002", "Bob", 20, "Learner", "0987654321");

    system.addVehicle("Toyota Corolla", 50, "Full");
    system.addVehicle("Honda Civic", 40, "Intermediate");
    system.addVehicle("Suzuki Alto", 30, "Learner");

    system.displayVehicles();

    system.rentVehicle("U001", "Toyota Corolla");
    system.rentVehicle("U002", "Honda Civic");

    return 0;
}
