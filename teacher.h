#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>

using namespace std;

class Teacher{
	private:
		int identity;
		int availability;
	public:
		Teacher(int id){
			identity = id;
			availability = 1; //the teacher is available
		}

		void SetAvailable(){
			availability = 1;
		}

		void SetNotAvailable(){
			availability = 0;
		}

		int getID(){
			return identity;
		}

		//return the availability of teacher
		int returnAvailability(){
			if(availability = 1){
				cout << "Teacher: " << identity << " is available!" << endl;
				return 1;
			}else{
				return 0;
			}
		}
};

#endif