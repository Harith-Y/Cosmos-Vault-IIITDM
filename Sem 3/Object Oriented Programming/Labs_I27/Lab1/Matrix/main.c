#include <stdio.h>
#include "matrix.h"

int main()
{
	struct matrix a, b, result;

	printf("Enter number of rows and columns for the matrix A: ");
	scanf(" %d %d", &a.rows, &a.cols);

	printf("Enter elements for the first matrix:\n");
	for (int i = 0; i < a.rows; i++)
		for (int j = 0; j < a.cols; j++)
			scanf(" %d", &a.data[i][j]);

	printf("Enter number of rows and columns for the matrix B: ");
	scanf(" %d %d", &b.rows, &b.cols);

	printf("Enter elements for the second matrix:\n");
	for (int i = 0; i < b.rows; i++)
		for (int j = 0; j < b.cols; j++)
			scanf(" %d", &b.data[i][j]);

	int choice = 0;
	while (printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Determinant\n6. Inverse\n7. Quit\nPlease Enter an Integer: ") && choice != 7 && scanf(" %d", &choice))
	{

		if (choice == 1)
		{
			if (a.rows == b.rows && a.cols == b.cols)
			{
				result = matrixAdd(a, b);
				printf("Result of addition:\n");
				for (int i = 0; i < result.rows; i++)
				{
					for (int j = 0; j < result.cols; j++)
						printf("%d ", result.data[i][j]);
					printf("\n");
				}
			}
			else
				printf("Error! Matrices must have the same dimensions.\n");
		}

		else if (choice == 2)
		{
			if (a.rows == b.rows && a.cols == b.cols)
			{
				result = matrixSubtract(a, b);
				printf("Result of subtraction:\n");
				for (int i = 0; i < result.rows; i++)
				{
					for (int j = 0; j < result.cols; j++)
						printf("%d ", result.data[i][j]);
					printf("\n");
				}
			}
			else
				printf("Error! Matrices must have the same dimensions.\n");
		}

		else if (choice == 3)
		{
			if (a.cols == b.rows)
			{
				result = matrixMultiply(a, b);
				printf("Result of multiplication:\n");
				for (int i = 0; i < result.rows; i++)
				{
					for (int j = 0; j < result.cols; j++)
						printf("%d ", result.data[i][j]);
					printf("\n");
				}
			}
			else
				printf("Error! Number of columns in the matrix A must equal the number of rows in the matrix B.\n");
		}

		else if (choice == 4)
		{
			printf("Choose Matrix for Transpose (1 or 2): ");
			int matrixChoice;
			scanf(" %d", &matrixChoice);

			if (matrixChoice == 1)
				result = matrixTranspose(a);

			else if (matrixChoice == 2)
				result = matrixTranspose(b);

			else
			{
				printf("Invalid choice. Please enter 1 or 2.\n");
				continue;
			}

			printf("Result of transpose:\n");
			for (int i = 0; i < result.rows; i++)
			{
				for (int j = 0; j < result.cols; j++)
					printf("%d ", result.data[i][j]);
				printf("\n");
			}
		}

		else if (choice == 5)
		{
			printf("Choose Matrix for Determinant (1 or 2): ");
			int matrixChoice;
			scanf(" %d", &matrixChoice);

			int determinant;
			if (matrixChoice == 1)
				determinant = matrixDeterminant(a);

			else if (matrixChoice == 2)
				determinant = matrixDeterminant(b);

			else
			{
				printf("Invalid choice. Please enter 1 or 2.\n");
				continue;
			}

			printf("Determinant: %d\n", determinant);
		}

		else if (choice == 6)
		{
			printf("Choose Matrix for Inverse (1 or 2): ");
			int matrixChoice;
			scanf(" %d", &matrixChoice);

			if (matrixChoice == 1)
				result = matrixInverse(a);

			else if (matrixChoice == 2)
				result = matrixInverse(b);

			else
			{
				printf("Invalid choice. Please enter 1 or 2.\n");
				continue;
			}

			if (result.rows != 0 && result.cols != 0)
			{
				printf("Result of inverse:\n");
				for (int i = 0; i < result.rows; i++)
				{
					for (int j = 0; j < result.cols; j++)
						printf("%d ", result.data[i][j]);
					printf("\n");
				}
			}
		}

		else if (choice == 7)
			printf("Exiting program. Thanks for using!\n");

		else
			printf("Please enter a valid choice!\n");
	}

	return 0;
}
