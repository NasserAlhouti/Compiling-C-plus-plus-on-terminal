#include "GpsPosition.h"

GpsPosition::GpsPosition(double latitudeStamp,double longitudeStamp,unsigned long timeSeconds){
 this-> latitude= latitudeStamp;
 this -> longitude= longitudeStamp;
 this -> timeSeconds = timeSeconds;
}
    void GpsPosition::SetLatitude(double latitude){
     this->latitude = latitude ;
    }
    void GpsPosition::SetLongitude(double longitude){
    this->longitude = longitude;
    } 
    void GpsPosition::SetTime(double timeSeconds){
    this->timeSeconds = timeSeconds;
    }
    double GpsPosition::GetLongitude(){
    return longitude;
    }
    unsigned long GpsPosition::GetTime(){
    return timeSeconds;
    }

double GpsPosition::GetLatitude(){
return latitude;
}
double GpsPosition::CalcDistanceKmTo(GpsPosition toPosition){   const double EarthRadiusKm = 6371.0;
  
  const double PI = 3.14159265358979323846;
  double fromLatitudeRad;
  double fromLongitudeRad;
  double toLatitudeRad;
  double toLongitudeRad;
  double deltaLatitude;
  double deltaLongitude;
  double a;
  double c;
  
  // Convert to radians 
   fromLatitudeRad = PI * this->GetLatitude() / 180.0;
   fromLongitudeRad = PI * this->GetLongitude() / 180.0;
   
   toLatitudeRad = PI * toPosition.GetLatitude() / 180.0;
   
   toLongitudeRad = PI * toPosition.GetLongitude() / 180.0;
  // 
   //Calculate delta for latituce and longitude   
   deltaLatitude = toLatitudeRad - fromLatitudeRad;
   deltaLongitude = toLongitudeRad - fromLongitudeRad;
  // Calculate great-circle distance using haversine formula   
  a = ( sin(deltaLatitude / 2) * sin(deltaLatitude / 2) ) +   ( sin(deltaLongitude / 2) * sin(deltaLongitude / 2) *    cos(fromLatitudeRad) * cos(toLatitudeRad) );
  //
  c = 2 * atan2(sqrt(a), sqrt(1-a));
  // 
   return EarthRadiusKm * c;
}
