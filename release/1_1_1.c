#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int arr[10] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    srand((unsigned int)time(NULL));
    arr[0] = rand() % 100 + 1;// 初始化第一个数
    printf("array = ");
    printf("%d ",arr[0]);
    int sum = arr[0];

    
    int i, j;
    for (i = 1; i< len; ++i) // 遍历数组
    {
        while(1){
            int num = rand() % 100 + 1;
            for(j = 0; j < i; j++){
                if(num == arr[j]){ // 只要有一个不相同就说明不合格，开启下一次循环
                    break;
                }
            }
            if(j == i){// 都不相同
                arr[i] = num;
                sum += num;
                break;
            }
        }
        printf("%d ", arr[i]);
    }
    printf("\nsum = %d\n",sum);

    // 求均值
    double average = 1.0 * sum / len;// 或者(double)sum / len,这里利用了隐形类型转换（double类型（1.0）参与运算）
    printf("avertage = %lf\n", average);

    int a = 0;
    for (int i = 0;i < len;i++)
    {
        if (arr[i] < average)
        {
            a++;
        }
    }
    printf("%d\n", a);
    return 0;
}