// // // // #include<stdio.h>
// // // // int main ()
// // // // {
// // // //     int a;
// // // //     printf("Enter a Number : ");
// // // //     scanf("%d",&a);
// // // //     if (a%2==0);
// // // //     {
// // // //         printf("%d is Even",a);
// // // //     }
// // // //         printf ("%d is Odd",a);

// // // //     return 0;
// // // // }
        
// // // #include<stdio.h>
// // // int main ()
// // // {
// // //     int n, i, j;
// // //     printf ("Enter How Many Lines : ");
// // //     scanf ("%d", &n);
// // //     for(i=1;i<=n;i++)
// // //     {
// // //         for(j=1;j<=n;j++)
// // //         {
// // //             if(i==1||i==n||j==1||j==n||i==j||i+j==n+1)
// // //                printf("*");
// // //             else
// // //                printf(" ");  
// // //         }
// // //         printf("\n");
// // //     }
// // //     return 0;
// // // }



// // // // #include<stdio.h>
// // // // int main()
// // // // {
// // // //     int n=5, i, j;
// // // //     printf ("Enter How Many Lines : ");
// // // //     scanf ("%d", &n);
// // // //     for(i=1;i<=n;i++)
// // // //     {
// // // //         if(i==1||i==n)
// // // //         {
// // // //             for(j=1;j<=n;j++)
// // // //             printf("*");
// // // //         }
// // // //         else
// // // //         {
// // // //             for(j=1;j<=n;j++)
// // // //             {
// // // //              if(j==1||j==n)
// // // //               printf("*");
// // // //              else
// // // //               printf(" ");
// // // //             }
// // // //         }
// // // //         printf("\n");
// // // //     }
// // // //     return 0;
// // // // }/

// // #include <stdio.h>
// // #include <stdlib.h>

// // int main() {
// //     // Dimensions of the 3D array
// //     int x_size = 10;
// //     int y_size = 20;
// //     int z_size = 30;

// //     // Dynamically allocate memory for the 3D array
// //     int ***array3D = (int ***)malloc(x_size * sizeof(int **));
// //     if (array3D == NULL) {
// //         printf("Memory allocation failed.\n");
// //         return 1;
// //     }

// //     for (int i = 0; i < x_size; i++) {
// //         array3D[i] = (int **)malloc(y_size * sizeof(int *));
// //         if (array3D[i] == NULL) {
// //             printf("Memory allocation failed.\n");
// //             return 1;
// //         }
// //         for (int j = 0; j < y_size; j++) {
// //             array3D[i][j] = (int *)malloc(z_size * sizeof(int));
// //             if (array3D[i][j] == NULL) {
// //                 printf("Memory allocation failed.\n");
// //                 return 1;
// //             }
// //         }
// //     }

// //     // Initialize the array
// //     for (int i = 0; i < x_size; i++) {
// //         for (int j = 0; j < y_size; j++) {
// //             for (int k = 0; k < z_size; k++) {
// //                 array3D[i][j][k] = i * y_size * z_size + j * z_size + k;
// //             }
// //         }
// //     }

// //     // Access and print an element
// //     printf("Element at (5, 10, 15): %d\n", array3D[5][10][15]);

// //     // Free the dynamically allocated memory
// //     for (int i = 0; i < x_size; i++) {
// //         for (int j = 0; j < y_size; j++) {
// //             free(array3D[i][j]);
// //         }
// //         free(array3D[i]);
// //     }
// //     free(array3D);

// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>

// #define DIM1 10
// #define DIM2 20
// #define DIM3 30

// int main() {
//     int ***array;  // Declare a 3D array of pointers to pointers to integers

//     // Allocate memory for the first dimension (array of pointers to 2D arrays)
//     array = (int***)malloc(DIM1 * sizeof(int**));
//     if (array == NULL) {
//         fprintf(stderr, "Memory allocation failed for first dimension\n");
//         return 1;
//     }

//     // Allocate memory for the second dimension (array of pointers to integers)
//     for (int i = 0; i < DIM1; i++) {
//         array[i] = (int**)malloc(DIM2 * sizeof(int*));
//         if (array[i] == NULL) {
//             fprintf(stderr, "Memory allocation failed for second dimension, row %d\n", i);
//             // Free previously allocated memory to avoid memory leaks
//             for (int j = 0; j < i; j++) {
//                 free(array[j]);
//             }
//             free(array);
//             return 1;
//         }
//     }

//     // Allocate memory for the third dimension (array of integers)
//     for (int i = 0; i < DIM1; i++) {
//         for (int j = 0; j < DIM2; j++) {
//             array[i][j] = (int*)malloc(DIM3 * sizeof(int));
//             if (array[i][j] == NULL) {
//                 fprintf(stderr, "Memory allocation failed for third dimension, row %d, col %d\n", i, j);
//                 // Free previously allocated memory to avoid memory leaks
//                 for (int k = 0; k < j; k++) {
//                     free(array[i][k]);
//                 }
//                 for (int k = 0; k < i; k++) {
//                     free(array[i][k]);
//                 }
//                 free(array);
//                 return 1;
//             }
//         }
//     }

//     // (Optional) Initialize the elements with a specific value (replace -1 with your desired value)
//     for (int i = 0; i < DIM1; i++) {
//         for (int j = 0; j < DIM2; j++) {
//             for (int k = 0; k < DIM3; k++) {
//                 array[i][j][k] = -1;  // Or any other value you want
//             }
//         }
//     }

//     // Accessing elements: array[i][j][k]
//     // ... your code to use the array ...

//     // Deallocate memory to prevent memory leaks
//     for (int i = 0; i < DIM1; i++) {
//         for (int j = 0; j < DIM2; j++) {
//             free(array[i][j]);
//         }
//         free(array[i]);
//     }
//     free(array);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare a pointer to a 3D array of integers
  int *array;

  // Allocate memory for the array
  array = (int *)malloc(10 * 20 * 30 * sizeof(int));

  // Check if the memory allocation was successful
  if (array == NULL) {
    printf("Error: Could not allocate memory for the array.\n");
    return 1;
  }

  // Initialize the array elements
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      for (int k = 0; k < 30; k++) {
        array[i * 20 * 30 + j * 30 + k] = i + j + k;
      }
    }
  }

  // Print the array elements
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      for (int k = 0; k < 30; k++) {
        printf("%d ", array[i * 20 * 30 + j * 30 + k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  // Free the memory allocated for the array
  free(array);

  return 0;
}