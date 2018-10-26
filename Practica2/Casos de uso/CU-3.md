#### Editar alumno

**ID**: 004  
**Breve descripción**: El sistema debe permitir al usuario la opcion de editar un alumno.

**Actores principales**: Usuario  
**Actores secundarios**: Ninguno

**Precondiciones**:

1. El alumno a editar debe existir en el sistema.

**Flujo principal**:

1. Se introducirá el DNI del alumno a editar.
2. Se visualizará los datos actuales de dicho alumno.
3. El usuario seleccionará el campo a editar y lo podrá modificar.
4. Seleccionará la opcion de fin de edición para terminar la operación.

**Postcondiciones**:

* El alumno se modificará.

**Flujos alternativos**:

3.a. No se podrá modificar el campo del DNI.  
3.b. Se puede modificar el campo de Correo pero si se introduce uno ya existente, éste no podrá ser modificado por el actual