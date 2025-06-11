#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
// Berutawit 
void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        cout << GREEN << "Inserted " << val << " at the beginning.\n" << RESET;
        displayForward();
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        cout << GREEN << "Inserted " << val << " at the end.\n" << RESET;
        displayForward();
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            insertAtEnd(val);
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
            cout << GREEN << "Inserted " << val << " at position " << pos << ".\n" << RESET;
            displayForward();
        }
    }

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = nullptr;
        size = 0;
    }
void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        cout << RED << "Deleted " << temp->data << " from beginning.\n" << RESET;
        delete temp;
        size--;
        displayForward();
    }

    void deleteAtEnd() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        cout << RED << "Deleted " << temp->data << " from end.\n" << RESET;
        delete temp;
        size--;
        displayForward();
    }

    void deleteAtPosition(int pos) {
        if (!head || pos < 1) return;

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp && i < pos; ++i) {
            temp = temp->next;
        }

        if (!temp) return;

        if (temp == tail) {
            deleteAtEnd();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            cout << RED << "Deleted " << temp->data << " at position " << pos << ".\n" << RESET;
            delete temp;
            size--;
            displayForward();
        }
}

void displayForward() {
        Node* temp = head;
        cout << MAGENTA << "List (forward): " << RESET;
        while (temp) {
            cout << CYAN << temp->data << " " << RESET;
            temp = temp->next;
        }
        cout << YELLOW << "[Size: " << size << "]" << RESET << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        cout << MAGENTA << "List (backward): " << RESET;
        while (temp) {
            cout << CYAN << temp->data << " " << RESET;
            temp = temp->prev;
        }
        cout << endl;
    }

    int search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val)
                return pos;
            temp = temp->next;
            ++pos;
        }
        return -1;
    }

    void loadSampleData() {
        int arr[] = {10, 20, 30, 40, 50};
        for (int val : arr)
            insertAtEnd(val);
    }
};
//fenet
if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "Invalid input type. Please enter a number.\n" << RESET;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                dll.insertAtPosition(val, pos);
                break;
            case 4:
                dll.deleteAtBeginning();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                dll.deleteAtPosition(pos);
                break;
            case 7:
                dll.displayForward();
                break;
            case 8:
                dll.displayBackward();
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> val;
                pos = dll.search(val);
                if (pos == -1)
                    cout << RED << "Value not found.\n" << RESET;
                else
                    cout << GREEN << "Found at position: " << pos << "\n" << RESET;
                break;
            case 0:
                cout << YELLOW << "Exiting program. Goodbye!\n" << RESET;
                return 0;
            default:
                cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    }

    return 0;
}
