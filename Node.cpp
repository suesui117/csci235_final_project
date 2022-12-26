/*
List class implementation for term projects
CSCI 235 Fall 2022
Hunter College
*/
// #include "Node.hpp"

/*
    Default Constructor
*/
template <class ItemType>
Node<ItemType>::Node() : next_{nullptr} {} // // private data next_ is a pointer, set private member next_ to nullptr




/*
    Parametarized Constructor
    @param item - the item to be constructed
    @param next_node - the next node to point to
 */
template <class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType> *next_node) : item_{item}, next_{next_node} {}
// private data item_, can be account, set input_item to item_
// private data next_ is a pointer, set input_next_node to next_



/*
    Setter function for node item
    @param anItem - the item to be set in item_
*/
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {
    item_ = anItem;
}


/*
    Setter function for pointer to next node in chain
    @param nextNodePtr - the nextNodePtr to be set in next_
*/
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr){
    next_ = nextNodePtr; // set next_ to a pointer passed in by user
}



/*
    @return returns the value for item_
*/
template <class ItemType>
ItemType Node<ItemType>::getItem() const { return item_; }


/*
    @return returns the value for next_
*/
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const { return next_; }