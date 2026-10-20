#include <iostream>
using namespace std;

int main() {
    int hash[10], n, x;

    for (int i = 0; i < 10; i++)
        hash[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> x;

        int pos = x % 10;
        int count = 0;

        while (hash[pos] != -1 && count < 10) {
            pos = (pos + 1) % 10;
            count++;
        }

        if (count == 10)
            cout << "Parking lot is full\n";
        else
            hash[pos] = x;
    }

    cout << "Parking slots:\n";
    for (int i = 0; i < 10; i++)
        cout << i << " : " << hash[i] << endl;

    return 0;
}
