#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int c;
    cin >> c;
    while(c--){
        int l , m , turns = 0 , tmp;
        string temp;
        cin >> l >> m;
        l *= 100;
        queue<int> left , right;
        for(int i = 0 ; i < m ; i++){
            cin >> tmp >> temp;
            if(temp == "left")
                left.push(tmp);
            else
                right.push(tmp);
        }
        int currpos = 0;
        while(true){
            if(left.empty() && right.empty())
                break;
            int len = 0;
            if(currpos == 0){
                while(!left.empty() && len + left.front() <= l){
                    len += left.front();
                    left.pop();
                }
            }
            else{
                while(!right.empty() && len + right.front() <= l){
                    len += right.front();
                    right.pop();
                }
            }
            turns++;
            currpos = 1 - currpos;
        }
        cout << turns << endl;
    }
    return 0;
}