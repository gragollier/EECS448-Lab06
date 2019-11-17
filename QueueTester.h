#ifndef QUEUE_TESTER_H
#define QUEUE_TESTER_H

#include "Queue.h"

class QueueTester {
public:
    QueueTester();
    ~QueueTester();
    void run();

private:
    Queue buildStackQueue(int numElems);
    Queue* buildHeapQueue(int numElems);
    bool test01();
    bool test02();
    bool test03();
    bool test04();
    bool test05();
    bool test06();
    bool test07();
    bool test08();
    bool test09();
    bool test10();
    bool test11();
    bool test12();
    bool test13();
    bool test14();
    bool test15();
    bool test16();
    bool test17();
    bool test18();
};

#endif