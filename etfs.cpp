#include<bits/stdc++.h>
using namespace std;
#define MAX 20000001
vector<long long> primes;
vector<long long> isPrime(MAX,true);
void sieve()
{
  isPrime[0] = false;
  isPrime[1] = false;
  for(long long i=2;i*i<MAX;i++)
  {
    if(isPrime[i])
    {
      for(long long j=2;j*i<MAX ;j++)
        isPrime[j*i] = false;
    }
  }
  primes.push_back(2);
  for(int i=3; i<MAX ;i+=2)
  {
    if(isPrime[i])
      primes.push_back(i);
  }

}

void segmentedETF(long long l , long long r ){
  long long phi[r-l+1];
  long long temp[r-l+1];
  for(long long i=0;i<=r-l;i++)
  {phi[i] = i+l; temp[i] = i+l;}

  for(long long i=0;i<primes[i]*primes[i]<=r ;i++){
    if(primes[i]>sqrt(r))
      break;
    int currPrime = primes[i];
    long long base = (l/currPrime)*currPrime;
    if(base<l)
      base += currPrime;

    for(long long j=base ; j<=r ; j+=currPrime){
      phi[j-l] = phi[j-l]/(currPrime)*(currPrime-1);
      while(temp[j-l]%currPrime == 0){
        temp[j-l]/=currPrime;
      }
    }

  }

  for(long long i=0;i<=r-l;i++)
  {
    if(temp[i]>1)
      phi[i] = phi[i]/temp[i]*(temp[i]-1);
  }

  for(long long i=0;i<=r-l;i++)
  {
    cout<<phi[i]<<endl;
  }

}

int main (){
  sieve();
  //cout<<primes[primes.size()-1]<<endl;
  int t = 1;;
  while(t--){
     long long l , r ; cin>>l>>r;

   segmentedETF(l , r);
  }
}
