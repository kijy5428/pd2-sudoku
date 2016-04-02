

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

    int read[81];//��J�ɮרϥ�
    int map[9][9];//�ݸѪ��ƿW�ѽL
    int solvedTimes;//���\�ѹL������
    int left ;//�ٳѴX�ӪŮ�
    int copy[9][9];//�ƻsmap�ϥ�







};
