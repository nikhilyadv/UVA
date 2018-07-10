#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    string s;
    while(cin >> s , s != "#"){
        if(next_permutation(s.begin() , s.end()))   cout << s << endl;
        else    cout << "No Successor" << endl;
    }
    return 0;
}