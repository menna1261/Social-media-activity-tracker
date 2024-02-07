#ifndef QUEUE_H
#define QUEUE_H
#include<LinkedList.h>
template <class T>
class Queue
{
private:
    LinkedList<T> l;

public:
    bool isEmpty() const
    {
        return l->size == 0;
    }

    void enqueue(T value)
    {

        l.append(value);
    }

    void dequeue()
    {
        l.deleteFront();
    }

    void display() const
    {
        l.display();
    }
    void enqueueFront(T val)
    {
        l.insertFirst(val);
    }

    void dequeueEnd()
    {
        l.deleteEnd();
    }
    int q_size()
    {

        return l.return_size();


    }
    void remove_activity(int num)
    {
        l.key_delete(num);
    }



};

#endif // QUEUE_H
