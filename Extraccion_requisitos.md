## Entrevista con el cliente:

>¿En qué lenguaje debe implementarse el proyecto?

* Se deberá implementar en C++	

>¿Tipo de documentación del proyecto?

* La documentación se realizará en Markdown

>¿Cuales son las funcionalidades básicas que desea que tenga el proyecto?

* El sistema deberá poder listar los contactos de los alumnos.(ordenado o por nombre o por DNI o por apellido o por curso mas alto que esta matriculado ascendente o descendentemente)

* Se deberá poder visualizar los datos de los alumnos(DNI, Nombre, Apellidos, tlf, email, dirección postal (calle), curso mas alto matriculado, fecha de nacimiento, equipo al que pertenece, líder o no líder(importante).) 

* El sistema debe poder buscar un alumno por DNI o Apellido(mínimo).

* El sistema debe permitir editar los datos de un alumno.

* El sistema debe permitir la búsqueda por grupo.

* El sistema debe permitir eliminar un alumno tanto por DNI como por Apellido.

>¿En qué sistemas operativos tendrá que tener funcionalidad el proyecto?

* El sistema tiene que funcionar en Linux.

>¿Que tipo de interfaz debe tener el proyecto?

* Como interfaz gráfica obligatoria tendrá linea de comandos, como opcional cualquiera.

>¿Que tipo de seguridad debe tener el proyecto?

* La seguridad se delega al sistema operativo

>¿Hay campos obligatorios en cuanto a la información de los alumnos?

* Sí, los campos obligatorios son todos menos el equipo y si es líder o no.

>¿Qué ocurriría si encontramos a dos personas o más con el mismo apellido?

* Si hay dos personas con el mismo apellido se pediría el DNI o se daría al usuario un listado de los alumnos con los mismos apellidos

>¿Qué se mostrará al iniciar el proyecto?

* Al iniciar se mostrará un menú

>¿Puede ser multilenguaje?

* Sí

>¿Cómo de difícil será la implementación del software?

* Será un software sencillo

>¿Se utilizarán copias de seguridad?

* Sí, se debe poder crear copias de seguridad, cargarlas y guardarlas.

>¿Cuantos alumnos se podrán registrar?

* Máximo 150 alumnos

>¿Cuantos lideres hay en cada grupo?

* Un grupo como máximo tiene un líder

>¿Pueden existir alumnos con el mismo email?

* No pueden tener ni mismo email ni mismo DNI.

>¿Como desea mostrar los alumnos?

* Los alumnos se pueden mostrar o por lineas de comandos o con fichero Markdown o fichero HTML.

----


## Datos a almacenar en la aplicación
>Se almacenarán los siguientes datos en la aplicación sobre los alumnos registrados:

1. DNI
2. Nombre
3. Apellidos
4. Número de teléfono
5. Correo electrónico
6. Dirección
7. Código postal
8. Curso mas alto matriculado
9. Fecha de nacimiento
10. Equipo al que pertenece
11. Líder de equipo

----
## Requisitos Funcionales

* **RF-1:** El sistema debe poder listar los contactos de los alumnos (ordenado o por nombre o por DNI o por apellido o por curso mas alto matriculado de forma ascendente o descendente)

* **RF-2:** Se deberá poder visualizar los datos de los alumnos

* **RF-3:** El sistema podrá buscar un alumnos por DNI o por apellido

* **RF-4:** El sistema debe poder editar los datos de un alumno

* **RF-5:** El sistema debe permitir la búsqueda por grupo

* **RF-6:** El sistema debe permitir eliminar un alumno tanto por DNI como por apellido

* **RF-7:** Los campos obligatorios sobre la información de los contactos son todos menos equipo y si son líder o no

* **RF-8:** En caso de que una búsqueda por apellidos y aparezcan varios registros, dará opción a seleccionar el deseado

* **RF-9:** El sistema debe poder crear copias de seguridad, guardarlas y cargarlas

* **RF-10:** El sistema mostrará la información mediante la linea de comandos o html o ambas

----

## Requisitos No Funcionales

* **RNF-1:** El proyecto se tiene que implementar en C++

* **RNF-2:** La documentación debe de realizarse en lenguaje Markdown

* **RNF-3:** El sistema debe funcionar en Linux

* **RNF-4:** El sistema deberá incorporar como interfaz gráfica la linea de comandos y como opcional cualquiera

* **RNF-5:** La seguridad de los datos se delega al sistema operativo

* **RNF-6:** Si se añade un DNI o correo ya existente, el software dará un aviso de que no se puede insertar o modificar dicho alumno


* **RNF-7:** Al iniciar el programa se mostrará un menú

* **RNF-8:** La capacidad máxima de alumnos registrados será de 150

* **RNF-9:** Un grupo puede tener como máximo un líder


----

## Prioridad de requisitos funcionales:

* **Prioridad 1:** RF-7.

* **Prioridad 2:** RF-9.

* **Prioridad 3:** RF-8.

* **Prioridad 4:** RF-4, RF-6.

* **Prioridad 5:** RF-1, RF-2, RF-3, RF-5, RF-10.

----

