#include <iostream>
#include <set>

using namespace std;

int main(){

    //creat
    set<int> mySet;

    //insert
    mySet.insert(18);

    //input
    cout<<"first:"<<*(mySet.begin())<<endl;

    //insert
    for(int i=0;i<10;i++){
        mySet.insert(i+2);
    }

    //output
    for(auto it =mySet.begin();it!=mySet.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //find
    if(mySet.find(18)!=mySet.end()){
        cout<<"find 18"<<endl;
        //打印迭代器的位置
        cout<<"position:"<<distance(mySet.begin(),mySet.find(18))<<endl;
    }
    else{
        cout<<"not find 18"<<endl;
    }

    //erase
    mySet.erase(18);

    //size
    cout<<"size:"<<mySet.size()<<endl;

    //now 
    cout<<(mySet.find(18)!=mySet.end())<<endl;
    

    return 0;
}