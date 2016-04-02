

class Sudoku{

public:
    void giveQuestion();
    void readIn();
    void solve();
    void answer();
    void transform();
    void changeNum(int a, int b);
    void changeRow(int a, int b);
    void changeCol(int a, int b);
    void rotate(int n);
    void flip(int n);
    void swaps(int a[]);
    void display();
    void display(int a[9][9]);
    void initialize();
    int findValue(int array[],int row, int col);
    bool isCorrect();


private:

    int read[81];//輸入檔案使用
    int map[9][9];//待解的數獨棋盤
    int solvedTimes;//成功解過的次數
    int left ;//還剩幾個空格
    int copy[9][9];//複製map使用







};
