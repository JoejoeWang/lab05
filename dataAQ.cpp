/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";

/*
  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } els、、、e if (theData->g】etBelowPoverty() < 30) {
    theKey += "BelowPovL essThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }
*/
  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {

  string theKey = "Key";
  /*
  if (theData->getFleeing() == "Foot") {
    theKey += "FleeingOnFoot";
  } else if (theData->getFleeing() == "Car") {
    theKey += "FleeingByCar";

  } else if (theData->getFleeing() == "Other") {
    theKey += "FleeingOtherMeans";
  } else {
    theKey += "NotFleeing";
  }
  */
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

//fill in

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in

}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
//fill in
  demogCombo first;
  first = demogCombo(theData[0]);
  pair<string, shared_ptr<demogCombo> > NUMONE (theData[0]->getStateName(), make_shared<demogCombo>(first));
  allComboDemogData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry: allComboDemogData)
    {
      if(theData[i]->getStateName()==entry.first)
      {
        // demogCombo second;
        // second = demogCombo(theData[i]);
        entry.second->popUpdate(*theData[i]);
        in = true;
      }
    }
    if(in == false)
    {
      demogCombo newone;
      newone = demogCombo(theData[i]);
      pair<string, shared_ptr<demogCombo> > Firstterm (theData[i]->getStateName(), make_shared<demogCombo>(newone));
      allComboDemogData.insert(Firstterm);
    }
  }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
//fill in
  psCombo first;
  first = psCombo(*theData[0]);
  pair<string, shared_ptr<psCombo> > NUMONE (theData[0]->getState(), make_shared<psCombo>(first));
  allComboPoliceData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry: allComboPoliceData)
    {
      if(theData[i]->getState()==entry.first)
      {
        entry.second->Update(*theData[i]);
        in = true;
        // if(entry.first=="CA")
        // {
        //   cout<<entry.second->getNumMentalI()<<endl;
        // }
      }
    }
    if(in == false)
    {
      psCombo newone;
      newone = psCombo(*theData[i]);
      pair<string, shared_ptr<psCombo> > Firstterm (theData[i]->getState(), make_shared<psCombo>(newone));
      allComboPoliceData.insert(Firstterm);
    }
  }
}


//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  //fill in
  shared_ptr<psCombo> max;
  shared_ptr<psCombo> a;
  vector<shared_ptr<psCombo>> psPop;
  for(auto entry : allComboPoliceData)
  {
    psPop.push_back(entry.second);
  }
  for(int i=0;i<psPop.size();i++)
  {
    int p(i),q;
    a = psPop[i];
    max = psPop[i];
    for(int j=i+1;j<psPop.size();j++)
    {
      if(psPop[j]->getNumberOfCases()>max->getNumberOfCases())
      {
        max = psPop[j];
        q = j;
      }
    }
    psPop[i] = max;
    psPop[q] = a;
  }
  cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  for(int i=0;i<9;i++)
  {
    cout << psPop[i]->getState();
    cout << "\nTotal population: ";
    cout << allComboDemogData[psPop[i]->getState()]->getPop();
    cout << "\nPolice shooting incidents: ";
    cout << psPop[i]->getNumberOfCases() <<endl;
    cout << "Percent below poverty: ";
    cout << setprecision(2) << fixed;
    cout << (double)(allComboDemogData[psPop[i]->getState()]->getPovertyCount())/allComboDemogData[psPop[i]->getState()]->getPop();
    //cout << allComboDemogData[psPop[i]->getState()]->getPoverty();
    cout << "\n";
  }
}


    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
//fill in
  shared_ptr<demogCombo> max;
  shared_ptr<demogCombo> a;
  vector<shared_ptr<demogCombo>> dePop;
  for(auto entry : allComboDemogData)
  {
    dePop.push_back(entry.second);
    //cout << entry.second->getPop()<<endl;
  }
  for(int i=0;i<dePop.size();i++)
  {
    int q;
    a = dePop[i];
    max = dePop[i];
    for(int j=i+1;j<dePop.size();j++)
    {
      double percent1 = 100.0f*dePop[j]->getPovertyCount()/dePop[j]->getPop();
      double percent2 = 100.0f*max->getPovertyCount()/max->getPop();
      if(percent1>percent2)
      {
        max = dePop[j];
        q = j;
      }
    }
    dePop[i] = max;
    dePop[q] = a;
  }
  for(int i=0;i<9;i++)
  {
    //cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
    cout << dePop[i]->getState();
    cout << "\nTotal population: ";
    cout << dePop[i]->getPop();
    cout << "\nPercent below poverty: ";
    cout << setprecision(2) << fixed;
    cout << (double)(dePop[i]->getPovertyCount())/dePop[i]->getPop();
    cout << "\nPolice shooting incidents: ";
    cout << allComboPoliceData[dePop[i]->getState()]->getNumberOfCases();
    cout << "\n";
  }
}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  return out;
}
