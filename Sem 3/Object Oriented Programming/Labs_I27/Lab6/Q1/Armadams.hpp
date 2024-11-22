#include <iostream>

using namespace std;

class ArmadamsPackage {
    private: 
        int num;
        int lowerBound;
        int upperBound;

    public:
        ArmadamsPackage(int num) : num(num) {}
        ~ArmadamsPackage() { cout << "Destructor called" << endl; }
    
        int getNum() const { return num; };

        int reverseNumber(int);
        bool isArmstrongNumber(int);
        bool isAdamNumber(int);
        void generateArmstrongNumbers(int, int);
        void generateAdamsNumbers(int, int);
};
