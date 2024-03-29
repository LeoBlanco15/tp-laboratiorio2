/*
 * Empleado.h
 *
 *  Created on: 17 sep. 2019
 *      Author: profesor
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
	float salario;
	int sector;
};
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad, float promedio);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ingresarEmpleado(struct sEmpleado aEmpleados[], int i);

int modificarEmpleados(struct sEmpleado aArray[], int mayor);
int bajarEmpleado(struct sEmpleado aArray[], int mayor);
int porcentaje(struct sEmpleado aArray[], int cantidad, float *promedio);
int buscarEmpleadoPorId(struct sEmpleado *aArray, int mayor, int *idSalida);

#endif /* EMPLEADO_H_ */
