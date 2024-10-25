#include <iostream>
#include <queue>
using namespace std;

struct vertex
{
  int data;
  vertex *next;
};

void BFS(vertex *graph[], int source, int size)
{
  queue<int> q;
  bool *visited = new bool[size];

  for (int i = 0; i < size; i++)
  {
    visited[i] = false;
  }
  q.push(source);

  int v, next;
  vertex *curr;

  while (!q.empty())
  {
    v = q.front();
    q.pop();

    if (!visited[v])
    {
      cout << v << " ";
      visited[v] = true;
    }

    curr = graph[v];

    while (curr != nullptr)
    {
      next = curr->data;

      if (!visited[next])
      {
        q.push(next);
      }

      curr = curr->next;
    }
  }
  cout << endl;
  delete[] visited;
}

int main()
{

  // cout << "hello world";
  int size = 3;
  vertex *graph[size];
  for (int i = 0; i < size; i++)
  {
    graph[i] = nullptr;
  }
  graph[0] = new vertex;
  graph[0]->data = 1;
  graph[0]->next = new vertex;
  graph[0]->next->data = 2;
  graph[0]->next->next = new vertex;
  graph[0]->next->next->data = 3;
  graph[1] = new vertex;
  graph[1]->data = 0;
  graph[1]->next = new vertex;
  graph[1]->next->data = 2;
  graph[2] = new vertex;
  graph[2]->data = 0;
  graph[2]->next = new vertex;
  graph[2]->next->data = 1;
  graph[2]->next->next = new vertex;
  graph[2]->next->next->data = 3;
  graph[3] = new vertex;
  graph[3]->data = 0;
  graph[3]->next = new vertex;
  graph[3]->next->data = 2;
  BFS(graph, 0, size);
  return 0;
}