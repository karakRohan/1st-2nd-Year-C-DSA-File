//  #include<stdio.h>
//  #include<stdlib.h>
//  int main()
//  {
//     int x=2,y=2,z=2,i,j,k;
//     int ***arr=(int***)malloc(x*sizeof(int**));
//     for(i=0;i<x;i++)
//     {
//         arr[i]=(int**)malloc(y*sizeof(int*));
//         for(j=0;j<y;j++)
//         arr[i][j]=(int*)malloc(z*sizeof(int));
//     }
//     printf("Enter Elements\n");
//     for(i=0;i<x;i++)
//     {
//         for(j=0;j<y;j++)
//         {
//             for(k=0;k<z;k++)
//             scanf("%d",&arr[i][j][k]);
//         }
//     }
//     printf("The Elements Are\n");
//     for(i=0;i<x;j++)
//     {
//         for(j=0;j<y;j++)
//         {
//             for(k=0;k<z;k++)
//             printf("%4d",arr[i][j][k]);
//         }
//         printf("\n");
//     } 
//     return 0;
//  }

 #include<stdio.h>
 int main(void)
 {
    int a[10][20][30]={{{0,1},{2,3},{4,5}},{{6,7},{8,9},{10,11}}};
    for(int i=0;i<10;++i)
    {
        for(int j=0;i<20;++j)   
      {
       for(int k=0;k<30;++k)
       {
        printf("a[%i][%i][%i]=%d",i,j,k,a[i][j][k]);
       }
      } 
    }
    return 0;
}
