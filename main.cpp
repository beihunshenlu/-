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
    //�˴���5*5������ȡ��9��3*3����
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












    /*��������ȡ��������
      ����ĸxΪ����������ȡ������Ҫ���������������ߣ�һ���Խ��ߣ�
       1 -1 -1       1 -1  1    -1 -1  1
      -1  1 -1      -1  1 -1    -1  1 -1
      -1 -1  1       1 -1  1     1 -1 -1

    */
    //ʹ�����������������о������
    double feature_middle[9][3][3] = {0};
    double feature_map[3][3][3] = {0};
    double agency[9] = {0};

    //���µ�����ѭ���Ƿ�������ȡ��3*3����Ĳ������е�һ�����������
    //�ó��Ľ����9��3*3����feature_middle
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
    //Ȼ���feature_middle�������������9������ֵ����feature_map
    //����ֵԽ�ӽ�1��ʾfeatureƥ��Խ������
    //Խ�ӽ�-1��ʾfeature�ķ���ƥ��Խ������
    //��ֵ�ӽ�0�ı�ʾ��Ӧλ��û���κ�ƥ�����˵û��ʲô��ϵ
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
    //�������㹤��
    for(int i = 0; i < 9; i ++)
        agency[i] = 0;

    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 3; j ++)
            for(int k = 0; k < 3; k ++)
                feature_middle[i][j][k] = 0;
    //���㹤������




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













    //����Ϊ���ػ�����
    //����feature_map�Ѿ���3��3*3�ľ���
    //�������³ػ���������ʽ���Ĳ�����
    //�ṩ�ػ��Ĵ���˼·
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

    //�ػ��������






    //���½��м�����������������ReLU������������
    //���ڳػ���������ʽ�ϵĲ��������¼�������Ƕ�feature_map���м������
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
