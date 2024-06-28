#include "MyQueue_Definitions.cc"

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