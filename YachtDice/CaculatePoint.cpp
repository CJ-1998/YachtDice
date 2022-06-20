#include<vector>
using namespace std;

int One(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 1)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Two(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 2)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Three(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 3)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Four(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 4)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Five(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 5)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Six(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SaveDice[i] == 6)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int Choice(vector<int>SaveDice)
{
	int point = 0;
	for (int i = 0; i < 5; i++)
	{
		point += SaveDice[i];
	}
	return point;
}
int FourofKind(vector<int>SaveDice)
{
	int point = 0;
	int temp1 = SaveDice[0], temp2 = SaveDice[4];
	if (SaveDice[1] == temp1 && SaveDice[2] == temp1 && SaveDice[3] == temp1|| SaveDice[1] == temp2 && SaveDice[2] == temp2 && SaveDice[3] == temp2)
	{
		for (int i = 0; i < 5;i++)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int FullHouse(vector<int>SaveDice)
{
	int point = 0;
	if (SaveDice[0] == SaveDice[1] && SaveDice[2] == SaveDice[3] && SaveDice[2] == SaveDice[4] || SaveDice[3] == SaveDice[4] && SaveDice[0] == SaveDice[1] && SaveDice[0] == SaveDice[2])
	{
		for (int i = 0; i < 5; i++)
		{
			point += SaveDice[i];
		}
	}
	return point;
}
int LargeS(vector<int>SaveDice)
{
	int point = 0;
	if (SaveDice[0] == 1 && SaveDice[1] == 2 && SaveDice[2] == 3 && SaveDice[3] == 4 && SaveDice[4] == 5|| SaveDice[0] == 2 && SaveDice[1] == 3 && SaveDice[2] == 4 && SaveDice[3] == 5 && SaveDice[4] == 6)
		point = 30;
	return point;
}
int SmallS(vector<int>SaveDice)
{
	int point = 0;
	int a = 0, b = 0, c = 0;
	if (SaveDice[0] < 4)
	{
		if (SaveDice[0] == 1)
		{
			for (int i = 1; i < 5; i++)
			{
				if (SaveDice[i] == 2)
					a = 1;
				if (SaveDice[i] == 3)
					b = 1;
				if (SaveDice[i] == 4)
					c = 1;
			}
		}
		if (SaveDice[0] == 2)
		{
			for (int i = 1; i < 5; i++)
			{
				if (SaveDice[i] == 3)
					a = 1;
				if (SaveDice[i] == 4)
					b = 1;
				if (SaveDice[i] == 5)
					c = 1;
			}
		}
		if (SaveDice[0] == 3)
		{
			for (int i = 1; i < 5; i++)
			{
				if (SaveDice[i] == 4)
					a = 1;
				if (SaveDice[i] == 5)
					b = 1;
				if (SaveDice[i] == 6)
					c = 1;
			}
		}
		int sum = a + b + c;
		if (sum == 3)
			point = 15;
	}
	return point;
}
int Yacht(vector<int>SaveDice)
{
	int point = 0;
	int temp = 0;
	int TF = 1;
	temp = SaveDice[0];
	for (int i = 1; i < 5; i++)
	{
		if (SaveDice[i] != temp)
		{
			TF = 0;
		}
	}
	if (TF == 1)
		point = 50;
	return point;
}