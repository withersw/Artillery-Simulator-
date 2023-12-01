//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__CONSTANTS_H
#define INC_230_07_LAB_GLDEMO__1__CONSTANTS_H

#include <map>

using namespace std;

class Constants {

public:

    // Constructor
    Constants(){}

    /*
     * GETTERS
     */
    map<double,double> getDrag(){
        return this->drag;
    };

    map<double,double> getDensity(){
        return this->density;
    };

    map<double,double> getSpeedOfSound(){
        return this->speedOfSound;
    };

    map<double,double> getGravity(){
        return this->gravity;
    };

    /*
     * GET VALUES FROM CONSTANTS
     * This function will receive
     */
    pair<double,double> getValueFromConstants(double altitude, map<double,double> table){

        // Creating result pair
        pair<double, double> result;

        // Setting the current value to begin;
        auto current = table.begin();

        // Creating a for loop and setting up a value called next
        // to hold the iterator next to current, so we can compare
        // the lower and upper value.
        for(auto next = std::next(current); next != table.end(); ++current, ++next){
            if(altitude >= current->first && altitude < next->first){
                result.first = current->first;
                result.second = next->first;
                return result;
            }
        }

        // If the result never received a value it means that is
        // higher than the last value, so we will set both values
        // to the last value
        if (result.second == 0){
            result.first = current->first;
            result.second = current->first;
        }

        // Return pair with the lower and upper value.
        return result;
    };

private:

    const map<double,double> drag = {
            {0.300, 0.1629},
            {0.500, 0.1659},
            {0.700, 0.2031},
            {0.890, 0.2597},
            {0.920, 0.3010},
            {0.960, 0.3287},
            {0.980, 0.4002},
            {1.000, 0.4258},
            {1.020, 0.4335},
            {1.060, 0.4483},
            {1.240, 0.4064},
            {1.530, 0.3663},
            {1.990, 0.2897},
            {2.870, 0.2297},
            {2.890, 0.2306},
            {5.000, 0.2656}
    };

    const std::map<double,double> density = {
            {0.0, 1.225},
            {1000.0, 1.112},
            {2000.0, 1.007},
            {3000.0, 0.9093},
            {4000.0, 0.8194},
            {5000.0, 0.7364},
            {6000.0, 0.6601},
            {7000.0, 0.59},
            {8000.0, 0.5258},
            {9000.0, 0.4671},
            {10000.0, 0.4135},
            {15000.0, 0.1948},
            {20000.0, 0.08891},
            {25000.0, 0.04008},
            {30000.0, 0.01841},
            {40000.0, 0.003996},
            {50000.0, 0.001027},
            {60000.0, 0.0003097},
            {70000.0, 0.0000828},
            {80000.0, 0.0000185}
    };

    const std::map<double,double> speedOfSound = {
            {0.0, 340.0},
            {1000.0, 336.0},
            {2000.0, 332.0},
            {3000.0, 328.0},
            {4000.0, 324.0},
            {5000.0, 320.0},
            {6000.0, 316.0},
            {7000.0, 312.0},
            {8000.0, 308.0},
            {9000.0, 303.0},
            {10000.0, 299.0},
            {15000.0, 295.0},
            {20000.0, 295.0},
            {25000.0, 295.0},
            {30000.0, 305.0},
            {40000.0, 324.0}
    };
    const std::map<double,double> gravity = {
            {0.0, 9.807},
            {1000.0, 9.804},
            {2000.0, 9.801},
            {3000.0, 9.797},
            {4000.0, 9.794},
            {5000.0, 9.791},
            {6000.0, 9.788},
            {7000.0, 9.785},
            {8000.0, 9.782},
            {9000.0, 9.779},
            {10000.0, 9.776},
            {15000.0, 9.761},
            {20000.0, 9.745},
            {25000.0, 9.730}
    };

};


#endif //INC_230_07_LAB_GLDEMO__1__CONSTANTS_H
