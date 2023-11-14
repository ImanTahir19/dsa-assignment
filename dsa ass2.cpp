#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void traverse() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void updateAtPosition(int position, int newValue) {
        Node* current = head;
        for (int i = 1; i < position && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            current->data = newValue;
            cout << "Value updated at position " << position << endl;
        } else {
            cout << "Invalid position" << endl;
        }
    }

    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Value inserted at the beginning" << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
            cout << "Value inserted at position " << position << endl;
        } else {
            cout << "Invalid position" << endl;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from the beginning" << endl;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Deleted from the end" << endl;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        cout << "Deleted from the end" << endl;
    }

    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted from position " << position << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            cout << "Deleted from position " << position << endl;
        } else {
            cout << "Invalid position" << endl;
        }
    }
};

int main() {
    LinkedList linkedList;

    // Insert values
    linkedList.insertAtPosition(1, 10);
    linkedList.insertAtPosition(2, 20);
    linkedList.insertAtPosition(3, 30);

    // Traverse and print the linked list
    cout << "Linked List: ";
    linkedList.traverse();

    // Search for a value
    int searchValue = 20;
    if (linkedList.search(searchValue))
        cout << searchValue << " is found in the linked list." << endl;
    else
        cout << searchValue << " is not found in the linked list." << endl;

    // Update at a specific position
    linkedList.updateAtPosition(2, 25);

    // Traverse and print the updated linked list
    cout << "Updated Linked List: ";
    linkedList.traverse();

    // Delete from the beginning
    linkedList.deleteFromBeginning();

    // Traverse and print the linked list after deletion
    cout << "Linked List after deletion from the beginning: ";
    linkedList.traverse();

    // Delete from the end
    linkedList.deleteFromEnd();

    // Traverse and print the linked list after deletion
    cout << "Linked List after deletion from the end: ";
    linkedList.traverse();

    // Delete from a specific position
    linkedList.deleteFromPosition(1);

    // Traverse and print the linked list after deletion
    cout << "Linked List after deletion from position 1: ";
    linkedList.traverse();

    return 0;
}
