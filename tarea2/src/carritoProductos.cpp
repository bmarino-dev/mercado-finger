#include "../include/carritoProductos.h"

struct rep_carritoProductos{
    TProducto producto ;
TCarritoProductos sig ;
    
};


TCarritoProductos crearCarritoProductosVacio(){
   return NULL;
}

void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto){
   TCarritoProductos p = new rep_carritoProductos;
   p->producto = producto;
   p->sig = NULL;
   if (carritoProductos == NULL){
    carritoProductos = p;
   } else{
        if (idTProducto(producto) < idTProducto(carritoProductos->producto)){
            p->sig = carritoProductos;
            carritoProductos = p;
        } else{
            TCarritoProductos q = carritoProductos;
            while (q->sig != NULL && idTProducto(q->sig->producto) < idTProducto(producto)){
                q = q->sig;
            }
            p->sig = q->sig;
            q->sig = p;
            
        }
        
        
   }
   
   
    

}

void imprimirCarritoProductos(TCarritoProductos carritoProductos){
 if (carritoProductos != NULL){
 TCarritoProductos p = carritoProductos;

 while (p != NULL){
    imprimirTProducto(p->producto);
    p = p->sig;
 }
 }
    

}

void liberarCarritoProductos(TCarritoProductos &carritoProductos){
 TCarritoProductos x;
 while (carritoProductos != NULL){
    x = carritoProductos;
    carritoProductos = carritoProductos->sig;
    liberarTProducto(x->producto);
    delete x;
 }carritoProductos = NULL;
 
}

bool esVacioCarritoProductos(TCarritoProductos carritoProductos){
  return carritoProductos == NULL;
}
bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    while (carritoProductos != NULL){
        if (idTProducto(carritoProductos->producto) == idProducto){
            return true;
        }
    carritoProductos = carritoProductos->sig;
    }
    return false;
}


TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
while (carritoProductos != NULL){
    if (idTProducto(carritoProductos->producto) == idProducto){
        return carritoProductos->producto;
    }
    carritoProductos = carritoProductos->sig;
}




    return NULL;
}

void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto){
  TCarritoProductos actual = carritoProductos;
    TCarritoProductos anterior = NULL;

    if (idTProducto(carritoProductos->producto) == idProducto) {
        carritoProductos = carritoProductos->sig; 
        liberarTProducto(actual->producto);       
        delete actual;                            
        return;
    }

    while (actual != NULL && idTProducto(actual->producto) != idProducto) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual != NULL) {
        anterior->sig = actual->sig;             
        liberarTProducto(actual->producto);     
        delete actual;                          
    }
}
