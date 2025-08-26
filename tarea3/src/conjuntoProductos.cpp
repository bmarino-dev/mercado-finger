#include "../include/conjuntoProductos.h"


// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos{
     bool* conjunto; int cantmax; int contador;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax){ 
    TConjuntoProductos nuevoconjunto = new rep_conjuntoProductos;
    nuevoconjunto->conjunto = new bool[cantMax];
    nuevoconjunto->cantmax = cantMax;
    nuevoconjunto->contador = 0;
    int i = 0;
    while (i != cantMax){
        nuevoconjunto->conjunto[i] = false;
        i++;
    }
  return nuevoconjunto;  
 }

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    if (idProducto >= conjuntoProductos->cantmax){
        return;
    }else
    if (conjuntoProductos->conjunto[idProducto] == true){
        return;
    }
    else {
        conjuntoProductos->conjunto[idProducto] = true;
        conjuntoProductos->contador++;

    }
    
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos){
    int i = 0;
    while (i < conjuntoProductos->cantmax){
        
        if (conjuntoProductos->conjunto[i] == true){
            printf("%d ", i);
            i++;
        }else {
            i++;
        }
        
        
    }
    printf("\n");
}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos){
    delete [] conjuntoProductos->conjunto;
    conjuntoProductos->conjunto = NULL;
    delete conjuntoProductos;
    conjuntoProductos = nullptr;
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos){ 
    if (conjuntoProductos->contador == 0) {
        return true;
    }else return false; }

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos){
     return conjuntoProductos->contador; }

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos){
     return conjuntoProductos->cantmax;}

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto){
     if (idProducto >= conjuntoProductos->cantmax){
        return false;
     }
     
     if (conjuntoProductos->conjunto[idProducto] == true){
        return true;
     }else return false; 
     }

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    if (conjuntoProductos->conjunto[idProducto] == false){
        return;
    }else{
        conjuntoProductos->conjunto[idProducto] = false;
        conjuntoProductos->contador--;
    }

    
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    TConjuntoProductos conjunto3 = new rep_conjuntoProductos;
    conjunto3->conjunto = new bool[conjuntoProductos1->cantmax];
    conjunto3->cantmax = conjuntoProductos1->cantmax;
    conjunto3->contador = 0;
    int i = 0;
    while (i < conjuntoProductos1->cantmax){
        if ((conjuntoProductos1->conjunto[i] == true) || (conjuntoProductos2->conjunto[i] == true)){
            conjunto3->conjunto[i] = true;
            conjunto3->contador++;
            i++;
        }else{
            conjunto3->conjunto[i] = false;
            i++;
        }
        
    }
     return conjunto3;   
}
TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    TConjuntoProductos conjunto3 = new rep_conjuntoProductos;
    conjunto3->conjunto = new bool[conjuntoProductos1->cantmax];
    conjunto3->cantmax = conjuntoProductos1->cantmax;
    conjunto3->contador = 0;
    int i = 0;
     while (i < conjuntoProductos1->cantmax){
        if ((conjuntoProductos1->conjunto[i] == true) && (conjuntoProductos2->conjunto[i] == true)){
            conjunto3->conjunto[i] = true;
            conjunto3->contador++;
            i++;
        }else{
            conjunto3->conjunto[i] = false;
            i++;
        }
        
    }
     return conjunto3;   
    
 }

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    TConjuntoProductos conjunto3 = new rep_conjuntoProductos;
    conjunto3->conjunto = new bool[conjuntoProductos1->cantmax];
    conjunto3->cantmax = conjuntoProductos1->cantmax;
    conjunto3->contador = 0;
    int i = 0;
     while (i < conjuntoProductos1->cantmax){
        if ((conjuntoProductos1->conjunto[i] == true) && (conjuntoProductos2->conjunto[i] == false)){
            conjunto3->conjunto[i] = true;
            conjunto3->contador++;
            i++;
        }else{
            conjunto3->conjunto[i] = false;
            i++;
        }
        
    }
     return conjunto3;   
    
 }
