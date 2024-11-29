//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回 [-1, -1]。
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> search(vector<int>& nums,int target){
        int leftborder=getleftborder(nums,target);
        int rightborder=getrightborder(nums,target);
        //1 在最左边or最右边
        if(leftborder==-2 || rightborder==-2){
            return {-1,-1};
        }

        //3 在数组里面
        if(rightborder-leftborder>1){
            return {leftborder+1,rightborder-1};
        }

        //2 范围在数组里面但是target不在数组里面
        return {-1,-1};

    }

//right:寻找到第一个比target大的数字
private:
    int getrightborder(vector<int>& nums,int target){
        int left=0;
        int right=nums.size()-1;
        int rightborder=-2;
        while(left<=right){
            int middle=left+((right-left)/2);
            if(nums[middle]>target){
                right=middle-1;
            }else{
                left=middle+1;
                rightborder=left;
            }
        return rightborder;
        }
    }


//left:寻找第一个比target小的数字
private:
    int getleftborder(vector<int>& nums,int target){
        int left=0;
        int right=nums.size()-1;
        int leftborder=-2;
        while(left<=right){
            int middle=left+((right-left)/2);
            if(nums[middle]<target){
                left=middle+1;
            }else{
                right=middle-1;
                leftborder=right;
            }
            return leftborder;
        }
    }


};

int main(){
    Solution solution;
    vector <int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;

    vector<int> result=solution.search(nums,target);

    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;

    return 0;
    
}