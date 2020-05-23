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
#include "cliente.h"

int cargarNombreCliente(char descripcion[] ,int idCliente,eCliente cliente[] ,int tam)
{
int rta=0;
for (int i = 0; i < tam; ++i)
{
    if(cliente[i].id == idCliente)
    {
        strcpy(descripcion,cliente[i].nombre);
        rta=1;
        break;
    }
}
 return rta;
}
