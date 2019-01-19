#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, n, d, t = 0;
    cin >> tc;
    while(tc--){
        cin >> n >> d;
        char ch;
        vector<int> small,big;
        big.push_back(0);
        int temp;
        for(int i = 0 ; i < n ; i++){
            cin >> ch;
            if(ch == 'B'){
                cin >> ch;
                cin >> temp;
                big.push_back(temp);
            }
            else if(ch == 'S'){
                cin >> ch;
                cin >> temp;
                small.push_back(temp);
            }
            else{
                i--;
                continue;
            }
        }
        big.push_back(d);
        int smallindex = 0, max_ = INT_MIN;
        for(int i = 0 ; i < big.size() - 1 ; i++){
            //i and i+1;
            int max__ = INT_MIN;
            int d1 = big[i], d2 = big[i+1];
            vector<int> s;
            while(smallindex < small.size() && small[smallindex] < d2){
                s.push_back(small[smallindex]);
                smallindex++;
            }
            int size = s.size();
            if(size == 0 || size == 1)
                max__ = (d2-d1);
            else{
                s.insert(s.begin(),d1);
                s.push_back(d2);
                for(int j = 0 ; j < s.size() - 2 ; j++)
                    max__ = max(max__,s[j+2]-s[j]);
            }
            max_ = max(max_,max__);
        }
        cout << "Case " << ++t << ": " << max_ << "\n";
    }
    return 0;
}
