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

  for(int i=0; i<numTestCases; i++)
  {
    cin >> bendersTokens >> cityName >> cityMap;

    cout << "City: " << cityName << endl;
    cout << "Tokens: " << bendersTokens << endl;
    cout << "Graph: " << endl << cityMap << endl;
  }

  return 0;
}
