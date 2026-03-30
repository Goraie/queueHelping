#include "Queue.h"

#include <iostream>

Queue::Queue() : tail(nullptr), size(0) {}

Queue::Queue(const Queue& other) : tail(nullptr), size(0) {
    copyFromOldest(other.tail, *this);
}

Queue& Queue::operator=(const Queue& other) {
    if (this == &other) {
        return *this;
    }

    clear();
    copyFromOldest(other.tail, *this);
    return *this;
}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(int value) {
    tail = new Node(value, tail);
    ++size;
}

bool Queue::dequeue(int& value) {
    if (tail == nullptr) {
        return false;
    }

    if (tail->prev == nullptr) {
        value = tail->data;
        delete tail;
        tail = nullptr;
        --size;
        return true;
    }

    Node* current = tail;
    while (current->prev->prev != nullptr) {
        current = current->prev;
    }

    Node* oldest = current->prev;
    value = oldest->data;
    current->prev = nullptr;
    delete oldest;
    --size;
    return true;
}

bool Queue::isEmpty() const {
    return tail == nullptr;
}

std::size_t Queue::getSize() const {
    return size;
}

void Queue::printFromOldest(const Node* node) {
    if (node == nullptr) {
        return;
    }

    printFromOldest(node->prev);
    std::cout << node->data << ' ';
}

void Queue::print() const {
    if (tail == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
        return;
    }

    std::cout << "Очередь (от первого к последнему): ";
    printFromOldest(tail);
    std::cout << std::endl;
}

void Queue::clear() {
    while (tail != nullptr) {
        Node* current = tail;
        tail = tail->prev;
        delete current;
    }
    size = 0;
}

void Queue::copyFromOldest(const Node* node, Queue& destination) {
    if (node == nullptr) {
        return;
    }

    copyFromOldest(node->prev, destination);
    destination.enqueue(node->data);
}

Queue Queue::createCopy() const {
    Queue copy;
    copyFromOldest(tail, copy);
    return copy;
}

Queue Queue::merge(const Queue& first, const Queue& second) {
    Queue result;
    copyFromOldest(first.tail, result);
    copyFromOldest(second.tail, result);
    return result;
}

bool Queue::getHarmonicMean(double& mean) const {
    if (tail == nullptr) {
        return false;
    }

    double reciprocalSum = 0.0;
    int count = 0;

    Node* current = tail;
    while (current != nullptr) {
        if (current->data == 0) {
            return false;
        }

        reciprocalSum += 1.0 / static_cast<double>(current->data);
        ++count;
        current = current->prev;
    }

    if (reciprocalSum == 0.0) {
        return false;
    }

    mean = static_cast<double>(count) / reciprocalSum;
    return true;
}

int Queue::countElementsGreaterThan(double value) const {
    int count = 0;
    Node* current = tail;

    while (current != nullptr) {
        if (static_cast<double>(current->data) > value) {
            ++count;
        }
        current = current->prev;
    }

    return count;
void Queue::visitFromOldest(const Node* node, void (*visitor)(int, void*), void* context) {
    if (node == nullptr) {
        return;
    }

    visitFromOldest(node->prev, visitor, context);
    visitor(node->data, context);
}

void Queue::forEachFromOldest(void (*visitor)(int, void*), void* context) const {
    visitFromOldest(tail, visitor, context);
}
