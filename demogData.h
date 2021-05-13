#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>
#include "raceDemogData.h"
#include "regionData.h"

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData : public regionData {
  public:
    demogData() : regionData("",""), name(""), state(""), popOver65(0), popUnder18(0), popUnder5(0), popBAup(0), popHSup(0), totalPopulation2014(0), poverty(0) {}
    demogData(string inN, string inS, double in65, double in18, double in5, double totPopBAup, double totPopHAup, double poverty, int totPop14, raceDemogData b) :
        regionData(inN, inS), name(inN), state(inS), popOver65(in65), popUnder18(in18), popUnder5(in5), popBAup(totPopBAup), popHSup(totPopHAup), poverty(poverty), totalPopulation2014(totPop14), race(b) {}
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14, raceDemogData b) :
            regionData(inN, inS), name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), popBAup(0), popHSup(0), poverty(0), totalPopulation2014(totPop14), race(b) {}

    //getter for percentage
    string getName() const { return name; }
    string getStateName() const { return state; }
    double getpopOver65() const { return popOver65;}
    double getpopUnder18() const { return popUnder18; }
    double getpopUnder5() const { return popUnder5; }
    double getBAup() const { return popBAup; }
    double getHSup() const { return popHSup; }
    double getPoverty() const { return poverty; }

    //getter for actual data
    int getPop() const { return totalPopulation2014; }
    int getpopOver65Count() const { return getpopOver65()*getPop()/100; }
    int getpopUnder18Count() const { return getpopUnder18()*getPop()/100; }
    int getpopUnder5Count() const { return getpopUnder5()*getPop()/100; }
    int getBAupCount() const { return getBAup()*getPop()/100; }
    int getHSupCount() const { return getHSup()*getPop()/100; }
    int getHSbelowCount() const { return (1-getHSup()/100)*getPop(); }
    int getPovertyCount() const { return getPoverty()*getPop()/100; }
    //int getCountNum() const { return count_num; }
    raceDemogData getrace() const { return race; }
    //string getRegionName() const { return name; }

    //setter for parameters
    // void setName(string a) { name = a; }
    // void setState(string a) { state = a; }
    void setpopOver65Count(double a) { popOver65 = a; }
    void setpopUnder18Count(double a) { popUnder18 = a; }
    void setpopUnder5Count(double a) { popUnder5 = a; }
    void setpopBAupCount(double a) { popBAup = a; }
    void setpopHSupCount(double a) { popHSup = a; }
    void setPopCount(int a) { totalPopulation2014 = a; }
    void setpovertyCount(double a) { poverty = a; }
    void setraceCount(raceDemogData b) { race = b; }

    //"+" operator
    // demogData& operator+=(const demogData& a)
    // {
    //   this->popOver65 = 100*((this->popOver65*this->totalPopulation2014/100)+(a.popOver65*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014);
    //   this->popUnder18 = 100*((this->popUnder18*this->totalPopulation2014/100)+(a.popUnder18*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014);
    //   this->popUnder5 = 100*((this->popUnder5*this->totalPopulation2014/100)+(a.popUnder5*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014); 
    //   this->popBAup = 100*((this->popBAup*this->totalPopulation2014/100)+(a.popBAup*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
    //   this->popHSup = 100*((this->popHSup*this->totalPopulation2014/100)+(a.popHSup*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
    //   this->poverty = 100*((this->poverty*this->totalPopulation2014/100)+(a.poverty*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
    //   this->totalPopulation2014 += a.totalPopulation2014;
    //   this->race += a.race;
    //   return *this;
    // }

    void add(const demogData& a)
    {
      popOver65 = 100*((popOver65*this->totalPopulation2014/100)+(a.popOver65*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014);
      popUnder18 = 100*((this->popUnder18*this->totalPopulation2014/100)+(a.popUnder18*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014);
      popUnder5 = 100*((this->popUnder5*this->totalPopulation2014/100)+(a.popUnder5*a.totalPopulation2014/100))/(this->totalPopulation2014+a.totalPopulation2014); 
      popBAup = 100*((this->popBAup*this->totalPopulation2014/100)+(a.popBAup*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
      popHSup = 100*((this->popHSup*this->totalPopulation2014/100)+(a.popHSup*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
      poverty = 100*((this->poverty*this->totalPopulation2014/100)+(a.poverty*a.totalPopulation2014))/(this->totalPopulation2014+a.totalPopulation2014);
      totalPopulation2014 += a.totalPopulation2014;
      race += a.race;
    }


    //
    void toString(ostream& os) const;

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    string name;
    string state;
    double popOver65;
    double popUnder18;
    double popUnder5;
    double popBAup;
    double popHSup;
    int totalPopulation2014;
    double poverty;
    //const int count_num;
    raceDemogData race;

};
#endif
