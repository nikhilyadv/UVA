#include<bits/stdc++.h>

using namespace std;

class mycompare{
public:
    int operator()(const pair<int ,pair<int,int>>& p , const pair<int ,pair<int,int>>& q){
        if(p.first > q.first)
            return 1;
        else if(p.first == q.first)
            return p.second.first > q.second.first;
        return 0;
    }
};

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    priority_queue<pair<int ,pair<int,int>>, vector<pair<int ,pair<int,int>>>, mycompare> pq;
    string s;
    int k;
    pair<int ,pair<int,int>> tmp;
    while(cin >> s){
        if(s == "#")
            break;
        cin >> tmp.second.first >> tmp.second.second;
        tmp.first = tmp.second.second;
        pq.push(tmp);
    }
    cin >> k;
    int count = 0;
    while(count < k){
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        int c = pq.top().first;
        pq.pop();
        cout << a << endl;
        tmp.first = c + b;
        tmp.second.first = a;
        tmp.second.second = b;
        pq.push(tmp);
        count++;
    }
    return 0;
}