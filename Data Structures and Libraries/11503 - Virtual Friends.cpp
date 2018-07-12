#include<bits/stdc++.h>

using namespace std;

int find(int parent[] , int a){
    if(parent[a] != a)
        parent[a] = find(parent , parent[a]);
    return  parent[a];
}

void unionset(int parent[] , int rank[] , unsigned long long count[], int a , int b){
    int x = find(parent , a);
    int y = find(parent , b);
    if(x == y)
        return;
    if(rank[x] > rank[y]) {
        parent[y] = x;
        count[x] += count[y];
    }
    else{
        parent[x] = y;
        count[y] += count[x];
        if(rank[x] == rank[y])
            rank[y]++;
    }
}

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int N;
    cin >> N;
    getchar();
    while(N--){
        int f;
        cin >> f;
        int index = 1;
        int parent[100005] , rank[100005];
        unsigned long long count[100005];
        for(int i = 1 ; i < 100005 ; i++){
            parent[i] = i;
            count[i] = 1;
        }
        memset(rank , 0 , sizeof(rank));
        unordered_map<string , int>mp;
        for(int i = 0 ; i < f ; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!mp[s1])
                mp[s1] = index++;
            if (!mp[s2])
                mp[s2] = index++;
            unionset(parent, rank, count, mp[s1], mp[s2]);
            cout << count[find(parent, mp[s1])] << endl;
        }
    }
    return 0;
}