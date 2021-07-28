#define _CRT_SECURE_NO_WARNINGS
//////////// 1001번 ////////////
#if 0
#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", a + b);
}
#endif

#if 0
#include<stdio.h>
//////////// 1002번 ////////////
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", a - b);
}
#endif

#if 0
#include<stdio.h>
//////////// 1008번 ////////////
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%.9lf", (double)a/(double)b);
	return 0;
}
#endif


#if 0
//////////// 1152번 ////////////
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[1000001];
	gets(arr);
	int i = 0;
	int sum = 0;
	while (arr[i]!=0)
	{
		if (arr[i] != ' ')
		{
			while (arr[i] != ' ')
			{
				if (arr[i] == 0)
				{
					break;
				}
				i++;
			}
			sum++;
		}
		else
		{
			i++;
		}
	}
	printf("%d", sum);
}
#endif
#include<stdio.h>
void main()
{
	char arr[1000001];
	scanf("%s", arr);

	int sum = 0;
	int max = 0;
	int max_num;
	int i = 0, j = 0;
	int cnt = 0;
	while (arr[i]!=0)
	{
		j = 0;
		while (arr[j] != 0)
		{
			if (arr[i] == arr[j] || arr[i] == arr[j]+32|| arr[i] == arr[j] -32) sum++;
			j++;
		}
		if (sum > max)
		{
			max_num = i;
			max = sum;
			cnt = 0;
		}
		else if (sum == max && sum>1)
		{
			cnt++;
		}
		sum = 0;
		i++;
	}

	if (cnt != 0)
	{
		printf("?");
		return 0;
	}
	if (arr[max_num] <= 0x5A)
	{
		printf("%c", arr[max_num]);
	}
	else
	{
		printf("%c", (arr[max_num] - 32));
	}
}