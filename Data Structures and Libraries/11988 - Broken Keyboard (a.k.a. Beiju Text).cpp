#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    string s;
    list<char> ans;
    list<char>::iterator k;
    while(getline(cin , s)){
        ans.clear();
        k = ans.begin();
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '[')
                k = ans.begin();
            else if(s[i] == ']')
                k = ans.end();
            else
                ans.insert(k , s[i]);
        }
        for(k = ans.begin() ; k != ans.end() ; k++)
            cout << *k;
        cout << endl;
    }
    return 0;
}