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
        int h1=x%n;
        int h2=n-(x%n);
        if(h2==0) h2=1;
        int pos=-1;
        for(int i=0;
        i<n;
        i++){
            int p=(h1+i*h2)%n;
            if(table[p]==-1){pos=p;
            break;
            }
        }
        if(pos==-1) cout<<"Full\n";
        else table[pos]=x;
    }
    for(int i=0;
    i<n;
    i++) cout<<i<<": "<<table[i]<<"\n";
}
