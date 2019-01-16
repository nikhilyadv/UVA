#include<bits/stdc++.h>

using namespace std;

int findmin(int i[5] , int j[5] , int k , int l) {
    int mini = INT_MAX;
    for (int m = 0; m < 5; m++)
        mini = min(mini, abs(i[m] - k) + abs(j[m] - l));
    return mini;
}

int cal(int a , int b , int c , int d , int e , int grid[5][5]){
    int i[5] , j[5];
    i[0] = a / 5    ,   j[0] = a % 5;
    i[1] = b / 5    ,   j[1] = b % 5;
    i[2] = c / 5    ,   j[2] = c % 5;
    i[3] = d / 5    ,   j[3] = d % 5;
    i[4] = e / 5    ,   j[4] = e % 5;
    int cost = 0;
    for(int k = 0 ; k < 5 ; k++)
        for(int l = 0 ; l < 5 ; l++)
            if(grid[k][l])
                cost += findmin(i,j,k,l)*grid[k][l];
    return cost;
}

bool notin(vector<int> res , int val){
    for(int i = 0 ; i < res.size() ; i++)
        if(res[i] == val)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int t , n , x , y , z , grid[5][5];
    vector<pair<int,pair<int,int>>> p;
    vector<int> res;
    cin >> t;
    while(t--){
        memset(grid , 0 , sizeof(grid));
        p.clear();
        res.clear();
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> x >> y >> z;
            p.push_back(make_pair(z,make_pair(x,y)));
            grid[x][y] = z;
        }
        if(n <= 5){
            int index = 0;
            while(index < p.size()){
                res.push_back(p[index].second.first*5+p[index].second.second);
                index++;
            }
            index = 0;
            while(res.size() < 5){
                if(notin(res , index))
                    res.push_back(index);
                index++;
            }
        }
        else{
            int min1 = INT_MAX , min2 = INT_MAX;
            for(int a = 0 ; a + 5 <= 25 ; a++)
                for(int b = a + 1 ; b + 4 <= 25 ; b++)
                    for(int c = b + 1 ; c + 3 <= 25 ; c++)
                        for(int d = c + 1 ; d + 2 <= 25 ; d++)
                            for(int e = d + 1 ; e + 1 <= 25 ; e++){
                                min2 = cal(a,b,c,d,e,grid);
                                if(min1 > min2){
                                    res.clear();
                                    min1 = min2;
                                    res.push_back(a);
                                    res.push_back(b);
                                    res.push_back(c);
                                    res.push_back(d);
                                    res.push_back(e);
                                }
                            }
        }
        sort(res.begin() , res.end());
        for(int i = 0 ; i < 4 ; i++)
            cout << res[i] << " ";
        cout << res[4] << endl;
    }
    return 0;
}