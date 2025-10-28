#include<iostream>
#include "Library.h"

int main(){
    std::cout << "\n============= Welcome to Library Management =============\n" << std::endl;

    Library lib;
    try{
        lib.loadFromFile("library_data.txt");   //Load books on start of the program
    }catch(const std::exception& err){
        std::cerr << "Error loading file: " << err.what() << '\n';
    }
    
    int choice;

    while(true){
        std::cout << "\n-----Library Menu-----\n";
        std::cout << "\n1. Add Books\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Issue Books\n";
        std::cout << "4. Return Books\n";
        std::cout << "5. Exit\n";
        std::cout << "\n Enter Choice :: "; std::cin >> choice;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input, please enter a Number.\n";
            continue;
        }
        
        switch(choice){
            case 1:{
                int id;
                std::string title, author;

                std::cout << "Enter Id : "; std::cin >> id;
                std::cin.ignore();  //remove leftover newline

                std::cout << "Enter Title : "; std::getline(std::cin, title);
                std::cout << "Enter Author : "; std::getline(std::cin, author);
                Book newBook(id, title, author);
                lib.addBook(newBook);
                break;
            }
            case 2:{
                lib.displayBooks();
                break;
            }
            case 3:{
                int id;
                std::cout << "Enter book id to issue : "; std::cin >> id;
                lib.issueBook(id);
                break;
            }
            case 4:{
                int id;
                std::cout << "Enter book id to return : "; std::cin >> id;
                lib.returnBook(id);
                break;
            }
            case 5:{
                lib.saveToFile("library_data.txt");
                std::cout << "Exiting the program, Goodbye.\n";
                return 0;
            }
            default:
                std::cout << "Invalid choice, Please try again.\n";
                break;
        }
    }
}