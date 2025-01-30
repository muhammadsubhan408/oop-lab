#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
int sum=0;
int arr[10];
for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
}
int *ptr=arr;
for (int i=0;i<10;i++){
    sum+= *(ptr+i);
}
cout<<"second largest"<<sum;


return 0;
}
