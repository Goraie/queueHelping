#ifndef QUEUE1_PUBLIC_H
#define QUEUE1_PUBLIC_H

#include "Queue.h"

class Queue1Public : public Queue {
public:
    int findRequiredValue() const;
    void printRequiredValue() const;
};

#endif
