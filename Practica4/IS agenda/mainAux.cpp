#include <iostream>
#include <stdio.h>

#include <string>


#include "main.hpp"
#include "macros.hpp"

#include "profesor.hpp"
#include "agenda.hpp"
#include "alumno.hpp"

int main(){
	//https://apple.stackexchange.com/questions/33736/can-a-terminal-window-be-resized-with-a-terminal-command
cout << '\e[8;80;100t';
	int logIn;

	Profesor profesor;

	do{

		// Se elige la opción del login
		logIn = login();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);


		switch(logIn){
			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
			break;

			case 1: 
				std::cout << "[1] Iniciar sesión." << std::endl;
				if(iniciarSesion(profesor)){
				/////////////////////////////////////////////////////////////////////////////////					
					int opcion;
					
					do{

						// Se elige la opción del menú
						opcion = menu(profesor);		

						std::cout << CLEAR_SCREEN;
						LUGAR(5,1);


						switch(opcion){
							case 0: 
								std::cout << INVERSE;
								std::cout << "Fin del programa" << std::endl;
								std::cout << RESET;
							break;

							case 1: 
								std::cout << "[1] Listado de alumnos." << std::endl;
								listarTodosAlumnos(profesor);
								break;

							case 2: 
								std::cout << "[2] Añadir alumno." << std::endl;
								insertarAlumno(profesor);
								break;

							case 3: 
								std::cout << "[3] Buscar alumno." << std::endl;
								buscarAlumno(profesor);
								break;

							case 4: 
								std::cout << "[4] Buscar grupo." << std::endl;
								buscarGrupo(profesor);
								break;

							case 5: case 6: 
								ficheroSeguridad(profesor, opcion);
								break;

							default:
							    LUGAR(25,25);
									std::cout << INVERSE;
									std::cout << "Opción incorrecta ";
									std::cout << RESET;
							  	std::cout << BRED;
									std::cout << " --> " << opcion << std::endl;
									std::cout << RESET;
				    }
				  
					    if (opcion !=0 and opcion != 5 and opcion != 6){
							 LUGAR(30,25);
							 std::cout << "pulse ----- ";
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
					}while(opcion!=0);
				/////////////////////////////////////////////////////////////////////////////////
				}
				break;

			case 2: 
				std::cout << "[2] Registrarse." << std::endl;
				registrarse(profesor);
				break;


			default:
			    LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  	std::cout << BRED;
					std::cout << " --> " << logIn << std::endl;
					std::cout << RESET;
    }
  
	    if (logIn !=0){
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
	}while(logIn!=0);








/*	do{

		// Se elige la opción del menún
		opcion = menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);


		switch(opcion){
			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
			break;

			case 1: 
				std::cout << "[1] Recursiva para el término n-ésimo de la sucesión de Fibonacci." << std::endl;
				opcion1();
				break;

			case 2: 
				std::cout << "[2] Determinante de una matriz de orden n usando la factorización LU." << std::endl;
				opcion2();
				break;

			case 3: 
				std::cout << "[3] Determinante recursivo de una matriz de orden n." << std::endl;
				opcion3();
				break;

			default:
			    LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  	std::cout << BRED;
					std::cout << " --> " << opcion << std::endl;
					std::cout << RESET;
    }
  
	    if (opcion !=0){
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
	}while(opcion!=0);*/

	return 0;
}


