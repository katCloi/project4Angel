#include <iostream>
#include "node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
public:
    // default constructor
    SLL(){
        headPtr = NULL;
        size = 0;
        //implement this method
    }
    
    // destructor
    ~SLL(){
        Node<U> *next;
        while(headPtr != NULL)
        {
            next = headPtr -> next;
            delete headPtr;
            headPtr = next;
        }// implement this method
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
        Node<U> *n = new Node<U>();
        n -> SSN = item1;
        n -> name = item2;
        n -> next = NULL;
        
        if(headPtr == NULL){
            headPtr = n;
        }
        else{
            Node<U> *last = headPtr;
            while(last -> next != NULL)
                last = last -> next;
            last -> next = n;
        }//implement this method
        size++;
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
        Node<U> * temp = headPtr;
        
        if(headPtr == NULL)
        {
            return NULL;
        }
        
        while(temp != NULL)
        {
            if(temp->SSN == item1)
            {
                return temp;
            }
            temp = temp->next;
        }
        
        return NULL;
    }
    
    
    // remove the node with key value: item1
    bool remove(U item1){
       Node<U> *prev = NULL;
        Node <U> *current = headPtr;
        
        while(current != NULL)
        {
            if(current -> SSN == item1){
                break;
            }
            
            prev = current;
            current = current -> next;
        }
        
        if(current == NULL)
        {
            return false;
        }
        
        if(current == headPtr)
        {
            headPtr = current -> next;
        }
        else{
            prev -> next = current -> next;
        }//implement this method
        
        delete current;
        size--;
        return true;
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};
