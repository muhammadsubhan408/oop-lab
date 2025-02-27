#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class CoffeeShop {
public:
    string name;
    vector<string>menu;
    vector<string>orders;
    vector<float>prices;
    vector<string>itemType; 

    CoffeeShop(string shopName, vector<string> menuItems, vector<float> itemPrices, vector<string> types){
        name = shopName;
        menu = menuItems;
        prices = itemPrices;
        itemType = types;
    }

    string addOrder(string item){
        for (int i = 0;i < menu.size();i++){
            if (menu[i]==item){
                orders.push_back(item);
                return "Order for " + item + " added.";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder(){
        if (!orders.empty()){
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders(){
        return orders;
    }

    float dueAmount(){
        float total = 0;
        for (const string& order : orders) {
            for (size_t i = 0; i < menu.size(); i++) {
                if (menu[i] == order) {
                    total += prices[i];
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available";
        float minPrice = numeric_limits<float>::max();
        string cheapest;
        for (size_t i = 0; i < menu.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                cheapest = menu[i];
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (size_t i = 0; i < itemType.size(); i++) {
            if (itemType[i] == "drink") {
                drinks.push_back(menu[i]);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (size_t i = 0; i < itemType.size(); i++) {
            if (itemType[i] == "food") {
                food.push_back(menu[i]);
            }
        }
        return food;
    }
};

int main(int argc, char* argv[]){
    vector<string> menu = {"Coffee", "Tea", "Sandwich", "Cake"};
    vector<float> prices = {2.5, 1.8, 5.0, 3.0};
    vector<string> types = {"drink", "drink", "food", "food"};

    CoffeeShop myShop("The Java Spot", menu, prices, types);

    cout << myShop.addOrder("Coffee") << endl;
    cout << myShop.addOrder("Sandwich") << endl;
    cout << myShop.addOrder("Burger") << endl;

    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;

    cout << "List of Orders: " << endl;
    vector<string> orders = myShop.listOrders();
    for (const string& order : orders) {
        cout << order << endl;
    }

    cout << "Total Due: $" << myShop.dueAmount() << endl;
    cout << "Cheapest Item: " << myShop.cheapestItem() << endl;

    cout << "Drinks Only: " << endl;
    vector<string> drinks = myShop.drinksOnly();
    for (const string& drink : drinks) {
        cout << drink << endl;
    }

    cout << "Food Only: " << endl;
    vector<string> food = myShop.foodOnly();
    for (const string& foodItem : food) {
        cout << foodItem << endl;
    }

    return 0;
}
