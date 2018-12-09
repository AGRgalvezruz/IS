
#include <iostream>
#include <string>
#include <cstring> //Para usar memset
#include <string>
#include <stdint.h> // Para usar uint64_t
#include <cassert>
#include <ctime>
#include <vector>
#include <fstream>
#include <stdlib.h>

#include "main.hpp"

#include "macros.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Menu Session /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////// Login Menu /////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
int login(){

	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Login | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10);
		std::cout << BWHITE"[1] Iniciar sesión.";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[2] Registrarse.";

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;
}

	////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////// Menu menu /////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

int menu(Profesor profesor){

	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
	if (profesor.getRol())
			std::cout << BBLUE << "Opciones del menú | Coordinador" << RESET;
		else
			std::cout << BBLUE << "Opciones del menú | Ayudante" << RESET;


	LUGAR(posicion++,10);
	if (profesor.getListStudents()->emptyStudents())
		std::cout << BRED"[1]" << BWHITE " Listado de alumnos";
	else
		std::cout << BWHITE"[1] Listado de alumnos";

	LUGAR(posicion++,10);
	std::cout << BWHITE"[2] Añadir alumno";


	LUGAR(posicion++,10);
	if (profesor.getListStudents()->emptyStudents())
		std::cout << BRED"[3]" << BWHITE " Buscar alumno";
	else
		std::cout << BWHITE"[3] Buscar alumno";


	LUGAR(posicion++,10);
	if (profesor.getListStudents()->emptyStudents())
		std::cout << BRED"[4]" << BWHITE " Buscar grupo";
	else
		std::cout << BWHITE"[4] Buscar grupo";

	LUGAR(posicion++,10);
	std::cout << BWHITE"[5] Copia de información";

	posicion++;

	if (profesor.getRol()){
		LUGAR(posicion++,10);
		std::cout << BWHITE"[6] Copia de seguridad";
	}

	//LUGAR(posicion++,10);
	//std::cout << BYELLOW"[9] Cerrar sesión";

	LUGAR(posicion++,10);
	std::cout << BGREEN << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << BIYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}

	////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////// Menu copy /////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

int copiaFicheroSeguridad(Profesor profesor, int num){

	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Nose | Opciones del menú   ";
		std::cout << RESET;


		if (num == 7){
			LUGAR(posicion++,10);
			std::cout << BWHITE"[1] Cargar información desde fichero.";

			LUGAR(posicion++,10);
			if (profesor.getListStudents()->emptyStudents())
				std::cout << BRED"[2]" << BWHITE " Guardar información en un fichero";
			else
				std::cout << BWHITE"[2] Guardar información en un fichero";
		}else{
			LUGAR(posicion++,10);
			std::cout << BWHITE"[1] Cargar copia de seguridad";

			LUGAR(posicion++,10);
			if (profesor.getListStudents()->emptyStudents())
				std::cout << BRED"[2]" << BWHITE " Guardar copia de seguridad";
			else
				std::cout << BWHITE"[2] Guardar copia de seguridad";
		}
		posicion++;

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Atrás.";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;
}



void ficheroSeguridad(Profesor & profesor, int opcion){
	int info;
	do{				

		// Se elige la opción del menún
		info = copiaFicheroSeguridad(profesor, opcion);		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);


		switch(info){
			case 0:
				break;	
			case 1: 
				if (opcion == 5){
					std::cout << "[1] Cargar información desde fichero." << std::endl;
					cargarDesdeFichero(profesor);
				}else{
					std::cout << "[1] Cargar copia de seguridad." << std::endl;
					//cargarDesdeFichero(profesor);
				}
				break;

			case 2: 
				if (opcion == 5){
					std::cout << "[1] Guardar información en un fichero." << std::endl;
					guardarEnFichero(profesor);
				}else{
					std::cout << "[1] Guardar copia de seguridad." << std::endl;
					//cargarDesdeFichero(profesor);
				}
				break;

			default:
			    LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  	std::cout << BRED;
					std::cout << " --> " << info << std::endl;
					std::cout << RESET;
	}

	    if (info == 1 or info == 2){
			 LUGAR(30,25);
			 std::cout << "pulse ";
			 std::cout << UNDERLINE;
			 std::cout << IYELLOW;
			 std::cout << "ENTER";
			 std::cout << RESET;
			 std::cout << " para ";
			 std::cout << INVERSE;
			 std::cout << "continuar"; 
			 std::cout << RESET;
			 getchar();
			 std::cout << CLEAR_SCREEN;
	    }
	}while(info!=0 and info != 1 and info != 2);
}


	////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////// Menu buscar /////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

int buscarAlumnoMenu(){

	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Buscar Alumno | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10);
		std::cout << BWHITE"[1] Buscar por DNI";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[2] Buscar por apellidos";

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;
}

void buscarAlumno(Profesor & profesor){
	if (profesor.getListStudents()->emptyStudents()){
		LUGAR(13,7);
		cout << BRED "No hay alumnos en la agenda" << RESET << endl;
	}else{

		int info;
		do{				

			// Se elige la opción del menún
			info = buscarAlumnoMenu();		

			std::cout << CLEAR_SCREEN;
			LUGAR(5,1);


			switch(info){
				case 0:
					break;	

				case 1: case 2:
					if (info == 1)
						std::cout << "[1] Buscar por DNI";
					else
						std::cout << "[2] Buscar por Apellidos";

					buscarAlumnoPorAtributo(profesor, info);
					break;

				default:
				    LUGAR(25,25);
						std::cout << INVERSE;
						std::cout << "Opción incorrecta ";
						std::cout << RESET;
				  		std::cout << BRED;
						std::cout << " --> " << info << std::endl;
						std::cout << RESET;
		}

		    if (info == 1 or info == 2){
				 LUGAR(30,25);
				 std::cout << "pulse ";
				 std::cout << UNDERLINE;
				 std::cout << IYELLOW;
				 std::cout << "ENTER";
				 std::cout << RESET;
				 std::cout << " para ";
				 std::cout << INVERSE;
				 std::cout << "continuar"; 
				 std::cout << RESET;
				 getchar();
				 std::cout << CLEAR_SCREEN;
		    }
		}while(info!=0 and info != 1 and info != 2);


	}
}


void buscarAlumnoPorAtributo(Profesor & profesor, int opcion){
	string atributo;
	bool valor = false;

	LUGAR(8,7);
	if(opcion == 1){
		cout << "DNI del alumno: ";
		cin >> atributo;
		valor = profesor.getListStudents()->existsStudentByDNI(atributo);
	}
	else{
		cout << "Apellidos del alumno: ";
		cin >> atributo;
		valor = profesor.getListStudents()->existsStudentBySurname(atributo);
	}
	

	if(valor){
		//vector <int> posicionAlumno = profesor.getListStudents()->studentPosition(atributo);
		operacionesAlumnos(profesor, opcion, atributo);

	}else{
		LUGAR(13,7);
		if (opcion == 1)
			cout << IRED << "El alumno con DNI " << atributo << " no existe en la agenda." << RESET <<endl;
		else
			cout << IRED << "El alumno con Apellido " << atributo << " no existe en la agenda." << RESET <<endl;
	}	

	std::cin.ignore();
}


int operacionesAlumnosMenu(int opcion){
	int op, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
   		if (opcion == 1)
			std::cout << "Alumno por DNI encontrado | Opciones del menú   ";
		else
			std::cout << "Alumno por Apellidos encontrado | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10);
		std::cout << BWHITE"[1] Visualizar alumno";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[2] Editar alumno";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[3] Eliminar alumno";

		posicion++;

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> op;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return op;
}

void operacionesAlumnos(Profesor & profesor, int opcion, string atributo){
	int info;
		do{				

			// Se elige la opción del menún
			info = operacionesAlumnosMenu(opcion);		

			std::cout << CLEAR_SCREEN;
			


			switch(info){
				case 0:
					break;	

				case 1: 
					LUGAR(5,1);
					std::cout << "[1] Visualizar alumno";
					visualizarAlumno(profesor, atributo);
					break;

				case 2:
					LUGAR(2,1);
					std::cout << "[2] Editar alumno";
					editarAlumno(profesor, atributo);
					break;

				case 3:
					LUGAR(5,1);
					std::cout << "[3] Eliminar alumno";
					eliminarAlumno(profesor, atributo);
					break;

				default:
				    LUGAR(25,25);
						std::cout << INVERSE;
						std::cout << "Opción incorrecta ";
						std::cout << RESET;
				  		std::cout << BRED;
						std::cout << " --> " << info << std::endl;
						std::cout << RESET;
		}

		    if (info != 0){
				 LUGAR(30,25);
				 std::cout << "pulse ";
				 std::cout << UNDERLINE;
				 std::cout << IYELLOW;
				 std::cout << "ENTER";
				 std::cout << RESET;
				 std::cout << " para ";
				 std::cout << INVERSE;
				 std::cout << "continuar"; 
				 std::cout << RESET;
				 getchar();
				 std::cout << CLEAR_SCREEN;
		    }
		}while(info!=0);
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Visualizacion menu /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int visualizacionMenu(){

	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Visualizacion | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10);
		std::cout << BWHITE"[1] Terminal";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[2] HTML";

		LUGAR(posicion++,10);
		std::cout << BWHITE"[3] Ambas";

		posicion++;

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;
}


/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Login Session /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool iniciarSesion(Profesor & profesor){
	string user, pass;
	bool valor = false;

	LUGAR(8,7);
	cout << "Nombre de profesor: ";
	cin >> user;
	LUGAR(9,7);
	cout << "Contraseña: ";
	cin >> pass;

	LUGAR(13,7);
	if (profesor.correctData(user, pass)){
		profesor.setUsername(user);
		profesor.setRol(profesor.getRol(user));
		valor = true;
	}else
		cout << IRED << "Profesor o contraseña incorrecta" << RESET <<endl;

	std::cin.ignore();
	
	return valor;
}

void registrarse(Profesor & profesor){
	string user, pass;

	LUGAR(8,7);
	cout << "Nombre de profesor a registrar: ";
	cin >> user;

	if (!profesor.existsUser(user)){ //si no existe el usuario
		LUGAR(13,7);
		cout << IRED << "El profesor " << user << " no existe en el sistema y no puede ser registrado." << RESET <<endl;
	}else{

		if (profesor.checkPassword(user)){ //si ya tiene contraseña asignada
			LUGAR(13,7);
			cout << IRED << "El profesor " << user << " ya tiene una contraseña y no puede ser modificada." << RESET <<endl;
		}else{

			LUGAR(9,7);
			cout << "Asigne su contraseña: ";
			cin >> pass;

			profesor.changePassword(user, pass); //cambiar contraseña
			LUGAR(13,7);
			cout << IGREEN << "Al profesor <" << user << "> se le ha asignado la contraseña <" << pass << ">" << RESET <<endl;
		}
	}
	
	std::cin.ignore();
}




/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Aux Functions /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void cargarDesdeFichero(Profesor & profesor){
	
	if (profesor.getListStudents()->emptyStudents()){
		ifstream file;
		string fichero;

		LUGAR(8,7);
		cout << "Nombre del fichero que contiene la lista de alumnos: ";
		cin >> fichero;

		file.open (fichero.c_str());
		
		LUGAR(13,7);
		if (file.is_open()){
			file.close();
			
			
				profesor.loadData(fichero.c_str());
				cout << IGREEN << "El listado de alumnos ha sido cargado correctamente." << RESET <<endl;


		}else
			cout << IRED << "El fichero \""<< fichero << "\" no existe." << RESET <<endl;

	}else{
		LUGAR(13,7);
		cout << BYELLOW "La lista tiene datos" << RESET << endl;
	}

	std::cin.ignore();
}


void guardarEnFichero(Profesor & profesor){
	if (profesor.getListStudents()->emptyStudents()){
		LUGAR(13,7);
		cout << BRED "No hay alumnos en la agenda" << RESET << endl;
	
	}else{

		string fichero;

		LUGAR(8,7);
		cout << "Nombre del fichero donde guardar la información: ";
		cin >> fichero;

		profesor.saveData(fichero.c_str());
		

		LUGAR(13,7);
		cout << BGREEN "Datos guardados en el fichero <" << fichero << ">" << RESET << endl;

		std::cin.ignore();

	}
}






void insertarAlumno(Profesor & profesor){

	Alumno alumno;
	string dni, correo, nombre, apellidos, direccion, fecha;
	int pos = 8, telefono, curso, grupo;
	bool lider;

	LUGAR(pos,7);	cout << "DNI -> ";	cin >> dni;
	LUGAR(pos++,7);	cout << "Email -> ";	cin >> correo;
	LUGAR(pos++,7);	cout << "Nombre -> ";	cin >> nombre;
	LUGAR(pos++,7);	cout << "Apellidos -> ";	cin >> apellidos;
	LUGAR(pos++,7);	cout << "Dirección -> ";	cin >> direccion;
	LUGAR(pos++,7);	cout << "Teléfono -> ";	cin >> telefono;
	LUGAR(pos++,7);	cout << "Fecha nacimiento -> ";	cin >> fecha;
	LUGAR(pos++,7);	cout << "Curso mas alto matriculado -> ";	cin >> curso;
	LUGAR(pos++,7);	cout << "Grupo -> ";	cin >> grupo;
	LUGAR(pos++,7);	cout << "Lider -> ";	cin >> lider;

	alumno.setDNI(dni);
	alumno.setEmail(correo);
	alumno.setName(nombre);
	alumno.setSurname(apellidos);
	alumno.setAddress(direccion);
	alumno.setTelephone(telefono);
	alumno.setBirthdate(fecha);
	alumno.setCourse(curso);
	alumno.setGroup(grupo);
	alumno.setLeader(lider);

	profesor.getListStudents()->insertStudent(alumno);

	LUGAR(13,7);
	cout << BGREEN "Alumno insertado correctamente en la agenda" << RESET << endl;

	std::cin.ignore();

}

void listarTodosAlumnos(Profesor & profesor){
	if (profesor.getListStudents()->emptyStudents()){
		LUGAR(13,7);
		cout << BRED "No hay alumnos en la agenda" << RESET << endl;
	}
	else
		profesor.getListStudents()->printAllStudents();
}









void visualizarAlumno(Profesor & profesor, string atributo){
	int info;
		do{				

			// Se elige la opción del menún
			info = visualizacionMenu();		

			vector <int> posicionAlumno = profesor.getListStudents()->studentPosition(atributo);

			std::cout << CLEAR_SCREEN;
			LUGAR(5,1);


			switch(info){
				case 0:
					break;	

				case 1: 
					std::cout << "[1] Terminal";
					LUGAR(8,7);
					for (int i=0; i < posicionAlumno.size(); i++){
						profesor.getListStudents()->printStudent(profesor.getListStudents()->getStudents()[posicionAlumno[i]]);
					}
					break;

				case 2:
					std::cout << "[2] HTML";
					html(profesor, posicionAlumno);
					break;

				case 3:
					std::cout << "[3] Ambas";
					LUGAR(8,7);
					for (int i=0; i < posicionAlumno.size(); i++){
						profesor.getListStudents()->printStudent(profesor.getListStudents()->getStudents()[posicionAlumno[i]]);
					}
					html(profesor, posicionAlumno);

					break;

				default:
				    LUGAR(25,25);
						std::cout << INVERSE;
						std::cout << "Opción incorrecta ";
						std::cout << RESET;
				  		std::cout << BRED;
						std::cout << " --> " << info << std::endl;
						std::cout << RESET;
		}

		    if (info != 0){
				 LUGAR(30,25);
				 std::cout << "pulse ";
				 std::cout << UNDERLINE;
				 std::cout << IYELLOW;
				 std::cout << "ENTER";
				 std::cout << RESET;
				 std::cout << " para ";
				 std::cout << INVERSE;
				 std::cout << "continuar"; 
				 std::cout << RESET;
				 getchar();
				 std::cout << CLEAR_SCREEN;
		    }
		}while(info!=0);
}


int editarAlumnoMenu(Profesor & profesor, string atributo){
		int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Editar | Opciones del menú   ";
		std::cout << RESET;

		vector <int> posicionAlumno = profesor.getListStudents()->studentPosition(atributo);

		cout << "<" << posicionAlumno.size() << ">" << endl;
		for (int i = 0; i < posicionAlumno.size(); i++){
				LUGAR(posicion++,10);
				cout << "[" << i+1 <<"] "; profesor.getListStudents()->printStudent(profesor.getListStudents()->getStudents()[posicionAlumno[i]]);
			}

		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;
}

int modificarAtributoAlumnoMenu(Profesor & profesor, Alumno actual, Alumno editado){


	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=6;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(4,10);
   		std::cout << BBLUE;
		std::cout << "Campo a modificar | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10); cout << "[1] Nombre";
		LUGAR(posicion++,10); cout << "[2] Apellidos";
		LUGAR(posicion++,10); cout << "[3] Dirección";
		LUGAR(posicion++,10); cout << "[4] Teléfono";
		LUGAR(posicion++,10); cout << "[5] Fecha nacimento";
		LUGAR(posicion++,10); cout << "[6] Curso";
		LUGAR(posicion++,10); cout << "[7] Grupo";
		LUGAR(posicion++,10); cout << "[8] Lider";
		LUGAR(posicion++,10); cout << BCYAN"[9] Guardar modificación" RESET;


		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";
		posicion++;
		LUGAR(posicion++,10);
		cout << BWHITE; profesor.getListStudents()->printStudent(actual);
		posicion++;
		LUGAR(posicion++,10);
		cout << BCYAN; profesor.getListStudents()->printStudent(editado);
		cout << RESET;

		posicion++;

		LUGAR(22,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;

}


void modificarAtributoAlumnoMenuImagen(Profesor & profesor, Alumno actual, Alumno editado){


	int posicion;

		// Se muestran las opciones del menú
		posicion=6;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(4,10);
   		std::cout << BBLUE;
		std::cout << "Campo a modificar | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10); cout << "[1] Nombre";
		LUGAR(posicion++,10); cout << "[2] Apellidos";
		LUGAR(posicion++,10); cout << "[3] Dirección";
		LUGAR(posicion++,10); cout << "[4] Teléfono";
		LUGAR(posicion++,10); cout << "[5] Fecha nacimento";
		LUGAR(posicion++,10); cout << "[6] Curso";
		LUGAR(posicion++,10); cout << "[7] Grupo";
		LUGAR(posicion++,10); cout << "[8] Lider";
		LUGAR(posicion++,10); cout << BCYAN "[9] Guardar modificación" RESET;


		LUGAR(posicion++,10);
		std::cout << BGREEN << "[0] Salir";
		posicion++;
		LUGAR(posicion++,10);
		cout << BWHITE; profesor.getListStudents()->printStudent(actual);
		posicion++;
		LUGAR(posicion++,10);
		cout << BCYAN; profesor.getListStudents()->printStudent(editado);
		cout << RESET;

}


void editarAlumno(Profesor & profesor, string atributo){
	int info, posicion = 4, num;
		do{				

			info = editarAlumnoMenu(profesor, atributo);	
			std::cout << CLEAR_SCREEN;

			vector <int> posicionAlumno = profesor.getListStudents()->studentPosition(atributo);

			if (info > 0 and info <= posicionAlumno.size()){
				int num;
				
					string nombre, apellidos, direccion, fecha;
					int telefono, curso, grupo;
					bool lider;

					Alumno actual = profesor.getListStudents()->getStudent(posicionAlumno[info-1]);
					Alumno editado = profesor.getListStudents()->getStudent(posicionAlumno[info-1]);

				do{				

					std::cout << CLEAR_SCREEN;
					// Se elige la opción del menún

					num = modificarAtributoAlumnoMenu(profesor, actual, editado);		

					

					switch(num){
						case 0:
							break;	

						case 1:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nuevo nombre: "<<RESET; cin >> nombre;
							editado.setName(nombre);
							break;

						case 2:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nuevo apellidos: "<<RESET; cin >> apellidos;
							editado.setSurname(apellidos);
							break;

						case 3:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nueva direccion: "<<RESET; cin >> direccion;
							editado.setAddress(direccion);
							break;

						case 4:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nuevo teléfono: "<<RESET; cin >> telefono;
							editado.setTelephone(telefono);
							break;

						case 5:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nueva fecha de nacimiento: "<<RESET; cin >> fecha;
							editado.setBirthdate(fecha);
							break;

						case 6:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nuevo curso mas alto matriculado: "<<RESET; cin >> curso;
							editado.setCourse(curso);
							break;

						case 7:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Nuevo grupo: "<<RESET; cin >> grupo;
							editado.setGroup(grupo);
							break;

						case 8:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							LUGAR(22,20);
							cout << BYELLOW << "Lider (1 si - 0 no): "<<RESET; cin >> lider;
							editado.setLeader(lider);
							break;

						case 9:
							modificarAtributoAlumnoMenuImagen(profesor, actual, editado);
							profesor.getListStudents()->deleteStudent(actual);
							profesor.getListStudents()->setStudent(editado);

							LUGAR(22,20);
							cout << BGREEN << "Alumno editado correctamente"<<RESET;
							std::cin.ignore();

							break;

						default:
						    LUGAR(25,25);
						    std::cout << CLEAR_SCREEN;
							std::cout << INVERSE;
							std::cout << "Opción incorrecta ";
							std::cout << RESET;
					  		std::cout << BRED;
							std::cout << " --> " << num << std::endl;
							std::cout << RESET;
				}

				    if (num != 0){
						 LUGAR(30,25);
						 std::cout << "pulse ";
						 std::cout << UNDERLINE;
						 std::cout << IYELLOW;
						 std::cout << "ENTER";
						 std::cout << RESET;
						 std::cout << " para ";
						 std::cout << INVERSE;
						 std::cout << "continuar"; 
						 std::cout << RESET;
						 getchar();
						 std::cout << CLEAR_SCREEN;
				    }
				}while(num!=0 and num!=9);


			}else if (info < 0 and info > posicionAlumno.size()){
				LUGAR(25,25);
				std::cout << INVERSE;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
		  		std::cout << BRED;
				std::cout << " --> " << info << std::endl;
				std::cout << RESET;
			}	
		    if (info != 0){
				 LUGAR(30,25);
				 std::cout << "pulse ";
				 std::cout << UNDERLINE;
				 std::cout << IYELLOW;
				 std::cout << "ENTER";
				 std::cout << RESET;
				 std::cout << " para ";
				 std::cout << INVERSE;
				 std::cout << "continuar"; 
				 std::cout << RESET;
				 getchar();
				 std::cout << CLEAR_SCREEN;
		    }
		}while(info!=0);
}

int borrarMenu(Profesor & profesor, Alumno actual){


	int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=6;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(4,10);
   		std::cout << BBLUE;
		std::cout << "Campo a modificar | Opciones del menú   ";
		std::cout << RESET;


		LUGAR(posicion++,10); cout << "[1] Si";
		LUGAR(posicion++,10); cout << "[0] No";


		posicion++;
		LUGAR(posicion++,10);
		cout << BWHITE; profesor.getListStudents()->printStudent(actual);


		LUGAR(22,20);
		std::cout << BIYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
    	std::cin.ignore();

		return opcion;

}

void eliminarAlumno(Profesor & profesor, string atributo){
	int info, posicion = 4, num;
		do{				

			info = editarAlumnoMenu(profesor, atributo);	

			vector <int> posicionAlumno = profesor.getListStudents()->studentPosition(atributo);

			std::cout << CLEAR_SCREEN;


			if (info > 0 and info <= posicionAlumno.size()){
				int num;
				

					Alumno actual = profesor.getListStudents()->getStudent(posicionAlumno[info-1]);


				do{				

					
					// Se elige la opción del menún

					num = borrarMenu(profesor, actual);		

					std::cout << CLEAR_SCREEN;
					
					LUGAR(5,1);
					switch(num){
						case 0:
							break;	

						case 1:
							std::cout << "[1] Eliminado." << std::endl;
							LUGAR(13,7);
							cout << BGREEN << "Alumno con DNI " << actual.getDNI() << " eliminado correctamente"<<RESET;
							profesor.getListStudents()->deleteStudent(actual);
							
							std::cin.ignore();

							break;

						default:
						    LUGAR(25,25);
						    std::cout << CLEAR_SCREEN;
							std::cout << INVERSE;
							std::cout << "Opción incorrecta ";
							std::cout << RESET;
					  		std::cout << BRED;
							std::cout << " --> " << num << std::endl;
							std::cout << RESET;
				}

				    if (num != 0){
						 LUGAR(30,25);
						 std::cout << "pulse ";
						 std::cout << UNDERLINE;
						 std::cout << IYELLOW;
						 std::cout << "ENTER";
						 std::cout << RESET;
						 std::cout << " para ";
						 std::cout << INVERSE;
						 std::cout << "continuar"; 
						 std::cout << RESET;
						 getchar();
						 std::cout << CLEAR_SCREEN;
				    }
				}while(num!=0 and num!=1);


			}else if (info < 0 and info > posicionAlumno.size()){
				LUGAR(25,25);
				std::cout << INVERSE;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
		  		std::cout << BRED;
				std::cout << " --> " << info << std::endl;
				std::cout << RESET;
			}	
		    if (info != 0){
				 LUGAR(30,25);
				 std::cout << "pulse ";
				 std::cout << UNDERLINE;
				 std::cout << IYELLOW;
				 std::cout << "ENTER";
				 std::cout << RESET;
				 std::cout << " para ";
				 std::cout << INVERSE;
				 std::cout << "continuar"; 
				 std::cout << RESET;
				 getchar();
				 std::cout << CLEAR_SCREEN;
		    }
		}while(info!=0);
}
void buscarGrupo(Profesor & profesor){
	if (profesor.getListStudents()->emptyStudents()){
		LUGAR(13,7);
		cout << BRED "No hay alumnos en la agenda" << RESET << endl;
	}
}

void html(Profesor & profesor, vector <int>  posicionAlumno){
	cout <<"hola" << endl;
}