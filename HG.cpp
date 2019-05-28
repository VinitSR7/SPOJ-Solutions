#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 100001
#define MOD 1000000000
long long MER(long long a ,long long b){
	if(b==0){
		return 1;
	}
	if(b%2==0)
		return MER((a*a)%MOD , b/2);
	return (a*MER((a*a)%MOD , b/2))%MOD;
}
vector<int> primes;

void sieve(){
	  vector<bool> isPrime(MAX +1, true);
	  for(long long i=3;i*i<=MAX;i+=2){
	  	if(isPrime[i]){
	  		for(long long j=i*i;j<MAX;j+=i){
	  			isPrime[j] = false;
	  		}
	  	}
	  }
	  primes.push_back(2);
	  for(int i=3;i<MAX;i+=2)
	  	if(isPrime[i])
	  		primes.push_back(i);
}
bool compare(unordered_map<int,int> a , unordered_map<int,int> b){
	return a.size()<b.size();
}
int main(){
	sieve();
	int n = 2;
	vector<unordered_map<int, int> > v(n);
	for(int i=0;i<n;i++){
		int m; cin>>m;
		//std::vector<int> a[m];
		for(int j=0;j<m;j++){
			int x; cin>>x;
			int temp = x;
			for(int k=0;k<primes.size();k++){
				if(temp%primes[k] == 0 ){
					int prime = primes[k];
					int cnt = 0 ; 
					while(temp%prime == 0 ){
						cnt++;
						temp/=prime;
					}
					v[i][prime] += cnt;
					
				}
				if(temp == 1)
					break;
			}
			if(temp>1)
				v[i][temp] += 1;
		}
	}
	//sort(v.begin() , v.end() , compare);
	//cout<<"*"<<endl;
	unordered_map<int,int>::iterator it = v[0].begin();
	unordered_map<int,int> res;
	while(it!=v[0].end()){
		int prime = it->first;
		int flag = 0;
		int cnt = it->second;
		for(int i=1;i<n;i++){
			//cout<<"*"<<endl;
			if(v[i][prime]>0){
				cnt = min(cnt ,v[i][prime]);
			}else{
				flag = 1;
				break;
			}
		}
		//cout<<"*"<<endl;
		if(flag){
			it++;
			continue;
		}

		else{
			res[prime] = cnt;
		}
		it++;

	}
	unordered_map<int,int>::iterator itr = res.begin();
	long long ans = 1;
	int flag = 0;
	while(itr!=res.end()){
		int prime = itr->first;
		int power = itr->second;
		ans = (ans*MER(prime, power));
		if(ans>MOD){
			flag = 1;
		}
		ans%=MOD;
		itr++;
	}
	if(flag == 0 ){
		cout<<ans<<endl;
	}else{
		long long temp = ans;
		int digits = 0;
		while(temp>0){
			temp/=10;
			digits++;
		}
		for(int i=0;i<9-digits;i++)
			cout<<'0';
		cout<<ans<<endl;
	}

}