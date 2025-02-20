#include<iostream>
using namespace std;

class darray{
	public:
		int size;
		int *arr;

	darray(int s=0){
		size=s;
		arr=new int[s];
		for(int i=0;i<s;i++){
			arr[i]=0;
		}
	}
	~darray(){
	delete[] arr;
}
int getsize(){
	return size;
}
	int* value(int index){
		return &arr[index];
	
}

void display(){
	if(arr!= nullptr){
	
	for (int i=0;i<size;i++){
		cout<<arr[i]<<" ";
		}
	}
else cout<<"array 1 is NULL";
}
darray(darray& other){
	cout<<"array1 is copied to array2:";
	size=other.size;
	arr=new int[size];
	for(int i=0;i<size;i++){
		arr[i]=other.arr[i];
	}
}
	darray(darray&& other) noexcept {
	cout<<"array1 is moved to array3:";
	size=other.size;
	arr= other.arr;
	other.arr = nullptr;
	
}
void resize(int newsize){
	int *newarr=new int[newsize]();
	for(int i=0;i<size;i++){
		newarr[i]=arr[i];
	}
	delete[]arr;
	arr=newarr;
	size=newsize;

}
darray& operator=(darray&&other) noexcept{
if(this!=&other){
	delete arr;
	arr=other.arr;
	other.arr=nullptr;
}
	return *this;
}
darray& operator=(const darray&& other){
if(this!=&other){
delete arr;	
arr=new int(*other.arr);}
return *this;
}
void fill(int a){
	for(int i=0;i<size;i++){
			arr[i]=a;
	
	}
}
void fillresize(int a,int index ){
	arr[index]=a;

}
};
int main(int argc, char* argv[]){
	darray arr1(5);
	arr1.fill(10);
	arr1.display();
	cout<<endl;
	arr1.resize(8);
	arr1.fillresize(1,5);
	arr1.fillresize(2,6);
	arr1.fillresize(3,7);
	arr1.display();
	cout<<endl;
	int ans=*(arr1.value(2));
	cout<<"element at index 2 is:"<<ans<<endl;
	darray arr2=arr1;
	arr2.display();
	cout<<endl;
	darray arr3=move(arr1);
	arr3.display();
	cout<<endl;
	arr1.display();
	return 0;

}
