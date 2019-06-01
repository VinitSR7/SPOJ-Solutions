/**
 *Code Author: Vinit
 *Institution: IIT Dhanbad
**/

#include <bits/stdc++.h>
using namespace std;

long long min_health(int** input ,int si , int sj ,int ei , int ej , int** health){
  
  if(si==ei || sj==ej)
    return INT_MAX;
  
  if(health[si][sj] > 0)
    return health[si][sj];
  long long cost1 = INT_MAX , cost2 = INT_MAX;
  if(si+1!=ei)
  	cost1 = min_health(input, si+1, sj, ei ,ej , health)-input[si+1][sj];
  if(sj+1!=ej)
  	cost2 = min_health(input, si, sj+1, ei ,ej , health)-input[si][sj+1];
  
  long long res = min(cost1, cost2);
    if(res<0)
      res = 1;
  health[si][sj] = res;
  return res;
  
}
long long min_health_i(int** input , int r , int c , int** health){
  health[r][c] = 1;
  for(int i=r-1;i>0;i--){
    if(health[i+1][c]-input[i][c]<=0){
      health[i][c] = 1;
    }
    else {
      health[i][c] = health[i+1][c]-input[i][c];
    }
  }
  for(int i=c-1;i>0;i--){
    if(health[r][i+1]-input[r][i]<=0){
      health[r][i] = 1;
    }
    else {
      health[r][i] = health[r][i+1]-input[r][i];
    }
  }
  
  for(int i=r-1;i>0;i--){
    for(int j=c-1;j>0;j--){
      int m = min(health[i][j+1] , health[i+1][j]);
      if(m-input[i][j]<=0)
        health[i][j] = 1;
      else
        health[i][j] = m-input[i][j];
    }
  }
  return health[1][1];  
  
}

int main()
{
  int t; cin>>t;
  while(t--){
  	int r,c;
    cin>>r>>c;
    int** input = new int*[r+1];
    
    int** health = new int*[r+1];
    
    for(int i = 0; i<=r;i++){
      input[i] = new int[c+1];
      health[i] = new int[c+1];
    }
    
    
    for(int i=1;i<=r;i++)
      for(int j=1;j<=c;j++)
        cin>>input[i][j];
   
    
    cout<<min_health_i(input, r, c, health)<<endl;
    
  }
  
  return 0;
}
