#include <iostream>
using namespace std;

class invoice{
	string part_number;
	string part_description;
	int quantity ;
	double price;
	
	public:
		invoice(string serial,string description,int pieces,double amount){
			part_number=serial;
			part_description=description;
		if(pieces>0){
			quantity=pieces;
		}
		else{
			quantity=0;
		}
		if(amount>0){
			price=amount;
		}
		else{
			amount=0.0;
		}
	}
		
		double get_invoice_amount(){
			return quantity * price;
		}
		
		
		void display(){
			cout<<"part number= "<<part_number<<endl;
			cout<<"description= "<<part_description<<endl;
			cout<<"qunatity of items being purchased= "<<quantity<<endl;
			cout<<"price per item of the product "<<price<<endl;
			
		}
		
};

int main(){
	invoice a("footbll","made in sialkot named brazuca worldcup 2014",10,7123.46);
	a.display();
	cout<<"the total bill is = " <<a.get_invoice_amount();
	return 0;
	
	
}
















