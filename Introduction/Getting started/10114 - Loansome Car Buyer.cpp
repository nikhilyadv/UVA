#include<bits/stdc++.h>

using namespace std;

float getdep(int n, vector<pair<int,float>> a, int month){
    int res = 0;
    for(int i = 0; i < n; i++){
        if(month >= a[i].first)
            res = i;
    }
    return a[res].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int months, drec;
    float downpayment, loan;
    while(cin >> months >> downpayment >> loan >> drec , months >=0){
        vector<pair<int,float>> a(drec);
        for(int i = 0 ; i < drec ; i++)
            cin >> a[i].first >> a[i].second;
        float carcost = downpayment + loan, worth, payment = 0, permonth;
        permonth = loan / months;
        int mon = 1, index = 0;
        if(a[0].first == 0)
            worth = carcost - a[0].second * carcost;
        while(worth < loan - payment){
            float v = getdep(drec,a,mon);
            worth -= v * worth;
            payment += permonth;
            //cout << mon << " " << v  << " " << worth  << " " << loan - payment << endl;
            mon++;
        }
        cout << mon-1;
        if(mon-1 == 1)      cout << " month\n";
        else                cout << " months\n";
    }
    return 0;
}
