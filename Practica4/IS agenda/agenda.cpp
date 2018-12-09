#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "agenda.hpp"
#include "alumno.hpp"

using namespace std;

bool Agenda::existsStudent(Alumno student){
	for (int i = 0; i < sizeStudents(); ++i){
		if (_Students[i].getDNI() == student.getDNI() or _Students[i].getEmail() == student.getEmail())
			return true;
	}
	return false;
}

bool Agenda::existsStudentByDNI(string attribute){
	for (int i = 0; i < sizeStudents(); ++i){
		if (_Students[i].getDNI() == attribute)
			return true;
	}
	return false;
}

bool Agenda::existsStudentBySurname(string attribute){
	for (int i = 0; i < sizeStudents(); ++i){
		if (_Students[i].getSurname() == attribute)
			return true;
	}
	return false;
}

int Agenda::studentPosition(Alumno student){
	for (int i = 0; i < sizeStudents(); ++i){
		if (_Students[i].getDNI() == student.getDNI() and _Students[i].getEmail() == student.getEmail())
			return i;
	}
}

vector <int> Agenda::studentPosition(string attribute){
	vector <int> v;
	for (int i = 0; i < sizeStudents(); ++i){
		if (_Students[i].getDNI() == attribute or _Students[i].getSurname() == attribute)
			v.push_back(i);
	}
	return v;
}

void Agenda::printAllStudents(){
	cout << endl;
	for (int i = 0; i < sizeStudents(); ++i){
		printStudent(_Students[i]);
	}
}

void Agenda::printStudent(Alumno student){
	cout << student.getDNI() << ", " << student.getSurname() << ", " << student.getName() << ", " << student.getEmail() << ", " << student.getCourse() << ", " << student.getGroup() << ", " << student.getLeader() << endl;
	//cout << "\t" << student.getAddress() << " , " << student.getBirthdate() << " , " << student.getTelephone() << endl;
}

bool Agenda::insertStudent(Alumno student){
	if (!existsStudent(student)){
		setStudent(student);
		return true;
	}else
		return false;
}