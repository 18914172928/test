/*
*每次输入一个无符号的整数，作为随机数的种子，每轮投两次骰子，
第一轮如果和位7或者11则为胜，游戏结束，和为2，3，12则为负，
游戏结束，和为其他值就将此值作为自己的点数，继续第三第四轮......

rand函数  函数原型：int rand(void)
          所需头文件：<cstdlib>
          功能和返回值：求出并返回一个伪随机数
srand函数 函数原型：void srand(unsigned int seed)
          函数参数：seed产生随机数的种子
          头文件：cstdlib
          功能：为使得rand（）产生一序列伪随机数整数二设置起始点。使用1作为seed参数可以重新初始化rand()
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//rolly函数模拟投骰子的过程，并且输出两次骰子数以及总数，返回总点数
int rolly(){
    int a1 = 1 + rand() % 6;
    int a2 = 1 + rand() % 6;
    int sum = a1 + a2;
    cout << a1 << "+" << a2 << "=" << sum<<endl;
    return sum;
}
enum GameStatus{WIN,LOSE,PLAYING};
int main() {
    int sum, mypoint;
    unsigned seed;
    GameStatus status;
    cout << "请输入种子数";
    cin >> seed;
    srand(seed);
    sum=rolly();
    switch (sum)
    {
    case 7:
    case 11: 
        status = WIN; break;
    case 2:
    case 3:
    case 12:
        status = LOSE; break;
    default:
        mypoint = sum;
        status = PLAYING;
        break;
    }
    while (status == PLAYING) {
        sum = rolly();
        if (sum == mypoint)
            status = WIN;
        else if (sum == 7)
            status = LOSE;
    }
    if (status == WIN) {
        cout << "player wins";
    }
    else
        cout << "player loses";
}
