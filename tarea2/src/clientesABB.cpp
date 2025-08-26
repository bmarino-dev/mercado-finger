#include "../include/clientesABB.h"

struct rep_clientesABB {
    TCliente elem;
    rep_clientesABB *izq;
    rep_clientesABB *der;
};
struct rep_cliente {
    int id , edad; char nombre[MAX_NOMBRE ] , apellido[MAX_APELLIDO];
};

TClientesABB crearTClientesABBVacio(){
    return NULL;
}

void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente){
    
    if (clientesABB == NULL){
        clientesABB = new rep_clientesABB;
        clientesABB->elem = cliente;
        clientesABB->izq = NULL;
        clientesABB->der = NULL;
    } else if (clientesABB->elem->id < cliente->id){
        insertarTClienteTClientesABB(clientesABB->der , cliente);
    } else if (clientesABB->elem->id > cliente->id){
        insertarTClienteTClientesABB(clientesABB->izq , cliente);
    }
    
    

}

void imprimirTClientesABB(TClientesABB clientesABB){
    if (clientesABB != NULL){
        imprimirTClientesABB(clientesABB->izq);
        imprimirTCliente(clientesABB->elem);
        imprimirTClientesABB(clientesABB->der);
    }
    
}

void liberaridividual(TClientesABB &clientesABB){
    if (clientesABB != nullptr){
    liberarTCliente(clientesABB->elem);
        delete clientesABB;
        clientesABB = NULL;
    }
}







void liberarTClientesABB(TClientesABB &clientesABB){
      if (clientesABB == NULL) {
        return;
    } else {
        liberarTClientesABB(clientesABB->izq);
        liberarTClientesABB(clientesABB->der);
        liberarTCliente(clientesABB->elem);  // Liberar el cliente del nodo
        delete clientesABB;  // Liberar el nodo
        clientesABB = NULL;
    }
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    while ((clientesABB != NULL) && (clientesABB->elem->id != idCliente)){
        if(clientesABB->elem->id > idCliente){
           clientesABB = clientesABB->izq; 
        }else clientesABB = clientesABB->der; 
    }
    if (clientesABB == NULL){
        return false;
    }else return true;
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if (existeTClienteTClientesABB(clientesABB , idCliente) == false){
    return NULL;
    }
    while(clientesABB->elem->id != idCliente){
        if(clientesABB->elem->id > idCliente){
           clientesABB = clientesABB->izq; 
        }else clientesABB = clientesABB->der;
    }return clientesABB->elem;
}
 int max(int x , int y){
if (x > y){
    return x;
}else return y;

 }


nat alturaTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL){
        return 0;
    }
    
    int alturaizq = alturaTClientesABB(clientesABB->izq);
    int alturader = alturaTClientesABB(clientesABB->der);
    return max(alturader , alturaizq) + 1;
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB){
    while (clientesABB->der != NULL){
        clientesABB = clientesABB->der;
    }
    
    return clientesABB->elem;
}


 TClientesABB maximoid(TClientesABB  clientesABB){
     while (clientesABB->der != NULL){
        clientesABB = clientesABB->der;
    }
    
    return clientesABB;
 }




void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente){
if (clientesABB == nullptr) {
        return;
    } 
    if (clientesABB->elem->id > idCliente) {
        removerTClienteTClientesABB(clientesABB->izq, idCliente);
    } else if (clientesABB->elem->id < idCliente) {
        removerTClienteTClientesABB(clientesABB->der, idCliente);
    } else {
        // Nodo encontrado
        if (clientesABB->izq == NULL && clientesABB->der == NULL) {// Liberar el cliente
            liberarTCliente(clientesABB->elem);
            delete clientesABB;
            clientesABB = nullptr;
        }
        else if (clientesABB->izq == NULL) {
            TClientesABB temp = clientesABB;
            clientesABB = clientesABB->der;
            liberarTCliente(temp->elem); // Liberar el cliente
            delete temp;
            temp = nullptr;
        } else if (clientesABB->der == NULL) {
            TClientesABB temp = clientesABB;
            clientesABB = clientesABB->izq;  // Liberar el cliente
            liberarTCliente(temp->elem);
            delete temp;
            temp = nullptr;
        } else {
            TClientesABB temp = maximoid(clientesABB->izq);  // Liberar el cliente actual antes de reemplazarlo
            TCliente y = clientesABB->elem;
            TCliente x = new rep_cliente;
            x->id = temp->elem->id;
            clientesABB->elem = temp->elem;
            temp->elem = x;
            liberarTCliente(y);
            x = nullptr;
            removerTClienteTClientesABB(clientesABB->izq, temp->elem->id);
        }
    }
}


int cantidadClientesTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL){
    return 0;
    } else {
        return 1 + cantidadClientesTClientesABB(clientesABB->izq) + cantidadClientesTClientesABB(clientesABB->der);
    }
}
int sumaredades(TClientesABB clientesABB){
    if (clientesABB == NULL){
    return 0;
    } else {
        return clientesABB->elem->edad + sumaredades(clientesABB->izq) + sumaredades(clientesABB->der);
    }
}


float edadPromedioTClientesABB(TClientesABB clientesABB){
    int totalClientes = cantidadClientesTClientesABB(clientesABB);  
    if (totalClientes == 0) {
        return 0.0f; 
    }

    int sumaEdades = sumaredades(clientesABB);  

    
    return (float)sumaEdades / totalClientes;
}
 
void inOrderRec(TClientesABB nodo, int &cont, int n, TCliente &res) {
        if (nodo == NULL || res != NULL) {
            return;
        }
        inOrderRec(nodo->izq, cont, n, res);

        cont++;
        if (cont == n) {
            res = nodo->elem; 
            return;
        }

        inOrderRec(nodo->der, cont, n, res);
    }

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n){
     int cont = 0;
    TCliente cliente_n = NULL;
     inOrderRec(clientesABB, cont, n, cliente_n);

    return cliente_n;
}

