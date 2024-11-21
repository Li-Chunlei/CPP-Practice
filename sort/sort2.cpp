//cmp最好用的是在结构体中
//在这个程序，我们尝试实现这样一种功能：将学生成绩进行从大到小排序。如果成绩相同则按学号从小到大排序

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stu{
    int number;
    int score;

    Stu(int number,int score):number(number),score(score){

    }
};


//定义排序规则
bool cmp(Stu a,Stu b){
    return a.score!=b.score ? a.score>b.score :a.number<b.number;
}

int main(){

    //定义结构体数组
    //这里每一个Stu初始化后是逗号，别问我为什么强调这个蠢问题
    //然后要记得vector写完之后加分号，同样别问我为什么强调这个
    vector<Stu> stu={
        Stu(1,78),
        Stu(2,72),
        Stu(3,78),
        Stu(4,92),
        Stu(5,38),
    };

    sort(stu.begin(),stu.end(),cmp);

     for (auto it=stu.begin();it!=stu.end();it++) {
        cout << "number: " << it->number << ", score: " << it->score << endl;
    }

    return 0;



}