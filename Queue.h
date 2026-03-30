#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

class Queue {
private:
    struct Node {
        int data;
        Node* prev;

        Node(int value, Node* previous) : data(value), prev(previous) {}
    };

    Node* tail;
    std::size_t size;

    static void printFromOldest(const Node* node);
    static void copyFromOldest(const Node* node, Queue& destination);

public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    virtual ~Queue();

    void enqueue(int value);
    bool dequeue(int& value);
    bool isEmpty() const;
    std::size_t getSize() const;
    void print() const;
    void clear();

    Queue createCopy() const;
    static Queue merge(const Queue& first, const Queue& second);

    bool getHarmonicMean(double& mean) const;
    int countElementsGreaterThan(double value) const;
};

#endif
