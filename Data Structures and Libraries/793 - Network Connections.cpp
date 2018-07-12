#include<bits/stdc++.h>

using namespace std;

int find(int parent[] , int a){
    if(parent[a] != a)
        parent[a] = find(parent , parent[a]);
    return  parent[a];
}

void unionset(int parent[] , int rank[] , int a , int b){
    int x = find(parent , a);
    int y = find(parent , b);
    if(x == y)
        return;
    if(rank[x] > rank[y])
        parent[y] = x;
    else{
        parent[x] = y;
        if(rank[x] == rank[y])
            rank[x]++;
    }
}

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int N;
    cin >> N;
    getchar();
    while(N--){
        string s;
        int a = 0 , b = 0 , n;
        cin >> n;
        int parent[n+1] , rank[n+1];
        for(int i = 1 ; i <= n ; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        getline(cin , s);
        while(getline(cin , s)){
            if(s == "")
                break;
            int x , y ;
            char c;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            if(c == 'c'){
                unionset(parent , rank , x , y);
            }
            else{
                if(find(parent,x) == find(parent,y))
                    a++;
                else
                    b++;
            }
        }
        cout << a << "," << b << endl;
        if(N)
            cout << endl;
    }
    return 0;
}