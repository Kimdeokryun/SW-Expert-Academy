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
	
	string encoding_str;
	string decoding_str;

	vector<char> base64_table(64);

	for (int i = 0; i < 26; ++i) base64_table[i] = 'A' + i;
	for (int i = 26; i < 52; ++i) base64_table[i] = 'a' + (i - 26);
	for (int i = 52; i < 62; ++i) base64_table[i] = '0' + (i - 52);
	base64_table[62] = '+';
	base64_table[63] = '/';

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> encoding_str;
		decoding_str = "";

		int buffer_length = 0, buffer_value = 0;

		for (char c : encoding_str)
		{
			// ��Ʈ ����
			if (c >= 'A' && c <= 'Z') {
				buffer_value = (buffer_value << 6) + c - 'A';
			}
			else if (c >= 'a' && c <= 'z') { 
				buffer_value = (buffer_value << 6) + c - 'a' + 26; 
			}
			else if (c >= '0' && c <= '9') { 
				buffer_value = (buffer_value << 6) + c - '0' + 52; 
			}
			else if (c == '+') {
				buffer_value = (buffer_value << 6) + 62;
		}
			else if (c == '/') { 
				buffer_value = (buffer_value << 6) + 63; 
			}

			buffer_length += 6;

			while (buffer_length >= 8) {
				decoding_str += char(buffer_value >> (buffer_length - 8));
				buffer_length -= 8;
				//������ ������ �� �տ������� �� ����Ʈ�� ������ ����Ѵ�.
				//�� ����Ʈ�� ���� �Ŀ��� �� ��ŭ ���ۿ��� �����Ѵ�.

				//�̶� ������ ������ ��Ʈ ������ �̵��ϰų� �����ؾ� �ϹǷ� ��Ʈ ������ ����Ѵ�.
				//�� ���� �� ����Ʈ�� �������� ������ ���� ���������� ������ ������ŭ ����Ʈ�ϸ� �ȴ�. 
				//�׸��� �� ����Ʈ�� ������ ���� ���������� ���� ���� �������� ������ ������ŭ ����Ʈ�ϸ� �ȴ�.
			}
		}
		

		cout << "#" << test_case << " " << decoding_str << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}