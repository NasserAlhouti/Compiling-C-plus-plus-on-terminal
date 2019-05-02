#ifndef Velociplotter_h
#define Velociplotter_h

#include <iostream>
#include <vector>
#include "GpsPosition.h"
class Velociplotter{
  private:
  public:
    Velociplotter();
}; 
void readInputFile(std::ifstream *ifs , std::vector <GpsPosition *> *position);
bool validateVector(std::vector <GpsPosition *> *position);
void produceOutput(std::vector <GpsPosition *> *position,std::ofstream *out);
void freeVector(std::vector <GpsPosition *> *position);
#endif /* name_hpp */

