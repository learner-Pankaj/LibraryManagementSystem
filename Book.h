#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>

class Book{
    int id;
    std::string author;
    std::string title;
    bool isIssued;

    public:
        Book();
        Book(int id, std::string author, std::string title);

        void display() const;   //kept const because I want data to be read only mode not to update
        int getId() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        bool getStatus() const;

        void issueBook();
        void returnBook();
};

#endif