#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h> 

#include "macros.hpp"
#include "profesor.hpp"

using namespace std;

Profesor::Profesor(){
	ifstream file;
	file.open (".credenciales.txt");
	
	if (file.is_open()){
		file.close();
	
	}else{
		ofstream file;
		file.open (".credenciales.txt");

		file << "1 coordinador coordinador" << endl;
		file << "0 ayudante1 -" << endl;
		file << "0 ayudante2 -" << endl;
		file << "0 ayudante3 -" << endl;

		file.close();
	}
}

bool Profesor::getRol(string username){
	string user, pass;
	bool rol;

	ifstream myfile;
	myfile.open(".credenciales.txt");

	bool valor;

	while(myfile >> rol >> user >> pass){
		if (username == user){
			valor = rol;
			break;
		}
	}

	myfile.close();

	return valor;
}

void Profesor::changePassword(string username, string password){
	string user, pass;
	bool rol;

	ifstream myfile;
	myfile.open(".credenciales.txt");

	ofstream temp;
	temp.open(".temp.txt");

	while(myfile >> rol >> user >> pass){
		if (username == user)
			temp << rol << " " << user << " " << password << endl;
		else
			temp << rol << " " << user << " " << pass << endl;
	}

	myfile.close();
  	temp.close();

  	remove(".credenciales.txt");				// borrar el original
  	rename(".temp.txt", ".credenciales.txt");  	// renombrar el temporal
}

bool Profesor::checkPassword(string username){
	string user, pass;
	bool rol;

	ifstream myfile;
	myfile.open(".credenciales.txt");

	bool valor = NULL;

	while(myfile >> rol >> user >> pass){
		if (username == user){
			if (pass == "-")
				valor = false;
			else
				valor = true;
			break;
		}		
	}

	myfile.close();

	return valor;
}

bool Profesor::existsUser(string username){
	string user, pass;
	bool rol;

	ifstream myfile;
	myfile.open(".credenciales.txt");

	bool valor = false;

	while(myfile >> rol >> user >> pass){
		if (username == user){
			valor = true;
		}
	}

	myfile.close();

	return valor;
}

bool Profesor::correctData(string username, string password){
	if (!checkPassword(username))
		return false;
	else{

		string user, pass;
		bool rol;

		ifstream myfile;
		myfile.open(".credenciales.txt");

		bool valor = NULL;

		while(myfile >> rol >> user >> pass){
			if (username == user){
				if (pass == password){
					_listStudents = new Agenda;
					valor = true;
				}
				else
					valor = false;
				break;
			}		
		}

		myfile.close();

		return valor;
	}
}





void Profesor::loadData(string fichero){

	ifstream myfile;
	myfile.open(fichero.c_str());

	string apellidos, nombre, fecha, dni, correo, direccion, line;
	int telefono, curso, grupo;
	bool lider;


	while (std::getline(myfile, line)) {  // Read file line by line.
		Alumno alumno;

		std::string field;
		std::vector<std::string> separated_fields;
		std::istringstream iss_line(line);

		while (std::getline(iss_line, field, ',')) { // Split line on the ':' character
			separated_fields.push_back(field);    // Vector containing each field, i.e. name, address...
		}

		// Do something with the results
		alumno.setSurname(separated_fields[0]); 
		alumno.setName(separated_fields[1]); 
		alumno.setDNI(separated_fields[2]); 
		alumno.setAddress(separated_fields[3]); 
		alumno.setTelephone(stoi(separated_fields[4])); 
		alumno.setBirthdate(separated_fields[5]);
		alumno.setEmail(separated_fields[6]); 
		alumno.setCourse(stoi(separated_fields[7])); 
		alumno.setGroup(stoi(separated_fields[8])); 
		alumno.setLeader(stoi(separated_fields[9])); 

		_listStudents->setStudent(alumno);
	}

	myfile.close();

}


void Profesor::saveData(string fichero){

	ofstream file;
	
	file.open (fichero.c_str());

		for (int i = 0; i < _listStudents->sizeStudents(); ++i){
			file << _listStudents->getStudents()[i].getSurname();
			file << ",";
			file << _listStudents->getStudents()[i].getName();
			file << ",";
			file << _listStudents->getStudents()[i].getDNI();
			file << ",";
			file << _listStudents->getStudents()[i].getAddress();
			file << ",";
			file << _listStudents->getStudents()[i].getTelephone();
			file << ",";
			file << _listStudents->getStudents()[i].getBirthdate();
			file << ",";
			file << _listStudents->getStudents()[i].getEmail();
			file << ",";
			file << _listStudents->getStudents()[i].getCourse();
			file << ",";
			file << _listStudents->getStudents()[i].getGroup();
			file << ",";
			file << _listStudents->getStudents()[i].getLeader();
			file << endl;
		}
			

		file.close();
}