//
// Created by Grant Broadwater on 4/26/16.
//

#ifndef ZDAY_GRAPH_H
#define ZDAY_GRAPH_H

#include "node.h"

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
