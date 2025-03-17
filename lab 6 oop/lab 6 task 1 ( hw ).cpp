#include <iostream>
using namespace std;

class Book{
    protected:
    string genre;
    public :

    Book(string gen){
        genre=gen;
    }

    virtual void Display(){

        cout<<"the genre of the book is " << genre <<endl;

    }

    virtual ~Book(){}

};

class Novel : public Book{

protected:

string title;
string author;

public:

Novel(string name,string writer):Book("novel"){
title=name;
author=writer;
}

void DisplayDetail(){
    cout<<"the title of the book is : "<<title<< endl;

cout<< "the author of the book is "<< author << endl;

}

};

class Mystery: public Book{

    protected:

string title;
string author;

public:

Mystery(string name,string writer):Book("mystery"){
    title=name;
    author=writer;
}

void DisplayDetail(){
    cout<<"the title of the book is : "<<title<< endl;
    
    cout<< "the author of the book is "<< author << endl;
}

};

int main(){
    Novel a("matilda","ronald dahl");
    Mystery b ("harry porter","eric john");
    a.Display();
    a.DisplayDetail();

    b.Display();
    b.DisplayDetail();

    return 0;
    
}
