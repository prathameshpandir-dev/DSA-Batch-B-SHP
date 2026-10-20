#include <iostream>
#include <string>
using namespace std;

string st[50];
int top = -1;

void visit(string page) {
    st[++top] = page;
}

void back() {
    if (top > 0)
        top--;
    else
        cout << "No previous page\n";
}

void display() {
    if (top == -1)
        cout << "No page visited\n";
    else
        cout << st[top] << endl;
}

int main() {
    int ch;
    string page;

    do {
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> page;
                visit(page);
                break;
            case 2:
                back();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
