#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Lista{

	Nodo *inicio;
};

typedef struct Nodo{

	char cadena[100];
	Nodo *sig; //EL puntero siguiente que recorre la lista enlazada.
};

Lista *lista_nueva(void);
void insertarEnLista(Lista *L, char cadena[100]);
void imprimirLista(const Lista *L);
void listaLibera(Lista *L);

 

int main(int argc, char *argv[]){

	int n=argc;
	int i;
	int e;
	Lista *L;
	L = lista_nueva();

	//Verificamos si hay suficientes argumentos de entrada para la ejecución.
	if(n<2){

		printf("No hay suficientes parametros de entrada.\n");
	}

	//Estructura FILE
	FILE *ptr;
	FILE *ptr2;

	//Abrimos los archivos en modo de lectura y escritura, respectivamente.
	ptr = fopen(argv[1],"r");
	ptr2 =fopen(argv[2],"w");

	//Mensaje de error si no se puede abrir el archivo.

	if(ptr==NULL){

		perror("Error en la apertura del archivo");
		return 1;
	}

	//Declaración de variables para almacenar el texto del primer archivo y ordenarlo por el metodo de burbuja.

	char aux[20];
	char ordenalfabetico[20][20];
	int ia,ja,ka;
	int l=0;

	//Mientras el archivo no llegue al final, se ejecuta el while
	while(feof(ptr)==0){
		//Guardamos todos los valores en la cadena ordenalfabetico en su respectivo indice.
		insertarEnLista(L,fscanf(ptr, "%s", ordenalfabetico[l]));
		printf("Ingresado correctamente");
		l++;
	}

	//Metodo de ordenamiento de burbuja

	for(ia=0; ia<l-1; ia++) {

        	ka=ia;
        	strcpy(aux, ordenalfabetico[ia]);
        	for(ja=ia+1; ja<l; ja++)
        	{
            		if(strcmp(ordenalfabetico[ja], aux)<0)
            		{
                	ka=ja;

                	strcpy(aux, ordenalfabetico[ja]);
               		//permite hacer una copia auxiliar de la cadena nombre[j];
            		}
        	}
        	strcpy(ordenalfabetico[ka],ordenalfabetico[ia]);
        	strcpy(ordenalfabetico[ia],aux);
    	}
//Impresion de los datos del archivo
	for(ia=0; ia<l; ia++)
    	{
        	printf(" %s",ordenalfabetico[ia]);
        	insertarEnLista(L,fprintf(ptr2,"%s\n",ordenalfabetico[ia]));
        	imprimirLista(L);
        	listaLibera(L);
        	printf("\n");
    }

	

	fclose(ptr);
	printf("\nEl archivo se leyo correctamente.");



	if(ptr2==NULL){
		printf("Error al crear el archivo\n");
		return 0;
	}


	fclose(ptr2);
	printf("\nEl archivo ha sido creado con exito!\n");
	return 0;
	}

Lista *lista_nueva(void){

	Lista *L;
	L = (Lista *) malloc(sizeof(Lista));
	L -> inicio = NULL;
	return L;
}

void insertarEnLista(Lista *L, char cadena[100]){

	Nodo *n, *m;
	if(L->inicio == NULL){
		L->inicio = (Nodo *)malloc(sizeof(Nodo));
		L->inicio->cadena[100] = cadena[100];
		L->inicio->sig = NULL;
	}
	n = L->inicio;
	while(n !=NULL){
		m = n;
		n = n->sig;
	}
	m->sig = (Nodo *)malloc(sizeof(Nodo));
	m->sig->sig = NULL;
	m->sig->cadena[100] = cadena[100];
}

void imprimirLista(const Lista *L){

	Nodo *i;
	for(i = L->inicio; i != NULL; i->sig){

		printf("%s", i->cadena[100]);
		printf("\n");
	}

	
}

void listaLibera(Lista *L){

	if(L->inicio == NULL){
		return;
	}
	Nodo *n,*m, *p;
	while(n != NULL){
		m = n;
		n = n->sig;
	}
	free(m);
	p->sig = NULL;
	listaLibera(L);

}
