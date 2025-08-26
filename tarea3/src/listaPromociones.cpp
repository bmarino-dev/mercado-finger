#include "../include/listaPromociones.h"

struct rep_listaPromociones {
TPromocion promo; TListaPromociones sig;
};
struct rep_promocion {
 int id; TFecha ini , fin; TConjuntoProductos productos;
};

struct rep_fecha {
  nat dia, mes, anio;
};




TListaPromociones crearTListaPromocionesVacia() { 
 return NULL;
 }

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones,
                                       TPromocion promocion) { 
TListaPromociones p = new rep_listaPromociones;
p->sig = nullptr;
p->promo = promocion;
if ((listaPromociones == nullptr) || (compararTFechas(p->promo->ini,listaPromociones->promo->ini) == -1)){
  p->sig = listaPromociones;
  listaPromociones = p;
}else{
 TListaPromociones q = listaPromociones;
    while ((q->sig != NULL) && (compararTFechas(q->sig->promo->ini,p->promo->ini) == -1)){
      q = q->sig;
    }
  p->sig = q->sig;
  q->sig = p;

} 


}

void imprimirTListaPromociones(TListaPromociones listaPromociones) {
  if (listaPromociones == nullptr){
    return;
  }else{
    TListaPromociones p = listaPromociones;
    while (p != nullptr){
      imprimirTPromocion(p->promo);
      p = p->sig;
    }
    
  }
  
}

void liberarTListaPromociones(TListaPromociones &listaPromociones,
                              bool liberarPromociones) {
  TListaPromociones p;
  if (liberarPromociones == true) {
  while (listaPromociones != nullptr){
     p = listaPromociones;
     listaPromociones = listaPromociones->sig;
     liberarTPromocion(p->promo);
      delete p;
      p = nullptr;

  }
  
  }else{
   while (listaPromociones != nullptr){
      p = listaPromociones;
      listaPromociones = listaPromociones->sig;
      delete p;
      p = nullptr;

   }
  }


}

bool esVaciaTListaPromociones(TListaPromociones promociones) { 
  if (promociones == nullptr){
    return true;
  }else return false;
  
}



bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones,
                                         int idPromocion) {
  TListaPromociones p = listaPromociones;
  while ((p != nullptr) && (p->promo->id != idPromocion)){
    p = p->sig;
  }
  if (p == nullptr){
    return false;
  } else return true;
    
}

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion) {
  TListaPromociones p = listaPromociones;
  while ((p != nullptr) && (p->promo->id != idPromocion)){
    p = p->sig; 
  }
  return p->promo;


}


TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                                                TFecha fecha) {
  TListaPromociones nueva = crearTListaPromocionesVacia(); 
  TListaPromociones fin = nullptr;  
  TListaPromociones ant = nullptr, actual = listaPromociones;

    while (actual != nullptr) {
        if (compararTFechas(actual->promo->fin, fecha) < 0) { 
            if (ant == nullptr) {
                listaPromociones = actual->sig;  
            } else {
                ant->sig = actual->sig; 
            }
            TListaPromociones temp = actual;
            actual = actual->sig;
            temp->sig = nullptr; 

            if (nueva == nullptr) {
                nueva = temp;
                fin = temp;  
            } else {
                fin->sig = temp;  
                fin = temp; 
            }
        } else {
            ant = actual;
            actual = actual->sig;
        }
    }

    return nueva;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha) {
  TListaPromociones nueva = crearTListaPromocionesVacia();
  TListaPromociones fin = nullptr; 
  TListaPromociones ant = nullptr, actual = listaPromociones;

    while (actual != nullptr) {
        if ((compararTFechas(actual->promo->fin, fecha) >= 0) && (compararTFechas(actual->promo->ini, fecha) <= 0)) { 
            if (ant == nullptr) {
                listaPromociones = actual->sig;
            } else {
                ant->sig = actual->sig; 
            }
            TListaPromociones temp = actual;
            actual = actual->sig;

            temp->sig = nullptr;  

            if (nueva == nullptr) {
                nueva = temp;  
                fin = temp; 
            } else {
                fin->sig = temp;
                fin = temp; 
            }
        } else {
            ant = actual;
            actual = actual->sig;
        }
    }

    return nueva;
}
bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion) {
  if (listaPromociones == nullptr) return false;
  TListaPromociones p = listaPromociones;
  while ((p != nullptr) && (sonPromocionesCompatibles(p->promo , promocion) == true)){
    p = p->sig; 
  }if (p == nullptr){
    return true;
  }else return false;
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2) {
TListaPromociones principal = nullptr;
TListaPromociones fin,nodo;

  while ((listaPromociones1 != nullptr) && (listaPromociones2 != nullptr)){
    if (compararTFechas(listaPromociones1->promo->ini, listaPromociones2->promo->ini) <= 0){
      nodo = new rep_listaPromociones;
      nodo->promo = listaPromociones1->promo;
      nodo->sig = nullptr;
      if (principal == nullptr) principal = nodo;
      else fin->sig = nodo;
      fin = nodo;
      listaPromociones1 = listaPromociones1->sig;

    }else{
       nodo = new rep_listaPromociones;
      nodo->promo = listaPromociones2->promo;
      nodo->sig = nullptr;
      if (principal == nullptr) principal = nodo;
      else fin->sig = nodo;
      fin = nodo;
      listaPromociones2 = listaPromociones2->sig;

    }
   
    
  }
   while (listaPromociones1 != nullptr){
      nodo = new rep_listaPromociones;
      nodo->promo = listaPromociones1->promo;
      nodo->sig = nullptr;
      if (principal == nullptr) principal = nodo;
      else fin->sig = nodo;
      fin = nodo;
      listaPromociones1 = listaPromociones1->sig;
   }
   while (listaPromociones2 != nullptr){
       nodo = new rep_listaPromociones;
      nodo->promo = listaPromociones2->promo;
      nodo->sig = nullptr;
      if (principal == nullptr) principal = nodo;
      else fin->sig = nodo;
      fin = nodo;
      listaPromociones2 = listaPromociones2->sig;
    }

  return principal;
}

