#include<iostream>
#include<vector>
using namespace std;

class Media
{
public:
    bool flag;
    string title, publicationDate, uniqueID, publisher;

    Media(string t, string p, string u, string pub) 
        : title(t), publicationDate(p), uniqueID(u), publisher(pub), flag(false) {}

    virtual void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut()
    {
        if (flag)
        {
            cout << "Item already checked out!" << endl;
        }
        else
        {
            flag = true;
            cout << "Item checked out!" << endl;
        }
    }

    void returnItem()
    {
        if (!flag)  // Corrected to set flag to false when returning an item
        {
            cout << "Item wasn't checked out!" << endl;
        }
        else
        {
            flag = false;
            cout << "Item returned!" << endl;
        }
    }

    // Overloaded searchMedia functions for different search criteria
    virtual void searchMedia(string search)
    {
        if (title == search)
        {
            displayInfo();
        }
    }

    virtual void searchMediaByAuthor(string author) {}
    virtual void searchMediaByPublisher(string searchPublisher)
    {
        if (publisher == searchPublisher)
        {
            displayInfo();
        }
    }

    virtual void searchMediaByID(string searchID)
    {
        if (uniqueID == searchID)
        {
            displayInfo();
        }
    }
};

class Book : public Media
{
public:
    string author, ISBN;
    int numPages;

    Book(string t, string p, string u, string pub, string author, string ISBN, int num)
        : Media(t, p, u, pub), author(author), ISBN(ISBN), numPages(num) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numPages << endl;
    }

    void searchMediaByAuthor(string authorSearch) override
    {
        if (author == authorSearch)
        {
            displayInfo();
        }
    }
};
class DVD : public Media
{
public:
    string director, duration, rating;

    DVD(string t, string p, string u, string pub, string director, string duration, string rating)
        : Media(t, p, u, pub), director(director), duration(duration), rating(rating) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media
{
public:
    string artist, genre;
    int numTracks;

    CD(string t, string p, string u, string pub, string artist, string genre, int numTracks)
        : Media(t, p, u, pub), artist(artist), genre(genre), numTracks(numTracks) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Tracks: " << numTracks << endl;
    }
};

class Magazine : public Media
{
public:
    int issueNumber;
    string frequency;

    Magazine(string t, string p, string u, string pub, int issueNumber, string frequency)
        : Media(t, p, u, pub), issueNumber(issueNumber), frequency(frequency) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Issue Number: "<< issueNumber << endl;
        cout << "Frequency: "<< frequency << endl;
    }
};

int main()
{
    Book book("Can't Hurt Me", "2022", "XYZ", "Lion Crest", "David Goggins", "9780743273565", 218);
    DVD dvd("Interstellar", "2014", "F001", "Paramount", "Christopher Nolan", "150.0", "R");
    CD cd("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", "Pop", 9);
    Magazine magazine("National Geographic", "2025", "M001", "National Geographic Society", 456, "Monthly");
    // Used vector to create array for media class and appended the above declared objects
    vector<Media*> library;
    library.push_back(&book);
    library.push_back(&dvd);
    library.push_back(&cd);
    library.push_back(&magazine);
    // Auto loop to iterate and display all media
    cout << "Displaying All Media:" << endl;
    for (Media* media : library)
    {
        media->displayInfo();
        cout << endl;
    }
    // Check-out functionality
    cout << "Checking out 'Can't Hurt Me'" << endl;
    book.checkOut();
    book.displayInfo();
    cout << endl;
    cout << "Returning 'Can't Hurt Me'" << endl;
    book.returnItem();
    book.displayInfo();
    cout << endl;
    cout << "Searching for title 'Interstellar'" << endl;
    for (Media* media:library)
    {
        media->searchMedia("Interstellar");
    }
    cout << "Searching for books by 'David Goggins'" << endl;
    for (Media* media:library)
    {
        media->searchMediaByAuthor("David Goggins");
    }
    cout << "Searching for publisher 'Paramount'" << endl;
    for (Media* media:library)
    {
        media->searchMediaByPublisher("Paramount");
    }
    cout << "Searching for media by ID 'F001'" << endl;
    for (Media* media:library)
    {
        media->searchMediaByID("F001");
    }

    return 0;
}
