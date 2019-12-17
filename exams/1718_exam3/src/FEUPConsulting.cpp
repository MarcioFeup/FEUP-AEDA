/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

#include <algorithm>

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//

void FEUPConsulting::addAvailability(Student* student, string expertizeAvailable, unsigned cost) {
	Expertize notFound("", 0);
	Expertize toAdd(std::move(expertizeAvailable), cost);
	Expertize found = expertizes.find(toAdd);

	if (found == notFound) {
		toAdd.addConsultant(student);
		expertizes.insert(toAdd);
	} else {
		expertizes.remove(found);
		found.addConsultant(student);
		expertizes.insert(found);
	}

}

vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	vector<Student*> temp;

	Expertize toFind(project->getExpertize(), project->getCost());
	Expertize expertize = expertizes.find(toFind);

	for (Student *student : expertize.getConsultants())
		if (student->getCurrentProject().empty())
			temp.push_back(student);

	return temp;

}


bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
	if (project->getConsultant() != nullptr || !student->getCurrentProject().empty())
		return false;

	vector<Student *> consultants = expertizes.find(Expertize(project->getExpertize(), project->getCost())).getConsultants();
	if (find(consultants.begin(), consultants.end(), student) == consultants.end())
		return false;

	student->addProject(project->getTitle());
	project->setConsultant(student);

	return true;

}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {
	StudentPtr ptr(student);
	students.insert(ptr);
}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	StudentPtr ptr(student);
	students.erase(ptr);
	student->setEMail(std::move(newEMail));
	students.insert(student);
}


//
// TODO: Part III - Priority Queue
//

void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {
	for (const Student& candidate : candidates)
		if (candidate.getPastProjects().size() >= min)
			activeStudents.push(candidate);
}


// prob wrong, didn't understand the studentMaximus part
int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {
	if (activeStudents.empty())
		return 0;

	Student active = activeStudents.top();
	activeStudents.pop();

	if (activeStudents.empty()) {
		studentMaximus = active;

		activeStudents.push(active);
	} else {
		Student tmp = activeStudents.top();
		activeStudents.push(active);

		if (active.getPastProjects().size() == tmp.getPastProjects().size())
			return 0;

		studentMaximus = active;
	}

	return activeStudents.size();
}





















