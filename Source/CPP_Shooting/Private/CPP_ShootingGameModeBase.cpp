// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()           //�Ҽ� Ŭ���� (���� ������ ::) ��� �Լ�/����
{
	PrimaryActorTick.bCanEverTick = true;
	//int32 a = 10;                                      //�׳� int �ƴ�. 32 bit
	//float f = 2.05f;
	//bool b = true;
	//int c = (b == true) ? 10 : 20;                     //���׿�����
	//FString name = TEXT("brad") + FString("ho");       //�𸮾� ���ڿ� FString ���. ������ ����. ������ *name      text+text(x)
	//name.Append("HAHaHAha");
	//FString msg = FString::Printf(TEXT("%s %d %f %s"), *name, a, f, (b) ? TEXT("True") : TEXT("False"));    //printf - static

 //   //����->����
	//FString itos = FString::FromInt(10);              
	//FString ftos = FString::SanitizeFloat(20.5f);

	//output log�� ����ϴ� ��ũ��(ī�װ�, �޼��� Ÿ��(warning-�����), text-����� ����/���� ���ڿ�, ������ ����)
	//UE_LOG(LogTemp, Warning, TEXT("%s"), * msg);

	//�迭
// 	TArray < int32 > arr;     //Linked List
// 	arr.Add(10);
// 	arr.Add(20);
// 	arr[0] = 20;
// 
// 	arr.RemoveAt(0);          //0���� ����
// 	arr.Insert(1, 20);        //1������ 20 ����
// 	arr.Num();
// 
// 	for (int value: arr) {      //for�� �ۼ���
// 		UE_LOG(LogTemp, Warning, TEXT("%d"), value);
//	}

// 	int a = 10;
// 	auto b = 20;       //auto �� �̸�
// 	auto c = TEXT("Hello");
// 	auto d = true;
}

