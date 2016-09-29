#include "cache.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Cache::Cache(){

  asociatividad = 1;
  sizeCache = 64;
  sizeBloque = 32;
  NSets = 1;

  byteOffset = 1;
  bitIndex = 1;
  bitsTag = 1;

  misses = 0;
  hits = 0;

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


        for(int i = 0; i<asociatividad; i++){
                    for(int j = 0; j<NSets; j++){
                                                  cache[i][j].writeTag(0);
            }

        }
    }
  } else {std::cerr << "Parámetros inválidos" << std::endl;}
};

Cache::~Cache(){};

void Cache::writeTag(int x, int y, unsigned long tag){
          cache[x][y].writeTag(tag);
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
        
}




int main(){};
