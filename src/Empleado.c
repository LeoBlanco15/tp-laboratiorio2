/*
 * Empleado.c
 *
 *  Created on: 17 sep. 2019
 *      Author: profesor
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"

int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleado;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bEmpleado = aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleado;
				}
				else if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)==0)
				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						bEmpleado = aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=bEmpleado;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}


int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad, float promedio){
	int i;
	int retorno = -1;
	float resultado;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status == 1)
			{

				printf("Id: %d - Nombre: %s - Apellido: %s - salario: %.2f \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido, aEmpleado[i].salario);
				if(aEmpleado[i].salario> promedio)
				{
					resultado= aEmpleado[i].salario - promedio;

					printf("pasa el medio de salario por: %.2f", resultado);
				}
			}
		}
	}
	return retorno;
}
int buscarEmpleadoPorId(struct sEmpleado *aArray, int mayor, int *idSalida){
	int retorno= -1;
	int i=0;
	int id;
	if(aArray != NULL){
		retorno= 0;
		printf("Introducir id: ");
		scanf("%d", &id);
		__fpurge(stdin);
		for(i=0; i< mayor; i++)
		{
			if(aArray[i].idEmpleado == id)
			{
				printf("%d esta en %d",id, i);	//busca al id
				*idSalida= i;
			}
		}

	}

	return retorno;
}
int ingresarEmpleado(struct sEmpleado aEmpleados[], int i){
	int idEmpleado= 0;
	struct sEmpleado bEmpleado;

		getString2(bEmpleado.nombre,"Ingrese el nombre", //pide nombre
					"ERROR", 1, 49, 2);

		getString2(bEmpleado.apellido,"Ingrese el apellido", //pide apellido
							"ERROR", 1, 49, 2);
		getValidFloat("Ingrese salario\n","No es un salario correcto\n", &bEmpleado.salario,0, 10000000,2); //pide salario
		getInt2 ("Ingrese sector 1/50", "Sector no correcto", &bEmpleado.sector, 1, 50, 2);
		bEmpleado.idEmpleado = i; //pone id

		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;



		aEmpleados[i] = bEmpleado;
	return 0;
}
int modificarEmpleados(struct sEmpleado aArray[], int Mayor)
{
	int id;
	int menuOpcionElegida;
	buscarEmpleadoPorId(aArray, Mayor, &id);
	do
	{
		printf("\n1-Modificar nombre\
		        \n2-Modificar apellido\
		        \n3-Modificar salario\
		        \n4-Modificar sector\
		        \n5-Cancelar\
		        \nIngrese opcion: ");
		scanf("%d", &menuOpcionElegida);
	 switch (menuOpcionElegida)
	 {
	 case 1:
		 getString2(aArray[id].nombre,"Ingrese el nombre",
		 					"ERROR", 1, 49, 2);
		 break;
	 case 2:
		 getString2(aArray[id].apellido,"Ingrese el apellido",
		 							"ERROR", 1, 49, 2);
		 break;
	 case 3:
		 getValidFloat("Ingrese salario\n","No es un salario correcto\n", &aArray[id].salario,0, 10000000,2);
		 break;
	 case 4:
		 getInt2 ("Ingrese sector 1/50", "Sector no correcto", &aArray->sector, 1, 50, 2);
		 break;
	 case 5:
		 break;
	 default:
		 printf("Esa no es una opcion valida");
	 }
	}while(menuOpcionElegida != 5);
	 return 0;
}
int bajarEmpleado(struct sEmpleado aArray[], int mayor)
{
	int id;
	struct sEmpleado baja;
	buscarEmpleadoPorId(aArray, mayor, &id);
	baja.status = 2;
	aArray[id]= baja;
	return 0;
}
int porcentaje(struct sEmpleado aEmpleados[], int cantidad, float *promedio)
{
	int retorno=-1;
	float acumulador=0;
	int i;
	if(aEmpleados != NULL)
	{
		retorno= 0;
		for(i=0; i<cantidad; i++)
		{
			acumulador = aEmpleados[i].salario + acumulador;
		}
	*promedio = acumulador /i ;
	printf("El promedio de los salaros es de %.2f \n", acumulador);

	}

	return retorno;
}



