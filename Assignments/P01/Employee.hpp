///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jered Stevens
// Email:            jstevens@altruiststudios.com
// Title:            c_Employee
// Semester:         Spring 2023
// Date:             7 March 2023
//
// Description:
//       This is a class to store person info. To be 
//          used in conjunction with c_AvlTree.cpp and TreeManager.hpp
//       
// Usage: 
//      This file is not meant to be used on its own.
//      Refer to TreeManager.hpp for usage.
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

class c_Employee
{
private:
    int ID;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string address;
    std::string city;
    std::string state;
    double latitude;
    double longitude;
    std::string car;
    std::string carModel;
    std::string carColor;
    std::string favMovie;
    std::string pet;
    std::string jobTitle;
    std::string phoneNumber;
    std::vector<std::string> stocks;

public:
    c_Employee();
    c_Employee(int id, std::string fName, std::string lName, std::string ema,
               std::string add, std::string cit, std::string sta, double lat,
               double lon, std::string cCar, std::string cMod, std::string cCol,
               std::string fav, std::string pPet, std::string job, std::string pho);
    c_Employee *getEmployee();
    void setID(int id);
    int getID();
    void setFirstName(std::string fName);
    std::string getFirstName();
    void setLastName(std::string lName);
    std::string getLastName();
    void setEmail(std::string ema);
    std::string getEmail();
    void setAddress(std::string add);
    std::string getAddress();
    void setCity(std::string cit);
    std::string getCity();
    void setState(std::string sta);
    std::string getState();
    void setLatitude(double lat);
    double getLatitude();
    void setLongitude(double lon);
    double getLongitude();
    void setCar(std::string car);
    std::string getCar();
    void setCarModel(std::string mod);
    std::string getCarModel();
    void setCarColor(std::string col);
    std::string getCarColor();
    void setMovie(std::string fav);
    std::string getMovie();
    void setPet(std::string pPet);
    std::string getPet();
    void setJob(std::string job);
    std::string getJob();
    void setPhone(std::string pho);
    std::string getPhone();
    void pushStock(std::string sto);
    void setStocks(std::vector<std::string> sto);
    std::vector<std::string> getStocks();
    friend std::ostream;
};

c_Employee::c_Employee()
{
    ID = -1;
    firstName = "First name place holder text";
    lastName = "Last name place holder text";
    email = "Email place holder text";
    address = "Address place holder text";
    city = "City place holder text";
    state = "State place holder text";
    latitude = -1;
    longitude = -1;
    car = "Car place holder text";
    carModel = "Car model place holder text";
    carColor = "Car color place holder text";
    pet = "Pet place holder text";
    jobTitle = "Job title place holder text";
    phoneNumber = "Phone number place holder text";
    stocks = {};
}
c_Employee::c_Employee(int id, std::string fName, std::string lName, std::string ema,
           std::string add, std::string cit, std::string sta, double lat,
           double lon, std::string cCar, std::string cMod, std::string cCol,
           std::string fav, std::string pPet, std::string job, std::string pho)
{
    ID = id;
    firstName = fName;
    lastName = lName;
    email = ema;
    address = add;
    city = cit;
    state = sta;
    latitude = lat;
    longitude = lon;
    car = cCar;
    carModel = cMod;
    carColor = cCol;
    favMovie = fav;
    pet = pPet;
    jobTitle = job;
    phoneNumber = pho;
}
c_Employee *c_Employee::getEmployee()
{
    return this;
}
void c_Employee::setID(int id)
{
    ID = id;
}
int c_Employee::getID()
{
    return ID;
}
void c_Employee::setFirstName(std::string fName)
{
    firstName = fName;
}
std::string c_Employee::getFirstName()
{
    return firstName;
}
void c_Employee::setLastName(std::string lName)
{
    lastName = lName;
}
std::string c_Employee::getLastName()
{
    return lastName;
}
void c_Employee::setEmail(std::string ema)
{
    email = ema;
}
std::string c_Employee::getEmail()
{
    return email;
}
void c_Employee::setAddress(std::string add)
{
    address = add;
}
std::string c_Employee::getAddress()
{
    return address;
}
void c_Employee::setCity(std::string cit)
{
    city = cit;
}
std::string c_Employee::getCity()
{
    return city;
}
void c_Employee::setState(std::string sta)
{
    state = sta;
}
std::string c_Employee::getState()
{
    return state;
}
void c_Employee::setLatitude(double lat)
{
    latitude = lat;
}
double c_Employee::getLatitude()
{
    return latitude;
}
void c_Employee::setLongitude(double lon)
{
    longitude = lon;
}
double c_Employee::getLongitude()
{
    return longitude;
}
void c_Employee::setCar(std::string car)
{
    car = car;
}
std::string c_Employee::getCar()
{
    return car;
}
void c_Employee::setCarModel(std::string mod)
{
    carModel = mod;
}
std::string c_Employee::getCarModel()
{
    return carModel;
}
void c_Employee::setCarColor(std::string col)
{
    carColor = col;
}
std::string c_Employee::getCarColor()
{
    return carColor;
}
void c_Employee::setMovie(std::string fav)
{
    favMovie = fav;
}
std::string c_Employee::getMovie()
{
    return favMovie;
}
void c_Employee::setPet(std::string pPet)
{
    pet = pPet;
}
std::string c_Employee::getPet()
{
    return pet;
}
void c_Employee::setJob(std::string job)
{
    jobTitle = job;
}
std::string c_Employee::getJob()
{
    return jobTitle;
}
void c_Employee::setPhone(std::string pho)
{
    phoneNumber = pho;
}
std::string c_Employee::getPhone()
{
    return phoneNumber;
}
void c_Employee::pushStock(std::string sto)
{
    stocks.push_back(sto);
}
void c_Employee::setStocks(std::vector<std::string> sto)
{
    stocks = sto;
}
std::vector<std::string> c_Employee::getStocks()
{
    return stocks;
}
std::ostream &operator<<(std::ostream &o, const std::vector<std::string> &vec)
{
    for (std::string i : vec)
    {
        o << i << " ";
    }

    return o;
};
std::ostream &operator<<(std::ostream &o, c_Employee &emp)
{
    o << emp.getID() << ' ' << emp.getFirstName()
      << " " << emp.getLastName() << " | "
      << "Email: " << emp.getEmail() << " | "
      << "Address: " << emp.getAddress()
      << ", " << emp.getCity() << " " 
      << emp.getState() << ", "
      << emp.getLatitude() << ", "
      << emp.getLongitude() << std::endl;
    o << "    Car: " << emp.getCarColor() << " "
      << emp.getCar() << " " << emp.getCarModel()
      << " | Favorite Movie: " << emp.getMovie() << " | "
      << "Pet: " << emp.getPet() << std::endl;
    o << "    Job Title: " << emp.getJob()
      << " | Phone: " << emp.getPhone() << std::endl;
    o << "    "
      << "Stocks: " << emp.getStocks() << std::endl;

    return o;
};

#endif