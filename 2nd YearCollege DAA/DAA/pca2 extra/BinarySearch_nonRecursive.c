#include<stdio.h>
#include<conio.h>
void Binary_search(int[],int,int,int);       //prototype
void main()
{
    int list[10],i,first,last,sElement,n;
    printf("Enter how many numbers :");
    scanf("%d",&n);
    printf("Enter sorted numbners one by one :\n");
for(i=0;i<n;i++)
    scanf("%d",&list[i]);
first=0;
last=n-1;
printf("Enter searching element :");
scanf("%d",&sElement);
Binary_search(list,first,last,sElement);  //Function call
getch();
}
void Binary_search( int list[], int first, int last, int sElement)
{
int middle;
while (first <= last)
{
middle = (first+last)/2;
if (list[middle] == sElement)
{
printf("Element found at index %d.\n",middle);
break;
}
else if (list[middle] < sElement)
first = middle + 1;
else
last = middle - 1;
}
if (first > last)
printf("Element Not found in the list.");
}

