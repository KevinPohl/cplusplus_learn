// Definition of base class Vehicle and derived class PersonalCar
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// base class
class Vehicle
{
    private:
        long vehicle_number;
        string manufacturer;
    
    public:
        // constructor
        Vehicle(long n = 0L, const string& m = "")
        {
            vehicle_number = n;
            manufacturer = m;
        };

        // setter/getter
        long getNr(void) const { return vehicle_number; }
        void setNr( long n ) { vehicle_number = n; }
        const string& getManufacturer() const{ return manufacturer; }
        void setManufacturer(const string& m){ manufacturer = m; }
        
        // display vehicle
        void display() const;
};

// derived class
class PersonalCar : public Vehicle
{
    private:
        string pkwType;
        bool sun_roof;
    
    public:
        // constructor
        PersonalCar(const string& tp, bool sd, long n = 0,
            const string& h = "");
        
        // setter/getter
        const string& getType() const { return pkwType; }
        void setType( const string type) { pkwType = type; }
        bool getSchiebe() const { return sun_roof; }
        void setSchiebe( bool sunroof){ sun_roof = sunroof; }
        void display() const;
};

void Vehicle::display(void) const
{
    cout << "Manufacturer: " << manufacturer;
    cout << "\nVehicle Number: " << vehicle_number << endl;
}

void PersonalCar::display( void) const
{
    Vehicle::display(); // mothod of base class
    cout << "Type: " << pkwType;
    cout << "\nSun roof: ";
    if(sun_roof)
        cout << " yes "<< endl;
    else
        cout << " no " << endl;
}

// // first version of constructor of PersonalCar
// //------------------------------------------------------------------------------
// PersonalCar::PersonalCar(const string& tp, bool sd, long n, const string& hs)
// {
//     // init values for elements of base class
//     setNr(n);
//     setManufacturer(hs);
    
//     // init values for elements of derived class
//     pkwType = tp;
//     sun_roof = sd;
// }

// // second version of constructor of PersonalCar
// //------------------------------------------------------------------------------
// PersonalCar::PersonalCar(const string& tp, bool sd, long n, const string& hs)
// : Vehicle(n, hs) // using constructor of base class
// {
//     // init values for elements of derived class
//     pkwType = tp;
//     sun_roof = sd;
// }

// third version of constructor of PersonalCar
//------------------------------------------------------------------------------
PersonalCar::PersonalCar(const string& tp, bool sd, long n, const string& hs)
: Vehicle(n, hs), pkwType(tp), sun_roof(sd)
{
    // nothing else to do, used constructor of base class and rewritten
    // initialization of private attributes of derived class
}

int main()
{
    const PersonalCar kaefer("New Beatle", false, 3421L, "VW");
    kaefer.display();
    cout << "\nvehicle number by getter: " 
        << kaefer.getNr() << "\n" << endl;

    PersonalCar cabrio("Carrera", true);
    cabrio.setNr(1000L);
    cabrio.setManufacturer("Porsche");
    cabrio.display();
    cout << "\nBase class data only:\n";
    cabrio.Vehicle::display();
    cout << "\nvehicle number by getter: " 
        << cabrio.getNr() << "\n" << endl;
    return 0;
}

