//快速排序：我的理解是重复利用二分法
/*
# 【模板】排序

## 题目描述

将读入的 $N$ 个数从小到大排序后输出。

## 输入格式

第一行为一个正整数 $N$。

第二行包含 $N$ 个空格隔开的正整数 $a_i$，为你需要进行排序的数。

## 输出格式

将给定的 $N$ 个数从小到大输出，数之间空格隔开，行末换行且无空格。

## 样例 #1

### 样例输入 #1

```
5
4 2 4 5 1
```

### 样例输出 #1

```
1 2 4 4 5
```

## 提示

对于 $20\%$ 的数据，有 $1 \leq N \leq 10^3$；

对于 $100\%$ 的数据，有 $1 \leq N \leq 10^5$，$1 \le a_i \le 10^9$。
*/

#include <bits/stdc++.h>
using namespace std;

int N,a[100001];

//快速排序算法
void qsort(int a[],int l,int r){//数组，左边界，右边界
    int i=l,j=r,judge=a[(l+r)/2],tmp;
    do{
        while(a[i]<judge) i++;//从左边寻找比judge大的数
        while(a[j]>judge) j--;//从右边寻找比judge小的数
        if(i<=j){//交换位置
        tmp=a[i];a[i]=a[j];a[j]=tmp;
        i++,j--;//只在交换时发生
    }
}while(i<=j);
    if(l<j) qsort(a,l,j);//递归,注意此时参数直接写a即可，不必再写a[]
    if(i<r) qsort(a,i,r);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,0,N-1);
    for(int i=0;i<N-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[N-1]);
    return 0;
}
