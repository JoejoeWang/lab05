#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "**Police shooting incidents:";
    out << "State Info: " << PD.printState();
    //out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "State Info: " << PD.state;
    out << "\nNumber of incidents: " << PD.NumberOfCases;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.CasesOver65;
    out << "\n(19 to 64): " << PD.NumberOfCases-PD.CasesOver65-PD.CasesUnder18;
    out << "\n(under 18): " << PD.CasesUnder18;
    out << "\nIncidents involving fleeing: " << PD.FleeingCount;
    out << "\nIncidents involving mental illness: " << PD.NumMentalI;
    out << "\nMale incidents: " <<  PD.numMales << " female incidents: " << PD.numFemales;
    out << "\nRacial demographics of state incidents: " << PD.onepiece;
    //fill in
    return out;
}