#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Passenger;

class Flight{
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<Passenger*> passengers;

public:
    Flight(string flightNo, string dep, string arr, int cap)
        : flightNumber(flightNo), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(Passenger& passenger);
    bool cancelSeat(Passenger& passenger);
    bool upgradeSeat(Passenger& passenger);

    string getFlightDetails() const {
        return "Flight Number: " + flightNumber + "\nDeparture: " + departure + "\nArrival: " + arrival;
    }

    int getAvailableSeats() const {
        return capacity - passengers.size();
    }

    bool isSeatBooked(Passenger& passenger);
    bool isSeatUpgraded(Passenger& passenger);

    friend class Passenger;
};

class Passenger {
private:
    string passengerID;
    string name;

public:
    Passenger(string id, string nm) : passengerID(id), name(nm) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat(*this)) {
            cout << "Booking successful for " << name << " on flight " << flight.flightNumber << ".\n";
        } else {
            cout << "Booking failed for " << name << " on flight " << flight.flightNumber << " - No available seats.\n";
        }
    }

    void requestCancellation(Flight& flight) {
        if (flight.cancelSeat(*this)) {
            cout << "Cancellation successful for " << name << " on flight " << flight.flightNumber << ".\n";
        } else {
            cout << "Cancellation failed for " << name << " on flight " << flight.flightNumber << " - Seat not booked.\n";
        }
    }

    void requestUpgrade(Flight& flight) {
        if (flight.upgradeSeat(*this)) {
            cout << "Upgrade successful for " << name << " on flight " << flight.flightNumber << ".\n";
        } else {
            cout << "Upgrade failed for " << name << " on flight " << flight.flightNumber << " - Seat not booked.\n";
        }
    }

    string getPassengerDetails() const {
        return "Passenger ID: " + passengerID + ", Name: " + name;
    }
};

bool Flight::bookSeat(Passenger& passenger) {
    if (getAvailableSeats() > 0 && !isSeatBooked(passenger)) {
        passengers.push_back(&passenger);
        return true;
    }
    return false;
}

bool Flight::cancelSeat(Passenger& passenger) {
    if (isSeatBooked(passenger)) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (*it == &passenger) {
                passengers.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool Flight::upgradeSeat(Passenger& passenger) {
    if (isSeatBooked(passenger) && !isSeatUpgraded(passenger)) {
        cout << passenger.getPassengerDetails() << " has been upgraded on flight " << flightNumber << ".\n";
        return true;
    }
    return false;
}

bool Flight::isSeatBooked(Passenger& passenger) {
    for (auto& p : passengers) {
        if (p == &passenger) {
            return true;
        }
    }
    return false;
}

bool Flight::isSeatUpgraded(Passenger& passenger) {
    return false;
}

int main() {
    Flight flight1("AB123", "New York", "London", 5);
    Flight flight2("CD456", "Los Angeles", "Tokyo", 3);

    Passenger passenger1("P001", "Alice");
    Passenger passenger2("P002", "Bob");
    Passenger passenger3("P003", "Charlie");
    Passenger passenger4("P004", "David");
    Passenger passenger5("P005", "Eva");
    Passenger passenger6("P006", "Frank");

    passenger1.requestBooking(flight1);
    passenger2.requestBooking(flight1);
    passenger3.requestBooking(flight1);
    passenger4.requestBooking(flight1);
    passenger5.requestBooking(flight1);
    passenger6.requestBooking(flight1);

    passenger2.requestCancellation(flight1);
    passenger2.requestUpgrade(flight1);

    passenger6.requestBooking(flight2);
    passenger3.requestCancellation(flight1);

    return 0;
}

