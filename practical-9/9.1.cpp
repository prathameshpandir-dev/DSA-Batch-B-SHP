#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;
    i<m;
    i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    cin>>start;
    vector<int> vis(n,0);
    function<void(int)> dfs=[&](int u){
        vis[u]=1;
        cout<<u<<" ";
        for(int v:g[u]) if(!vis[v]) dfs(v);
    };
    dfs(start);
    cout<<"\n";
    fill(vis.begin(),vis.end(),0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:g[u]) if(!vis[v]){vis[v]=1;
        q.push(v);
        }
    }
    cout<<"\n";
}
