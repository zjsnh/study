#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//ʹ�ó����ý��д�������߳���Ч��
void Animal_Judge(short* Features, const short& FeatureCount)
{
	//ʹ�ó�ʼ���б�Ա�����ʼ�������Ч��
	bool isMammal(false);
	bool isBird(false);
	bool isCarnivore(false); //��ʳ�⶯��
	bool isUngulates(false); //�������ද��

	for (int i(0); i < FeatureCount; ++i)
	{
		switch (Features[i])
		{
		case 1: { isMammal = true; break; }
		case 2: { isMammal = true; break; }
		case 3: { isBird = true; break; }
		case 4:
		{
			if (i < FeatureCount - 1)
			{
				if (Features[i + 1] == 5)
				{
					isBird == true;
				}
			}
			break;
		}
		case 5:break;
		case 6: { isCarnivore = true; break; }
		case 7:
		{
			if (i < FeatureCount - 2)
			{
				if (Features[i + 1] == 8 && Features[i + 2] == 9)
				{
					isCarnivore = true;
				}
			}
			break;
		}
		case 8:break;
		case 9:break;
		case 10:
		{
			if (isMammal == true)
			{
				isUngulates = true;
			}
			break;
		}
		case 11:
		{
			if (isMammal == true)
			{
				isUngulates = true;
			}
			break;
		}
		case 12:
		{
			if (isMammal == true && isCarnivore == true)
			{
				if (i < FeatureCount - 1)
				{
					if (Features[i + 1] == 13)
					{
						cout << "�������飬�ö����Ǳ���" << endl;
						return;
					}
					else if (Features[i + 1] == 14)
					{
						cout << "�������飬�ö����ǻ���" << endl;
						return;
					}
				}
			}
			break;
		}
		case 13:
		{
			if (isUngulates == true)
			{
				if (i < FeatureCount - 2)
				{
					if (Features[i + 1] == 15 && Features[i + 2] == 16)
					{
						cout << "�������飬�ö����ǳ���¹��" << endl;
						return;
					}
				}
			}
			break;
		}
		case 14:
		{
			if (isUngulates == true)
			{
				cout << "�������飬�ö���Ϊ����" << endl;
				return;
			}
			break;
		}
		case 15:break;
		case 16:break;
		case 17:
		{
			if (isBird == true)
			{
				if (i > 1 && i < FeatureCount - 1)
				{
					if (Features[i - 2] == 15 && Features[i - 1] == 16 && Features[i + 1] == 18)
					{
						cout << "�������飬�ö���Ϊ����" << endl;
						return;
					}
				}
				else if (i < FeatureCount - 2)
				{
					if (Features[i + 1] == 18 && Features[i + 2] == 19)
					{
						cout << "�������飬�ö���Ϊ��졣" << endl;
						return;
					}
				}
			}
			break;
		}
		case 18:break;
		case 19:break;
		case 20:
		{
			if (isBird == true)
			{
				cout << "�������飬�ö���Ϊ�����̡�" << endl;
				return;
			}
		}

		}
	}
	cout << "���������������û���ҵ�ƥ��Ķ���Ŷ��" << endl;
	return;
}

int main(void)
{
	const string Features[20] = { "1.��ë��","2.����","3.����ë","4.���","5.������","6.����","7.��Ϭ������","8.��צ","9.����ǰ��","10.����","11.��ۻ","12.�лƺ�ɫ","13.�а��ߵ�","14.�к�ɫ����","15.�г�����","16.�г���","17.�����","18.�кڰ���ɫ","19.����Ӿ","20.�Ʒ�" };
	cout << "�����Ƕ���Ļ���������" << endl;
	for (int i(0); i < 20; ++i)
	{
		if (i % 5 == 0 && i != 0)
		{
			cout << "\n";
		}
		cout << setiosflags(ios::left);
		cout << setw(15) << Features[i];
	}
	cout << endl << endl;
loop:
	cout << "���������ʶ����������ı�Ÿ���������-1�˳����򣩣�";
	short FeatureCount;
	cin >> FeatureCount;
	if (FeatureCount != -1)
	{
		short* FeatureIncluded = new short[FeatureCount];
		cout << "�밴������һ�������ʶ����������ı�ţ�";
		for (int i(0); i < FeatureCount; ++i)
		{
			cin >> FeatureIncluded[i];
		}
		Animal_Judge(FeatureIncluded, FeatureCount);
		cout << endl;
		goto loop;
	}
	return 0;
}
