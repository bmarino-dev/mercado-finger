#include "../include/clientesSucursalesLDE.h"
struct rep_auxiliar {
	TClientesABB clientesABB;
	int idSucursal;
	rep_auxiliar *sig;
	rep_auxiliar *ant;
	};

struct rep_clientesSucursalesLDE {
	rep_auxiliar *inicio;
	rep_auxiliar *final;
};
struct rep_cliente {
    int id , edad; char nombre[MAX_NOMBRE ] , apellido[MAX_APELLIDO];
};
typedef struct rep_auxiliar *TAuxiliar;

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia(){
	TClientesSucursalesLDE nuevaSucursal = new rep_clientesSucursalesLDE;
    nuevaSucursal->inicio = nullptr;
    nuevaSucursal->final = nullptr;
    return nuevaSucursal;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal){
 TAuxiliar nuevo = new rep_auxiliar;
    nuevo->clientesABB = clientesABB;
    nuevo->idSucursal = idSucursal;
    nuevo->sig = nullptr;
    nuevo->ant = nullptr;

   
    if (clientesSucursalesLDE->inicio == nullptr) {
        clientesSucursalesLDE->inicio = nuevo;
        clientesSucursalesLDE->final = nuevo;
    } else {
        
        TAuxiliar actual = clientesSucursalesLDE->inicio;
        
      
        while ((actual != nullptr) && (edadPromedioTClientesABB(nuevo->clientesABB) >= edadPromedioTClientesABB(actual->clientesABB))) {
            actual = actual->sig;
        }

       
        if (actual == clientesSucursalesLDE->inicio) {
            nuevo->sig = clientesSucursalesLDE->inicio;
            clientesSucursalesLDE->inicio->ant = nuevo;
            clientesSucursalesLDE->inicio = nuevo;
        }
  
        else if (actual == nullptr) {
            nuevo->ant = clientesSucursalesLDE->final;
            clientesSucursalesLDE->final->sig = nuevo;
            clientesSucursalesLDE->final = nuevo;
        }
   
        else {
            nuevo->sig = actual;
            nuevo->ant = actual->ant;
            actual->ant->sig = nuevo;
            actual->ant = nuevo;
        }
    }

}
void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE){
if (clientesSucursalesLDE == nullptr) {
        return; 
    }

    TAuxiliar q = clientesSucursalesLDE->inicio;

    while (q != nullptr) {
        TAuxiliar siguiente = q->sig; 
        liberarTClientesABB(q->clientesABB);
        delete q;
        q = siguiente;
    }

    delete clientesSucursalesLDE;
    clientesSucursalesLDE = nullptr;
}

void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
 printf("clientesSucursalesLDE de grupos:\n");
    TAuxiliar actual = clientesSucursalesLDE->inicio; 
    
    while (actual != nullptr) {
        float edadprom = edadPromedioTClientesABB(actual->clientesABB);
        printf("Grupo con edad promedio %.2f:\n", edadprom);
        imprimirTClientesABB(actual->clientesABB); 
        actual = actual->sig; 
    }
}


void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
printf("clientesSucursalesLDE de grupos:\n");
    TAuxiliar actual = clientesSucursalesLDE->final; 
    
    while (actual != nullptr) {
        float edadprom = edadPromedioTClientesABB(actual->clientesABB);
        printf("Grupo con edad promedio %.2f:\n", edadprom);
        imprimirTClientesABB(actual->clientesABB);
        actual = actual->ant;
    }

}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	nat x = 0;
	if ((clientesSucursalesLDE == NULL)  || (clientesSucursalesLDE->inicio == NULL)){
		return 0;
	}
	TAuxiliar actual = clientesSucursalesLDE->inicio;
	while (actual != NULL){
		x = x + 1;
		actual = actual->sig;
	}
	
	return x;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	if (clientesSucursalesLDE == nullptr || clientesSucursalesLDE->inicio == nullptr) {
        return nullptr;
    }

    return clientesSucursalesLDE->inicio->clientesABB;
	return NULL;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	if (clientesSucursalesLDE == nullptr || n <= 0) {
        return nullptr;
    }

    TAuxiliar actual = clientesSucursalesLDE->inicio;
    int contador = 1;

    while (actual != nullptr && contador < n) {
        actual = actual->sig;
        contador++;
    }

    if (actual == nullptr) {
        return nullptr; 
    }

    return actual->clientesABB;
	return NULL;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	TAuxiliar p = clientesSucursalesLDE->final;
    if (clientesSucursalesLDE->inicio == clientesSucursalesLDE->final){
        TClientesABB x = p->clientesABB;
        p->clientesABB = nullptr;
        clientesSucursalesLDE->inicio = nullptr;
        clientesSucursalesLDE->final = nullptr;
        delete p;
        p = nullptr;
        return x;
    } else{
    
    clientesSucursalesLDE->final = p->ant;
    p->ant->sig = nullptr;
    p->ant = nullptr;
    TClientesABB x = p->clientesABB;
    p->clientesABB = nullptr;
    delete p;
    p = nullptr;

    return x;
}
}
TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	TAuxiliar p = clientesSucursalesLDE->inicio;
    int cont = 1;
    while (p != nullptr && cont < n){
        p = p->sig;
        cont++;
    } 
    TClientesABB x = p->clientesABB;
    if (p == clientesSucursalesLDE->inicio) {
        clientesSucursalesLDE->inicio = p->sig;
        if (clientesSucursalesLDE->inicio != nullptr) {
            clientesSucursalesLDE->inicio->ant = nullptr;
        }
    } else if (p == clientesSucursalesLDE->final) {
        clientesSucursalesLDE->final = p->ant;
        if (clientesSucursalesLDE->final != nullptr) {
            clientesSucursalesLDE->final->sig = nullptr;
        }
    } else {
        p->ant->sig = p->sig;
        p->sig->ant = p->ant;
    }

    delete p;
    return x;    
    }
    

    int contarFrecuenciaCliente(TClientesSucursalesLDE clientesSucursalesLDE, int idCliente) {
    int contador = 0;
    TAuxiliar sucursal = clientesSucursalesLDE->inicio;
    while (sucursal != nullptr) {
        if (existeTClienteTClientesABB(sucursal->clientesABB, idCliente)) {
            contador++;
        }
        sucursal = sucursal->sig;
    }  
    return contador;
}



TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE){
    if (clientesSucursalesLDE == nullptr || clientesSucursalesLDE->inicio == nullptr) {
        return nullptr;
    }

    TCliente cliente1 = nullptr;
    int mayor = 0;
    for (TAuxiliar sucu = clientesSucursalesLDE->inicio; sucu != nullptr; sucu = sucu->sig) {
        int total = cantidadClientesTClientesABB(sucu->clientesABB);
        int i = 1;
        while (i <= total) {
            TCliente clienteActual = obtenerNesimoClienteTClientesABB(sucu->clientesABB, i);
            int fre = contarFrecuenciaCliente(clientesSucursalesLDE, clienteActual->id);
            if (fre > mayor || (fre == mayor && clienteActual->id < cliente1->id)) {
                mayor = fre;
                cliente1 = clienteActual;
            }
            i++;
        }
    }

    return cliente1;
}
 