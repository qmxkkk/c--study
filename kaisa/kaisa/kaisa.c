#define _CRT_SECURE_NO_WARNINGS

int kaisa(char arr[],int sz,int key)
{
	int i = 0;
	for (i = 0; arr[i]!='\0' || i < sz;i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			char t = arr[i] += key;
			if(t > 'Z')
				arr[i] -= 26;
			else if(t < 'A')
				arr[i] += 26;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			char t = arr[i] += key;
			if (t > 'z' || t < '\0')
				arr[i] -= 26;
			else if (t < 'a')
				arr[i] += 26;
		}
	}
}