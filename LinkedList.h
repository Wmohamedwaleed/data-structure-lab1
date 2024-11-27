#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
private:
    Node* head;
    Node* tail;

    // Helper function to find a node by its data
    Node* getNodeUsingData(int data) {
        Node* current = head;
        while (current != NULL) {
            if (current->Data == data) {
                return current;
            }
            current = current->Next;
        }
        return NULL;  // Not found
    }

public:
    LinkedList() {
        head = tail = NULL;
    }

    // Add a new node with the given data to the list
    void add(int data) {
        Node* node = new Node(data);  // Create new node

        if (head == NULL) {  // First node
            head = tail = node;
        } else {  // Not the first node
            tail->Next = node;  // Old -> Next = New Node
            node->Prev = tail;  // New Node -> Prev = Old Node
            tail = node;        // Update tail
        }
    }

    // Display the list elements
    void display() {
        Node* current = head;
        if (current == NULL) {
            cout << "Linked List is Empty\n";
            return;
        }
        while (current != NULL) {
            cout << current->Data << "\t";
            current = current->Next;
        }
        cout << endl;
    }

    // Remove a node by its data
    void removeNode(int data) {
        Node* node = getNodeUsingData(data);
        if (node == NULL) {
            cout << "Element Not Found, Can't Remove\n";
            return;
        }

        if (node == head) {  // Removing the first node
            if (node == tail) {  // Only one node in the list
                head = tail = NULL;
            } else {
                head = node->Next;
                head->Prev = NULL;
            }
        } else if (node == tail) {  // Removing the last node
            tail = node->Prev;
            tail->Next = NULL;
        } else {  // Removing a middle node
            Node* A = node->Prev;
            Node* B = node->Next;
            A->Next = B;
            B->Prev = A;
        }

        delete node;  // Free the memory
    }

    // Insert a new node with data after the node with afterdata
    void insert_after(int data, int afterdata) {
        Node* node = getNodeUsingData(afterdata);
        if (node == NULL) {
            cout << "Element Not Found, Can't Insert\n";
            return;
        }

        Node* newNode = new Node(data);

        if (node == tail) {  // Insert at the tail (last position)
            node->Next = newNode;
            newNode->Prev = node;
            tail = newNode;
        } else {  // Insert in the middle
            Node* nextNode = node->Next;
            node->Next = newNode;
            newNode->Prev = node;
            newNode->Next = nextNode;
            if (nextNode != NULL) {
                nextNode->Prev = newNode;
            }
        }
    }

void insert_before(int data, int befordata) {
    Node* node = getNodeUsingData(befordata);
    if (node == NULL) {
        cout << "Element Not Found, Can't Insert\n";
        return;
    }


    Node* newNode = new Node(data);

    if (node == head) {
        newNode->Next = node;
        node->Prev = newNode;
        head = newNode;
    } else if (node == tail) {  // Insert before the tail
        Node* beforeNode = node->Prev;
        beforeNode->Next = newNode;
        newNode->Prev = beforeNode;
        newNode->Next = node;
        node->Prev = newNode;
    } else {  // Insert in the middle
        Node* beforeNode = node->Prev;
        beforeNode->Next = newNode;
        newNode->Prev = beforeNode;
        newNode->Next = node;
        node->Prev = newNode;
    }
}


int counter () {
        int x=0;
        Node* COUNT = head;
        while (COUNT != NULL) {
               COUNT = COUNT->Next;
                x++;
        }
         return x;  // Not found
    }

int getdatabyindex (int index) {
        int x=0;
        Node* getdata = head;
        while (getdata != NULL) {
                if(index==x)
               return getdata->Data;
               getdata = getdata->Next;
                x++;
        }
    }



    // Search for a node with the given data
    int search_using_data(int data) {
        Node* node = getNodeUsingData(data);
        return (node == NULL) ? 0 : 1;  // Return 0 if not found, 1 if found
    }

protected:
    // No additional protected members required for this class.
};

#endif // LINKEDLIST_H
