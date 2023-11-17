/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
void solve(int r,vector<vector<bool>>&maze,vector<bool>&cols,vector<bool>&ndiag,vector<bool>&rdiag,int skp){
    
    if(skp==r){
        solve(r+1,maze,cols,ndiag,rdiag,skp);
    }
    
    int n=maze.size();
    if(r==maze.size()){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j]){
                    cout<<" 1 ";
                }else{
                    cout<<" 0 ";
                }
            }
            cout<<endl;
        }
        return;
    }
    
    
    for(int c=0;c<n;c++){
        
        if(cols[c]==false && ndiag[r+c]==false &&rdiag[r-c+n-1]==false){
            
            maze[r][c]=true;
            cols[c]=true;
            ndiag[r+c]=true;
            rdiag[r-c+n-1]=true;
            solve(r+1,maze,cols,ndiag,rdiag,skp);
            maze[r][c]=false;
            cols[c]=false;
            ndiag[r+c]=false;
            rdiag[r-c+n-1]=false;
        }
           
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<bool>> maze(n,vector<bool>(n,false));
    vector<bool> cols(n,false);
    vector<bool> ndiag(2*n-1,false);
    vector<bool> rdiag(2*n-1,false);
    
    int r,c;
    cin>> r>>c;
    
    maze[r][c]=true;
    cols[c]=true;
    ndiag[r+c]=true;
    rdiag[r-c+n-1]=true;
    
    solve(0,maze,cols,ndiag,rdiag,r);
    
    
    
    
    
    return 0;
}