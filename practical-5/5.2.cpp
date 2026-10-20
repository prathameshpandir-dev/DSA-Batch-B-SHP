#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(int pos, int x, int type) {
    Node* newNode = new Node{x, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        if (type == 2)
            newNode->prev = head;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    if (type == 2) {
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
}

void deleteNode(int pos, int type) {
    if (head == NULL)
        return;

    Node* temp = head;

    if (pos == 1) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        while (temp->next != head)
            temp = temp->next;

        Node* del = head;
        head = head->next;
        temp->next = head;

        if (type == 2)
            head->prev = temp;

        delete del;
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head)
        return;

    Node* del = temp->next;
    temp->next = del->next;

    if (type == 2)
        del->next->prev = temp;

    delete del;
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int ch, type, pos, x;

    cout << "1. Circular Linked List\n2. Doubly Circular Linked List\n";
    cin >> type;

    do {
        cout << "1. Join student\n2. Leave student\n3. Display circle\n0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> pos >> x;
                insert(pos, x, type);
                break;

            case 2:
                cin >> pos;
                deleteNode(pos, type);
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
