#include "../include/tablaQuejas.h"

struct nodotabla{
  TQueja R;
  nodotabla* sig;
};



struct rep_tablaQuejas {
  nodotabla** tabla;
  int cant;
  int cantEstimadas;
 };

int funcionHash(TFecha fecha, int cantEstimadas){
    return (31 * (int) mesTFecha(fecha) + (int) diaTFecha(fecha)) % cantEstimadas;
}

TablaQuejas crearTablaQuejas(int cantEstimadas) { 
  TablaQuejas nuevatabla = nullptr;
    if (nuevatabla != nullptr) {
        liberarTablaQuejas(nuevatabla);
    }

   nuevatabla = new rep_tablaQuejas;
  nuevatabla->tabla = new nodotabla* [cantEstimadas];
  for (int i = 0; i < cantEstimadas; i++){
    nuevatabla->tabla[i] = nullptr;
  }
  nuevatabla->cant = 0;
  nuevatabla->cantEstimadas = cantEstimadas;  
  return nuevatabla;
}

void agregarQuejaTablaQuejas(TablaQuejas tabla, TQueja queja) { 
  int posicion = funcionHash(fechaTQueja(queja) , tabla->cantEstimadas);
  nodotabla* nuevo = new nodotabla;
  nuevo->R = queja;
  nuevo->sig = tabla->tabla[posicion];
  tabla->tabla[posicion] = nuevo;
  tabla->cant++;
}

void imprimirTablaQuejas(TablaQuejas tabla) {
  for (int i = 0; i < tabla->cantEstimadas; i++){
    if (tabla->tabla[i] == nullptr){
      printf("No hay elementos guardados en la posicion %d de la tabla.\n", i);
    }else{
        printf("Elementos en la posicion %d de la tabla:\n", i);
        nodotabla* actual =tabla->tabla[i];
        while (actual != nullptr){
        imprimirTQueja(actual->R);
        actual = actual->sig;
      }
      
    }
    
  }
  
}

bool perteneceQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha) {
  int poscicion = funcionHash(fecha , tabla->cantEstimadas);
  
    nodotabla* actual = tabla->tabla[poscicion];
  while (actual != nullptr) {
        if (compararTFechas(fecha, fechaTQueja(actual->R)) == 0) {
          return true;  
        }
        actual = actual->sig;
      }
      return false;
  }
  

TQueja obtenerQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha) {
  int posicion = funcionHash(fecha, tabla->cantEstimadas);
    nodotabla* actual = tabla->tabla[posicion];
    while (actual != nullptr) {
        if (compararTFechas(fecha, fechaTQueja(actual->R)) == 0) {
            return actual->R;
        }
        actual = actual->sig;
    }
    return nullptr;
}
void liberarTablaQuejas(TablaQuejas &tabla) {
  if(tabla != nullptr){
  
    for (int i = 0; i < tabla->cantEstimadas; i++){
      nodotabla* aux = tabla->tabla[i];


      while (aux != NULL){
        nodotabla* a_eliminar = aux;
      liberarTQueja(a_eliminar->R);
      aux = aux->sig;
      delete a_eliminar;
      a_eliminar = NULL;
       
      } 
      tabla->tabla[i] = nullptr;
    }
   delete[] tabla->tabla;
    delete tabla;
    tabla = nullptr;
  }
}
