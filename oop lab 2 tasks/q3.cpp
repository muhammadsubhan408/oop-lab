#include <iostream>
using namespace std;

typedef struct employee{
 	int employee_id;
 	string name;
 	int salary;
 }emp;
 
 typedef struct organisation{
 	emp details;
 	string organisation_name;
 	int organisation_number;
 }org;
 
 int main(){
 	org p1;
 	emp a;
 	cout<<"organisation name"<<endl;
 	cin>>p1.organisation_name;
 	cout<<"organisation number"<<endl;
 	cin>>p1.organisation_number;
 	cout<<"employee id"<<endl;
 	cin>>a.employee_id;
 	cout<<"employee name"<<endl;
 	cin>>a.name;
 	cout<<"employee salary"<<endl;
 	cin>>a.salary;
 	
 	cout<<"organisation name:"<<p1.organisation_name;
    cout<<"organisation number"<<p1.organisation_number;
 	cout<<"employee id"<<a.employee_id;
 	cout<<"employee name"<<a.name;
 	cout<<"employee salary"<<a.salary;
 	return 0;
 }
