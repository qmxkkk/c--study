#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


bool isMatch(char* s, char* p) 
{
	int i = 0, j = 0;
	int tk = 0, ti = 0, tj = 0, ans = 0;
	int log = 0, e_log1 = 0, e_log2 = 0, c_log = 0, logj = 0, xc = 0, xcc = 0, logi = 0, a_log = 0, xc_log = 0, xcd = 0;
	int c = 0, sc = 0, cc = 0, tc = 0;

	start:
	while (p[i])
	{

		if (p[i] == '.')//读取.
		{
			if (p[i + 1] == '*')//读取.后的*
			{
			restar:
				for (int k = i + 2;p[k] && p[k + 1] == '*';k += 2)
				{
					i = k;
				}
				if (!p[i + 2])
					return true;
			restart1:
				xc = 0;
				xc_log = 0;
				for (i+=2;p[i]&&p[i]!='*';i++)
				{
					xc++;
					if (p[i + 1] == '*')
					{
						xc--;
						xc_log = 1;
					}

				}
				if (xc)
				{
					c_log = 1;
				}
				i -= xc_log ? xc + 1 : xc;
			
				xcc = 0;
				for (;s[j] && s[j] != p[i + xcc];j++)
				{
					if (p[i + xcc] == '.')
						xcc++;
				}
				for (;s[j] && s[j] == p[i + xcc];j++)
				{
						xcc++;
				}
				j -= xcc;
				if (xcc < xc)
				{
					if (!s[j])
						return false;
					else
					{
						j+=xcc;
						goto restart1;
					}
						
				}
				if (!xcc && !s[j])
					return false;
				

				else if (xcc  >= xc)
				{
					if(xcc>xc)
						logj = j + 1;
					else
						logj = j + xcc;
					logi = i;
					continue;
				}

			}
			else if (p[i])
			{
				if (s[j])
				{
					i++;
					j++;
				}
				else
				{
					i++;
					a_log = 1;
					ans = 0;
				}
				

			}
		}
		if (p[i] >= 'a' && p[i] <= 'z')
		{
			if (p[i + 1] == '*')
			{
				for (int k = i + 1; p[k] == '*' && p[k + 1];k += 2)//判断后面是否有别的字符加*
				{
					tk = k + 1;
					if ( p[k + 1] == p[i] )//*后有原字母，log置1
						log = 1;
				}
				
				if (log)
				{
					for (int k = i + 2;k < tk;k += 2)//log置1后计算，*号后面有几个原字符,同时计算可以跳过多少位
					{
						j++;
						tc++;
						if (p[k] == '.')
						{
							c_log = 1;
							k += 2;
						}
						while (s[j] && p[k] != p[i] && s[j] != p[i])
						{
							if (s[j] == p[k])
								c++;
							j++;
							tc++;
						}
						while (s[j] != p[k] && s[j] && p[k] == p[i])
						{
							j++;
							tc++;
						}
						j -= tc;
						sc += c;
						c = 0;
						tc = 0;
					}

					
					j++;//计算完log后，j++进一位计算需要跳过的目标字符串的字符个数，同时计算跳过的前后符合原字符的个数
					
					e_log1 = 0;
					e_log2 = 0;
					while (s[j] == p[i] && s[j])
					{
						e_log1++;
						j++;
					}
					e_log1++;
					tj = j;
					while (s[j] != p[i] && s[j])
					{
						j++;
						cc++;
					}
					while (s[j] == p[i] && s[j])
					{
						e_log2++;
						j++;
					}
					j--;

					if ((sc + 1 >= cc || sc == 0 || c_log))//对*后面的字符计数
					{
						

						for (int k = tk;p[k] == p[i] && log;k++)
						{
								log++;
						}
						if (log)
							log--;

						if (!sc)//对*后面的字符忽略判断
						{
							if (e_log1 < log)
							{
								ans = 0;
								a_log = 1;
								break;
							}
						}
						if (c_log || sc + 1 >= cc || !sc)
						{
							if (e_log2 >= log)
								j -= log;
							else if (e_log1 >= log)
							{
								j = tj;
								j -= log;
							}

						}


						log = 0;


						
					}
					
				}
				else//*后无同字符，直接正常取到最后
				{


					while (s[j] == p[i] && s[j])
					{
						j++;
					}
				}
				
				i += 2;

				
			}
			else
			{
				if (s[j] == p[i])
				{
					j++;
					i++;
				}
				else
				{
					ans = 0;
					a_log = 1;
					break;
				}
			}
			
		}
	}
	if (!a_log)
	{
		ans = (s[j]) ? 0 : 1;

	}
	
	if (c_log)
	{
		if (!ans)
		{
			i = logi;
			j = logj;
			goto start;
		}

	}
	else
		return ans ? true : false;

}

int main() 
{	char s[21] = { "bbba" };
	char p[21] = { ".*b" };
	printf("%d", isMatch(s, p));

	return 0;
}