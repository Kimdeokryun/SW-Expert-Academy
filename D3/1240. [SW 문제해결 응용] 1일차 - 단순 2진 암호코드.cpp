/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}