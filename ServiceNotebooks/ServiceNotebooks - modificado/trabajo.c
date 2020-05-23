#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "notebooks.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"

int altaTrabajo(eTrabajo trabajo[],int tamtrabajo, eNotebook notebook[] ,int tamNote,eServicio servicio[] ,int tamServ,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo,int id,eCliente cliente[],int tamCliente)

{
int rta,indice;
char salir='n';
eTrabajo auxTrabajo;

do
{
rta=0;
switch(menuAltaTrabajo())
{
	case 1:
		mostrarNotebooks(notebook,tamNote,marca,tamMarca,tipo,tamTipo,cliente,tamCliente);
		system("pause");
		break;
	case 2:
		mostrarServicios(servicio,tamServ);
		system("pause");
		break;

	case 3:
	auxTrabajo.isEmpty=0;
	auxTrabajo.id=id;
	if (-1<(indice=buscarLibreTrabajo(trabajo,tamtrabajo)))
	{
	if ((getInt(&auxTrabajo.idNotebook,2,100,200,"Ingrese un Id de notebook.\nRango predefinido entre 100 y 200: ","Error. Ingrese un Id de notebook.\nRango predefinido entre 100 y 200: ")))
	{
	    printf("\n------------------------------------\n");
		if (-1<(buscarNotebook(notebook,tamNote,auxTrabajo.idNotebook)))
		{
			if ((getInt(&auxTrabajo.idServicio,2,20000,20003,"Ingrese Id del servicio que desea realizar.\nRango predefinido entre 20000 y 20003: ","Error. Ingrese Id del servicio que desea realizar.\nRango predefinido entre 20000 y 20003: ")))
			{
			    printf("\n------------------------------------\n");
				if (-1<(buscarServicio(servicio,tamServ,auxTrabajo.idServicio)))
				{
				if (getInt(&auxTrabajo.fecha.dia,2,1,31,"Ingrese dia inicio de trabajo.\n\nValores permitidos entre 1 y 31: ","\nIngrese dia inicio de trabajo. "))
                        {printf("\n------------------------------------\n");
                            if (getInt(&auxTrabajo.fecha.mes,2,1,12,"Ingrese mes de inicio de trabajo.\n\nValores permitidos entre 1 y 12: ","\nError. Vuelva a intentarlo.\n\nValores permitidos entre 1 y 12: "))
                            {printf("\n------------------------------------\n");
                                if (getInt(&auxTrabajo.fecha.anio,2,1985,2020,"Ingrese anio de inicio de trabajo.\n\nValores permitidos entre 1985 y 2020 anios: ","\nError. Vuelva a intentarlo.\n\nValores permitidos entre 1985 y 2020: "))
                                {printf("\n------------------------------------\n");
                            	trabajo[indice]=auxTrabajo;
                            	rta = 1;
                            	}else
                            		printf("Fecha mal cargada.\n");
                            }else
                            	printf("Fecha mal cargada.\n");
                        }else
                        	printf("Fecha mal cargada.\n");
				}else
					printf("El id de servicio no existe.\nVuelva a intentarlo.");
			}else
				printf("Ocurrio un error con el ingreso de datos.\nVuelva a intentarlo");
		}else
			printf("El id de notebook no existe.\nVuelva a intentarlo.");
	}else
		printf("Ocurrio un error con el ingreso de datos.\nVuelva a intentarlo");
	}else
		printf("No hay espacio disponible para ingresar un nuevo trabajo.\n");
		system("pause");
		break;

	case 4:
	if(!getChar(&salir,2,1,'s','n',"Confirma salir (S/N): ","Error.Confirma salir (S/N): "))
	{
		printf("La opcion ingresada es incorrecta.\n");
		system("pause");
	}
		break;

	default:
	printf("La opcion ingresada no existe.\n");
	system("pause");
		break;

}
if (rta)
{
	if(!getChar(&salir,2,1,'s','n',"Desea salir de alta trabajos?\nS para salir\nN para ingresar otro alta. ","Desea salir de alta trabajos?\nS para salir\nN para ingresar otro alta. "))
	{
		printf("La opcion ingresada es incorrecta.\n");
		printf("Se devuelve al menu de altas trabajos\n");
		system("pause");
	}
}
system("cls");
}while(salir != 's');

return rta;
}


int menuAltaTrabajo(void)
{
	int op=0;
printf("1)Lista de notebooks.\n");
printf("2)Lista de servicios.\n");
printf("3)Alta de trabajo.\n");
printf("4)Salir.\n");
getInt(&op,2,1,4,"Ingrece opcion: ","Error. Ingrece opcion: ");
return op;
}

int buscarLibreTrabajo(eTrabajo trabajo[],int tam)
{
    int rta=-1;
    for (int i = 0; i < tam; ++i)
    {
        if (trabajo[i].isEmpty)
        {
            rta = i;
            break;
        }
    }
    return rta;
}


void inicializarTrabajo(eTrabajo trabajo[],int tam,int indice)
{
    for (int i = indice; i < tam; ++i)
    {
        trabajo[i].isEmpty = 1;
    }
}


void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajo,eNotebook notebook[],int tamNote,eServicio servicio[] ,int tamServ)
{
    int flag=0;
system("cls");
printf("*****Listados de trabajos*****\n");

for (int i = 0; i < tamTrabajo; ++i)
{
	if (!trabajos[i].isEmpty)
	{
		if (!flag)
		{
		printf("Id     Id NoteBook      Servicio      precio       Fecha\n");
		flag=1;
		}
		mostrarTrabajo(trabajos[i],notebook,tamNote,servicio,tamServ);
	}
}
if (!flag)
{
	printf("No hay Trabajos que listar.\n");
}
printf("\n\n");
}



void mostrarTrabajo(eTrabajo trabajos,eNotebook notebook[],int tamNote,eServicio servicio[] ,int tamServ)
{
char descripServ[25];
float precioServ;
	cargarDescripcionServicios(descripServ,trabajos.idServicio,servicio,tamServ);
	cargarPrecioServicio(&precioServ,trabajos.idServicio,servicio,tamServ);

printf("%d          %d       %10s       %.2f     %02d/%02d/%4d\n",trabajos.id,trabajos.idNotebook,descripServ,precioServ,trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);

}
