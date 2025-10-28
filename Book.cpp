#include "Book.h"
using namespace std;

Book::Book() : id(0), title(""), author(""), isIssued(false){}  //default constructor

Book::Book(int id, string title, string author) : id(id), title(title), author(author), isIssued(false){} //Parametrized cnostructor

void Book::display() const{
    cout << "ID: " << id 
            << "| Title: " << title
            << "| Author: " << author
            << "| Status: " << (isIssued ? "Issued" : "Available")
            << endl;
}

int Book::getId() const {return id;}
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
bool Book::getStatus() const {return isIssued;}


void Book::issueBook() {
    isIssued = true;
    cout << "Book issued successfully.\n";
}
void Book::returnBook() {
    isIssued = false;
    cout << "Book returned successfully.\n";
}