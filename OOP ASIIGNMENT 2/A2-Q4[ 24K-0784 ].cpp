#include <iostream>
using namespace std;

// Hash function for passwords
unsigned int hashPassword(string password) {
    unsigned int hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return hash;
}

// Base User class
class User {
protected:
    string name, id;
    string role;
    unsigned int hashed_password;
public:
    User(string name, string id, string password, string role) : name(name), id(id), role(role) {
        hashed_password = hashPassword(password);
    }
    virtual void display() {
        cout << "User: " << name << " (" << role << ") ID: " << id << endl;
    }
    virtual void accessLab() {
        cout << name << " checking lab access." << endl;
    }
    friend void authenticateAndPerformAction(User* user, string action);
};

// Derived Student class
class Student : public User {
private:
    int assignments[5]; // 0 = not submitted, 1 = submitted
public:
    Student(string name, string id, string password) : User(name, id, password, "Student") {
        for (int i = 0; i < 5; i++) assignments[i] = 0;
    }
    void display() override {
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < 5; i++) {
            cout << "Assignment " << i+1 << " Status: " << (assignments[i] ? "Submitted" : "Not Submitted") << " | ";
        }
        cout << endl;
    }
    void submitAssignment(int index) {
        if (index >= 0 && index < 5) {
            assignments[index] = 1;
            cout << "Assignment " << index+1 << " submitted successfully!\n";
        }
    }
};

// Derived TA class
class TA : public Student {
private:
    Student* assignedStudents[10];
    string projects[2];
    int studentCount, projectCount;
public:
    TA(string name, string id, string password) : Student(name, id, password) {
        role = "TA";
        studentCount = 0;
        projectCount = 0;
    }
    void display() override {
        User::display();
        cout << "TA Managing " << studentCount << " students and " << projectCount << " projects." << endl;
    }
    void assignStudent(Student* student) {
        if (studentCount < 10) {
            assignedStudents[studentCount++] = student;
        }
    }
    void assignProject(string project) {
        if (projectCount < 2) {
            projects[projectCount++] = project;
        }
    }
};

// Derived Professor class
class Professor : public User {
private:
    TA* assignedTAs[2];
    int taCount;
public:
    Professor(string name, string id, string password) : User(name, id, password, "Professor"), taCount(0) {}
    void display() override {
        User::display();
        cout << "Professor managing " << taCount << " TAs." << endl;
    }
    void assignTA(TA* ta) {
        if (taCount < 2) {
            assignedTAs[taCount++] = ta;
        }
    }
};

// Authentication and action execution
void authenticateAndPerformAction(User* user, string action) {
    cout << user->name << " performing action: " << action << endl;
    if (user->role == "Student" && action == "submit") {
        ((Student*)user)->submitAssignment(0);
    } else if (user->role == "TA" && action == "manage_students") {
        cout << "Managing students..." << endl;
    } else if (user->role == "Professor" && action == "assign_projects") {
        cout << "Assigning projects..." << endl;
    } else {
        cout << "Permission Denied!" << endl;
    }
}

int main() {
    Student s1("Alice", "S101", "pass123");
    TA ta1("Bob", "T201", "pass456");
    Professor p1("Dr. Smith", "P301", "pass789");
    
    s1.display();
    authenticateAndPerformAction(&s1, "submit");
    s1.display();
    
    ta1.display();
    authenticateAndPerformAction(&ta1, "manage_students");
    
    p1.display();
    authenticateAndPerformAction(&p1, "assign_projects");
    
    return 0;
}

