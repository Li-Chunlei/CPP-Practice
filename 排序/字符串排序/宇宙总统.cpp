//共有n(n<=20)个非凡拔尖的人竞选总统，现在票数已经统计完毕，请算出谁能当上总统
//第一行输出候选人的编号，第二行输出选票数量
//ATTENTION!!!票数可能会很大，最大有100位

//由于本题只需要求出最大的那一个数，可以考虑选择/冒泡
//但是数字太大无法存下
//考虑将数字存入数组或者字符串

//存入字符串比较方便
//但是不能直接对字符串进行大小比较，因为字符串比较是比较字典序，第一位小的在前面，如果相同则比较第二位
//所以会有10000<1200<200

//所以需要自己编写比较器
#include <bits/stdc++.h>
using namespace std;

const int MAX=25;
int n;

struct node{
    string x;//票数
    int id;//候选人编号
}s[MAX];

int cmp(node a,node b){
    if(a.x.length()!= b.x.length()) return a.x.length()>b.x.length();
    return a.x>b.x;//如果长度相同，按字典序比较
}


//本题使用scanf和printf不能很好的通过
//但是换成cin和cout就可以通过
//所以有的时候可以考虑用cin和cout
//但是好奇怪啊啊啊啊啊
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> s[i].x;
        s[i].id=i+1;
    }
    sort(s,s+n,cmp);
    cout << s[0].id << endl << s[0].x;
    return 0;
}