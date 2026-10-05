#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int x){data=x;
    left=right=NULL;
    }
};
Node *root=NULL;
Node *insertNode(Node *p,int x){
    if(!p)return new Node(x);
    if(x<p->data)p->left=insertNode(p->left,x);
    else if(x>p->data)p->right=insertNode(p->right,x);
    return p;
}
void inorder(Node *p){if(p){inorder(p->left);
cout<<p->data<<" ";
inorder(p->right);
}}
void preorder(Node *p){if(p){cout<<p->data<<" ";
preorder(p->left);
preorder(p->right);
}}
void postorder(Node *p){if(p){postorder(p->left);
postorder(p->right);
cout<<p->data<<" ";
}}
void levelorder(Node *p){
    if(!p)return;
    queue<Node*> q;
    q.push(p);
    while(!q.empty()){
        Node *x=q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left)q.push(x->left);
        if(x->right)q.push(x->right);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;
    i<n;
    i++){int x;
    cin>>x;
    root=insertNode(root,x);
    }
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    levelorder(root);
    cout<<"\n";
}
