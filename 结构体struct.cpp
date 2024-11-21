#include <iostream>
using namespace std;

void printbook(struct Books book);

struct Books
{
    string name;
    string author;
    string subject;
    int id;
}book1,book2;

 int main()
{
    //book1
   book1.name="heihei";
   book1.author="lichunlei";
   book1.subject="sha";
   book1.id=1;

   //book2
   book2.name="haha";
   book2.author="lichunlei";
   book2.subject="ben";
   book2.id=2;

   printbook(book1);
   printbook(book2);
   
   return 0;
}

void printbook(struct Books book)
{
   cout << "title : " << book.name <<endl;
   cout << "author : " << book.author <<endl;
   cout << "subject : " << book.subject <<endl;
   cout << "id : " << book.id <<endl;
}







//添加了构造函数，并使用了引用作为参数类型，使得函数可以修改结构体的值。
#include <iostream>
using namespace std;

//define a struct
struct Book{
    string name;
    string author;
    string subject;
    int id;


    //构造函数
    //Book(string name,string author,string subject,int id)是构造函数的声明。构造函数的作用是初始化新创建的对象。
    //它接收四个参数：name（书名）、author（作者）、subject（主题）、id（标识符），分别对应于Book结构体中的成员变量。
    

    //:name(name), author(author), subject(subject), id(id)
    //这部分是初始化列表，用于初始化Book结构体的成员变量。
    //name(name) 表示将传入的参数name的值赋给结构体中的成员变量name。
    //同样，author(author)、subject(subject)和id(id)也做了对应的赋值。
    //使用初始化列表的好处是可以在构造对象时直接初始化成员变量，避免了先定义再赋值的过程。


    //构造函数的主体部分是空的，因为所有的初始化都已经在初始化列表中完成了。
    Book(string name,string author,string subject,int id):name(name),author(author),subject(subject),id(id){
    }
};

void printbook(const Book& book)
{
    cout << "title : " << book.name <<endl;
    cout << "author : " << book.author <<endl;
    cout << "subject : " << book.subject <<endl;
    cout << "id : " << book.id <<endl;
}

int main(){
    Book book1("heihei","lichunlei","sha",1);
    Book book2("haha","lichunlei","ben",2);

    printbook(book1);
    printbook(book2);

    return 0;

}