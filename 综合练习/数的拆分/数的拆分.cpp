//回溯，DFS

#include <iostream>
using namespace std;

class Solution{
public:
    int ans[20];//记录拆分成的值

    
    //k当前加和
    //s接下来可以选择的最小的数字
    //m当前有几个元素
    //n输入的值
    void dfs(int k,int s,int m,int n){
        if(k==n){
            for(int i=0;i<m-1;i++){
                printf("%d+",ans[i]);
            }
            printf("%d\n",ans[m-1]);
        }else if(k<n){
            for(int i=s;i<n;i++){//注意！！从s到n开始选择
                ans[m]=i;
                dfs(k+i,i,m+1,n);
            }
        }
    }

};

int main(void){
    Solution solution;
    int n;
    scanf("%d",&n);
    solution.dfs(0,1,0,n);
    return 0;

}