#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    while(cin >> n , n){
        int num , cost = 0 , c = 0 , currentsum;
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i = 0 ; i < n ; i++) {
            cin >> num;
            pq.push(num);
        }
        while(pq.size() > 1){
            c = pq.top();
            pq.pop();
            c += pq.top();
            pq.pop();
            cost += c;
            pq.push(c);
        }
        cout << cost << endl;
    }
    return 0;
}