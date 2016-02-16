// ***************************************************************
// This is the implementation file for the Permutation class
// ***************************************************************
#include "permutations.h"

// Default constructor
Permutations::Permutations() : myPerms(NULL) {
}

// Destructor
Permutations::~Permutations() {
    removeAll();
}

// Generates permutations for set of size n
void Permutations::generate(int n) {
    if (myPerms != NULL) { // First clean the permutations if necessary
        removeAll();
    }

    int* aSet = new int[n];
    // Populate the set with the first n whole numbers
    for (int i = 0; i < n; i++) {
        aSet[i] = i+1;
    }

    // Use the recursive permutations function to generate all the permutations
    myPerms = permutate(aSet, n);
    // Deallocate aSet
    delete [] aSet;
}

// Prints all the permutations
void Permutations::print() const
{
    // You have to implement this function.
    // It should call the printSet function
    int count = 1;
    for(NodePtr iter = myPerms; iter != NULL; iter = iter->next)
    {
        cout << count << ": ";
        printSet(iter->setPtr,iter->setSize);
        cout << endl;
        count++;
    }
}

// Private functions start here
void Permutations::printSet(int set[], int size) const {
    cout << "{";
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << set[i];
    }
    cout << "}";
}

void Permutations::remove(NodePtr node)
{
    delete [] node->setPtr;  // delete the set inside the node
    delete node;             // delete the node
}

// Remove every node from the list
void Permutations::removeAll()
{
    while (myPerms != NULL) {
        NodePtr next = myPerms->next;
        remove(myPerms);              // delete this node
        myPerms = next;
    }
}

void Permutations::insert(int num, NodePtr smaller, NodePtr& larger)
{
// For each permutation of the smaller list, make a permutation (pointed to by 'larger')
// that includes the number 'num' in each position

// You have to implement this function, but it is partly given below.

    int pos = 0;
    NodePtr newNode = NULL;

    while (smaller != NULL) { // Traverse the 'smaller' list

        for (int i = 0; i <= smaller->setSize; i++) { // Iterate through the set.

            // Create a new set which is one larger than the current set and add 'num' in the correct pos
            // This will become part of the list pointed to by 'larger'

            NodePtr temp = new Node;
            temp->setSize = smaller->setSize+1;
            temp->setPtr = new int[temp->setSize];

            for(int i = 0; i < temp->setSize; i++)
            {
                if(i < pos%temp->setSize)
                {
                    temp->setPtr[i] = smaller->setPtr[i];
                }
                else if(i == pos%temp->setSize)
                {
                    temp->setPtr[i] = num;
                }
                else
                {
                    temp->setPtr[i] = smaller->setPtr[i-1];
                }
            }

            temp->next = newNode;
            newNode = temp;

            pos++;

        }
        // Delete the node we just used, and move to the next one
        NodePtr next = smaller->next;
        remove(smaller);
        smaller = next;
    }
    larger = newNode;
}

// Recursive function that returns a list containing all of the permutations of the set
NodePtr Permutations::permutate(int set[], int size)
{
    // You have to implement this function.
    // It should call itself recursively and also call the insert function
    if(size == 1)
    {
        myPerms = new Node;
        myPerms->next = NULL;
        myPerms->setSize = 1;
        myPerms->setPtr = new int[1];
        myPerms->setPtr[0] = set[0];
    }
    else
    {
        NodePtr temp = permutate(set,size-1);
        insert(set[size-1],temp,myPerms);
    }
    return myPerms;
}
