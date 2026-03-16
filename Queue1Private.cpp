#include "Queue1Private.h"

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

void Queue1Private::add(int value) {
    enqueue(value);
}

bool Queue1Private::extract(int& value) {
    return dequeue(value);
}

void Queue1Private::printQueue() const {
    print();
}

bool Queue1Private::empty() const {
    return isEmpty();
}

Queue Queue1Private::createCopyQueue() const {
    return createCopy();
}

Queue Queue1Private::mergeWith(const Queue& other) const {
    Queue selfCopy = createCopy();
    return Queue::merge(selfCopy, other);
}

int Queue1Private::findRequiredValue() const {
    CounterContext context{0};
    forEachFromOldest(countPositive, &context);
    return context.positiveCount;
}

void Queue1Private::printRequiredValue() const {
    std::cout << "Требуемое значение (количество положительных элементов): "
              << findRequiredValue() << std::endl;
}
