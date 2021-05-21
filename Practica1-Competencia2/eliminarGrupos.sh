#!/bin/bash
ROOT_UID=0
SUCCESS=0

#Correr como usuario root
if [ "$UID" -ne "$ROOT_UID" ]
then
    echo "Se debe estar como root para ejecutar este script"
    exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
    echo "Debe indicar el archivo del listado con Nombres de grupo a eliminar..."
    exit 1
fi

#Del archivo con el listado de grupos a eliminar:
#Este es el formato
#Ejemplo
#	|
#	f1
#$f1 = nombreGrupo

eliminarGrupo(){

	#echo "---> Eliminar Grupo <---"
	eval nombreGrupo="$1"
	#echo "nombreGrupo		=${nombreGrupo}"
	#echo "------------------------"

	groupdel "${nombreGrupo}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] eliminado correctamente..."
	else
		echo "Grupo [${nombreGrupo}] no se pudo eliminar..."
	fi

}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"
done < ${file}

exit 0
