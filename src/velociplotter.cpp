#include "velociplotter.h"
#include <fstream>
#include <iostream>
using namespace std;
bool validateVector(std::vector <GpsPosition *> *position){
  for (size_t i = 0 ; i < position->size()-1;i++){
    GpsPosition *left = position->at(i);
    GpsPosition *right = position->at(i+1);
    if(left->GetTime() > right->GetTime()){
      return false;
    }

  }
  return true;

}
void produceOutput(std::vector <GpsPosition *> *position,std::ofstream *out){

  for (size_t i = 0 ; i < position->size()-1;i++){
    GpsPosition *left = position->at(i);
    GpsPosition *right = position->at(i+1);
    cout << left->GetLatitude() << " " << right->GetLatitude() << endl;
    unsigned long t_right = right->GetTime();
    unsigned long t_left = left->GetTime();
    // calcuate Average speed
    double dx = left->CalcDistanceKmTo(*right);
    unsigned long  dt = t_right - t_left;
    double speed = dx/((double)dt /3600);
    // for every integer second in between t_left and t_right statring with 1 r
    for (unsigned long t_curr = t_left +1 ; t_curr < t_right+1;t_curr++){

      ( *out) <<(t_curr )<< " "<<(speed)<<(endl);

    }
  }
}
void freeVector(std::vector <GpsPosition *> *position){
  for (size_t i = 0 ; i < position->size();i++){
    delete position->at(i); 
  }
}
