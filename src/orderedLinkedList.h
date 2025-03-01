#pragma once
// Online C++ compiler to run C++ program online
// Example program
#include <iostream>
#include <string>

using namespace std;

//Definition of the node


template <class Type> struct nodeType
{
    Type info;
    nodeType<Type>* link;
};

// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
        (const linkedListType<Type>&);
    //Overload the assignment operator.

    void initializeList();
    //Initialize the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0;

    bool isEmptyList() const;
    //Function to determine whether the list is empty. 
    //Postcondition: Returns true if the list is empty, otherwise
    //    it returns false.

    void print() const;
    //Function to output the data contained in each node.
    //Postcondition: none

    int length() const;
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.

    void destroyList();
    //Function to delete all the nodes from the list.
    //Postcondition: first = NULL, last = NULL, count = 0;

    Type front() const;
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    //    otherwise, the first element of the list is returned.

    Type back() const;
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the last  
    //               element of the list is returned.

    virtual void insertFirst(const Type& newItem) = 0;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the beginning of the list, last points to
    //    the last node in the list, and count is incremented by
    //    1.

    virtual void insertLast(const Type& newItem) = 0;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the end of the list, last points to the
    //    last node in the list, and count is incremented by 1.
    virtual bool search(const Type& searchItem) const = 0;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    //    otherwise the value false is returned.

    virtual void deleteNode(const Type& deleteItem) = 0;
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    //    deleted from the list. first points to the first node,
    //    last points to the last node of the updated list, and
    //    count is decremented by 1.


    linkedListType();
    //default constructor
    //Initializes the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0; 

    linkedListType(const linkedListType<Type>& otherList);
    //copy constructor

    ~linkedListType();
    //destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed. 

protected:
    int count; //variable to store the number of list elements
    // 
    nodeType<Type>* first; //pointer to the first node of the list
    nodeType<Type>* last;  //pointer to the last node of the list

private:
    void copyList(const linkedListType<Type>& otherList);
    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and assigned
    //    to this list.
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type>* temp;   //pointer to deallocate the memory
    //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }

    last = NULL; //initialize last to NULL; first has already
    //been set to NULL by the while loop
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type>* current; //pointer to traverse the list

    current = first;    //set current so that it points to 
    //the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << "\n";
        current = current->link;
    }
}//end print

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}  //end length

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);

    return first->info; //return the info of the first node	
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);

    return last->info; //return the info of the last node	
}//end back

template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type>* newNode; //pointer to create a node
    nodeType<Type>* current; //pointer to traverse the list

    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();

    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the 
        //list to be copied
        count = otherList.count;

        //copy the first node
        first = new nodeType<Type>;  //create the node

        first->info = current->info; //copy the info
        first->link = NULL;        //set the link field of 
        //the node to NULL
        last = first;              //make last point to the
        //first node
        current = current->link;     //make current point to
        //the next node

//copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL;       //set the link of 
            //newNode to NULL
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
            //the actual last node
            current = current->link;   //make current point 
            //to the next node
        }//end while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}//end destructor

template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor

         //overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

    return *this;
}

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:

    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    //    otherwise the value false is returned.


    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the beginning of the list, last points to
    //    the last node in the list, and count is incremented by
    //    1.

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the end of the list, last points to the
    //    last node in the list, and count is incremented by 1.

    void insert(const Type& newItem);
    //Function to insert newItem in the list.
    //Postcondition: first points to the new list, newItem
    //    is inserted at the proper place in the list, and
    //    count is incremented by 1.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    //    deleted from the list; first points to the first node
    //    of the new list, and count is decremented by 1. If
    //    deleteItem is not in the list, an appropriate message
    //    is printed.
    friend void updateReservationPeriod(orderedLinkedList<reservation>& reservations, int reservationNumber, const string& newPeriod);
    friend reservation searchReservationByRoomNumber(orderedLinkedList<reservation>& otherlist, int targetRoomNumber);
    friend bool searchReservationByid(orderedLinkedList<reservation>& reservations, int id);
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type>* current; //pointer to traverse the list

    current = linkedListType<Type>::first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
        found = (current->info == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* trailCurrent; //pointer just before current
    nodeType<Type>* newNode;  //pointer to create a node

    bool  found;
    trailCurrent = NULL;
    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newItem in the node
    newNode->link = NULL;      //set the link field of the node
    //to NULL

    if (linkedListType<Type>::first == NULL)  //Case 1
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != NULL && !found) //search the list
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == linkedListType<Type>::first)      //Case 2
        {
            newNode->link = linkedListType<Type>::first;
            linkedListType<Type>::first = newNode;
            linkedListType<Type>::count++;
        }
        else                       //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
                linkedListType<Type>::last = newNode;

            linkedListType<Type>::count++;
        }
    }//end else
}//end insert
template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}
reservation searchReservationByRoomNumber(orderedLinkedList<reservation>& otherlist, int targetRoomNumber)
{
    reservation found;

    nodeType<reservation>* current = otherlist.first;
    while (current != NULL)

    {
        if (current->info.room_no == targetRoomNumber)
            found = current->info;

        current = current->link;
    }
    return found;
}
bool searchReservationByid(orderedLinkedList<reservation>& reservations, int id)
{
    nodeType<reservation>* current = reservations.first;
    bool found = false;

    while (current != nullptr)
    {
        if (current->info.id == id)
        {
            cout << "Reservation number: " << current->info.reservation_no << endl;
            cout << "Period: " << current->info.period << endl;
            cout << "Room number: " << current->info.room_no << endl;
            cout << "Review: " << current->info.review << endl;
            cout << "Price: " << current->info.price << endl;
            
            found = true;
            break;
        }
        current = current->link;
    }
    return found;
}
template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* trailCurrent; //pointer just before current
    bool found;
    trailCurrent = NULL;
    if (linkedListType<Type>::first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "The item to be deleted is not in the "
            << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be
                //deleted is in the list
            {
                if (linkedListType<Type>::first == current)       //Case 2
                {
                    linkedListType<Type>::first = linkedListType<Type>::first->link;

                    if (linkedListType<Type>::first == NULL)
                        linkedListType<Type>::last = NULL;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == linkedListType<Type>::last)
                        linkedListType<Type>::last = trailCurrent;

                    delete current;
                }
                linkedListType<Type>::count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                << "list." << endl;
    }
}//end deleteNode
