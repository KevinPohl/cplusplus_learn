//------------------------------------------------------------------------------
/** \file classtemplate_queue_tpl4_standalone.cc
 * \brief contains classes EmptyQueueException and MyQueue.
 * EmptyQueueException is a class for a userdefined exception and is used inside
 * `MyQueue<T>::dequeue()`. It is thrown there, if the user tries to dequeue
 * (delete one entry) from an empty queue.
 * Class MyQueue manages the queue-object, a deque is used as data foundation
 * because of the latter use of an iterator in `MyQueue<T>::printQueue()`.
 */
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>

// (trying the prepared docstring recommendation from doxygen and own format to
// be able to use markdown formats more freely, so prepare for some alternating)

/**
 * Class MyQueue manages the queue-object, a deque is used as data foundation
 * because of the latter use of an iterator in `MyQueue<T>::printQueue()`.
 * methods are `enqueue()`, `dequeue()`, `isEmpty()` and `printQueue()`
 */
template <typename T>
class MyQueue
{
    private:
        // std::queue<T> data; // changed to deque because of iterator
        std::deque<T> data;

    public:
        // constructor with and without init vector
        MyQueue(){};
        MyQueue(const std::vector<T> &v);

        // dummy destructor, no customisation needed for deque
        ~MyQueue(){};

        // class methods
        void enqueue(const T &element);
        T dequeue();
        bool isEmpty() const;
        void printQueue() const;
};