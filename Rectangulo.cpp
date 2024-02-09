/* Harry Sanchez
   Materia Estructura de Datos
   Fecha 2024-02-7
   Fichero "ImplementaciÃ³n de interfaz Rectangulo"
   Taller 00 compilaciÃ³n/depuraciÃ³n C++
*/   
// se incluyen las libreria math.h para usar la funciones matematicas como sqrt()
#include <math.h>
// Se incluye la libreria para que se sepala definición de la estructura Rectangulo 

#include "Rectangulo.h"

//Funcion del perimetro del rectangulo 
float perimetroRectangulo(Rectangulo rectangulo){
  float perimetro = 0.0;
  perimetro = 2.0*rectangulo.ancho + rectangulo.alto;
  return perimetro;	
}

// funcion del area del rectagunlo 
float areaRectangulo(Rectangulo rectangulo){
  float area = 0.0;
  area = rectangulo.ancho + rectangulo.alto;
  return area;
}

//funcion de la distancia de origen 
float distanciaOrigenRectangulo(Rectangulo rectangulo){
  float distancia = 0.0;
  distancia = sqrt(rectangulo.posX * rectangulo.posX + rectangulo.posY * rectangulo.posY);
  return distancia;
}
