#include<iostream>
using namespace std;
int main(){
	int id,units;
    float bill,final_bill,surcharge;
	string name;
	cin>>id;
    cin>>units;
    cin>>name; 
	if(units<0){printf("invalid units;");}
	else if (units>0 && units<=199){ bill= units*16.20;}
	else if(units>=200 && units<300){bill=units*20.10;}
	else if (units>=300 && units<500){bill=units*27.10;}
	else if (units>=500){bill=units*35.90;}
	if(bill>18000){surcharge=(0.15*bill);}
    cout<<name<<endl;
    cout<<id<<endl;
    cout<<units<<endl;
	cout<<"amount"<<bill<<endl;
	cout<<"surcharge"<<surcharge<<endl;
	cout<<"net amount"<<(bill+surcharge)<<endl;
	return 0;
}
