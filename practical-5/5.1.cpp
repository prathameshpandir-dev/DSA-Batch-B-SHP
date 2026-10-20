#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBegin(string song) {
    Node* newNode = new Node{song, NULL, head};

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(string song) {
    Node* newNode = new Node{song, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(string name, string song) {
    Node* temp = head;

    while (temp != NULL && temp->song != name)
        temp = temp->next;

    if (temp == NULL)
        return;

    Node* newNode = new Node{song, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteSong() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int ch;
    string song, name;

    do {
        cout << "1. Add at beginning\n2. Add at end\n3. Insert after song\n4. Remove first song\n5. Display\n0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> song;
                insertBegin(song);
                break;

            case 2:
                cin >> song;
                insertEnd(song);
                break;

            case 3:
                cin >> name >> song;
                insertAfter(name, song);
                break;

            case 4:
                deleteSong();
                break;

            case 5:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
