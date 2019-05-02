//
//  name.hpp
//  example
//
//  Created by nasser alhouti on 4/28/19.
//  Copyright © 2019 nasser alhouti. All rights reserved.
//

#ifndef GpsPosition_h
#define GpsPosition_h

#include <iostream>
#include <math.h>
class GpsPosition {
  private:  
    double latitude;
    double longitude;
    unsigned long timeSeconds;
  public:
    GpsPosition();   
    GpsPosition(double latitude, double longitude, unsigned long timeSeconds);
    double GetLatitude(); 
    double GetLongitude(); 
    unsigned long GetTime(); 
    void SetLatitude(double latitude); 
    void SetLongitude(double longitude); 
    void SetTime(double timeSeconds);
    double CalcDistanceKmTo(GpsPosition toPosition);};
#endif /* name_hpp */
