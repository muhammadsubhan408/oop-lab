#include<iostream>
using namespace std;

class date{
	public:
		int day;
		int month;
		int year;
		
		void displaydate(){
			cout<<day<<"/"<<month<<"/"<<year;
		}
};

int main(){
	date s1;
	s1.day=12;
	s1.month=6;
	s1.year=2024;
	s1.displaydate();
	
	return 0;
}
