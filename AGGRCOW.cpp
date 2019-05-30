#include<bits/stdc++.h>
using namespace std;

int isPossible(int arr[] , int s ,int e , int mid , int c){
   int cowscount = 1 ;
  int i=0, j;
  int lastpos = arr[s];
     for( j = 0; j<=e ;j++){
        if(arr[j]-lastpos>=mid){
           lastpos = arr[j];
          cowscount++;
        }
       if(cowscount==c)
         return true;
       
     }

  return false;
   
}

int main() {

  int t ;cin>>t; 
  for(int i0=0;i0<t;i0++){
    int n , c;
    cin>>n>>c;
    int arr[n];
    
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    sort(arr, arr+n);
    
    int left = arr[0];
    int right = arr[n-1];
    int result = -1;
    
    while(left<=right){
      int mid = left + (right - left)/2;
      if(isPossible(arr, 0 , n-1 , mid , c )){
        result = mid ;
        left = mid+1 ;
      }
      else 
        right = mid-1 ;
    }
      cout<<result<<endl;
  }
  
}