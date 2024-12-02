#include<bits/stdc++.h>
using namespace std;
struct ll{
	int x,y;
};
int n,a[1010][1010],t[1010][1010],dx[]={0,1},dy[]={1,0};
void bfs(){
	queue<ll>q;
	q.push({0,0});
	memset(t,-1,sizeof(t));
	t[0][0]=0;
	while(!q.empty()){
		ll tmp=q.front();
		q.pop();
		if(t[n-1][n-1]!=-1){
			cout<<t[n-1][n-1]<<endl;
			return;
		}
		for(int i=0;i<2;i++){
			int tx=tmp.x+dx[i],ty=tmp.y+dy[i];
			if(tx>=n||ty>=n)continue;
			if(t[tx][ty]!=-1)continue;
			t[tx][ty]=t[tmp.x][tmp.y]+1;
			q.push({tx,ty});
		}
		for(int i=tmp.y+1;i<n;i++){
			if(a[tmp.x][i]>=a[tmp.x][i-1])break;
			if(t[tmp.x][i]!=-1)continue;
			t[tmp.x][i]=t[tmp.x][tmp.y]+1;
			q.push({tmp.x,i});
		}
		for(int i=tmp.y-1;i>=0;i--){
			if(a[tmp.x][i]<=a[tmp.x][i+1])break;
			if(t[tmp.x][i]!=-1)continue;
			t[tmp.x][i]=t[tmp.x][tmp.y]+1;
			q.push({tmp.x,i});
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	bfs();
	return 0;
}
