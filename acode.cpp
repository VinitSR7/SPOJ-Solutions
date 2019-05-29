#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

  
int num_codes_i(int * input, int size) {
  long long* output = new long long[size + 1];
  output[0] = 1;
  output[1] = 1;
      
  for (int i = 2; i <= size; i++) {
      output[i] = 0 ;
      if(input[i-1]!=0)
    output[i] = output[i - 1];
      
      if( input[i-2] *10 + input[i - 1] <= 26 && input[i-2]!=0) {
      output[i] = (output[i] + output[i - 2]);
    }
  }
  long long ans = output[size];
  delete [] output;
  return ans;
    
}

long long helper(char str[] ,int size){
  int* arr = new int[size+1];
  int flag=0 ;
  for( int i=0;i<size;i++)
      {
      arr[i] = str[i]-'0' ;
        
      }
  if(flag == 1)
    return 0;
  //vector<long long> output(size+1,-1);
  long long x =  num_codes_i(arr,size);
  //arr.clear() ;
  //output.clear();
  return x;
}

int main() {

  while(1) {
     
    char str[100000]; 
    int i;
    scanf("%s[^\n]", str);
    
    
      if(str[0] == '0')     
        break;

      cout<<helper(str, strlen(str))<<endl;
    
    }
}
