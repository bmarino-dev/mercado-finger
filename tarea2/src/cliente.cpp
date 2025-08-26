#include "../include/cliente.h"

struct rep_cliente {
    int id , edad; char nombre[MAX_NOMBRE ] , apellido[MAX_APELLIDO];
};


TCliente crearTCliente(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TCliente nuevocliente = NULL;
    nuevocliente = new rep_cliente;
    nuevocliente->id = id;
    nuevocliente->edad = edad;
    strcpy(nuevocliente->nombre , nombre);
     strcpy(nuevocliente->apellido , apellido);
    return nuevocliente;
}

void imprimirTCliente(TCliente cliente){
printf("Cliente %s %s\n", cliente->nombre , cliente->apellido);
printf("Id: %d\n", cliente->id);
printf("Edad: %d\n", cliente->edad);
}

void liberarTCliente(TCliente &cliente){
   if (cliente != nullptr){
     delete cliente;
    cliente = NULL;
   }
}

void nombreTCliente(TCliente cliente, char nombre[MAX_NOMBRE]){
    strcpy(nombre, cliente->nombre);
}

void apellidoTCliente(TCliente cliente, char apellido[MAX_APELLIDO]){
     strcpy(apellido, cliente->apellido);
}

int idTCliente(TCliente cliente){
    int id1 = 0;
    id1 = cliente->id;
    return id1;
}

int edadTCliente(TCliente cliente){
    int edad1 = 0;
    edad1 = cliente->edad;
    return edad1;
}

TCliente copiarTCliente(TCliente cliente){
    TCliente copiacliente = NULL;
    copiacliente = new rep_cliente;
    copiacliente->id = cliente->id;
    copiacliente->edad = cliente->edad;
    strcpy(copiacliente->nombre , cliente->nombre);
    strcpy(copiacliente->apellido , cliente->apellido);

    return copiacliente;
}
