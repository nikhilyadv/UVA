#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    while(cin >> n){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int type , num , res[3] = {1,1,1};
        for(int i = 0 ; i < n ; i++){
            cin >> type >> num;
            if(type == 1){
                if(res[0])
                    s.push(num);
                if(res[1])
                    q.push(num);
                if(res[2])
                    pq.push(num);
            }
            else{
                if(s.empty() || s.top() != num)
                    res[0] = 0;
                else
                    s.pop();
                if(q.empty() || q.front() != num)
                    res[1] = 0;
                else
                    q.pop();
                if(pq.empty() || pq.top() != num)
                    res[2] = 0;
                else
                    pq.pop();
            }
        }
        int ans = 0;
        if(res[0])
            ans = 1;
        if(res[1])
            if(ans)
                ans = 4;
            else
                ans = 2;
        if(res[2])
            if(ans)
                ans = 4;
            else
                ans = 3;
        switch(ans){
            case 0 : cout << "impossible";  break;
            case 1 : cout << "stack" ;      break;
            case 2 : cout << "queue";       break;
            case 3 : cout << "priority queue";  break;
            case 4 : cout << "not sure";    break;
        }
        cout << endl;
    }
    return 0;
}