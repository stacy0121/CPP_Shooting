// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShootPlayer.generated.h"

UCLASS()
class CPP_SHOOTING_API AShootPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShootPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;     //입력 처리할 함수와 묶어줌

public:
	//PlayerMove 컴포넌트 추가 (속성 등록) -> 생성자에서 추가
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UPlayerMove* playerMove;            //class - 헤더 등록, 컴파일 타임 필요

	UPROPERTY(VisibleAnywhere, Category="Component")
	class UPlayerFire* playerFire;


	// actor 에서 컨트롤하기 위해
	UPROPERTY(VisibleAnywhere, Category = "FirePosition")
	class UArrowComponent* firePosition;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	class UBoxComponent* boxCollision;
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
};
