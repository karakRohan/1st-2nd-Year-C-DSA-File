// // // // #include <stdio.h>
// // // // #include <math.h>

// // // // int main()
// // // // {
// // // //     float a, b, c, root1, root2;
    
// // // //     printf("Enter Coefficients (a, b, c): ");
// // // //     scanf("%f%f%f", &a, &b, &c);
    
// // // //     if (a == 0 && b == 0)
// // // //         printf("No Solution\n");
// // // //     else if (a == 0)
// // // //     {
// // // //         root1 = -c / b;
// // // //         printf("Root is %f\n", root1);
// // // //     }
// // // //     else if ((b * b - 4 * a * c) < 0)
// // // //         printf("No Real Roots\n");
// // // //     else
// // // //     {
// // // //         root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
// // // //         root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
// // // //         printf("Roots are %f and %f\n", root1, root2);
// // // //     }

// // // //     return 0;
// // // // }

// // // #include <stdio.h>
// // // #include <stdlib.h>

// // // int main() {
// // //     // Dimensions of the 3D array
// // //     int x_size = 10;
// // //     int y_size = 20;
// // //     int z_size = 30;

// // //     // Dynamically allocate memory for the 3D array
// // //     int ***array3D = (int ***)malloc(x_size * sizeof(int **));
// // //     if (array3D == NULL) {
// // //         printf("Memory allocation failed.\n");
// // //         return 1;
// // //     }

// // //     for (int i = 0; i < x_size; i++) {
// // //         array3D[i] = (int **)malloc(y_size * sizeof(int *));
// // //         if (array3D[i] == NULL) {
// // //             printf("Memory allocation failed.\n");
// // //             return 1;
// // //         }
// // //         for (int j = 0; j < y_size; j++) {
// // //             array3D[i][j] = (int *)malloc(z_size * sizeof(int));
// // //             if (array3D[i][j] == NULL) {
// // //                 printf("Memory allocation failed.\n");
// // //                 return 1;
// // //             }
// // //         }
// // //     }

// // //     // Initialize the array
// // //     for (int i = 0; i < x_size; i++) {
// // //         for (int j = 0; j < y_size; j++) {
// // //             for (int k = 0; k < z_size; k++) {
// // //                 array3D[i][j][k] = i * y_size * z_size + j * z_size + k;
// // //             }
// // //         }
// // //     }

// // //     // Access and print an element
// // //     printf("Element at (5, 10, 15): %d\n", array3D[5][10][15]);

// // //     // Free the dynamically allocated memory
// // //     for (int i = 0; i < x_size; i++) {
// // //         for (int j = 0; j < y_size; j++) {
// // //             free(array3D[i][j]);
// // //         }
// // //         free(array3D[i]);
// // //     }
// // //     free(array3D);

// // //     return 0;
// // // }


// // // 

// // // #include<stdio.h>
// // // int main ()
// // // {
// // //     int i,j;
// // //     for(i=0;i<6;i++)
// // //     {
// // //         for(j=0;j<i;j++)
// // //         {
// // //             printf(" ");
// // //         }
// // //         for(j='F'-i;j>='A';j--)
// // //         {
// // //             printf("%c",j);
// // //         }
// // //         printf("\n");
// // //     }

// // //     return 0;

// // // }

// // #include <stdio.h>

// // int main() {
// //     int n, i, j;
// //     printf("Enter the number of lines: ");
// //     scanf("%d", &n);

// //     for (i = 0; i < n; i++) {
// //         for (j = 0; j < i; j++) {
// //             printf(" ");
// //         }
// //         for (j = 0; j < n - i; j++) {
// //             printf("%C", 'F'-j-i);
// //         }
// //         printf("\n");
// //     }

// //     return 0;
// // }


// // #include <stdio.h>
// // int main() {
// //     int n, i, j;
// //     printf("Enter the number of rows: ");
// //     scanf("%d", &n);
// //     for (i = 1; i <= n; i++) {
// //         for (j = 1; j <= i; j++) {
// //             printf("%d ", i);
// //         }
// //         printf("\n");
// //     }

// //     return 0;
// // }

// //  #include <stdio.h>
// //  int main() 
// // {
// //     int a,b,c;
// //     printf("Enter A 3 Numbers");
// //     scanf("%d%d%d",&a,&b,&c);
// //     if(a>b&&a>c)
// //     {
// //         printf("%d is greatest", a);
// //     }
// //     else if(b>a&&b>c)
// //     {
// //         printf("%d is greatest", b);
// //     }
// //     else
// //     {
// //         printf("%d is greatest", c);
// //     }
// //     return 0;
// // }

// // #include <stdio.h>
// //  int main()
// // {
// //     int a;
// //     printf("Enter a Numbers : ");
// //     scanf("&d",&a);
// //     if(a%2==0)
// //     {
// //         printf("%d is even",a);
// //     }
// //     else{
// //         printf("%d is Odd",a);
// //     }
// //     return 0;

// // }

// // #include<stdio.h>
// // #include<math.h>
// // int main()
// // {
// //     int a,b,c,root1,root2;
// //     printf("Enter the co-effincents :");
// //     scanf("%d %d %d",&a,&b,&c);
// //     if(a==0 && b==0)
// //     {
// //         printf("No sollution");
// //     }
// //     else if(a==0)
// //     {
// //         root1=-c/b;
// //         printf("Root is %f",root1);
// //     }
// //     else
// //     {
// //         root1=((-b+sqrt(b*b-4*a*c))/(2*a));
// //         root2=((-b-sqrt(b*b-4*a*c))/(2*a));
// //         printf("Roots are %d %d",root1,root2);

// //     }
// // }

// // #include <stdio.h>

// // int main() {
// //     int totalMarks;
// //     char grade;
  
// //     printf("Enter your total marks: ");
// //     scanf("%d", &totalMarks);

    
// //     if (totalMarks >= 90) {
// //         grade = 'A';
// //     } else if (totalMarks >= 80) {
// //         grade = 'B';
// //     } else if (totalMarks >= 70) {
// //         grade = 'C';
// //     } else if (totalMarks >= 60) {
// //         grade = 'D';
// //     } else {
// //         grade = 'F';
// //     }
 
// //     printf("Your grade is: %c\n", grade);

// //     return 0;
// // }

// //  #include <stdio.h>

// // void printPattern(int n) {
// //     for (int i = 1; i <= n; i++) {
// //         // Print leading spaces
// //         for (int j = i; j < n; j++) {
// //             printf("  ");
// //         }

// //         // Print increasing part of the pattern
// //         for (int j = 1; j <= i; j++) {
// //             printf("%d ", j);
// //         }

// //         // Print decreasing part of the pattern
// //         for (int j = i - 1; j >= 1; j--) {
// //             printf("%d ", j);
// //         }

// //         // Move to the next line
// //         printf("\n");
// //     }
// // }

// // int main() {
// //     int n;

// //     // Ask the user to enter a number
// //     printf("Enter a number: ");
// //     scanf("%d", &n);

// //     // Print the pattern
// //     printPattern(n);

// //     return 0;
// // }


// #include <stdio.h>

// int main() {
//     int n;

//     // Prompt user to enter the size of the matrix
//     printf("Enter the size of the matrix (n x n): ");
//     scanf("%d", &n);

//     int matrix[n][n];

//     // Input the matrix elements
//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     // Find the maximum element
//     int maxElement = matrix[0][0];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (matrix[i][j] > maxElement) {
//                 maxElement = matrix[i][j];
//             }
//         }
//     }

//     // Print the maximum element
//     printf("The maximum element in the matrix is: %d\n", maxElement);

//     return 0;
// }

#include <stdio.h>

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int rows = 4; // Change this value to adjust the number of rows in the pattern
    printPattern(rows);
    return 0;
}

