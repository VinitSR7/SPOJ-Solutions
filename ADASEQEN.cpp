#include<bits/stdc++.h>
using namespace std;
int cost[26];
int dp[2009][2009];
int helper(string s1, string s2, int n, int m){
	if(n==0 || m==0){
		return 0;
	}
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s1[0]==s2[0]){
		int op1 = cost[s1[0]-'a'] + helper(s1.substr(1), s2.substr(1), n-1, m-1);
		dp[n][m] = op1;
		return op1;
	}
	int op1 = helper(s1.substr(1), s2, n-1, m);
	int op2 = helper(s1, s2.substr(1), n, m-1);
	dp[n][m] = max(op1, op2);
	return max(op1, op2);
}
int main(){
	int t; t=1;

	while(t--){
		int n, m; cin>>n>>m;
		
		for(int i=0;i<26;i++)
			cin>>cost[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				dp[i][j] = -1;
		string s1, s2;
		cin>>s1>>s2;
		cout<<helper(s1, s2, n, m)<<endl;
	}
}