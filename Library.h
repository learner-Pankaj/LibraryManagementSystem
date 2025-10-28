#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include<vector>
#include<fstream>

class Library{
    private:
        std::vector<Book> books;    //collection of books

    public:
        //add new books
        void addBook(const Book &book);

        //display all books
        void displayBooks() const;

        //search book by id
        Book* findBookById(int id);

        //issue and return book
        void issueBook(int id);
        void returnBook(int id);

        //file operation
        void saveToFile(const std::string &filename) const;
        void loadFromFile(const std::string &filename);

        void searchBookByTitle(const std::string& titleName) const;
        void searchBookByAuthor(const std::string& authorName) const;
};
#endif