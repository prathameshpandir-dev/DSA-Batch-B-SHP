#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> que(n);
    int front=0,rear=-1,count=0;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            if(count==n) cout<<"Overflow\n";
            else{rear=(rear+1)%n;
            que[rear]=x;
            count++;
            cout<<que[front]<<"\n";
            }
        }else if(op==2){
            if(count==0) cout<<"Underflow\n";
            else{front=(front+1)%n;
            count--;
            if(count==0)rear=-1;
            else cout<<que[front]<<"\n";
            }
        }else if(op==3){
            if(count==0) cout<<"Empty\n";
            else cout<<que[front]<<"\n";
        }
    }
}
