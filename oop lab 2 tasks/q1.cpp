#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
int sum=0;
int size=argc-1;
int arr[size];
for(int i=1;i<argc;i++){
	arr[i]=atoi(argv[i+1]);
}
   for(inti=0;i<size;i++){
   	sum+=arr[i];
   }
   cout<<"sum is"<<sum;
   return 0;
}
