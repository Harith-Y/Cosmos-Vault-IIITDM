#include <iostream>
#include <mysql/mysql.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "harith";
const char* PASSWORD = "harith";
const char* DATABASE = "movies";

MYSQL* conn;

bool connectToDatabase() {
	conn = mysql_init(NULL);
	if (!conn)
		return false;
	conn = mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
	
	if (!conn)
		return false;
	return true;
}

void executeQuery(const string& query) {
	if (mysql_query(conn, query.c_str()))
		cout << "Query Error" << endl;
	else
		cout << "Query Success" << endl;
}

void createTables() {
	string createMoviesTable = "CREATE TABLE IF NOT EXISTS movies(movie_id INT AUTO_INCREMENT PRIMARY KEY,title VARCHAR(50),director VARCHAR(50), year INT);";
	
	executeQuery(createMoviesTable);
}

void addMovie() {
	
	string title;
	cout << "Enter title : ";
	getline(cin, title);
	
	string director;
	cout << "Enter director : ";
	getline(cin, director);
	
	int year;
	cout << "Enter Year of release : ";
	cin >> year;
	
	string query = "INSERT INTO movies (title, director, year) VALUES ('" + title + "', '" + director + "', " + to_string(year) + ");";
	
	executeQuery(query);
}

void displayResults() {
	string query = "SELECT * FROM movies;";
	executeQuery(query);
	
	MYSQL_RES* result = mysql_store_result(conn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result)) {
		cout << "Movie ID: " << row[0] << " | Title: " << row[1] << " | Director: " << row[2] << " | Year: " << row[3] << endl;
	}
	
	mysql_free_result(result);
}

void closeConnection() {
	if (conn)
		mysql_close(conn);
} 

int main() {
	if (!connectToDatabase())
		return 1;
		
	createTables();
	if (0)
		addMovie();		
	else
		displayResults();

	closeConnection();
	return 0;
}

