#include <iostream>
using namespace std;

// 声明一个结构体 Book
struct Book {
    string name;
    string author;
    string subject;
    int id;

    // 构造函数
    Book(string name, string author, string subject, int id) :
        name(name), author(author), subject(subject), id(id) {
    }
};

// 打印函数
void printBookInfo(const Book& book) {
    cout << "name: " << book.name << endl;
    cout << "author: " << book.author << endl;
    cout << "subject: " << book.subject << endl;
    cout << "ID: " << book.id << endl;
}

int main() {
    // 使用构造函数初始化 book1 和 book2
    Book book1("C++ Primer", "Bjarne Stroustrup", "Programming", 101);
    Book book2("C++ Primer Plus", "Bjarne Stroustrup", "Programming", 102);

    // 调用打印函数
    printBookInfo(book1);
    printBookInfo(book2);

    return 0;
}
