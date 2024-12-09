//在nxn的国际象棋棋盘上放置n个皇后使得他们互不攻击。
//皇后的攻击范围是同一行、同一列、在同斜线上的其他棋子
//n不超过13，求方案数，并输出前3种方法

#include <bits/stdc++.h>
using namespace std;

const int maxn=100;
int a[maxn],n,ans=0;
int b1[maxn],b2[maxn],b3[maxn];
void dfs(int x){
    if(x>n){
        ans++;
        if(ans<=3){
            for(int i=1;i<=n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(b1[i]==0&&b2[x+i]==0&&b3[x-i+15]==0){//剪枝
            a[x]=i;
            b1[i]=1;b2[x+i]=1;b3[x-i+15]=1;
            dfs(x+1);
            b1[i]=0;b2[x+i]=0;b3[x-i+15]=0;
        }
    }

}

int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d",ans);
    return 0;
}