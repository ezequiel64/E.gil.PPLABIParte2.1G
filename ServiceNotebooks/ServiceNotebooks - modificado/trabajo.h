#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;//auto incrementar
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED


//MENU

/** \brief Informa las distintas operacions que se pueden realizar desde el menu
 *
 * \return devuelve la OP que va a realizarse
 *
 */
int menuAltaTrabajo(void);


//--------------------------------------


//INICIALIZACION - BUSQUEDA

/** \brief Inicializa la variable isEmpty en 1
 *
 * \param vector de trabajos que va a inicializar
 * \param tamaño del vector de trabajos que va a ser recorrido
 * \param se pasa el indice desde donde se quiere que empiese a inicializar por el hardcodeo de trabajo
 */
void inicializarTrabajo(eTrabajo trabajo[],int tam,int indice);

/** \brief busca la primera posicion libre en el arreglo de trabajos
 *
 * \param vector de trabajos
 * \param tamaño del vector de trabajos que va a ser recorridoo
 * \return retorna la posicion libre o -1 si esta completo
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[],int tam);


//--------------------------------------

//FUNCIONES ABM



int altaTrabajo(eTrabajo trabajo[],int tamtrabajo, eNotebook notebook[] ,int tamNote,eServicio servicio[] ,int tamServ,eMarca marca[],int tamMarca,eTipo tipo[],int tamTipo,int id,eCliente cliente[],int tamCliente);

/** \brief Muestra los trabajos que fueron dado de alta
 *
 * \param vector de trabajo.
 * \param tamaño del vector de trabajo que va a ser recorrido
 * \param vector de notebook. Necesario para mostrar informacion asociada a la trabajo
 * \param tamaño del vecttor de notebook que va a ser recorrido
 * \param vector de servicio. Necesario para mostrar informacion asociada a la trabajo
 * \param tamaño del vector de servicio que va a ser recorrido
 */
void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajo,eNotebook notebook[],int tamNote,eServicio servicio[] ,int tamServ);

/** \brief Muestra los trabajos que fueron dado de alta
 *
 * \param Estructura de trabajo.
 * \param vector de notebook. Necesario para mostrar informacion asociada a la trabajo
 * \param tamaño del vecttor de notebook que va a ser recorrido
 * \param vector de servicio. Necesario para mostrar informacion asociada a la trabajo
 * \param tamaño del vector de servicio que va a ser recorrido
 */
void mostrarTrabajo(eTrabajo trabajos,eNotebook notebook[],int tamNote,eServicio servicio[] ,int tamServ);
