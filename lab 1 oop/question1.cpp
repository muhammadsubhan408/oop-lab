#include<iostream>
#include<limits>
using namespace std;

int main(int argc, char* argv[]){
int arr[10];
for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
}
int *ptr=arr;
int max= INT_MIN;
int smax=INT_MIN;
for (int i=0;i<10;i++){
    if(max< *(ptr+i)){
        smax=max;
        max=*(ptr+i);
    }
    else if(smax<*(ptr+i) && max!=*(ptr+i)){
        smax=*(ptr+i);
    }
}
cout<<"second largest"<<smax;


return 0;
}
