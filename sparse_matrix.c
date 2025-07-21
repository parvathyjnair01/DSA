#include<stdio.h>
int main()
{
  int a[10][10],b[10][3],i,j,k=1,m,n;
  printf("Enter the rows and columns:");
  scanf("%d%d",&m,&n);
  printf("Enter the matrix:");
  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
   {
     scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
     {
       if(a[i][j]!=0)
        {
         b[k][0]=i;
         b[k][1]=j;
         b[k][2]=a[i][j];
         k++;
        }
        }
        }
        b[0][0]=m;
        b[0][1]=n;
        b[0][2]=k-1;
    for(i=0;i<k;i++)
    {
    for(j=0;j<3;j++)
     {
       printf("%d",b[i][j]);
      }
      printf("\n");
    }
     int a1[10][10],b1[10][3],p,q,r=1,m1,n1;
    printf("Enter the rows and columns matrix 2:");
  scanf("%d%d",&m1,&n1);
  printf("Enter the matrix 2:");
  for(p=0;p<m1;p++)
  {
   for(q=0;q<n1;q++)
   {
     scanf("%d",&a1[p][q]);
    }
  }
  for(p=0;p<m1;p++)
  {
    for(q=0;q<n1;q++)
     {
       if(a1[p][q]!=0)
        {
         b1[r][0]=p;
         b1[r][1]=q;
         b1[r][2]=a1[p][q];
         r++;
        }
        }
        }
        b1[0][0]=m1;
        b1[0][1]=n1;
        b1[0][2]=r-1;
    for(p=0;p<r;p++)
    {
    for(q=0;q<3;q++)
     {
       printf("%d",b1[p][q]);
      }
      printf("\n");
    }
    return 0;
    }
