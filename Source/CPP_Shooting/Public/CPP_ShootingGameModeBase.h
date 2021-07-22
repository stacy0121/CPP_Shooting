// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"                            //상속을 위해
#include "CPP_ShootingGameModeBase.generated.h"                    //클래스 정보 기록

/**
 * 
 */
UCLASS()                                                           //매크로 - 바로 아래(class)가 unreal class다.
class CPP_SHOOTING_API ACPP_ShootingGameModeBase : public AGameModeBase              //ACPP_ShootingGameModeBase가 클래스 이름. AGameModeBase 상속
{
	GENERATED_BODY()

public:
	ACPP_ShootingGameModeBase();                                   //default 생성자. 헤더에는 선언만. 구현{}은 소스 파일에(shift+alt+Q)

	//Tick 함수 오버라이딩
//	virtual void Tick(float DeltaSeconds) override;



};
