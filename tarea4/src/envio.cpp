#include "../include/envio.h"

struct rep_envio {
  TCarritoProductos carrito;
  TFecha fecha;
};

TEnvio crearTEnvio(TCarritoProductos carrito, TFecha fecha) {
  TEnvio nuevoenvio = new rep_envio;
  nuevoenvio->carrito = carrito;
  nuevoenvio->fecha = fecha;
  return nuevoenvio;
}

void liberarTEnvio(TEnvio &envio) {
  liberarCarritoProductos(envio->carrito);
  envio->carrito = NULL;
  liberarTFecha(envio->fecha);
  envio->fecha = NULL;
  delete envio;
  envio = NULL;

}

TCarritoProductos obtenerCarritoProductosTEnvio(TEnvio envio) {
   return envio->carrito; }

TFecha obtenerFechaTEnvio(TEnvio envio) {
  return envio->fecha; }

void imprimirTEnvio(TEnvio envio) {
imprimirCarritoProductos(envio->carrito);
printf("\n");
printf("Fecha del envio: ");
imprimirTFecha(envio->fecha);
printf("\n");
}
