#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int size = 0, i;
        for(i = 0 ; i < n ; i++)
            if(a[i] != 0) {
                size++;
                cout << a[i];
                i++;
                break;
            }
        for(;i < n ; i++)
            if(a[i] != 0)
                cout << " " << a[i] , size++;
        if(size == 0)
            cout << "0\n";
        else
            cout << "\n";
    }
    return 0;
}/*#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        vector<vector<int>> sum(n);
        int max = INT_MIN, iindex = 0, jindex = 0, min = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            sum[i].resize(n);
            for(int j = i ; j < n ; j++){
                for(int k = i ; k <= j ; k++){
                    sum[i][j] += a[k];
                }
                if(sum[i][j] > max and (a[i] != 0 and a[j] != 0)){
                    max = sum[i][j];
                    iindex = i;
                    jindex = j;
                    min = INT_MAX;
                }
                if(sum[i][j] == max and min < jindex - iindex){
                    min = jindex - iindex;
                    max = sum[i][j];
                    iindex = i;
                    jindex = j;
                }
            }
        }
        cout << a[iindex];
        for(int i = iindex+1 ; i <= jindex ; i++)
            if(a[i] != 0)
                cout << " " << a[i];
        cout << "\n";
    }
    return 0;
}
*/