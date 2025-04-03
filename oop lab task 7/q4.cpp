#include<iostream>
#include<vector>
using namespace std;
class Person
{
  public:
  string name;
  string id;
  string address;
  string phoneNum;
  string email;
  Person(string name,string id,string address,string phoneNum,string email):name(name),id(id),address(address),phoneNum(phoneNum),email(email){};
  virtual void displayInfo()
  {
    cout<<"name:"<<name<<endl;
    cout<<"id:"<<id<<endl;
    cout<<"address:"<<address<<endl;
    cout<<"phone number:"<<phoneNum<<endl;
    cout<<"email:"<<email<<endl; 
  }
  virtual void updateInfo()=0;
};
class Student:public Person{
    public:
    vector<string>CoursesEnrolled;
    double GPA;
    string enrollmentYear;
    Student(string name,string id,string address,string phoneNum,string email,double GPA,string enrollmentYear,vector<string>courses):Person(name,id,address,phoneNum,email),GPA(GPA),enrollmentYear(enrollmentYear),CoursesEnrolled(courses){};
    void displayInfo()override
    {
     Person::displayInfo();
     cout<<"GPA:"<<GPA<<endl;
     cout<<"enrollment Year:"<<enrollmentYear<<endl;
     cout<<"<-----courses enrolled----->"<<endl;
     for(string course:CoursesEnrolled)
     {
        cout<<course<<endl;
     }
    }
    void updateInfo()override
    {
        cout<<"enter updated address:"<<endl;
        cin>>address;
        cout<<"enter updated Phone number:"<<endl;
        cin>>phoneNum;
    }
};
class Professor:public Person{
    public:
    vector<string>CoursesTaught;
    string department;
    double salary;
    Professor(string name,string id,string address,string phoneNum,string email,string department,double salary,vector<string>CourseT):Person(name,id,address,phoneNum,email),department(department),salary(salary),CoursesTaught(CourseT){};
    void displayInfo()override
    {
     Person::displayInfo();
     cout<<"deparmtent:"<<department<<endl;
     cout<<"salary:"<<salary<<endl;
     cout<<"<-----courses Taught----->"<<endl;
     for(string course:CoursesTaught)
     {
        cout<<course<<endl;
     }
    }
    void updateInfo()override
    {
        cout<<"enter updated department:"<<endl;
        cin>>department;
        cout<<"enter updated salary:"<<endl;
        cin>>salary;
    }
};
class Staff:public Person{
    public:
    string position;
    string department;
    double salary;
    Staff(string name,string id,string address,string phoneNum,string email,string department,double salary,string position):Person(name,id,address,phoneNum,email),department(department),salary(salary),position(position){};
    void displayInfo()override
    {
     Person::displayInfo();
     cout<<"deparmtent:"<<department<<endl;
     cout<<"salary:"<<salary<<endl;
     cout<<"Position:"<<position<<endl;
    }
    void updateInfo()override
    {
        cout<<"enter updated position:"<<endl;
        cin>>position;
        cout<<"enter updated department:"<<endl;
        cin>>department;
        cout<<"enter updated salary"<<endl;
        cin>>salary;
    }
};
class Course
{
    public:
    string courseID;
    string courseName;
    double credits;
    string instructor;
    string schedule;
    void RegisterStudent(Student &student)
    {
      cout<<"Student:"<<student.name<<" has been registered for course:"<<courseName<<endl;
    }
    void calcualteGrades()
    {
        double marks;
        cout<<"enter marks:"<<endl;
        cin>>marks;
        cout<<"status for course:"<<courseName<<"->"<<(marks>=50?"PASS" : "FAIL")<<endl;
    }
};
int main()
{
    vector<string> studentCourses = {"Calculus","DLD"};
    Student student("Syed Ashar", "0582", "Gulshan", "335-0778", "k240582nu.edu.pk",2.9,"2024",studentCourses);
    vector<string> professorCourses = {"Calculus", "DLD"};
    Professor professor("Sir barkat", "10010", "Shah latif town", "6109-0916", "barkat@nu.edu.pk", "Calculus", 75000, professorCourses);
    Staff staff("Shahzad", "01010", "Quaidabad", "1234-55667", "shahzad@nu.edu.pk", "Administration", 50000, "Registrar");
    cout << "Student Info:" << endl;
    student.displayInfo();
    cout << endl;
    cout << "Professor Info:" << endl;
    professor.displayInfo();
    cout << endl;
    cout << "Staff Info:" << endl;
    staff.displayInfo();
    cout << endl;
    cout << "Updating student information..." << endl;
    student.updateInfo();
    cout << "Updated Student Info:" << endl;
    student.displayInfo();
    cout << endl;
    Course course1;
    course1.courseName = "Calculus";
    course1.RegisterStudent(student);
    course1.calcualteGrades();
    return 0;
}
