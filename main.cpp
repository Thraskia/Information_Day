#include <iostream>
#include <ctime>
#include <cstdlib>

#include "tqueue.h"
#include "pqueue.h"
#include "teacher.h"
#include "parent.h"

using namespace std;

int main(){
	int N=10;
	int K=3;
	//cout << "Give the number of teachers: ";
	//cin >> N;
	//cout << "Give the number of parents: ";
	//cin >> K;
	int L = 5;
	PQueue queueParents;
	PQueue queueArea;
	//create an array of teachers
	Teacher** teachers = new Teacher* [N];
	for(int i = 0; i< N; i++){
		teachers[i] = new Teacher(i+1);
		//cout << teachers[i] << endl; 
	}
	//create K-parents( push them in queueParents)
	//for each one create random number(and random teachers) of teachers 
	//that need to visit
	srand(time(NULL));
	Parent* parent;
	for(int i = 1; i<= K; i++){ 
		parent = new Parent(i);
		/*int random_no_teachers = rand();
	    while(random_no_teachers > N){ 
	    	random_no_teachers = random_no_teachers% N;
	   		if(random_no_teachers == 0 ){
	   			random_no_teachers= rand();
	   		}
	   	}*/
	   	int random_no_teachers = 1;
	   	int random_t = rand();
	   	for(int j = 0; j < random_no_teachers; j++){ 
	   		while(random_t >= N){
				random_t = random_t%N;
	   		}
			parent->PushInList(teachers[random_t]);
	   	}
		queueParents.insert(parent);
	}
	//push L-parents(or less) to queueArea
	//delete those parents from queueParents
	for(int i = 0; i< L; i++){
		if(queueParents.Size()>0){
			(queueParents.returnData(1))->SortQueue();
			//(queueParents.returnData(1))->PrintQueue();
			queueArea.insert(queueParents.returnData(1));
			queueParents.delet();
		}
	}
	int pos_teacher = 0; //start from the 1st teacher of list
	while(queueArea.Size() != 0){ //there are parents that they want to talk to teachers
		if(teachers[pos_teacher]->returnAvailability() == 1){// Teacher is available
			int idt = pos_teacher+1; 
			int pos_parent = 0;
			for(int i=1; i<=queueArea.Size(); i++ ){
				if((queueArea.returnData(i))->match(idt) == 1){//if want to visit that teacher
					pos_parent = i; //keep the parent's identity
					break;
				}
			}
			if(pos_parent != 0){ //if there is a parent that want to visit the teacher
				teachers[pos_teacher]->SetNotAvailable(); //teacher is not available anymore
				(queueArea.returnData(pos_parent))->DeleteTeacher(idt); //remove teacher from parent's queue
				if((queueArea.returnData(pos_parent))->Visit() == 1){ //parent want to visit more teachers 
					int random_message = rand();
					if(random_message%2 == 0){
						cout << "You're in wrong position. PLease, find you're position." << endl;
					}else{
						cout << "Well done. You're in correct position" << endl;
					}
					queueArea.insert((queueArea.returnData(pos_parent))); //push him at the end of queue
					queueArea.specialDelete(pos_parent); //delete him from the previous position in queue
				}else{
					queueArea.specialDelete(pos_parent); //delete him from the queueArea
					cout << "I finished! " << endl;
				}
				teachers[pos_teacher]->SetAvailable(); //teacher is available again
				//START: for each parent that visit a teacher---i have to create randomly number of parents that enter the building
				if(queueParents.Size() != 0){
					int random= rand(); 
				   	while(random > queueParents.Size()){ //create random number of parents
				   		random= random%queueParents.Size();
				   	}
				   	if(random > 0){
				   		for(int i=1; i<=random; i++){
				   			if(queueParents.Size()>0){
				   				queueArea.insert(queueParents.returnData(1));
					   			queueParents.delet();
				   			}
					   	}
				   	}
				}
			}
		}
		pos_teacher++;
		if(pos_teacher == N){ //start over again
			pos_teacher = 0;
		}
	}
}