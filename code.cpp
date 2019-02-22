#include <bits/stdc++.h>
#define ll long long
using namespace std;

int soln[20][20];


bool checkRight(int maze[][20],  int soln[][20], int row, int col,int n){
    if(col+1==n){
        return false;
    }
    else if(maze[row][col+1]==1 && soln[row][col+1]==0){
        return true;
    }
    return false;
}
bool checkDown(int maze[][20], int soln[][20],  int row, int col,int n){
    if(row+1==n){
        return false;
    }
    else if(maze[row+1][col]==1 && soln[row+1][col]==0 ){
        return true;
    }
    return false;
}
bool checkLeft(int maze[][20], int soln[][20],  int row, int col,int n){
    if(col-1==-1){
        return false;
    }
    else if(maze[row][col-1]==1 && soln[row][col-1]==0){
        return true;
    }
    return false;
}
bool checkUp(int maze[][20], int soln[][20], int row, int col,int n){
    if((row-1)==(-1)){
        return false;
    }
    else if(maze[row-1][col]==1 && soln[row-1][col]==0){
        return true;
    }
    return false;
}

void mazeSolve(int maze[][20] ,int n , int row, int col){

    soln[row][col]=1;
    if(row==n-1 && col==n-1 ){
        for(int i=0 ; i<n ; i++) {
            for (int j = 0; j < n; j++) {
                cout << soln[i][j] << " ";
            }
        }
        cout<<endl;
        soln[row][col]=0;
        return ;
    }



    soln[row][col]=1;

    if(checkUp(maze,soln,row,col,n)){
        mazeSolve(maze,n,row-1,col);
    }
    if(checkDown(maze,soln,row,col,n)){
        mazeSolve(maze,n,row+1,col);
    }
    if(checkLeft(maze,soln,row,col,n)){
        mazeSolve(maze,n,row,col-1);
    }
    if(checkRight(maze,soln,row,col,n)){
        mazeSolve(maze,n,row,col+1);
    }

    soln[row][col]=0;

    return;

}




void ratInAMaze(int maze[][20], int n){

    mazeSolve(maze,n,0,0);

}





int main() {
    int n;
    cin>>n;
    int maze[n][20];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n;j++){
            cin>>maze[i][j];
        }
    }

    ratInAMaze(maze,n);
    return 0;
}
