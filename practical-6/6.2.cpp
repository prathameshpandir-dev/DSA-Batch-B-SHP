#include <bits/stdc++.h>
using namespace std;
struct Node{
    string page;
    Node *next;
    Node(string s){page=s;
    next=NULL;
    }
};
Node *top=NULL;
void push(string s){
    Node *p=new Node(s);
    p->next=top;
    top=p;
}
void popPage(){
    if(!top){cout<<"No page\n";
    return;
    }
    Node *p=top;
    top=top->next;
    delete p;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){string s;
        cin>>s;
        push(s);
        }
        else if(op==2) popPage();
        if(top) cout<<top->page<<"\n";
        else cout<<"Empty\n";
    }
}
