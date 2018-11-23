#### Añadir alumno
**ID**: 005  
**Breve descripción**: El sistema debe poder insertar los datos de alumnos.

**Actores principales**: Usuario  
**Actores secundarios**: Ninguno

**Precondiciones**:

1. El alumno a introducir no puede existir en la lista.

**Flujo principal**:

1. Se comprueba el número de alumnos en el sistema.
2. Se introducirá el DNI del alumno
3. Se introducirá el correo del alumno
4. Se introducirá el Apellido, Teléfono, Dirección, Curso más alto matriculado, Fecha nacimiento, Grupo de trabajo y si es o no Lider del grupo.

**Postcondiciones**:

* El alumno se insertará en la lista.

**Flujos alternativos**:

1.a. Si hay 150 alumnos registrados se mostrará un mensaje de advertencia.
2.a. Una vez introducido el DNI, el sistema buscará si existe ese DNI para que en ese caso, no se siga introduciendo mas datos.  
3.a. Una vez introducido el correo, el sistema buscará si existe ese correo para que en ese caso, no se siga introduciendo mas datos.

