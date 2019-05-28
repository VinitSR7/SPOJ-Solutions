#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*  so here , first i am calculating , sum of digits till b 
	and the calculating sum of digits till a-1
    to do so i used a fuction name sumOfDigits  -- Arg are a number and its lengthf
    what i had done is let suppose number is 4345 
    first thought which came in my mind , find all possible number till n and find the summation of digits of each number 
    it will work but TLE 
    so second thought 
    	let say first digit is 0 , then rest of the numbers can range from 000 to 999
        okay i did a recuresive call to fuction sumOfDigits2 which only requires the size of number which is 
        n-1 and find all the sum
        similar case when first digit is 2 , 3 but not 4
        coz if first digit is 4 , the rest of the number will range from 000 to 234
        so i did a recursive call to sumOfDigits to find summation till 234
        and just add 4*(1+345) + smallOutoput2 to the result
        and you are done
*/

ll sumOfDigits2(ll space){
  if(space == 1)
    return 45;
  ll sum = 0;
  long long x = sumOfDigits2(space-1);
  ll y = (ll)pow(10 , space-1);
  
  sum = (45*y) + 10*x ;
  return sum;
}


ll sumOfDigits(ll num , ll size){
  if(size == 1){
    ll sum = (num*(num+1))/2;
    return sum ;
  }
  
  ll firstDigit = num / (ll)pow(10 , size-1);
  long long sum = 0 ;
  ll x = num - firstDigit * (ll)pow(10 ,size-1) ; 
  long long smallOutput = sumOfDigits2( size-1) ;
  
  for(ll i=0;i<firstDigit ;i++){
    
   long long temp = i*(ll)pow(10 ,  size-1) + smallOutput;
    sum+=temp;
    
  } 
  long long smallOutput2 = sumOfDigits(x , size-1);
  sum = sum + ( firstDigit*(1+x) ) + smallOutput2; 
  
 
  return sum;
  
}


ll sizeOfDigits(ll n){
  ll size = 0 ;
  while(n!=0){
    size++;
    n/=10;
  }
  return size;
}

int main()
{
   ll a, b;
    cin>>a>>b;
 while(a!=-1 && b!=-1) {
    ll m = sizeOfDigits(a-1);
    ll n = sizeOfDigits(b);
     
    long long ans1 =0, ans2=0;
   if(a==1 || a==0)
     ans2 = 0;
   else
     ans2 = sumOfDigits(a-1 , m);
   if(b==0 || b==1)
     ans1 = b ; 
   else
   ans1 = sumOfDigits(b, n);

    cout<<ans1-ans2<<endl;
    cin>>a>>b;
  }
  
    return 0;
}
