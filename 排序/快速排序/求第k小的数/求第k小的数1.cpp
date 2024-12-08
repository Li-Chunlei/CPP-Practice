/*
# 【深基9.例4】求第 k 小的数

## 题目描述

输入 $n$（$1 \le n < 5000000$ 且 $n$ 为奇数）个数字 $a_i$（$1 \le a_i < {10}^9$），输出这些数字的第 $k$ 小的数。最小的数是第 $0$ 小。

请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
5 1
4 3 2 1 5
```

### 样例输出 #1

```
2
```
*/

//全部排序，定位到k
#include <bits/stdc++.h>
using namespace std;

int n,k,a[5000005];

void qsort(int a[],int l,int r){
    int i=l, j=r,judge=a[(l+r)/2],tmp;
    do{
        while(a[i]<judge) i++;
        while(a[j]>judge) j--;
        if(i<=j){
            tmp=a[i];a[i]=a[j];a[j]=tmp;
            i++;j--;
        }
    }while(i<=j);
    if(l<j) qsort(a,l,j);
    if(i<r) qsort(a,i,r);
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    printf("%d",a[k]);
    return 0;
}