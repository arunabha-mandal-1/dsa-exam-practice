// Depth first search algorithm impemented using in-built Stack
#include <stdio.h>

// dfs
void dfs(int arr[6][6], int u, int* visited);

// main function
int main(){
    int visited[6]={0,0,0,0,0,0};
    int A[6][6]={
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,0,1,0},
        {0,1,0,0,1,1},
        {0,0,1,1,0,1},
        {0,0,1,1,0,0}
    };

    dfs(A, 0, visited);
    printf("\n");
    
    return 0;
}

// dfs
void dfs(int arr[6][6], int u, int* visited){
    printf("%d ", u);
    visited[u]=1;
    for(int i=0; i<6; i++){
        if(arr[u][i]==1 && visited[i]==0){
            dfs(arr, i, visited);
        }
    }
}