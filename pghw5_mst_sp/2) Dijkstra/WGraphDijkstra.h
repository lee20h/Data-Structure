//201610674 컴퓨터공학부 이영훈 
#include "WGraph.h"
class WGraphDijkstra : public WGraph {
   int dist[MAX_VTX];
   bool found[MAX_VTX];
   int check[MAX_VTX];
   int path1[MAX_VTX][MAX_VTX];
public :
   void path_init(int path[][MAX_VTX]){
      for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
      path[i][j] = INF;
   }
   int chooseVertex() {
      int min = INF;
      int minpos = -1;
      for (int i=0; i<size; i++) {
         if (dist[i]<min && !found[i]) {
            min = dist[i];
            minpos = i;
         }
      }
      return minpos;
   }
   
   void ShortestPath(int start) {
      for (int i=0; i<size; i++) {
         dist[i]=getEdge(start,i);
         found[i] = false;
         path1[i][0] = start;
         check[i] = 1;
      }
      path_init(path1);
      found[start] = true;
      dist[start] = 0;
      for (int i=1; i<size; i++) {
         printf("Step%2d:", i);
         printfDistance();
         int u= chooseVertex();
         found[u] = true;
         for (int w=0; w<size; w++) {
            if(found[w] == false) {
               if(dist[u] + getEdge(u,w) < dist[w]) {
               if(i==0){ // 첫 방 문 
                    path1[w][check[w]] = u; 
                    check[w]++;
                }
                  else{
                     for(int j=0; j<(check[u]+1); j++){
                     path1[w][j] = path1[u][j]; 
                     path1[w][j+1] = u;
                     check[w]++;
                     }
                  dist[w] = dist[u] + getEdge(u,w);
                  }
               }
            }
         }
      }
         
         char a = 'A';
         char st = a + start;
         char temp = 'A';
        for(int i=0; i<size; i++, a++){
           printf("%c에서 %c까지의 최소비용 : %d \n",st,a,dist[i]);
           printf("%c에서 %c까지의 경로 : ",st,a);
           printf("%c->", st);
           for(int j=0; j<size; j++){
               if(path1[i][j]!=INF){   
                     printf("%c->", temp + path1[i][j]);
              }      
          }   
           printf("%c\n", temp+i);
     }
   }
   void printfDistance() {
      for(int i=0; i<size; i++)
         printf("%5d", dist[i]);
      printf("\n");
   }
   
};
