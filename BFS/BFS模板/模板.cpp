#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//方向
int dir[4][2]={
    {0,1},//向右移动
    {1,0},//向下移动
    {0,-1},//向左移动
    {-1,0}//向上移动

};

//map表示地图，一个二维数组
//visited用来标记访问过的节点，不要重复访问
//x,y表示开始搜索节点的下标

void bfs(vector<vector<char>>& map,vector<vector<bool>>& visited,int x,int y){
    queue<pair<int,int>> que;//定义队列，其中pair用来表示一堆数值
    que.push({x,y});//起始节点加入队列
    visited[x][y]=true;//只要加入队列，立刻标记为访问过的节点
    while(!que.empty()){//开始遍历队列里的元素
        pair<int,int> cur=que.front();
        que.pop();//从队列中取元素
        int curx=cur.first;
        int cury=cur.second;//当前节点坐标
        for(int i=0;i<4;i++){//从当前节点的四个方向上下左右去遍历
            int nextx=curx+dir[i][0];//控制上下
            int nexty=curx+dir[i][1];
            if(nextx<0||nextx>=map.size()||nexty<0||nexty>=map[0].size()){
                continue;
            }
            if(!visited[nextx][nexty]){//如果节点没有被访问过
                que.push({nextx,nexty});//队列添加该节点为一轮要遍历的节点
                visited[nextx][nexty]=true;//只要加入队列就标记
            }

        }
    }
}