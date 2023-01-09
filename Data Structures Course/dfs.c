#include<stdio.h>
//check for adjacent(if adj->check for visited, else->leave)
//visited->check for parent or not(if parent->nothing, else->backedge)
//not visited->proceed
void read_matrix(int adj[10][10],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
}

void dfs(int v,int adj[10][10],int n,int visited[10],int parent)
{
    visited[v]=1;
        //printf("%d",k);
        for(int i=0;i<n,i++)
        {
            if(adj[k][i] && !visited[i])
            {
                dfs(i,adj,visited,n);
            }
        }
}

int main()
{
    int adj[10][10];
    int n=3;
    int visited[10]={0};
    read_matrix(adj,n);
    for(int i=0;i<n,i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,n);
        }
    }
}