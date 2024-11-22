#include "Graduate.hpp"

int main() {
    Student S("Karthik", "Krishnan");
    Graduate G("Anusha", "Srinivasan", "B.E");

    cout << "Student S's details " << S << endl;
    cout << "Graduate G's details " << G << endl;

    Student* sptr = &G;
    cout << *sptr << endl;

    Graduate* gptr = &G;
    cout << *gptr << endl;

    return 0;
}
