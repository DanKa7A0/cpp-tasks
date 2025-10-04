#include "mathOps.h"
#include "globals.h"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
    cout << squareArea(5) << endl;
    cout << cubeArea(5) << endl;
    cout << circleArea(5) << endl;
    cout << rectangleArea(5, 10) << endl;
    cout << rightАngledТriangleArea(5, 10) << endl;
    cout << "Operation Count: " << OperationCount << endl;

    return 0;
}
