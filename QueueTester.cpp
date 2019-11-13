#include "QueueTester.h"
#include "Queue.h"
#include <iostream>

QueueTester::QueueTester() {

}

QueueTester::~QueueTester() {

}

void QueueTester::run() {
    std::cout<<"\n\nQueueTester is running\n\n";

    int totalTests = 13;
    int passedTests = 0;
    // Empty Queue is Empty
    passedTests += test01();

    // Singleton is non empty
    passedTests += test02();

    // Multi-element is non empty
    passedTests += test03();

    // Dequeue from empty queue throws exception
    passedTests += test04();

    // Dequeue Twice from Singleton throws exception
    passedTests += test05();

    // Dequeue once from singleton is empty
    passedTests += test06();

    // Peeking empty queue throws error
    passedTests += test07();

    // Value in singleton is correct
    passedTests += test08();

    // Value after removing then adding to singleton
    passedTests += test09();

    // Checking proper ordering right after insert
    passedTests += test10();

    // Proper ordering on size 2 when removing then inserting
    passedTests += test11();

    // Peek is const
    passedTests += test12();

    // isEmpty is const
    passedTests += test13();

    std::cout<<"\n\n\n............................\n";
    std::cout<<"Passed: "<<passedTests<<" tests out of "<<totalTests<<". ("<< ((float)passedTests * 100) / ((float)totalTests)<<"% Passing)\n";

}

Queue QueueTester::buildStackQueue(int numElems) {
    Queue retr;
    for (int i = 0; i < numElems; i++) {
        retr.enqueue(i);
    }
    return retr;
}

Queue* QueueTester::buildHeapQueue(int numElems) {
    Queue* retr = new Queue();
    for (int i = 0; i < numElems; i++) {
        retr->enqueue(i);
    }
    return retr;
}

bool QueueTester::test01() {
    Queue stackQueue;
    if (stackQueue.isEmpty()) {
        std::cout<<"Passed. Empty Queue is empty\n";
        return true;
    } else {
        std::cout<<"Failed. Empty Queue is not empty\n";
        return false;
    }
}

bool QueueTester::test02() {
    Queue stackQueue = buildStackQueue(1);
    if (!stackQueue.isEmpty()) {
        std::cout<<"Passed. Singleton Queue is not empty\n";
        return true;
    } else {
        std::cout<<"Failed. Singleton Queue is empty\n";
        return false;
    }
}

bool QueueTester::test03() {
    Queue stackQueue = buildStackQueue(3);
    if (!stackQueue.isEmpty()) {
        std::cout<<"Passed. Multi-element Queue is not empty\n";
        return true;
    } else {
        std::cout<<"Failed. Multi-element Queue is empty\n";
        return false;
    }
}

bool QueueTester::test04() {
    Queue stackQueue = buildStackQueue(0);
    try
    {
        stackQueue.dequeue();
        std::cout<<"Failed. Dequeueing from an empty queue did not throw an error\n";
        return false;
    }
    catch(const std::runtime_error& e)
    {
        std::cout<<"Passed. Dequeueing from empty queue throws error\n";
        return true;
    }
}

bool QueueTester::test05() {
    Queue stackQueue = buildStackQueue(1);
    try
    {
        stackQueue.dequeue();
        stackQueue.dequeue();
        std::cout<<"Failed. Dequeueing twice from a singleton queue did not throw an error\n";
        return false;
    }
    catch(const std::runtime_error& e)
    {
        std::cout<<"Passed. Dequeueing twice from a singleton queue throws error\n";
        return true;
    }
}

bool QueueTester::test06() {
    Queue stackQueue = buildStackQueue(1);
    stackQueue.dequeue();
    if (stackQueue.isEmpty()) {
        std::cout<<"Passed. Dequeueing once from a singleton queue is empty\n";
        return true;
    }
    std::cout<<"Failed. Dequeueing once from a singleton queue is not empty\n";
    return false;   
}

bool QueueTester::test07() {
    Queue stackQueue = buildStackQueue(0);
    try
    {
        stackQueue.peekFront();
        std::cout<<"Failed. Peeking front on empty queue did not throw an error\n";
        return false;
    }
    catch(const std::runtime_error& e)
    {
        std::cout<<"Passed. Peeking front on empty queue threw an error\n";
        return true;
    }
}

bool QueueTester::test08() {
    Queue stackQueue = buildStackQueue(1);
    if (stackQueue.peekFront() == 0) {
        std::cout<<"Passed. Peeking front on singleton queue gave right value\n";
        return true;
    }
    std::cout<<"Failed. Peeking front on singleton queue gave the wrong value";
    return false;
}

bool QueueTester::test09() {
    Queue stackQueue = buildStackQueue(1);
    stackQueue.dequeue();
    stackQueue.enqueue(5);
    if (stackQueue.peekFront() == 5) {
        std::cout<<"Passed. Peeking front from singleton after removing then adding a new value matched\n";
        return true;
    }
    std::cout<<"Failed. Peeking front after removing then adding value\n";
    return false;
}

bool QueueTester::test10() {
    Queue stackQueue = buildStackQueue(5);
    for (int i = 0; i < 5; i++) {
        if (stackQueue.peekFront() != i) {
            std::cout<<"Failed. Checking correct ordering on queue of size 5 with direct insertion\n";
            return false;
        }
        stackQueue.dequeue();
    }
    std::cout<<"Passed. Queue has correct ordering on size 5 after direct inserting\n";
    return true;
}

bool QueueTester::test11() {
    Queue stackQueue = buildStackQueue(2);
    stackQueue.dequeue();
    stackQueue.enqueue(100);
    if (stackQueue.peekFront() == 1) {
        std::cout<<"Passed. Queue maintains ordering when inserting removing and then inserting\n";
        return true;
    }
    std::cout<<"Failed. Queue does not maintain ordering when inserting removing and then inserting\n";
    return false;
}

bool QueueTester::test12() {
    Queue stackQueue = buildStackQueue(1);
    if (stackQueue.peekFront() == 0) {
        if (stackQueue.peekFront() == 0) {
            std::cout<<"Passed. Peeking queue doesn't affect queue\n";
            return true;
        }
    }
    std::cout<<"Failed. Peeking queue affects the queue values\n";
    return false;
}

bool QueueTester::test13() {
    Queue stackQueue = buildStackQueue(1);
    if (!stackQueue.isEmpty() && stackQueue.peekFront() == 0) {
        if (!stackQueue.isEmpty() && stackQueue.peekFront() == 0) {
            std::cout<<"Passed. Checking isEmpty on queue doesn't affect stored values\n";
            return true;
        }
    }
    std::cout<<"Failed. Checking isEmpty on queue causes stored values to change\n";
    return false;
}