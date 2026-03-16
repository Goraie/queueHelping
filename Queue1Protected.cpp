#include "Queue1Protected.h"

#include <iostream>

namespace {
struct CounterContext {
    int positiveCount;
};

void countPositive(int value, void* rawContext) {
    CounterContext* context = static_cast<CounterContext*>(rawContext);
    if (value > 0) {
        ++context->positiveCount;
    }
}
}

void Queue1Protected::add(int value) {
    enqueue(value);
}

bool Queue1Protected::extract(int& value) {
    return dequeue(value);
}

void Queue1Protected::printQueue() const {
    print();
}

bool Queue1Protected::empty() const {
    return isEmpty();
}

Queue Queue1Protected::createCopyQueue() const {
    return createCopy();
}

Queue Queue1Protected::mergeWith(const Queue& other) const {
    Queue selfCopy = createCopy();
    return Queue::merge(selfCopy, other);
}

int Queue1Protected::findRequiredValue() const {
    CounterContext context{0};
    forEachFromOldest(countPositive, &context);
    return context.positiveCount;
}

void Queue1Protected::printRequiredValue() const {
    std::cout << "Требуемое значение (количество положительных элементов): "
              << findRequiredValue() << std::endl;
}
