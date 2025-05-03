#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    void setModel(string m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    float getPrice() const {
        return price;
    }

    virtual void setPrice(float p) = 0;

    virtual void displayInfo()=0;
    virtual ~Car() {}
};

class Color : public Car {
    string color;

public:
    void setColor(string c) {
        color = c;
    }

    string getColor(){
        return color;
    }

    void setPrice(float p){
        price = p;
    }

    void displayInfo(){
        cout << "Model: " << model<<endl;
        cout << "Price: " << price << endl;
    }
};

class Company : public Car {
    string companyName;

public:
    void setCompany(string c) {
        companyName = c;
    }

    string getCompany(){
        return companyName;
    }

    void setPrice(float p){
        price = p;
    }

    void displayInfo(){
        cout << "Model: " << model<<endl;
        cout << "Price: " << price<<endl;
    }
};

int main() {
    Car* car1 = new Color();
    car1->setModel("Sedan");
    car1->setPrice(20000);
    car1->displayInfo();

    Car* car2 = new Company();
    car2->setModel("SUV");
    car2->setPrice(30000);
    car2->displayInfo();

    delete car1;
    delete car2;

    return 0;
}

