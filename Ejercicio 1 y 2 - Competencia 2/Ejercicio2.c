#include <stdio.h>

int main(){

	int arrayInt[5];

	for(int i=0; i < 5; i++){

		arrayInt[i] = i;
		printf("En posicion %i se almacena el valor %i \n",i, arrayInt[i]);
	}

	int *punteroInt = arrayInt;

	int *punteroIntDos = &arrayInt[0];


	printf("El valor del primer elemento de arrayInt es: %i \n", arrayInt[0]);

	printf("El valor del primer elemento de punteroInt es: %i \n", punteroInt);

	printf("El valor del primer elemento de punteroIntDos es: %i \n", punteroIntDos);

	printf("El valor del quinto elemento de arrayInt es: %i \n", arrayInt[4]);

	printf("El valor del quinto elemento de punteroInt es: %i \n", punteroInt += 4);

	printf("El valor del quinto elemento de punteroIntDos es: %i \n", punteroIntDos += 4);

	for(int i=0; i < 5; i++){

		punteroInt++;
		printf("El valor del punteroInt en la posicion %i es de %i \n", i, punteroInt);

	}

	for(int i=0; i < 5; i++){

		punteroIntDos += i;
		printf("El valor del punteroIntDos en la posicion %i es de %i \n", i, punteroIntDos);
	}

}