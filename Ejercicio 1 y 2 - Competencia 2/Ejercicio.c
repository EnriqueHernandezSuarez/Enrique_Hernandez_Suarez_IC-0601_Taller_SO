#include <stdio.h>

int main(){

	int x;
	int *p;

	int y;
	int *puntero;

	x = 10;

	p = &x;

	printf("Puntero \"p\": %i \n", p);

	p += 1;

	printf("Puntero \"p\": %i \n", p);

	p += 2;

	printf("Puntero \"p\": %i \n", p);

	y = 20;

	puntero = &y;

	printf("Puntero \"puntero\": %i \n", puntero);
}