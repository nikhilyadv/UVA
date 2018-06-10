#include<bits/stdc++.h>

using namespace std;

int main(){
    int s , b;
    cin>>s>>b;
    while(s!=0 && b!=0) {
        vector <bool> fightingsoliders(s);
        vector <int> right(s);
        vector <int> left(s);
        fill(fightingsoliders.begin(), fightingsoliders.end(), true);
        int l , r;
        for(int i = 0 ; i < b; i++){
            cin>>l>>r;
            for(int j = l-1 ; j <= r -1 ; j++) {
                right[j] = r;
                left[j] = l - 2;
                fightingsoliders[j] = false;
            }
            int x = l-1, y = r -1;
            while(y>=0 && fightingsoliders[y] != true) y = left[y];
            while(x<s && fightingsoliders[x] != true) x = right[x];
            if(y<0) cout << "* ";
            else cout << (y+1) << " ";
            if(x>=s) cout << "*\n";
            else cout << (x+1) << "\n";
            int index1 = y, index2 = x;
            x = l-1; y = r-1;
            int temp;
            while(y>=0 && fightingsoliders[y] != true){
                temp = left[y];
                left[y] = index1;
                y = temp;
            }
            while(x<s && fightingsoliders[x] != true){
                temp = right[x];
                right[x] = index2;
                x = temp;
            }
        }
        cout<<"-\n";
        cin>>s>>b;
    }
    return 0;
}
