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
#include "informes.h"
#include "cliente.h"


#define TAMNOTE 6
#define TAMTIPO 4
#define TAMM 4
#define TAMSERV 4
#define HARDCTIPO 4
#define HARDMARCA 4
#define HARDSERV 4
#define TAMHARD 4
#define TAMTRABAJO 6
#define TAMCLIENT 6

int main()
{

    eNotebook notebooks[TAMNOTE];
    eCliente clientes[TAMCLIENT] = {{200,"Ezequiel",'m'},{201,"Ludmila",'f'},{202,"Claudia",'f'},{203,"Federico",'m'}};
    eTipo tipos[TAMTIPO]= {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normalita"}};
    eMarca marcas[TAMM] = {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"}};
    eServicio servicios [TAMSERV] = {{20000,"Bateria", 250}, {20001,"Antivirus", 300}, {20002,"Actualizacion", 400},{20003,"Fuente", 600}};
    eTrabajo trabajos[TAMTRABAJO] = {{1,100,20000,{20,10,2020},0},{2,100,20000,{20,10,2020},0},{3,103,20003,{1,5,2019},0},{4,102,20002,{19,1,2020},0}};

    char salir='n';
    int proxId=100,indice,idTrabajo=1;

    inicializarNotebook(notebooks,TAMNOTE);
    hardcodeNotebook(notebooks,TAMHARD);
    inicializarTrabajo(trabajos,TAMTRABAJO,TAMTRABAJO);
    idTrabajo+=TAMTRABAJO;
    proxId+=TAMHARD;


    printf("******Gestion Notebook******\n");
    do
    {

        switch(menuNotebook())
        {
        case 'a':
            system("cls");
            printf("****Alta Notebook****\n");
            if (-1<(indice=buscarLibre(notebooks,TAMNOTE)))
            {
                if(altaNotebook(notebooks,TAMNOTE,tipos,TAMTIPO,marcas,TAMM,clientes,TAMCLIENT,proxId,indice))
                {
                    system("cls");
                    proxId++;
                    printf("Se a dado de alta correctamente\n\n");
                }
                else
                {
                    system("cls");
                    printf("Ocurrio un error al intentar dar de alta la NOTEBOOK.\nIntentelo nuevamente\n\n");
                }
            }
            else
            {
                printf("No hay espacio disponible para ingresar una nueva NOTEBOOK.\n\n");
            }
            system("pause");
            break;
        case 'b':
            system("cls");
            printf("*****Modificacion de Notebook****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                modificarNotebook(notebooks,TAMNOTE,tipos,TAMTIPO);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            break;
        case 'c':
            system("cls");
            printf("*****Baja de Notebook*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                if (bajaNotebook(notebooks,TAMNOTE,tipos,TAMTIPO,marcas,TAMM,clientes,TAMCLIENT))
                    printf("Baja Exitosa.\n");
                else
                    printf("no se realizo la baja.\n");
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'd':
            system("cls");
            printf("*****Listar Notebook*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                ordenar(notebooks,TAMNOTE,marcas,TAMM);
                mostrarNotebooks(notebooks,TAMNOTE,marcas,TAMM,tipos,TAMTIPO,clientes,TAMCLIENT);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'e':

            printf("*****Listar Marcas*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                menuMarca(marcas,TAMM);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'f':

            system("cls");
            printf("*****Listar Tipos*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                menuTipo(tipos,TAMTIPO);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'g':
            system("cls");
            printf("*****Listar Servicios*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                mostrarServicios(servicios,TAMSERV);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'h':

            system("cls");
            printf("*****Alta de Trabajos*****\n");
            if(hayRegistros(notebooks,TAMNOTE))
            {
                if(altaTrabajo(trabajos,TAMTRABAJO,notebooks,TAMNOTE,servicios,TAMSERV,marcas,TAMM,tipos,TAMTIPO,idTrabajo,clientes,TAMCLIENT))
                {
                    printf("El trabajo se ha dado de alta.\n");
                    idTrabajo++;
                }
                else
                    printf("Ocurrio un error en el alta de trabajo.\n");
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'i':
            system("cls");
            printf("*****Listados de trabajos*****\n");
            if (hayRegistros(notebooks,TAMNOTE))
            {
                mostrarTrabajos(trabajos,TAMTRABAJO,notebooks,TAMNOTE,servicios,TAMSERV);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("pause");
            break;

        case 'j':
            system("cls");
            if (hayRegistros(notebooks,TAMNOTE))
            {
            informes(notebooks,TAMNOTE,tipos,TAMTIPO,marcas,TAMM,trabajos,TAMTRABAJO,servicios,TAMSERV,clientes,TAMCLIENT);
            }
            else
                printf("Debe generar por lo menos un alta.\n\n");
            system("notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamClientepause");
            break;
        case 'k':
            system("cls");
            printf("****Salir****\n");
            getChar(&salir,3,1,'s','n',"Confirma salir? (S/N): ","Caracteres validos 's' para salir, 'n' para quedarse en el programa\nConfirma salir? (S/N): ");
            break;
        default:
            printf("La opcion ingresada no existe\n");
            system("pause");
            break;
        }
        system("cls");
    }
    while(salir!='s');
    return 0;
}
