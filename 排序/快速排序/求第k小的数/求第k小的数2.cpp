//分治思想
#include <bits/stdc++.h>
using namespace std;

int n,k,a[5000005];
int ans=0;//记录结果

void qsort(int a[],int l,int r){
    int i=l,j=r,judge=a[(l+r)/2],tmp;

    if(l==r){//区间长度是1
    ans=a[l];
    return;
    }

    do{
        while(a[i]<judge) i++;
        while(a[j]>judge) j--;
        if(i<=j){
            tmp=a[i];a[i]=a[j];a[j]=tmp;
            i++;j--;
        }
    }while(i<=j);

    if(k<=j){//说明k在左区间
        qsort(a,l,j);
    }else if(k>=i){//k在右区间
        qsort(a,i,r);
    }else{
        qsort(a,j+1,i-1);//既不在左区间也不在右区间，递归时直接返回即可
    }
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    printf("%d",ans);
    return 0;
}