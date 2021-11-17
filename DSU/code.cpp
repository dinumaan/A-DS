// This File content:
// 1.Union-Find/Disjoint Sets Into
// 2.Simple Array implementation
// 3.Simple Lists implementation
// 4.Efficient implementation with Rank(Height) & Path Compression
// 5.Time complexity analysis of above optimizations
// 6.Adding some more functionaliaty like min,max,size etc..

#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;
vector<ll> parent;
vector<ll> Rank;
vector<ll> Size;
vector<ll> Min;
vector<vector<ll>> adj;

ll Find(ll x){
    // return set contain

// method -1&2
    // return parent[x];

// 4. method -3
    ll root = x;
    while(parent[root] != root){
        root = parent[root];
    }
    while(parent[x] != x){
        ll tmp = parent[x];
        parent[x] = root;
        x = tmp;
    }
    return root;
    // recursive-version
    // if(parent[x] == x) return x;
    // return parent[x] = Find(parent[x]);
}

void Union(ll x, ll y){
    // unite sets contain x and y 
    x = Find(x);
    y = Find(y);

// 2. method -1
    // int n = parent.size();
    // for(int i = 0; i < n;   i++){
    //     if(parent[i] == x){
    //         parent[i] = y;
    //     }
    // }

 // 3. method -2
    // TC in one operation will be linear but total TC will be O(nlogn) 
    // if(adj[x].size() > adj[y].size()){
    //     swap(x,y);
    // }
    // for(auto &it : adj[x]){
    //     parent[it] = y;
    //     adj[y].push_back(it);
    // }
    // adj[x].clear();

// 4. method -3
    if(Rank[x] > Rank[y]){
        swap(x, y);
    }
    parent[x] = y;
    if(Rank[x] == Rank[y]){
        Rank[y]++;
    }

// add functionality
    Size[y]+=Size[x];
    Size[x] = 0;
    Min[y] = min({Min[x], Min[y]});
   
    
}

//__________________________________________________Final code of union and find_____________________________
int Find_final(ll x){
    // return set head contion
    if(parent[x] == x) return x;
    return parent[x] = Find_final(x);
}

void Union_final(ll x, ll y){
    // unite set contain x and y
    x = Find_final(x);
    y = Find_final(y);
    if(Rank[x] > Rank[y]){
        swap(x, y);
    }
    parent[x] = y;
    if(Rank[x] == Rank[y]) Rank[y]++;
}
//_________________________________________________________________________________________________________

int main(){
    ll n,m; cin>>n>>m;
    parent.resize(n, 0);
    Rank.resize(n, 0);
    Size.resize(n, 1);
    Min.resize(n,0);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < n; i++){
        Min[i] = i;
    }
    // adj.resize(n);
    // for(int i = 0; i < n; i++){
    //     adj[i].push_back(i);
    // }
    for(int i = 0; i < m; i++){
        ll x,y; cin>>x>>y;
        ll par_x = Find_final(x);
        ll par_y = Find_final(y);
        if(par_x != par_y){
            Union_final(par_x, par_y);
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout<<i<<" => ";
    //     for(auto it : adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<"parent is \n";
    for(auto it : parent) cout<<it<<"\n";
    cout<<"rank is \n";
    for(auto it : Rank) cout<<it<<"\n";
    // cout<<"size is \n";
    // for(int i = 0; i < n; i++) cout<<Size[parent[i]]<<"\n";
    // cout<<"minimum is \n";
    // for(int i = 0; i < n; i++) cout<<Min[parent[i]]<<"\n";
    return 0;
}