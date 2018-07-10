#include<bits/stdc++.h>

using namespace std;

bitset <1000005> a;
int n , m;

bool check(vector<int> s , vector<int> e ,vector<int> r){
    int start , end , interval;
    for(int i = 0 ; i < n ; i++){
        start = s[i] + 1;
        end = e[i];
        for(int j = start ; j <= end ; j++)
            if(a.test(j))
                return true;
            else
                a.set(j);
    }
    for(int i = n ; i < n + m ; i++){
        start = s[i];
        end = e[i];
        interval = r[i];
        while(start < 1000000){
            for(int j = start + 1 ; j <= end ; j++)
                if(a.test(j))
                    return true;
                else
                    a.set(j);
            start += interval;
            end = min(end+interval , 1000000);
        }
    }
    return false;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n >> m , n || m){
        vector<int> s(n+m) , e(n+m) , r(n+m);
        a.reset();
        for(int i = 0 ; i < n ; i++)
            cin >> s[i] >> e[i];
        for(int i = n ; i < n + m ; i++)
            cin >> s[i] >> e[i] >> r[i];
        if(check(s,e,r))    cout << "CONFLICT" << endl;
        else    cout << "NO CONFLICT" << endl;
    }
    return 0;
}