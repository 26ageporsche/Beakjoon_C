#define _CRT_SECURE_NO_WARNINGS
#if 0
/////////////////// 1157번 오답코드 //////////////////////////////////
//////////////////////오답이유 : 런타임 에러 = 너무 많이 돌음 //////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
int main()
{
    char arr[1000001];

    scanf("%s", arr);
    int i = 0;
    int sum = 0;
    int max = 1;
    int save = 0;
    int cnt = 0;
    int j = 0;
    while (arr[i] != 0)
    {
        j = 0;

        while (arr[j] != 0) // 한바퀴 돌림
        {
            if (arr[i] <= 0x5A) // i번째가 대문자일 경우
            {
                if (arr[i] == arr[j] || arr[j] == (arr[i] + 0x20)) //i번째 문자와 같거나 소문자일경우
                {
                    sum++; // 같은 문자가 있을 경우 +1
                }
            }
            else
            {
                if (arr[i] == arr[j] || arr[j] == (arr[i] - 0x20)) //i번째 문자와 같거나 대문자일경우
                {
                    sum++; // 같은 문자가 있을 경우 +1
                }
            }
            j++;
        }

        // 한바퀴 끝난 후에 sum 과 max 비교

        if (sum >= max) // 자기를 제외한 나머지 문자가 있을경우 
        {
            if (sum == max && sum > 1) // 중복되는 횟수가 같은 문자가 있을 경우
            {
                if (arr[i] <= 0x5A)
                {
                    if (arr[i] != save && (arr[i] + 0x20) != save)
                    {
                        cnt++;
                    }
                }
                else
                {
                    if (arr[i] != save && (arr[i] - 0x20) != save)
                    {
                        cnt++;
                    }
                }
            }
            else
            {
                max = sum;
                save = arr[i];
                cnt = 0; // 만약 더 큰수가 나올경우 cnt 초기화를 시켜 줌
            }
        }
        sum = 0;
        i++;
    }

    // 다 끝나고 cnt값이 1이상이면 중복되는것이 있으므로 ? 출력
    // 아니라면 save 출력

    if (cnt >= 1)
    {
        printf("?");
    }
    else
    {
        if (save <= 0x5A)
        {
            printf("%c", save);
        }
        else
        {
            printf("%c", (save - 0x20));
        }
    }
    return 0;
}
#endif




///////////////////// 1157번 /////////////////////
#include<stdio.h>
#include <string.h>
int main()
{
	char arr[1000001];

	scanf("%s", arr);
	
	int num[26] = { 0, }; // 알파벳이 몇번 중복되는지 기록하는 배열

	int t = strlen(arr);
	
	// 대문자 65~90
	// 소문자 97~122

	for (int i = 0; i < t; i++)
	{
		if (arr[i] > 0x5A) // 소문자일 경우 
		{
			num[arr[i] - 97]++;
		}
		else
		{
			num[arr[i] - 65]++;
		}
	}

	int max = 0;
	int save;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			save = i;
			cnt = 0;
		}
		else if (num[i] == max)
		{
			cnt++;
		}
	}
	
	if (cnt != 0)
	{
		printf("?");
	}
	else
	{
		printf("%c", save+65);
	}
	return 0;
}