
**Comandos GitHub**

>Añadir repositorio remoto:

`git  remote  add  origin  url`

>Ver repositorios remotos:

`git  remote  -v`

>Eliminar repositorio remoto:

`git  remote  rm  origin`

>Añadir cambios del repositorio local al remoto:

`git  push -u origin  master`

>Añadir cambios del repositorio remoto al local:

`git  pull`

>Ver branches remotos:

`git  branch  -r`

>Ver todos los branches:

`git  branch  -a`

>Clonar un repositorio remoto:

`git  clone  url`

**Dar seguimiento a branches remotos**

>LOCAL -> REMOTO

* Cambios en el repositorio local.
* Commit de los cambios.
* Añadir cambios a repositorio remoto:

`git  push`

>REMOTO -> LOCAL

* Sincronización y unión:

`git  fetch  origin`

`git  merge  origin/master`

* En un solo paso:

`git  pull`

**Operaciones con branches remotos**

>Creación:

* Crear branch local.
* Hacer cambios en dicho branch.
* Hacer commit.
* Copiar el branch al repositorio remoto:

`git  push -u origin  branch_remoto`

>Copia:

`git  checkout  -b local  remoto`

>Eliminación:

`git  push  origin  --delete  branch_remoto`