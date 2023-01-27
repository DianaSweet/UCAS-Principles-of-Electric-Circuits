#include <stdio.h>
#define Size 15
#define Length1 5 //判断四禁手时，取一个长度为5的数组
#define Length2 3 //判断三禁手时，取一个长度为3的数组

extern int JudgeBoard[Size][Size];
extern int color;

void Judge(int a, int b){
    if (color == 0){
        JudgeBoard[Size-b][a-65] = 1;
    }
    else if(color == 1){
        JudgeBoard[Size-b][a-65] = 2;
    }

    if (color == 0){  //只有下一手为黑子时判断是否禁手,此时color为0
        LongConnect(a, b);
    }
}

int LongConnect(int a, int b){
    int i;
    int jud1, jud2, jud3, jud4, jud5, jud6;
      
    //判断六长连(由于七长连，八长连和九长连必定会形成六长连，所以只需要判断六长连即可)
    for (i = 0; i< 6; i++){
        if ((Size-b-5+i >=0) && (Size-b+i <= Size-1)){  //判断竖排是否达成六长连，if条件为保证棋子不越界，下同
            jud1 = (JudgeBoard[Size-b-5+i][a-65] == 1);
            jud2 = (JudgeBoard[Size-b-4+i][a-65] == 1);
            jud3 = (JudgeBoard[Size-b-3+i][a-65] == 1);
            jud4 = (JudgeBoard[Size-b-2+i][a-65] == 1);
            jud5 = (JudgeBoard[Size-b-1+i][a-65] == 1);
            jud6 = (JudgeBoard[Size-b+i][a-65] == 1);

            if (jud1 && jud2 && jud3 && jud4 && jud5 && jud6){
                return 1;
                break;
            }
        }
        if ((Size-b-5+i >=0) && (Size-b+i <= Size-1) && (a-5+i >=65) && (a+i <= 79)){  //判断左上-右下是否达成六长连
            jud1 = (JudgeBoard[Size-b-5+i][a-65-5+i] == 1);
            jud2 = (JudgeBoard[Size-b-4+i][a-65-4+i] == 1);
            jud3 = (JudgeBoard[Size-b-3+i][a-65-3+i] == 1);
            jud4 = (JudgeBoard[Size-b-2+i][a-65-2+i] == 1);
            jud5 = (JudgeBoard[Size-b-1+i][a-65-1+i] == 1);
            jud6 = (JudgeBoard[Size-b+i][a-65+i] == 1);

            if (jud1 && jud2 && jud3 && jud4 && jud5 && jud6){
                return 1;
                break;
            }
        }
        if ((a-5+i >=65) && (a+i <= 79)){  //判断横排是否达成六长连
            jud1 = (JudgeBoard[Size-b][a-65-5+i] == 1);
            jud2 = (JudgeBoard[Size-b][a-65-4+i] == 1);
            jud3 = (JudgeBoard[Size-b][a-65-3+i] == 1);
            jud4 = (JudgeBoard[Size-b][a-65-2+i] == 1);
            jud5 = (JudgeBoard[Size-b][a-65-1+i] == 1);
            jud6 = (JudgeBoard[Size-b][a-65+i] == 1);

            if (jud1 && jud2 && jud3 && jud4 && jud5 && jud6){
                return 1;
                break;
            }
        }
        if ((Size-b-5+i >=0) && (Size-b+i <= Size-1) && (a-i >=65) && (a+5-i <= 79)){  //判断左下-右上是否达成六长连
            jud1 = (JudgeBoard[Size-b-5+i][a-65+5-i] == 1);
            jud2 = (JudgeBoard[Size-b-4+i][a-65+4-i] == 1);
            jud3 = (JudgeBoard[Size-b-1+i][a-65+3-i] == 1);
            jud4 = (JudgeBoard[Size-b-2+i][a-65+2-i] == 1);
            jud5 = (JudgeBoard[Size-b-1+i][a-65+1-i] == 1);
            jud6 = (JudgeBoard[Size-b+i][a-65-i] == 1);

            if (jud1 && jud2 && jud3 && jud4 && jud5 && jud6){
                return 1;
                break;
            }
        }
    }
    return 0;   
}

int FourForbidden(int a, int b){
    int JudgeRow[Length1];

    int i, j;
    int jud1, jud2, jud3, jud4,jud5;
    int num4; //记录“四”的个数

    for (i = 0; i < Length1; i++){
        if ((Size-b-4+i == 0) || (Size-b+i == 0)){  //判断竖排,若所取数组位于某边界时
            for (j = 0; j < Length1; j++){  //把相应位置的棋盘数据传入JudgeRow
                JudgeRow[j] = JudgeBoard[Size-b-4+i+j][a-65];
            }
            if (Size-b-4+i == 0){
                jud1 = (JudgeRow[0] == 0) && (JudgeRow[1] == 1) && (JudgeRow[2] == 1) && (JudgeRow[3] == 1) && (JudgeRow[4] == 1);
                jud2 = (JudgeRow[0] == 1) && (JudgeRow[1] == 0) && (JudgeRow[2] == 1) && (JudgeRow[3] == 1) && (JudgeRow[4] == 1);
                jud3 = (JudgeRow[0] == 1) && (JudgeRow[1] == 1) && (JudgeRow[2] == 0) && (JudgeRow[3] == 1) && (JudgeRow[4] == 1);
                jud4 = (JudgeRow[0] == 1) && (JudgeRow[1] == 1) && (JudgeRow[2] == 1) && (JudgeRow[3] == 0) && (JudgeRow[4] == 1);
                jud5 = (JudgeRow[0] == 1) && (JudgeRow[1] == 1) && (JudgeRow[2] == 1) && (JudgeRow[3] == 1) && (JudgeRow[4] == 0);  //这表示五种“四”的形式
                if (jud1){

                }
            }
            
        }
        if ((Size-b-4+i > 0) && (Size-b+i <= Size -1)){  //判断竖排
            for (j = 0; j < Length1; j++){  //把相应位置的棋盘数据传入JudgeRow
                JudgeRow[j] = JudgeBoard[Size-b-4+j][a-65];
            }
            
        }
        
    }
    if (num4 >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

/* void ThreeForbidden(int a, int b){
    int i, j;
    int nf;  //记录出现“三”的次数
    int jud1, jud2, jud3, jud4;  //对棋子类型的判断
    int jud;  //判断是否构成“三，三”
    for (i = 0; i <= 3; i++){
        if ((Size-b-3+i >=0) && (Size-b+i <= Size-1)){  //判断竖排是否有“三”，if条件为保证棋子不越界，下同
            jud1 = ((JudgeBoard[Size-b-3+i][a-65] == 3) || (JudgeBoard[Size-b-3+i][a-65] == 5));
            jud2 = ((JudgeBoard[Size-b-2+i][a-65] == 3) || (JudgeBoard[Size-b-2+i][a-65] == 5));
            jud3 = ((JudgeBoard[Size-b-1+i][a-65] == 3) || (JudgeBoard[Size-b-1+i][a-65] == 5));
            jud4 = ((JudgeBoard[Size-b+i][a-65] == 3) || (JudgeBoard[Size-b+i][a-65] == 5));

            jud = (jud1 && jud2 && jud3 && !jud4) || (jud1 && jud2 && !jud3 && jud4) || (jud1 && !jud2 && jud3 && jud4) || (!jud1 && jud2 && jud3 && jud4);
            if (jud){
                nf++;
            }
        }
    }
}
*/