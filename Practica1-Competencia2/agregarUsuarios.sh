#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo ">>>Debe indicar el archivo del listado con Nombres de los usuarios que se desean Ingresar<<<"
   exit 1
fi
# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# usuario:90-Enrique:575:0:BO-P ENRIQUE Hernandez:/home/ejemplo/:/bin/bash
#    |         |      |  |            |                 |            | 
#    f1       f2      f3 f4           f5                f6           f7
#$f1 = nombreUsuario
#$f2 = pasword     *Por defecto es el nombre del usuario, pero cambia al iniciar la sesion
#$f3 = UserID  *Se puede dejar en blanco
#$f4 = GroupID    *Debe existir en etc/group
#$f5 = UserIDInfo
#$f6 = homeDirectory
#$f7 = commandShell

agregarUsuario()
{
	echo "----> Ingreso de Usuarios <----"
	echo "-------------------------------"

	eval username="$1"
	eval password="$2"
	eval UserID="$3"
	eval GroupID="$4"
	eval UserIDInfo="$5"
	eval homeDirectory="$6"
	eval comandShell="$7"

	#Si el usuario ya ha sido agregado, no lo agregará
	if grep -q "${username}" /etc/passwd
	then
	    echo "!!!EL usuario [${username}] ya ha sido agregado...!!!"
	else

	    if grep -i "${GroupID}" /etc/group #Comprobamos que el grupo exista
	    then

     	        useradd "${username}" -p "${password}" -u "${UserID}" -g "${GroupID}" -c "${UserIDInfo}" -d "${homeDirectory}" -s "${comandShell}"

		#Validamos el inicio de sesion con la contraseña que le dimos al usuario 
	        echo  "$username:$password" | chpasswd --md5

		#Forzamos el cambio de contraseña la proxima vez que se inicie sesión
	        chage -d0  "${username}"

	        if [ $? -eq $SUCCESS ];
	        then
	            echo "---->Usuario [${username}] ha sido agregado correctamente<---"
	        fi
	    else
	        echo "!!!El grupo [${GroupID}] no existe, por lo que no fue agregado el usuario [${username}]!!!}"
	    fi
	fi
}


while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do

    agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}

exit 0
