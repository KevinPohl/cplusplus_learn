#include "Measurement.h"
Measurement::Measurement() {value = 0.0;}

Measurement::Measurement(double v, const DayTime& t)
{
    value = v; time = t;
}

Measurement::Measurement(double v, int hr, int min, int sec)
{
    value = v;
    time = DayTime(hr, min, sec); // temporary object of type DayTime 
} 