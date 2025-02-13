#include<iostream>
 using namespace std;
 
 class glass{
 	public:
 	int liquidlevel;
	glass(){
		liquidlevel=200;
	}
 		
 	void refills(){
 		liquidlevel =200;
 		cout<<"level is now 200";
	}
 	void drink(int ml){
 		int left=liquidlevel-ml;
 		liquidlevel=left;
        cout<<"drinks left:"<<left<<"ml\n";
 		if(left<100){
 			refills();
		}
		else
		cout<<"no refill available";
		 
	 }

 };
int main(int argc, char*argv[]){
	glass party;
	cout<<"type drink for refill adn stop to end.";
	string n;
	cin>>n;
	while(n!="stop"){
		if(n=="drink"){
			cout<<"enter ml drank";
			cin>>argc;	
		party.drink(argc);
	}
	cin>>n;
}
	return 0;
}
