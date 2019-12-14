#ifndef TQUEUE_H
#define TQUEUE_H
#ifndef TEACHER_H
#include "teacher.h"
#endif

#include <iostream>

using namespace std;

struct TNode{
    Teacher* data;
    TNode* next;
};

class TQueue{
    TNode *front,*rear;
    int length;
public:

    //initializes: front, rear and length
    TQueue(){
        front=NULL;
		rear=NULL;
        length = 0;
    }

    //return the Teacher* in "position" of queue
    Teacher* returnData(int position){
    	TNode* tnode = new TNode;
		if(position == 1){
			return front->data;
		}else if(position == Size()){
			return rear->data;
		}else{
			tnode = front;
			for(int i=1; i < position; i++){
	    		tnode = tnode->next;
			}
	    	return tnode->data;
		}
    	
	} 

    int GetLength(){
        return length;
    }

	// size of queue
	int Size(){ 
		TNode* tnode = new TNode;
		tnode = front;
		int size = 0;
        while(tnode != NULL){
            size++;
            tnode = tnode->next;
        }
        return size--;
		
	}
    
    //insert item at the end of queue
    void insert(Teacher* item){
        length++;
        TNode *tnode;
        tnode = new TNode;
        if(front==NULL){
            rear=front=tnode;
            rear->next=NULL;
            front->next = NULL;
            front->data=item;
        }else{
			TNode *temp = new TNode;
			temp = front;
            if(temp == rear){//we have one node
                temp->next = tnode;
                rear = tnode;
                rear->data = item;
                rear->next = NULL;
            }else{
            	while(temp!=rear){
            		temp = temp->next;
				}
				temp->next = tnode;
				tnode->data = item;
				tnode->next = NULL;
				rear = tnode;
            }
        }
    }

    //sort the queue from smaller to bigger
    void Sort(){
        TNode* curr_i = new TNode;
        curr_i = front;
        TNode* curr_j = new TNode;
        TNode* temp = new TNode;
        if(front==NULL){
                return;
        }else{
            for(int i=1; i<Size(); i++){
                curr_j= curr_i->next;
                for(int j=i+1; j<=Size(); j++){
                    if((curr_i->data)->getID() >(curr_j->data)->getID()){
                        temp->data = curr_i->data;
                        curr_i->data = curr_j->data;
                        curr_j->data = temp->data;
                    }
                    curr_j = curr_j->next;
                }
                if (i==1){
                    front->data = curr_i->data;
                }
                curr_i = curr_i->next;
            }
            rear->data = curr_i->data;
            return;
        }
    }
    
    //delete the 1st node of queue
    void delet(){
        TNode *temp = new TNode;
        if(front!=NULL){		
            //cout << "Deleted element is " << front->data << endl;
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    
    //delete the node in "position" of queue
    void specialDelete(int position){
            TNode* curr = new TNode;
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
                TNode* prev = new TNode;
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
        TNode *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

#endif