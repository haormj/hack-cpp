#include <iostream>

using namespace std;

class test {
    private:
        int* p;
        int size;
    public:
        test():test(2) {
        }
        test(int size) {
            cout << "调用构造函数" << endl;
            this->size = size;
            p = new int[this->size];
            for (auto i = 0; i < size; i++) {
                p[i] = 100 + i;
            }
        }
        ~test() {
            cout << "调用析构函数" << endl;
            delete []p;
        }
        void print() {
            for (auto i = 0; i < size; i++) {
                cout << p[i] << endl;
            }
        }
};


int main() {
    test t1;
    t1.print();

    auto pt2 = new test();
    pt2->print();
    delete pt2;

    return 0;
}

