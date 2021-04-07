#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

	int ProcNum;
	bool TP; //Tareas Pendientes.


	//Definir numero total de procesos.
	printf("Ingresa el numero de procesos que deseas ejecutar: ");
	scanf("%i", &ProcNum);

	int procID[ProcNum];
	int procPr[ProcNum];
	int procT[ProcNum];


	//Asignación de id, prioridades y tareas a cada proceso.
	for(int i = 0; i < ProcNum; i++){

		procID[i] = i;
		procT[i] = rand() % 31;
		procPr[i] = rand() % 2;
		
	}

	//Ciclo para revisar si hay procesos con tareas pendientes
	for(int i = 0; i < ProcNum; i++){
		if(procT[i] > 0){
			TP = true;
		}
		else{
			printf("\nNo hay mas procesos con tareas pendientes por ejecutar");
			TP = false;
		}
	}

	//Ciclo que ejecute periodicamente cada tarea de los procesos.
	do{

		TP = false;
		//Ejecutar las tareas restantes de acuerdo a la prioridad de los procesos e imprimir la cantidad de tareas restantes de cada proceso.
		for(int i = 0; i < ProcNum; i++){
			if(procT[i] > 0){
				printf("\n Proceso No. %i, tiene %i tareas pendientes.", procID[i], procT[i]);
				TP = true;
				
			}

			//Los procesos con prioridad 0 ejecutarán más tareas que los de prioridad 1.
			if(procPr[i] == 0){
				procT[i] = procT[i] - 5;
			}
			if(procPr[i] == 1){
				procT[i] = procT[i] - 3;
			}

		}


	}while(TP);


	//Revisar si los procesos han terminado de ser ejecutados, de acuerdo a su prioridad.
	for(int i = 0; i < ProcNum; i++){
		if(procPr[i] == 0){
			if(procT[i] <= 0){
				printf("\nProceso No. %i finalizado.", procID[i]);
			}
		}
						
		if(procPr[i] == 1){
			if(procT[i] <= 0){
				printf("\nProceso No. %i finalizado.", procID[i]);
			}
		}
	}
		

	printf("\nTodos los procesos han sido ejecutados. No hay procesos pendientes.");
	return 0;
}