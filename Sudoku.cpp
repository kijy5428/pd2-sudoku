#include "Sudoku.h"
#include <cstdlib>
#include <time.h>
#include <cstdio>
using namespace std;

void Sudoku::giveQuestion(){


    unsigned int seed = time(NULL);
    srand(seed);
    int output[9][9];
    int candidate[9] = {1,2,3,4,5,6,7,8,9};
    int count =0;
    swaps(candidate);


//把剛剛產生的亂數填入第一個 large grid
    for(int i =0 ; i<3;i++)
        for(int k=0;k<3;k++)
         output[i][k] = candidate[count++];


    //接著先填左邊三個columns

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
    //填右邊2*3的矩陣
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



    //挖洞
    int grid_x;
    int grid_y;

    //挖74個洞
    for(int i=0;i<73;i++){
        grid_x = rand()%9;
        grid_y = rand()%9;

        output[grid_x][grid_y] = 0;

    }


    //印出題目
    for(int row3=0;row3<9;row3++){
        for(int col3=0;col3<9;col3++){
            printf("%d%c",output[row3][col3],' ');
        }
        printf("%c",'\n');
    }
}

//把數獨的map輸出
void Sudoku::display(){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d%c",map[i][j],' ');

        printf("%c",'\n');
    }

}

//把數獨的map輸出
void Sudoku::display(int a[9][9]){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d%c",a[i][j],' ');

        printf("%c",'\n');
    }

}

//只是出題目時，產生亂數數列，來填第一個block
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

//解題前的初始化，把solved times 社為0，並且計算有幾個空格
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

//檢驗目前的格式是否正確
bool Sudoku::isCorrect(){

    int r,r2,c,c2,checks;

    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){

            if(map[row][col]!=0){   //找非零的數字開始檢查

                checks = map[row][col];

                    for(r=0;r<9;r++){   //找同一行是否有duplicate
                        if(r==row)
                            continue;
                        if(map[r][col]==checks){

                            return false;

                        }
                    }

                    for(c=0;c<9;c++){   //找同一列是否有duplicate
                        if(c==col)
                            continue;

                        if(map[row][c]==checks){
                            return false;
                        }


                    }

                    //找營個block裡面是否有重複
                    r2 = (row/3)*3;
                    c2 = (col/3)*3;

                    for(r =r2;r<r2+3;r++){
                        for(c =c2;c<c2+3;c++){

                            if(r==row && c ==col)
                                continue;
                            if(map[r][c] ==checks){

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



}


void Sudoku::changeNum(int a, int b){


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
            a[n++] =i;

        }

    }

        return n;

    }

//程式解題精隨所在，利用backtracking recursive
void Sudoku::answer(){

    int blankRow;//存放某次 function call裡找到的下一個空格 row
    int blankCol;//column

    int i,j;
    bool getOut;
    int possibleValues[9] ={0};
    int possibleNum;//找到的下一個空格可填入數字的可解數量

    //check 是否是滿的，也就是成功的意思

    if(left==0){

        solvedTimes++;
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++)
                copy[i][j] = map[i][j];

        }
        return;

    }

    //////////////////////////////////////////////////////

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


    /////////////////////////////////////////////////////////////////////

        for(int num=0;num<possibleNum;num++){

            map[blankRow][blankCol] = possibleValues[num];
            left--;
            answer();

            if(solvedTimes>1)
                return;

        }

        map[blankRow][blankCol] =0;
        left++;
        return;


        }




void Sudoku::solve(){

    initialize();

    //read近來的格式不正確，就將solvedtimes設為0
    if(!isCorrect())
       solvedTimes =0;

    else
        answer();

    //無解輸出0
    if(solvedTimes==0){
            printf("%d",0);

    }
    //有單一解，輸出1,整個答案
    else if(solvedTimes ==1){
            printf("%c%c",'1','\n');
            display(copy);

          }
    //多解輸出2
    else if(solvedTimes>1)
            printf("%c",'2');





}







