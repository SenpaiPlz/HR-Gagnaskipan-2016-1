#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

class LinkedListException {
    // Implement this
public:
    LinkedListException(string msg) : message(msg){}
    string getMessage() const {return message;};
private:
    string message;
};

template <class T>
class LinkedList
{
    private:

        class Node{
        public:
            // Constructs a new node
            Node() {};
            // Constructs a new node with a value, next and previous links
            Node(T value, Node *nextLink, Node* prevLink) : data(value), next(nextLink), prev(prevLink) {};

            // Retrieve value for this node
            T getData() const { return data; } ;
            // Retrieve the next node
            Node* getNext() const { return next; };
            // Retrieve previous node
            Node* getPrev() const { return prev; };

            // Modifies the value
            void setValue(T value) { data = value; };
            // Changes the reference to the next node
            void setNext(Node* nextLink) { next = nextLink; };
            // Changes the reference to the previous node
            void setPrev(Node* prevLink) { prev = prevLink; };


        private:
            T data;
            Node* next;
            Node* prev;
        };


        void insert(Node* beforeMe, const T& elem);   // Inserts a new node with elem before node beforeMe
        void removeAll();   // Deletes all nodes, excluding the sentinel nodes
        void init();        // Initializes member variables
        int currSize;       // Current number of list items
        Node* currNode;  // A pointer to the current node of the list
        Node* header;    // A pointer to the header (a sentinel node)
        Node* trailer;   // A pointer to the trailer (a sentinel node)



    public:

        class LinkedListIterator{
        public:
            LinkedListIterator() : node(NULL) {};
            LinkedListIterator(Node* p) : node(p) {};
            bool operator==(const LinkedListIterator& other) {return (node == other.node);}
            bool operator!=(const LinkedListIterator& other) {return (node != other.node);}
            T operator*() {return(node->getData());}
            LinkedListIterator& operator++()
            {
                node = node->getNext();
                return *this;
            }
        private:
            Node* node;
        };

        LinkedList();                   // Constructor
        LinkedList(LinkedList<T>& lis); // Copy constructor;
        ~LinkedList();                  // Destructor

        void next();                // Moves the current node one step right
        void prev();                // Moves the current node one step left
        void moveToStart();         // Moves the current node to the start of the list
        void moveToEnd();           // Moves the current node past the last node of the list
        void moveToPos(int pos);    // Moves the current node to the one at pos
        int length() const;         // Returns the current length of the list
        T value() const throw(LinkedListException); // Returns the element of the current node
        bool empty() const;         // Returns true if the list is empty, else false
        void append (T elem);       // Appends an element at the end of the list
        void insert (const T& elem);// Inserts an element before the current node
        T remove() throw(LinkedListException); // Removes the current node and returns its element
        void clear();               // Clears the contents of the list

        LinkedListIterator begin() {return(LinkedListIterator(header->getNext()));}
        LinkedListIterator end() {return(LinkedListIterator(trailer));}
        typedef LinkedListIterator iterator;
};

#endif // ARRAYLIST_H
