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
    int primaryKeyToDelete;

    movieData = fopen("MovieData.csv", "r");
    if (movieData == NULL) {
        printf("MovieData.csv not found!\n");
        exit(1);
    }

    // Create a temporary file to store data without the deleted row
    tempFile = fopen("TempMovieData.csv", "w");
    if (tempFile == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(movieData);
        exit(1);
    }

    printf("Enter the Primary Key of the movie you want to delete: ");
    scanf(" %d", &primaryKeyToDelete);

    // Validate if the primary key exists
    if (!doesPrimaryKeyExist(movieData, primaryKeyToDelete)) {
        printf("Error: Primary Key %d does not exist in the file!\n", primaryKeyToDelete);
        fclose(movieData);
        return 1;
    }

    primaryKeyToDelete++;  // Increment to match the primary key in the file

    char line[1024];
    int currentKey = 0;

    // Read each line and write to the temp file except the line with the primary key to delete
    while (fgets(line, sizeof(line), movieData)) {
        currentKey++;
        // Skip the line that matches the primary key
        if (currentKey == primaryKeyToDelete)
            continue;
        
        fputs(line, tempFile);
    }

    fclose(movieData);
    fclose(tempFile);

    // Remove the original file and rename the temp file to the original file
    remove("MovieData.csv");
    rename("TempMovieData.csv", "MovieData.csv");

    printf("Movie with Primary Key %d has been deleted.\n", primaryKeyToDelete - 1);

    return 0;
}
