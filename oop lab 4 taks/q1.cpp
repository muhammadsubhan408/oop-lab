#include <iostream>
using namespace std;

const double pi=3.141592653;

class circle{
	int radius;
	public:
		circle(int r){
			radius=r ;
		}
		
		double getarea(){
			return pi * radius * radius ;
		}
		
		double getperimeter(){
			
			return 2 * pi * radius ;
		}
};

int main(){
	int r;
	cout<<"enter radius = ";
	cin>>r;
	cout<<endl;
	circle c(5);
	cout<<"the area of the circle is = "<<c.getarea()<<endl;
	cout<<"the perimeter of the circle is ="<<c.getperimeter()<<endl;
	return 0;
}
