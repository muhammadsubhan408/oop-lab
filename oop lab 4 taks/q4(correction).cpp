#include <iostream>
using namespace std;

class book {
    string author, title, publisher;
    double price;
    int stock;

public:
    // Constructor
    book(string book_name, string writer, string publish, double amount, int quantity) {
        title = book_name;
        author = writer;
        publisher = publish;
        price = amount;
        stock = quantity;
    }

    void bookSearch(string t, string a) {
        if (title == t && author == a) { // Direct string comparison
            cout << "\nBook Available!\n";
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Price per copy: $" << price << endl;

            int copies;
            cout << "Enter copies required: ";
            cin >> copies;
            cout << endl;

            if (copies <= stock) {
                cout << "Total Price: $" << copies * price << endl;
            } else {
                cout << "Sorry, only " << stock << " copies are available.\n";
            }
        } else {
            cout << "No such book is available.\n";
        }
    }
};

int main() {
    book book1("Lord of the Rings", "J.R.R. Tolkien", "Alt.Co", 20.58, 3);
    book book2("Pride and Prejudice", "Jane Austen", "George.Co", 94, 4);

    book1.bookSearch("Lord of the Rings", "J.R.R. Tolkien");
    book2.bookSearch("Matilda", "Roald Dahl"); // Not in inventory

    return 0;
}
