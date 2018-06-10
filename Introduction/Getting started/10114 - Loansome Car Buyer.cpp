#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int months , dep , x ;
    double downpayment , loan , y;
    while(cin >> months >> downpayment >> loan >> dep , months > 0){
        vector<pair<int , double>> data;
        double worth = loan + downpayment , monthlypay = loan / months , curr;
        int ans = 1 , dip = dep , i = 1;
        while(dip--){
            cin >> x >> y;
            data.push_back(pair<int , double>(x , y));
        }
        worth -= worth * data[0].second;
        while(loan >= worth){
            if(i < dep && data[i].first == ans){
                curr = data[i].second , i++;
            }
            worth -= worth * curr;
            loan -= monthlypay;
            ans++;
        }
        ans > 2 ? cout << ans - 1 << " months\n" : cout << "1 month\n";
    }
    return 0;
}