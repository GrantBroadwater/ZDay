//
// Created by Grant Broadwater on 4/26/16.
//

#ifndef ZDAY_NEIGHBOR_H
#define ZDAY_NEIGHBOR_H

#include <iostream>

using namespace std;

template <typename T>
struct Neighbor
{
  T m_id;
  short m_cost;

  Neighbor()
      : m_id(), m_cost(0)
  {}

  Neighbor(const T& id, const short cost)
      : m_id(id), m_cost(cost)
  {}

  Neighbor(const Neighbor<T>& copy)
      : m_id(copy.m_id), m_cost(copy.m_cost)
  {}

};

template <typename T>
ostream& operator<<(ostream& out, const Neighbor<T>& n)
{
  out << "\"" << n.m_id << "\" (cost $" << n.m_cost << ")";

  return out;
}

template <typename T>
istream& operator>>(istream& in, Neighbor<T>& n)
{
  in >> n.m_id >> n.m_cost;

  return in;
}

#endif //ZDAY_NEIGHBOR_H
