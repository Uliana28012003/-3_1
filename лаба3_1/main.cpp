#include <iostream>
#include <vector>
#include <chrono>
#include "queue_vect.cpp"  
#include "test.h"          
using namespace std;
using namespace chrono;


class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    setlocale(LC_ALL, "Russian");
    {
        LogDuration input;  

        // Проведение юнит-тестов для класса QueueVect
        if (testQueue()) {
            cout << "Юнит-тесты пройдены успешно!" << endl;
        }
        else {
            cerr << "Юнит-тесты не пройдены!" << endl;
        }

        try {
            // Пример использования QueueVect для различных типов данных
            QueueVect<int> intQueue;
            intQueue.enqueue(59);
            intQueue.enqueue(20);
            cout << "Извлечено из intQueue: " << intQueue.dequeue() << endl;

            QueueVect<double> doubleQueue;
            doubleQueue.enqueue(9.13);
            doubleQueue.enqueue(2.8);
            cout << "Извлечено из doubleQueue: " << doubleQueue.dequeue() << endl;

            QueueVect<string> stringQueue;
            stringQueue.enqueue("Лабораторная работа 3");
            stringQueue.enqueue("Hello");
            cout << "Извлечено из stringQueue: " << stringQueue.dequeue() << endl;

        }
        catch (const exception& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        return 0;  
    }
}
