#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList
{
    public:
        ArrayList(int size);        // Constructor
        ~ArrayList();               // Destructor
        void append (T elem);       // Appends an element at the end of the list
        void insert (T elem);      // Inserts an element at currElemPos.
        void next();                // Moves the current position one step right
        void prev();                // Moves the current position one step left
        void moveToStart();         // Set the current position to the start of the list
        void moveToEnd();           // Set the  current position to the currentSize.
        void moveToPos(int pos);    // Set the current position to the integer pos.
        void remove();              // Removes the element at current position.
        void clear();
        int currPos() const;        // Returns the position of the current element
        int length() const;         // Returns the current length of the list
        T value() const;            // Returns the current element

    private:
        void doubleSize();  // Doubles the maximum size of the list
        int maxSize;        // Maximum size of list
        int currSize;       // Current number of list items
        int currElemPos;    // Position of the current element of the list
        T* arr;           // A pointer to the array holding the list elements
};

#endif // ARRAYLIST_H
