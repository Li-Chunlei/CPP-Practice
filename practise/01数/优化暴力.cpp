#include <iostream>
using namespace std;

int count=0;

void dfs(int n,int sum){
    //注意判断条件，>?还是>=?
    if(sum>n){
        return;
    }
    count++;
    //如果sum小于n，乘以10；
    //乘以10+1
    dfs(n,sum*10);
    dfs(n,sum*10+1);
}

int main(){
    int n;
    scanf("%d",&n);
    dfs(n,1);
    printf("%d",count);
}