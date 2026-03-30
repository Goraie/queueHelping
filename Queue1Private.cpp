#include "Queue1Private.h"

#include <iostream>

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
    double harmonicMean = 0.0;
    if (!getHarmonicMean(harmonicMean)) {
        return 0;
    }

    return countElementsGreaterThan(harmonicMean);
}

void Queue1Private::printRequiredValue() const {
    double harmonicMean = 0.0;
    if (!getHarmonicMean(harmonicMean)) {
        std::cout << "Невозможно вычислить среднее гармоническое (очередь пуста или есть 0)."
                  << std::endl;
        return;
    }

    std::cout << "Среднее гармоническое: " << harmonicMean << std::endl;
    std::cout << "Количество элементов, больших среднего гармонического: "
              << countElementsGreaterThan(harmonicMean) << std::endl;
}
