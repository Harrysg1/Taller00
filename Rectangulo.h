/* Harry Sanchez
   Materia Estructura de Datos
  Fecha 2024-02-7
   Fichero "Interfaz Rectangulo"
   Taller 00 compilaciÃ³n/depuraciÃ³n C++
*/   

// Codigo que muestra que se esta difiniendo una interfaz  si no se a definido interfazrectangulo defina hasta donde esta el endif
#ifndef __INTERFAZRECTANGULO_H__
#define __INTERFAZRECTANGULO_H__
// Se define la estructura del rectangulo 
struct Rectangulo{
  float posX;
  float posY;
  int ancho;
  int alto;
};

// se muestran las firmas de las funciones las cuales estan definidas en el Rectangulo. cpp
float perimetroRectangulo(Rectangulo rectangulo);
float areaRectangulo(Rectangulo rectangulo);
float distanciaOrigenRectangulo(Rectangulo rectangulo);

#endif