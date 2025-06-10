#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertAtPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Position must be greater than 0.\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* current = head;
        int index = 1;

        while (current != nullptr && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (!current) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }

        current->next = newNode;
        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        cout << "Deleted node from beginning.\n";
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
        cout << "Deleted node from end.\n";
    }

    void deleteAtPosition(int pos) {
        if (!head || pos <= 0) {
            cout << "Invalid position or list is empty.\n";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* current = head;
        int index = 1;

        while (current && index < pos) {
            current = current->next;
            index++;
        }

        if (!current) {
            cout << "Position out of bounds.\n";
            return;
        }

        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;

        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;

        delete current;
        cout << "Deleted node at position " << pos << ".\n";
    }

    void displayForward() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        cout << "List (forward): ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void displayReverse() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = tail;
        cout << "List (reverse): ";
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << "\n";
    }

    void search(int value) {
        Node* current = head;
        int pos = 1;
        while (current) {
            if (current->data == value) {
                cout << "Value " << value << " found at position " << pos << ".\n";
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Value " << value << " not found in the list.\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, position;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Display Forward\n8. Display Reverse\n9. Search\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                dll.insertAtPosition(value, position);
                break;
            case 4:
                dll.deleteAtBeginning();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                dll.deleteAtPosition(position);
                break;
            case 7:
                dll.displayForward();
                break;
            case 8:
                dll.displayReverse();
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                dll.search(value);
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
