#include <iostream>
#include "SLL.h"
#include <string>
#include <cmath>
using  namespace  std;

template <class V>
class HashTable {
    int tableSize; // table size
    //int count;
    SLL<V>* table;
    
    public:
    
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size)
    {
        tableSize = size;
        table = new SLL<V>[tableSize];

      // implement this method
    }
//    int hashFunc(V key){
//
//        return key % 10007;
//    }
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item){
       
        int hashNum = 0;
        int hashReal = 0;
        
        for(int i = 0; i <= item.length()-1; i++)
        {
            int power = item.length()-1-i;
            hashNum = hashNum + ((int)(item.at(i)))*(pow(31,power));
        }
        hashReal = abs(hashNum)%(10007);
        SLL<string>* temp = &table[hashReal];
            //cout << "ranen is poop";
        if( temp-> search(item) == NULL){
                return true;
        }else{
        return false;
        }
        //val is the location of the list in the array
        // implement this method
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2){
        int hashNum=0;
        int hashReal=0;
        
        for(int i=0; i<=item1.length()-1; i++)
        {
            int power = item1.length()-1-i;
            hashNum = hashNum + ((int)(item1.at(i)))*(pow(31, power));
        }
        hashReal = abs((hashNum)%(10007));
        
        SLL<string>* temp1 = &table[hashReal];
        
        if(temp1->search(item1) != NULL)
        {
            return false;
        }
        
        SLL<string>* temp2 = &table[hashReal];
        
        temp2->insert(item1, item2);
        
        SLL<string>* temp3 = &table[hashReal];
        
        if(temp3->search(item1) != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false 
    bool erase(V item){
        int hashNum = 0;
        int hashReal = 0;
        
        for(int i = 0; i <= item.length()-1; i++)
        {
            int power = item.length()-1-i;
            hashNum = hashNum + ((int)(item.at(i)))*(pow(31,power));
        }
        hashReal = abs(hashNum)%(10007);
        SLL<string>* temp = &table[hashReal];
        //cout << "ranen is poop";
        if( temp-> remove(item)){
            return true;
        }else{
            return false;
        }
    }

    // return the total number of nodes in the hash table    
    int getSize(){
        int count=0;
        
        for(int i=0; i<=tableSize-1; i++)
        {
            SLL<string>* temp = &table[i];
            count = count + temp->getSize();
        }
        
        return count;
    } // implement this method
    

};
