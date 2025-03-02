#include <iostream>
using namespace std;

#define MAXSPORTS 5
#define MAXLEARNERS 3

class mentors;
class students;
class Sport;
class Skill;

class students{
	string student_id;
	string student_name;
	int student_age;
	string sports_interests[5];
	mentors *m;
	
	public:
		students(){
			student_id="";
			student_name="";
			student_age=0;
			for(int i=0;i<5;i++){
				sports_interests[i]="";
			}
			m = nullptr ;
			
		}
        students(string id, string name,int age){
            student_id=id;
            student_name=name;
            student_age=age;

        }

		void registerFormentorship(mentors *m){}


		void viewMentorDetail(){
			cout<<"mentor id:" << m->mentor_id<<endl;
            cout<< " mentor name :" << m->name<<endl;
            cout<<"sports expertised:"<<endl;
            for(int i=0 ; i<MAXSPORTS ; i++){
                cout<<m->sportsexpertised[i];
            }
            cout<< "max number of learners:" <<  MAXLEARNERS <<endl;
            cout<< "assigned learners:" << m->assigned_count <<endl;
		}

        void displaystudent_Detail(){
            cout<<"student id :"<< student_id <<endl;
            cout<<"student name " << student_name <endl;
            cout<<"student age" << student_age <endl;
        }

bool students::registerFormentorship(mentors* m) {
    if (m->assignLearner(this)) {
        cout << "Student " << name << " successfully registered with Mentor " << m->name << "." << endl;
        return true;
    } else {
        cout << "Mentor " << m->name << " has reached the maximum number of learners." << endl;
        return false;
    }
}

class mentors{
	string mentor_id;
	string name;
	string sportsexpertised[MAXSPORTS];
	int sportscount;
	students* assignedlearners[MAXLEARNERS];
    int assigned_count;
	
	public:
    mentors(string id, string n, string sports[], int sportCount,)
    : mentor_id(id), name(n), sportscount(sportCount), assigned_count(0) {
    for (int i = 0; i < sportCount; i++) {
        sportsexpertised[i] = sports[i];
    }
    }

    bool assignLearner(students* student) {
        if (assigned_count < MAXLEARNERS) {
            assignedlearners[assigned_count++] = student;
            student->m = this;
            return true;
        }
        return false;
    }

    void removeLearner(students* student) {
        for (int i = 0; i < assignedCount; i++) {
            if (assignedLearners[i] == student) {
                for (int j = i; j < assignedCount - 1; j++) {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                assignedCount--;
                student->mentorAssigned = nullptr;
                return;
            }
        }
        cout << "Student not found in the list.\n";
    }

    void viewLearners() const {
        cout << "Mentor: " << name << " has the following learners:\n";
        for (int i = 0; i < assignedCount; i++) {
            cout << "- " << assignedLearners[i]->name << endl;
        }
    }

    void provideGuidance() const {
        cout << "Mentor " << name << " is providing guidance.\n";
    }

    friend void Students::viewMentorDetails() const;
};
};

class Sport {
    string sportID;
    string name;
    string description;
    Skill* requiredSkills[MAXSPORTS];
    int skillCount;

public:
    Sport(string id, string n, string desc) : sportID(id), name(n), description(desc), skillCount(0) {}

    void addSkill(Skill* skill) {
        if (skillCount < MAXSPORTS) {
            requiredSkills[skillCount++] = skill;
        } else {
            cout << "Cannot add more skills to this sport.\n";
        }
    }

    void removeSkill(Skill* skill) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i] == skill) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                return;
            }
        }
        cout << "Skill not found in the list.\n";
    }
};

class Skill {
    string skillID;
    string skillName;
    string description;

public:
    Skill(string id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    void showSkillDetails() const {
        cout << "Skill ID: " << skillID << ", Skill Name: " << skillName << ", Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
};
