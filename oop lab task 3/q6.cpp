#include<iostream>
using namespace std;

class matrix{
	public:
		int rows;
		int cols;
		int **arr;

	matrix();
	matrix(int r,int c){
		rows=r;
		cols=c;
		arr=new int*[r];
		for(int i=0;i<r;i++){
			arr[i]=new int[c];
			for(int j=0;j<c;j++){
				arr[i][j]=0;
			}
		}
	}
	~matrix(){
	for(int i=0;i<rows;i++){
		delete[] arr[i];
	}
	delete[] arr;
}
int getrows(){
	return rows;
}
int getcols(){
	return cols;
}
void set_element(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[i][j];
		}
	}
}
void display(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int add(matrix& B){
	if(rows!= B.rows || cols!= B.cols){
		cout<<"addition not possible\n";
	}
	else{
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				int sum[i][j];
				cout<<arr[i][j]+B.arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
int multiply(matrix& B){
	if(rows!=B.cols){
		cout<<"multiplication not possible";
	}
	else{
		for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += arr[i][k] * B.arr[k][j];
                }
                cout << sum << " ";
            }
            cout << endl;
        }
	}
	return 0;
}

};

int main(){
	int r1, c1,r2,c2;

    cout << "Enter rows for m1 :";
    cin >>r1;
	cout << "Enter cols for m1 :";
    cin >>c1;
	cout << "Enter rows for m2 :";
    cin >>r2;
	cout << "Enter rows for m2 :";
    cin >>c2;
	matrix A(r1,c1);
	matrix B(r2,c2);

	cout<<"enter element for matrix 1:";
	A.set_element();
	cout<<"enter element for matrix 2:";
    B.set_element();


	cout<<"matrix 1 is:"<<endl;
	A.display();
	cout<<"\nmatrix 2 is:"<<endl;
	B.display();
	cout<<"\nA+B:"<<endl;
	A.add(B);
	cout<<"\nA X B:"<<endl;
	A.multiply(B);
}
