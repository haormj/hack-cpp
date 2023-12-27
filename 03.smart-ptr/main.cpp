#include <iostream>
#include <memory>
#include <cassert>
#include <string>

using namespace std;

int main() {
    unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 == 10);

    unique_ptr<string> ptr2(new string("hello world"));
    assert(*ptr2 == "hello world");
    cout << ptr2->size() << endl;

    unique_ptr<string> ptr3(new string("你好"));

    shared_ptr<string> ptr4(new string("shared"));
    shared_ptr<string> ptr5 = ptr4;

    cout << *ptr5 << endl;
    
}