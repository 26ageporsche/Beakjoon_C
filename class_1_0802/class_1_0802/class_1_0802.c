#define _CRT_SECURE_NO_WARNINGS
#if 0
/////////////////// 1157�� �����ڵ� //////////////////////////////////
//////////////////////�������� : ��Ÿ�� ���� = �ʹ� ���� ���� //////////////////////
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

        while (arr[j] != 0) // �ѹ��� ����
        {
            if (arr[i] <= 0x5A) // i��°�� �빮���� ���
            {
                if (arr[i] == arr[j] || arr[j] == (arr[i] + 0x20)) //i��° ���ڿ� ���ų� �ҹ����ϰ��
                {
                    sum++; // ���� ���ڰ� ���� ��� +1
                }
            }
            else
            {
                if (arr[i] == arr[j] || arr[j] == (arr[i] - 0x20)) //i��° ���ڿ� ���ų� �빮���ϰ��
                {
                    sum++; // ���� ���ڰ� ���� ��� +1
                }
            }
            j++;
        }

        // �ѹ��� ���� �Ŀ� sum �� max ��

        if (sum >= max) // �ڱ⸦ ������ ������ ���ڰ� ������� 
        {
            if (sum == max && sum > 1) // �ߺ��Ǵ� Ƚ���� ���� ���ڰ� ���� ���
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
                cnt = 0; // ���� �� ū���� ���ð�� cnt �ʱ�ȭ�� ���� ��
            }
        }
        sum = 0;
        i++;
    }

    // �� ������ cnt���� 1�̻��̸� �ߺ��Ǵ°��� �����Ƿ� ? ���
    // �ƴ϶�� save ���

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




///////////////////// 1157�� /////////////////////
#include<stdio.h>
#include <string.h>
int main()
{
	char arr[1000001];

	scanf("%s", arr);
	
	int num[26] = { 0, }; // ���ĺ��� ��� �ߺ��Ǵ��� ����ϴ� �迭

	int t = strlen(arr);
	
	// �빮�� 65~90
	// �ҹ��� 97~122

	for (int i = 0; i < t; i++)
	{
		if (arr[i] > 0x5A) // �ҹ����� ��� 
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