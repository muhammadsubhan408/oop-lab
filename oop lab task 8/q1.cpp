#include<iostream>
#include<numeric>
#include<cmath>
using namespace std;

class Fraction{
    int numerator;
    int denominator;

    void reduce(){
        int gcd;
        numerator /= gcd;
        denominator /= gcd;
        if(denominator<0){
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int denom) : numerator(num),denominator(denom){
        if(denom == 0){
            throw invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    Fraction operator+(const Fraction& other) const{
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const{
        int num = numerator*other.denominator - other.numerator * denominator;
        int denom = denominator*other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const{
        int num = numerator*other.numerator;
        int denom = denominator*other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const{
        int num = numerator*other.denominator;
        int denom = denominator*other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const{
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const{
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const{
        return numerator*other.denominator<other.numerator*denominator;
    }

    bool operator>(const Fraction& other) const{
        return other < *this;
    }

    bool operator<=(const Fraction& other) const{
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const{
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f){
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f){
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
};

int main(){
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl;
    return 0;
}

