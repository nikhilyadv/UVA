#include<bits/stdc++.h>

using namespace std;

struct car{
    int t , b;
    car(int x , int y){
        t = x;
        b = y;
    }
};

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int c;
    cin >> c;
    while(c--){
        int n ,t ,m , tmp;
        string temp;
        cin >> n >> t >> m;
        queue<car> left , right;
        for(int i = 0 ; i < m ; i++){
            cin >> tmp >> temp;
            if(temp == "left")
                left.push(car(tmp,i));
            else
                right.push(car(tmp,i));
        }
        int time = 0 , currpos = 0 , ans[20000];
        while(1){
            if(left.empty() && right.empty())
                break;
            int num = 0;
            if(currpos == 0){
                while(num < n && !left.empty() && left.front().t <= time){
                    num++;
                    ans[left.front().b] = time + t;
                    left.pop();
                }
                if(num){
                    time += t;
                    currpos = 1 - currpos;
                    continue;
                }
                if(right.empty() || (!left.empty() && left.front().t <= right.front().t)) {
                    time = left.front().t;
                    while(num < n && !left.empty() && left.front().t <= time){
                        num++;
                        ans[left.front().b] = time + t;
                        left.pop();
                    }
                    time += t;
                }
                else{
                    if(!right.empty() || (!left.empty() && left.front().t > right.front().t))
                        time = max(right.front().t , time) + t;
                    else
                        time += t;
                }
            }
            else{
                while(num < n && !right.empty() && right.front().t <= time){
                    num++;
                    ans[right.front().b] = time + t;
                    right.pop();
                }
                if(num){
                    time += t;
                    currpos = 1 - currpos;
                    continue;
                }
                if(left.empty() || (!right.empty() && right.front().t <= left.front().t)) {
                    time = right.front().t;
                    while(num < n && !right.empty() && right.front().t <= time){
                        num++;
                        ans[right.front().b] = time + t;
                        right.pop();
                    }
                    time += t;
                }
                else{
                    if(!left.empty() || (!right.empty() && right.front().t > left.front().t))
                        time = max(left.front().t , time) + t;
                    else
                        time += t;
                }
            }
            currpos = 1 - currpos;
        }
        for(int i = 0 ; i < m ; i++)
            cout << ans[i] << endl;
        if(c)
            cout << endl;
    }
    return 0;
}