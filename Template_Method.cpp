#include <iostream>

using namespace std;

class lib {
public:
    void run() //固定的调用步骤
    {
        fun1();
        fun2();
        fun3();
        fun4();
        fun5();
    }

private:
    void fun1();
    void fun2();
    void fun5();

    virtual void fun3(); //由子类实现
    virtual void fun4();
};
