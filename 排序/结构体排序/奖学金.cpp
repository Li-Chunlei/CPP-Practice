//给出n(n<=300)名学生的语文数学英语成绩，这些学生的学号一次是1到n。
//对这些学生排序，如果总分相同，则语文成绩高的名次在前
//语文分数相同，学号小的在前面
//输出排名前5的学生的学号和总分

#include <bits/stdc++.h>
using namespace std;

const int MAX=310;
int n;

struct Student{//只写需要比较的部分
    int id;
    int chinese;
    int total;
}a[MAX];

//自定义cmp函数
int cmp(Student a,Student b){
    if(a.total!=b.total) return a.total>b.total; //先比较总分
    if(a.chinese!=b.chinese) return a.chinese>b.chinese;
    return a.id<b.id;
}

int main(){
    int math,english;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[i].chinese,&math,&english);
        a[i].total=a[i].chinese+math+english;
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++){
        printf("%d %d\n",a[i].id,a[i].total);
    }
    return 0;
}