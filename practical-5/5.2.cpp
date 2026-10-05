#include <bits/stdc++.h>
using namespace std;
struct Node{
    string song;
    Node *prev,*next;
    Node(string s){song=s;
    prev=next=NULL;
    }
};
Node *head=NULL,*tail=NULL;
void addFirst(string s){
    Node *p=new Node(s);
    if(!head) head=tail=p;
    else{p->next=head;
    head->prev=p;
    head=p;
    }
}
void addLast(string s){
    Node *p=new Node(s);
    if(!tail) head=tail=p;
    else{tail->next=p;
    p->prev=tail;
    tail=p;
    }
}
void insertAfter(string cur,string s){
    Node *q=head;
    while(q && q->song!=cur) q=q->next;
    if(!q){cout<<"Song not found\n";
    return;
    }
    Node *p=new Node(s);
    p->next=q->next;
    p->prev=q;
    if(q->next) q->next->prev=p;
    else tail=p;
    q->next=p;
}
void removeFirst(){
    if(!head){cout<<"Playlist empty\n";
    return;
    }
    Node *p=head;
    head=head->next;
    if(head) head->prev=NULL;
    else tail=NULL;
    delete p;
}
void display(){
    Node *p=head;
    while(p){cout<<p->song<<" ";
    p=p->next;
    }
    cout<<"\n";
}
int countSongs(){
    int n=0;
    Node *p=head;
    while(p){n++;
    p=p->next;
    }
    return n;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){string s;
        cin>>s;
        addFirst(s);
        }
        else if(op==2){string s;
        cin>>s;
        addLast(s);
        }
        else if(op==3){string cur,s;
        cin>>cur>>s;
        insertAfter(cur,s);
        }
        else if(op==4) removeFirst();
        else if(op==5) cout<<countSongs()<<"\n";
        else if(op==6) display();
    }
}
