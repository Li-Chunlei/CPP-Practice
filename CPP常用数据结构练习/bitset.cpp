#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<5> b("1101");//5表示5个二进位
    //初始化方式：
    //bitset<5> b;都为0
    //bitset<5> b(u);u为int类型，如果u=3，则输出b的结果为00011
    //bitset<8> b(s);s为字符串，如“1101”，输出结果是00001101，在前面补0
    //bitset<8> b(s,pos,n);从字符串的s[pos]开始，n位长度


    cout<<b<<endl;
    for(int i=0;i<5;i++){
        cout<<b[i];
    }
    cout<<endl;

    //注意，bieser相当于一个数组，但是他是从二进制的低位到高位分别为b[0]，b[1]...的
    //所以，按照b[i]的方式输出和直接输出是有区别的
    //所以，对于上面第一种打印方式，是正常的二进制顺序
    //对于第二种，是正常二进制顺序的倒序



    //修改位
    b[3]=0;//把下标是3的位置改为0
    cout<<b<<endl;//输出结果是00101

    b.set(4);//把下标是4的位置改为1
    cout<<b<<endl;
    b.reset(0);//把下标是0的位置改为0
    cout<<b<<endl;
    b.reset();//所有位归零
    cout<<b<<endl;
    b.flip();//b的二进制逐位取反
    cout<<b<<endl;



    cout << endl << b.any(); //b中是否存在1的⼆进制位
    cout << endl << b.none(); //b中不存在1吗？
    cout << endl << b.count(); //b中1的⼆进制位的个数
    cout << endl << b.size(); //b中⼆进制位的个数
    cout << endl << b.test(2); //测试下标为2处是否⼆进制位为1


    cout<<endl;
    bitset<8> b1("10101010");
    bitset<8> b2("11110000");

    //位与操作
    bitset<8> b_and=b1&b2;
    cout<<"AND: "<<b_and<<endl;

    //位或操作
    bitset<8> b_or=b1 | b2;
    cout<<"OR:  "<<b_or<<endl;

    //位异或操作
    bitset<8> b_xor=b1^b2;
    cout<<"XOR: "<<b_xor<<endl;

    //位非操作
    bitset<8> b_not=~b1;
    cout<<"NOT: "<<b_not<<endl;



    return 0;

}