#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        vector<pair<string,pair<unsigned long ,unsigned long>>> v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i].first >> v[i].second.first >> v[i].second.second;
        }
        int q;
        cin >> q;
        while(q--){
            string s;
            int count = 0;
            unsigned long price;
            cin >> price;
            for(int i = 0 ; i < n ; i++){
                if(v[i].second.first <= price && v[i].second.second >= price){
                    count++;
                    s = v[i].first;
                }
                if(count == 2)
                    break;
            }
            if(count == 1)
                cout << s << endl;
            else
                cout << "UNDETERMINED" << endl;
        }
        if(c)
            cout << endl;
    }
    return 0;
}