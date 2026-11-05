#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
srand(time(NULL));
int n,i,j,minDist=2000,dist,index;

printf("Enter the number of cities:");
scanf("%d",&n);

int cx[n],cy[n];
int px[n],py[n];
  

//cities are randomly placed with co-ordinates between (0,0) and (1000,1000)
for(i=0;i<n;i++)
{
cx[i]=rand()%1000;
cy[i]=rand()%1000;
}

px[0]=cx[0];
py[0]=cy[0];

cx[0]=-1;
cy[0]=-1;

for(i=0;i<n;i++)
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
px[i+1]=cx[index];
py[i+1]=cy[index];
cx[index]=-1;
cy[index]=-1;
}

printf("Sequential Path by Nearest Neighbour Method:\n");
for(i=0;i<n;i++)
{
printf("City%d: X=%d,Y=%d\n",i,px[i],py[i]);
}
printf("Returning to starting city: X=%d,Y=%d",px[0],py[0]);

}
