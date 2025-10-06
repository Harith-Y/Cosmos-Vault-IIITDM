#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a primary key exists in the file
int doesPrimaryKeyExist(FILE *file, int primaryKey) {
    char line[1024];
    int currentKey = 0;
    
    // Skip header line
    fgets(line, sizeof(line), file);
    
    // Read through file looking for matching primary key
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token != NULL) {
            int lineKey = atoi(token);
            if (lineKey == primaryKey) {
                rewind(file);  // Reset file position before returning
                return 1;  // Key found
            }
        }
    }
    rewind(file);  // Reset file position before returning
    return 0;  // Key not found
}

int main() {
    FILE *movieData, *tempFile;
    int primaryKeyToUpdate, columnIndexToUpdate;
    char updatedValue[256];

    movieData = fopen("MovieData.csv", "r");
    if (movieData == NULL) {
        printf("MovieData.csv not found!\n");
        exit(1);
    }

    printf("Enter the Primary Key of the movie to update: ");
    scanf(" %d", &primaryKeyToUpdate);

    // Validate if the primary key exists
    if (!doesPrimaryKeyExist(movieData, primaryKeyToUpdate)) {
        printf("Error: Primary Key %d does not exist in the file!\n", primaryKeyToUpdate);
        fclose(movieData);
        return 1;
    }

    printf("Enter the Category number to update (starting from 1): ");
    scanf(" %d", &columnIndexToUpdate);
    columnIndexToUpdate++;  // Increment to match the column number in the file

    printf("Enter the new value: ");
    getchar();  // To clear newline from buffer
    fgets(updatedValue, sizeof(updatedValue), stdin);
    updatedValue[strcspn(updatedValue, "\n")] = '\0';  // Remove newline

    // Create a temporary file to store updated data
    tempFile = fopen("TempMovieData.csv", "w");
    if (tempFile == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(movieData);
        exit(1);
    }

    char line[1024];
    char headerLine[1024];
    
    // First, read and write the header line
    fgets(headerLine, sizeof(headerLine), movieData);
    fputs(headerLine, tempFile);

    // Process the rest of the file
    while (fgets(line, sizeof(line), movieData)) {
        char lineCopy[1024];
        strcpy(lineCopy, line);
        char *firstToken = strtok(lineCopy, ",");
        int currentKey = atoi(firstToken);

        if (currentKey == primaryKeyToUpdate) {
            // Count total number of columns
            char countCopy[1024];
            strcpy(countCopy, line);
            int totalColumns = 1;
            char *countToken = strtok(countCopy, ",");
            while (strtok(NULL, ",") != NULL) {
                totalColumns++;
            }

            // Update the line
            char *token = strtok(line, ",");
            int column = 1;
            while (token != NULL) {
                // Remove any trailing newline from the last token
                token[strcspn(token, "\n")] = '\0';
                
                if (column == columnIndexToUpdate)
                    fprintf(tempFile, "%s", updatedValue);
                else
                    fprintf(tempFile, "%s", token);

                // Add comma only if it's not the last column
                if (column < totalColumns)
                    fprintf(tempFile, ",");
                
                token = strtok(NULL, ",");
                column++;
            }
            fprintf(tempFile, "\n");  // Add newline at the end of the updated line
        } 
        else
            fputs(line, tempFile);  // Copy other lines as is
            
    }

    fclose(movieData);
    fclose(tempFile);

    // Remove the original file and rename the temp file to the original file
    remove("MovieData.csv");
    rename("TempMovieData.csv", "MovieData.csv");

    printf("Movie with Primary Key %d has been updated.\n", primaryKeyToUpdate);

    return 0;
}