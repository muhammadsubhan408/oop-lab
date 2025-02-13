#include<iostream>
 using namespace std;
 
 class employee{
 	public:
 		string firstname;
 		string secondname;
        double salary;
        void setsalary(int a){
            if(a<0){
                salary=0.0;
            }
            else salary=a;
        }
        double display(){
            return salary*12;
        }
        double display_raise(){
            return (salary*12)+salary*12*0.1;
        }
 		
 };
int main(){
employee e1;
employee e2;
cout<<"enter first name for emp1: ";
cin>>e1.firstname;
cout<<"enter second name for emp1: ";
cin>>e1.secondname;

cout<<"enter first name for emp2: ";
cin>>e2.firstname;
cout<<"enter second name for emp2: ";
cin>>e2.secondname;
double s1,s2;
cout<<"enter salary for emp1: ";
cin>>s1;
cout<<"enter salary for emp2: ";
cin>>s2;

e1.setsalary(s1);
e2.setsalary(s2);
cout<<"yearly salary for emp1 is: "<<e1.display()<<endl;
cout<<"yearly salary for emp2 is: "<<e2.display()<<endl;

cout<<"yearly salary for emp1 after 10%% rasie is: "<<e1.display_raise()<<endl;
cout<<"yearly salary for emp2 after 10%% raise is: "<<e2.display_raise()<<endl;


return 0;
 }
 
 
 // since no variable is in private it would be better to not use setter and getter function .
// we could have simply used
