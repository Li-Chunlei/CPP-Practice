#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //记录最后的结果
    vector<vector<int>> result;
    //记录临时结果
    vector<int> out;

    //uesd用来标记元素是否被使用过！！！
    void backtracking(vector<int>& nums,vector<bool>& used){
        //终止条件
        if(out.size()==nums.size()){
            result.push_back(out);
            return;
        }

        for(int i=0;i<nums.size();i++){
            //判断元素有没有被使用
            //使用过，pass
            //没有使用过，继续下面的步骤
            if(used[i]==true){
                continue;
            }else{
                //标记使用
                used[i]=true;
                out.push_back(nums[i]);
                backtracking(nums,used);
                out.pop_back();
                used[i]=false;
            }
        }
    }

    //使用回调函数
    vector<vector<int>> finalresult(vector<int>& nums){
        //好习惯：先清空
        result.clear();
        out.clear();

        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};

int main(){
    Solution solution;
    int n;
    scanf("%d",&n);
    vector<int> nums;
    for(int i=0;i<n;i++){
        nums.push_back(i+1);
    }

    vector<vector<int>> result=solution.finalresult(nums);
    for(const vector<int>& com:result){
        for(const int com1:com){
            printf("%d ",com1);
        }
        printf("\n");
    }

    return 0;
}
