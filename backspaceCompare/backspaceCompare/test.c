#include <stdio.h>


void backspaceCompare(char * S, char * T){
	int i = 0;
	int j = 0;
	while (S[i])
	{
		if (S[0] == '#')
		{
			if (S[1] == 0)
			{
				S[0] = 0;
				break;
			}
			j = i;
			while (S[j + 1])
			{
				S[j] = S[j + 1];
				j++;
			}
			S[j] = 0;
			j = 0;
		}
		if (S[i] == '#' && i != 0)
		{
			j = i - 1;
			while (S[j + 2])
			{
				S[j] = S[j + 2];
				j++;
			}
			S[j] = 0;
			j = 0;
			i = i - 1;
		}
		if (S[i] != '#' && S[i] != 0)
		{
			i++;
		}
	}
	i = 0;
	while (T[i])
	{
		if (T[0] == '#')
		{
			if (T[1] == 0)
			{
				T[0] = 0;
				break;
			}
			j = i;
			while (T[j + 1])
			{
				T[j] = T[j + 1];
				j++;
			}
			T[j] = 0;
			j = 0;
		}
		if (T[i] == '#' && i != 0)
		{
			j = i - 1;
			while (T[j + 2])
			{
				T[j] = T[j + 2];
				j++;
			}
			T[j] = 0;
			j = 0;
			i = i - 1;
		}
		if (T[i] != '# '&& T[i] != 0)
		{
			i++;
		}
	}
	if (strcmp(S, T) == 0)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

}

int main()
{
	char S[] = "ab##";
	char T[] = "c#d#";
	backspaceCompare(S,T);

	return 0;
}