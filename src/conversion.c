#include "conversion.h"

double FLOUR_D = 0.6;
double SUGAR_D = 0.9;

double convert_to_ml(double g, char ingredient){
    double result = 0;
    if (ingredient == 'F'){
        result = g/FLOUR_D;
    }else if (ingredient == 'S') {
        result = g/SUGAR_D;
    }else{
        result = -1;
    }
    return result;
}


