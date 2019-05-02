//
//  main.cpp
//  example
//
//  Created by nasser alhouti on 4/28/19.
//  Copyright © 2019 nasser alhouti. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
#include <string>
#include "GpsPosition.h"
#include "velociplotter.h"
using namespace std;
int main(int argc, const char * argv[]) {

	vector <GpsPosition*> gpsCordinates;
	ifstream file1(argv[1]);
	string line;
	string trash;

	while(getline(file1,line)){
		stringstream ss;
		unsigned long timeSeconds;
		double longitudeStamp;
		double latitudeStamp;
		unsigned long hours;
		unsigned long minutes;
		unsigned long seconds;
		stringstream converter;
		ss = stringstream(line);
		string result; 
		getline(ss,result,',');

		if(result.compare("$GPGGA") == 0){
			// read the time
			string timeToken;
			getline(ss,timeToken,',');

			// convert to unsigned long
			converter << timeToken;
			converter >> timeSeconds;

			// store time as seconds
			hours = timeSeconds/10000;
			minutes = (timeSeconds/100)%100;
			seconds = timeSeconds % 100;
			timeSeconds = hours * 3600 + minutes * 60 + seconds;

			// read the latitude
			string latitudeConverter;
			getline(ss,latitudeConverter,',');

			// find the index of the decimal point
			int latitudeDotPos;
			latitudeDotPos = latitudeConverter.find('.');

			// split the latitude token into two parts: the whole degrees part,
			// and the minutes part
			string latitudeWholeDegreesToken;
			string latitudeMinutesToken;
			latitudeWholeDegreesToken = latitudeConverter.substr(0, latitudeDotPos - 2);
			latitudeMinutesToken = latitudeConverter.substr(latitudeDotPos - 2);

			// parse the latitude whole degrees and minutes with fraction,
			// storing the final result as degrees
			stringstream(latitudeConverter) >> latitudeStamp;
			int latitudeWholeDegrees;
			double latitudeMinutes;
			stringstream(latitudeWholeDegreesToken) >> latitudeWholeDegrees;
			stringstream(latitudeMinutesToken) >> latitudeMinutes;
			latitudeStamp = (double)latitudeWholeDegrees + latitudeMinutes / 60;

			// skip N
			getline(ss,trash,',');

			// read the longitude
			string longitudeConverter;
			getline(ss,longitudeConverter,',');

			// find the index of the decimal point
			int longitudeDotPos;
			longitudeDotPos = longitudeConverter.find('.');

			// split the longitude token into two parts: the whole degrees part,
			// and the minutes part
			string longitudeWholeDegreesToken;
			string longitudeMinutesToken;
			longitudeWholeDegreesToken = longitudeConverter.substr(0, longitudeDotPos - 2);
			longitudeMinutesToken = longitudeConverter.substr(longitudeDotPos - 2);

			// parse the longitude whole degrees and minutes with fraction,
			// storing the final result as degrees
			stringstream(longitudeConverter) >> longitudeStamp;
			int longitudeWholeDegrees;
			double longitudeMinutes;
			stringstream(longitudeWholeDegreesToken) >> longitudeWholeDegrees;
			stringstream(longitudeMinutesToken) >> longitudeMinutes;
			longitudeStamp = (double)longitudeWholeDegrees + longitudeMinutes / 60;

			// instantiate GPs and add to vector 
			GpsPosition *position = new GpsPosition(latitudeStamp,longitudeStamp,timeSeconds);
			gpsCordinates.push_back(position);
		}

	} 
	// for (size_t i = 0 ; i <gpsCordinates.size();i++){
	//   cout << gpsCordinates.at(i)->GetTime()<<endl;
	// }

	//for (size_t i = 0 ; i <gpsCordinates.size();i++){
	//	cout << gpsCordinates.at(i)->toString() << endl;
	//}

	if(gpsCordinates.size() == 0 || !validateVector(&gpsCordinates)){
		cout << "Error : bad input file";
		ofstream ofs(argv[2]);
		ofs << "";
		ofs.close();

		return 1;
	}

	ofstream ofs(argv[2]);
	produceOutput(&gpsCordinates,&ofs);
	ofs.close();
	freeVector(&gpsCordinates);
	return 0;
}
