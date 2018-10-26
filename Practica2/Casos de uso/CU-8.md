#### Cargar copias de seguridad
**ID**:008  
**Breve descripción:**
El sistema debe permitir al usuario cargar  desde un fichero las copias de seguridad del listado de los alumnos.

**Actores principales:** Usuario  
**Actores secundarios:** Ninguno

**Precondiciones:**

1. Debe existir el fichero a cargar.

**Flujo principal:**

1. El usuario elige la opción de cargar copia de seguridad.
2. El sistema pide el nombre del fichero desde el cual cargar la información.
3. El sistema elimina la información almacenada en ese hasta ese momento y carga la nueva almacenada en el fichero.

**Postcondiciones:**

* El sistema muestra los datos del alumno.

**Flujos alternativos:**

3.a. Si no existe un fichero con dicho nombre se mostrará un mensaje de advertencia.