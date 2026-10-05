#include <bits/stdc++.h>
using namespace std;
int main(){
    const int n=10;
    int table[n];
    fill(table,table+n,-1);
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int pos=x%10,tries=0;
        while(table[pos]!=-1&&tries<n){pos=(pos+1)%n;
        tries++;
        }
        if(tries==n) cout<<"Full\n";
        else table[pos]=x;
    }
    for(int i=0;
    i<n;
    i++) cout<<i<<": "<<table[i]<<"\n";
}
