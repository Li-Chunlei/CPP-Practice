#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> array;//创建一个空的vector
    
    //循环遍历：向vector中添加元素
    for(int i=0;i<10;i++)
    {
        array.push_back(i+1);
    }

    //迭代器遍历：打印vector中的元素
    for(auto it = array.begin();it!=array.end();it++)
    {
        cout<<*it<<" ";
    }

    cout<<"\n";

    //获取vector的大小
    int size=array.size();

    //获取vector的特定元素
    cout<<"first:"<<array[0]<<endl;
    cout<<"last:"<<array.at(size-1);

    cout<<"\n";
    
    //删除vector中的元素
    array.erase(array.begin()+2);

    //遍历新vector
    for(auto it = array.begin();it!=array.end();it++)
    {
        cout<<*it<<" ";
    }

    cout<<"\n";

    //清空vector
    array.clear();

    cout<<"new size:"<<array.size()<<endl;
    return 0;

}