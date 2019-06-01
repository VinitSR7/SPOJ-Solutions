#include<bits/stdc++.h>
using namespace std;
int bitmap[200][200];
int res[200][200];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void multi_source_bfs(std::vector<pair<int, int> >&v, int n, int m){

	for(int i=0;i<v.size();i++){
		queue<pair<int, int> > q;
		res[v[i].first][v[i].second] = 0;
		q.push(v[i]);
		set<pair<int, int> > s;

		s.insert(v[i]);
		while(!q.empty())
		{
			pair<int, int > p = q.front(); q.pop();
			int x = p.first, y = p.second;
			for(int j=0;j<4;j++){
				if( (x+dx[j]>=0 && x+dx[j]<n) && (y+dy[j]>=0 && y+dy[j]<m)&& (s.find({x+dx[j], y+dy[j]}) == s.end())){
					if(res[x+dx[j]][y+dy[j]]>res[x][y]+1){
						res[x+dx[j]][y+dy[j]] = res[x][y] + 1;
						s.insert({x+dx[j], y+dy[j]});
						q.push({x+dx[j], y+dy[j]});
					}
				}
			}

		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 
	int t; cin>>t;
	
	while(t--){
		
		int n, m ; cin>>n>>m;
		 
		vector<pair<int, int> > v;
		for(int i=0;i<n;i++){
			string s; cin>>s;
			for(int j=0;j<m;j++)
				if(s[j] == '0')
					res[i][j] = INT_MAX;
				else {
					v.push_back({i, j}), res[i][j] = 0;
				}
		}
		multi_source_bfs(v, n, m);

	}
}