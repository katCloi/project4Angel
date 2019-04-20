//
//  KatrinaG_project4.cpp
//  
//
//  Created by Katrina Gutierrez on 4/12/19.
//

#include <iostream>
#include "node.h"
using namespace std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
public:
    // default constructor
    SLL(){
        headPtr = nullptr;
        size = 0;
    }
    
    // destructor
    ~SLL(){
        Node<U> *next;
        while(headPtr != nullptr)
        {
            next = headPtr->next;
            delete headPtr;
            headPtr = next;
        }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
        Node<U> *n = new Node<U>();
        n->SSN = item1;
        n->name = item2;
        n->next = nullptr;
        
        if(headPtr == nullptr)
            headPtr = n;
        else
        {
            Node<U> last = headPtr;
            while(last->next != nullptr)
                last = last->next;
            last->next = n;
        }
        size++;
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
        Node<U> *curr = headPtr;
        while(curr != nullptr)
        {
            if(curr->item1 == SSN)
                return curr;
            curr = curr->next;
        }
        
        return nullptr;//not found
    }
    
    // remove the node with key value: item1
    bool remove(U item1){
        Node<U> *prev = nullptr, *curr = headPtr;
        
        while(curr != nullptr)
        {
            if(curr->SSN == item1)
                break;
            prev = curr;
            curr = curr->next;
        }
        
        if(curr == nullptr) //not found
            return false;
        
        if(curr == headPtr) //remove head node?
            headPtr = curr->next;
        else
            prev->next = curr->next;
        
        delete curr;
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


