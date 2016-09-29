#include "Bloque.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>



using namespace std;

Bloque::Bloque(){
  sizeBloque = 1;
  tag = 0;
  valid = false;

};

Bloque::Bloque(int size):sizeBloque(size){

};

Bloque::~Bloque(){
};

void Bloque::writeTag(unsigned long T){
    this->tag = tag;
};

unsigned long Bloque::readTag(){
    return this->tag;

};

void Bloque::writeValid(bool valid){
    this->valid = valid;
};

bool Bloque::readValid(){
      return this->valid;
};
