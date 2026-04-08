#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

long long sum_of_aaa(int a, int n)
{
	long long sum = 0;
	long long current = 0;
	
	for(int i = 0;i < n; i++)
	{
		current = current * 10 + a;
		sum += current;
	}
	
	return sum;
}

int main()
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	#endif
	
	printf("连数求和\n");

	int test_case[][2] = {{6,9}};
	int test_count = sizeof(test_case) / sizeof(test_case[0]);
	
	for(int i = 0; i < test_count; i++)
	{
		int a = test_case[i][0];
		int n = test_case[i][1];
		long long result = sum_of_aaa(a,n);
		
		printf("测试%d:", i + 1);
		
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < j; k++)
			{
				printf("%d", a);
			}
			
			if(j < n)
			{
				printf(" + ");
			}
		}
		printf(" = %lld\n", result);
	}
	return 0;
}
