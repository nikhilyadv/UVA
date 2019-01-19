#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int b, s, t = 0;
    while(cin >> b >> s, b || s){
        vector<int> ba(b), sp(s);
        for(int i = 0 ; i < b ; i++)
            cin >> ba[i];
        for(int i = 0 ; i < s ; i++)
            cin >> sp[i];
        sort(ba.begin(),ba.end());
        sort(sp.begin(),sp.end());
        int res = 0;
        for(int i = b-1 ; i >= 0 ; i--){
            int age = ba[i];
            int min = INT_MAX, index = -1;
            for(int j = 0 ; j < s ; j++) {
                if (sp[j] != -1) {
                    if (abs(age - sp[j]) < min) {
                        min = abs(age - sp[j]);
                        index = j;
                    }
                }
            }
            if(index != -1){
                ba[i] = -1;
                res++;
                sp[index] = -1;
            }
        }
        cout << "Case " << ++t << ": ";
        res = b - res;
        if(res == 0)
            cout << "0\n";
        else
            cout << res << " " << ba[0] << "\n";
    }
    return 0;
}

