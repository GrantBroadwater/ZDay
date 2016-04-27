//
// Created by Grant Broadwater on 4/26/16.
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

  cin >> drZTokens >> cityName >> cityMap;

  cout << "City Map: " << endl << cityMap << endl;

  cout << "cost for airport to museum: "
       << cityMap.cost(string("airport"), string("museum")) << endl;
  cout << "cost for airport to zoo: "
       << cityMap.cost(string("airport"), string("zoo")) << endl;
  cout << "cost for airport to park: "
       << cityMap.cost(string("airport"), string("park")) << endl;

  cout << "\nIn " << cityName << ", Dr. Zoidberg can reach:" << endl;
  cityMap.printLocationsWithinRange("airport", drZTokens);

  return 0;
}
