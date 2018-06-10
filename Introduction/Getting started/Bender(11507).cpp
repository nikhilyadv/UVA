#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string move[2],final[2];
	strcpy(final,"+x");
	while(cin>>n, n){
		for(int i=1;i<n;i++){
			cin>>move;
			if(move[0]=='N'){
				continue;
			}
			else if(strcmp(final,"+x")){
				 strcpy(final,move);
			}
			else if(strcmp(final,"-x")){
				if(move[1]=='x')
					continue;
				else{
					strcpy(final,move);
					if(final[0]=='+')
						final[0]='-';
					else
					  	final[0]='+';
				}
			}
			else if(strcmp(final,"+y")){	
				if(move[1]=='y'){
					move[1]='x';
					strcpy(final,move);
					if(final[0]=='+')
						final[0]='-';
					else
					  	final[0]='+';
				}
				else if(move[1]=='z')
					continue;			
			}
			else if(strcmp(final,"-y")){
				if(move[1]=='y'){
					move[1]='x';
					strcpy(final,move);
				}
				else if(move[1]=='z')
					continue;			
			}
			else if(strcmp(final,"+z")){
				if(move[1]=='y')
					continue;
				else{
					move[1]='x';
					strcpy(final,move);
					if(final[0]=='+')
						final[0]='-';
					else
					  	final[0]='+';
				}
			}
			else if(strcmp(final,"-z")){
				if(move[1]=='y')
					continue;
				else{
					move[1]='x';
					strcpy(final,move);
					
				}
			}
		}
		cout<<final<<endl;
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int len;
	while(cin >> len, len){
		vector <string> a(len-1);
		for(int i=0; i<len-1; i++) cin >> a[i];
		int current = 1;
		for(int i=0; i<len-1; i++){
			if(a[i] == "No");
			else if(abs(current) == 1){
				if(a[i] == "+y") current *= 2;
				if(a[i] == "-y") current *= -2;
				if(a[i] == "+z") current *= 3;
				if(a[i] == "-z") current *= -3;
			}
			else if(abs(current) == 2){
				if(a[i] == "+z");
				if(a[i] == "-z");
				if(a[i] == "+y") current = (current/2)*-1;
				if(a[i] == "-y") current = (current/2)*1;
			}
			else if(abs(current) == 3){
				if(a[i] == "+z") current = (current/3)*-1;
				if(a[i] == "-z") current = (current/3)*1;
				if(a[i] == "+y") ;
				if(a[i] == "-y") ;
			}	
		}
		switch(current){
			case -1: cout << "-x" << endl; break;
			case 1: cout << "+x" << endl; break;
			case -2: cout << "-y" << endl; break;
			case 2: cout << "+y" << endl; break;
			case -3: cout << "-z" << endl; break;
			case 3: cout << "+z" << endl; break;
		}
	}
	return 0;
}
*/