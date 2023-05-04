#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i,j,a,aux, aux2,filas[10], columnas[10];
  

  for ( i = 0 ; i < 9 ; i++){
    for ( a = 0 ; a < 10 ; a++){
      filas[a] = 0;
      columnas[a] = 0;
    }
    for( j = 0 ; j < 9 ; j++){
      aux = n->sudo[i][j];
      if ( aux != 0){
        if (filas[aux] == 0){
          filas[aux] = 1;
        }
        else{
          return 0;
        }
      }
      aux2 = n->sudo[j][i];
      if ( aux2 != 0){
        if (columnas[aux2] == 0){
          columnas[aux2] = 1;
        }
        else{
          return 0;
        }
      }
    }
  }
  
  return 1;
}



List* get_adj_nodes(Node* n){
  List* list=createList();
  for( int i = 0 ; i < 9 ; i++){
    for( int j = 0 ; j < 9 ; j++){
      if ( n->sudo[i][j] == 0){
        for( int k = 0 ; k < 9 ; k++){
        Node* b = copy( n);
        b->sudo[i][j] = k + 1;
        pushBack( list, b);
        }
        return list;
      }
    }
  }
  return list;
}

int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/