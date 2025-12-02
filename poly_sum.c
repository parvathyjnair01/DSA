#include<stdio.h>
struct poly
{
int coef;
int exp;
}p1[30],p2[30],p3[30];
int main()
{
  int n1,n2,n3,i,j,k;

printf("Enter the no.of terms in 1'st polynomial:");
scanf("%d",&n1);
for(i=0;i<n1;i++)
{
printf("Enter the coefficents & exponents of terms %d : ", i+1);
scanf("%d %d",&p1[i].coef,&p1[i].exp);
}
printf("\n Enter the no.of terms in 2'nd polynomial :");
scanf("%d",&n2);
for(i=0;i<n2;i++)
{
printf("Enter the coefficents & exponents of terms %d:",i+1);
scanf("%d %d",&p2[i].coef,&p2[i].exp);
}
i=0;j=0;k=0;
while(i<n1 && j<n2)
{
   if(p1[i].exp==p2[j].exp)
    {
       p3[k].coef=p1[i].coef+p2[j].coef;
       p3[k].exp=p1[i].exp;
       i++;k++;j++;
   }
   else if (p1[i].exp>p2[j].exp)
     {
      p3[k].coef = p1[i].coef;
      p3[k].exp = p1[i].exp;
      k++;i++;
    }
  else
  if(p1[i].exp < p2[j].exp)
   {
    p3[k].coef = p2[j].coef;
    p3[k].exp = p2[j].exp;
    k++;j++;
  }
}

n3=k;
printf("The Polynomial is:");
for(k=0;k<n3;k++)
{
  if (p3[k].exp!=0)
    {
    printf("%d x^%d +",p3[k].coef,p3[k].exp);
    }
else
  {
     printf("%d",p3[k].coef);
   }
}
printf("\n");
return 0;
}




    


