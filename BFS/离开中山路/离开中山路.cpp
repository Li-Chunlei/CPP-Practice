
#include <bits/stdc++.h>
using namespace std;

const int N=1010;
typedef pair<int,int> PII;

int n;
int x1,x2,y1_pos,y2;
char g[N][N];
int dist[N][N];
queue<PII> q;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int bfs(int xxx,int yyy){
    memset(dist,-1,sizeof dist);
    q.push({xxx,yyy});
    dist[xxx][yyy]=0;

    while(!q.empty()){
        auto t=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int a=t.first+dx[i];
            int b=t.second+dy[i];

            if(a<1||a>n||b<1||b>n) continue;
            if(g[a][b]!='0') continue;
            if(dist[a][b]>0) continue;

            q.push({a,b});
            dist[a][b]=dist[t.first][t.second]+1;

            if(a==y1_pos&&b==y2) return dist[y1_pos][y2];
        }
    }
    return dist[y1_pos][y2];
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
	scanf("%d%d%d%d",&x1,&x2,&y1_pos,&y2);
    int res=bfs(x1,x2);
	printf("%d",res);
    return 0;
}

