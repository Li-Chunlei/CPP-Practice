#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution{
//首先保存数字与字母之间的映射
//使用private保护数据
private:
    //使用二维数组
    const string num_letter[10]={
        "",//0
        "",//1
        "abc",//2
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };


//接口函数，public
public:
    //记录临时结果
    string s;
    //记录最终结果，要注意results包含多个字符组合，所以是用vector类型
    vector<string> result;

    //先定义回溯函数，其实就是递归函数啦~
    void backtracking(const string& digits,int index){

        //终止条件
        if(index==digits.size()){
            //最终结果
            result.push_back(s);
            return;

        }

        int digit=digits[index]-'0';//这一部非常重要，是把index指向的数字字符串转成了int类型
        string letters=num_letter[digit];//取相应字符串

        for(int i=0;i<letters.size();i++){
            s.push_back(letters[i]);
            backtracking(digits,index+1);
            s.pop_back();

        }
    
    }

    //使用回溯函数，返回最终结果
    vector<string> conbination(const string& digits){
        s.clear();
        result.clear();
        if(digits.size()==0){
            return result;
        }
        backtracking(digits,0);
        return result;

    }

};


int main(){
    Solution solution;
    
    string digits;
    cin >> digits;  // 从标准输入读取数字字符串
    
    vector<string> result = solution.conbination(digits);
    
    // 按行输出每一个字母组合
    for (const string& combination : result) {
        cout << combination << endl;
    }
    
    return 0;

}