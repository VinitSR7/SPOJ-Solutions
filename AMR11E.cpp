/**
 *Code Author: Vinit
 *Institution: IIT Dhanbad
**/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 10001
#define pb push_back
vector<int> factors[MAX];
vector<int> three_factors;

void distinct_primes_calculations(){
	for(int i = 0 ;i<MAX ; i++)
		factors[i].push_back(i);

	for(int i=2;i<MAX ;i++)
	{
		if(factors[i][0]==i){
			for(int j = i+i ;j <MAX ;j+=i){

				while(factors[j][0]%i==0)
				{
                    factors[j].pb(i);
                    factors[j][0]=factors[j][0]/i;
				}

			}
		}
	}

	for(int i= 29;i<=MAX ;i++){
		{
		    factors[i].erase(unique(factors[i].begin(),factors[i].end()),factors[i].end());
		    if(factors[i].size() >= 4)
                three_factors.pb(i);
		}
	}

}

int main() {

	distinct_primes_calculations();

   int t; cin>>t;
   for(int i = 0 ;i<t;i++)
   	{
   		int n ;cin>>n;
   		cout<<three_factors[n-1]<<endl;
   	}



	return 0;
}
