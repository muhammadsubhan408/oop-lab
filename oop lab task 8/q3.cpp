#include<iostream>
#include<vector>
#include<string>
using namespace std;


class BigInteger{
	
    vector<int> digits;
    bool isNegative;
    
    void removeLeadingZeros(BigInteger& bigInt) const{
        while(bigInt.digits.size()>1 && bigInt.digits.back()==0){
            bigInt.digits.pop_back();
        }
    }
    int compareAbsoluteValues(const BigInteger& a, const BigInteger& b) const{
        if(a.digits.size() != b.digits.size()){
            return a.digits.size()>b.digits.size() ? 1 : -1;
        }
        for(int i=a.digits.size()-1;i>=0;i--){
            if(a.digits[i] != b.digits[i]){
                return a.digits[i] > b.digits[i] ? 1 : -1;
            }
        }
        return 0;
    }

    BigInteger operator-() const{
        BigInteger result = *this;
        result.isNegative = !isNegative;
        return result;
    }
public:
    BigInteger() : isNegative(false){}
    BigInteger(string str){
        isNegative = (str[0] == '-');
        if(isNegative){
			str = str.substr(1);}
        for(int i=str.size()-1;i>=0;i--){
            digits.push_back(str[i]-'0');
        }
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bigInt){
        if(bigInt.isNegative){
			cout << "-";}
        for(int i = bigInt.digits.size()-1;i >= 0;i--){
            cout << bigInt.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& bigInt){
        string str;
        cin>>str;
        bigInt = BigInteger(str);
        return is;
    }

    BigInteger operator+(const BigInteger& other) const{
        if(isNegative && !other.isNegative){
            BigInteger temp = *this;
            temp.isNegative = false;
            return other-temp;
        }
        if(!isNegative && other.isNegative){
            BigInteger temp = other;
            temp.isNegative = false;
            return *this-temp;
        }
        BigInteger result;
        int carry = 0;
        int maxLength = digits.size()>other.digits.size() ? digits.size() : other.digits.size();
        for(int i=0;i<maxLength || carry;i++){
            int sum = carry;
            if(i<digits.size()){
				sum += digits[i];}
            if(i<other.digits.size()){
				sum += other.digits[i];}
            result.digits.push_back(sum % 10);
            carry = sum/10;
        }
        result.isNegative = isNegative;
        return result;
    }

    BigInteger operator-(const BigInteger& other) const{
        if(isNegative && !other.isNegative){
            BigInteger temp = *this;
            temp.isNegative = false;
            return -(temp + other);
        }
        if(!isNegative && other.isNegative){
            BigInteger temp = other;
            temp.isNegative = false;
            return *this+temp;
        }
        bool resultNegative = false;
        const BigInteger *larger, *smaller;
        if(compareAbsoluteValues(*this, other)>=0){
            larger = this;
            smaller = &other;
        }else{
            larger = &other;
            smaller = this;
            resultNegative = true;
        }
        BigInteger result;
        int borrow = 0;
        for(int i=0;i<larger->digits.size();i++){
            int diff = larger->digits[i]-borrow;
            if(i<smaller->digits.size()){
				diff -= smaller->digits[i];}
            if(diff<0){
                diff += 10;
                borrow = 1;
            }else{
                borrow = 0;
            }
            result.digits.push_back(diff);
        }

        result.isNegative = resultNegative;
        removeLeadingZeros(result);
        return result;
    }
    bool operator==(const BigInteger& other) const{
        if(isNegative != other.isNegative || digits.size() != other.digits.size()) {
            return false;
        }
        for(int i=0;i<digits.size();i++){
            if(digits[i] != other.digits[i]){
				return false;}
        }
        return true;
    }

    bool operator!=(const BigInteger& other) const{
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const{
        if(isNegative && !other.isNegative) return true;
        if(!isNegative && other.isNegative) return false;
        int compare = compareAbsoluteValues(*this, other);
        return (isNegative ? compare>0 : compare<0);
    }

    bool operator>(const BigInteger& other) const{
        return other<*this;
    }

    bool operator<=(const BigInteger& other) const{
        return !(other<*this);
    }

    bool operator>=(const BigInteger& other) const{
        return !(*this<other);
    }


};

int main(int argc, char* argv[]){
    BigInteger a, b;
    cout<<"Enter first big integer: ";
    cin>>a;
    cout<<"Enter second big integer: ";
    cin>>b;

    cout<<"Sum: " << a+b <<endl;
    cout<<"Difference: " <<a-b <<endl;
    cout<<"Equal: " << (a==b) <<endl;
    cout<<"Greater than: " << (a>b) <<endl;

    return 0;
}

