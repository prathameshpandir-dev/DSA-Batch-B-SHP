#include <bits/stdc++.h>
using namespace std;
struct Node{
    string name;
    Node *next;
    Node(string s){name=s;
    next=NULL;
    }
};
Node *front=NULL,*rear=NULL;
void add(string s){
    Node *p=new Node(s);
    if(!rear) front=rear=p;
    else{rear->next=p;
    rear=p;
    }
}
void removePatient(){
    if(!front){cout<<"Empty\n";
    return;
    }
    Node *p=front;
    front=front->next;
    if(!front) rear=NULL;
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
        add(s);
        }
        else if(op==2) removePatient();
        if(front) cout<<front->name<<"\n";
        else cout<<"Empty\n";
    }
}
