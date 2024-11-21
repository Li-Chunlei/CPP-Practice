#include <iostream>
#include <stack>

using namespace std;

int main(){
    //create a stack
    stack<int> myStack;

    //push
    for(int i=0;i<6;i++){
        myStack.push(i+1);
    }

    //访问栈顶元素
    cout<<myStack.top()<<endl;

    //获取大小
    cout<<myStack.size()<<endl;

    //移除栈顶元素
    myStack.pop();

    //打印所有元素
    while(!myStack.empty()){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }

    return 0;
}