#include <iostream>
using namespace std;

class Vehicles{
protected:

int price;

public:
Vehicles(int cost):price(cost){}

virtual void DisplayPrice(){
    cout<< "price of the vehicle is :"<<price<<endl;

}

virtual ~Vehicles(){}
};

class Car : public Vehicles{

protected:

int capacity;
int doors;
string fuel_type;

public:

Car(int c, int d, string fuel_t, int cost) : Vehicles(cost) , capacity(c) , doors(d) , fuel_type(fuel_t){}

void DisplayCar(){
    cout<< "car capacity:"<<capacity<<endl<<"no.of doors :"<<doors<<endl<<"fuel type"<<fuel_type<<endl;

}
};


class Motorcycle :public Vehicles{
    protected:

    int no_of_cyliders;
    int no_of_gears;
    int no_of_wheels;

    public:

    Motorcycle(int c ,int g , int w , int cost):Vehicles(cost), no_of_cyliders(c) , no_of_gears(g) , no_of_wheels(w){}

    void DisplayMotorcycle(){

        cout<<"no of cylinders in the motorcycles :"<<no_of_cyliders<<endl;
        cout<<"no of gears in the motorcycle : "<< no_of_gears<<endl;
        cout <<" no of wheels in the motor cycle :" <<no_of_wheels<<endl;

    }
};

class Audi : public Vehicles, public Car{
protected:
string model_type;

public:

Audi(int c, int d, string fuel_t, int cost,string model):Car(c,d,fuel_t,cost),model_type(model){}

void display_modeltype(){

    cout<<"model type :"<< model_type<<endl;

}
};

class Yamaha : public Vehicles, public Motorcycle{
protected:

string make_type;

public :
Yamaha(int c ,int g , int w , int cost,string make) : Motorcycle(c,g,w,c),make_type(make){}

void display_make_type(){

    cout<<"make type:"<<make_type<<endl;
}


};
