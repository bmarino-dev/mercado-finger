#include "../include/producto.h"

struct rep_producto {
    int ident, precio; TFecha fechaing; char nombre[MAX_NOMBRE_PRODUCTO];
};

struct rep_fecha {
    nat dia, mes, anio;
};
TProducto crearTProducto(int id, const char nombre[MAX_NOMBRE_PRODUCTO], int precio, TFecha fechaIngreso){
    TProducto nuevoproducto = NULL;
    nuevoproducto = new rep_producto;
    nuevoproducto->ident = id;
    strcpy(nuevoproducto->nombre , nombre);
    nuevoproducto->precio = precio;
    nuevoproducto->fechaing = fechaIngreso;
    return nuevoproducto;
}

int idTProducto(TProducto producto){
    int idproducto = 0;
    idproducto = producto->ident;
        return idproducto;
}

int precioTProducto(TProducto producto){
    int precio = 0;
    precio = producto->precio;
    return precio;
}

void imprimirTProducto(TProducto producto){
    printf("Producto: %d\n", producto->ident);
    printf("%s\n", producto->nombre);
    printf("Precio: %d\n", producto->precio);
    printf("Ingresado el: %u/%u/%u\n", producto->fechaing->dia,producto->fechaing->mes,producto->fechaing->anio);
} 

void liberarTProducto(TProducto &producto){
    liberarTFecha(producto->fechaing);
    delete producto;
    producto = NULL;

}


