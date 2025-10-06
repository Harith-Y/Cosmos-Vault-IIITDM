#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the highest primary key in the file
int findHighestPrimaryKey(FILE *file) {
    char line[1024];
    int highestKey = 0;
    int currentKey;
    
    // Skip the header line
    fgets(line, sizeof(line), file);
    
    // Read each line and extract the primary key
    while (fgets(line, sizeof(line), file)) {
        currentKey = atoi(line); // Convert the first number in the line to integer
        if (currentKey > highestKey)
            highestKey = currentKey;
    }
    
    return highestKey;
}

int main() {
    FILE *movieData;

    // First check if the file exists
    movieData = fopen("MovieData.csv", "r");
    if (movieData == NULL) {
        printf("MovieData.csv does not exist, please create a file\n");
        exit(1);
    }
    fclose(movieData);

    int choice = 0;
    while (1) {
        printf("----------Menu----------\n1. Enter more movie details\n2. Define new categories\n3. Exit\nEnter: ");
        scanf(" %d", &choice);
        
        getchar();  // Consume newline

        if (choice == 1) {
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

            // Find the highest existing primary key
            rewind(tempFile);  // Go back to start of file
            int PRIMARY_KEY = findHighestPrimaryKey(tempFile);
            
            fclose(tempFile);

            printf("Categories have already been defined in MovieData.csv\nEnter the movie details now\n");
            int numOfMovies = 0;
            printf("Enter the Number of Movies: ");
            scanf(" %d", &numOfMovies);
            getchar();

            for (int i = 1; i <= numOfMovies; i++) {
                PRIMARY_KEY++; // Increment to get next available key
                fprintf(movieData, "%d", PRIMARY_KEY);
                fprintf(movieData, "%s", ",");

                for (int j = 1; j <= numOfCategories; j++) {
                    printf("Enter the Category %d for Movie %d: \t", j, i);
                    char movieParam[256] = {0};
                    fgets(movieParam, sizeof(movieParam), stdin);
                    movieParam[strcspn(movieParam, "\n")] = '\0';

                    fprintf(movieData, "%s", movieParam);

                    if (j < numOfCategories)
                        fprintf(movieData, "%s", ",");
                    
                }
                printf("\n");
                fprintf(movieData, "%s", "\n");
            }

            fclose(movieData);
        }
        
        else if (choice == 2) {
            movieData = fopen("MovieData.csv", "w");

            int numOfCategories = 0;
            printf("Enter the Number of Categories: ");
            scanf(" %d", &numOfCategories);
            getchar();

            fprintf(movieData, "%s", "PRIMARY_KEY");
            fprintf(movieData, "%s", ",");

            for (int i = 1; i <= numOfCategories; i++) {
                printf("Enter the category %d: \t", i);
                char categoryName[256] = {0};
                fgets(categoryName, sizeof(categoryName), stdin);
                categoryName[strcspn(categoryName, "\n")] = '\0';

                fprintf(movieData, "%s", categoryName);

                if (i < numOfCategories) 
                    fprintf(movieData, "%s", ",");
                
            }

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
