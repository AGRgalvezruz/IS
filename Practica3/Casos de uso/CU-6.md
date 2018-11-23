#### Guardar copias de seguridad
**ID**:006  
**Breve descripción:**
El sistema debe permitir al usuario guardar  en ficheros las copias de seguridad del listado de los alumnos.

**Actores principales:** Usuario  
**Actores secundarios:** Ninguno

**Precondiciones:**

1. Debe haber al menos un alumno registrado en el sistema.

**Flujo principal:**

1. El usuario elige la opción de guardar copia de seguridad.
2. El sistema pide e nombre del fichero en el cual guardar la información.
3.El sistema crea el fichero y guarda la información en él.

**Postcondiciones:**

* El sistema muestra los datos del alumno.

**Flujos alternativos:**

3.a. Si ya existe un fichero con dicho nombre se sobrescribirá la información.
