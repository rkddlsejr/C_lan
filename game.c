#include <stdio.h>

int main()
{
	printf("적 캐릭터는 hp가 30입니다.");
	printf("\n\n프로그램이 시작되면 다음과 같이 캐릭터 메이킹 화면을 구성해 주세요.");
	printf("\n---------------------------------------------------------------\n");
	int a;
	int e = 30;
	printf("주인공의 공격력을 입력하세요. : ");
	scanf("%d", &a);
	printf("주인공의 공격력은 %d입니다.\n", a);
	printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n", a);

	if(e>a)
	{
		printf("적의 잔여 HP:%d\n",e-a);
		printf("적이 주인공을 공격하여 주인공이 뒤졌습니다.\n");
		printf("Game Over\n");
	}	
	else
	{
		printf("적의 잔여 HP:0\n");
		printf("적을 물리쳤습니다!\n");
		printf("Happy End\n");
	}
	return 0;
}
