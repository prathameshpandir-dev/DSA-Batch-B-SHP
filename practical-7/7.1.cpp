#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1, n;

void join(int x) {
    if (rear == n - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1)
            front = 0;
        q[++rear] = x;
    }
}

void serve() {
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else {
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front == -1)
        cout << "Queue is empty\n";
    else
        cout << q[front] << endl;
}

int main() {
    int ch, x;
    cout<<"No of entries"<<endl;
    cin>>n;

    do {
        cout<<"1-ADD\n2-delete\n3-display\n 0-exit"<<endl;
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                join(x);
                break;
            case 2:
                serve();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
