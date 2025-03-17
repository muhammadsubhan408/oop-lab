#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;
    string department;

public:
    Student(const string& studentName, int studentRollNumber, const string& studentDepartment)
        : name(studentName), rollNumber(studentRollNumber), department(studentDepartment) {}

    void displayStudentDetails() const {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Department: " << department << endl;
    }
};

class Marks : public Student {
protected:
    static const int MAX_COURSES = 5; // Maximum number of courses
    int courseMarks[MAX_COURSES];
    int numCourses; // Number of courses

public:
    Marks(const string& studentName, int studentRollNumber, const string& studentDepartment, const int marks[], int numCourses)
        : Student(studentName, studentRollNumber, studentDepartment), numCourses(numCourses) {
        for (int i = 0; i < numCourses; ++i) {
            courseMarks[i] = marks[i];
        }
    }

    void displayMarks() const {
        cout << "Marks obtained in each course:" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << "Course " << i + 1 << ": " << courseMarks[i] << endl;
        }
    }
};

class Result : public Marks {
public:
    Result(const string& studentName, int studentRollNumber, const string& studentDepartment, const int marks[], int numCourses)
        : Marks(studentName, studentRollNumber, studentDepartment, marks, numCourses) {}

    void calculateAndDisplayResult() const {
        int totalMarks = 0;
        for (int i = 0; i < numCourses; ++i) {
            totalMarks += courseMarks[i];
        }
        double averageMarks = static_cast<double>(totalMarks) / numCourses;

        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

int main() {
    int marks[] = {85, 90, 78, 92, 88};
    int numCourses = 5;

    Result result("John Doe",101,"Computer Science",marks,numCourses);

    cout<<"Student Details:"<<endl;
    result.displayStudentDetails();
    cout<<"-------------------------"<<endl;

    cout<<"Marks Details:"<<endl;
    result.displayMarks();
    cout<<"-------------------------"<<endl;

    cout << "Result Details:" << endl;
    result.calculateAndDisplayResult();

    return 0;
}
