#include "marca.h"
#include "tipo.h"



#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTiopo;
    float precio;
    int isEmpty;

}eNotebook;


#endif // NOTEBOOKS_H_INCLUDED


//MENUS

/** \brief Informa las distintas operacions que se pueden realizar desde el menu
 *
 * \return retorna la opcion que se va a realizar
 *
 */
int menuNotebook (void);

/** \brief Menu que informa las distintas modificaciones que se pueden realizar
 *
 * \return retorna la opcion que se va a realizar
 *
 */
int menuModificacion (void);


//---------------------------------------------------


//BUSQUEDAS - INICIALIZACIONES

/** \brief Inicializa la variable isEmpty en 1
 *
 * \param vector de notebooks que va a inicializar
 * \param tamaño del vector de notebooks que va a ser recorrido
 *
 */
void inicializarNotebook(eNotebook list[] ,int tam);

/** \brief busca la primera posicion libre en el arreglo de notebooks
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorridoo
 * \return retorna la posicion libre o -1 si esta completo
 *
 */
int buscarLibre(eNotebook list[],int tam);

/** \brief busca una notebook, por ID
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorrido
 * \param id de notebook que va a buscar
 * \return
 *
 */
int buscarNotebook(eNotebook list[],int tam,int idx);

/** \brief recorre el areglo de notebooks buscando si hay por lo menos un registro cargado
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorrido
 * \return retorna 1 o 0 como true o false
 *
 */
int hayRegistros(eNotebook list[],int tam);

/** \brief Hardcodeo de variables para notebooks
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorrido
 *
 */
void hardcodeNotebook(eNotebook list[],int tam);


//---------------------------------------------------


//FUNCIONES DE ABM

/** \brief Genera una alta de notebook
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorrido
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de tipo que va a ser recorrido
 * \param vector de marca. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de marca que va a ser recorrido
 * \param id de la nueva alta
 * \param indice donde se va a guardar la nueva notebook
 * \return retorna 1 o 0 como true o false
 *
 */
int altaNotebook(eNotebook list[],int tam,eTipo tipo[],int tamTipo,eMarca marca[],int tamMarca,int id,int indice);

/** \brief Realiza baja logica de una notebook
 *
 * \param vector de notebooks
 * \param tamaño del vector de notebooks que va a ser recorrido
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de tipo que va a ser recorrido
 * \param vector de marca. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de marca que va a ser recorrido
 * \return retorna 1 o 0 como true o false
 *
 */
int bajaNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo,eMarca marca[],int tamMar);

/** \brief realiza la modificacion de campos especificos
 *
 * \param vector de notebooks para realizarla modificacion
 * \param tamaño del vector de notebooks que va a ser recorrido
 * \param posicion donde se va a realizar la modificacion.
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de tipo que va a ser recorrido
 * \return retorna 1 o 0 como true o false
 *
 */
void modificarNotebook(eNotebook list[],int indice,eTipo tipo[],int tamTipo);

/** \brief Muestra listado de notebooks dadas de alta por el momento.
 *
 * \param estructura de notebooks
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de tipo que va a ser recorrido
 * \param vector de marca. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de marca que va a ser recorrido
 * \return
 *
 */
void mostrarNotebook(eNotebook list,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo);

/** \brief Muestra listado de notebooks dadas de alta por el momento.
 *
 * \param vector de notebooks
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de tipo que va a ser recorrido
 * \param vector de marca. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de marca que va a ser recorrido
 *
 */
void mostrarNotebooks(eNotebook list[] ,int tam,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo);

/** \brief ordena las notebooks dadas de alta por marca
 *
 * \param vector de notebooks
 * \param vector de tipo. Necesario para mostrar informacion asociada a la notebook
 * \param vector de marca. Necesario para mostrar informacion asociada a la notebook
 * \param tamaño del vector de marca que va a ser recorrido

 *
 */
void ordenar(eNotebook list[],int tam, eMarca marca[],int tamMarca);
