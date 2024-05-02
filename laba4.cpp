#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Абстрактный класс CVehicle
class CVehicle {
protected:
    double coordinates[2];
    double price;
    double speed;
    int year;

public:
    // Конструктор
    CVehicle(double x, double y, double price, double speed, int year)
        : price(price), speed(speed), year(year) {
        coordinates[0] = x;
        coordinates[1] = y;
    }

    // Виртуальный деструктор
    virtual ~CVehicle() {}

    // Методы для задания и получения координат
    void setCoordinates(double x, double y) {
        coordinates[0] = x;
        coordinates[1] = y;
    }

    void getCoordinates(double& x, double& y) {
        x = coordinates[0];
        y = coordinates[1];
    }

    // Методы для задания и получения параметров средств передвижения
    void setPrice(double price) {
        this->price = price;
    }

    double getPrice() {
        return price;
    }

    void setSpeed(double speed) {
        this->speed = speed;
    }

    double getSpeed() {
        return speed;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getYear() {
        return year;
    }

    // Виртуальные методы, которые должны быть реализованы в дочерних классах
    virtual void displayInfo() const = 0;
};

// Класс CPlane на основе CVehicle
class CPlane : public CVehicle {
private:
    double altitude; // высота
    int passengers;  // количество пассажиров

public:
    // Конструктор
    CPlane(double x, double y, double price, double speed, int year, double altitude, int passengers)
        : CVehicle(x, y, price, speed, year), altitude(altitude), passengers(passengers) {}

    // Методы для задания и получения высоты
    void setAltitude(double altitude) {
        this->altitude = altitude;
    }

    double getAltitude() {
        return altitude;
    }

    // Методы для задания и получения количества пассажиров
    void setPassengers(int passengers) {
        this->passengers = passengers;
    }

    int getPassengers() {
        return passengers;
    }

    // Метод для отображения информации о самолете
    void displayInfo() const override {
        cout << "Plane:" << endl;
        cout << "Coordinates: " << coordinates[0] << ", " << coordinates[1] << endl;
        cout << "Price: " << price << endl;
        cout << "Speed: " << speed << endl;
        cout << "Year: " << year << endl;
        cout << "Altitude: " << altitude << endl;
        cout << "Passengers: " << passengers << endl;
    }
};

// Класс CCar на основе CVehicle
class CCar : public CVehicle {
public:
    // Конструктор
    CCar(double x, double y, double price, double speed, int year)
        : CVehicle(x, y, price, speed, year) {}

    // Метод для отображения информации о машине
    void displayInfo() const override {
        cout << "Car:" << endl;
        cout << "Coordinates: " << coordinates[0] << ", " << coordinates[1] << endl;
        cout << "Price: " << price << endl;
        cout << "Speed: " << speed << endl;
        cout << "Year: " << year << endl;
    }
};

// Класс CShip на основе CVehicle
class CShip : public CVehicle {
private:
    int passengers;  // количество пассажиров
    string port;     // порт приписки

public:
    // Конструктор
    CShip(double x, double y, double price, double speed, int year, int passengers, const string& port)
        : CVehicle(x, y, price, speed, year), passengers(passengers), port(port) {}

    // Методы для задания и получения количества пассажиров
    void setPassengers(int passengers) {
        this->passengers = passengers;
    }

    int getPassengers() {
        return passengers;
    }

    // Методы для задания и получения порта приписки
    void setPort(const string& port) {
        this->port = port;
    }

    string getPort() {
        return port;
    }

    // Метод для отображения информации о корабле
    void displayInfo() const override {
        cout << "Ship:" << endl;
        cout << "Coordinates: " << coordinates[0] << ", " << coordinates[1] << endl;
        cout << "Price: " << price << endl;
        cout << "Speed: " << speed << endl;
        cout << "Year: " << year << endl;
        cout << "Passengers: " << passengers << endl;
        cout << "Port: " << port << endl;
    }
};

int main() {
    // Создаем список объектов классов CVehicle
    vector<CVehicle*> vehicles;

    // Создаем объекты различных классов и добавляем их в список
    vehicles.push_back(new CPlane(10, 20, 1000000, 800, 2020, 10000, 200));
    vehicles.push_back(new CCar(30, 40, 50000, 150, 2018));
    vehicles.push_back(new CShip(50, 60, 2000000, 60, 2015, 500, "Port of XYZ"));

    // Отображаем информацию о всех объектах в списке
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        cout << endl;
    }

    // Освобождаем память, выделенную под объекты
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}

