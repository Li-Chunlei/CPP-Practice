#include <iostream>
#include <deque>
using namespace std;

int main(){
    //creat a deque
    deque<int> myDeque;

    //add elements to the deque,在后面添加
    for(int i=0;i<10;i++){
        myDeque.push_back(i+1);
    }
    //add elements to the front of the deque,在前面添加
    for(int i=0;i<10;i++){
        myDeque.push_front(i+1);
    }

    //print the deque
    for(int i=0;i<myDeque.size();i++){
        cout<<myDeque[i]<<" ";
    }
    cout<<endl;

    //remove the first element of the deque
    myDeque.pop_front();

    //remove the last element of the deque
    myDeque.pop_back();

    //print the deque
    for(int i=0;i<myDeque.size();i++){
        cout<<myDeque[i]<<" ";
    }
    cout<<endl;

    return 0;


}