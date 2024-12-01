/*
如果一个正整数，其各个数位上的数字均满足要么是 0，要么是 1，则称该数字为 01 数。

例如，1 和 10 都是 01 数。
给定一个整数 n。

请你计算，1∼n 中有多少个 01 数。

输入格式:
一行，一个整数 n。

输出格式:
一个整数，表示 01 数的数量。

【数据范围】
对于60%的数据满足 1≤n≤1000。
对于100%的数据满足 1≤n≤10^8。
*/

//暴力
#include <iostream>
#include <string>
using namespace std;

int istrue(int num){
    string number=to_string(num);
    for(int i=0;i<number.size();i++){
        if(number[i]!='1'&&number[i]!='0'){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    for(int i=1;i<=n;i++){
        if(istrue(i)){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}

