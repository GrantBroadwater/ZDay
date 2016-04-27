//
// Created by Grant Broadwater on 4/26/16.
//

#ifndef ZDAY_GRAPH_H
#define ZDAY_GRAPH_H

#include <iostream>

#include "node.h"

using namespace std;

template <typename T>
class Graph
{
  short m_numNodes;
  Node<T> * m_node;

public:

  Graph()
      : m_numNodes(0), m_node(NULL)
  {}

  Graph(const short numNodes)
      : m_numNodes(numNodes), m_node(NULL)
  {
    if(m_numNodes > 0)
      m_node = new Node<T>[m_numNodes];
    else
      m_numNodes = 0;
  }

  Graph(const Graph<T>& copy)
      : m_numNodes(copy.m_numNodes), m_node(NULL)
  {
    if(m_numNodes > 0)
    {
      m_node = new Node<T>[m_numNodes];
      for(int i=0; i<m_numNodes; i++)
      {
        m_node[i] = Node<T>(copy.m_node[i]);
      }
    }
  }

  const Graph<T>& operator=(const Graph<T>& rhs)
  {
    if(this == &rhs)
      return *this;

    clear();

    m_numNodes = rhs.m_numNodes;

    if(m_numNodes > 0)
    {
      m_node = new Node<T>[m_numNodes];
      for(int i=0; i<m_numNodes; i++)
      {
        m_node[i] = Node<T>(rhs.m_node[i]);
      }
    }

    return *this;
  }

  short cost(const T& originVal, const T& targetVal) const
  {
    short originNum = 0;
    int myCost = -1, neighborCost;

    // Return no cost if both nodes are the same
    if(originVal == targetVal)
      return 0;

    // Find the origin in the node array
    while(originNum < m_numNodes && m_node[originNum].m_id != originVal)
      originNum++;

    if(originNum >= m_numNodes)
      throw 404;

    // For each neighbor
    for(int i=0; i<m_node[originNum].m_numNeighbors; i++)
    {

      // Calculate the cost to get to the target through that neighbor
      neighborCost = cost(m_node[originNum].m_neighbor[i].m_id, targetVal)
                     + m_node[originNum].m_neighbor[i].m_cost;

      // If neighborCost is the best route, save that cost
      if(neighborCost >= 0 && (myCost < 0 || neighborCost < myCost))
        myCost = neighborCost;

    }

    return myCost;
  }

  void clear()
  {
    if(m_node != NULL)
    {
      delete [] m_node;
      m_node = NULL;
      m_numNodes = 0;
    }
  }

  template <typename T1>
  friend ostream& operator<<(ostream& out, const Graph<T1>& g);

  template <typename T1>
  friend istream& operator>>(istream& in, Graph<T1>& g);

  ~Graph()
  {
    clear();
  }
};

template <typename T>
ostream& operator<<(ostream& out, const Graph<T>& g)
{
  if(g.m_node != NULL)
    for(int i=0; i<g.m_numNodes; i++)
      out << g.m_node[i];

  return out;
}

template <typename T>
istream& operator>>(istream& in, Graph<T>& g)
{
  g.clear();

  in >> g.m_numNodes;

  if(g.m_numNodes > 0)
  {
    g.m_node = new Node<T>[g.m_numNodes];
    for(int i=0; i<g.m_numNodes; i++)
      in >> g.m_node[i];
  }

  return in;
}

#endif //ZDAY_GRAPH_H
