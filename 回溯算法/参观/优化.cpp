#include<iostream>
using namespace std;
//用b[i]来剪枝

int n,a[20][20],b[20],cnt;
bool used[20];
void dfs(int step,int sum){
    if(step==n+1){
        cnt=max(cnt,sum);
        return;
    }
    //如果当前累积的 sum 加上 b[step]（表示从 step 开始到最后所有可能的最大熟悉程度总和）仍然比当前的 cnt 小
    //说明即使继续递归，得到的结果也不可能大于当前的 cnt，从而可以提前结束这个递归分支，避免浪费时间。
    if(cnt>sum+b[step]){
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            dfs(step+1,sum+a[step][i]);
            used[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i]=max(b[i],a[i][j]);
        }
    }
    //从后往前填充数组，累加
    for(int i=n;i>=1;i--)
        b[i]+=b[i+1];
    dfs(1,0);
    cout<<cnt;
} 