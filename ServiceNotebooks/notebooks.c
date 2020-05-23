#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "tipo.h"
#include "marca.h"
#include "notebooks.h"
#include "datawarehouse.h"


//MENUS

int menuModificacion (void)
{
    int op;
    printf("1)Precio\n");
    printf("2)Tipo\n");
    printf("3)salir\n");
    fflush(stdin);
    scanf("%d",&op);
    return	op;

}

int menuNotebook (void)
{
    char op;
    printf("a)ALTA NOTEBOOK\n");
    printf("b)MODIFICAR NOTEBOOK\n");
    printf("c)BAJA NOTEBOOK\n");
    printf("d)LISTAR NOTEBOOKS\n");
    printf("e)LISTAR  MARCAS \n");
    printf("f)LISTAR TIPOS\n");
    printf("g)LISTAR SERVICIOS\n");
    printf("h)ALTA TRABAJO\n");
    printf("i)LISTAR TRABAJOS\n");
    printf("j)salir\n\n");
    fflush(stdin);
    scanf("%c",&op);
    op=tolower(op);
    return	op;

}

//INICIALIZACION Y BUSQUEDAS

int buscarLibre(eNotebook list[],int tam)
{
    int rta=-1;
    for (int i = 0; i < tam; ++i)
    {
        if (list[i].isEmpty)
        {
            rta = i;
            break;
        }

    }
    return rta;
}

int buscarNotebook(eNotebook list[],int tam,int idx)
{
    int rta=-1;
    for (int i = 0; i < tam; ++i)
    {
        if (list[i].id==idx && !list[i].isEmpty)
        {
            rta = i;
            break;
        }

    }
    return rta;
}

void inicializarNotebook(eNotebook list[] ,int tam)
{
    for (int i = 0; i < tam; ++i)
    {
        list[i].isEmpty = 1;
    }
}

int hayRegistros(eNotebook list[],int tam)
{

    int rta=0;
    for (int i = 0; i < tam; ++i)
    {
        if (!list[i].isEmpty)
        {
            rta = 1;
            break;
        }
    }
    return rta;
}

void hardcodeNotebook(eNotebook list[],int tam)
{
    for(int i =0 ; i < tam;i++)
    {
    list[i].id=ids[i];
    //srtcpy(list[i].modelo,modelo[i]);
    strcpy(list[i].modelo,modelo[i]);
    list[i].idMarca=idMarca[i];
    list[i].idTiopo=idTipo[i];
    list[i].precio=precio[i];
    list[i].isEmpty=0;
    }

}

//FUNCIONES ABM

int altaNotebook(eNotebook list[],int tam,eTipo tipo[],int tamTipo,eMarca marca[],int tamMarca,int id,int indice)
{
   int rta = 0;
    eNotebook auxNote;
    auxNote.isEmpty=0;
    auxNote.id=id;
    system("cls");
    printf("****Alta de Notebook****\n\n");

    if(getString(auxNote.modelo,20,"Ingrese Modelo (color)","Error. Ingrese Modelo  (color)",2))
    {
        menuMarca(marca,tamMarca);
        if(getInt(&auxNote.idMarca,2,1000,1003,"Ingrese id de marca.\nRango valido de 1000 a 1003: ","Error. Ingrese id de marca.\nRango valido de 1000 a 1003: "))
        {
            menuTipo(tipo,tamTipo);
            if(getInt(&auxNote.idTiopo,2,5000,5003,"Ingrese id de tipo.\nRango valido de 5000 a 5003: ","Error. Ingrese id de tipo.\nRango valido de 5000 a 5003: "))
            {system("cls");
                if(getFloat(&auxNote.precio,2,25000,150000,"Ingrse el precio.\nValores validos desde $25.000 a $150.000: ","Error.\nValores validos desde $25.000 a $150.000: "))
                {
                rta = 1;
                list[indice]=auxNote;
                }
            }
        }
    }
    return rta;

}

void modificarNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo)
{
char salir='n',continuar='s';
int indice,id,flag;
eNotebook auxNote;

do
{
    flag=0;
    if(!flag)
    {
    system("cls");
    printf("****Modificacion de Notebook****\n\n");
    printf("*****Si no recuerda el numero de ID ingrese al apartado 'D', del menu Gestion de Notebook*****\n\n");
    system("pause");
    system("cls");
    printf("****Modificacion de Notebook****\n\n");
    }
     if(getInt(&id,1,100,150,"Ingrese el id de la notebook que desea modificar: ","Error. Ingrese el id de la notebook que desea modificar: "))
            {
            if (-1<(indice=buscarNotebook(list,tamNote,id)))
            {
    system("cls");
    printf("****Modificacion de Notebook****\n\n");
    printf("Ingrese opcion que desea modificar.\n\n");
    switch(menuModificacion())
	{


        printf("\n--------------------------------------------\n");
		case 1:
		if(getFloat(&auxNote.precio,2,25000,150000,"Ingrse el precio.\nValores validos desde $25.000 a $150.000: ","Error.\nValores validos desde $25.000 a $150.000: "))
			{printf("\nSe han cargado cambios\n");
            list[indice].precio=auxNote.precio;
            flag=1;
			}
			else
				printf("Ocurrio un error en la carga. Vuelva a intentaro.\n");
        break;
		case 2:
            menuTipo(tipo,tamTipo);
            if(getInt(&auxNote.idTiopo,2,5000,5003,"Ingrese id de tipo.\nRango valido de 5000 a 5003: ","Error. Ingrese id de tipo.\nRango valido de 5000 a 5003: "))
                {printf("\nSe han cargado cambios\n");
            	list[indice].idTiopo=auxNote.idTiopo;
            	flag=1;
        		}
                else
                printf("Ocurrio un error en la carga. Vuelva a intentaro.\n");
            break;

		case 3:
		    system("cls");
            printf("****Salir****\n");
            getChar(&salir,3,1,'s','n',"Confirma salir? (S/N): ","Caracteres validos 's' para salir, 'n' para quedarse en el programa\nConfirma salir? (S/N): ");
			break;

		default:
		printf("La opcion ingresada no existe.\n");
		system("pause");
			break;


    }
        }
            }else
            printf("El id de la notebook ingresado no EXISTE o NO SE ENCUENTA ACTIVO en la base de datos.\n\n");
    if(flag)
        {
        if(!getChar(&continuar,2,1,'s','n',"Desea ingresar una nueva modificaion?\nCaracteres validos 's' para seguir, 'n' para volver al menu de Notebooks. ","Error. Desea ingresar una nueva modificaion?\nCaracteres validos 's' para seguir, 'n' para volver al menu de Notebooks. "))
            {
                printf("Error, con el ingreso de datos.\nSe devuelve al menu de Notebooks.");
                continuar='n';
            }
            system("cls");
        }

}while(salir!='s'&&continuar!='n');

}

int bajaNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo,eMarca marca[],int tamMar)
{
    int rta=0,id,indice,op=2;
    char confirma='n';
    if(!rta)
    {
    system("cls");
    printf("****Baja de Notebook****\n\n");
    printf("*****Si no recuerda el numero de ID ingrese al apartado 'D', del menu Gestion de Notebook*****\n\n");
    system("pause");
    system("cls");
    printf("****Baja de Notebook****\n\n");
    }

    printf("1)Baja.\n2)Menu de gestion.");
    getInt(&op,1,1,2,"","");
    switch(op)
    {
    case 1:
     if(getInt(&id,1,100,150,"Ingrese el id de la notebook que desea dar de baja: ","Error. Ingrese el id de la notebook que desea dar de baja: "))
            {
            if (-1<(indice=buscarNotebook(list,tamNote,id)))
            {
                printf("Id         Marca          Tipo          Modelo       Precio\n\n");
                mostrarNotebook(list[indice],marca,tamMar,tipo,tamTipo);
                if(getChar(&confirma,2,1,'s','n',"Confirma baja?\nCaracteres validos S para si, N para no. ","Error. Confirma baja?\nCaracteres validos S para si, N para no. "))
                {
                    if (confirma=='s')
                    {
                     list[indice].isEmpty=1;
                     rta =1;
                    }

                }else
                printf("\nError en la confirmacion. vuelva a intentarlo.\n");
            }
            }else
            	printf("\nEl id de la notebook ingresado no EXISTE o NO SE ENCUENTA ACTIVO en la base de datos.\n\n");

            break;

    case 2:

        break;

    }
      return rta;

}

void mostrarNotebook(eNotebook list,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo)
{
    char descripcionMarca[20],descripcionTipo[20];
    cargarDescripcionTipo(descripcionTipo,list.idTiopo,tipo,tamTipo);
    cargarDescripcionMarca(descripcionMarca,list.idMarca,marca,tamMarca);
    printf("%3d       %6s      %10s   %10s     %.2f\n",list.id,descripcionMarca,descripcionTipo,list.modelo,list.precio);

}

void mostrarNotebooks(eNotebook list[] ,int tam,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo)
{

int flag = 0;
system("cls");
printf("******Lisado de Notebook*****\n\n");
for(int i=0;i<tam;i++)
{
    if(!list[i].isEmpty)
    {
        if(!flag)
        {
        printf("Id         Marca          Tipo          Modelo       Precio\n");
        flag=1;
        }
    mostrarNotebook(list[i],marca,tamMarca,tipo,tamTipo);
    }

}

}

void ordenar(eNotebook list[],int tam, eMarca marca[],int tamMarca)
{
    eNotebook auxNote;
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(list[i].idMarca > list[j].idMarca && !list[i].isEmpty)
            {
            auxNote = list[i];
            list[i] = list[j];
            list[j] = auxNote;
            }
            if(list[i].idMarca == list[j].idMarca&& !list[i].isEmpty)
            {
                if(list[i].precio<list[j].precio)
                {
                auxNote = list[i];
                list[i] = list[j];
                list[j] = auxNote;
                }
            }
        }
    }

}
