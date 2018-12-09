#ifndef _ALUMNO_HPP_
#define _ALUMNO_HPP_

#include <iostream>
#include <string>

using namespace std;


class Alumno {
	private:
		string 	_DNI;
		string 	_Name;
		string 	_Surname;
		string	_Address;
		string	_Email;
		string	_Birthdate;
		int 	_Telephone;
		int		_Course;
		int		_Group;
		bool	_Leader;

	public:
		inline Alumno(){ _DNI=""; _Name=""; _Surname=""; _Address=""; _Email=""; _Birthdate=""; _Telephone=0; _Course=0; _Group=0; _Leader=false;}

		inline void setDNI(string DNI){ _DNI = DNI; }
		inline string getDNI(){ return _DNI; }

		inline void setName(string name){ _Name = name; }
		inline string getName(){ return _Name; }

		inline void setSurname(string surname){ _Surname = surname; }
		inline string getSurname(){ return _Surname; }

		inline void setAddress(string address){ _Address = address; }
		inline string getAddress(){ return _Address; }

		inline void setEmail(string email){ _Email = email; }
		inline string getEmail(){ return _Email; }

		inline void setBirthdate(string birthdate){ _Birthdate = birthdate; }
		inline string getBirthdate(){ return _Birthdate; }

		inline void setTelephone(int telephone){ _Telephone = telephone; }
		inline int getTelephone(){ return _Telephone; }

		inline void setCourse(int course){ _Course = course; }
		inline int getCourse(){ return _Course; }

		inline void setGroup(int group){ _Group = group; }
		inline int getGroup(){ return _Group; }

		inline void setLeader(bool leader){ _Leader = leader; }
		inline bool getLeader(){ return _Leader; }
};

#endif