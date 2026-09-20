//Book.h
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book
{
private:
    string bookName;
    string author;
    bool isBorrowed; //false可借，true已借出
public:
    Book(string name, string a);
    void borrowBook();//借书
    void returnBook();//还书
    void showInfo();//输出图书信息
};
#endif
