#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED


int cargarNombreCliente(char descripcion[] ,int idCliente,eCliente cliente[] ,int tam);
