#ifndef PARENT_H
#define PARENT_H
#include <iostream>
#include "teacher.h"
#include "tqueue.h"

using namespace std;

class Parent{
	private:
		int identity; 
		TQueue queueGoToTeacher; //queue with teachers that want to visit each parent

	public:
		Parent(int id){
			identity = id;

		}
		//check if parent is going to teacher "idt"
		int match(int idt){
			for(int i=1; i<=queueGoToTeacher.Size(); i++){
				if((queueGoToTeacher.returnData(i))->getID() == idt){
					return 1;
				}else if((queueGoToTeacher.returnData(i))->getID() > idt){
					return 0; //its sorted 
				}
			}
		}
		//sort the queue
		void SortQueue(){
			queueGoToTeacher.Sort();
		}

		//delete from queue the teacher that have visited by parent
		void DeleteTeacher(int idt){
			for(int i=1; i<= queueGoToTeacher.Size(); i++){
				if((queueGoToTeacher.returnData(i))->getID() == idt){
					queueGoToTeacher.specialDelete(i);
					return;
				}
			}
		}

		//check if parent want to visit more teachers
		int Visit(){
			if(queueGoToTeacher.Size() > 0){
				cout << "i want to visit more teachers" << endl;
				return 1;
			}else{
				cout << "oh yes! I just finished my work here" << endl;
				return 0;
			}
		}

		//print queue
		void PrintQueue(){
			cout << "Parent with id: " << identity << " is going to teachers: " << endl;
			queueGoToTeacher.display();
		}

		//push a teacher to queue
		void PushInList(Teacher* teacher){
			queueGoToTeacher.insert(teacher);
		}


};
#endif