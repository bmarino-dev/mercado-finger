#include "../include/promocion.h"

//  La estructura almacena un id de tipo entero, dos fechas para representar el inicio y el fin 
// de la promocion, así como la información de qué productos forman parte de la promocion.
struct rep_promocion {
 int id; TFecha ini , fin; TConjuntoProductos productos;
};

struct rep_conjuntoProductos{
     bool* conjunto; int cantmax; int contador;
};

struct rep_producto {
  int id;
  char nombre[MAX_NOMBRE_PRODUCTO];
  TFecha fechaIngreso;
  int precio;
};

TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax){ 
    TPromocion nuevapromocion = new rep_promocion;
    nuevapromocion->id = idProm;
    nuevapromocion->ini = ini;
    nuevapromocion->fin = fin;
    nuevapromocion->productos = crearTConjuntoProductos(cantMax);
    return nuevapromocion;
 }

void agregarATPromocion(TPromocion &prom, TProducto p){
    if (p->id >= prom->productos->cantmax){
        return;
    }
    prom->productos->conjunto[p->id] = true;
}

void imprimirTPromocion(TPromocion prom){
    printf("Promocion #%d del ", prom->id);
    imprimirTFecha(prom->ini);
    printf(" al ");
    imprimirTFecha(prom->fin);
    printf("\n");
    printf("Productos: ");
    imprimirTConjuntoProductos(prom->productos);


}

void liberarTPromocion(TPromocion &prom){
    liberarTConjuntoProductos(prom->productos);
    liberarTFecha(prom->ini);
    liberarTFecha(prom->fin);
    delete prom;
    prom = NULL;
}

bool perteneceATPromocion(TPromocion prom, TProducto p){ 
    if (p->id >= prom->productos->cantmax){
        return false;
    }else if (prom->productos->conjunto[p->id] == true){
        return true;
    }else return false;
    
 }

int idTPromocion(TPromocion prom){ 
    return prom->id;
 }

TFecha fechaInicioTPromocion(TPromocion prom){ 
    return prom->ini;  }

TFecha fechaFinTPromocion(TPromocion prom){ 
    return prom->fin; }

bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2){ 
int i = 0;
int cant = 0;
while (i < prom1->productos->cantmax){
    if ((prom1->productos->conjunto[i] == true) && (prom2->productos->conjunto[i] == true)){
        cant++;
        i++;
    }else i++;
}
if (cant == 0){
    return true;
}else{
    if (compararTFechas(prom1->ini, prom2->ini) == -1){
        if ((compararTFechas(prom1->fin,prom2->ini) == 0) || (compararTFechas(prom1->fin,prom2->ini) == 1)){
            return false;
        }else return true;
        
    }else if (compararTFechas(prom1->ini,prom2->fin) == 1){
        return true;
    }else return false;


}

}

