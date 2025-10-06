#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to represent a Row/Entity of the Movie Data Table.
typedef struct {
    int id;
    char name[50];
    int year;
    float rating;
    char language[15];
} Row;


// To Display the Table in a table-like fashion.
void displayTable(Row *table, int rowCount, int *columns, int columnCount) {
    printf("+----+----------------------+-----+--------+\n");
    printf("| ID | Name                 | Year | Rating |\n");
    printf("+----+----------------------+-----+--------+\n");

    for (int i = 0; i < rowCount; i++) {
        if (columns[0]) 
        	printf("| %-2d ", table[i].id);
        if (columns[1]) 
        	printf("| %-20s ", table[i].name);
        if (columns[2]) 
        	printf("| %-3d ", table[i].year);
        if (columns[3]) 
        	printf("| %-6.2f |\n", table[i].rating);
    }

    printf("+----+----------------------+-----+--------+\n");
}

// To get results of the query given, i.e. parse and execute the SELECT command
void resultQuery(char *query, Row *table, int rowCount) {
    
	if (strstr(query, "SELECT * FROM table WHERE") != NULL) {
		char *condition = strstr(query, "WHERE") + 6;
		int columns[] = {1, 1, 1, 1};
		Row filter[rowCount];
		int filteredCount = 0;

		for (int i = 0; i < rowCount; i++) {
			if (strstr(condition, "Year >") != NULL) {
				int yearthreshold = atoi(condition + 6);
				if (table[i].year > yearthreshold) {
					filter[filteredCount++] = table[i];
				}	
			}
			
			else if (strstr(condition, "Year <") != NULL) {
				int yearthreshold = atoi(condition + 6);
				if (table[i].year < yearthreshold) {
					filter[filteredCount++] = table[i];
				}	
			}
			
			else if (strstr(condition, "Year =") != NULL) {
				int yearthreshold = atoi(condition + 6);
				if (table[i].year == yearthreshold) {
					filter[filteredCount++] = table[i];
				}	
			}
		}
		
	displayTable(filter, filteredCount, columns, 4);
	}
	
	else if (strstr(query, "SELECT *") != NULL) {
        // Handling SELECT * FROM table
        int columns[] = {1, 1, 1, 1};
        displayTable(table, rowCount, columns, 4);
    }

    else if (strstr(query, "SELECT") != NULL) {
        // Handle SELECT (some_subset_of_attributes) FROM table
        int columns[] = {0, 0, 0, 0};
        if (strstr(query, "ID") != NULL) 
        	columns[0] = 1;
        if (strstr(query, "Name") != NULL) 
        	columns[1] = 1;
        if (strstr(query, "Year") != NULL) 
        	columns[2] = 1;
        if (strstr(query, "Rating") != NULL) 
        	columns[3] = 1;

        displayTable(table, rowCount, columns, 4);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"SELECT command\"\n", argv[0]);
        return 1;
    }

    // Opening MovieData.csv
    FILE *movieData = fopen("MovieData.csv", "r");
    if (!movieData) {
        printf("Unable to open file!");
        return 1;
    }

    Row table[100]; // Assuming the table will have at most 100 rows
    int rowCount = 0;
    char line[256];

    while (fgets(line, sizeof(line), movieData)) {
        if (rowCount == 0) {
             // To adjust rowCount to the actual number of rows in the MovieData.csv file.
            rowCount++;
            continue;
        }
        
        sscanf(line, "%d,%49[^,],%d,%f", &table[rowCount-1].id, table[rowCount-1].name, &table[rowCount-1].year, &table[rowCount-1].rating);
        
        rowCount++;
    }

    fclose(movieData);
    rowCount--; // Adjust rowCount to the actual number of data rows

    
	// Initiate working on the query to produce Search results.
    resultQuery(argv[1], table, rowCount);

    return 0;
}
