#include "scheduler.h"
#include <pthread.h>

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

//Funciones que ejecutan los hilos para mostrar las acciones a realizar.
void *reprod_musica(void *args){ puts("Reproduciendo musica\n");	return NULL;}
void *ver_youtube(void *args){ puts("Abriendo Youtube\n");return NULL;}
void *escribir_en_word(void *args){ puts("Escribiendo un texto en word\n");return NULL;}
void *descarga_archivo(void *args){ puts("Descargando un archivo\n");return NULL;}
void *subir_archivo(void *args){ puts("Subiendo un archivo\n");return NULL;}
void *compilar_programa(void *args){ puts("Compilando un archivo\n");return NULL;}
void *ejecutar_programa(void *args){ puts("Ejecutando el programa\n");return NULL;}
void *usar_terminal(void *args){ puts("Usando la terminal\n");return NULL;}


int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}


void reproducir_musica(void){

	//Declaración del hilo.
	pthread_t proc_music;

	//Creación del hilo.
	pthread_create(&proc_music, NULL, (void *)reprod_musica, NULL);

	//Ejecución del hilo.
	pthread_join(proc_music, NULL);
}

void abrir_youtube(void){

	//Declaración del hilo.
	pthread_t proc_youtube;

	//Creación del hilo.
	pthread_create(&proc_youtube, NULL, (void *)ver_youtube, NULL);

	//Ejecución del hilo.
	pthread_join(proc_youtube, NULL);
}

void escribir_texto_word(void){


	//Declaración del hilo.
	pthread_t proc_word;

	//Creación del hilo.
	pthread_create(&proc_word, NULL, (void *)escribir_en_word, NULL);

	//Ejecución del hilo.
	pthread_join(proc_word, NULL);
}

void descargar_archivo(void){

	//Declaración del hilo.
	pthread_t proc_descarga;

	//Creación del hilo.
	pthread_create(&proc_descarga, NULL, (void *)descarga_archivo, NULL);

	//Ejecución del hilo.
	pthread_join(proc_descarga, NULL);
}

void subiendo_archivo(void){

	//Declaración del hilo.
	pthread_t proc_subir_archivo;

	//Creación del hilo.
	pthread_create(&proc_subir_archivo, NULL, (void *)subir_archivo, NULL);

	//Ejecución del hilo.
	pthread_join(proc_subir_archivo, NULL);
}

void compilando_programa(void){

	//Declaración del hilo.
	pthread_t proc_compilar;

	//Creación del hilo.
	pthread_create(&proc_compilar, NULL, (void *)compilar_programa, NULL);

	//Ejecución del hilo.
	pthread_join(proc_compilar, NULL);
}

void ejecutando_programa(void){

	//Declaración del hilo.
	pthread_t proc_programa;

	//Creación del hilo.
	pthread_create(&proc_programa, NULL, (void *)ejecutar_programa, NULL);

	//Ejecución del hilo.
	pthread_join(proc_programa, NULL);
}

void usando_terminal(void){

	//Declaración del hilo.
	pthread_t proc_terminal;

	//Creación del hilo.
	pthread_create(&proc_terminal, NULL, (void *)usar_terminal, NULL);

	//Ejecución del hilo.
	pthread_join(proc_terminal, NULL);
}
