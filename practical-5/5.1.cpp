#include <bits/stdc++.h>
using namespace std;
struct SNode{
    int data;
    SNode *next;
    SNode(int x){data=x;
    next=NULL;
    }
};
struct DNode{
    int data;
    DNode *prev,*next;
    DNode(int x){data=x;
    prev=next=NULL;
    }
};
SNode *sh=NULL,*st=NULL;
DNode *dh=NULL,*dt=NULL;
void addS(int x,int pos){
    SNode *p=new SNode(x);
    if(!sh){sh=st=p;
    p->next=p;
    return;
    }
    if(pos<=1){p->next=sh;
    sh=p;
    st->next=sh;
    return;
    }
    SNode *q=sh;
    for(int i=1;
    i<pos-1 && q->next!=sh;
    i++) q=q->next;
    p->next=q->next;
    q->next=p;
    if(q==st) st=p;
}
void delS(int x){
    if(!sh)return;
    if(sh->data==x){
        if(sh==st){delete sh;
        sh=st=NULL;
        return;
        }
        SNode *p=sh;
        sh=sh->next;
        st->next=sh;
        delete p;
        return;
    }
    SNode *q=sh;
    while(q->next!=sh && q->next->data!=x) q=q->next;
    if(q->next!=sh){
        SNode *p=q->next;
        q->next=p->next;
        if(p==st) st=q;
        delete p;
    }
}
void showS(){
    if(!sh){cout<<"Empty\n";
    return;
    }
    SNode *p=sh;
    do{cout<<p->data<<" ";
    p=p->next;
    }while(p!=sh);
    cout<<"\n";
}
void addD(int x,int pos){
    DNode *p=new DNode(x);
    if(!dh){dh=dt=p;
    p->next=p->prev=p;
    return;
    }
    if(pos<=1){p->next=dh;
    p->prev=dt;
    dt->next=p;
    dh->prev=p;
    dh=p;
    return;
    }
    DNode *q=dh;
    for(int i=1;
    i<pos-1 && q->next!=dh;
    i++) q=q->next;
    p->next=q->next;
    p->prev=q;
    q->next->prev=p;
    q->next=p;
    if(q==dt) dt=p;
}
void delD(int x){
    if(!dh)return;
    DNode *p=dh;
    do{if(p->data==x)break;
    p=p->next;
    }while(p!=dh);
    if(p->data!=x)return;
    if(p==dh && dh==dt){delete p;
    dh=dt=NULL;
    return;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    if(p==dh) dh=p->next;
    if(p==dt) dt=p->prev;
    delete p;
}
void showD(){
    if(!dh){cout<<"Empty\n";
    return;
    }
    DNode *p=dh;
    do{cout<<p->data<<" ";
    p=p->next;
    }while(p!=dh);
    cout<<"\n";
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int type,op,x,pos;
        cin>>type>>op;
        if(op==1){cin>>x>>pos;
        if(type==1)addS(x,pos);
        else addD(x,pos);
        }
        else if(op==2){cin>>x;
        if(type==1)delS(x);
        else delD(x);
        }
        else if(op==3){if(type==1)showS();
        else showD();
        }
    }
}
