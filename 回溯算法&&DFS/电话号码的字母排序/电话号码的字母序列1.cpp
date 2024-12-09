//输入一个仅包含数字 2-9 的字符串，输出所有它能表示的字母序列。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

//组合问题——用回溯法！！
#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        
        
        map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        string combination;  // 用于存储当前组合
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        // 如果组合完成（即已遍历完所有数字）
        if (index == digits.length()) {
            combinations.push_back(combination);  // 将当前组合加入结果
            return;
        }
        
        // 获取当前数字对应的字母
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        
        // 遍历当前数字的所有字母
        for (const char& letter : letters) {
            combination.push_back(letter);  // 加入当前字母
            backtrack(combinations, phoneMap, digits, index + 1, combination);  // 递归处理下一个数字
            combination.pop_back();  // 回溯，移除当前字母
        }
    }
};

int main() {
    Solution solution;
    
    string digits;
    cin >> digits;  // 从标准输入读取数字字符串
    
    vector<string> result = solution.letterCombinations(digits);
    
    // 按行输出每一个字母组合
    for (const string& combination : result) {
        cout << combination << endl;
    }
    
    return 0;
}


