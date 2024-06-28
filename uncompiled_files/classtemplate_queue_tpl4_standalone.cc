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

/** \class EmptyQueueException
 * @brief Exception for empty queue.
 * 
 * Exception to be thrown, if an empty queue is dequeued.
 * @param error_message the message to be returned, if error is read via
 * get_error_message
 */
class EmptyQueueException
{
    private:
        std::string error_message;
    public:
        EmptyQueueException(const std::string& error_message)
        : error_message(error_message) {}
        /**
         * @brief Error message method.
         * 
         * Returns error message as string to be printed or logged.
         * @return error_message: std::string
         */
        const std::string& get_error_message() const {return error_message;}
};

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

int main()
{
    MyQueue<std::string> some_queue;
    some_queue.enqueue("hi");
    some_queue.enqueue("there");
    some_queue.enqueue("how");
    some_queue.enqueue("goes");
    some_queue.enqueue("it");

    std::string dequeued_value = some_queue.dequeue();
    std::cout << "\nthe dequeued value is: " << dequeued_value << std::endl;
    std::cout << "\ncheck, if queue is empty: " << some_queue.isEmpty() << std::endl;
    
    std::cout << "\nthe rest of the queue is here:" << std::endl;
    some_queue.printQueue();
    std::cout << "\nand again, to show that the queue is still filled:" << std::endl;
    some_queue.printQueue();

    std::vector<float> init_float_vector = {1.2, 2, 2.8, 1000, 5000.01};
    MyQueue<float> some_other_queue(init_float_vector);
    std::cout << "\nthe queue can be instantiated with a vector as well:" << std::endl;
    some_other_queue.printQueue();
    
    std::cout << "\nprint emptied queue:" << std::endl;
    some_other_queue.dequeue();
    std::cout << "one of the returns of dequeue: " << some_other_queue.dequeue() << std::endl;
    some_other_queue.dequeue();
    some_other_queue.dequeue();
    some_other_queue.dequeue();
    some_other_queue.printQueue();

    // some error catching
    std::cout << "\ndequeue emptied queue:" << std::endl;
    try {some_other_queue.dequeue();}
    catch (EmptyQueueException& error) {std::cerr << error.get_error_message() << std::endl;}
    catch (...)
    {
        std::cerr << "unexpected error!\n" << std::endl;
        exit(1);
    }
    
    return 0;
}
