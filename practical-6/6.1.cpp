#include <iostream>
using namespace std;

int st[100], top = -1, n;

void push(int x) {
    if (top == n - 1)
        cout << "Stack Overflow\n";
    else
        st[++top] = x;
}

void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        top--;
}

void display() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << st[top] << endl;
}

int main() {
    int ch, x;
    cin >> n;

    do {
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
