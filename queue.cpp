#include <iostream>

// This creates a structure called Node that can store any type of data (T) and a pointer to the next node
template <typename T>
struct Node
{
    T data;        // This variable holds the actual data of the node
    Node<T> *next; // This pointer points to the next node in the queue
};

// This creates a class called Queue that can store any type of data (T)
template <typename T>
class Queue
{
private:
    Node<T> *front; // This pointer points to the first node in the queue (or nullptr if empty)
    Node<T> *rear;  // This pointer points to the last node in the queue (or nullptr if empty)

public:
    // This constructor initializes the queue with no elements (front and rear set to nullptr)
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // This function adds a new element (data) to the end of the queue
    void enqueue(const T &data)
    {
        // Create a new node to store the data
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        // If the queue is empty, set both front and rear to the new node
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            // Otherwise, add the new node to the end and update the rear pointer
            rear->next = newNode;
            rear = newNode;
        }

        // Print a message to indicate successful addition
        std::cout << data << " enqueued successfully!\n";
    }
};

int main()
{
    // Create a queue for storing integers
    Queue<int> q;
    q.enqueue(10); // Add 10 to the queue
    q.enqueue(20); // Add 20 to the queue
    q.enqueue(30); // Add 30 to the queue
    q.enqueue(40); // Add 40 to the queue

    // Create a queue for storing strings
    Queue<std::string> l;
    l.enqueue("hello world"); // Add "hello world" to the queue

    return 0;
}
