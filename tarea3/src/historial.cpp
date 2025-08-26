#include "../include/historial.h"

struct rep_historial {
    TFecha fecha; TListaPromociones activas,futuras,pasadas;
};
struct rep_promocion {
 int id; TFecha ini , fin; TConjuntoProductos productos;
};
struct rep_listaPromociones {
TPromocion promo; TListaPromociones sig;
};




THistorial crearTHistorial(TFecha fecha) { 
    THistorial nuevohistorial = new rep_historial;
    nuevohistorial->activas = nullptr;
    nuevohistorial->futuras = nullptr;
    nuevohistorial->pasadas = nullptr;
    nuevohistorial->fecha = fecha;
    return nuevohistorial;
 }

void agregarPromocionTHistorial(THistorial historial, TPromocion promocion) {
    if (compararTFechas(historial->fecha,promocion->fin) > 0){
        agregarPromocionTListaPromociones(historial->pasadas , promocion);
    }else if (compararTFechas(historial->fecha , promocion->ini) < 0){
        agregarPromocionTListaPromociones(historial->futuras , promocion);
    }else{
        agregarPromocionTListaPromociones(historial->activas , promocion);
    }


}

void agregarProductoAPromocionTHistorial(THistorial historial,
                                         TProducto producto, int idPromo) {
  TListaPromociones p = historial->activas;
  TListaPromociones q = historial->pasadas;
  TListaPromociones x = historial->futuras;
  while (p != nullptr) {
    if (p->promo->id == idPromo){
        agregarATPromocion(p->promo , producto);
        p = nullptr;
    } else p = p->sig;
    }


    while (q != nullptr) {
    if (q->promo->id == idPromo){
        agregarATPromocion(q->promo , producto);
        q = nullptr;
    } else q = q->sig;
    }


    while (x != nullptr) {
    if (x->promo->id == idPromo){
        agregarATPromocion(x->promo , producto);
        x = nullptr;
    } else x = x->sig;
    }
  
}
void avanzarAFechaTHistorial(THistorial historial, TFecha fecha) {
   liberarTFecha(historial->fecha);
   historial->fecha = fecha;
        TListaPromociones l1 = obtenerPromocionesFinalizadas(historial->activas , historial->fecha);
        TListaPromociones l2 = obtenerPromocionesFinalizadas(historial->futuras , historial->fecha);
        TListaPromociones l3 = obtenerPromocionesActivas(historial->futuras , historial->fecha);
        TListaPromociones uni = unirListaPromociones(l1,l2);
        liberarTListaPromociones(l1,false);
        liberarTListaPromociones(l2,false);
        TListaPromociones uni2 = unirListaPromociones(uni,historial->pasadas);
        liberarTListaPromociones(uni,false);
        liberarTListaPromociones(historial->pasadas,false);
        historial->pasadas = uni2;
        TListaPromociones uni3 = unirListaPromociones(historial->activas , l3);
        liberarTListaPromociones(l3,false);
        liberarTListaPromociones(historial->activas,false);
        historial->activas = uni3;

}
  
void imprimirPromocionesFinalizadosTHistorial(THistorial historial) {
    imprimirTListaPromociones(historial->pasadas);
}

void imprimirPromocionesActivasTHistorial(THistorial historial) {
    imprimirTListaPromociones(historial->activas);
}

void imprimirPromocionesFuturasTHistorial(THistorial historial) {
    imprimirTListaPromociones(historial->futuras);
}

bool esCompatiblePromocionTHistorial(THistorial historial,
                                     TPromocion promocion) { 
  if ((esCompatibleTListaPromociones(historial->activas , promocion)) && (esCompatibleTListaPromociones(historial->futuras , promocion)) && (esCompatibleTListaPromociones(historial->pasadas , promocion))){
    return true;
  }else return false;
  



}

void liberarTHistorial(THistorial &historial) {
    liberarTFecha(historial->fecha);
    liberarTListaPromociones(historial->activas, true);
    liberarTListaPromociones(historial->futuras,true);
    liberarTListaPromociones(historial->pasadas,true);
    delete historial;
}

/* TListaPromociones fin = historial->pasadas;
    historial->fecha = fecha;
    
    while (fin->sig != nullptr){
        fin = fin->sig;
    }
    if (historial->activas != nullptr){
        fin->sig = obtenerPromocionesFinalizadas(historial->activas , fecha);
        while (fin->sig != nullptr){
        fin = fin->sig;
        }
    }
    if (historial->futuras != nullptr){
       fin->sig = obtenerPromocionesActivas(historial->futuras , fecha);
        while (fin->sig != nullptr){
        fin = fin->sig;
        }
        fin->sig = obtenerPromocionesFinalizadas(historial->futuras , fecha);
    }



*/
    