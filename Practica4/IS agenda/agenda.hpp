#ifndef _AGENDA_HPP_
#define _AGENDA_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "alumno.hpp"

using namespace std;


class Agenda {
	private:
		vector<Alumno> _Students;

	public:
		inline Agenda(){}

		//agenda de estudiantes: true->vacia
		inline bool emptyStudents(){ return _Students.empty(); }

		//obtiene el numero de estudiantes en la agenda
		inline int sizeStudents(){ return _Students.size(); }

		//comprueba que el numero de estudiantes no sobrepase 150
		inline bool checkNumberOfStudents(){ if(sizeStudents() < 150) return true; else return false; }

		//comprueba si existe el alumno pasado en la agenda
		bool existsStudent(Alumno student);
		bool existsStudentByDNI(string attribute);
		bool existsStudentBySurname(string attribute);

		//obtenemos la posicion en el la agenda del alumno
		int studentPosition(Alumno student);
		vector <int> studentPosition(string attribute);


		//inserta un estudiante en la agenda
		inline void setStudent(Alumno student) { _Students.push_back(student); }
		
		inline vector<Alumno> getStudents() { return _Students; }
//		inline vector<Alumno> getStudents(int group);
		inline Alumno getStudent(int position){ return _Students[position]; }

		//borra un alumno
		inline void deleteStudent(Alumno student){ _Students.erase(_Students.begin() + studentPosition(student)); }

		void printStudent(Alumno student);
		void printAllStudents();

		bool insertStudent(Alumno student);


};

#endif