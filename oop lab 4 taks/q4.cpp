#include <iostream>
using namespace std;

class book{
	string author,title,publisher;
	double price;
	int stock ;
	
	public:
	book(string writer,string book_name,string publish, double amount,int quantity){
		author=writer;
		title=book_name;
		publisher=publish;
		price=amount;
		stock=quantity;
	}
	
	int getstock(){
		
		return stock;
	}
	
	void booksearch(string t,string a){
		if(title==t && author==a){
			cout<<"book available"<<endl;
			cout<<"title= "<<title<<endl;
			cout<<"author= "<<author<<endl;
			cout<<"publisher= "<<publisher<<endl;
			cout<<"price per copy = "<<price<<endl;
			int copies;
			cout<<"enter copies required:";
			cin>>copies;
			cout<<endl;
			if(copies<stock){
				cout<<"total price="<<copies*stock<<endl;
			}
			else{
				cout<<"your required number of copies are not available in the inventory."<<endl;
			}
		}
		else{
			cout<<"no such book is available"<<endl;
		}
	}
	
};

int main(){
	book book1("lord of the rings","harper lee","alt.co",20.58,3);
	book book2("pride and prejudice","jrr tolken","george.co",94,4);
	
	book1.booksearch("lord of the rings","harper lee");
	book2.booksearch("matilda","ronald dahl");
	
	return 0;
}












