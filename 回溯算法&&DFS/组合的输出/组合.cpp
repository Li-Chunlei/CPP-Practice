/*
从 n 个元素中抽出 r 个元素(不分顺序且 r ≤ n)
例如 n＝5，r＝3，所有组合为：
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //老方法
    //记录最终结果
    vector<vector<int>> result;
    //记录临时结果
    vector<int> outcome;

    //回溯函数
    void backtracking(int n,int r,int index){
        if(outcome.size()==r){
            result.push_back(outcome);
            return;
        }

        for(int i=index;i<=n;i++){//控制横向搜索，保证不重复
            outcome.push_back(i);
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //注意是i+1，不是index+1——写错了，卡bug卡了好久o(╥﹏╥)oo(╥﹏╥)oo(╥﹏╥)o
            backtracking(n,r,i+1);//纵向搜素，注意下一个节点是i+1
            outcome.pop_back();//撤销节点
        }
    }

    //使用回溯函数
    vector<vector<int>> finalresult(int n,int k){
        result.clear();
        outcome.clear();
        backtracking(n,k,1);
        return result;
    }
};

int main(){
    Solution solution;
    int n,r;
    scanf("%d %d",&n,&r);

    vector<vector<int>>result=solution.finalresult(n,r);
    for(const vector<int>& result1:result){
        for(const int result2:result1){
            printf("%3d",result2);
        }
        printf("\n");
    }

    return 0;
}