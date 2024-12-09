//给出一个4x4的格子，每个格子只能填写由1到4的整数，要求每行、每列和四等分更小的正方形部分都刚好由1到4组成
//给出空白的方格，请问一共有多少种合法的填写方法

#include <bits/stdc++.h>
using namespace std;
#define size 5
int a[size*size], n=4*4,ans=0;//数组的大小设置为5*5，这样方便从1开始遍历，不用考虑错位问题
int b1[size][5],b2[size][5],b3[size][5];

void dfs(int x){
    if(x==n){
        ans++;
        return;
    }

    int row=(x-1)/4+1;
    int col=(x-1)%4+1;
    int block=(row-1)/2*2+(col-1)/2+1;
    for(int i=1;i<=4;i++){
        if(b1[row][i]==0&&b2[col][i]==0&&b3[block][i]==0){
            a[x]=i;//记录放置位置
            b1[row][i]=1;b2[col][i]=1;b3[block][i]=1;//占位
            dfs(x+1);//下一层递归
            b1[row][i]=0;b2[col][i]=0;b3[block][i]=0;//取消占位
        }
    }
}
int main(){
    dfs(1);
    printf("%d",ans);
    return 0;
}


