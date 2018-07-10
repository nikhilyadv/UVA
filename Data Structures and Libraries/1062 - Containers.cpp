#include<bits/stdc++.h>

using namespace std;

string s;
int n , t = 0;
stack<char> tmp;
vector<stack<char>> a;

int check(int index){
    for(int i = 0 ; i < a.size() ; i++)
        if(s[index] <= a[i].top()) {
            a[i].push(s[index]);
            return 0;
        }
    a.push_back(tmp);
    a[a.size() - 1].push(s[index]);
    return 1;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> s){
        if(s == "end")
            break;
        t++;
        n = s.size();
        a.clear();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans += check(i);
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}