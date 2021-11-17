#include<bits/stdc++.h>
using namespace std;
vector<int> r, p;
/* 1.Add operations getMin(x), getMax(x), getSize(x) to Disjoint Sets, which return the minimum, maximum and number of elements in the set x.
vector<int> Min, Max, Size; 

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

int getMin(int x){
    x = Find(x);
    return Min[x];
}

int getMax(int x){
    x = Find(x);
    return Max[x];
}

int getSize(int x){
    x = Find(x);
    return Size[x];
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(r[x] > r[y]){
        swap(x, y);
    }
    if(r[x] == r[y]) r[y]++;
    Min[y] = min({getMin(x), getMin(y)});
    Max[y] = max({getMax(x), getMax(y)});
    Size[y] += Size[x];
    Size[x] = 0;
    p[x] = y;
}

int main(){
    int n,m; cin>>n>>m;
    p.resize(n);
    r.resize(n,0);
    Min.resize(n);
    Max.resize(n);
    Size.resize(n,1);
    
    for(int i = 0; i < n; i++){
        p[i] = i;
        Min[i] = i;
        Max[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        if(p[x] != p[y]){
            Union(x, y);
        }
    }

    cout<<"parent is\n";
    for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }
    
    cout<<"\nsize is\n";
    for(int i = 0; i < n; i++){
        cout<<Size[p[i]]<<" ";
    }

    cout<<"\nmin is\n";
    for(int i = 0; i < n; i++){
        cout<<Min[p[i]]<<" ";
    }

    cout<<"\nmax is\n";
    for(int i = 0; i < n; i++){
        cout<<Max[p[i]]<<" ";
    }

    return 0;
}

*/

/* 2 .There is an empty graph. Edges are added one by one. After each addition, find the size of the largest connected component.
int maxSize = 1;
vector<int> Size;

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(r[x] > r[y]){
        swap(x, y);
    }
    if(r[x] == r[y]) r[y]++;
    Size[y] += Size[x];
    maxSize = max({maxSize, Size[y]});
    p[x] = y;
}

int main(){
    int n,m; cin>>n>>m;
    p.resize(n);
    r.resize(n,0);
    Size.resize(n, 1);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        if(p[x] != p[y]){
            Union(x, y);
        }
        cout<<maxSize<<"\n";
    }

    return 0;
}
*/

//  There is an empty graph. There are two types of queries: 1) add an edge 2) find the number of edges in the connected component x.
vector<int> Size;
vector<int> edages;

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(r[x] > r[y]){
        swap(x, y);
    }
    if(r[x] == r[y]) r[y]++;
    Size[y] += Size[x];
    p[x] = y;
}

int main(){
    int n,m; cin>>n>>m;
    p.resize(n);
    r.resize(n,0);
    edages.resize(n,0);
    Size.resize(n, 1);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        if(p[x] != p[y]){
            Union(x, y);
        }else{
            edages[p[x]]++;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
        edages[i] += Size[p[i]]-1;
    }
    cout<<"\n";
    for(auto it : edages) cout<<it<<" ";
    return 0;
}