#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    set<int>p;
    vector<int> score;
    for(int i = 0 ; i <= 20 ; i++)  p.insert(i) , p.insert(i*2) , p.insert(i*3);
    p.insert(50);
    for(auto it = p.begin() ; it != p.end() ; it++)
        score.push_back(*it);
    int points , per , comb , flag;
    bool visited[61][61][61];
    while(cin >> points , points > 0){
        memset(visited , false , sizeof(visited));
        per = comb = flag = 0;
        for(int i = 0 ; i < score.size() ; i++)
            for(int j = 0 ; j < score.size() ; j++)
                for(int k = 0 ; k < score.size() ; k++)
                    if(score[i] + score[j] + score[k] == points){
                        per++;
                        flag = 1;
                        if(!visited[i][j][k]){
                            comb++;
                            visited[i][j][k] = true;
                            visited[i][k][j] = true;
                            visited[j][i][k] = true;
                            visited[j][k][i] = true;
                            visited[k][i][j] = true;
                            visited[k][j][i] = true;
                        }
                    }
        if(flag){
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << points <<" IS "<< comb << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << points <<" IS "<< per << "." << endl;
        }
        else
            cout << "THE SCORE OF " << points << " CANNOT BE MADE WITH THREE DARTS." << endl;
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}