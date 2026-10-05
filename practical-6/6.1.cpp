#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> st(n);
    int top=-1,q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            if(top==n-1) cout<<"Overflow\n";
            else{st[++top]=x;
            cout<<st[top]<<"\n";
            }
        }else if(op==2){
            if(top==-1) cout<<"Underflow\n";
            else{cout<<st[top]<<"\n";
            top--;
            }
        }else if(op==3){
            if(top==-1) cout<<"Empty\n";
            else cout<<st[top]<<"\n";
        }
    }
}
