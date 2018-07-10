#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int tc;
    cin >> tc;
    getchar();
    getchar();
    while(tc--){
        unsigned long long n = 0;
        map<string , unsigned long long> mp;
        map<string , unsigned long long>:: iterator it;
        string s;
        while(getline(cin ,s)){
            if(s.compare("") == 0)
                break;
            mp[s]++;
            n++;
        }
        float res;
        for(it = mp.begin() ; it != mp.end() ; it++){
            cout << (*it).first << " ";
            res = float((*it).second) / float(n) * 100;
            cout << fixed << setprecision(4) << res << endl;
        }
        if(tc)
            cout << endl;
    }
    return 0;
}