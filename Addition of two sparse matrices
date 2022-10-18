#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r1, c1, r2, c2, i, j, k, count1, count2, size1, size2;
    count1 = size1 = count2 = size2 = 0;

    int **a1;
    int **a2;

    // Take inputs from the user
    printf("\nEnter rows and columns for the 1st matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("\nEnter rows and columns for the 2nd matrix: ");
    scanf("%d %d", &r2, &c2);

    // If the rows and columns are not equal then show error message and take inputs again
    while (r1 != r2 || c1 != c2)
    {
        printf("\nERROR! rows and coloumns must be equal to perform addition...\nEnter rows and columns again.\n");
        printf("\nEnter rows and columns for the 1st matrix: ");
        scanf("%d %d", &r1, &c1);
        printf("\nEnter rows and columns for the 2nd matrix: ");
        scanf("%d %d", &r2, &c2);
    }

    // Dynamically allocate space for matrices a1 and a2 according to the user inputs
    a1 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
    {
        a1[i] = (int *)malloc(c1 * sizeof(int));
    }

    a2 = (int **)malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++)
    {
        a2[i] = (int *)malloc(c2 * sizeof(int));
    }

    // take the elements of the 1st matrix as user inputs
    printf("\nEnter the elements of the 1st matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }

    // print the 1st Matrix
    printf("\nElements are:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t", a1[i][j]);
        }
        printf("\n");
    }

    // count the number of 0 in 1st Matrix
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (a1[i][j] == 0)
            {
                count1++;
            }
        }
    }

    // Check whether the 1st Matrix is a sparse matrix or not; if not then exit
    if (count1 < ((r1 * c1) / 2))
    {
        printf("\nMatrix 1 is not sparse matrix\n\nSo sparse matrix addition is  not possible\n\nExiting code execution...");
        exit(0);
    }

    // if sparse matrix then count the non-zero elements and store the value in size1
    printf("\nMatrix 1 is a sparse matrix \n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (a1[i][j] != 0)
            {
                size1++;
            }
        }
    }

    // Create the shortcut form of sparse matrix a1
    int compactMatrix1[size1 + 1][3];
    compactMatrix1[0][0] = r1;
    compactMatrix1[0][1] = c1; // The 1st row contains the total no. of rows,columns and non-zero elements
    compactMatrix1[0][2] = size1;
    k = 1;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (a1[i][j] != 0)
            {
                compactMatrix1[k][0] = i;
                compactMatrix1[k][1] = j;
                compactMatrix1[k][2] = a1[i][j];
                k++;
            }

    // Print the shortcut form of a1
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < size1 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", compactMatrix1[i][j]);

        printf("\n");
    }

    // take the elements of the 2nd matrix as user inputs
    printf("\nEnter the elements of the 2nd matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }

    // print the 2nd Matrix
    printf("\nElements are:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", a2[i][j]);
        }
        printf("\n");
    }

    // count the number of 0 in 2nd Matrix
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            if (a2[i][j] == 0)
            {
                count2++;
            }
        }
    }

    // Check whether the 2nd Matrix is a sparse matrix or not; if not then exit
    if (count2 < ((r2 * c2) / 2))
    {
        printf("\nMatrix 2 is not sparse matrix\n\nSo sparse matrix addition is  not possible\n\nExiting code execution...");
        exit(0);
    }

    // if sparse matrix then count the non-zero elements and store the value in size2
    printf("\nMatrix 2 is a sparse matrix \n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            if (a2[i][j] != 0)
            {
                size2++;
            }
        }
    }

    // Create the shortcut form of sparse matrix a2
    int compactMatrix2[size2 + 1][3];
    compactMatrix2[0][0] = r2;
    compactMatrix2[0][1] = c2; // The 1st row contains the total no. of rows,columns and non-zero elements
    compactMatrix2[0][2] = size2;
    k = 1;
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            if (a2[i][j] != 0)
            {
                compactMatrix2[k][0] = i;
                compactMatrix2[k][1] = j;
                compactMatrix2[k][2] = a2[i][j];
                k++;
            }

    // Print the shortcut form of a2
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < size2 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", compactMatrix2[i][j]);

        printf("\n");
    }

    // Addition Part
    // Let i,j,k be the indices of sparse matrices of a1,a2 and the result matrix
    i = j = k = 1;      // Initialize i,j,k to 1
    int result[100][3]; // Create result matrix to store the addition result

    result[0][0] = compactMatrix1[0][0]; // 1st row -> 1st column -> Total no of rows
    result[0][1] = compactMatrix1[0][1]; // 1st row -> 2nd column -> Total no of columns

    // Transverse both sparse matrices from 2nd row
    while ((i <= size1) && (j <= size2)) // Repeat till the end of any matrix triplet
    {
        if (compactMatrix1[i][0] == compactMatrix2[j][0]) // if (row no. of matrix1 == row no. of matrix2)
        {
            if (compactMatrix1[i][1] == compactMatrix2[j][1]) // if (column no. of matrix1 == column no. of matrix2)
            {
                result[k][0] = compactMatrix1[i][0];
                result[k][1] = compactMatrix1[i][1];
                result[k][2] = compactMatrix1[i][2] + compactMatrix2[j][2]; // make the addition of non-zero values and store in result
                i++;
                j++; // incrementing all the indices
                k++;
            }
            else // which ever has less column value copy that to result by incrementing respective indices
            {
                if (compactMatrix1[i][1] < compactMatrix2[j][1]) // if matrix1 has less column value
                {
                    result[k][0] = compactMatrix1[i][0];
                    result[k][1] = compactMatrix1[i][1]; // copy all matrix1 elements to result
                    result[k][2] = compactMatrix1[i][2];
                    i++; // increment i,k
                    k++;
                }
                else
                {
                    if (compactMatrix1[i][1] > compactMatrix2[j][1]) // if matrix2 has less column value
                    {
                        result[k][0] = compactMatrix2[j][0];
                        result[k][1] = compactMatrix2[j][1]; // copy all matrix2 elements to result
                        result[k][2] = compactMatrix2[j][2];
                        j++; // increment j,k
                        k++;
                    }
                }
            }
        }
        else // compare rows of both sparse matrices which ever has less row value copy to result by incrementing respective indices
        {
            if (compactMatrix1[i][0] > compactMatrix2[j][0]) // if matrix2 has less row value
            {
                result[k][0] = compactMatrix2[j][0];
                result[k][1] = compactMatrix2[j][1]; // copy all matrix2 elements to result
                result[k][2] = compactMatrix2[j][2];
                j++; // increment j,k
                k++;
            }
            else
            {
                if (compactMatrix1[i][0] < compactMatrix2[j][0]) // if matrix1 has less row value
                {
                    result[k][0] = compactMatrix1[i][0];
                    result[k][1] = compactMatrix1[i][1]; // copy all matrix1 elements to result
                    result[k][2] = compactMatrix1[i][2];
                    i++; // increment i,k
                    k++;
                }
            }
        }
    }

    // copy the remaining term of sparse matrix (if any) to result matrix
    while ((j <= size2) && (i >= size1)) // when matrix1 has ended but matrix2 has not
    {
        result[k][0] = compactMatrix2[j][0];
        result[k][1] = compactMatrix2[j][1]; // copy the remaining terms of matrix2 to result
        result[k][2] = compactMatrix2[j][2];
        j++; // increment j,k
        k++;
    }

    while ((i <= size1) && (j >= size2)) // when matrix2 has ended but matrix1 has not
    {
        result[k][0] = compactMatrix1[i][0];
        result[k][1] = compactMatrix1[i][1]; // copy the remaining terms of matrix1 to result
        result[k][2] = compactMatrix1[i][2];
        i++; // increment i,k
        k++;
    }

    result[0][2] = k - 1; // 1st row -> 3rd column -> k-1 -> Total no. of non-zero elements in result matrix

    // print the Result Matrix
    printf("\nAddition Result:\n");
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < result[0][2] + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", result[i][j]);

        printf("\n");
    }

    // Free the dynamically allocated memories of a1 and a2
    for (i = 0; i < r1; i++)
    {
        free(a1[i]);
    }
    free(a1);
    for (i = 0; i < r2; i++)
    {
        free(a2[i]);
    }
    free(a2);

    return 0;
}
