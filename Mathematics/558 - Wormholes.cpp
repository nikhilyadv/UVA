#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

struct node{
    int edgeto , weight;
    struct node * next;
};

struct Adjnode{
    struct node *head;
};

struct Graph{
    int numvertices , numedges;
    struct Adjnode *list;
};

struct Graph * createGraph(int n , int e){
    struct Graph *G;
    G = (struct Graph *)malloc(sizeof(struct Graph));
    G->numedges = e;
    G->numvertices = n;
    G->list = new struct Adjnode [n];
    return G;
}

void addedge(struct Graph *G , int from , int to , int weight){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(node));
    ptr->edgeto = to;
    ptr->weight = weight;
    ptr->next = G->list[from].head;
    G->list[from].head = ptr;
}

void deleteGraph(struct Graph *G){
    delete G;
}

int main(){
    int c;
    cin>>c;
    while(c--){
        int n , e , from , to , weight;
        cin>>n>>e;
        struct Graph * G;
        G = createGraph(n , e);
        for(int i  = 0 ; i < e ; i++){
            cin>>from>>to>>weight;
            addedge(G , from ,to , weight);
        }
        int flag = 0;
        int distance[n];
        memset(distance , INT_MAX , sizeof(distance));
        distance[0] = 0;
        for(int i = 0 ; i <= n-1 ; i++){
            for(int j = 0 ; j < n ; j++) {
                struct node *ptr;
                ptr = G->list[j].head;
                while(ptr!=NULL){
                    int u = j;
                    int v = ptr->edgeto;
                    if(distance[u]!=INT_MAX && distance[u] + ptr->weight < distance[v])
                        distance[v] = distance[u] + ptr->weight;
                    ptr=ptr->next;
                }
            }
        }
        for(int j = 0 ; j < n ; j++) {
            struct node *ptr;
            ptr = G->list[j].head;
            while(ptr!=NULL){
                int u = j;
                int v = ptr->edgeto;
                if(distance[u]!=INT_MAX && distance[u] + ptr->weight < distance[v]) {
                    flag = 1;
                    break;
                }
                ptr=ptr->next;
            }
        }
        if(flag == 1)   cout<<"possible\n";
        else cout<<"not possible\n";

    }
    return 0;
}
