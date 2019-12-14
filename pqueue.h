#ifndef PQUEUE_H
#define PQUEUE_H

//#include "parent.h"


#include <iostream>

using namespace std;
class Parent;
struct PNode{
    Parent* data;
    PNode* next;
};

class PQueue{
    PNode *front,*rear;
    int length;
public:
    
    //initializes: front, rear and length
    PQueue(){
        front=NULL;
		rear=NULL;
        length = 0;
    }
    
    //return the Parent* in "position" of queue
    Parent* returnData(int position){
    	PNode* pnode = new PNode;
		if(position == 1){
			return front->data;
		}else if(position == Size()){
			return rear->data;
		}else{
			pnode = front;
			for(int i=1; i < position; i++){
	    		pnode = pnode->next;
			}
	    	return pnode->data;
		}
    	
	} 

    int GetLength(){
        return length;
    }

	// size of queue
	int Size(){ 
		PNode* pnode = new PNode;
		pnode = front;
		int size = 0;
        while(pnode != NULL){
            size++;
            pnode = pnode->next;
        }
        return size--;
		
	}

    //insert item at the end of queue
    void insert(Parent* item){
        length++;
        PNode *pnode;
        pnode = new PNode;
        if(front==NULL){
            rear=front=pnode;
            rear->next=NULL;
            front->next = NULL;
            front->data=item;
        }else{
			PNode *temp = new PNode;
			temp = front;
            if(temp == rear){//we have one node
                temp->next = pnode;
                rear = pnode;
                rear->data = item;
                rear->next = NULL;
            }else{
            	while(temp!=rear){
            		temp = temp->next;
				}
				temp->next = pnode;
				pnode->data = item;
				pnode->next = NULL;
				rear = pnode;
            }
        }
    }

    //delete the 1st node of queue
    void delet(){
        PNode *temp = new PNode;
        if(front!=NULL){		
            //cout << "Deleted element is " << front->data << endl;
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    
    //delete the node in "position" of queue
    void specialDelete(int position){
            PNode* curr = new PNode;
            curr = front;
            if(front == NULL){
                return;
            }
            if(position == 1){
                delet();
                return;
            }
            if(length == 2){
                if(position == 2){
                    curr = rear;
                    front->next = NULL;
                    rear = front;
                }
                length--;
                delete curr;
            }else{
                PNode* prev = new PNode;
                if(position == length){
                    for (int i = 1; i < length-1; i++){
                        curr = curr->next;
                    }
                    curr->next = NULL;
                    prev = curr;
                    curr = rear;
                    delete curr;
                    rear = prev;
                }else{
                    for(int i= 1; i< position; i++){
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = curr->next;
                    delete curr;
                }
                length--;
            }
        }

    //print the queue
    void display(){
        PNode *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

#endif