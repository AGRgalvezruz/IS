#ifndef _PROFESOR_HPP_
#define _PROFESOR_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "agenda.hpp"
#include "alumno.hpp"

using namespace std;

class Profesor {
	private:
		string	_username;
		bool	_rol;

		Agenda * _listStudents;

	public:
		//constructor de nuestro sistema que crea el fichero credenciales si no existe
		Profesor();

		inline void setUsername(string username){ _username = username; }
		inline string getUsername(){ return _username; }

		inline void setRol(bool rol){ _rol = rol; }
		inline bool getRol(){ return _rol; }
		bool getRol(string username); //obtener el rol de un usuario

		Agenda * getListStudents(){ return _listStudents; }

		//permite hacer el cambio de contraseña de un usuario pasdo
		void changePassword(string username, string password);

		//comprobar si el username no tiene contraseña para poder ser cambiada
		bool checkPassword(string username); //true->puede ser cambiada

		//comprueba si existe un usuario en nuestro sistema con dicho username
		bool existsUser(string username);

		//comprueba si los datos de login son correctos
		bool correctData(string username, string password);


		void loadData(string fichero);

		void saveData(string fichero);

};

#endif