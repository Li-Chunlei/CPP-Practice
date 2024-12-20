/*
给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。

最初，有一个人位于左上角(1, 1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。

数据保证(1, 1)处和(n, m)处的数字为0，且一定至少存在一条通路。

输入格式

第一行包含两个整数n和m。

接下来n行，每行包含m个整数（0或1），表示完整的二维数组迷宫。

输出格式

输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围

1≤n,m≤100
*/


#include <bits/stdc++.h>
using namespace std;

const int N=110;
//如果是两个点，可以直接用pair
//当然也可以用结构体，但是pair更方便一些
//如果是更多的点，xyw，就要用stuct了
typedef pair<int,int> PII;

int n,m;
int g[N][N];//存储地图
int dist[N][N];//存储每个点到起点的距离
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
    return dist[n][m];
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

