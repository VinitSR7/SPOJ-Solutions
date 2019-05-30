#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > edges(10000005, vector<int>());
vector<int> res(10000005, 0);
int n, r, m; 
void bfs(int k, int s){
	vector<bool> vis(n+1, false);
	vis[k] = true;
	res[k]++;
	queue<int> q;
	q.push(k);
	q.push(-1);
	int level = 0;
	while(!q.empty() && level<s){
		int p = q.front();
		q.pop();
		if(p == -1){
			level++;
			q.push(-1);
			if(q.front() == -1)
			break;
			else continue;
		}
		for(int u : edges[p]){
				if(!vis[u]){
				vis[u] = true;
				q.push(u);
				res[u]++;
			}
		}
	 
	}
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		cin>>n>>r>>m;
		res.assign(n+1, 0);
		for(int i=0;i<=n;i++)
			edges[i].clear();
			
			
		while(r--){
			int x, y; cin>>x>>y;
			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}
		while(m--){
			int k, s; cin>>k>>s;
			bfs(k-1, s);
		}
		int flag = 1;
		for(int i=0;i<n;i++)
			if(res[i] != 1){
				flag = 0;
				break;
			}
		
		if(flag){
			cout<<"Yes"<<endl;
		}else 
		cout<<"No"<<endl;
	}
	
	return 0;
}