// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"                            //����� ����
#include "CPP_ShootingGameModeBase.generated.h"                    //Ŭ���� ���� ���

/**
 * 
 */
UCLASS()                                                           //��ũ�� - �ٷ� �Ʒ�(class)�� unreal class��.
class CPP_SHOOTING_API ACPP_ShootingGameModeBase : public AGameModeBase              //ACPP_ShootingGameModeBase�� Ŭ���� �̸�. AGameModeBase ���
{
	GENERATED_BODY()

public:
	ACPP_ShootingGameModeBase();                                   //default ������. ������� ����. ����{}�� �ҽ� ���Ͽ�(shift+alt+Q)

	//Tick �Լ� �������̵�
//	virtual void Tick(float DeltaSeconds) override;



};
