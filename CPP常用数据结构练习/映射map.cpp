#include <iostream>
#include <map>

using namespace std;

int main(){
    //create a map
    map<string,int> myMap;//定义一个空的map myMap，键是string类型，值是int类型

    //add
    myMap["hello"]=2;//将键设为“hello”，值设为2

    //print
    cout<<myMap["hello"]<<endl;//访问myMap中键为“hello”的值，如果键不存在，则返回0
    cout<<myMap["world"]<<endl;

    myMap["world"]=3;
    myMap[","]=1;

    //print all elements
    for(auto it=myMap.begin();it!=myMap.end();it++){
        //用迭代器遍历，输出map中所有的元素
        //key用it->first获取，value用it->second获取
        cout<<it->first<<" "<<it->second<<endl;

    }

    //size
    cout<<"size:"<<myMap.size()<<endl;

    //访问第一个元素
    cout<<myMap.begin()->first<<" "<<myMap.begin()->second<<endl;

    //访问最后一个元素
    cout<<myMap.rbegin()->first<<" "<<myMap.rbegin()->second<<endl;

    //检查键是否存在
    if(myMap.find("chunlei")!=myMap.end()){
        cout<<"chunlei"<<endl;
    }
    else{
        cout<<"can't find chunlei"<<endl;
    }

    //删除元素
    myMap.erase(",");
    cout<<"size:"<<myMap.size()<<endl;

    //清空
    myMap.clear();
    cout<<"size:"<<myMap.size()<<endl;

    return 0;
}
