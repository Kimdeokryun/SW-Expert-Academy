/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/

	int result;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> sudoku(9, vector<int>(9));

		int check;
		int check2;

		result = true;

		for (int i = 0; i < 9; i++) 
		{
			check = 0;
			for (int j = 0; j < 9; j++)
			{
				cin >> sudoku[i][j];
				// ���� ���� üũ
				check += sudoku[i][j];
			}
			// 1 ~ 9 ���� �ϳ��� ������ �ʾҴٸ� ������ 45 �ʰ��� ��
			if (check > 45) { result = false; }
		}
		if (result) 
		{

			for (int j = 0; j < 9 && result; j++)
			{
				check = 0;
				// ���� üũ
				for (int i = 0; i < 9 && result; i++)
				{
					check += sudoku[i][j];
					// 3x3 üũ
					if (i % 3 == 0 && j % 3 == 0 && result) 
					{
						check2 = 0;
						for (int y = i; y <= i + 2; y++) 
						{
							for (int x = j; x <= j + 2; x++)
							{
								check2 += sudoku[y][x];
							}
						}
						// 1 ~ 9 ���� �ϳ��� ������ �ʾҴٸ� ������ 45 �ʰ��� ��
						if (check2 > 45) { result = false; }
					}
				}
				// 1 ~ 9 ���� �ϳ��� ������ �ʾҴٸ� ������ 45 �ʰ��� ��
				if (check > 45) { result = false; }
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}