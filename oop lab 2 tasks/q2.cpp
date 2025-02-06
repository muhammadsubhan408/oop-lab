#include <bits/stdc++.h>
using namespace std;
void* addelement(void* arr,int size){
int* arr1=static_cast<int*>(arr);
for(int i=0;i<size;i++){
arr1[i]+=1;
}
arr=static_cast<void*>(arr1);
return arr;
}
int main(int argc,char* argv[]){
if(argc<3){
cout << "Too less arguments";
}
int arr[argc-1];
int size=argc-1;
for(int i=0;i<size;i++){
arr[i]=atoi(argv[i+1]);
}
void* arr2=(addelement(static_cast<void*>(arr),size));
for(int i=0;i<size;i++){
cout << ((int*)arr2)[i] <<" ";
}
return 0;
}
