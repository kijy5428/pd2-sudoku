#include <time.h>
#include <iostream>
#include "Sudoku.h"
#include <cstdlib>

using namespace std;

int main(){
    long start ;
    Sudoku ss;
	ss.readIn();
	start = time(NULL);
	ss.solve();
	long endt = time(NULL);
	//cout << endt-start;
	return 0;





}
