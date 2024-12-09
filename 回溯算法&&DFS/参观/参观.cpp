/*
实验小学邀请同学们参观实验小学内的各处美景，已知实验小学内共有n处景点。现在有n位该校的大队长承担导游。每个大队长对各个美景的熟悉程度是不同的，如何将n位大队长分配至n处景点，使得总的熟悉程度最大呢?
要求每个美景处都有一个大队长。

输入格式:
输入文件 visit.in 中有若干行:

第一行只有一个正整数n，表示有n个景点和n个大队长。

第二行至第 n+1 行共n行，每行有n个以空格分隔的正整数。第i+1行的第j个数

k(1≤k≤1000)，表示第i个大队长对景点i的熟悉程度为k。

输出格式:
输出文件 visit.out 只有一行，该行只有一个正整数，表示求得的熟悉程度之和最大值

【数据范围】
对于50%的数据，n<=9

对于100%的数据，n<=17

输入样例:
3
10 6 8
9 2 3
1 7 2
输出样例:
24
*/

/*
回溯的换汤不换药，其实就是找出最大的加和
*/


//二维回溯
//思路：
//横向搜素，标记横向位置
//纵向搜素


#include <iostream>
#include <vector>
using namespace std;

int n;
int m[20][20];
int sum;
class Solution{
public:
    //sum表示加和
    //used标记使用过的位置
    //m是二维数组
    void backtracking(int step,int newsum,vector<bool>& used){
        //结束判断
        if(step==n){
            sum=max(sum,newsum);
            return;
        }

        //横向搜索
        for(int i=0;i<n;i++){
            //检查横向位置有没有被占用
            //即：若第一位局长选择在第一个位置，那么used将第一个位置标记
            //第二个局长只能选在其他位置
            if(used[i]==true){
                continue;
            }else{
                used[i]=true;
                backtracking(step+1,newsum+m[step][i],used);
                used[i]=false;

            }
        }
    }

    //使用回溯函数
    int maxsum(){
        vector<bool> used(n,false);
        backtracking(0,0,used);
        return sum;
    }
};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];  // 读取每个大队长对每个景点的熟悉程度
        }
    }

    Solution solution;
    cout << solution.maxsum() << endl;  // 输出最大熟悉程度之和
    return 0;
}