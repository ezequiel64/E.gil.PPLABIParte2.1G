#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "marca.h"
#include "tipo.h"
#include "notebooks.h"


//MENUS

void menuTipo(eTipo list[],int tamTipo)
{
    system("cls");
    printf("*****Listar Tipo*****\n");
    for (int i = 0; i < tamTipo; ++i)
    {
        if (i==0)
        {
            printf("Id Sector     Descripcion\n");
        }
        printf("    %d         %10s\n",list[i].id,list[i].descripcion);
    }

}

int cargarDescripcionTipo(char descripcion[],int idTipo,eTipo tipo[],int tamTipo)
{
    int rta=0;
    for (int i = 0; i < tamTipo; ++i)
    {
        if (tipo[i].id==idTipo)
        {
            strcpy(descripcion,tipo[i].descripcion);
            rta=1;
            break;
        }
    }

    return rta;
}
