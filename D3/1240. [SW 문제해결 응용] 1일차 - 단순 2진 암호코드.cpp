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
#include<string>
#include<vector>
#include<map>

using namespace std;

void make_code(string& code) 
{
	int count = 0;

	if (code.size() < 56)
	{
		int fill_code = 56 - code.size();
		string fill = "";
		for (int i = 0; i < 56 - code.size(); i++)
		{
			fill += "0";
		}
		code = fill + code;
	}

	for (int i = 55; i > 0; i--)
	{
		if (code[i] == '0') { count++; }
		else { break; }
	}

	string fill = "";

	for (int i = 0; i < count; i++)
	{
		fill += "0";
	}

	code = fill + code.substr(0, code.size() - count);
}



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
	
	map<string, int> code_rule;
	code_rule["3211"] = 0;
	code_rule["2221"] = 1;
	code_rule["2122"] = 2;
	code_rule["1411"] = 3;
	code_rule["1132"] = 4;
	code_rule["1231"] = 5;
	code_rule["1114"] = 6;
	code_rule["1312"] = 7;
	code_rule["1213"] = 8;
	code_rule["3112"] = 9;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		string onecode;
		vector<vector<string>> codemap(n, vector<string>(m));

		string code = "";

		bool find = false;
		int code_len = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> onecode;
			for (int j = 0; j < m; j++)
			{
				codemap[i][j] = onecode[j];

				if (codemap[i][j] == "1" && !find) {
					find = true;
				}

				if (find && code_len < 56)
				{
					code_len++;
					code += codemap[i][j];
				}
			}
			if (find) { code_len = 56; }
		}

		make_code(code);

		int count = 0, len = 0;
		char bit = '0';
		string part_code = "";
		int result = 0;
		int cal_result = 0;

		for (int i = 0; i <= 56; i++) 
		{
			if (i != 0 && i % 7 == 0) {

				part_code += (len + '0');
				int decode = code_rule[part_code];

				if ((i / 7) % 2 == 0)
				{
					cal_result += decode;
				}
				else {
					cal_result += decode*3;
				}
				result += decode;

				len = 0;
				count = 0; 
				bit = '0';
				part_code = "";

			}
			if (i < 56) 
			{
				if (code[i] != bit)
				{			
					part_code += (len + '0');
					bit = code[i];
					len = 0;
				}
				len++;
			}
		}

		if (cal_result % 10 != 0) { result = 0; }

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}