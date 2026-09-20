#include <iostream>
#include <string>
using namespace std;

//图书类
class Book
{
private:
    string bookName;   //书名
    string author;     //作者
    bool isBorrowed;   //是否被借出 true已借出 false可借阅
public:
    //构造函数
    Book(string bn, string au)
    {
        bookName = bn;
        author = au;
        isBorrowed = false;
    }

    //借书
    bool borrowBook()
    {
        if (isBorrowed)
        {
            cout << "该书已经被借走！\n";
            return false;
        }
        isBorrowed = true;
        cout << "借书成功\n";
        return true;
    }

    //还书
    void returnBook()
    {
        isBorrowed = false;
        cout << "还书成功\n";
    }

    //显示图书信息
    void showInfo()
    {
        cout << "书名：" << bookName << "  作者：" << author;
        if (isBorrowed)
            cout << "  状态：已借出\n";
        else
            cout << "  状态：可借阅\n";
    }
};

//读者类
class Reader
{
private:
    string name;
public:
    Reader(string n)
    {
        name = n;
    }

    //读者执行借书
    void doBorrow(Book& b)
    {
        cout << "\n读者【" << name << "】尝试借书\n";
        b.borrowBook();
    }

    //读者执行还书
    void doReturn(Book& b)
    {
        cout << "\n读者【" << name << "】执行还书\n";
        b.returnBook();
    }
};

int main()
{
    //创建2本图书
    Book b1("C++程序设计", "谭浩强");
    Book b2("计算机组成原理", "唐朔飞");

    //创建读者
    Reader r1("张三");

    b1.showInfo();
    b2.showInfo();

    r1.doBorrow(b1);   //张三借b1
    b1.showInfo();

    r1.doBorrow(b1);   //重复借同一本书，测试

    r1.doReturn(b1);   //还书
    b1.showInfo();

    return 0;
}
