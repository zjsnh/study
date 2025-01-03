#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//使用常引用进行传参以提高程序效率
void Animal_Judge(short* Features, const short& FeatureCount)
{
	//使用初始化列表对变量初始化以提高效率
	bool isMammal(false);
	bool isBird(false);
	bool isCarnivore(false); //是食肉动物
	bool isUngulates(false); //是有蹄类动物

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
						cout << "经过检验，该动物是豹。" << endl;
						return;
					}
					else if (Features[i + 1] == 14)
					{
						cout << "经过检验，该动物是虎。" << endl;
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
						cout << "经过检验，该动物是长颈鹿。" << endl;
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
				cout << "经过检验，该动物为斑马。" << endl;
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
						cout << "经过检验，该动物为鸵鸟。" << endl;
						return;
					}
				}
				else if (i < FeatureCount - 2)
				{
					if (Features[i + 1] == 18 && Features[i + 2] == 19)
					{
						cout << "经过检验，该动物为企鹅。" << endl;
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
				cout << "经过检验，该动物为信天翁。" << endl;
				return;
			}
		}

		}
	}
	cout << "根据您输入的特征没有找到匹配的动物哦！" << endl;
	return;
}

int main(void)
{
	const string Features[20] = { "1.有毛发","2.有奶","3.有羽毛","4.会飞","5.会生蛋","6.吃肉","7.有犀利牙齿","8.有爪","9.眼向前方","10.有蹄","11.反刍","12.有黄褐色","13.有暗斑点","14.有黑色条纹","15.有长脖子","16.有长腿","17.不会飞","18.有黑白两色","19.会游泳","20.善飞" };
	cout << "以下是动物的基础特征：" << endl;
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
	cout << "请输入待标识动物所满足的编号个数（输入-1退出程序）：";
	short FeatureCount;
	cin >> FeatureCount;
	if (FeatureCount != -1)
	{
		short* FeatureIncluded = new short[FeatureCount];
		cout << "请按升序逐一输入待标识动物所满足的编号：";
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
