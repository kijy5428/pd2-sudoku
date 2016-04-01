
#include <iostream>
#include "Sudoku.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){

    Sudoku ss;
    ss.readIn();
    for(int i=0;i<100000;i++){
        ss.transform();
        cout << i << "\n\n\n";

    }


    return 0;






}
