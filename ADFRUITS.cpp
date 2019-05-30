#include<bits/stdc++.h>
using namespace std;

void adfruits(string s1, string s2){
	int m, n; 
	m = s1.length();
	n = s2.length();
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0 || j == 0 )
				dp[i][j] = 0 ; 
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string lcs;
	int i = m, j = n ; 
	while(i>0&&j>0){
		if(s1[i-1] == s2[j-1]){
			lcs = s1[i-1]+lcs;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	//cout<<lcs<<endl;
	i = 0, j = 0 ; 
	int lengthlcs = dp[m][n];
	string scs;
	
	for(int l=0;l<lcs.length();l++){
		char c = lcs[l];
		while(s1[i]!=c){
			scs = scs+s1[i];
			i++;
		}
		while(s2[j]!=c){
			scs = scs+s2[j];
			j++;
		}
		scs = scs+c;
		i++;
		j++;
	}
	while(i<m){
			scs = scs+s1[i];
			i++;
		}
		while(j<n){
			scs = scs+s2[j];
			j++;
		}
	cout<<scs<<endl;

}

int main(){
string s1, s2;
	
	while(cin>>s1>>s2){
		adfruits(s1, s2);
	}
}