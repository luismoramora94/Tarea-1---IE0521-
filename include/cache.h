#include "Bloque.h"
#include <cstring>
#include <vector>
#ifndef CACHE_H
#define CACHE_H

/**
 * Clase que representa una memoria cache hecha de diferentes objetos tipo Bloque de memoria
 */
class Cache{

  public:
            /**
            * Constructor por defecto - crea un cache de mapeo directo, de tamaño de 64 kB y bloques de tamaño de 32 B
            */
          Cache();
          /**
          * Constructor:      n es el grado de asociatividad del cache:  1 - mapeo directo
                                                                         2 - 2 set way associative
                                                                         3 - 4 set way associative

                              m es el el tamaño del cache en kB y k es el tamaño del bloque
                                                                         */
          Cache(int, int, int);

          virtual ~Cache();

          /**
          * Metodo para escribir un tag en un bloque específico del cache
          * @param  x el numero de set
          * @param  y el numero de columna
          * @param  newtag el tag a escribir
          */
          void writeTag(int, int, unsigned long);
          /**
          * Metodo para leer el tag en un bloque específico del cache
          * @param  x el numero de set
          * @param  y el numero de columna
          * @return  el tag del bloque
          */
          unsigned long readTag(int, int);
          /**
          * Metodo para buscar un tag en el cache
          * @param  el tag a buscar
          */
          void buscarTag(unsigned long);
          /**
          * Metodo para leer cuantos misses lleva el cache
          * @return  el numero de misses
          */
          int readMisses();
          /**
          * Metodo para leer cuantos hits lleva el cache
          * @return  el numero de hits
          */
          int readHits();

          /**
          * Metodo para reemplazar un bloque del cache, dejando el valid bit en 1
          * @param x el numero set
          * @param y el numero de columna
          * @param newtag el tag a reemplazar
          */
          void reemplazarBloque(int, int, unsigned long);
          /**
          * Metodo para escribir sobre el valid bit de un bloque del cache
          * @param x el numero set
          * @param y el numero de columna
          * @param newtag el tag a reemplazar
          */
          void writeValid(int, int, bool);
          /**
          * Metodo para leer el valid bit de un bloque del cache
          * @param x el numero set
          * @param y el numero de columna
          * @return el valid bit del bloque
          */
          bool readValid(int, int); // Lee el valid bit de un bloque en las coordenadas x,y


  private: // variables del cache

  std::vector<std::vector<Bloque>> cache; // Cache formada por una matriz de objetos tipo bloque

  int asociatividad; // Datos de la estructura del cache
  int sizeCache;
  int sizeBloque;
  int NSets;


  int byteOffset; // Datos sobre las direcciones
  int bitIndex;
  int bitsTag;

  int misses; // Variables contadoras de hits y misses
  int hits;

};

#endif
