/*#include <iostream>
#include <queue>
using namespace std;

int main(){

    //创建队列
    queue<int> myQueue;

    //入队,添加元素
    for(int i=0;i<=10;i++){
        myQueue.push(i+1);
    }

    //队列大小
    cout<<"size:"<<myQueue.size()<<endl;

    //打印首元素
    cout<<"first:"<<myQueue.front()<<endl;

    //打印尾元素
    cout<<"last:"<<myQueue.back()<<endl;

    //出队
    while(!myQueue.empty()){
        cout<<myQueue.front()<<" ";
        //删掉首元素
        myQueue.pop();
    }

    cout<<endl;
    
    return 0;
}
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    //创建
    queue<int> myQueue;

    //入队
    for(int i=0;i<10;i++){
        myQueue.push(i+1);
    }

    //size
    cout<<"size:"<<myQueue.size()<<endl;

    //first
    cout<<"first:"<<myQueue.front()<<endl;

    //last
    cout<<"last:"<<myQueue.back()<<endl;

    //output
    while(!myQueue.empty()){
    cout<<myQueue.front()<<" ";
    myQueue.pop();
    }

    cout<<endl;

    return 0;

    }