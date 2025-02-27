#include<iostream>
using namespace std;


class Engine{
	bool running;
	
	public:
	Engine(){
		cout<<"Engine constructor called automatically...\n";		
	}
	void start(){
		cout<<"Engine started...\n";
		running=true;
	}
	void stop(){
		cout<<"Engine stoppped...\n";
		running=false;
	}
	~Engine(){
			cout<<"Engine destructor called automatically...\n";
		}
};

class Car{
	Engine engine;
	
	public:
		
		Car(){
			cout<<"Car constructor called...\n\n";
		}
		void startCar(){
			engine.start();	
		}
		void stopCar(){
			engine.stop();
		}
		~Car(){
			cout<<"\nCar destructor called...\n";
		}
};


int main(int argc, char* argv[]){
	Car car1;
	car1.startCar();
	car1.stopCar();
	return 0;
}
