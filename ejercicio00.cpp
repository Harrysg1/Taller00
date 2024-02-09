// Se incluyen la libreria iostream para el uso de entradas y salidas
#include <iostream>
// Se incluye la libreria Rectangulo.h donde se encuentra la definicion de las funciones que nosotros creamos, por eso esta ""
#include "Rectangulo.h"

using namespace std;


int main(int argc, char* argv[]){
  /*Declaracion de variables*/
  Rectangulo rect1;

  
  //int a, b:Estas variables aparecian en el codigo original, pero no se usan en el codigo

  /*Ingreso de valores iniciales*/
  cout << "Ingrese coordenada X de la posicion del rectangulo: ";
  cin  >> rect1.posX;
  cout << "Ingrese coordenada Y de la posicion del rectangulo: ";
  cin  >> rect1.posY;
  cout << "Ingrese ancho del rectangulo: ";
  cin  >> rect1.ancho;
  cout << "Ingrese alto del rectangulo: ";
  cin  >> rect1.alto;

  /*Presentacion de los calculos haciendo uso de la interfaz, siendo esta Rectangulos.h */
  // Se presenta el perimetro, el area, y la distancia del rectagulo con repecto al origen de cordenadas llamando las funciones que estan en Rectangulo.h que su implementacion esta definida en Rectangulo.cpp
  cout << "\n Perimetro del rectangulo: \t" << perimetroRectangulo(rect1);
  cout << "\n area del rectangulo: \t" << areaRectangulo(rect1);
  cout << "\n Distancia del rectangulo al origen de coordenadas: \t" << distanciaOrigenRectangulo(rect1) << endl;

  return 0;
}