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
	

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int length;
		cin >> length;

		vector<string> board(8);
		for (int i = 0; i < 8; i++) { cin >> board[i]; }

		int result = 0;
		int start, end;
		int s_start, s_end;
		bool search = false;
		int search_len = 0;

		// ���� Ž��
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				start = j; end = 8 - 1;
				search = false;

				while (start <= end)
				{
					search_len = 0;

					if (board[i][start] == board[i][end])
					{
						s_start = start; s_end = end;

						while (s_start <= s_end)
						{
							if (board[i][s_start] == board[i][s_end]) 
							{
								if (s_start == s_end) { 
									search_len += 1; 
									search = true; 
									break; 
								}
								if (s_end - s_start == 1) {
									search_len += 2; 
									search = true; 
									break; 
								}
								else { search_len += 2; }

								if (search_len > 4) { break; }

								s_start++;
								s_end--;

							}
							else { break; }
						}
					}
					if (search) {
						if (search_len == length) { result++; }
						break;
					}
					else { end--; }
				}

			}
		}

		// ���� Ž��
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				start = i; end = 8 - 1;
				search = false;

				while (start <= end)
				{
					search_len = 0;
					if (board[start][j] == board[end][j])
					{
						s_start = start; s_end = end;

						while (s_start <= s_end)
						{
							if (board[s_start][j] == board[s_end][j])
							{
								if (s_start == s_end) {
									search_len += 1;
									search = true;
									break;
								}
								if (s_end - s_start == 1) {
									search_len += 2;
									search = true;
									break;
								}
								else { search_len += 2; }

								if (search_len > 4) { break; }

								s_start++;
								s_end--;
							}
							else { break; }
						}
					}
					if (search) {
						if (search_len == length) { result++; }
						break;
					}
					else { end--; }
				}

			}
		}



		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}