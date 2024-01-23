#include <cassert>
#include "queue_vect.cpp"

bool testQueue() {
    QueueVect<int> intQueue;
    intQueue.enqueue(500);
    intQueue.enqueue(22);
    assert(intQueue.dequeue() == 500);

    QueueVect<double> doubleQueue;
    doubleQueue.enqueue(1.45);
    doubleQueue.enqueue(4.1);
    assert(doubleQueue.dequeue() == 1.45);

    QueueVect<std::string> stringQueue;
    stringQueue.enqueue("Тестирование операций с int");
    stringQueue.enqueue("Тестирование операций со строками");
    assert(stringQueue.dequeue() == "Тестирование операций с int");

    return true;
}