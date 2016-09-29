#include "Bloque.h"
#include "cache.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char* argv[]){

  int misses;
  int hits;
  // int parametros[3];

  //for(int i =0; i<3; i++){
	//	parametros[i] = atoi(argv[i+1]);
	//}

  // Cache C1(parametros[0], parametros[1], parametros[2]);//  1, 32, 64
Cache C1(1, 32, 64);
  // ifstream file("prueba.trace");


  misses = C1.readMisses();
  hits = C1.readHits();

  //C1.writeTag(0,0,12);
  // C1.buscarTag(0xF);

  // std::cout << "Cache: " << C1.readTag(0,0) << hits << std::endl;
  std::cout << "Hits: " << hits << std::endl;
  std::cout << "Misses: " << misses << std::endl;


}
