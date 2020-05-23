#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;


#endif // SERVICIO_H_INCLUDED


/** \brief Muestra los servicios que hay disponibles
 *
 * \param Vector de servicios que va a mostrar
 * \param tamaño del vector de servicios
 *
 */
void mostrarServicios(eServicio servicio[],int tam);

/** \brief busca si el ID de servicio existe
 *
 * \param Vector de servicios donde se va a realizar la busqueda
 * \param tamaño del vector de servicios
 * \param id de servicio que se va a buscar
 * \return devuelve el indice si es encontrado -1 si no existe
 *
 */
int buscarServicio(eServicio servicio[],int tam,int idx);

/** \brief Carga la descripcion del servicio por referencia
 *
 * \param arreglo donde va a ser cargada la descripcion
 * \param id del servicio que se va a cargar
 * \param Vector de servicios donde se va a realizar la busqueda
 * \param tamaño del vector de servicios
 * \return devuelve 1 o 0 si se pudo realizar la carga
 *
 */
int cargarDescripcionServicios(char descripcion[],int idServi,eServicio servicio[],int tamServi);

/** \brief Carga el precio del servicio por referencia
 *
 * \param puntero a variable donde se va a cargar el precio
 * \param id del servicio que se va a cargar
 * \param Vector de servicios donde se va a realizar la busqueda
 * \param tamaño del vector de servicios
 * \return devuelve 1 o 0 si se pudo realizar la carga
 *
 */
int cargarPrecioServicio(float* precio,int id,eServicio servicio[] ,int tamServ);
