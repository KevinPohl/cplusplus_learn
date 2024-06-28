/** \class EmptyQueueException
 * @brief Exception for empty queue.
 * 
 * Exception to be thrown, if an empty queue is dequeued.
 * @param error_message the message to be returned, if error is read via
 * get_error_message
 */

#include <iostream> 

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