#include<bits/stdc++.h>

using namespace std;

int main(){
	float h,u,d,f,dayclimb,nclimb,finalclimb,day,success;
	while(1){
		cin>>h;
		if(h==0)
			break;
		cin>>u>>d>>f;
		day=0;
		dayclimb=0;
		finalclimb=0;
		success=0;
		while(1){
			dayclimb=u-u*day*f/100;
			//cout<<dayclimb<<endl;
			if(dayclimb>0)
				finalclimb+=dayclimb;
			if(!(finalclimb>h))
				finalclimb-=d;
			else{
				day++;
				success=1;
				break;
			}
			if(finalclimb<0)
			{
				day++;
				success=0;
				break;
			}
			day++;
		}
		if(success==0)
			cout<<"failure on day "<<day<<endl;
		else
			cout<<"success on day "<<day<<endl;
	}	
	return 0;
}
