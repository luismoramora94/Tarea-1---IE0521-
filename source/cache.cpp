#include "cache.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Cache::Cache(){

  byteOffset = log2(sizeBloque);
  NSets = sizeCache/(sizeBloque*asociatividad);
  bitIndex = log2(NSets);
  bitsTag = 32 - bitIndex - byteOffset;

  asociatividad = 1;
  sizeCache = 64;
  sizeBloque = 32;

  misses = 0;
  hits = 0;

  std::vector<Bloque> columnas(NSets,Bloque(sizeBloque));
  std::vector<std::vector<Bloque>> arrayColumnas(asociatividad,columnas);

  cache = arrayColumnas;
};

Cache::Cache(int n, int m, int k):asociatividad(n),sizeCache(m),sizeBloque(k){
    if(k%2 == 0){
      if((sizeCache/(sizeBloque*asociatividad))%2 == 0 || (sizeCache/(sizeBloque*asociatividad)) == 1){

        byteOffset = log2(k);
        NSets = sizeCache/(sizeBloque*asociatividad);
        bitIndex = log2(NSets);
        bitsTag = 32 - bitIndex - byteOffset;

        misses = 0;
        hits = 0;

        std::vector<Bloque> columnas(NSets,Bloque(sizeBloque));
        std::vector<std::vector<Bloque>> arrayColumnas(asociatividad,columnas);

        cache = arrayColumnas;


      //  for(int i = 0; i<NSets; i++){
      //              for(int j = 0; j<asociatividad; j++){
      //                                            cache[i][j].writeTag(0);
      //      }

      //  }
    }
  } else {std::cerr << "Parámetros inválidos" << std::endl;}
};

Cache::~Cache(){};

void Cache::writeTag(int x, int y, unsigned long newtag){
            cache[x][y].writeTag(newtag);
};

void Cache::buscarTag(unsigned long newtag){

          bool hit = false;
          int randx; randx = rand();
          int randy; randy = randx%asociatividad;

          for(int i = 0; i<NSets; i++){
            for(int j = 0; j<asociatividad; j++){
                        if(cache[i][j].readValid() == true && newtag == cache[i][j].readTag()){
                            hit = true;
                            hits++;
                            return;
            }
          }


        }if(hit == false){
                reemplazarBloque(randx,randy,newtag);
                misses++;
              }

};

unsigned long Cache::readTag(int x, int y){
          return cache[x][y].readTag();
}

int Cache::readMisses(){
  return misses;
}

int Cache::readHits(){
  return hits;
}

bool Cache::readValid(int x, int y){
      return cache[x][y].readValid();
}


void Cache::reemplazarBloque(int x, int y, unsigned long newtag){
        writeTag(x,y,newtag);
        cache[x][y].writeValid(true);
}
