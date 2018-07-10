#include<bits/stdc++.h>

using namespace std;

bool check(vector<queue<int>> b){
    for(int i = 0 ; i < b.size() ; i++)
        if(!b[i].empty())
            return true;
    return false;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int t;
    cin >> t;
    while(t--){
        int n , q , s;
        cin >> n >> s >> q;
        stack<int> a;
        vector<queue<int>> b(n);
        for(int i = 0 ; i < n ; i++){
            int len , temp;
            cin >> len;
            for(int j = 0 ; j < len ; j++) {
                cin >> temp;
                b[i].push(temp);
            }
        }
        int time = 0, curr = 1;
        while(true){
            if(curr == n+1)
                curr = 1;
            //unloading
            while(!a.empty() && (a.top() == curr || b[curr-1].size() < q )){
                while(!a.empty() && a.top() == curr)
                    a.pop() , time++;
                if(!a.empty() && b[curr-1].size() < q) {
                    b[curr - 1].push(a.top());
                    a.pop();
                    time++;
                }
            }
            //loading
            while(a.size() < s && !b[curr-1].empty()){
                a.push(b[curr-1].front());
                b[curr-1].pop();
                time++;
            }
            curr++;
            if(!a.empty() || check(b))
                time += 2;
            else
                break;
        }
        cout << time << endl;
    }
    return 0;
}