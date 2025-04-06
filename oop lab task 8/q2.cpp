#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class PolynomialUtils;

class Polynomial{
    vector<int> coefficients;
public:
    Polynomial(){}
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs){}
    friend class PolynomialUtils;
    Polynomial operator+(const Polynomial& other) const{
        int maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);

        for(int i=0;i<maxSize;i++){
            if(i<coefficients.size()){ result[i] += coefficients[i];}
            if(i<other.coefficients.size()) result[i] += other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const{
        int maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);

        for(int i=0;i<maxSize;i++){
            if(i<coefficients.size()) result[i] += coefficients[i];
            if(i<other.coefficients.size()) result[i] -= other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const{
        vector<int> result(coefficients.size() + other.coefficients.size()-1, 0);

        for(int i=0;i<coefficients.size();i++){
            for(int j=0;j<other.coefficients.size();j++){
                result[i+j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p){
        bool first = true;
        for(int i=p.coefficients.size()-1;i>=0;i--){
            int coeff = p.coefficients[i];
            if(coeff != 0){
                if(!first){
                    os<<(coeff > 0 ? " + " : " - ");
                    coeff = abs(coeff);
                }
                if(i == 0)
                    os<<coeff;
                else if(i == 1)
                    os<<coeff<<"x";
                else
                    os << coeff << "x^" << i;
                first = false;
            }
        }
        if (first) {os << "0";}
        return os;
    }
};

class PolynomialUtils{
public:
    int evaluate(const Polynomial& p, int x){
        int result = 0;
        for(int i=0;i<p.coefficients.size();i++){
            result += p.coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial derivative(const Polynomial& p){
        vector<int> derivativeCoeffs;
        for(int i=1;i<p.coefficients.size();i++){
            derivativeCoeffs.push_back(p.coefficients[i] * i);
        }
        return Polynomial(derivativeCoeffs);
    }
};

int main(int argc, char* argv[]){
    Polynomial p1({2, -3, 0, 4});
    Polynomial p2({1, 2, 3});

    PolynomialUtils utils;

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    Polynomial sum = p1 + p2;
    cout << "p1 + p2: " << sum << endl;

    Polynomial p1_derivative = utils.derivative(p1);
    cout << "Derivative of p1: " << p1_derivative << endl;

    int result = utils.evaluate(p1, 2);
    cout << "p1 evaluated at x = 2: " << result << endl;

    return 0;
}

