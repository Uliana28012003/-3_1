#include <vector>
#include <stdexcept>

using namespace std;

// ��������� ������ ������ � ���������� ���� T
template <class T>
class QueueVect {
private:
    vector<T> data;  

public:
    // ����� ��� ���������� �������� � ����� �������
    void enqueue(const T& value) {
        data.push_back(value);
    }

    // ����� ��� ���������� �������� �� ������ �������
    T dequeue() {

        if (empty()) {
            throw out_of_range("Queue is empty");
        }

     // ��������� ������� �� ������ �������, ������� ��� �� ������� � ���������� ����������� ��������
        T frontElement = data.front();
        data.erase(data.begin());
        return frontElement;
    }

    // ����� ��� ��������, ����� �� �������
    bool empty() const {
        return data.empty();
    }
};
