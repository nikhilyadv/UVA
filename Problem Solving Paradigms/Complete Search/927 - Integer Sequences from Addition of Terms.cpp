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
        int temp , d , k , n;
        vector<int> v;
        cin >> n;
        for(int i = 0 ; i <= n ; i++){
            cin >> temp;
            v.push_back(temp);
        }
        cin >> d >> k;
        int realindex = 0 , imgindex = 0;
        while(imgindex < k){
            realindex++;
            imgindex += realindex*d;
        }
        long long sum = 0;
        for(int i = 0 ; i < v.size() ; i++){
            sum += v[i] * pow(realindex , i);
        }
        cout << sum << endl;
    }
    return 0;
}