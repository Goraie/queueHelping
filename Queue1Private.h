#ifndef QUEUE1_PRIVATE_H
#define QUEUE1_PRIVATE_H

#include "Queue.h"

class Queue1Private : private Queue {
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
