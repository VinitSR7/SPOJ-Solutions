#include<bits/stdc++.h>
using namespace std; 
long long dp[5009];
long long altseq(int arr[], int n){
	for(int i=0;i<n;i++)
		dp[i] = 1;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(arr[i]<0){
				if(arr[j]>0 && abs(arr[i])>arr[j])
					dp[i] = max(dp[i], 1+dp[j]);
			}else{
				if(arr[j]<0 && (arr[i])>abs(arr[j])){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
	}
	long long res = 1;
	for(int i=0;i<n;i++){
		res = max(res, dp[i]);
	}
	return res;
}

int main(){
	int n; cin>>n;
	int arr[n+1];
	for(long long i=0;i<n;i++)
		cin>>arr[i];
	cout<<altseq(arr, n)<<endl;
}