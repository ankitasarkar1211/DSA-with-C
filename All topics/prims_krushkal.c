#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 999

int graph[MAX][MAX];
int n;

void prims() {
  int visited[MAX], min, total=0, ne=0;
  for(int i=0;i<n;i++)  visited[i]=0;
  visited[0]=1;

  while(ne<n-1) {
    min=INF; int x=0,y=0;
    for(int i=0;i<n;i++) {
      if(visited[i]) {
        for(int j=0;j<n;j++) {
          if(!visited[j] && graph[i][j]) {
            if(graph[i][j]<min) {
              min=graph[i][j];
              x=i;
              y=j;
            }
          }
        }
      }
    }
    printf("Edge (%d-%d) Cost: %d\n", x, y, min);
    total+=min;
    visited[y]=1;
    ne++;
  }
  printf("Total Cost: %d", total);
}

int parent[MAX];
int find(int i) {
  while(parent[i]!=i)
    i=parent[i];
  return i;
}
void unionSet(int i, int j) {
  int a=find(i);
  int b=find(j);
  parent[a]=b;
}
void krushkal() {
  int total=0, ne=0;
  for(int i=0;i<n;i++)  parent[i]=i;

  while(ne<n-1) {
    int min=INF, x=0, y=0;
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(find(i)!=find(j) && graph[i][j]) {
          if(graph[i][j]<min) {
            min=graph[i][j];
            x=i;
            y=j;
          }
        }
      }
    }
    unionSet(x,y);
    printf("Edge (%d-%d) Cost: %d\n", x, y, min);
    total+=min;
    ne++;
  }
  printf("Total Cost: %d", total);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prims();
    krushkal();

    return 0;
}