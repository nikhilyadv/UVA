#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    int u;
    int v;
    int weight;
};

bool compare(Edge a , Edge b){
    return a.weight < b.weight;
}

struct vertices{
    int rank, parent;
};

class UFSD{
    struct vertices *ptr;
public:
    UFSD(int n){
        ptr = new vertices [n];
        for(int i = 0 ; i < n ; i++){
            ptr[i].rank = 0;
            ptr[i].parent = i;
        }
    }
    int find(int x){
        if(x != ptr[x].parent)
            ptr[x].parent = find(ptr[x].parent);
        return ptr[x].parent;
    }
    void unionset(int x , int y){
        int xroot = find(x);
        int yroot = find(y);
        if(ptr[xroot].rank > ptr[yroot].rank){
            ptr[yroot].parent = xroot;
        }
        else if(ptr[xroot].rank < ptr[yroot].rank){
            ptr[xroot].parent = yroot;
        }
        else{
            ptr[xroot].parent = yroot;
            ptr[yroot].rank++;
        }
    }
    ~UFSD(void){
        delete ptr;
    }

};

int main(){
    ll v , e;
    while(cin>>v>>e , v!=0 && e!=0){
    	ll totalsum = 0 , mstsum = 0;
        struct Edge Edges[e];
        for(int i = 0 ; i < e ; i++){
            cin>>Edges[i].u>>Edges[i].v>>Edges[i].weight;
            totalsum +=Edges[i].weight;
        }
        sort(Edges , Edges + e , compare);
        UFSD unionfind(v);
        int n = 0 , i = 0;
            while (n != v - 1) {
                int x = unionfind.find(Edges[i].u);
                int y = unionfind.find(Edges[i].v);
                if (x != y) {
	            mstsum += Edges[i].weight;
                    unionfind.unionset(Edges[i].u, Edges[i].v);
                    n++;
                }
                i++;
            }
            cout<<totalsum - mstsum<<endl;
        }
    return 0;
}
