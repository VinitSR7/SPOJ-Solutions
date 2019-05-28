#include<bits/stdc++.h>
using namespace std;

int cost[21]; //opening cost
int c[21][21]; // cost
int r[21][21]; // rating
int dp[21][21][1001]; 
 
int main(){
	int t; cin>>t;
	while(t--){
		int n, m, k;		
		cin>>n>>m>>k;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				for(int l=0;l<=k;l++)
					dp[i][j][l] = 0;

		for(int i=0;i<n;i++)
			cin>>cost[i];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cin>>r[i][j];
		} 

		for(int i=1;i<=n;i++){

			for(int j=1;j<=m;j++){


					for(int l=0;l<=k;l++)
					{

						dp[i][j][l] = dp[i-1][j][l];

						if(l>=cost[i-1]){

							int money_left = l-cost[i-1];
							if(j!=0){
								dp[i][j][l] = dp[i][j-1][l];
							}
							int x = 0;
				            while (true) {
				              x++;
				              if (money_left >= x * c[i-1][j-1])
				                dp[i][j][money_left] = max(dp[i][j][money_left], 
				                	x * r[i-1][j-1] + dp[i][j-1][money_left-x * c[i-1][j-1]]);
				              else
				                break;
          					}

						}
					}
			}
		}
		
		int res = 0 ;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				for(int l=0;l<=k;l++)
					res = max(res, dp[i][j][l]);
		cout<<res<<endl;
	}
}