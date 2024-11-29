#include <iostream>
using namespace std;

// 传⼊的是n的副本
int func1(int a) {// 传⼊的是0这个值，并不会改变main函数中n的值
a = 99;
return a;
}

//传入的是n的引用
void func2(int &a) { // 传⼊的是n的引⽤，相当于直接对n进⾏了操作，只不过在func2函数中换了个名字叫a
a = 99;
}


int main() {
int n = 0;

func1(n); //并不会改变n的值，n还是0
cout << "n = " << n << endl;
func2(n);// n由0变成了99
cout << "n = " << n << endl;

return 0;

}