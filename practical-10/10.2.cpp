#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> table[10];
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        table[x%10].push_back(x);
    }
    for(int i=0;
    i<10;
    i++){
        cout<<i<<": ";
        for(int x:table[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
