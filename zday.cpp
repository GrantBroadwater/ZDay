//
// Created by Grant Broadwater on 4/26/16.
// 1510 section A
//

#include <iostream>

#include "graph.h"

using namespace std;

int main()
{
  short numTestCases;
  short drZTokens;
  string cityName;
  Graph<string> cityMap;

  cin >> numTestCases;

  for(int i=0; i<numTestCases; i++)
  {
    cin >> drZTokens >> cityName >> cityMap;

    cout << "In " << cityName << ", Dr. Zoidberg can reach:" << endl;
    cityMap.printLocationsWithinRange("airport", drZTokens);
    cout << endl;
  }

  return 0;
}
