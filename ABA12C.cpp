#include <bits/stdc++.h>
using namespace std;

long long apples(pair<int, int > arr[] , int s, int k , int**dp){
	if(s==0){
		if(k==0)
			return 0;
		else
			return INT_MAX;
	}

	if(k==0)
		return 0;
    if(k<0)
        return INT_MAX;
    if(dp[s][k]!=-1)
        return dp[s][k];

	if(arr[0].second == -1)
		return apples(arr+1 , s-1, k , dp);

	long long option1 = arr[0].second+apples(arr , s,k-arr[0].first , dp);
	long long option2 = apples(arr+1 , s-1 , k , dp);
	long long res = min(option1 , option2);
	dp[s][k] = res;
	return res;
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
		int n,k ; cin>>n>>k;
		pair<int,int> arr[k];
		for(int i=0;i<k;i++){
			int x ; cin>>x;
			arr[i] = make_pair(i+1 , x);
		}

		int**dp = new int*[k+1];
		for(int i=0;i<=k;i++){
            dp[i] = new int[k+1];
            for(int j=0;j<=k;j++)
                dp[i][j] = -1;
		}
        int s = k;
		long long res = apples(arr , s,k , dp);
		if(res >= INT_MAX)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
	}
	return 0;
}
