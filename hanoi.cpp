#include<iostream>
using namespace std;
//从起始位置start，移动到dest；
void move(char start, char dest) {
	cout << start << "->" << dest << endl;
}
//汉诺塔问题，输入n个元素，把start位置的数据借助medium移动到dest上；
void hanoi(int n, char start, char medium,char dest) {
	if (n == 1)
		move(start, dest);
	else {
		hanoi(n - 1, start, dest, medium);
		move(start, dest);
		hanoi(n - 1, medium, start, dest);

	}
}
int main() {
	int m;
	cout << "请输入：";
	cin >> m;
	hanoi(m, 'A', 'B', 'C');
}
