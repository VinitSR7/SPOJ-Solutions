#include<bits/stdc++.h>
using namespace std;
int arr[51][51];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int n, m; 
std::vector<std::vector<bool> > vis(51, std::vector<bool>(51));
int dfs(int x, int y){
	vis[x][y] = true;
	int len=0;
	for(int i=0;i<8;i++){
		int xx=x+dx[i], yy=y+dy[i];
		if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy] && arr[xx][yy]-arr[x][y] == 1){
			int temp=dfs(xx, yy);
			if(temp>len)
				len=temp;
		}	
	}
	return len+1;
}

int main(){
	 cin>>n>>m;
	 int t=1;
	while(n!=0){
		for(int i=0;i<n;i++){
			string s; cin>>s;
			for(int j=0;j<m;j++){
				arr[i][j] = int(s[j]);
				
			}
		}
		int result = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j] == int('A')){
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							vis[i][j] = false;
						}
					}

					int temp = dfs(i,j);
					if(temp>result)
						result = temp;
				}
			}
		}
		cout<<"Case "<<t++<<": "<<result<<endl; 
		cin>>n>>m;
	}
}