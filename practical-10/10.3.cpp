#include <iostream>
using namespace std;

int main() {
    int hash[10], n, x;

    for (int i = 0; i < 10; i++)
        hash[i] = -1;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> x;

        int h1 = x % 10;
        int h2 = 7 - (x % 7);
        int pos = h1;
        int j = 0;

        while (hash[pos] != -1 && j < 10) {
            j++;
            pos = (h1 + j * h2) % 10;
        }

        if (j == 10)
            cout << "Hash table is full\n";
        else
            hash[pos] = x;
    }

    cout << "Hash table:\n";

    for (int i = 0; i < 10; i++)
        cout << i << " : " << hash[i] << endl;

    return 0;
}
