/*
 ============================================================================
 Name        : Clase_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"



int main(void)
{

	struct sEmpleado aEmpleados[1000];
	int menuOpcionElegida;
	int i=0;
	float promedio;

	 do
	 {
		 	menuOpcionElegida= 0;
	        printf("\n1-Ingresar empleado\
	                 \n2-Modificar datos del empleado\
	                 \n3-Baja del empleado\
	                 \n4-Informar\
	                 \n5-Salir\
	                 \nIngrese opcion: ");
	        scanf("%d", &menuOpcionElegida); //pido la respuesta del menu
	        __fpurge(stdin);
	        	switch (menuOpcionElegida)
	        	{
	        	case 1:
	        		ingresarEmpleado(aEmpleados, i); //dar de alta empleado
	        		i++;
	        		break;
	        	case 2:
	        		if(i>0)
	        		{
	        			modificarEmpleados(aEmpleados, i); // modificar empleados
	        		}
	        		else
	        		{
	        			printf("No es una opcion valida\n");
	        		}
	        		break;
	        	case 3:
	        		if(i>0)
	        		{
	        			bajarEmpleado(aEmpleados, i); // elimina el empelado
	        		}
	        		else
	        		{
	        			printf("No es una operacion valida\n");
	        		}
	        		break;
	        	case 4:
	        		if(i>0)
	        		{
	        			ordenarArrayEmpleados(aEmpleados, i); //ordena, calcula promedio e impime
	        			porcentaje(aEmpleados, i, &promedio);
	        			imprimirArrayEmpleados(aEmpleados,i, promedio);
	        		}
	        		else
	        		{
	        			printf("No es una opcion valida\n");
	        		}
	        		break;
	        	case 5:
	        		break;
	        	case 0:
	        		printf("No es una opcion valida\n");
	        		menuOpcionElegida = 5;
	        		break;
	        	default:
	        		printf("No es una opcion valida\n");
	        	}

	        }while (menuOpcionElegida != 5 ); //termina el programa

	return EXIT_SUCCESS;
}




















