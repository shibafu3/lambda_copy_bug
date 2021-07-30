// http://yohshiy.blog.fc2.com/blog-entry-303.html
// https://shibafu3.hatenablog.com/entry/2020/05/15/110206
// https://cpprefjp.github.io/lang/cpp17/lambda_capture_of_this_by_value.html

#include <iostream>
#include <functional>

using namespace std;

class Test {
    double a = 3;

    std::function<void(void)> f = [this]() {
        a = 30;
        std::cout << __LINE__ << " this in      f: " << this << std::endl;
        std::cout << __LINE__ << "    a in      f: " << a << std::endl;
        std::cout << __LINE__ << "   &a in      f: " << &a << std::endl;
    };

public:
    Test() {}
    ~Test() { std::cout << __LINE__ << " deleted " << this << std::endl; }
    void RunF() {
        f();
        std::cout << __LINE__ << " this in member: " << this << std::endl;
        std::cout << __LINE__ << "    a in member: " << a << std::endl;
        std::cout << __LINE__ << "   &a in member: " << &a << std::endl;
    }
};


int main() {
    {
        std::cout << "test 1" << std::endl;
        Test t;
        t.RunF();
    }
    std::cout << std::endl;

    {
        std::cout << "test 2" << std::endl;
        Test t;
        t = Test();
        t.RunF();
    }
    std::cout << std::endl;

    {
        std::cout << "test 3" << std::endl;
        Test t0, t1;
        t1 = t0;
        t0.RunF();
        t1.RunF();
    }
    std::cout << std::endl;

    return 0;
}