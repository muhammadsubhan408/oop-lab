#include <iostream>
using namespace std;

// Forward Declaration
class BusRoute;

// Student Class
class Student {
private:
    const string studentID;
    string name;
    bool feePaid;
    static int totalStudents; // Static variable

public:
    Student(string id, string n) : studentID(id), name(n), feePaid(false) {
    	
    	
        totalStudents++;
    }

    ~Student() {
    	
        totalStudents--;
    }

    void payFee() {
    	
        feePaid=true;
        cout << name << " has paid the semester fee.\n";
    }

    bool isFeePaid() const {return feePaid;}
    string getID() const {return studentID;}
    string getName() const {return name;}

    static int getTotalStudents() {return totalStudents;}
};

int Student::totalStudents=0; 


class BusStop {
private:
    string stopName;

public:
    BusStop() : stopName("") {} // Default constructor
    BusStop(string name) : stopName(name) {}

    string getStopName() const {return stopName;}
};

class BusRoute {
private:
    string routeID;
    BusStop* stops; 
    int stopCount;

    Student** assignedStudents; 
    int studentCount;
public:
    BusRoute(string id, int maxStops, int maxStudents) : routeID(id), stopCount(0), studentCount(0) {
        stops = new BusStop[maxStops]; 
        assignedStudents = new Student*[maxStudents]; 
    }

    ~BusRoute() {
    	
        delete[] stops; 
        delete[] assignedStudents; 
    }

    void addStop(string stopName) {
    	
        stops[stopCount++] = BusStop(stopName);
    }

    void assignStudent(Student* student) {
    	
        if (student->isFeePaid()) {
            assignedStudents[studentCount++] = student;
            cout << student->getName() << " assigned to route " << routeID << endl;
        } else {
            cout << "Fee not paid. Cannot assign " << student->getName() << " to route.\n";
        }
        
    }

    void recordAttendance(string studentID) {
        for (int i = 0; i < studentCount; i++) {
            if (assignedStudents[i]->getID() == studentID) {
                cout << "Attendance recorded for " << assignedStudents[i]->getName() << endl;
                return;
            }
        }
        cout << "Student not found on this route!\n";
    }

    void displayRoute() const {
    	
        cout << "Route " << routeID << " Stops: ";
        for (int i = 0; i < stopCount; i++) {
            cout << stops[i].getStopName() << " -> ";
        }
        cout << "End\n";
        
    }
    
};

// Main Function
int main() {
   
    Student s1("S101", "Alice");
    Student s2("S102", "Bob");

    s1.payFee(); 
    BusRoute route1("R1", 5, 5);
    route1.addStop("Stop A");
    route1.addStop("Stop B");
    route1.addStop("Campus");

  
    route1.assignStudent(&s1);
    route1.assignStudent(&s2);

    
    route1.recordAttendance("S101");
    route1.recordAttendance("S102");

    route1.displayRoute();

    cout << "Total registered students: " << Student::getTotalStudents() << endl;

    return 0;
}
