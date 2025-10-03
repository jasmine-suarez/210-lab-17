// COMSC-210 | Lab 17 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototypes
void addFront(Node *&, float);
void addTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);
void output(Node *);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void addFront(Node *& head, float val) {
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = head;
    head = newVal;
}

void addTail(Node *& head, float val) {
    // create a new node
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = nullptr;

    // check if list is empty
    if (!head) {
        head = newVal;
        return;
    }

    // traverse to end of list
    Node *current = head;
    while (current->next)
        current = current->next;

    // links the node at the end
    current->next = newVal;
}

void deleteNode(Node *& head, int position) {
    Node *current = head;
    if (position == 1) {
        head = current->next;
        delete current;
        return;
    }

    Node *prev = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
        if (!current)
            return;
        if (i > 1)
            prev = prev->next;
    }

    prev->next = current->next;
    delete current;
}

void insertNode(Node *& head, int position, float val) {
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = nullptr;
    if (!head) {
        newVal->next = head;
        head = newVal;
        return;
    }

    Node *current = head;
    Node *prev = nullptr;
    for (int i = 0; i < position; i++) {
        prev = current;
        current = current->next;
    }

    newVal->next = current;
    prev->next = newVal;
}

void deleteList(Node *& head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}