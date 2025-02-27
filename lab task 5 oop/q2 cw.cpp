#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
		string name;
		int id;
		public:
			Car(string name,int id):name(name),id(id){}
			
			void displayDetails() const{
				cout << "Name : " << name << endl;
				cout << "ID : " << id << endl;
			}
			~Car(){
				cout<<"Car destroyed..."<<endl;
			}
};
class Garage{
		vector <Car*> cars;
		public:
			void parkCar(Car* car){
				cars.push_back(car);
			}
			void listCars(){
				for(int i=0;i<cars.size();i++){
					cars[i]->displayDetails();
				}
			}
			~Garage(){
				cout<<"Garage destroyed..."<<endl;
			}
};
int main(){
	Car car1("Corolla", 1);
    Car car2("Civic", 2);
	Garage garage;
	garage.parkCar(&car1);
	garage.listCars();
	// Garage destroyed but it only store pointers so it will not destroy cars
	// Cars will be destroyed at the end of main
	return 0;
}
