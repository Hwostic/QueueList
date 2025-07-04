
#include "MyQueue.h"
#include <iostream>
using namespace std;

int main()
{

    setlocale(LC_ALL, "RU");

    MyQueue<int> queue;

    queue.pushBack(5);
    queue.pushBack(4);
    queue.pushBack(2);
    queue.pushBack(20);

    cout << "Размер очереди: " << queue.getSize() << endl;

    cout << "Первый элемент: " << queue.getFront() << "\nПоследний элемент: " << queue.getBack() << endl;

    queue.show();

   queue.popFront();

    cout << "Первый элемент: " << queue.getFront() << endl;
    cout << "Размер очереди: " << queue.getSize() << endl;


}




