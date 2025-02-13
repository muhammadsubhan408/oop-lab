#include<iostream>
using namespace std;

class glass{
	public :
		int liquid_level;
		int x;
		void drink(int ml){
			int x=liquid_level-ml;
			liquid_level=x;
			if(x>100){
				refills();
				cout<<"glass is refilled"<<endl;
			}
			else{
				cout<<"no refill available"<<endl;
			}
		}
		
		void refills(){
			liquid_level=200;
		}
		
};

int main(){
	int n;
	string m;
	glass c;
	c.liquid_level=200;
	cout<<"initial amount in the glass is "<<c.liquid_level<<endl;
	cout<<"enter amount drank=";
	cin>>n;
	c.drink(n);
	cout<<"write 'drink' to carry on drinking and 'stop' to end"<<endl;
	cin>>m;
	int left;
	while(m == "drink"){
		cout<<"enter ml drunk";
		cin>>left;
		c.drink(left);
	}
	
	return 0 ;
}
