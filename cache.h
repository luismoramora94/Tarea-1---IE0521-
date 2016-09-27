#ifndef CACHE_H
#define CACHE_H


class Cache{

  public:

          Cache(); // Constructor por defecto
          Cache(int n); // n es el grado de asociatividad
          Cache(const Cache &other); // constructor por copia

          virtual ~Cache();

          virtual void buscar();
          virtual void sacarbloque();
          virtual void meterbloque();

  private: // variables del cache

  int asociatividad;
  int sizeCache;
  int sizeBloque;
  char *direcciones;

};

#endif
