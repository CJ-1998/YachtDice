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
	for (int i = 0; i < num; i++)	//주사위 굴리기
	{
		dice[i] = (rand() % 6) + 1;
	}
	for (int i = 0; i < num-1; i++)	//주사위 정렬
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
	for (int i = 0; i < num; i++)	//주사위 출력
	{
		cout << dice[i] << " ";
	}
	cout << "\n";
	return dice;
}

vector<int> OneTurn()
{
	int DiceNum = 5;	//처음 주사위 개수
	vector<int> SaveDice;	//내가 저장한 주사위 담는 vector
	int* GetDice=0;	//받아올 주사위
	for (int i = 0; i < 3; i++)
	{
		if (SaveDice.size() == 5)	//5개 다 저장하면 턴 종료
			break;
		int* CheckDice = new int[DiceNum];	//넣을 주사위 선택하는 1, 0 저장할 배열
		cout << i + 1 << "번째 주사위 던짐\n"; 
		GetDice=RollDice(DiceNum);	//주사위 굴린 것 받아옴
		if (i != 2)	//2번째까지는 주사위 넣을 수 있다.
		{
			cout<< "넣을 주사위 선택\n";
			for (int j = 0; j < DiceNum; j++)	//넣을 주사위 선택
			{
				cin >> CheckDice[j];
			}
			int TempDiceNum = DiceNum;
			for (int k = 0; k < TempDiceNum; k++)	//주사위 넣는 작업
			{
				if (CheckDice[k] == 1)
				{
					SaveDice.push_back(GetDice[k]);	//주사위 넣기
					DiceNum--;	//현재 주사위 개수 줄이기
				}
			}
			
			cout << "\n";
			cout << "뺄 주사위 선택\n";
			for (int h = 0; h < SaveDice.size(); h++)	//내가 골라서 저장한 주사위 보여주기
			{
				cout << SaveDice[h] << " ";
			}
			cout << "\n";

			int InDiceNum= 5 - DiceNum;	//저장된 주사위 개수
			int* OutDice = new int[InDiceNum];	//다시 뺄 주사위 1, 0으로 체크하는 배열

			for (int j = 0; j < InDiceNum; j++)	//뺄 주사위 선택
			{
				cin >> OutDice[j];
			}
			int Erasenum = 0;	//빼는 주사위 개수 
			for (int k = 0; k < InDiceNum; k++)	//주사위 빼는 작업
			{
				if (OutDice[k] == 1)
				{
					SaveDice.at(k) = 0;	
					
					//SaveDice에 뺄 주사위 위치를 0으로 바꿔놓음. 그리고 아래에서 벡터에 0인것 다 뺀다.
					DiceNum++;	//현재 주사위 개수 늘리기
					Erasenum++;	//빼는 주사위 개수 늘리기
				}
			}
			for (int i = 0; i < Erasenum; i++)	//주사위 빼기
			{
				int temp = 0;	//SaveDice에서 현재 체크 위치 가장 앞으로 초기화
				while (true)
				{
					vector<int> ::iterator iter = SaveDice.begin();
					iter += temp;	//체크하는 위치로 iter 옮기기.
					if (SaveDice[temp] == 0)	//SaveDice에 현재 체크 위치에 0이 있다면 지워야 한다.
					{	
						SaveDice.erase(iter);	//현재 체크하는 위치에 iter 가있으니 그 위치를 SaveDice vector에서 삭제.
						break;
					}
					else
						temp++;	//SaveDice의 다음 위치 확인하려고 ++
				}
			}
			cout << "\n";
		}
		else	//3번째에서는 나온 주사위 바로 들어간다.
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
	//if (SaveDice.size() == 5)	//주사위 5개 
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
	//배열 받아와서 배열에 계산한 점수 저장
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

	//점수 표시
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	cout << "나온 점수\n";
	cout << "\tone\ttwo\tthree\tfour\tfive\tsix\tchoice\t4ofkind\tfullH\tLargeS\tSmallS\tyacht\t\n";
	cout << "점수\t";
	for (int i = 0; i < 12; i++)
	{
		cout << Point[i] << " \t";
	}
	cout << "\n";
	//저장할 점수 선택
	cout << "번호\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t\n";
	cout << "-------------------------------------------------------------------------------------------------------------\n";
}

void ShowPoint(int* arr1, int* arr2)
{
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	cout << "점수표\n";
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
	//player들의 점수표 초기화

	for (int i = 0; i < 24; i++)	//24턴하면 게임 종료
	{
		if (i % 2 == 0)
			cout << "1P\n";
		else
			cout << "2P\n";
		vector<int> check = OneTurn();	//1턴 진행
		Sleep(2000);
		system("cls");
		if (i % 2 == 0)
			cout << "1P\n";
		else
			cout << "2P\n";
		cout << "최종 선택 주사위\n";
		for (int i = 0; i < 5; i++)
		{
			cout << check[i] << " ";	//선택된 주사위 5개 표시
		}
		cout << "\n\n";

		//1p, 2p 점수표 표시
		ShowPoint(player1.Point, player2.Point);

		int Point[12];	//선택 가능한 점수들 받아오는 배열
		CalPoint(check,Point);	//점수 계산해서 받아오기
		int PickedNum;	//선택한 점수 번호
		
		if (i % 2 == 0)	//1p인 경우
		{
			while (true)
			{
				cout << "선택할 점수 번호를 입력하세요 :" ;
				cin >> PickedNum;	//선택한 점수 번호 입력
				if (PickedNum > 6)	//choice부터는 앞에 bonus가 껴서 -1 안해도 된다.
				{
					if (player1.Point[PickedNum ] == -1)	//-1인 경우 점수 저장이 가능한 곳이다.
					{
						player1.Point[PickedNum] = Point[PickedNum - 1];	//내 점수표에 점수 저장
						break;
					}
					else
						cout << "이미 저장된 점수입니다. 다시 입력하세요\n";
				}
				else	//1~6까지는 -1을 해서 배열에 넣어야 한다.
				{
					if (player1.Point[PickedNum - 1] == -1)	//위와 동일
					{
						player1.Point[PickedNum - 1] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "이미 저장된 점수입니다. 다시 입력하세요\n";
				}
			}
		}
		else	//2p 점수 저장
		{
			while (true)
			{
				cout << "선택할 점수 번호를 입력하세요 :";
				cin >> PickedNum;
				if (PickedNum > 6)
				{
					if (player2.Point[PickedNum] == -1)
					{
						player2.Point[PickedNum] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "이미 저장된 점수입니다. 다시 입력하세요\n";
				}
				else
				{
					if (player2.Point[PickedNum - 1] == -1)
					{
						player2.Point[PickedNum - 1] = Point[PickedNum - 1];
						break;
					}
					else
						cout << "이미 저장된 점수입니다. 다시 입력하세요\n";
				}
			}
		}
		system("cls");
		player1.Point[13] = 0;
		player2.Point[13] = 0;
		// total계산 방식 때문에 계속 초기화 해줘야 한다.
		for (int i = 0; i < 13; i++)
		{
			//-1이 아닌 것들은 점수이기 때문에 total에 저장한다. 
			if (player1.Point[i] != -1)
			{
				player1.Point[13] += player1.Point[i];
			}
			if (player2.Point[i] != -1)
			{
				player2.Point[13] += player2.Point[i];
			}
		}
		//1p, 2p 보너스 점수 계산
		int Bonus1 = 0, Bonus2 = 0;	//1~6 점수 더할 변수
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
		//1p, 2p 점수표 표시
		ShowPoint(player1.Point, player2.Point);
	}

	system("cls");
	ShowPoint(player1.Point, player2.Point);
	if (player1.Point[13] > player2.Point[13])
		cout << "1P승리!" << endl;
	else
		cout << "2P승리!" << endl;
}
