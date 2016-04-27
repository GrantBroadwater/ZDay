//
// Created by Grant Broadwater on 4/26/16.
//

#include <iostream>

#include "graph.h"

using namespace std;

int main()
{
  short numTestCases;
  short bendersTokens;
  string cityName;
  Graph<string> cityMap;

  cin >> numTestCases;

  cin >> bendersTokens >> cityName >> cityMap;

  cout << "City Map: " << endl << cityMap << endl;

  cout << "cost for airport to museum: "
       << cityMap.cost(string("airport"), string("museum")) << endl;
  cout << "cost for airport to zoo: "
       << cityMap.cost(string("airport"), string("zoo")) << endl;
  cout << "cost for airport to park: "
       << cityMap.cost(string("airport"), string("park")) << endl;

  return 0;
}
