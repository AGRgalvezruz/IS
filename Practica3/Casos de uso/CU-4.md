#### Eliminar alumno
**ID**: 004  
**Breve descripción**: El sistema debe permitir eliminar un alumno del listado.

**Actores principales**: Usuario  
**Actores secundarios**: Ninguno

**Precondiciones**:

1. El alumno a eliminar debe existir en el sistema.

**Flujo principal**:

1. Se introducirá el DNI o apellido del alumno a eliminar.
2. Se visualizará los datos actuales de dicho alumno.
3. El usuario seleccionará confirmará dicha operación.
4. Seleccionará la opcion de fin de edición para terminar la operación.

**Postcondiciones**:

* El alumno se eliminará.

**Flujos alternativos**:

1.a. Si se introduce un apellido y hay varios registros con el mismo, aparecerá una lista con todos los alumnos con ese apellido y se seleccionará el deseado a eliminar.
