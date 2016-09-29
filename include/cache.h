#include "Bloque.h"
#include <cstring>
#include <vector>
#ifndef CACHE_H
#define CACHE_H


class Cache{

  public:

          Cache(); // Constructor por defecto - Crea una cache de mapeo directo, de 64 KB y tamaño de bloque de 32 B
          Cache(int, int, int); /* n es el grado de asociatividad:       1 - mapeo directo
                                                                         2 - 2 set way associative
                                                                         3 - 4 set way associative*/

          virtual ~Cache(); // Destructor por defecto vacio

          void writeTag(int, int, unsigned long); // escribe el tag en la posicion x,y
          unsigned long readTag(int, int);  // lee el tag en la posicion x,y

          int readMisses();
          int readHits();

          void reemplazarBloque(int, int, ); // Recibe 



  private: // variables del cache

  std::vector<std::vector<Bloque>> cache; // Cache formada por una matriz de objetos tipo bloque

  int asociatividad; // Datos de la estructura del cache
  int sizeCache;
  int sizeBloque;
  int NSets;


  int byteOffset; // Datos sobre las direcciones
  int bitIndex;
  int bitsTag;

  int misses; // Variables ontadores de hits y misses
  int hits;





};

#endif
