//给出N（N<=100）个1-1000的数字，输出去重后剩余数字的个数，以及驱虫后排序后的序列
//从小到大
#include <bits/stdc++.h>
using namespace std;
 int main(){
    int n,a[105],ans[105],tmp=-1,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]!=tmp){
            ans[cnt++]=a[i];
            tmp=a[i];
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt-1;i++){
        printf("%d ",ans[i]);
    }
    printf("%d",ans[cnt-1]);
    return 0;
 }

//sort(a,a+n,cmp)
//cmp是指自定义排序函数，如果是从小到大，可以省略
 //如果是从大到小，需要写一个名字是cmp的自定义函数
 //bool cmp(int a,int b){
 //    return a>b;
 //}