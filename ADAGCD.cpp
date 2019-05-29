#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 10000100
#define MOD 1000000007
long long MER(long long a ,long long b){
	if(b==0){
		return 1;
	}
	if(b%2==0)
		return MER((a*a)%MOD , b/2);
	return (a*MER((a*a)%MOD , b/2))%MOD;
}
vector<int> primes(MAX+1, 1);

void sieve(){
	  for(int i=2;i*i<=MAX;i++){
	  	if(primes[i]==1){
	  		for(int j=i;j<MAX;j+=i){
	  			if(primes[j] == 1)
	  			primes[j] = i;
	  		}
	  	}
	  }
	  for(int i=sqrt(MAX);i<MAX;i++)
	  	if(primes[i] == 1)
	  		primes[i] = i;
}
bool compare(unordered_map<int,int> a , unordered_map<int,int> b){
	return a.size()<b.size();
}
template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	sieve();

	 
	int n ;  cin>>n;
	unordered_map<int,int> t;
	unordered_map<int,int> result;
	for(int i=0;i<n;i++){
		int m;  cin>>m;
		//std::vector<int> a[m];
		for(int j=0;j<m;j++){
			int x; cin>>x;
			int temp = x;
			while(temp>1){
				int lpd = primes[temp];
				int cnt = 0 ; 
				while(temp%lpd == 0 )
				{
					temp/=lpd;
					cnt++;
				}
				 
				t[lpd] += cnt;
			}
			
		}
		if(i==0)
		{
			result = t;
			t.clear();
		}
		else{
			unordered_map<int,int>::iterator it = t.begin();
			while(it!=t.end()){
				int prime = it->first;
				if(result[prime]>0){
					t[prime] = min(result[prime] , t[prime]);
				}else{
					t[prime] = 0 ; 
				}

				it++;
			}
			result = t;
			t.clear();
		}
	}
	//sort(v.begin() , v.end() , compare);

	
	unordered_map<int,int>::iterator itr = result.begin();
	long long ans = 1;
	while(itr!=result.end()){
		int prime = itr->first;
		int power = itr->second;
		ans = (ans*MER(prime, power))%MOD;
		itr++;
	}
	cout<<ans<<endl;
}