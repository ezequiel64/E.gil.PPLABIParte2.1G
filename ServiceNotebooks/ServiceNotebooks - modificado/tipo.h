#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;// comienza en 5000
    char descripcion[20];

}eTipo;

#endif // TIPO_H_INCLUDED

void menuTipo(eTipo list[],int tamTipo);

int cargarDescripcionTipo(char descripcion[],int idTipo,eTipo tipo[],int tamTipo);

