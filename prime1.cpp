#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieve(int max){
        vector<bool> isPrime (max+1, true);
		isPrime[0]=false;
		isPrime[1]=false;
		for (int i=2 ; i<max+1 ; i++ ) {
			if(isPrime[i]==true) {
				primes.push_back(i);
				for(int j = i*i;j<=max ; j+=i){
					isPrime[j]=false;
				}
			}
		}
}

void segmented_sieve(long int m,long int n) {
		int temp = sqrt(n);
		sieve(temp);
		vector<int> prime2(n-m+2, true);
		if(m==1) prime2[0]=false;
		
		int low = m;
		int hight = n;

		for(int i = 0 ; i<primes.size();i++) {
			int rem = primes[i] - (low%primes[i]) ;
			int loLim = low + rem;
			if(low%primes[i]==0) { loLim = loLim-rem; }
			for(int j = loLim ; j<=n ; j+=primes[i]) {
				 prime2[j-low]=false;
			}
			if(loLim == primes[i])prime2[loLim-low]=true;

		}

		int count=0;
		for (int i=0;i<=n-m; i++){
			if(prime2[i]==true) cout<<low+i<<endl;
		}




}



int main() {
	// your code here
	int t;
	cin>>t ;
	for (int i0=0;i0<t;i0++) {

		long int m,n;
		cin>>m>>n;
		segmented_sieve(m , n);

	}

	return 0;
}
