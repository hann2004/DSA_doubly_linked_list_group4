
  DSA - Doubly Linked List Project (Group 4)

Welcome to our Data Structures and Algorithms group project! This is a C++ console application that implements a **Doubly Linked List** with full functionality and a clean, interactive terminal interface. It is part of our university coursework under the subject of **Data Structures**.


Project Structure
```bash
DSA_doubly_linked_list_group4/
│
├── main.cpp               # Full implementation of the doubly linked list CLI program
├── README.md              # You’re reading it 
├── test_cases.txt         # Contains sample test cases for validation
└── contributions/         # Individual markdown files showing each member's contribution
├── hanan.md
├── berutawit.md
├── degnet.md
├── rita.md
├── zekiya.md
└── fenet.md
```

 How to Run

 Requirements

- C++ compiler (e.g. `g++`)
- Terminal or Command Prompt

 Steps

1. **Compile the code**:
   ```bash
   g++ -o dll_app main.cpp


2. **Run the program**:

   ```bash
   ./dll_app
   ```

3. **Follow the interactive menu** to insert, delete, display, or search elements in the list.



 Features

* Insert node at beginning, end, or at a specific position
* Delete node from beginning, end, or a specific position
* Search a node by value
* Traverse list forwards and backwards
* Colorful terminal output (with ANSI escape codes)
* Automatically loads a sample list on start
* Clean memory management (deletes entire list on exit)



 Test Cases

You can find sample test cases in the `test_cases.txt` file. These include:

* Typical insertions and deletions
* Edge cases (e.g. deleting from an empty list)
* Searching for present and absent values



 Group 4 - Team Members and Contributions

| Name          | Contribution Summary                                                                             | Full Log                                     |
| ------------- | ------------------------------------------------------------------------------------------------ | -------------------------------------------- |
| **Hanan**     | 	Setup, includes, color definitions, Node struct, constructor & destructor of DoublyLinkedList  | [`hanan.md`](contributions/hanan.md)         |
| **Berutawit** | Insertion methods: insertAtBeginning, insertAtEnd, insertAtPosition with forward display         | [`berutawit.md`](contributions/berutawit.md) |
| **Degnet**    | Deletion methods: deleteAtBeginning, deleteAtEnd, deleteAtPosition with display after deletions  | [`degnet.md`](contributions/degnet.md)       |
| **Rita**      | Display methods: displayForward, displayBackward, and search function                            | [`rita.md`](contributions/rita.md)           |
| **Zekiya**    | Menu interface: main menu display, user input prompts, calling class methods                     | [`zekeriya.md`](contributions/zekeriya.md)   |
| **Fenet**     | Menu logic: switch-case handling for all menu options, input validation                          | [`fenet.md`](contributions/fenet.md)         |



 Learning Outcomes

* Strengthened understanding of doubly linked list structures
* Improved our C++ problem-solving and memory handling
* Learned collaboration using Git-style file structure
* Practiced modular code development and teamwork



 License

This project is for academic use and personal learning. Feel free to explore and modify for educational purposes. No commercial use is permitted.



Made with  by Group 4 — Software Engineering students at Arba Minch University.




