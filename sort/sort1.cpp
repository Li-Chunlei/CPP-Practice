#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//cmp函数返回的值是bool类型
//定义了从大到小的排序规则
bool cmp(int a,int b){
    return a>b;
}


int main(){
    //vector
    vector<int> v(10);
    for(int i=0;i<10;i++){
        cin>>v[i];
    }
    //没有使用cmp参数，所以按照默认的从小到大排序
    sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


    //array
    int array[10];
    for(int i=0;i<10;i++){
        cin>>array[i];
    }
    //使用cmp函数作为参数，所以是从大到小排序
    sort(array,array+10,cmp);
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return 0;

}

