#include <stdio.h>

//// 定义枚举类型 color，表示颜色
//enum color {
//    RED=1,    
//    GREEN,  
//    BLUE    
//};
//
//int main() {
//    enum color myColor;
//
//    myColor = RED;
//
//
//    printf("%d\n", myColor);
//    //printf("%u", sizeof(myColor));
//
//    /*switch (myColor) {*/
//    /*case RED:
//        printf("The color is red.\n");
//        break;
//    case GREEN:
//        printf("The color is green.\n");
//        break;
//    case BLUE:
//        printf("The color is blue.\n");
//        break;
//    default:
//        printf("Unknown color.\n");
//        break;
//    }*/
//
//    return 0;
//}

//struct Example {
//	int i;
//	double d;
//	char c;
//};

#pragma pack(push, 8)
struct Example {
	double d;
	int i;
	char c;
};
#pragma pack(pop)


int main() {
	printf("%zu \n", sizeof(struct Example));
	return 0;
}