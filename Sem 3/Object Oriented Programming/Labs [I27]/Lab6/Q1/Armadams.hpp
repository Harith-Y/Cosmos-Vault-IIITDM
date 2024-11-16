#include <iostream>

class ArmadamsPackage {
    private: int num;
    private: int lowerBound;
    private: int upperBound;

    public: ArmadamsPackage(int val) {
        num = val;
    }

    public: ~ArmadamsPackage(){
        // Destructor code goes here
    }
    public: int getNum() const { 
        return num; 
    };

    public: int reverseNumber(int);
    public: bool isArmstrongNumber(int);
    public: bool isAdamNumber(int);
    public: void generateArmstrongNumbers(int, int);
    public: void generateAdamsNumbers(int, int);

};