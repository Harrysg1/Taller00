/* Autor Harry Sanchez
   Materia Estructura de Datos
   Fecha 2024-02
   Fichero que contiene modificatión del ejemplo usado para el tutorial "debuggin".
   Autor del tutorial Gilpin, agg1@cec.wustl.edu
   Taller 00 compilación/depuración C++
*/

#include <iostream>

using namespace std;

// Este codigo usa una lista enlazada simple utilizando templates, lo que le permite almacenar elementos de cualquier tipo. La estructura se compone de nodos (Node), y una lista enlazada (LinkedList) que maneja estos nodos.
int numb_inst = 0;
// Aqui se define un template que permite escribir código que puede trabajar con cualquier tipo de datos. Se entra un class tipo T
template <class T> class Node {
  public:
// Se Inicializa un nodo con un valor y un puntero opcional al siguiente nodo. Al crear un nodo, incrementa un contador global numb_inst que lleva la cuenta de cuántos nodos existen en ese momento y muestra un mensaje que es lo que vemos en consola de cuando cramos o eliminamos un nodo.
      Node (const T &value, Node<T> *next = 0) {
        value_ = value;
        next_ = next;
        cout << "Creating Node, " << ++numb_inst << " are in existence right now" << endl;
    }
// el simbolo atras muestra que es un destructor
      ~Node () {
        cout << "Destroying Node, " << --numb_inst << " are in existence right now" << endl;
        next_ = 0;
      }

      Node<T>* next () const {
        return next_;
      }

      void next (Node<T> *new_next) {
        next_ = new_next;
      };

    const T& value () const {
      return value_;
      }

    void value (const T &value) {
        value_ = value;
      }

  private:
      Node ();
      T value_;
      Node<T> *next_;
};

template <class T> class LinkedList {

  public:
//Inicializa la lista enlazada con head_ apuntando a 0 (o nullptr), indicando una lista vacía.
      LinkedList () : head_(0) {};
//Destructor para liberar la memoria de todos los nodos antes de que el objeto LinkedList sea destruido.
      ~LinkedList () { delete_nodes (); };

      // returns 0 on success, -1 on failure
//Añade un nuevo elemento al principio de la lista.0 si lo hace bien
      int insert (const T &new_item) {
        return ((head_ = new Node<T>(new_item, head_)) != 0) ? 0 : -1;
      }

      // returns 0 on success, -1 on failure
//Aqui se remueve el elemento
      int remove (const T &item_to_remove) {
        Node<T> *marker = head_;
        Node<T> *temp = 0;  // temp points to one behind as we iterate

        while (marker != 0) {
            if (marker->value() == item_to_remove) {
              if (temp == 0) { // marker is the first element in the list
                  if (marker->next() == 0) {
                    head_ = 0;
                    delete marker; // marker is the only element in the list
                    marker = 0;
                  } else {
                    head_ = new Node<T>(marker->value(), marker->next());
                    delete marker;
                    marker = 0;
                  }
                  return 0;
              } else {
                  temp->next (marker->next());
                  //delete temp;error
                  delete marker;
                  temp = 0;
                  return 0;
              }
          }
          marker = 0;  // reset the marker
          temp = marker;
          marker = temp->next();
          //marker = marker->next(); error
      }
      return -1;    // failure
    }


//Imprime todos los valores de los nodos en la lista.
    void print (void) {
      Node<T> *marker = head_;
      while (marker != 0) {
          cout << marker->value() << endl;
          marker = marker->next();
      }
    }

  private:
// Llamado por el destructor para eliminar todos los nodos de la lista y liberar la memoria asociada.
      void delete_nodes (void) {
        Node<T> *marker = head_;
        while (marker != 0) {
            Node<T> *temp = marker;
            delete marker;
            marker = temp->next();
        }
      }

      Node<T> *head_;
  };

int main (int argc, char **argv) {
    LinkedList<int> *list = new LinkedList<int> ();
// Aqui se ingresan los datos
    list->insert (1);
    list->insert (2);
    list->insert (3);
    list->insert (4);
// se imprime la lista
    cout << "The fully created list is:" << endl;
    list->print ();
// le eliminan los elementos
    cout << endl << "Now removing elements:" << endl;
    list->remove (4);
    list->print ();
    cout << endl;

    list->remove (1);
    list->print ();
    cout << endl;

    list->remove (2);
    list->print ();
    cout << endl;

    list->remove (3);
    list->print ();
//se elimina la lista 
    delete list;

    return 0;
}
