#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    string word, longw;
    cout<<"Enter a sentence:";
    getline(cin,s);

    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (word.length() > longw.length()) {
                longw = word;
            }
            word = "";
        } else {
            word += s[i];
        }
    }

    cout << longw<< endl;
    cout << longw.length();

    return 0;
}
