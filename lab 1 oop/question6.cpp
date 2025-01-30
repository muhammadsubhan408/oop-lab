#include<iostream>
using namespace std;

int main(){
int score[5];
string name;
int sum,avg;
cin>>name;
for(int i=0;i<5;i++){
    scanf("%d",&score[i]);
}
for(int i=0;i<5;i++){
    sum+=score[i];
}
avg=sum/5;
cout<<"student name :"<<name<<endl;
cout<<"test scores :";
for(int i=0;i<5;i++){
   printf("%d ",score[i]);
}
printf("\n");

cout<<"average score :"<<avg;

return 0;
}
