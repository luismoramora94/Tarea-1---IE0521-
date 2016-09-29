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

          //virtual void buscar();
          //virtual void push();
          //virtual void pop();
          //virtual void sacarbloque();
          //virtual void meterbloque();

  private: // variables del cache

  vector<vector<Bloque>> cache;

  int asociatividad;
  int sizeCache;
  int sizeBloque;
  int byteOffset;
  int NSets;
  int bitIndex;

};

#endif
