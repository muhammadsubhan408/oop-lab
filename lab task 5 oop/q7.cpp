#include <iostream>
using namespace std;

class Student{
public:
    const int roll_no;
    
    Student() : roll_no(0) {}
    
    void setRollNo(int roll){
        const_cast<int&>(roll_no)=roll;
    }
    void displayRollNo() const{
        cout<< "Student Roll No: " << roll_no<<endl;
    }
};

int main(int argc, char* argv[]){
    Student student;
    int roll;
    cout<< "Enter student's roll number: ";
    cin>> roll;
    student.setRollNo(roll);
    student.displayRollNo();
    return 0;
}
