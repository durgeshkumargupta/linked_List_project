/* Multiplication of two matrix(3x3) */
#include<stdio.h>
#include<conio.h>
#define r 3
#define c 3
void main()
{
	int p=0,row,col,k=0,sum=0,v=1,a[r][c],b[r][c],d[r][c];
	clrscr();
	/* Enter first matrix */
	for(row=0;row<r;row++)
	{
	  for(col=0;col<c;col++)
	  {
	    printf("Enter data[%d][%d]=",(row+1),(col+1));
	    scanf("%d",&a[row][col]);
	  }
	}
	printf("\n");
	/* Enter second matrix */
	for(row=0;row<r;row++)
	{
	   for(col=0;col<c;col++)
	   {
	      printf("Enter data[%d][%d]=",(row+1),(col+1));
	      scanf("%d",&b[row][col]);
	  }
	}
	printf("\n");
    /* Now print first matrix and second matrix */
    printf("\nShow Second matrix=\n");
      for(row=0;row<r;row++)
      {
	 for(col=0;col<c;col++)
	 {
	   printf("%3d",a[row][col]);
	 }
	 printf("\n");
      }
      printf("\n Second matrix=\n");
      for(row=0;row<r;row++)
      {
	for(col=0;col<c;col++)
	{
	  printf("%3d",b[row][col]);
	}
	printf("\n");
      }
    /* Now perform multiplication */
    printf("\n");
      for(row=0;row<r;row++)
      {
	for(k=0;k<r;k++)
	{
	  for(col=0;col<c;col++)
	  {
	    v=a[row][col]*b[col][k];
	    sum=sum+v;
	  }
	  d[row][p]=sum;
	  p++;
	  sum=0;
	  v=1;
	}
	p=0;
      }
      for(row=0;row<r;row++)
      {
	for(col=0;col<c;col++)
	{
	  printf("%3d",d[row][col]);
	}
	printf("\n");
      }
getch();
}

