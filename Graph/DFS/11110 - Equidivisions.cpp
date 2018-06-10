#include<bits/stdc++.h>

using namespace std;
#define maxn 150
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int n;
int a[maxn][maxn];

int floodfill(int r , int c , int val){
    if(r<0 || c<0 || r==n ||c==n)   return 0;
    if(a[r][c] != val)  return 0;
    int ans = 1;
    a[r][c] = -1;
    for(int k = 0 ; k < 4 ; k++)
        ans += floodfill(r + dr[k] , c + dc[k] , val);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n , n){
        string temp;
        cin.ignore();
        int N = n;
        pair<int , int> hi[n];
        memset(a , 0 , sizeof(a));
        int counter = 1 ,  j , k;
        for(int i = 0 ; i < n - 1 ; i++){
            getline(cin,temp);
            stringstream is(temp);
            while(is>>j>>k) {
                j--, k--;
                hi[i].first = j;
                hi[i].second = k;
                a[j][k] = counter;
            }
            counter++;
        }
        int flag = 0 ;
        for(int i = 0 ; i < n ; i++)
            for(int l = 0 ; l < n ; l++){
                if(a[i][l] == 0){
                    if(floodfill(i , l, 0) != n){
                        flag = 1;
                        break;
                    }
                }
            }
        for(int i = 0 ; i < n-1 && flag == 0; i++){
            if(floodfill(hi[i].first , hi[i].second , i+1) != n){
                flag = 1;
                break;
            }
        }
        if(flag == 1)   cout<<"wrong"<<endl;
        else    cout<<"good"<<endl;
//        for(int i = 0 ; i < n ; i++){
//            for(int j = 0 ; j < n ; j++)
//                cout<<a[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<endl;
    }

    return 0;
}
