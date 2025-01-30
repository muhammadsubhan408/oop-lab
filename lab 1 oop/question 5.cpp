#include <iostream>
using namespace std;
int main() {
string movieName;
float adultTicketPrice, childTicketPrice;
int adultTicketsSold, childTicketsSold;
float donationPercentage;
    cout << "Enter movie name: ";
    cin>>movieName;
    cout << "Enter adult ticket price: ";
    cin >> adultTicketPrice;
    cout << "Enter child ticket price: ";
    cin >> childTicketPrice;
    cout << "Enter number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter number of child tickets sold: ";
    cin >> childTicketsSold;
    cout << "Enter percentage of gross amount to be donated to charity: ";
    cin >> donationPercentage;

    float grossAmount = (adultTicketsSold * adultTicketPrice) + (childTicketsSold * childTicketPrice);
    float amountDonated = (donationPercentage / 100.0) * grossAmount;
    float netSale = grossAmount - amountDonated;
    
    cout<<"movie name:"<<movieName<<endl;
    cout<<"tickets sold:"<< adultTicketsSold+childTicketsSold<<endl;
    cout<<"gross amount:"<<grossAmount<<endl;
    cout<<"percentage of gross amount:"<<donationPercentage<<endl;
    cout<<"donated amount:"<<amountDonated<<endl;
    cout<<"net sales:"<<netSale<<endl;
}
