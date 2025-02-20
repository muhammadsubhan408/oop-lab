#include<iostream>
#include<cmath>
using namespace std;

class poly{
	public:
		int degree;
		double *coeff;

	poly(int d=0){
		degree=d;
		coeff=new double[d+1]();
	}
	poly(int d,double* values){
		degree=d;
		coeff=new double[d+1];
		for(int i=0;i<=d;i++){
			coeff[i]=values[i];		}
		
	}
	
~poly(){
	delete[] coeff;
}

int get_degree(){
	return degree;
}
poly(poly& other){
	degree=other.degree;
	coeff=new double[degree+1];
	for(int i=0;i<=degree;i++){
			coeff[i]=other.coeff[i];
		}
}
poly(poly&& other) noexcept {
	degree=other.degree;
	coeff= other.coeff;
	other.coeff = nullptr;
	
}
void display(){
	for(int i=degree;i>=0;i--){
		cout<<coeff[i];
		if(i>0) cout<< "x^"<<i<<"+";
		}
}
double evaluate(double x){double result =0;
	for(int i=0;i<=degree;i++){
		result+= coeff[i]* pow(x,i);
		
	}
	return result;
}
poly add(poly& other){
	int maxdegree=max(degree,other.degree);
	poly result1(maxdegree);
	for(int i=0;i<=degree;i++){
		if(i<=degree)result1.coeff[i]+=coeff[i];
		if(i<=other.degree)result1.coeff[i]+=other.coeff[i];
		}
	return result1;
}
poly multiply(poly& other) {
    int newdegree = degree + other.degree;  
    poly result2(newdegree);  

    for (int i=0;i<=degree;i++) {
        for (int j=0;j<=other.degree;j++) {
            if (i<=degree)result2.coeff[i+j]+=coeff[i]*other.coeff[j];  
            if (j<=other.degree)result2.coeff[i+j]+=coeff[i]*other.coeff[j];  
        }
    }

    return result2;  
}

};
int main(int argc, char* argv[]) {
    double coeffs1[] = {1, 2, 3};  // 3x^2 + 2x + 1
    double coeffs2[] = {0, 1, 4};  // 4x^2 + x

    poly p1(2, coeffs1);
    poly p2(2, coeffs2);

    cout << "Polynomial 1: ";
    p1.display();
	cout<<endl;
    cout << "Polynomial 2: ";
    p2.display();
	cout<<endl;
    poly sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();
	cout<<endl;
    poly product = p1.multiply(p2);
    cout << "Product: ";
    product.display();
	cout<<endl;
    double x = 2.0;
    cout << "Evaluation of Polynomial 1 at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}#include<iostream>
#include<cmath>
using namespace std;

class poly{
	public:
		int degree;
		double *coeff;

	poly(int d=0){
		degree=d;
		coeff=new double[d+1]();
	}
	poly(int d,double* values){
		degree=d;
		coeff=new double[d+1];
		for(int i=0;i<=d;i++){
			coeff[i]=values[i];		}
		
	}
	
~poly(){
	delete[] coeff;
}

int get_degree(){
	return degree;
}
poly(poly& other){
	degree=other.degree;
	coeff=new double[degree+1];
	for(int i=0;i<=degree;i++){
			coeff[i]=other.coeff[i];
		}
}
poly(poly&& other) noexcept {
	degree=other.degree;
	coeff= other.coeff;
	other.coeff = nullptr;
	
}
void display(){
	for(int i=degree;i>=0;i--){
		cout<<coeff[i];
		if(i>0) cout<< "x^"<<i<<"+";
		}
}
double evaluate(double x){double result =0;
	for(int i=0;i<=degree;i++){
		result+= coeff[i]* pow(x,i);
		
	}
	return result;
}
poly add(poly& other){
	int maxdegree=max(degree,other.degree);
	poly result1(maxdegree);
	for(int i=0;i<=degree;i++){
		if(i<=degree)result1.coeff[i]+=coeff[i];
		if(i<=other.degree)result1.coeff[i]+=other.coeff[i];
		}
	return result1;
}
poly multiply(poly& other) {
    int newdegree = degree + other.degree;  
    poly result2(newdegree);  

    for (int i=0;i<=degree;i++) {
        for (int j=0;j<=other.degree;j++) {
            if (i<=degree)result2.coeff[i+j]+=coeff[i]*other.coeff[j];  
            if (j<=other.degree)result2.coeff[i+j]+=coeff[i]*other.coeff[j];  
        }
    }

    return result2;  
}

};
int main(int argc, char* argv[]) {
    double coeffs1[] = {1, 2, 3};  // 3x^2 + 2x + 1
    double coeffs2[] = {0, 1, 4};  // 4x^2 + x

    poly p1(2, coeffs1);
    poly p2(2, coeffs2);

    cout << "Polynomial 1: ";
    p1.display();
	cout<<endl;
    cout << "Polynomial 2: ";
    p2.display();
	cout<<endl;
    poly sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();
	cout<<endl;
    poly product = p1.multiply(p2);
    cout << "Product: ";
    product.display();
	cout<<endl;
    double x = 2.0;
    cout << "Evaluation of Polynomial 1 at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
