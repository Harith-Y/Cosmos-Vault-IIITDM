#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *movieData;

    // First check if the file exists
    movieData = fopen("MovieData.csv", "r");
    if (movieData == NULL) {
        printf("MovieData.csv does not exist, please create a file\n");
        exit(1);
    }
    fclose(movieData); // Close the file after checking existence

    int choice = 0;
    while (1) {
        printf("----------Menu----------\n1. Enter more movie details\n2. Define new categories\n3. Exit\nEnter: ");
        scanf(" %d", &choice);
        
        // Clear the input buffer to handle the newline left by scanf
        getchar();  // This will consume the newline character left in the input buffer

        if (choice == 1) {
            // For Entering the details of the Movies:
            movieData = fopen("MovieData.csv", "a");

            // Open the file in read mode to check for categories
            FILE *tempFile = fopen("MovieData.csv", "r");
            if (!tempFile) {
                printf("Unable to open file.\n");
                exit(1);
            }

            char ch;
            int numOfCategories = 0;
            while ((ch = fgetc(tempFile)) != '\n' && ch != EOF) {
                if (ch == ',')
                    numOfCategories++;
            }

            fclose(tempFile); // Close the file after counting categories

            printf("Categories have already been defined in MovieData.csv\nEnter the movie details now\n");
            int numOfMovies = 0;
            printf("Enter the Number of Movies: ");
            scanf(" %d", &numOfMovies);

            // Clear the input buffer after reading numOfMovies
            getchar();  // This will consume the newline character left in the input buffer

            // Reopen the file to get the current primary key
            tempFile = fopen("MovieData.csv", "r");
            int PRIMARY_KEY = 0;
            while ((ch = fgetc(tempFile)) != EOF) {
                if (ch == '\n')
                    PRIMARY_KEY++;
            }
            fclose(tempFile);

            // Now we have the current highest PRIMARY_KEY (we will use this value for new entries)
            PRIMARY_KEY++; // Increment to get the next available primary key

            for (int i = 1; i <= numOfMovies; i++) {
                fprintf(movieData, "%d", PRIMARY_KEY);
                fprintf(movieData, "%s", ",");

                for (int j = 1; j <= numOfCategories; j++) {
                    printf("Enter the Category %d for Movie %d: \t", j, i);
                    char movieParam[256] = {0};
                    // Use fgets to allow spaces in input
                    fgets(movieParam, sizeof(movieParam), stdin);

                    // Remove the newline character if it exists
                    movieParam[strcspn(movieParam, "\n")] = '\0';

                    fprintf(movieData, "%s", movieParam);

                    // A category value has been entered, time for the next Category value.
                    if (j < numOfCategories) {
                        fprintf(movieData, "%s", ",");
                    }
                }
                printf("\n");

                // The category details for a movie have been entered, it's time to move to the next line.
                fprintf(movieData, "%s", "\n");
                PRIMARY_KEY++; // Increment primary key after each movie entry
            }

            fclose(movieData);
        }
        
        else if (choice == 2) {
            // For Entering the details of the categories:
            movieData = fopen("MovieData.csv", "w");

            int numOfCategories = 0;
            printf("Enter the Number of Categories: ");
            scanf(" %d", &numOfCategories);

            // Clear the input buffer after reading numOfCategories
            getchar();  // This will consume the newline character left in the input buffer

            fprintf(movieData, "%s", "PRIMARY_KEY");
            fprintf(movieData, "%s", ",");

            for (int i = 1; i <= numOfCategories; i++) {
                printf("Enter the category %d: \t", i);
                char categoryName[256] = {0};
                // Use fgets to allow spaces in category names
                fgets(categoryName, sizeof(categoryName), stdin);

                // Remove the newline character if it exists
                categoryName[strcspn(categoryName, "\n")] = '\0';

                fprintf(movieData, "%s", categoryName);

                // A category name has been entered, time for the next Category name.
                if (i < numOfCategories) {
                    fprintf(movieData, "%s", ",");
                }
            }

            // All the categories have been defined
            fprintf(movieData, "%s", "\n");

            fclose(movieData);
        }

        else if (choice == 3) {
            printf("Thank you for using!\nExiting...\n");
            break;
        }

        else
            printf("Invalid Input, Please try again!\n");
        
    }
    
    return 0;
}

