#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> shelf[10];
    int n, x;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> x;

        int pos = x % 10;
        shelf[pos].push(x);
    }

    cout << "Shelf contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << i << " : ";

        stack<int> temp = shelf[i];

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }

    return 0;
}
