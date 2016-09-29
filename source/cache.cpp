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

};

Cache::Cache(int n, int m, int k):asociatividad(n),sizeCache(m),sizeBloque(k){
    if(k%2 == 0){
      if((sizeCache/(sizeBloque*asociatividad))%2 == 0 || (sizeCache/(sizeBloque*asociatividad)) == 1){

        byteOffset = log2(k);
        NSets = sizeCache/(sizeBloque*asociatividad);
        bitIndex = log2(NSets);
        bitsTag = 32 - bitIndex - byteOffset;
    }
  } else {std::cerr << "Parámetros inválidos" << std::endl;}
};


Cache::~Cache(){
};
