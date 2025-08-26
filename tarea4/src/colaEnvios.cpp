#include "../include/colaEnvios.h"
struct rep_fecha {
  nat dia, mes, anio;
};

struct rep_cola_envios {
    rep_envio** nodocola;
    int cant;
    bool inv;
    int max;
};

TColaEnvios crearTColaEnvios(int N) { 
    TColaEnvios nuevaCL = new rep_cola_envios;
    nuevaCL->nodocola = new rep_envio*[N]; 
    nuevaCL->cant = 0;
    nuevaCL->inv = false;
    nuevaCL->max = N;
    for (int i = 0; i < N; i++){
        nuevaCL->nodocola[i] = NULL;
    }
    return nuevaCL;
 }
void filtradoAscendente(int pos, TColaEnvios &colaEnvios){
   if (colaEnvios->inv == false){ 
    while (pos > 0){
        int padre = (pos - 1) / 2;
        if (compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[pos]) , obtenerFechaTEnvio(colaEnvios->nodocola[padre])) == 1){
            TEnvio aux = colaEnvios->nodocola[pos];
            colaEnvios->nodocola[pos] = colaEnvios->nodocola[padre];
            colaEnvios->nodocola[padre] = aux;
           pos = padre;
        }else{
            break;
        }
    }
    }else{
         while (pos > 0){
        int padre = (pos - 1) / 2;
        if (compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[pos]) , obtenerFechaTEnvio(colaEnvios->nodocola[padre])) == -1){
            TEnvio aux = colaEnvios->nodocola[pos];
            colaEnvios->nodocola[pos] = colaEnvios->nodocola[padre];
            colaEnvios->nodocola[padre] = aux;
           pos = padre;
        }else{
            break;
        }
    }

    }
    

}
void encolarEnvioTColaEnvios(TColaEnvios &colaEnvios, TEnvio envio) {
    colaEnvios->nodocola[colaEnvios->cant] = envio;
    filtradoAscendente(colaEnvios->cant , colaEnvios);
    colaEnvios->cant++;
    }

int cantidadTColaEnvios(TColaEnvios colaEnvios) {
     return colaEnvios->cant;
 }

void imprimirTColaEnvios(TColaEnvios colaEnvios) {


}

void filtradoDescendente(int pos, TColaEnvios &colaEnvios){
    if (colaEnvios->inv == false){
        int max = colaEnvios->cant;
        while (true) {
            int izq = 2 * pos + 1;
            int der = 2 * pos + 2;
            int mayor = pos;

            if (izq < max && compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[izq]) , obtenerFechaTEnvio(colaEnvios->nodocola[mayor])) == 1) {
                mayor = izq;
            }
            if (der < max && compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[der]) , obtenerFechaTEnvio(colaEnvios->nodocola[mayor])) == 1) {
                mayor = der;
            }
            if (mayor != pos) {
                TEnvio aux = colaEnvios->nodocola[mayor];
                colaEnvios->nodocola[mayor] = colaEnvios->nodocola[pos];
                colaEnvios->nodocola[pos] = aux;
                pos = mayor;
            } else {
                break;
            }
        }
    }else{
        int max = colaEnvios->cant;
        while (true) {
            int izq = 2 * pos + 1;
            int der = 2 * pos + 2;
            int mayor = pos;

            if (izq < max && compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[izq]) , obtenerFechaTEnvio(colaEnvios->nodocola[mayor])) == -1) {
                mayor = izq;
            }
            if (der < max && compararTFechas(obtenerFechaTEnvio(colaEnvios->nodocola[der]) , obtenerFechaTEnvio(colaEnvios->nodocola[mayor])) == -1) {
                mayor = der;
            }
            if (mayor != pos) {
                TEnvio aux = colaEnvios->nodocola[mayor];
                colaEnvios->nodocola[mayor] = colaEnvios->nodocola[pos];
                colaEnvios->nodocola[pos] = aux;
                pos = mayor;
            } else {
                break;
            }
        }
    } 
}




TEnvio desencolarTColaEnvios(TColaEnvios &colaEnvios) { 
    TEnvio maspriori = colaEnvios->nodocola[0];
    colaEnvios->nodocola[0] = colaEnvios->nodocola[colaEnvios->cant - 1];
    colaEnvios->cant--;
    filtradoDescendente(0 , colaEnvios);
    return maspriori;

 }

void liberarTColaEnvios(TColaEnvios &colaEnvios) {
    for (int i = 0; i < colaEnvios->cant; i++){
        liberarTEnvio(colaEnvios->nodocola[i]);
        colaEnvios->nodocola = NULL;
    }
    delete[] colaEnvios->nodocola;
    delete colaEnvios;
    colaEnvios = NULL;
}










void invertirPrioridadTColaEnvios(TColaEnvios &colaEnvio) {
      colaEnvio->inv = !colaEnvio->inv;
      int n =colaEnvio->cant;
      TEnvio temp[n];
      for (int i = 0; i < n; i++){
        temp[i] = desencolarTColaEnvios(colaEnvio);
      }
      for (int i = 0; i < n; i++){
        encolarEnvioTColaEnvios(colaEnvio , temp[i]);
      }
      
       
    
}
TEnvio masPrioritarioTColaEnvios(TColaEnvios colaEnvio) { 
    return colaEnvio->nodocola[0]; }

int maxTColaEnvios(TColaEnvios colaEnvio) { 
    return colaEnvio->max; }