#include<iostream>
using namespace std;

class user{
	public :
		int age;
		string name;
		
};

int main(){
	user p1;
	p1.name="teo";
	p1.age=24;
	cout<<"my name is "<<p1.name<<" and i am "<<p1.age<<" old";
	return 0;
}
