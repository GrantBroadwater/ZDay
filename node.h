//
// Created by Grant Broadwater on 4/26/16.
//

#ifndef ZDAY_NODE_H
#define ZDAY_NODE_H

#include "neighbor.h"

template <typename T>
struct Node
{
  T m_id;
  short m_numNeighbors;
  Neighbor<T> * m_neighbor;

  Node()
      : m_id(), m_numNeighbors(0), m_neighbor(NULL)
  {}

  Node(const T& id, const short numNeighbors)
      : m_id(id), m_numNeighbors(numNeighbors), m_neighbor(NULL)
  {
    if(m_numNeighbors > 0)
      m_neighbor = new Neighbor<T>[m_numNeighbors];
    else
      m_numNeighbors = 0;
  }

  Node(const Node<T>& copy)
      : m_id(copy.m_id), m_numNeighbors(copy.m_numNeighbors), m_neighbor(NULL)
  {
    if(m_numNeighbors > 0)
    {
      m_neighbor = new Neighbor<T>[m_numNeighbors];
      for(int i=0; i<m_numNeighbors; i++)
        m_neighbor[i] = copy.m_neighbor[i];
    }
    else
    {
      m_numNeighbors = 0;
    }
  }

  void clear()
  {
    if(m_neighbor != NULL)
    {
      delete [] m_neighbor;
      m_neighbor = NULL;
      m_numNeighbors = 0;
    }
  }

  ~Node()
  {
    clear();
  }

};

template <typename T>
ostream& operator<<(ostream& out, const Node<T>& n)
{
  out << "You can go from \"" << n.m_id <<"\" to:" << endl;
  for(int i=0; i<n.m_numNeighbors; i++)
  {
    out << "\t" << n.m_neighbor[i] << endl;
  }

  return out;
}

template <typename T>
istream& operator>>(istream& in, Node<T>& n)
{
  n.clear();

  in >> n.m_id >> n.m_numNeighbors;

  if(n.m_numNeighbors > 0)
  {
    n.m_neighbor = new Neighbor<T>[n.m_numNeighbors];
    for(int i=0; i<n.m_numNeighbors; i++)
      in >> n.m_neighbor[i];
  }
  else
    n.m_numNeighbors = 0;

  return in;
}

#endif //ZDAY_NODE_H
