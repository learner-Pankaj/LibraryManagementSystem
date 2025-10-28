console-based Library Management System

This project demonstrates class design, encapsulation, STL usage, file handling, and exception management — all in a structured, real-world style.

🧱 Features:

📚 Add New Books — Add books with title, author, and ID.

🔍 Search Books — Search by title or author keywords.

📄 Display Books — View all stored books with status (issued/available).

✅ Issue / Return Books — Change issue status interactively.

💾 Persistent Storage — Uses file handling to save and reload data automatically.

⚠️ Input Validation & Exception Handling — Prevents invalid IDs and handles file errors gracefully.

🧠 Concepts Used

Concept	                |  Description
------------------------------------------------------------------------------------------
Classes & Objects	      |  Separate Book and Library classes with clear responsibilities.
Encapsulation	          |  Private data members and public accessors/mutators.
STL (vector)	          |  Dynamic list for storing books efficiently.
File Handling (fstream)	|  Read/write data for persistence across runs.
Exception Handling	    |  Handles invalid input and file errors.
Menu-driven System	    |  Simple text-based interface for user operations.

🗂️ Project Structure

LibraryManagementSystem/
│
├── Book.h
├── Book.cpp
├── Library.h
├── Library.cpp
├── main.cpp
├── build.bat            # (for Windows users – compile & run)
├── library_data.txt      # auto-created file for storing books
└── README.md

🧩 Sample Menu

----- Library Menu -----
1. Add Book
2. Display Books
3. Issue Book
4. Return Book
5. Search by Title
6. Search by Author
7. Save & Exit
Enter choice:

