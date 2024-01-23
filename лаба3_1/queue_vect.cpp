#include <vector>
#include <stdexcept>

using namespace std;

// Объявляем шаблон класса с параметром типа T
template <class T>
class QueueVect {
private:
    vector<T> data;  

public:
    // Метод для добавления элемента в конец очереди
    void enqueue(const T& value) {
        data.push_back(value);
    }

    // Метод для извлечения элемента из начала очереди
    T dequeue() {

        if (empty()) {
            throw out_of_range("Queue is empty");
        }

     // Извлекает элемент из начала очереди, удаляет его из вектора и возвращает извлеченное значение
        T frontElement = data.front();
        data.erase(data.begin());
        return frontElement;
    }

    // Метод для проверки, пуста ли очередь
    bool empty() const {
        return data.empty();
    }
};
