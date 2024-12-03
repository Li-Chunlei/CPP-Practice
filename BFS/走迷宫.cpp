#include <bits/stdc++.h>
using namespace std;

const int N=110;
typedef pair<int,int> PII;

int n,m;
int g[N][N];//存储地图
int dist[N][N];//存储每个店到起点的距离
queue<PII> q;//队列

//方向
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

//bfs
int bfs(int x1,int y1){
    memset(dist,-1,sizeof dist);
    q.push({x1,y1});
    dist[x1][y1]=0;

    while(!q.empty()){
        auto t=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int a=t.first+dx[i];
            int b=t.second+dy[i];

            if(a<1||a>n||b<1||b>m) continue;
            if(g[a][b]!=0) continue;
            if(dist[a][b]>0) continue;//已访问

            q.push({a,b});
            dist[a][b]=dist[t.first][t.second]+1;

            if(a==n&&b==m) return dist[n][m];
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    int res=bfs(1,1);
    printf("%d\n",res);
    return 0;
}
