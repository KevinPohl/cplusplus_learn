// DayTime displays time in hours, minutes and seconds
//------------------------------------------------------------------------------
#ifndef DAYTIME_H
#define DAYTIME_H

class DayTime
{
    private:
    short hour, minute, second;
    bool overflow;
    public:
    DayTime(int h = 0, int m = 0, int s = 0)
    {
        overflow = false;
        if(!setTime(h, m, s)) // this->setTime(...)
        hour = minute = second = 0; // hour is this->hour
    }

    bool setTime(int hour, int minute, int second = 0)
    {
        if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0
            && second < 60)
        {
            this->hour = (short)hour;
            this->minute = (short)minute;
            this->second = (short)second;
            return true;
        }
        else
            return false;
    }
    int getHour() const {return hour;}
    int getMinute() const {return minute;}
    int getSecond() const {return second;}
    
    // daytime in seconds
    int asSeconds() const {return (60*60*hour + 60*minute + second);}
    
    // compare *this with t
    // this->asSeconds() < t.asSeconds();
    bool isLess(DayTime t) const {return asSeconds() < t.asSeconds();}
};

#endif // DAYTIME_H