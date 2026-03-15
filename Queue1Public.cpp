#include "Queue1Public.h"

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

int Queue1Public::findRequiredValue() const {
    CounterContext context{0};
    forEachFromOldest(countPositive, &context);
    return context.positiveCount;
}

void Queue1Public::printRequiredValue() const {
    std::cout << "Требуемое значение (количество положительных элементов): "
              << findRequiredValue() << std::endl;
}
