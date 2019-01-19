#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int k , f = 1;
    vector<int> l(50);
    while(cin >> k , k){
        if(!f)
            cout << endl;
        f = 0;
        for(int i = 0 ; i < k ; i++)    cin >> l[i];
        for(int a = 0 ; a + 6 <= k ; a++)
            for(int b = a + 1 ; b + 5 <= k ; b++)
                for(int c = b + 1 ; c + 4 <= k ; c++)
                    for(int d = c + 1 ; d + 3 <= k ; d++)
                        for(int e = d + 1 ; e + 2 <= k ; e++)
                            for(int f = e + 1 ; f + 1 <= k ; f++)
                                cout << l[a] << " " << l[b] << " " << l[c] << " " << l[d] << " " << l[e] << " " << l[f] << endl;

    }
    return 0;
}