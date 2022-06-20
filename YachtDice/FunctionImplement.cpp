#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include"Functionheader.h"
#include"CalculatePoint.h"
using namespace std;

int* RollDice(int num)
{
	srand((unsigned int)time(NULL));

	int *dice=new int[num];
	for (int i = 0; i < num; i++)	//�ֻ��� ������
	{
		dice[i] = (rand() % 6) + 1;
	}
	for (int i = 0; i < num-1; i++)	//�ֻ��� ����
	{
		for (int j = i+1; j < num; j++)
		{
			if (dice[i] > dice[j])
			{
				int temp = dice[i];
				dice[i] = dice[j];
				dice[j] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)	//�ֻ��� ���
	{
		cout << dice[i] << " ";
	}
	cout << "\n";
	return dice;
}

vector<int> OneTurn()
{
	int DiceNum = 5;	//ó�� �ֻ��� ����
	vector<int> SaveDice;	//���� ������ �ֻ��� ��� vector
	int* GetDice=0;	//�޾ƿ� �ֻ���
	for (int i = 0; i < 3; i++)
	{
		if (SaveDice.size() == 5)	//5�� �� �����ϸ� �� ����
			break;
		int* CheckDice = new int[DiceNum];	//���� �ֻ��� �����ϴ� 1, 0 ������ �迭
		cout << i + 1 << "��° �ֻ��� ����\n"; 
		GetDice=RollDice(DiceNum);	//�ֻ��� ���� �� �޾ƿ�
		if (i != 2)	//2��°������ �ֻ��� ���� �� �ִ�.
		{
			cout<< "���� �ֻ��� ����\n";
			for (int j = 0; j < DiceNum; j++)	//���� �ֻ��� ����
			{
				cin >> CheckDice[j];
			}
			int TempDiceNum = DiceNum;
			for (int k = 0; k < TempDiceNum; k++)	//�ֻ��� �ִ� �۾�
			{
				if (CheckDice[k] == 1)
				{
					SaveDice.push_back(GetDice[k]);	//�ֻ��� �ֱ�
					DiceNum--;	//���� �ֻ��� ���� ���̱�
				}
			}
			
			cout << "\n";
			cout << "�� �ֻ��� ����\n";
			for (int h = 0; h < SaveDice.size(); h++)	//���� ��� ������ �ֻ��� �����ֱ�
			{
				cout << SaveDice[h] << " ";
			}
			cout << "\n";

			int InDiceNum= 5 - DiceNum;	//����� �ֻ��� ����
			int* OutDice = new int[InDiceNum];	//�ٽ� �� �ֻ��� 1, 0���� üũ�ϴ� �迭

			for (int j = 0; j < InDiceNum; j++)	//�� �ֻ��� ����
			{
				cin >> OutDice[j];
			}
			int Erasenum = 0;	//���� �ֻ��� ���� 
			for (int k = 0; k < InDiceNum; k++)	//�ֻ��� ���� �۾�
			{
				if (OutDice[k] == 1)
				{
					SaveDice.at(k) = 0;	
					
					//SaveDice�� �� �ֻ��� ��ġ�� 0���� �ٲ����. �׸��� �Ʒ����� ���Ϳ� 0�ΰ� �� ����.
					DiceNum++;	//���� �ֻ��� ���� �ø���
					Erasenum++;	//���� �ֻ��� ���� �ø���
				}
			}
			for (int i = 0; i < Erasenum; i++)	//�ֻ��� ����
			{
				int temp = 0;	//SaveDice���� ���� üũ ��ġ ���� ������ �ʱ�ȭ
				while (true)
				{
					vector<int> ::iterator iter = SaveDice.begin();
					iter += temp;	//üũ�ϴ� ��ġ�� iter �ű��.
					if (SaveDice[temp] == 0)	//SaveDice�� ���� üũ ��ġ�� 0�� �ִٸ� ������ �Ѵ�.
					{	
						SaveDice.erase(iter);	//���� üũ�ϴ� ��ġ�� iter �������� �� ��ġ�� SaveDice vector���� ����.
						break;
					}
					else
						temp++;	//SaveDice�� ���� ��ġ Ȯ���Ϸ��� ++
				}
			}
			cout << "\n";
		}
		else	//3��°������ ���� �ֻ��� �ٷ� ����.
		{
			for (int i = 0; i < DiceNum; i++)
			{
				SaveDice.push_back(GetDice[i]);
			}
		}
		/*if (i == 2)
		{
			for (int i = 0; i < DiceNum; i++)
			{
			SaveDice.push_back(GetDice[i]);
			}
		}*/
	}
	//if (SaveDice.size() == 5)	//�ֻ��� 5�� 
	//{
	//	return SaveDice;
	//}
	//else
	//{
	//	for (int i = 0; i < DiceNum; i++)
	//	{
	//		SaveDice.push_back(GetDice[i]);
	//	}
	//	return SaveDice;
	//}
	sort(SaveDice.begin(), SaveDice.end());	//vector sort
	return SaveDice;
}

void CalPoint(vector <int> SaveDice,int * Point)
{
	//�迭 �޾ƿͼ� �迭�� ����� ���� ����
	//int Point[13];
	Point[0] = One(SaveDice);
	Point[1] = Two(SaveDice);
	Point[2] = Three(SaveDice);
	Point[3] = Four(SaveDice);
	Point[4] = Five(SaveDice);
	Point[5] = Six(SaveDice);
	//Point[6] = 0;
	Point[6] = Choice(SaveDice);
	Point[7] = FourofKind(SaveDice);
	Point[8] = FullHouse(SaveDice);
	Point[9] = LargeS(SaveDice);
	Point[10] = SmallS(SaveDice);
	Point[11] = Yacht(SaveDice);
	//Point[13] = 0;
	//int BounusPoint = 0;
	//for (int i = 0; i < 6; i++)
	//{
	//	BounusPoint += Point[i];
	//}
	//if (BounusPoint >= 63)
	//	Point[6] = 35;
	//else
	//	Point[6] = 0;
	//int SumPoint = 0;
	//for (int i = 0; i < 13; i++)
	//{
	//	SumPoint += Point[i];
	//}
	//Point[13] = SumPoint;

	//���� ǥ��
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	cout << "���� ����\n";
	cout << "\tone\ttwo\tthree\tfour\tfive\tsix\tchoice\t4ofkind\tfullH\tLargeS\tSmallS\tyacht\t\n";
	cout << "����\t";
	for (int i = 0; i < 12; i++)
	{
		cout << Point[i] << " \t";
	}
	cout << "\n";
	//������ ���� ����
	cout << "��ȣ\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t\n";
	cout << "-------------------------------------------------------------------------------------------------------------\n";
}

void ShowPoint(int* arr1, int* arr2)
{
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	cout << "����ǥ\n";
	cout << "1P\n";
	cout << "one\ttwo\tthree\tfour\tfive\tsix\tbonus\tchoice\t4ofkind\tfullH\tLargeS\tSmallS\tyacht\ttotal\t\n";
	for (int i = 0; i < 14; i++)
	{
		if (arr1[i] != -1)
			cout << arr1[i] << " \t";
		else
			cout << "\t";
	}
	cout << "\n\n";

	cout << "2P\n";
	cout << "one\ttwo\tthree\tfour\tfive\tsix\tbonus\tchoice\t4ofkind\tfullH\tLargeS\tSmallS\tyacht\ttotal\t\n";
	for (int i = 0; i < 14; i++)
	{
		if (arr2[i] != -1)
			cout << arr2[i] << " \t";
		else
			cout << "\t";
	}
	cout << "\n";
	cout << "-------------------------------------------------------------------------------------------------------------\n";
}

void menu()
{
	Player player1;
	Player player2;
	//1p, 2p
	for (int i = 0; i < 14; i++)
	{
		player1.Point[i] = -1;
		player2.Point[i] = -1;
	}
	player1.Point[13] = 0;
	player2.Point[13] = 0;
	//player���� ����ǥ �ʱ�ȭ

	for (int i = 0; i < 24; i++)	//24���ϸ� ���� ����
	{
		if (i % 2 == 0)
			cout << "1P\n";
		else
			cout << "2P\n";
		vector<int> check = OneTurn();	//1�� ����
		Sleep(2000);
		system("cls");
		if (i % 2 == 0)
			cout << "1P\n";
		else
			cout << "2P\n";
		cout << "���� ���� �ֻ���\n";
		for (int i = 0; i < 5; i++)
		{
			cout << check[i] << " ";	//���õ� �ֻ��� 5�� ǥ��
		}
		cout << "\n\n";

		//1p, 2p ����ǥ ǥ��
		ShowPoint(player1.Point, player2.Point);

		int Point[12];	//���� ������ ������ �޾ƿ��� �迭
		CalPoint(check,Point);	//���� ����ؼ� �޾ƿ���
		int PickedNum;	//������ ���� ��ȣ
		
		if (i % 2 == 0)	//1p�� ���
		{
			while (true)
			{
				cout << "������ ���� ��ȣ�� �Է��ϼ��� :" ;
				cin >> PickedNum;	//������ ���� ��ȣ �Է�
				if (PickedNum > 6)	//choice���ʹ� �տ� bonus�� ���� -1 ���ص� �ȴ�.
				{
					if (player1.Point[PickedNum ] == -1)	//-1�� ��� ���� ������ ������ ���̴�.
					{
						player1.Point[PickedNum] = Point[PickedNum - 1];	//�� ����ǥ�� ���� ����
						break;
					}
					else
						cout << "�̹� ����� �����Դϴ�. �ٽ� �Է��ϼ���\n";
				}
				else	//1~6������ -1�� �ؼ� �迭�� �־�� �Ѵ�.
				{
					if (player1.Point[PickedNum - 1] == -1)	//���� ����
					{
						player1.Point[PickedNum - 1] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "�̹� ����� �����Դϴ�. �ٽ� �Է��ϼ���\n";
				}
			}
		}
		else	//2p ���� ����
		{
			while (true)
			{
				cout << "������ ���� ��ȣ�� �Է��ϼ��� :";
				cin >> PickedNum;
				if (PickedNum > 6)
				{
					if (player2.Point[PickedNum] == -1)
					{
						player2.Point[PickedNum] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "�̹� ����� �����Դϴ�. �ٽ� �Է��ϼ���\n";
				}
				else
				{
					if (player2.Point[PickedNum - 1] == -1)
					{
						player2.Point[PickedNum - 1] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "�̹� ����� �����Դϴ�. �ٽ� �Է��ϼ���\n";
				}
			}
		}
		system("cls");
		player1.Point[13] = 0;
		player2.Point[13] = 0;
		// total��� ��� ������ ��� �ʱ�ȭ ����� �Ѵ�.
		for (int i = 0; i < 13; i++)
		{
			//-1�� �ƴ� �͵��� �����̱� ������ total�� �����Ѵ�. 
			if (player1.Point[i] != -1)
			{
				player1.Point[13] += player1.Point[i];
			}
			if (player2.Point[i] != -1)
			{
				player2.Point[13] += player2.Point[i];
			}
		}
		//1p, 2p ���ʽ� ���� ���
		int Bonus1 = 0, Bonus2 = 0;	//1~6 ���� ���� ����
		if (player1.Point[6] == -1)
		{
			for (int i = 0; i < 6; i++)
			{
				Bonus1 += player1.Point[i];
			}
			if (Bonus1 >= 63)
				player1.Point[6] = 35;
		}
		if (player2.Point[6] == -1)
		{
			for (int i = 0; i < 6; i++)
			{
				Bonus2 += player2.Point[i];
			}
			if (Bonus2 >= 63)
				player2.Point[6] = 35;
		}
		//1p, 2p ����ǥ ǥ��
		ShowPoint(player1.Point, player2.Point);
	}

	system("cls");
	ShowPoint(player1.Point, player2.Point);
	if (player1.Point[13] > player2.Point[13])
		cout << "1P�¸�!" << endl;
	else
		cout << "2P�¸�!" << endl;
}
