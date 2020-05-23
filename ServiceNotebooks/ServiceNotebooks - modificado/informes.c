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



int menuInformes (void)
{
    char op;
    printf("a)Informe por tipo\n");
    printf("b)Informe por marca\n");
    printf("c)Informe Notebooks economicas\n");
    printf("d)Informe Notebooks por Marcas (Todas).\n");
    printf("e)Informe Notebooks conteo de marca y tipo.\n");
    printf("f)Informe Notebooks mas solicitadas.\n");
    printf("g)Informar Trabajos Realizados a Notebook\n");
    printf("h)Informar total de servicios realizados a Notebook\n");
    printf("i)Iformar las Notebooks sometidas a un servicio.\n");
    printf("j)Informar los servicios realizados en una fecha\n");
    printf("k)Salir.\n");
    fflush(stdin);
    scanf("%c",&op);
    op=tolower(op);
    return	op;

}


void informes (eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{


    char salir='n';

    do
    {
        system("cls");
        printf("*****Informes*****\n");
        switch(menuInformes())
        {

        case 'a' :
           mostrarNotebooksXtipo(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'b' :
           mostrarNotebookXmarca(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;

        case 'c':
            mostrarNotebookEconomicas(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'd':
            mostrarNotebooksXmarcas(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'e':
            mostrarCantidadNotebookXmarcaYtipo(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);

            break;
        case 'f':


            break;
        case 'g':
            mostrarTrabajosSobreNotebooks(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'h':
            mostrarServiciosRealizadosNotebooks(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'i':
            serviciosRealizados(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'j':
            serviciosRealizadosFecha(notebooks,tamNote,tipos,tamtipo,marcas,tamMarca,trabajos,tamTrabajo,servicio,tamServ,cliente,tamCliente);
            break;
        case 'k':
            system("cls");
            printf("****Salir****\n");
            getChar(&salir,3,1,'s','n',"Confirma salir? (S/N): ","Caracteres validos 's' para salir, 'n' para quedarse en el programa\nConfirma salir? (S/N): ");
            break;

        default:
            printf("La opcion ingresada no existe.\n");
            system("pause");
            break;


        }

        system("pause");
    }
    while(salir!='s');

}


void mostrarNotebooksXtipo(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int id,flag=0;
    printf("****Notebooks por tipo****\n\n");
            menuTipo(tipos,tamtipo);
            if(getInt(&id,2,5000,5003,"Igrese el id del tipo por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id del tipo por el cual quiere consultar: "))
            {
                system("cls");
                for(int i=0; i<tamNote; i++)
                {
                    if(notebooks[i].idTiopo == id && !notebooks[i].isEmpty)
                    {
                        if(!flag)
                        {
                            printf("Id         Marca          Tipo          Modelo       Precio\n\n");
                            flag = 1;
                        }
                        mostrarNotebook(notebooks[i],marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
                    }
                }
                if(!flag)
                {
                    printf("No hay notebooks, del tipo ingresado.\n");
                }
            }
            else
            {
                printf("Fllada en de intentos. Vuelva intentarlo.\n");
            }

}

void mostrarNotebookXmarca(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int id,flag=0;
 printf("****Notebooks por marca****\n\n");
            menuMarca(marcas,tamMarca);
            if(getInt(&id,2,1000,1003,"Igrese el id de la marca por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id de la marca por el cual quiere consultar: "))
            {
                system("cls");
                for(int i=0; i<tamNote; i++)
                {
                    if(notebooks[i].idMarca == id && !notebooks[i].isEmpty)
                    {
                        if(!flag)
                        {
                            printf("Id         Marca          Tipo          Modelo       Precio\n\n");
                            flag = 1;
                        }
                        mostrarNotebook(notebooks[i],marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
                    }
                }
                if(!flag)
                {
                    printf("No hay notebooks, de la marca que ha ingresado.\n");
                }
            }
            else
            {
                printf("Fllada en de intentos. Vuelva intentarlo.\n");
            }
}

void mostrarNotebookEconomicas(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int flag=0;
    float auxFloat;
    system("cls");
            printf("****Notebooks mas economicas****\n\n");
            for(int i=0; i<tamNote; i++)
            {
                if(!notebooks[i].isEmpty)
                {
                    if(notebooks[i].precio <= auxFloat || !flag)
                    {
                        auxFloat = notebooks[i].precio;
                        flag = 1;
                    }
                }
            }
            flag=0;
            for(int i=0; i<tamNote; i++)
            {
                if(!notebooks[i].isEmpty)
                {
                    if(notebooks[i].precio <= auxFloat)
                    {
                        if(!flag)
                        {
                            printf("Id         Marca          Tipo          Modelo       Precio\n\n");
                            flag = 1;
                        }
                        mostrarNotebook(notebooks[i],marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
                    }
                }
            }
}

void mostrarNotebooksXmarcas(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int flag = 0;
    eNotebook auxNote;

                system("cls");
            printf("****Notebooks Por Marca****\n\n");
            for(int i=0; i<tamNote-1; i++)
            {
                for(int j=i+1; j<tamNote; j++)
                {
                    if(!notebooks[i].isEmpty)
                    {
                        if(notebooks[i].idMarca > notebooks[j].idMarca)
                        {
                         auxNote = notebooks[i];
                         notebooks[i] = notebooks[j];
                         notebooks[j] = auxNote;
                        }
                    }
                }
            }
            flag=0;
            for(int i=0; i<tamNote; i++)
            {
                if(!notebooks[i].isEmpty)
                {
                        if(!flag)
                        {
                            printf("Id         Marca          Tipo          Modelo       Precio\n\n");
                            flag = 1;
                        }
                        mostrarNotebook(notebooks[i],marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
                }
            }
}

void mostrarCantidadNotebookXmarcaYtipo(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int idtipo,idmarca,flag=0,cont=0;
    //int cont2=0;
    char descripcionMarca[20],descripcionMarcaTipo[20];

            printf("****Notebooks por marca y tipo****\n\n");
            menuTipo(tipos,tamtipo);
            if(getInt(&idtipo,2,5000,5003,"Igrese el id del tipo por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id del tipo por el cual quiere consultar: "))
            menuMarca(marcas,tamMarca);
            if(getInt(&idmarca,2,1000,1003,"Igrese el id de la marca por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id de la marca por el cual quiere consultar: "))
            {
                system("cls");
                for(int i=0; i<tamNote; i++)
                {
                    if(!notebooks[i].isEmpty)
                    {
                        if(notebooks[i].idTiopo == idtipo && notebooks[i].idMarca == idmarca)
                        {

                        flag=1;
                        cont++;
                        }
                    }
                }
                if(flag)
                {
                cargarDescripcionMarca(descripcionMarca,idmarca,marcas,tamMarca);
                cargarDescripcionTipo(descripcionMarcaTipo,idtipo,tipos,tamtipo);
                printf("Hay %d Notebooks que coinciden con el tipo '%s' y marca '%s' solicitado\n",cont,descripcionMarcaTipo,descripcionMarca);
                }else
                    printf("No hay considencia entre el tipo y marca que ha ingresado.\n");
            }
            else
            {
                printf("Fllada en de intentos. Vuelva intentarlo.\n");
            }

//            printf("****Notebooks por tipo y marca****\n\n");
//            menuTipo(tipos,tamtipo);
//            if(getInt(&idtipo,2,5000,5003,"Igrese el id del tipo por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id del tipo por el cual quiere consultar: "))
//            menuMarca(marcas,tamMarca);
//            if(getInt(&idmarca,2,1000,1003,"Igrese el id de la marca por el cual quiere consultar: ","Error. El valor ingresado es incorrecto\nIgrese el id de la marca por el cual quiere consultar: "))
//            {
//                system("cls");
//                for(int i=0; i<tamNote; i++)
//                {
//                    if(!notebooks[i].isEmpty)
//                    {
//                        if(notebooks[i].idTiopo == idtipo)
//                        {
//                        flag=1;
//                        cont++;
//                        }
//                        if(notebooks[i].idMarca == idmarca)
//                        {
//                        flag=1;
//                        cont2++;
//                        }
//                    }
//                }
//                if(flag)
//                {
//                cargarDescripcionMarca(descripcionMarca,idmarca,marcas,tamMarca);
//                cargarDescripcionTipo(descripcionMarcaTipo,idtipo,tipos,tamtipo);
//                printf("Hay %d que coinciden con la marca '%s' y %d que coinciden con el tipo '%s'\n",cont2,descripcionMarca,cont,descripcionMarcaTipo);
//                }else
//                    printf("No hay considencia entre el tipo y marca que ha ingresado.\n");
//            }
//            else
//            {
//                printf("Fllada en de intentos. Vuelva intentarlo.\n");
//            }serviciosRealizados
}

void mostrarTrabajosSobreNotebooks(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int id,flag=0;
            mostrarNotebooks(notebooks,tamNote,marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
            printf("\n\n");
            if(getInt(&id,2,100,150,"Ingrese el ID de la notebook por la cual quiere consultar :","Error. El id de la notebook es invalido."))
            {
                system("cls");
                for(int i = 0;i<tamNote;i++)
                {
                if (!notebooks[i].isEmpty)
                {
                    if(trabajos[i].idNotebook == id)
                   {
                    flag=1;
                    mostrarTrabajo(trabajos[i],notebooks,tamNote,servicio,tamServ);
                   }
                }

                }
            }
            if(!flag)
                printf("No hay trabajos realizados sobre esta notebook.\n");
}

void mostrarServiciosRealizadosNotebooks(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int id,flag=0;
    float total=0,precio;
            mostrarNotebooks(notebooks,tamNote,marcas,tamMarca,tipos,tamtipo,cliente,tamCliente);
            printf("\n\n");
            if(getInt(&id,2,100,150,"Ingrese el ID de la notebook por la cual quiere consultar :","Error. El id de la notebook es invalido."))
            {
                system("cls");
                for(int i = 0;i<tamNote;i++)
                {
                if (!notebooks[i].isEmpty)
                {
                    if(trabajos[i].idNotebook == id)
                   {
                    cargarPrecioServicio(&precio,trabajos[i].idServicio,servicio,tamServ);
                    total+=precio;
                    flag = 1;
                   }
                }
                }
            }

            if(flag)
                printf("El total de servicios efectuado sobre la Notebook con el ID %d es de $%.2f.\n",id,total);
                else
                    printf("No hay trabajos realizados sobre esta notebook.\n");
}

void serviciosRealizados(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{

     int id,flag=0;
     char descripcionServicio[20];
            mostrarServicios(servicio,tamServ);
            printf("\n\n");
            if(getInt(&id,2,20000,20003,"Ingrese el ID del servicio por el cual quiere consultar :","Error. El id de servicio no es invalido."))
            {
                system("cls");
                cargarDescripcionServicios(descripcionServicio,id,servicio,tamServ);
                for(int i = 0;i<tamServ;i++)
                {
                    if(trabajos[i].idServicio == id)
                   {
                       if(!flag)
                       {
                        printf("La/s notebook/s a las cuales se realizo el servicio '%s' son: ",descripcionServicio);
                        printf("\n\nId     Id NoteBook      Servicio      precio       Fecha\n");
                        flag = 1;
                       }
                    mostrarTrabajo(trabajos[i],notebooks,tamNote,servicio,tamServ);

                   }

                }
            }

            if(!flag)
                    printf("No hay trabajos realizados sobre esta notebook.\n");

}


void serviciosRealizadosFecha(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
{
    int flag =0;
    eTrabajo auxTrabajo;
    printf("Ingrese la Fecha en la cual quiere realizar la consulta: ");
 				if (getInt(&auxTrabajo.fecha.dia,2,1,31,"Ingrese dia que se inicio el servicio.\n\nValores permitidos entre 1 y 31: ","\nError. Vuelva a intentarlo.\n\nValores permitidos entre 1 y 31"))
                        {printf("\n------------------------------------\n");
                            if (getInt(&auxTrabajo.fecha.mes,2,1,12,"Ingrese mes que se inicio el servicio.\n\nValores permitidos entre 1 y 12: ","\nError. Vuelva a intentarlo.\n\nValores permitidos entre 1 y 12: "))
                            {printf("\n------------------------------------\n");
                                if (getInt(&auxTrabajo.fecha.anio,2,1985,2020,"Ingrese anio que se inicio el servicio.\n\nValores permitidos entre 1985 y 2020 anios: ","\nError. Vuelva a intentarlo.\n\nValores permitidos entre 1985 y 2020: "))
                                {printf("\n------------------------------------\n");
                                system("cls");
                                for(int i = 0;i<tamTrabajo;i++)
                                {
                                if(auxTrabajo.fecha.dia == trabajos[i].fecha.dia && auxTrabajo.fecha.mes == trabajos[i].fecha.mes && auxTrabajo.fecha.anio == trabajos[i].fecha.anio)
                                {
                                    if(!flag)
                                    {
                                    printf("Los servicios realizados en la fecha %d/%d/%d son : \n",auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio);
                                    printf("\n\nId     Id NoteBook      Servicio      precio       Fecha\n");
                                    flag = 1;
                                    }
                                mostrarTrabajo(trabajos[i],notebooks,tamNote,servicio,tamServ);
                                }
                                }
                                }
                            }
                        }
        if(!flag)
        {
            printf("\nNo hay registro de servicios realizados en esa fechas.");
        }

}

//void marcasMasElejidas(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente)
//{
//
//int vec[tamNote];
//
//    for(int i = 0;i<tamNote;i++)
//    {
//        vec[i] = marcas[i].id;
//    }
//
//
//     printf("La/s marca/s mas elejidas son: ");
//
//
//}


