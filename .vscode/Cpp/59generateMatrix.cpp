/*
        坚持统一的规则，左闭右开还是闭区间
        若为左开右闭：
*/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> rec(n, vector<int>(n));

        /*
        判断循环的圈数：n / 2;
        且奇数项最内层一定会有一个空位 rec[i / 2][j / 2] = n * n;
        偶数：n - 1, n  - 1 - 2 …… 1;皆为循环4次
        奇数：同偶数但是中间位置空出
        那么可以在中间判断一下是否是奇数来确定是否填充
        循环次数和填充常量都可以用会变的n控制
        */
        int startx = 0, starty = 0; // 定义起始位置，因为其实位置是会变的，提前设置好可以简化循环
        int offset = 1;
        int count = 1;     // 用来填充的数字
        int round = n / 2; // 初始次数
        int i, j;
        while (round)
        {
            for (j = starty; j < n - offset; j++)
            {
                rec[startx][j] = count++;
            }
            for (i = startx; i < n - offset; i++)
            {
                rec[i][j] = count++;
            }
            for (; j > starty; j--)
            {
                rec[i][j] = count++;
            }
            for (; i > startx; i--)
            {
                rec[i][j] = count++;
            }
            startx++;
            starty++;
            offset += 1;
            round--;
        }
        if (n % 2 != 0)
        {
            rec[startx][starty] = count;
        }
        return rec;
    }
};