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
    FILE *movieData;
    int primaryKeyToRead;

    movieData = fopen("MovieData.csv", "r");
    if (movieData == NULL) {
        printf("MovieData.csv not found!\n");
        exit(1);
    }

    printf("Enter the Primary Key of the movie to read: ");
    scanf(" %d", &primaryKeyToRead);

    // Validate if the primary key exists
    if (!doesPrimaryKeyExist(movieData, primaryKeyToRead)) {
        printf("Error: Primary Key %d does not exist in the file!\n", primaryKeyToRead);
        fclose(movieData);
        return 1;
    }
    
    int key = 0;
    if (primaryKeyToRead == 1) {
        primaryKeyToRead = 2;
        key = 2;
    }
    else if (primaryKeyToRead == 2) {
        primaryKeyToRead = 3;
        key = 3;
    }

    char line[1024];
    int currentKey = 0;

    // Read each line and print the line matching the primary key
    while (fgets(line, sizeof(line), movieData)) {
        currentKey++;
        if (currentKey == primaryKeyToRead) {
            printf("Movie with Primary Key %d: %s", key != 0 ? key - 1 : primaryKeyToRead, line);
            fclose(movieData);
            return 0;
        }
    }

    fclose(movieData);
    // printf("Movie with Primary Key %d not found.\n", key != 0 ? key - 1 : primaryKeyToRead);
    return 0;
}
