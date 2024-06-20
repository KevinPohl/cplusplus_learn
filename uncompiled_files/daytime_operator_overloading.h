//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
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
            hour = h;
            minute = m;
            second = s; 
        };

        bool setTime(int hour, int minute, int second = 0)
        {
            hour = hour;
            minute = minute;
            second = second; 
        };

        bool setTime_from_seconds(int second)
        {
            hour = second / 3600;
            second %= 3600;
            minute = second / 60;
            second %= 60;
            second = second; 
        };

        int getHour() const { return hour; }
        int getMinute() const { return minute; }
        int getSecond() const { return second; }
        int asSeconds() const // daytime in seconds
        {
            return (60*60*hour + 60*minute + second);
        }

        bool operator<(const DayTime& t) const
        {
            // compare *this with t
            return asSeconds() < t.asSeconds();
        }

        DayTime operator+(const DayTime& t) const
        {
            DayTime result;
            result.setTime_from_seconds(asSeconds() + t.asSeconds());
            return result;
        }

        DayTime& operator++()
        {
            // increase seconds, manage overflow
            ++second;
            return *this;
        }

        void print() const{
            std::cout
                << std::setw(2) << std::setfill('0') << getHour() << ":" 
                << std::setw(2) << std::setfill('0') << getMinute() << ":" 
                << std::setw(2) << std::setfill('0') << getSecond()
                << std::endl;
        }
};
#endif // DAYTIME_H