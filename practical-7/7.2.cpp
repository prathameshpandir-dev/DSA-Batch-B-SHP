#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void arrive(int x) {
    Node* newNode = new Node{x, NULL};

    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void attend() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "No patients waiting\n";
        return;
    }

    cout << front->data << endl;
}

int main() {
    int ch, x;

    do {
            cout<<"1-ADD\n2-delete\n3-display\n 0-exit"<<endl;
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                arrive(x);
                break;
            case 2:
                attend();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
