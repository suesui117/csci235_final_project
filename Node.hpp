/*
Node class interface for term projects
CSCI 235 Fall 2022
Hunter College
*/


#ifndef Node_
#define Node_

#include <iostream>
#include "Post.hpp"

template<typename ItemType>
class Node {

    public:
        /*
            Default Constructor
        */
        Node();

        /*
            Parametarized Constructor
            @param item - the item to be constructed
            @param next_node - the next node to point to
         */
        Node(const ItemType& item, Node<ItemType> *next_node = nullptr);

        /*
            Setter function for node item
            @param anItem - the item to be set in item_
        */
        void setItem(const ItemType &anItem);

        /*
            Setter function for pointer to next node in chain
            @param nextNodePtr - the nextNodePtr to be set in next_
        */
        void setNext(Node<ItemType> *nextNodePtr);

        /*
            @return returns the value for item_
        */
        ItemType getItem() const;

        /*
            @return returns the value for next_
        */
        Node<ItemType> *getNext() const;


    private:
        ItemType item_; // private data item_, can be account
        Node<ItemType> *next_; // private data next_ is a pointer
};

#include "Node.cpp"
#endif
