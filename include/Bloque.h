#ifndef BLOQUE_H
#define BLOQUE_H


class Bloque{

  public:

          Bloque(); // Constructor por defecto - Crea un bloque de tamaño uno, tag 1 y valid false.

          Bloque(int); /* Constructor - recibe un entero para el tamaño del bloque*/

          virtual ~Bloque(); // Destructor por defecto vacio

          void writeTag(unsigned long);
          unsigned long readTag();

          void writeValid(bool);
          bool readValid();

  private: // variables del Bloque

  int sizeBloque;
  unsigned long tag;
  bool valid;

};

#endif
