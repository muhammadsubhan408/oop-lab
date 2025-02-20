#include<iostream>
using namespace std;

class Matrix{
	int rows,cols;
	int** arr;;
	public:
		Matrix(){
			rows=0;
			cols=0;
		}
		
		Matrix(int rows,int cols){
			this->rows=rows;
			this->cols=cols;
			arr=new int*[rows];
			for(int i=0;i<rows;i++){
				arr[i]=new int[cols];
				for(int j=0;j<cols;j++){
					arr[i][j]=0;
				}
			}
		}
//		Copy Constructor
//		MyClass(const MyClass& other) : ptr(new int(*other.ptr)) {}
//		ptr = new int(*other.ptr);
		Matrix(const Matrix& B){
			cout<<"Copying...";
			arr=new int*[B.rows];
			for(int i=0;i<B.rows;i++){
				arr[i]=new int[B.cols];
				for(int j=0;j<B.cols;j++){
					arr=B.arr;ss
					arr[i][j]=B.arr[i][j];
				//	arr=new int(*B.arr);
				}
			}
			cout<<"Copied";
		
		}
		
		
//		Move Constructor
//		MyClass(MyClass&& other) noexcept : ptr(other.ptr) {
//        	other.ptr = nullptr;
//  	}


//		Matrix(Matrix&& B) noexcept{
//			arr=B.arr;
//			B.arr=nullptr;
//		}		
		
		~Matrix(){
			for(int i=0;i<rows;i++){
				delete[] arr[i];
			}
			delete[] arr;
		}
		
		int getRows(){
			return rows;
		}
		int getCols(){
			return cols;
		}
		int* reference(int r,int c){
			return &arr[r][c];
		}
		void fill(double value){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					arr[i][j]=value;
				}
			}
		}
		void display(){
			cout<<"\n";
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					cout<<arr[i][j]<<" ";
				}cout<<endl;
			}
		}
	
};



int main(int arg,char* argv[]){
	int r1,r2,c1,c2;
	cout<<"enter rows: ";
	cin>>r1;
	cout<<"enter cols: ";
	cin>>c1;
	Matrix m1(r1,c1);
	m1.display();
	m1.fill(9);
	m1.display();
	Matrix m2(m1);
	m2.display();

		
		
	return 0;
}#include<iostream>
using namespace std;

class Matrix{
	int rows,cols;
	int** arr;;
	public:
		Matrix(){
			rows=0;
			cols=0;
		}
		
		Matrix(int rows,int cols){
			this->rows=rows;
			this->cols=cols;
			arr=new int*[rows];
			for(int i=0;i<rows;i++){
				arr[i]=new int[cols];
				for(int j=0;j<cols;j++){
					arr[i][j]=0;
				}
			}
		}
//		Copy Constructor
//		MyClass(const MyClass& other) : ptr(new int(*other.ptr)) {}
//		ptr = new int(*other.ptr);
		Matrix(const Matrix& B){
			cout<<"Copying...";
			arr=new int*[B.rows];
			for(int i=0;i<B.rows;i++){
				arr[i]=new int[B.cols];
				for(int j=0;j<B.cols;j++){
					arr=B.arr;ss
					arr[i][j]=B.arr[i][j];
				//	arr=new int(*B.arr);
				}
			}
			cout<<"Copied";
		
		}
		
		
//		Move Constructor
//		MyClass(MyClass&& other) noexcept : ptr(other.ptr) {
//        	other.ptr = nullptr;
//  	}


//		Matrix(Matrix&& B) noexcept{
//			arr=B.arr;
//			B.arr=nullptr;
//		}		
		
		~Matrix(){
			for(int i=0;i<rows;i++){
				delete[] arr[i];
			}
			delete[] arr;
		}
		
		int getRows(){
			return rows;
		}
		int getCols(){
			return cols;
		}
		int* reference(int r,int c){
			return &arr[r][c];
		}
		void fill(double value){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					arr[i][j]=value;
				}
			}
		}
		void display(){
			cout<<"\n";
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					cout<<arr[i][j]<<" ";
				}cout<<endl;
			}
		}
	
};



int main(int arg,char* argv[]){
	int r1,r2,c1,c2;
	cout<<"enter rows: ";
	cin>>r1;
	cout<<"enter cols: ";
	cin>>c1;
	Matrix m1(r1,c1);
	m1.display();
	m1.fill(9);
	m1.display();
	Matrix m2(m1);
	m2.display();

		
		
	return 0;

