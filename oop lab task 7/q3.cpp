#include<iostream>
using namespace std;

class Currency
{
public:
    double amount;
    string CurrencyCode;
    string currencySymbol;
    double exchangeRate;
    Currency(double a, string cc, string cs, double er) : amount(a), CurrencyCode(cc), currencySymbol(cs), exchangeRate(er) {};

    virtual void convertToBase() = 0;

    virtual void displayCurrency()
    {
        cout << "Amount: " << amount << endl;
        cout << "Currency Code: " << CurrencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }

    virtual void convertTo(Currency& TargetCurrency) = 0;
};

class Dollar : public Currency
{
public:
    Dollar(double a, string cc, string cs, double er) : Currency(a, cc, cs, er) {};

    void displayCurrency() override
    {
        Currency::displayCurrency();
    }

    void convertToBase() override
    {
        double baseAmount = amount * exchangeRate;
        cout << "Amount in base currency: " << baseAmount << endl;
    }

    void convertTo(Currency& TargetCurrency) override
    {
        if (TargetCurrency.CurrencyCode == "USD")
        {
            cout << "Can't convert to the same currency." << endl;
        }
        else if (TargetCurrency.CurrencyCode == "PKR")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Rupees: " << convertedAmount << endl;
        }
        else if (TargetCurrency.CurrencyCode == "EUR")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Euros: " << convertedAmount << endl;
        }
    }
};

class Rupee : public Currency
{
public:
    Rupee(double a, string cc, string cs, double er) : Currency(a, cc, cs, er) {};

    void displayCurrency() override
    {
        Currency::displayCurrency();
    }

    void convertToBase() override
    {
        double baseAmount = amount * exchangeRate;
        cout << "Amount in base currency: " << baseAmount << endl;
    }

    void convertTo(Currency& TargetCurrency) override
    {
        if (TargetCurrency.CurrencyCode == "PKR")
        {
            cout << "Can't convert to the same currency." << endl;
        }
        else if (TargetCurrency.CurrencyCode == "USD")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Dollars: " << convertedAmount << endl;
        }
        else if (TargetCurrency.CurrencyCode == "EUR")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Euros: " << convertedAmount << endl;
        }
    }
};

class Euro : public Currency
{
public:
    Euro(double a, string cc, string cs, double er) : Currency(a, cc, cs, er) {};

    void displayCurrency() override
    {
        Currency::displayCurrency();
    }

    void convertToBase() override
    {
        double baseAmount = amount * exchangeRate;
        cout << "Amount in base currency: " << baseAmount << endl;
    }

    void convertTo(Currency& TargetCurrency) override
    {
        if (TargetCurrency.CurrencyCode == "EUR")
        {
            cout << "Can't convert to the same currency." << endl;
        }
        else if (TargetCurrency.CurrencyCode == "USD")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Dollars: " << convertedAmount << endl;
        }
        else if (TargetCurrency.CurrencyCode == "PKR")
        {
            double convertedAmount = amount * (TargetCurrency.exchangeRate / exchangeRate);
            cout << "Amount in Rupees: " << convertedAmount << endl;
        }
    }
};

int main()
{
    Dollar dollar(100, "USD", "$", 1.0);   
    Rupee rupee(7400, "PKR", "RS.", 0.0135); 
    Euro euro(85, "EUR", "€", 1.18);        

    dollar.displayCurrency();
    rupee.displayCurrency();
    euro.displayCurrency();

    dollar.convertToBase();
    dollar.convertTo(euro);
    
    rupee.convertToBase();
    rupee.convertTo(dollar);
    rupee.convertTo(euro);
    
    euro.convertToBase();
    euro.convertTo(rupee);
    euro.convertTo(dollar);

    return 0;
}
