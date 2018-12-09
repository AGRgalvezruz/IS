
#ifndef _MAIN_
#define _MAIN_


#include <cstring> //Para usar memset
#include <string>
#include <stdint.h> // Para usar uint64_t
#include <cassert>
#include <ctime>
#include <vector>
#include <fstream>

#include "profesor.hpp"
#include "agenda.hpp"
#include "alumno.hpp"

int login();
int menu(Profesor profesor);
int copiaFicheroSeguridad(Profesor profesor, int num);

int buscarAlumnoMenu();
void buscarAlumnoOperaciones(Profesor & profesor, int opcion);

void buscarAlumnoPorAtributo(Profesor & profesor, int opcion);
void operacionesAlumnos(Profesor & profesor, int opcion, string atributo);
int operacionesAlumnosMenu(int opcion);
int visualizacionMenu();


void ficheroSeguridad(Profesor & profesor, int opcion);

bool iniciarSesion(Profesor & profesor); //*

void registrarse(Profesor & profesor); //*

void cargarDesdeFichero(Profesor & profesor); //*

void guardarEnFichero(Profesor & profesor); //*

int editarAlumnoMenu(Profesor & profesor, vector <int>  posicionAlumno);
int modificarAtributoAlumnoMenu(Profesor & profesor, Alumno actual, Alumno editado);
void modificarAtributoAlumnoMenuImagen(Profesor & profesor, Alumno actual, Alumno editado);

void html(Profesor & profesor, vector <int>  posicionAlumno);



void listarTodosAlumnos(Profesor & profesor);
void insertarAlumno(Profesor & profesor);

void buscarAlumno(Profesor & profesor);

void visualizarAlumno(Profesor & profesor, string atributo);
void editarAlumno(Profesor & profesor, string atributo);
int borrarMenu(Profesor & profesor, Alumno actual);
void eliminarAlumno(Profesor & profesor, string atributo);

void buscarGrupo(Profesor & profesor);
void copiaSeguridad(Profesor & profesor);

#endif

