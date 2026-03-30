#include "Queue1Public.h"

#include <iostream>

int Queue1Public::findRequiredValue() const {
    double harmonicMean = 0.0;
    if (!getHarmonicMean(harmonicMean)) {
        return 0;
    }

    return countElementsGreaterThan(harmonicMean);
}

void Queue1Public::printRequiredValue() const {
    double harmonicMean = 0.0;
    if (!getHarmonicMean(harmonicMean)) {
        std::cout << "Невозможно вычислить среднее гармоническое (очередь пуста или есть 0)."
                  << std::endl;
        return;
    }

    std::cout << "Среднее гармоническое: " << harmonicMean << std::endl;
    std::cout << "Количество элементов, больших среднего гармонического: "
              << countElementsGreaterThan(harmonicMean) << std::endl;
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
