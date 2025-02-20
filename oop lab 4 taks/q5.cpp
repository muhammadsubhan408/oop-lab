#include <iostream>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n = "", string t = "", double p = 0.0) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[10]; 
    string orders[10]; 
    int menuSize;
    int orderCount;

public:
    CoffeeShop(string n, MenuItem m[], int size) : name(n), menuSize(size), orderCount(0) {
        for (int i = 0; i < size; i++) {
            menu[i] = m[i];
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 10) {
                    orders[orderCount++] = itemName;
                    return "Order added: " + itemName;
                }
                return "Order list is full";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 1; i < orderCount; i++) {
                orders[i - 1] = orders[i];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders yet." << endl;
            return;
        }
        cout << "Current orders: ";
        for (int i = 0; i < orderCount; i++) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "Menu is empty";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    void drinksOnly() {
        cout << "Drinks available: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        cout << "Foods available: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    MenuItem menu[4] = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 1.5),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.0)
    };

    CoffeeShop shop("Java Cafe", menu, 4);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    
    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
