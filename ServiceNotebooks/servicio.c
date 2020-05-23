#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "notebooks.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"


void mostrarServicios(eServicio servicio[],int tam)
{
    int flag = 0;
    system("cls");
printf("*****Listar Servicios*****\n");
for (int i = 0; i < tam; ++i)
{
	if (!flag)
	{
		flag = 1;
		printf("  Id          Servicio        Precio\n");
	}
	printf("%d     %15s     %.2f\n",servicio[i].id,servicio[i].descripcion,servicio[i].precio);

}

}

int buscarServicio(eServicio servicio[],int tam,int idx)
{
    int rta=0;
    for (int i = 0; i < tam; ++i)
    {
        if (servicio[i].id==idx)
        {
            rta = i;
            break;
        }

    }
    return rta;
}


int cargarDescripcionServicios(char descripcion[],int idServi,eServicio servicio[],int tamServi)
{
    int rta=0;
    for (int i = 0; i < tamServi; ++i)
    {
        if (servicio[i].id==idServi)
        {
            strcpy(descripcion,servicio[i].descripcion);
            rta=1;
            break;
        }
    }

    return rta;
}

int cargarPrecioServicio(float* precio,int id,eServicio servicio[] ,int tamServ)
{
    int rta=0;
    for (int i = 0; i < tamServ; ++i)
    {
        if (servicio[i].id==id)
        {
            *precio = servicio[i].precio;
            rta=1;
            break;
        }
    }
    return rta;
}
