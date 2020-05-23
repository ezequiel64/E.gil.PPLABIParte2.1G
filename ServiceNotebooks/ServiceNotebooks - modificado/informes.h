#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#endif // INFORMES_H_INCLUDED

/** \brief Muestra las opciones a elegir
 *

 * \return retorna la opcion a realizar
 *
 */
int menuInformes (void);

/** \brief Estructura general de informes, llama a las funciones correspondientes, para realizarlos
 *
 * \param
 * \param
 * \return
 *
 */
void informes (eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarNotebooksXtipo(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarNotebookXmarca(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarNotebookEconomicas(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarNotebooksXmarcas(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarCantidadNotebookXmarcaYtipo(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarTrabajosSobreNotebooks(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void mostrarServiciosRealizadosNotebooks(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void serviciosRealizados(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
void serviciosRealizadosFecha(eNotebook notebooks[],int tamNote,eTipo tipos[],int tamtipo,eMarca marcas[],int tamMarca,eTrabajo trabajos[],int tamTrabajo,eServicio servicio[] ,int tamServ,eCliente cliente[],int tamCliente);
