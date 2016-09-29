#ifndef BLOQUE_H
#define BLOQUE_H

/**
 * Clase que representa un bloque de memoria
 */
class Bloque{

  public:
          /**
          * Constructor por defecto - Crea un bloque de tamaño 1
          */
          Bloque();
          /**
          * Constructor - crea un bloque de tamaño size
          */
          Bloque(int); /* Constructor - recibe un entero para el tamaño del bloque*/

          virtual ~Bloque(); // Destructor por defecto vacio

          /**
          * Metodo para escribir un tag en el bloque
          * @param  Numero del tag
          */
          void writeTag(unsigned long);
          /**
          * Metodo para leer el tag en el bloque
          * @return  El tag del bloque
          */
          unsigned long readTag();
          /**
          * Metodo para escribir el bit de valid del bloque
          * @param  Bit de valid - true or false
          */
          void writeValid(bool);
          /**
          * Metodo para leer el bit de valid en el bloque
          * @return  El bit de valid del bloque
          */
          bool readValid();

  private: // variables del Bloque

  /**
  * sizeBloque: tamaño del bloque de memoria
  */
  int sizeBloque;
  /**
  * tag: Tag de la direccion del bloque
  */
  unsigned long tag;
  /**
  * valid: bit de valid del bloque
  */
  bool valid;

};

#endif
