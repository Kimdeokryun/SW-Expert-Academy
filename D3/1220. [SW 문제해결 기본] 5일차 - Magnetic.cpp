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
#include<stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
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
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int len;
		cin >> len;

		vector<vector<int>> table(len, vector<int>(len));
		int result = 0;


		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				cin >> table[i][j];
			}
		}

		for (int j = 0; j < len; j++)
		{
			stack<int> N;
			stack<int> S;
			for (int i = 0; i < len; i++)
			{
				// 2�� S�� �ڼ�ü
				if (table[i][j] == 2) {
					if (N.empty()) {
						table[i][j] = 0;
					}
					else {
						S.push(i);
						continue;
					}
				}
				else if (table[i][j] == 1)
				{
					N.push(i);
				}

			}

			while (S.empty() && !N.empty())
			{
				table[N.top()][j] = 0;
				N.pop();
			}

			while (!N.empty() && !S.empty() && S.top() < N.top())
			{
				table[N.top()][j] = 0;
				N.pop();
			}

		}

		bool trans = false;

		for (int j = 0; j < len; j++)
		{
			trans = false;
			for (int i = 0; i < len; i++)
			{
				if (table[i][j] != 0) 
				{
					if (table[i][j] == 1 && trans)
					{
						trans = false;
						result++;
					}
					else if(table[i][j] == 2) {
						trans = true;
					}
				}
			}
			if (trans) { result++; }
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}