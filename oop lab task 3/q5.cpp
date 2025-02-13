#include<iostream>
#include<string.h>
 using namespace std;
 
 class book{
 	public:
 		string book_name;
        int ISBN;
        string author;
		string publisher;
		
    book(string book_name,int ISBN,string author,string publisher){
        this->book_name=book_name;
        this->ISBN=ISBN;
        this->author=author;
        this->publisher=publisher;
    }
    string get_name(){
        return book_name;
    }
    string get_author(){
        return author;
    }
    string get_publisher(){
        return publisher;
    }
    int get_isbn(){
        return ISBN;
    }
 };
int main(int argc, char*argv[]){
book books[5] = {
        book("The Great Gatsby",0743273565, "F. Scott Fitzgerald", "Scribner"),
        book("1984",451524935, "George Orwell", "Signet Classic"),
        book("To Kill a Mockingbird",61120084, "Harper Lee", "Harper Perennial"),
        book("Moby Dick", 1503280786, "Herman Melville", "CreateSpace"),
        book("Pride and Prejudice",150329056, "Jane Austen", "CreateSpace")
    };
    for(int i=0;i<5;i++){
        cout<<"book"<<i+1<<endl;
        cout<<books[i].get_author()<<endl;
        cout<<books[i].get_name()<<endl;
        cout<<books[i].get_publisher()<<endl;
        cout<<books[i].get_isbn()<<endl;
    }
return 0;
 }
