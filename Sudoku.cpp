#include <iostream>
#include "Sudoku.h"
#include <cstdlib>
#include <time.h>
#include <cstdio>
using namespace std;

void Sudoku::giveQuestion(){


    unsigned int seed = time(NULL);
    srand(seed);
    //vector<int> candidate ={1,2,3,4,5,6,7,8,9};
    int output[9][9];
    int candidate[9] = {1,2,3,4,5,6,7,8,9};
    int count =0;
    swaps(candidate);


//把剛剛產生的亂數填入第一個 large grid
    for(int i =0 ; i<3;i++){

        for(int k=0;k<3;k++){

         output[i][k] = candidate[count++];
         //cout << output[i][k]<<" " ;

        }
    }


    //先填第一先填左邊三個columns

    int location ;
    for(int col =0;col<3;col++){

        for(int block =1;block<3;block++){

            location = col+block;
            location =(location>2)?location-3:location;

            for(int row =0;row<3;row++){

              output[row+3*block][location] = output[row][col];

            }
        }
    }

    for(int i=0;i<3;i++){

        for(int row2 =0;row2<3;row2++){

           for(int block2=1;block2<3;block2++){
               location = row2+block2;
               location =(location>2)?location-3:location;
               location =location +(i*3);
                for(int col2 =0;col2<3;col2++){
                    output[location][col2+3*block2] = output[(i*3)+row2][col2];

                }
            }
        }

    }

//印出題目


    int grid_x;
    int grid_y;


    for(int i=0;i<74;i++){
        grid_x = rand()%9;
        grid_y = rand()%9;

        output[grid_x][grid_y] = 0;

    }



    for(int row3=0;row3<9;row3++){

        for(int col3=0;col3<9;col3++){


            cout<<output[row3][col3]<< " ";

        }
        cout << endl;
    }
}

void Sudoku::display(){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d%c",map[i][j],' ');

        printf("%c",'\n');
    }

}


void Sudoku::display(int a[9][9]){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d%c",a[i][j],' ');

        printf("%c",'\n');
    }

}


void Sudoku::swaps(int a[]){

    int num1,num2;
    int temp;
    unsigned int random  = (unsigned)time(NULL);
    srand(random);

    for(int i =0;i<10;i++){

        num1 = rand()%9;
        num2 = rand()%9;

        while(num2 == num1)
            num2 = rand()%9;

        temp = a[num1];
        a[num1] = a[num2];
        a[num2] =temp;

    }
}

void Sudoku::initialize(){

    solvedTimes=0;
    left =0;

     for(int q=0;q<9;q++ ){
            for(int e=0;e<9;e++){
               if(map[q][e]==0)
                left ++;
            }
        }

}

bool Sudoku::isCorrect(){

    int r,r2,c,c2,checks;

    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){

            if(map[row][col]!=0){

                checks = map[row][col];
                //int test[10]={0};


                    for(r=0;r<9;r++){
                        if(r==row)
                            continue;
                        if(map[r][col]==checks){

                            /*cout << "col!!" << endl;
                            display();
                            cout << "( row,col):" <<  row<<"," << col << endl;
                            cout <<"duplicate (r,c)" << r<<col<< endl;*/
                            return false;

                        }

                        //test[map[r][c]]++;
                    }



                    for(c=0;c<9;c++){

                        if(c==col)
                            continue;

                        if(map[row][c]==checks){

                            /*cout << "row!!" << endl;
                            display();
                            cout << "( row,col):" <<  row<<"," << col << endl;
                            cout <<"duplicate (r,c)" << row<<c<< endl;*/
                            return false;
                        }


                    }


                    r2 = (row/3)*3;
                    c2 = (col/3)*3;

                    for(r =r2;r<r2+3;r++){
                        for(c =c2;c<c2+3;c++){

                            if(r==row && c ==col)
                                continue;
                            if(map[r][c] ==checks){

                                /*cout << "block" << endl;

                                display();
                                cout << "( row,col):" <<  row<<"," << col << endl;
                                cout <<"duplicate (r,c)" << r<<c<< endl;*/
                                return false;
                            }

                        }

                    }
            }
        }
    }

    return true;



}



void Sudoku::readIn(){

    int input;
    int count =0;
    int count2 =0;

    while(scanf("%d",&input)==1)
        read[count++] = input;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            map[i][j] = read[count2++];

    //display();
   // cout <<endl;
   // initialize();




    //cout << "first left1 is: " << left<< endl;
   // testleft = left;



}


void Sudoku::changeNum(int a, int b){

    //要填在原本b的位置上
    //if(a==b)
       // return;
    //display();
   // cout << "a" << a<<endl;
    //cout <<  "b"  << b<< endl;
   // int row_a;
    //int col_a;

    //要填在原本a的位置上
    //int row_b;
   // int col_b;
   int a_x[9];
   int a_y[9];
   int counta=0;

   int b_x[9];
   int b_y[9];
   int countb=0;

   for(int i=0;i<9;i++){

    for(int j=0;j<9;j++){

        if(map[i][j]==a){

            a_x[counta] = i;
            a_y[counta++] =j;

        }

        if(map[i][j]==b){

            b_x[countb] = i;
            b_y[countb++] =j;

        }

    }

    for(int i=0;i<counta;i++)
       map[a_x[i]][a_y[i]] = b;

     for(int i=0;i<countb;i++)
       map[b_x[i]][b_y[i]] = a;



   }






   /*for(int brow=0;brow<3;brow++){
        for(int bcol=0;bcol<3;bcol++){
            for(int row=0;row<3;row++){
                for(int col=0;col<3;col++){

                    curr_row = row+(brow*3);
                    curr_col = col +(bcol*3);

                    if(map[curr_row][curr_col]==a){

                        row_b = curr_row;
                        col_b = curr_col;
                    }

                    if (map[curr_row][curr_col]==b){

                            row_a = curr_row;
                            col_a = curr_col;
                        }
                    }
            }

            map[row_a][col_a] = a;
            map[row_b][col_b] = b;

        }
    }*/
}



void Sudoku::changeRow(int a, int b){


    if(a==b)
        return;

    int tempRowArray[3][9];

    for(int row=0;row <3;row++)
        for(int col=0;col<9;col++)
            tempRowArray[row][col] = map[row+3*a][col];



    for(int i =0 ;i<3;i++)
        for(int j =0;j<9;j++)
            map[a*3+i][j] = map[b*3+i][j];


    for(int i =0 ;i<3;i++)
        for(int j =0;j<9;j++)
            map[b*3+i][j] = tempRowArray[i][j];

}



void Sudoku::changeCol(int a, int b){


    if(a==b)
        return;

    int tempColArray[9][3];

    for(int row=0;row < 9;row++)
        for(int col=0;col<3;col++)
            tempColArray[row][col] = map[row][3*a+col];



    for(int i =0 ;i<9;i++)
        for(int j =0;j<3;j++)
            map[i][a*3+j] = map[i][b*3+j];


    for(int i =0 ;i<9;i++)
        for(int j =0;j<3;j++)
            map[i][b*3+j] = tempColArray[i][j];



}


void Sudoku::rotate(int n){


    int copy[9][9];
    int pos_x;
    int pos_y;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            copy[i][j] = map[i][j];


     for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(n%4==0)
                   return ;

                else if (n%4==1){

                    pos_x = col;
                    pos_y = 8-row;
                }

                else if (n%4==2){

                    pos_x = 8-row;
                    pos_y = 8-col;
                }

                else{
                    pos_x = 8-col;
                    pos_y = row;
                }


                map[pos_x][pos_y] = copy[row][col];
            }
        }



}


void Sudoku::flip(int n){

    int copy[9][9];

    for(int i=0;i<9;i++){
        for(int j =0;j<9;j++){
            copy[i][j] =map[i][j];

        }
    }


    if (n ==0){

        for(int row=0;row<9;row++)
            for(int col =0;col<9;col++)
                map[row][col] = copy[8-row][col];


    }
    else if(n==1){

         for(int row=0;row<9;row++)
            for(int col =0;col<9;col++)
                map[row][col] = copy[row][8-col];


    }

}



void Sudoku::transform(){


    srand((unsigned)time(NULL));

    changeNum(rand()%9+1,rand()%9+1);
    changeRow(rand()%3,rand()%3);
    changeCol(rand()%3,rand()%3);
    rotate(rand()%101);
    flip(rand()%2);
    display();

}



bool Sudoku::checkIsFull(){

    //cout << "left is :" <<left <<  endl;
    if(left == 0)
        return 1;
    else
        return 0;


}


int Sudoku::findValue(int a[],int row, int col){

    int test[10]={0};
    int r,c;
    int r2,c2;
    int n =0;

    c=col;
    for(r=0;r<9;r++)
        test[map[r][c]]++;

    r =row;
    for(c=0;c<9;c++)
        test[map[r][c]]++;

    r2 = (row/3)*3;
    c2 = (col/3)*3;

    for(r =r2;r<r2+3;r++)
        for(c =c2;c<c2+3;c++)
            test[map[r][c]]++;

    for(int i=1;i<10;i++){
        if(test[i]==0){
            a[n] =i;
            //cout<<a[n];
            n++;
        }

    }

        return n;

    }

void Sudoku::answer(){

    int blankRow;
    int blankCol;
    int i,j;
    bool getOut;
    int possibleValues[9] ={0};
    int possibleNum;

    //紀錄值型幾次


    //check 是否成功

    if(checkIsFull()){

        //cout<<"check"<< endl;
        //cout << "checi left" << left<< endl;
        //left++;
        solvedTimes++;
        //solvedFlag =true;
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++)
                copy[i][j] = map[i][j];

        }
        //display();

        return;

    }





    //////////////////////////////////////////////////////
        //cout << "fuck"<<endl;

        getOut =false;
        for(i =0;i<9;i++){
            for( j =0 ; j<9;j ++){

                if(map[i][j]==0){

                    getOut =true;
                    break;
                }
            }
            if(getOut)
                break;
        }

        blankRow = i;
        blankCol =j;


    ///////////////////////////////////////////////////////////////////////
        possibleNum = findValue(possibleValues,blankRow,blankCol);

        if(possibleNum==0){
            map[blankRow][blankCol] =0;
            left++;
            return ;

        }


        else{

            //cout <<"Possible values:\n";

           // for(int i=0;i<9;i++)
            //    cout <<possibleValues[i]<<" ";
        }

    /////////////////////////////////////////////////////////////////////

        for(int num=0;num<possibleNum;num++){

            map[blankRow][blankCol] = possibleValues[num];
           // cout<< "map "<< map[blankRow][blankCol] <<endl ;
            left--;
            answer();

            if(solvedTimes>1)
                return;
           // if(solvedFlag == true)
           //     return;
        }

        map[blankRow][blankCol] =0;
        left++;
        return;







        }




void Sudoku::solve(){

    initialize();

    if(!isCorrect()){


    //return true;

       solvedTimes =0;

       //cout << "fuck" << endl;
    }


    else
        answer();



    if(solvedTimes==0){
            printf("%d",0);
           // cout << "0 solvedtimes" << endl;


    }



    else if(solvedTimes ==1){
            printf("%c%c",'1','\n');
            display(copy);
           //cout << "=1" << endl;
           //return 1;
          }

    else if(solvedTimes>1){
           // cout << ">1" << endl;

            printf("%c",'2');

    }
           // printf("%d",2);


}







