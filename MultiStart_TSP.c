#define n 20

#include<raylib.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

     
    int TravelPath(int start,int cx0[n],int cy0[n],int px[n],int py[n])
    {
       int i,j,minDist=2000,dist,index,TotalDist=0;
       int cx[n],cy[n];
    
  
    for(i=0;i<n;i++)
    {
    cx[i]=cx0[i];
    cy[i]=cy0[i];
    }
    
    px[0]=cx[start];
    py[0]=cy[start];

    cx[start]=-1;
    cy[start]=-1;

    for(i=0;i<n-1;i++)
    {
    minDist=2000;
    for(j=0;j<n;j++)
    {
    if(cx[j]>=0 && cy[j]>=0)
    {
    dist=(int)sqrt((px[i]-cx[j])*(px[i]-cx[j])+(py[i]-cy[j])*(py[i]-cy[j]));
    if(minDist>dist)
    {
    minDist=dist;
    index=j;
    }
    }
    }
    TotalDist+=minDist;
    px[i+1]=cx[index];
    py[i+1]=cy[index];
    cx[index]=-1;
    cy[index]=-1;
    }
    TotalDist+=sqrt((px[n-1]-px[0])*(px[n-1]-px[0])+(py[n-1]-py[0])*(py[n-1]-py[0]));
    return TotalDist;
    }

int main()
{
    int cx0[n],cy0[n];
    int px[n],py[n];
    int startInd=0,distance;
    InitWindow(800,800,"Travelling Salesman Problem");
    SetTargetFPS(60);
    srand(time(NULL));
    
     for(int i=0;i<n;i++)
    {
    cx0[i]=50+rand()%700;
    cy0[i]=50+rand()%700;
    }    
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(IsKeyPressed(KEY_ENTER)) startInd++;
        if(IsKeyPressed(KEY_BACKSPACE)) startInd--;
        
        if(startInd>=n) startInd=0; 
        if(startInd<0)  startInd=n-1;
        distance=TravelPath(startInd,cx0,cy0,px,py);
        
        for(int i=0;i<n;i++)   DrawCircle(px[i],py[i],5.0,RED);
        
         if(!IsKeyDown(KEY_SPACE))
        {
         for(int i=0;i<n-1;i++) DrawLine(px[i],py[i],px[i+1],py[i+1],BLACK);
         DrawLine(px[0],py[0],px[n-1],py[n-1],BLACK);
        }
        
       // for(int i=0;i<n;i++)   DrawCircle(px[i],py[i],5.0,RED);
        
        DrawCircle(px[0],py[0],7.0,GREEN);
        DrawText(TextFormat("Distance=%d",distance),620,10,20,BLACK);
        EndDrawing();
    }
    
}


