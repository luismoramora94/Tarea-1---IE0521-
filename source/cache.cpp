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
  string DatosCache = "hola";

};

Cache::Cache(int n, int m, int k):asociatividad(n),sizeCache(m),sizeBloque(k){
    byteOffset = log2(k);
    NSets = sizeCache/(sizeBloque*asociatividad);
    bitIndex = log2(NSets);
};


Cache::~Cache(){
};

int main(){
  Cache c1();
//  std::cout <<c1.DatosCache<< std::endl;
};

// void Cache::buscar();
//void Cache::push();
//void Cache::pop();
//void Cache::sacarbloque();
//void Cache::meterbloque();
