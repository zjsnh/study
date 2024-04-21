#include"binary.cpp"



int main()
{
	char BT[] = "ABD##E#H##CF##G##";
	BTNode A;
	int a = 0;
	int* pi = &a;
	A.BinaryTreeCreate(BT, 0, pi);

	/*A.BinaryTreePrevOrder();*/

	return 0;

}