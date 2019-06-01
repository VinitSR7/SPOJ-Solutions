/**
 *Code Author: Vinit
 *Institution: IIT Dhanbad
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i , n) for(int i=0;i<n ;i++)

int main(){
	while(true){
		int n1;
		scanf("%d",&n1);
		if(n1==0)
			break;
		std::vector<ll> a(n1);
		FOR(i , n1){
			cin>>a[i];
		}
		int n2;
		cin>>n2;
		std::vector<ll> b(n2);
		FOR(i , n2){
			cin>>b[i];
		}
		ll temp1 =0 , temp2 = 0 ; 
		int i=0 , j = 0 ;
		ll res = 0 ;
		while(i<n1 && j<n2){
			if(a[i] == b[j]){
				res+=a[i] + max(temp1 , temp2);
				i++;
				j++;
				temp1 = 0 ; 
				temp2 = 0 ; 
			}else if(a[i]>b[j]){
				temp2+=b[j];
				j++;
			}else{
				temp1+=a[i];
				i++;
			}

		}
		while(i<n1){
			temp1+=a[i++];
		}
		while(j<n2){
			temp2+=b[j++];
		}
		res+=max(temp2 , temp1);
		cout<<res<<endl;
}
}