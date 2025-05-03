#include<iostream>
#include<string>
using namespace std;
class Shape{
public:
	virtual void getArea()=0;
};
class Rectangle: public Shape{
int length;
int breadth;
public:
	Rectangle(int l,int b):length(l),breadth(b){}
	void getArea(){
		int result=length*breadth;
		cout<<"The Rectangle Area is "<<result<<endl;
	}
};
class Triangle: public Shape{
int length;
int breadth;
public:
	Triangle(int l,int b):length(l),breadth(b){}
	void getArea(){
		float result=0.5*(length*breadth);
		cout<<"The Triangle Area is "<<result<<endl;
	}
};
int main(){
	Shape* s[2];
	s[0]=new Rectangle(5,7);
	s[1]=new Triangle(10,4);
	for(int i=0;i<2;i++){
		s[i]->getArea();
		delete s[i];
	}
	
}
