#ifndef QUEUE1_PROTECTED_H
#define QUEUE1_PROTECTED_H

#include "Queue.h"

class Queue1Protected : protected Queue {
public:
    void add(int value);
    bool extract(int& value);
    void printQueue() const;
    bool empty() const;

    Queue createCopyQueue() const;
    Queue mergeWith(const Queue& other) const;

    int findRequiredValue() const;
    void printRequiredValue() const;
};

#endif
