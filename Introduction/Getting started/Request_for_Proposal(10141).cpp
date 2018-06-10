#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,p,r,flag,counter=1,answer=0;
	while(cin>>n>>p || n || p){
		int max=INT_MIN;
		/*cin>>n>>p;
		if(n==0 || p==0)
			break;
		*///char req[n][81],temp[81],pro[p][81];
		string req[n],pro[p],temp;
		float comp[p],price[p];
		for(int i=0;i<n;i++)
			cin>>req[i];

		for(int i=0;i<p;i++){
			cin>>pro[i];
			cin>>price[i];
			cin>>r;
			comp[i]=0;
			for(int j=0;j<r;j++){
				cin>>temp;
				flag=0;
				for(int k=0;k<n;k++){
					if(req[k]==temp){
						flag=1;
						break;
					}
				}
				if(flag==1)
					comp[i]++;
			}
			comp[i]/=n;
			if(max<comp[i]){
				answer=i;
			}
			else if(max==comp[i]){
				if(price[i]<price[answer])
					answer=i;
			}
		}
		cout<<"RFP #"<<counter<<endl;
		cout<<pro[answer]<<endl<<endl;
		counter++;
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

class Data{
public:
	string name;
	double price;
	int req;
};

bool pred(Data a, Data b){
	if(a.req < b.req) return true;
	else if(a.req == b.req && a.price > b.price) return true;
	return false;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int n, p;
	int cas = 1;
	while(cin >> n >> p, n||p){
		if(cas != 1) cout << endl;
		vector <string> a(n);
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, a[i]);
		}
		vector <Data> b(p);
		for(int i = 0; i<p; i++){
			getline(cin, b[i].name);
			cin >> b[i].price >> b[i].req;
			string null;
			cin.ignore();
			for(int j=0; j<b[i].req; j++){
				getline(cin, null);
			}
		}
		cout << "RFP #" << cas << endl;
		int index = max_element(b.begin(), b.end(), pred) - b.begin();
		cout << b[index].name << endl;
		cas++;
	}
	return 0;
}
*/