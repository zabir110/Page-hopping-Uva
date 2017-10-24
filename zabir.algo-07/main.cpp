#include <iostream>
#include<fstream>
#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int n1,n2,w,cnt=0;
float node;
int dis[100][100];


void find_distance()
{
    float sum=0,div=0;
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            if(dis[i][j]!=INF && i!=j) {
                    sum+=dis[i][j];
                    div++;
            }
        }
    }
    cout<<"Case "<<++cnt<<": average length between pages = "<<sum/div<<" clicks"<<endl;
}

void flowdWarshall()
{
    for(int k=0; k<node; k++)
    {
        for(int i=0; i<node; i++)
        {
            for(int j=0; j<node; j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    find_distance();
}


int main()
{


    ifstream in("z.txt");
    while(in>>n1>>n2)
    {

        for(int i=0; i<100; i++)
        {
        for(int j=0; j<100; j++)
        {
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
        node=0;

        if(n1==0 && n2==0) break;

        while(n1!=0 && n2!=0)
        {
            dis[n1-1][n2-1]=1;

            if(node<n1) node=n1;
            if(node<n2) node=n2;
            in>>n1>>n2;
        }

        flowdWarshall();
    }
    return 0;
}
