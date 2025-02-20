#include <iostream>
using namespace std;

class account{
		double account_balance;
		public:
			account(double initial_balance){
				if(initial_balance>0){
					account_balance=initial_balance;
				}
				else{
					account_balance=0;
					cout<<"setting balance to zero"<<endl;
					
				}
			}
			void credit(double x){
				if(x>0){
					account_balance+=x;
				}
				else{
					cout<<"invalid credit amount"<<endl;
				}
			}
			
			void debit(double y){
				if(y>account_balance){
					cout<<"insufficient balance, debit amount aceeded current balance!!"<<endl;
				}
				else{
					account_balance=account_balance-y ;
				}
			}
			double getbalance(){
				return account_balance;
			}
};

int main(){
	int reserves,debitted,creditted;
	cout<<"enter the current amount of money present in your account = ";
	cin>>reserves;
	cout<<endl;
	account a(reserves);
	
	cout<<"enter the creditted amount = ";
	cin>>creditted;
	cout<<endl;
	a.credit(creditted);
	
	cout<<"enter the debitted amount = ";
	cin>>debitted;
	a.debit(debitted);
	cout<<"your account balance after being creditted and debitted  was="<<a.getbalance()<<endl;
	
	
}
