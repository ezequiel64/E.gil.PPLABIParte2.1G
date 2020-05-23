#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

}eMarca;


#endif // MARCA_H_INCLUDED


/** \brief Muestra un listado de las marcas
 *
 * \param Arreglo de marcas que se va a recorrer
 * \param tamanio del arreglo de marca
 * \return
 *
 */
void menuMarca(eMarca listMarca[],int tamMarca);

/** \brief Guarda la descripcion de marca por referencia en el arreglo recibiodo como parametro
 *
 * \param vector donde se guarda el arreglo por referencia.
 * \param Id de la marca que se va a buscar
 * \param vector de marca que va a ser recorrido para buscar el ID
 * \param tamaño del vector de marcas
 * \return retorna 1 o 0 como true o false
 *
 */
int cargarDescripcionMarca(char descripcion[],int idMarca,eMarca marca[],int tamMarca);

