#include "com_def.h"
#include "mgraphdef.h"
#include "mgraphapp.h"
void main(){
  MGraph G;
  CreateGraph(G);
  PrintGraph(G);
  GraphDegree(G);
  cout<<endl; 
}
