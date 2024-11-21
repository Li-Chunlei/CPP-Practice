#include <iostream>
#include <list>

using namespace std;

int main(){

    //基本操作
    //creat a list
    list<int> myList;

    //add elements to the list
    for(int i=0;i<10;i++){
        myList.push_back(i+1);
    }

    //print the first
    cout<<"first:"<<myList.front()<<endl;

    //print the last
    cout<<"last:"<<myList.back()<<endl;

    //print all elements
    for(auto it=myList.begin();it!=myList.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //size
    cout<<"size:"<<myList.size()<<endl;





    //插入和删除特定元素
    auto it = myList.begin();
    advance(it,3);//移动迭代器到第四个元素
    myList.insert(it,11);//在第四个元素前插入11
    myList.erase(it);//删除第四个元素

    it = myList.begin();
    advance(it,2);
    myList.insert(it,8);
    myList.erase(it);

    for(auto it=myList.begin();it!=myList.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;






    //排序
    myList.sort();
    myList.unique();//删除相邻元素
    for(auto it=myList.begin();it!=myList.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;






    //合并
    list<int> myList2={5,8,6,13,1};
    myList2.sort();//确保合并的是两个已排序的链表
    myList.merge(myList2);     
    for(auto it=myList.begin();it!=myList.end();it++){
        cout<<*it<<" ";
    }

   cout<<endl; 






    //反转
    myList.reverse();
    //打印        
    for(auto it=myList.begin();it!=myList.end();it++){          
        cout<<*it<<" ";
    }

    cout<<endl; 







    //交换
    list<int> myList3={1,2,3,4,5};
    myList.swap(myList3);
   
    for(auto it=myList.begin();it!=myList.end();it++){          
        cout<<*it<<" ";
    }


    cout<<endl; 

   




   //删除所有等于特定元素值的元素
    myList.remove(5);
    for(auto it=myList.begin();it!=myList.end();it++){          
        cout<<*it<<" ";
    }

    cout<<endl;    
    

}