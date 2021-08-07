#include<iostream>
#include<cmath>

using namespace std;

class game
{
public:
				void settable();
				void setposition();
				bool check(int x1, int x2, int y1, int y2);
				bool walk();
				void test();

				int table[8][8] = {0};
				int x1;
				int y1;
				int x2;
				int y2;
};

int main()
{
				bool flag;
				game G;
				G.settable();
				while (cin >> G.x1 >> G.y1 >> G.x2 >> G.y2)
				{
								G.setposition();
								if (G.walk())
								{
												G.table[G.y1][G.x1] = 0;
												G.table[G.y2][G.x2] = 0;
												cout << "pair matched" << endl;
								}
								else
												cout << "bad pair" << endl;
								//G.test();
				}
}

void game::settable()
{
				for (int i = 1; i < 7; i++)
				{
								for (int j = 1; j < 7; j++)
								{
												cin >> table[i][j];
								}
				}
}

void game::setposition()
{
				x1++;
				x2++;
				y1++;
				y2++;
}

bool game::check(int x1, int x2, int y1, int y2)
{
				if ((abs(x2 - x1) + abs(y1 - y2) == 1)&&(table[y1][x1]==table[y2][x2]))
								return 1;
				if (x1 == x2)
				{
								int sum = 0;
								for (int i = min(y1, y2)+1; i < max(y1, y2); i++)
								{
												sum += table[i][x1];
								}
								if (sum == 0)
												return 1;
								else 
												return 0;
				}

				if (y1 == y2)
				{
								int sum = 0;
								for (int i = min(x1, x2)+1; i < max(x1, x2); i++)
								{
												sum += table[y1][i];
								}
								if (sum == 0)
												return 1;
								else
												return 0;
				}
				return 0;
}

bool game::walk()
{
				if (table[y1][x1] != table[y2][x2]||x1==x2&&y1==y2||table[y1][x1]==0)
								return 0;
				else
				{
								if (check(x1, x2, y1, y2))
												return 1;
								if (check(x1, x1, y1, y2) && check(x1, x2, y2, y2) && table[y2][x1] == 0 ||
												check(x1, x2, y1, y1) && check(x2, x2, y1, y2) && table[y1][x2] == 0)
												return 1;

								for (int i = 0; i < 8; i++)
								{
												if (table[y1][i]==0 &&
																table[y2][i]==0&&
																check(x1, i, y1, y1) &&
																check(i, i, y1, y2) &&
																check(x2, i, y2, y2))
																return 1;
								}

								for (int i = 0; i < 8; i++)
								{
												if (table[i][x1]==0 &&
																table[i][x2]==0 &&
																check(x1, x1, y1,i ) &&
																check(x1, x2, i, i) &&
																check(x2, x2, y2, i))
																return 1;
								}
				}
				return 0;
}

void game::test()
{
				for (int i = 0; i < 8; i++)
				{
								for (int j = 0; j < 8; j++)
								{
												cout << table[i][j] << " ";
								}
								cout << endl;
				}
}
