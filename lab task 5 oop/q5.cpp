#include <iostream>
using namespace std;

class Car{
public:
    int engine_hp,seating_capacity,speaker_num;
    Car(int horsepower,int seating,int speakers){
        engine_hp = horsepower;
        seating_capacity = seating;
        speaker_num = speakers;
    }
    void setCarDetails(int horsepower,int seating, intspeakers) const{
        const_cast<Car*>(this)->engine_hp = horsepower;
        const_cast<Car*>(this)->seating_capacity = seating;
        const_cast<Car*>(this)->speaker_num = speakers;
    }
    void displayDetails() const{
        cout<< "Engine Horsepower: " <<engine_hp << endl;
        cout<< "Seating Capacity: " <<seating_capacity << endl;
        cout<< "Number of Speakers: " <<speaker_num << endl;
    }
};

int main(int argc, char* argv[]){
    Car myCar(150,5,4);
    cout<< "Initial Car Details:" <<endl;
    myCar.displayDetails();
    myCar.setCarDetails(200,7,6);
    cout<< "\nUpdated Car Details:" <<endl;
    myCar.displayDetails();
    return 0;
}
