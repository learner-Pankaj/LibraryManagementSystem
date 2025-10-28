#include<iostream>
#include "Library.h"

void Library::addBook(const Book &book){
    for(const auto& b : books){
        if(b.getId() == book.getId()){
            std::cout << "Book with this id already exist.\n";
            return;
        }
    }

    if(book.getTitle().empty() || book.getAuthor().empty()){
        std::cout << "Titlr or Author cannot be empty.\n";
        return;
    }

    books.push_back(book);
    std::cout<<"Book added successful." << std::endl;
}

void Library::displayBooks() const{
    if(books.empty()){
        std::cout << "No books available.\n";
        return;
    }

    for(const auto &b : books){
        b.display();
    }
}

Book* Library::findBookById(int id){
    for(auto &b:books){
        if(b.getId()==id){
            return &b;
        }
    }
    return nullptr;
}

void Library::issueBook(int id){
    Book* book = findBookById(id);
    if(book){
        book->issueBook();
    }else{
        std::cout << "Book not found.\n";
    }
}

void Library::returnBook(int id){
    Book* book = findBookById(id);
    if(book){
        book->returnBook();
    }else{
        std::cout << "Book not found.\n";
    }
}

//saving books to library
void Library::saveToFile(const std::string &filename) const{
    std::ofstream file(filename);
    if(!file){
        std::cout << "Error saving to file.\n";
        return;
    }

    for(const auto &b : books){
        file << b.getId() << '\n'
            << b.getTitle() << '\n'
            << b.getAuthor() << '\n'
            << b.getStatus() << '\n' ;
    }

    file.close();
    std::cout << "Book saved to Library successfully.\n";
}

//Load books from file
void Library::loadFromFile(const std::string &filename){
    std::ifstream file(filename);
    if(!file){
        std::cout << "No previous data found.\n";
        return;
    }

    books.clear();
    int id, issued;
    std::string title, author;

    while(file >> id){
        file.ignore();  //consume newline
        std::getline(file, title);
        std::getline(file, author);
        file >> issued;
        file.ignore();

        Book b(id, title, author);
        if(issued){
            b.issueBook();
        }
        books.push_back(b);
    }
    file.close();
    std::cout << "library loaded successfully.\n";
}

void Library::searchBookByTitle(const std::string& titleName) const{
    bool found = false;
    for(const auto& b : books){
        if(b.getTitle().find(titleName) != std::string::npos){
            b.display();
            found = true;
        }
    }
    if(!found){
        std::cout << "No book found with that Title Name.\n";
    }
}

void Library::searchBookByAuthor(const std::string& authorName) const{
    bool found = false;
    for(const auto& b : books){
        if(b.getTitle().find(authorName) != std::string::npos){
            b.display();
            found = true;
        }
    }
    if(!found){
        std::cout << "No book found with that Author Name.\n";
    }
}