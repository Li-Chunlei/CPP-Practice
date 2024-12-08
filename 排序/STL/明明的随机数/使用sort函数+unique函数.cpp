#include <bits/stdc++.h>
using namespace std;

int n,a[105],cnt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    //unique(a,a+n):对数组从头到尾去重，要求a数组已经有序
    //返回去重后最后一个元素对应的指针
    //即，用返回结果减去a的指针可以得到去重后元素的个数
    cnt=unique(a,a+n)-a;
    printf("%d\n",cnt);
    for(int i=0;i<cnt-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[cnt-1]);
    return 0;
}