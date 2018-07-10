#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    map <string , pair<string , int>> dict ;
    map <string , pair<string , int>>::iterator it;
    vector <string>res;
    string s , temp;
    while(cin >> s , s != "#"){
        temp = s;
        transform(temp.begin() , temp.end() , temp.begin() , ::toupper);
        sort(temp.begin() , temp.end());
        dict[temp].first = s;
        dict[temp].second++;
    }
    for(it = dict.begin() ; it != dict.end() ; it++){
            if(it->second.second == 1){
                res.push_back(it->second.first);
            }
    }
    sort(res.begin() , res.end());
    for(int i = 0 ; i != res.size() ; i++){
        cout << res[i] << endl;
    }
    return 0;
}