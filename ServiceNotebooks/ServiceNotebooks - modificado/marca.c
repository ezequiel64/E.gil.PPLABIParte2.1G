#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "notebooks.h"
#include "tipo.h"


//MENUS
void menuMarca(eMarca listMarca[],int tamMarca)
{
system("cls");
printf("*****Listar Marcas*****\n");
    for (int i = 0; i < tamMarca; ++i)
    {
        if (i==0)
        {
        printf("Id Marca     Descripcion\n");
        }
        printf("    %d         %10s\n",listMarca[i].id,listMarca[i].descripcion );
    }

}


//Marca
int cargarDescripcionMarca(char descripcion[],int idMarca,eMarca marca[],int tamMarca)
{
int rta=0;
for (int i = 0; i < tamMarca; ++i)
{
    if (marca[i].id==idMarca)
    {
        strcpy(descripcion,marca[i].descripcion);
        rta=1;
        break;
    }
}
return rta;
}

//listar Marcas


