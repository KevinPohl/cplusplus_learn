#include "MyQueue.h"
#include "EmptyQueueException.h"

/**
 * MyQueue constructor with initialisation by vector.
 * The vector is given to the method by reference and is copied at
 * initialisation and not deleted after use. In a larger environment, the vector
 * has to be cleaned up after init of MyQueue object.
 */
template <typename T>
MyQueue<T>::MyQueue(const std::vector<T> &v)
{
    for (T element : v)
        {
            MyQueue::enqueue(element);
        }
};


/**
 * @brief insert data into queue.
 * insert one unit of the instantiated data type into the back of the queue
 * @param[in] element: one element of before specified datatype, if queue was
 * instantiated with <'MyQueue<int> abc;'>
 */
template <typename T>
void MyQueue<T>::enqueue(const T &element)
{
    data.push_back(element);
}

/**
 * removes first item in a queue
 * - throws an EmptyQueueException, if the queue is empty and
 * - returns a value, if the queue is not empty
 * 
 * example:
```c++
MyQueue<std::string> a_queue;
try {a_queue.dequeue();}
    catch (EmptyQueueException& error) {std::cerr << error.get_error_message() << std::endl;}
```
 * output: `Error: tried to dequeue an empty queue`
```c++
a_queue.enqueue("test");
try {std::cout << a_queue.dequeue() << std::endl;}
    catch (EmptyQueueException& error) {std::cerr << error.get_error_message() << std::endl;}
```
 * output: `test`
 */
template <typename T>
T MyQueue<T>::dequeue()
{
    if (MyQueue<T>::isEmpty())
    {
        throw EmptyQueueException("Error: tried to dequeue an empty queue");
    }
    T value = data.front();
    data.pop_front();
    return value;
}

/**
 * checks, if a queue is empty:
 * - returns true, if the queue is empty and
 * - false, if it isn't
 * 
 * example:
```c++
MyQueue<std::string> a_queue;
std::cout << a_queue.isEmpty() << std::endl;
```
 * output: `1`
```c++
a_queue.enqueue("test");
std::cout << a_queue.isEmpty() << std::endl;
```
 * output: `0`
 */
template <typename T>
bool MyQueue<T>::isEmpty() const
{
    bool empty = data.empty();
    return empty;
}

/**
 * outputs all values of a queue, alternatively outputs a message, if queue is
 * empty
 */
template <typename T>
void MyQueue<T>::printQueue() const
{
    // check if queue is empty, output a message if true, run loop if false
    if (MyQueue<T>::isEmpty()) 
    {
        std::cout << "the queue is empty." << std::endl;
    }
    else
    {
        // range-based for-loop is my personal favorite in this case, but the
        // use of an iterator was requested here specifically
        // for (T element : data) {std::cout << element << std::endl;}

        // iterator based for loop
        for (auto it = data.begin(); it != data.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }
}

