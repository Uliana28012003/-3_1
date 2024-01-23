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

        // ���������� ����-������ ��� ������ QueueVect
        if (testQueue()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cerr << "����-����� �� ��������!" << endl;
        }

        try {
            // ������ ������������� QueueVect ��� ��������� ����� ������
            QueueVect<int> intQueue;
            intQueue.enqueue(59);
            intQueue.enqueue(20);
            cout << "��������� �� intQueue: " << intQueue.dequeue() << endl;

            QueueVect<double> doubleQueue;
            doubleQueue.enqueue(9.13);
            doubleQueue.enqueue(2.8);
            cout << "��������� �� doubleQueue: " << doubleQueue.dequeue() << endl;

            QueueVect<string> stringQueue;
            stringQueue.enqueue("������������ ������ 3");
            stringQueue.enqueue("Hello");
            cout << "��������� �� stringQueue: " << stringQueue.dequeue() << endl;

        }
        catch (const exception& e) {
            cerr << "����������: " << e.what() << endl;
        }

        return 0;  
    }
}
