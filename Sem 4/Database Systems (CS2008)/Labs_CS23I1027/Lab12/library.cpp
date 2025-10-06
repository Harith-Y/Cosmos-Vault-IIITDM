#include <iostream>
#include <mysql/mysql.h>

using namespace std;

// MySQL Connection Parameters
const char* HOST = "localhost";
const char* USER = "harith";
const char* PASSWORD = "harith";
const char* DATABASE = "library";

MYSQL* conn;

// Function to establish MySQL connection
bool connectToDatabase() {
    conn = mysql_init(NULL);
    if (!conn) {
        cerr << "MySQL Initialization Failed!" << endl;
        return false;
    }
    conn = mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
    if (!conn) {
        cerr << "MySQL Connection Failed: " << mysql_error(conn) << endl;
        return false;
    }
    return true;
}

// Function to execute SQL queries	
void executeQuery(const string& query) {
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query Execution Failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Query Executed Successfully!" << endl;
    }
}

// Function to create necessary tables
void createTables() {
        string createBooksTable = "CREATE TABLE IF NOT EXISTS books(book_id INT AUTO_INCREMENT PRIMARY KEY,title VARCHAR(50),author VARCHAR(50), year INT,ISBN VARCHAR(50),copies INT);";
        
        string createLendersTable = "CREATE TABLE IF NOT EXISTS lenders(lender_id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(50),email VARCHAR(50),phone_no VARCHAR(50),address TEXT);";
               
        string createTransactionsTable = "CREATE TABLE IF NOT EXISTS transactions(transaction_id INT AUTO_INCREMENT PRIMARY KEY,book_id INT,lender_id INT,issue_date DATE,return_date DATE,FOREIGN KEY (book_id) REFERENCES books(book_id),FOREIGN KEY (lender_id) REFERENCES lenders(lender_id));";
   
    executeQuery(createBooksTable);
    executeQuery(createLendersTable);
    executeQuery(createTransactionsTable);
}


void addBook() {
    string title, author, isbn;
    int year, copies;
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cout << "Enter Number of Copies: ";
    cin >> copies;
    cin.ignore();

    string query = "INSERT INTO books (title, author, year, ISBN, copies) VALUES ('"+title+"','"+author+"',"+to_string(year)+",'"+isbn+"',"+to_string(copies)+");";
    executeQuery(query);
}

void addLender() {
    string name, email, phone_no, address;
    cout << "Enter Lender Name: ";
    getline(cin, name);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Phone Number: ";
    getline(cin, phone_no);
    cout << "Enter Address: ";
    getline(cin, address);

    string query = "INSERT INTO lenders (name,email,phone_no,address) VALUES ('"+name+"','"+email+"','"+phone_no+"','"+address+"');";
    executeQuery(query);
}
void addTransaction() {
    int book_id, lender_id;
    string issue_date, return_date;
    cout << "Enter Book ID: ";
    cin >> book_id;
    cin.ignore();
    cout << "Enter Lender ID: ";
    cin >> lender_id;
    cin.ignore();
    cout << "Enter Issue Date (YYYY-MM-DD): ";
    getline(cin, issue_date);
    cout << "Enter Return Date (YYYY-MM-DD): ";
    getline(cin, return_date);

    string query = "INSERT INTO Transactions (Book_ID, Lender_ID, Issue_Date, Return_Date) VALUES (" + to_string(book_id) + ", " + to_string(lender_id) + ", '" + issue_date + "', '" + return_date + "');";
    executeQuery(query);
}

void listBooks() {
    if (mysql_query(conn, "SELECT * FROM Books")) {
        cerr << "Query Execution Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Result Storage Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "Book ID: " << row[0] << " | Title: " << row[1] << " | Author: " << row[2] << " | Year: " << row[3] << " | ISBN: " << row[4] << " | Copies: " << row[5] << endl;
    }
    mysql_free_result(result);
}

void listLenders() {
    if (mysql_query(conn, "SELECT * FROM Lenders")) {
        cerr << "Query Execution Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Result Storage Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "Lender ID: " << row[0] << " | Name: " << row[1] << " | Email: " << row[2] << " | Phone No: " << row[3] << " | Address: " << row[4] << endl;
    }
    mysql_free_result(result);
}

void listTransactions() {
    if (mysql_query(conn, "SELECT * FROM Transactions")) {
        cerr << "Query Execution Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Result Storage Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "Transaction ID: " << row[0] << " | Book ID: " << row[1] << " | Lender ID: " << row[2] << " | Issue Date: " << row[3] << " | Return Date: " << row[4] << endl;
    }
    mysql_free_result(result);
}

void deleteBook() {
    int book_id;
    cout << "Enter Book ID to delete: ";
    cin >> book_id;
    cin.ignore();

    string query = "DELETE FROM books WHERE book_id = " + to_string(book_id) + ";";
    executeQuery(query);
}

void deleteLender(){
    int lender_id;
    cout << "Enter Lender id to delete:";
    cin >> lender_id;
    cin.ignore();

    string query = "DELETE FROM lenders WHERE lender_id = "+to_string(lender_id)+";";
    executeQuery(query);
}

void deleteTransaction() {
    int transaction_id;
    cout << "Enter Transaction ID to delete: ";
    cin >> transaction_id;
    cin.ignore();

    string query = "DELETE FROM transactions WHERE transaction_id = " + to_string(transaction_id) + ";";
    executeQuery(query);
}

void updateBook() {
    int book_id;
    string title, author, isbn;
    int year, copies;
    cout << "Enter Book ID to update: ";
    cin >> book_id;
    cin.ignore();
    cout << "Enter New Title: ";
    getline(cin, title);
    cout << "Enter New Author: ";
    getline(cin, author);
    cout << "Enter New Year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter New ISBN: ";
    getline(cin, isbn);
    cout << "Enter New Number of Copies: ";
    cin >> copies;
    cin.ignore();

    string query = "UPDATE books SET title = '" + title + "', author = '" + author + "', year = " + to_string(year) + ", ISBN = '" + isbn + "', copies = " + to_string(copies) + " WHERE book_id = " + to_string(book_id) + ";";
    executeQuery(query);
}

void updateLender() {
    int lender_id;
    string name, email, phone_no, address;
    cout << "Enter Lender ID to update: ";
    cin >> lender_id;
    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, name);
    cout << "Enter New Email: ";
    getline(cin, email);
    cout << "Enter New Phone Number: ";
    getline(cin, phone_no);
    cout << "Enter New Address: ";
    getline(cin, address);

    string query = "UPDATE lenders SET name = '" + name + "', email = '" + email + "', phone_no = '" + phone_no + "', address = '" + address + "' WHERE lender_id = " + to_string(lender_id) + ";";
    executeQuery(query);
}

void updateTransaction() {
    int transaction_id, book_id, lender_id;
    string issue_date, return_date;
    cout << "Enter Transaction ID to update: ";
    cin >> transaction_id;
    cin.ignore();
    cout << "Enter New Book ID: ";
    cin >> book_id;
    cin.ignore();
    cout << "Enter New Lender ID: ";
    cin >> lender_id;
    cin.ignore();
    cout << "Enter New Issue Date (YYYY-MM-DD): ";
    getline(cin, issue_date);
    cout << "Enter New Return Date (YYYY-MM-DD): ";
    getline(cin, return_date);

    string query = "UPDATE transactions SET book_id = " + to_string(book_id) + ", lender_id = " + to_string(lender_id) + ", issue_date = '" + issue_date + "', return_date = '" + return_date + "' WHERE transaction_id = " + to_string(transaction_id) + ";";
    executeQuery(query);
}

void searchBook() {
    string title;
    cout << "Enter Book Title to search: ";
    getline(cin, title);

    string query = "SELECT * FROM books WHERE title LIKE '%" + title + "%';";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query Execution Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Result Storage Failed: " << mysql_error(conn) << endl;
        return;
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "Book ID: " << row[0] << " | Title: " << row[1] << " | Author: " << row[2] << " | Year: " << row[3] << " | ISBN: " << row[4] << " | Copies: " << row[5] << endl;
    }
    mysql_free_result(result);
}


void closeConnection() {
    mysql_close(conn);
}

int main() {
    if (!connectToDatabase()) {
        return 1;
    }

    createTables();

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Add Lender\n";
        cout << "4. List Lenders\n";
        cout << "5. Add Transaction\n";
        cout << "6. List Transactions\n";
        cout << "7. Delete Book\n";
        cout << "8. Delete Lender\n";
        cout << "9. Delete Transaction\n";
        cout << "10. Update Book\n";
        cout << "11. Update Lender\n";
        cout << "12. Update Transaction\n";
        cout << "13. Search Book\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                addLender();
                break;
            case 4:
                listLenders();
                break;
            case 5:
                addTransaction();
                break;
            case 6:
                listTransactions();
                break;
            case 7:
                deleteBook();
                break;
            case 8:
                deleteLender();
                break;
            case 9:
                deleteTransaction();
                break;
            case 10:
                updateBook();
                break;
            case 11:
                updateLender();
                break;
            case 12:
                updateTransaction();
                break;
            case 13:
                searchBook();
                break;
            case 14:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 14);

    closeConnection();
    return 0;
}
