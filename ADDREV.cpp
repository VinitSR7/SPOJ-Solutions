#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;

        int len1=str1.length();
        int len2=str2.length();

       if(len1>len2){
        for(int i=len2;i<len1;i++)
            str2[i]='0';
       }
       else if(len2>len1){
        for(int i=len1;i<len2;i++)
            str1[i]='0';
       }

        int len = max(len1,len2);
        int num[len+1],rem = 0;
        for(int i = 0; i<len;i++){
            int x = str1[i]-'0';
            int y = str2[i]-'0';

            int sum = x+y;

            int digit = (sum+rem)%10;
            num[i]=digit;

            rem = (sum+rem)/10;
        }

            num[len]=rem;
            int pos =0;
            for(int i =0;i<=len;i++){
            if(num[i]!=0){
                pos=i;
                break;
                }
            }

        for(int i=pos;i<len;i++)
            cout<<num[i];
        if(rem!=0)
            cout<<num[len];

            cout<<endl;

    }

}
