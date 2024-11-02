//  Program II 
//  Ty'Mon Harvey
//  Partner: Shane Brown
//  10/10/24


#ifndef LIST_H 
#define LIST_H 
using namespace std; 
#include<iostream> 
template <typename T> 
class LinkedList 

{ 

    private: 

    //Doubly linked list bc there is a next and prev node 

        struct ListNode 
        { 

            T val; 

            ListNode * nextNode; 
            ListNode * prevNode; 
        }; 

 

        //Linked List 

        ListNode * head; 

        ListNode * tail; 

         

//--------------------------------------(Private) Print-------------------------------------- 

        void print(ListNode * node) 

        { 

            //counter to assign numbers to the list when printed 

            int count = 1; 

 

            //called in the public print function 

            //prints all values in the list, takes in and starts 

            //with the value that is passed 

            while (node != NULL) 

            { 

                cout << count << ". " << *(node->val); 

                cout << endl; 

                node = node->nextNode; 

 

                //Increments the counter 

                count++; 

            } 

        } 

//--------------------------------------(Private) MergeSort-------------------------------------- 

        typename LinkedList<T>::ListNode * mergesort(ListNode * front, ListNode * back) 

        { 

            //sorts nodes in linked list in descending order  

            //of population by county using merge sort 

            ListNode * mid; 

            ListNode * holdOne; 

            ListNode * holdTwo; 

 

            //Base case 

            //Checks if list is empty or if the list has only one element 

            if(front == NULL || front->nextNode == NULL) 

            { 

                return front; 

            } 

            //Splits the linked list with the split function 

            //Assigning the mid with the val returned for the split function 

            mid = split(front, back); 


            //The values returned from the mergesort function is assigned to the 

            //holder pointers 

            holdOne = mergesort(front, mid->prevNode); 

            holdTwo = mergesort(mid, back); 

 

            return merge(holdOne, holdTwo); 

        } 

//--------------------------------------(Private) Merge-------------------------------------- 

    typename LinkedList<T>::ListNode* merge(ListNode* front, ListNode* back)
{
    if (front == NULL)
    {
        return back;
    }
    if (back == NULL)
    {
        return front;
    }

    // Uses the getPrice() function from PhoneType instead of getPopulation()
    if (front->val->getPrice() < back->val->getPrice())
    {
        back->nextNode = merge(front, back->nextNode);
        back->prevNode = NULL;
        return back;
    }
    else
    {
        front->nextNode = merge(front->nextNode, back);
        front->prevNode = NULL;
        return front;
    }
}


//--------------------------------------(Private) Split-------------------------------------- 

        typename LinkedList<T>::ListNode * split (ListNode * front, ListNode * back) 

        { 

            //Finds the middle node in the linked list by traversing the list until 

            //the tail and head are overlapping with eachother 

            ListNode * mid = NULL; 

            //traverses the linked list 

            while(front != back && front->nextNode != back) 

            { 

                front = front->nextNode; 

                back = back->prevNode; 

            } 

 

            //Assigning the next value node to the mid, partitions 

            //and splits the linked list. 

            mid = front->nextNode; 

            //Splits the list in two 

            front->nextNode = NULL; 

            return mid; 
        } 

    public: 

//--------------------------------------Constructor--------------------------------------    

        LinkedList() 

        { 

            //Sets head and tail to null 

            head = NULL; 

            tail = NULL; 

        } 


//--------------------------------------Deconstructor-------------------------------------- 

        ~LinkedList() 

        { 
            ListNode * currNode = head; 

            ListNode * tempNode; 


            //Destructor deletes each node by moving through the linked list until 

            //the while loop returns NULL 

            while(tempNode != NULL) 

            { 

                tempNode = currNode->nextNode; 

                delete currNode; 

                currNode = tempNode; 

            } 

        } 
//--------------------------------------(Public) Print-------------------------------------- 

        void print() 

        { 

            //Calls the private print function and passes the head of the linked list 

            ListNode * currNode = head; 

            print(head); 

        } 

//--------------------------------------Append-------------------------------------- 

        void append(const T& userVal) 

        { 

            //adds a new node from the value passed in from the csv file 

            //dynamically allocates a new ListNode 

            ListNode * newNode = new ListNode; 

            newNode->val = userVal; 

            newNode->nextNode = NULL; 

            newNode->prevNode = NULL; 

            //If list is empty, the head and tail are set to the new val passed 

            if(head == NULL) 

            { 
                head = newNode; 

                tail = newNode; 

            } 

            //otherwise, adds the value to the end of the linked list 

            else 
            { 
                tail->nextNode = newNode; 

                newNode->prevNode = tail; 

                tail = newNode; 

            } 

        } 

//--------------------------------------(Public) MergeSort-------------------------------------- 

        void mergeSort() 
        { 

            //Calls the private mergesort function 

            ListNode * newNode = NULL; 

            //Assigns the head of the linked list to the 
            //value returned by the private mergesort function 
            head = mergesort(head, tail); 

            newNode = head; 

            //the newNode is used to traverse the linked list until 

            //the nextNode is equal to null 

            //Assigns the value to tail 

            while(newNode != NULL) 

            { 

                newNode = newNode->nextNode;                                                                                                                                                                                                                                                                  
            } 

            tail = newNode; 

        } 

        //--------------------------------------(Public) Remove--------------------------------------

void remove(const T& value) 
{
    ListNode* currNode = head;

    // Traverse the list to find the node with the specified value
    while (currNode != nullptr && *(currNode->val) != value) 
    {
        currNode = currNode->nextNode;
    }

    // If the value is not found, exit the function
    if (currNode == nullptr) 
    {
        cout << "Value not found in the list." << endl;
        return;
    }

    // If the node to be removed is the head node
    if (currNode == head) 
    {
        head = currNode->nextNode;
        if (head) head->prevNode = nullptr;
    } 
    else if (currNode == tail) // If the node to be removed is the tail node
    {
        tail = currNode->prevNode;
        if (tail) tail->nextNode = nullptr;
    } 
    else // If the node to be removed is in the middle
    {
        currNode->prevNode->nextNode = currNode->nextNode;
        currNode->nextNode->prevNode = currNode->prevNode;
    }

    delete currNode; // Delete the node from memory
    cout << "Node removed successfully." << endl;
}

}; 

#endif 



