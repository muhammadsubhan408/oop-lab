#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Vehicle {
protected:
    static int activeDeliveries;
    string vehicleID;
public:
    Vehicle(string id) : vehicleID(id) { activeDeliveries++; }
    virtual ~Vehicle() { activeDeliveries--; }
    virtual void deliver(string packageID, int urgencyLevel = 0) const = 0;
    virtual void calculateRoute() const {
        cout << "Vehicle " << vehicleID << " calculating the optimal delivery route..." << endl;
    }
    static int getActiveDeliveries() { return activeDeliveries; }
};
int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id) : Vehicle(id) {}
    void deliver(string packageID, int urgencyLevel = 0) const override {
        cout << "RamzanDrone " << vehicleID << " delivering package " << packageID;
        if (urgencyLevel > 5)
            cout << " at high-speed for Iftar meal!";
        cout << endl;
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id) : Vehicle(id) {}
    void deliver(string packageID, int urgencyLevel = 0) const override {
        cout << "RamzanTimeShip " << vehicleID << " ensuring historical consistency for package " << packageID;
        if (urgencyLevel > 5)
            cout << " - extra validation required!";
        cout << endl;
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id) : Vehicle(id) {}
    void deliver(string packageID, int urgencyLevel = 0) const override {
        cout << "RamzanHyperPod " << vehicleID << " using underground tunnels for bulk delivery of package " << packageID << endl;
    }
};

void resolveConflict(const Vehicle &v1, const Vehicle &v2, string packageID) {
    cout << "Conflict detected between " << typeid(v1).name() << " and " << typeid(v2).name() << " for package " << packageID << "." << endl;
    cout << "Deciding based on speed and efficiency..." << endl;
    v1.deliver(packageID);
}

int main() {
    RamzanDrone d1("D1");
    RamzanTimeShip t1("T1");
    RamzanHyperPod h1("H1");

    cout << "Total active deliveries: " << Vehicle::getActiveDeliveries() << endl;

    d1.deliver("PKG101", 6);
    t1.deliver("PKG102", 3);
    h1.deliver("PKG103", 0);
    
    resolveConflict(d1, t1, "PKG200");
    
    return 0;
}
