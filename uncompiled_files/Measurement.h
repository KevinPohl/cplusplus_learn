// Messwert.h
// Die Klasse Messwert zur Darstellung eines Messwerts
// mit dem Zeitpunkt der Messung.
// class Measurement for display of a measure
//------------------------------------------------------------------------------
#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include "daytime_this_pointer.h" // class DayTime

class Measurement
{
    private:
        double value;
        DayTime time;
    
    public:
        // default constructor
        Measurement();
        // Measurement(double v, const DayTime& t = currentTime()); // current time not included
        Measurement(double v, int hr, int min, int sec);

        double getValue() const
        {
            return value;
        }

        void setValue(double v)
        {
            value = v;
        }

        const DayTime& getTime() const
        {
            return time;
        }

        void setTime(const DayTime& t)
        {
            time = t;    
        }
        
        bool setTime(int hr, int min, int sec)
        {
            return time.setTime( hr, min, sec);
        }
        
        // print value and time
        void print() const;
};

#endif // MEASUREMENT_H



