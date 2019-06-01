#include<bits/stdc++.h>
using namespace std;
int arr[109];
int dp[109][109][109];
int n;
int BORW(int inc, int dec, int idx){
	if(idx==n+1){
		return 0;
	}
	if(dp[inc][dec][idx]!=-1){
		return dp[inc][dec][idx];
	}
	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if(inc==0 || arr[idx]>arr[inc])
	{
		op1 = BORW(idx, dec, idx+1);
	}
	if(dec == 0 || arr[idx]<arr[dec])
		op2 = BORW(inc, idx, idx+1);

	op3 = 1+BORW(inc, dec, idx+1);
	int res = min(op1, min(op2, op3));
	dp[inc][dec][idx] = res;
	return res;
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		 
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					dp[i][j][k] = -1;
		 
		cout<<n-BORW(0, 0, 1)<<endl;
	}
}