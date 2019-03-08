#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
    double matrix[5][5] =
    {
         1, -1, -1, -1,  1,
        -1,  1, -1,  1, -1,
        -1, -1,  1, -1, -1,
        -1,  1, -1,  1, -1,
         1, -1, -1, -1,  1
    };

    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 5; j ++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    double feature_matrix[9][3][3];
    int r = 0;
    //此处做5*5矩阵中取下9个3*3矩阵
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                for(int t = 0; t < 3; t ++)
                {
                    feature_matrix[r][k][t] = matrix[i + k][j + t];
                }
            }
            r ++;
        }
    }












    /*以下是提取特征操作
      以字母x为例，可以提取三个重要特征（两个交叉线，一个对角线）
       1 -1 -1       1 -1  1    -1 -1  1
      -1  1 -1      -1  1 -1    -1  1 -1
      -1 -1  1       1 -1  1     1 -1 -1

    */
    //使用上述三个特征进行卷积操作
    double feature_middle[9][3][3] = {0};
    double feature_map[3][3][3] = {0};
    double agency[9] = {0};

    //以下的四重循环是仿造上述取下3*3矩阵的操作进行第一步卷积操作，
    //得出的结果是9个3*3矩阵feature_middle
    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                for(int t = 0; t < 3; t ++)
                {
                    feature_middle[r][k][t] = feature_matrix[0][k][t] * matrix[i + k][j + t];
                }
            }
            r ++;
        }
    }
    //然后对feature_middle矩阵加起来除以9，并将值赋给feature_map
    //其中值越接近1表示feature匹配越完整，
    //越接近-1表示feature的反面匹配越完整，
    //而值接近0的表示对应位置没有任何匹配或者说没有什么关系
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                agency[i] += feature_middle[i][j][k];
            }
        }
    }
    for(int i = 0; i < 9; i ++)
        agency[i] /= 9;
    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            feature_map[0][i][j] = agency[r];
        }
        r ++;
    }
    //进行清零工作
    for(int i = 0; i < 9; i ++)
        agency[i] = 0;

    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 3; j ++)
            for(int k = 0; k < 3; k ++)
                feature_middle[i][j][k] = 0;
    //清零工作结束




    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            feature_middle[0][i][j] = feature_matrix[0][i][j] * matrix[i][j];
        }
    }
    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                for(int t = 0; t < 3; t ++)
                {
                    feature_middle[r][k][t] = feature_matrix[2][k][t] * matrix[i + k][j + t];
                }
            }
            r ++;
        }
    }
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                agency[i] += feature_middle[i][j][k];
            }
        }
    }
    for(int i = 0; i < 9; i ++)
        agency[i] /= 9;
    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            feature_map[1][i][j] = agency[r];
        }
        r ++;
    }


    for(int i = 0; i < 9; i ++)
        agency[i] = 0;
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 3; j ++)
            for(int k = 0; k < 3; k ++)
                feature_middle[i][j][k] = 0;



    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                for(int t = 0; t < 3; t ++)
                {
                    feature_middle[r][k][t] = feature_matrix[4][k][t] * matrix[i + k][j + t];
                }
            }
            r ++;
        }
    }
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                agency[i] += feature_middle[i][j][k];
            }
        }
    }
    for(int i = 0; i < 9; i ++)
        agency[i] /= 9;
    r = 0;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            feature_map[2][i][j] = agency[r];
        }
        r ++;
    }


    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                cout << feature_map[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }













    //以下为最大池化操作
    //由于feature_map已经是3个3*3的矩阵
    //所以以下池化仅仅是形式化的操作，
    //提供池化的代码思路
    double max_pool_number[4] = {-999, -999, -999, -999};
    double max_pool[3][2][2] = {0};
    int sign = 0;
    for(int s = 0; s < 3; s ++)
    {
        sign = 0;
        r = 0;
        for(int i = 0; i < 4; i ++)
            max_pool_number[i] = -999;
        for(int i = 0; i < 2; i ++)
        {
            for(int j = 0; j < 2; j ++)
            {
                for(int k = 0; k < 2; k ++)
                {
                    for(int t = 0; t < 2; t ++)
                    {
                        if(max_pool_number[r] < feature_map[s][i+k][j+t])
                            max_pool_number[r] = feature_map[s][i+k][j+t];
                    }
                }
                r ++;
            }
        }
        for(int i = 0; i < 2; i ++)
        {
            for(int j = 0; j < 2; j ++)
            {
                max_pool[s][i][j] = max_pool_number[sign ++];
            }
        }


    }


    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 2; j ++)
        {
            for(int k = 0; k < 2; k ++)
            {
                cout << max_pool[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //池化操作完成






    //以下进行激活操作，激活函数采用ReLU线性整流函数
    //由于池化仅仅是形式上的操作，以下激活函数仍是对feature_map进行激活操作
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                if(feature_map[i][j][k] < 0)
                    feature_map[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                cout << feature_map[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
