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
#include<vector>
using namespace std;

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
			// 비트 연산
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
				//버퍼의 내용을 맨 앞에서부터 한 바이트씩 꺼내서 출력한다.
				//한 바이트를 꺼낸 후에는 그 만큼 버퍼에서 삭제한다.

				//이때 버퍼의 내용은 비트 단위로 이동하거나 삭제해야 하므로 비트 연산을 사용한다.
				//맨 앞의 한 바이트를 꺼내려면 버퍼의 값을 오른쪽으로 적절한 개수만큼 시프트하면 된다. 
				//그리고 한 바이트를 삭제할 때도 마찬가지로 버퍼 값을 왼쪽으로 적절한 개수만큼 시프트하면 된다.
			}
		}
		

		cout << "#" << test_case << " " << decoding_str << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}