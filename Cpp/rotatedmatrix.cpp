#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        在顺时针循环的过程中
        用数组 record 记录该位置是否已经被收录
        若已经被收入，或者到达数组的边界，就向右侧转向
        路径长度等于所有元素就结束
        */
       // 判断是否为空,横竖都要判断！
       if(matrix.size() == 0 || matrix[0].size() == 0){
        return {};
       }
       // 获得行列数构成记录
       int rows = matrix.size(), cols = matrix[0].size();
       // bool 类型记录,注意要分配空间
       vector<vector<bool>> record(rows,vector<bool>(cols));
       int total = rows * cols;
       vector<int> order(total);
       
    }
};

int main(){
    // 定义二维数组模拟矩阵
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    // 创建一个 Solution类 的实例 solution
    Solution solution;
    // 调用 solution实例 的 spiralOrder方法 传入定义好的矩阵 matrix
    vextor<int> result = solution.spiralOrder(matrix);
    // 使用循环遍历result数组，打印
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}