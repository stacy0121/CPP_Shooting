// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()           //소속 클래스 (범위 연산자 ::) 멤버 함수/변수
{
	PrimaryActorTick.bCanEverTick = true;
	//int32 a = 10;                                      //그냥 int 아님. 32 bit
	//float f = 2.05f;
	//bool b = true;
	//int c = (b == true) ? 10 : 20;                     //삼항연산자
	//FString name = TEXT("brad") + FString("ho");       //언리얼 문자열 FString 사용. 포인터 존재. 역참조 *name      text+text(x)
	//name.Append("HAHaHAha");
	//FString msg = FString::Printf(TEXT("%s %d %f %s"), *name, a, f, (b) ? TEXT("True") : TEXT("False"));    //printf - static

 //   //숫자->문자
	//FString itos = FString::FromInt(10);              
	//FString ftos = FString::SanitizeFloat(20.5f);

	//output log에 출력하는 매크로(카테고리, 메세지 타입(warning-노란색), text-출력할 문자/포맷 문자열, 데이터 나열)
	//UE_LOG(LogTemp, Warning, TEXT("%s"), * msg);

	//배열
// 	TArray < int32 > arr;     //Linked List
// 	arr.Add(10);
// 	arr.Add(20);
// 	arr[0] = 20;
// 
// 	arr.RemoveAt(0);          //0번지 삭제
// 	arr.Insert(1, 20);        //1번지에 20 삽입
// 	arr.Num();
// 
// 	for (int value: arr) {      //for문 작성법
// 		UE_LOG(LogTemp, Warning, TEXT("%d"), value);
//	}

// 	int a = 10;
// 	auto b = 20;       //auto 긴 이름
// 	auto c = TEXT("Hello");
// 	auto d = true;
}

