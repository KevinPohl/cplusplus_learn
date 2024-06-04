#include <iostream>

class Thermometer {
    private:
        double temperatureCelsius;

    public:
        Thermometer(double tempC) : temperatureCelsius(tempC) {}

        double getCelsius() const {
            return temperatureCelsius;
        }

        double getFahrenheit() const {
            return temperatureCelsius * 9.0 / 5.0 + 32.0;
        }

        double getKelvin() const {
            return temperatureCelsius +273.15;
        }
};

int main(){
    // instatiate object
    Thermometer therm(25.0);

    // use class methods
    std::cout << "Temp in Celsius: " << therm.getCelsius() << " °C" << std::endl;
    std::cout << "Temp in Fahrenheit: " << therm.getFahrenheit() << " °F" << std::endl;
    std::cout << "Temp in Kelvin: " << therm.getKelvin() << " °K" << std::endl;

    return 0;
}