// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
//#include "CPP_Shooting.h"
#include "PlayerMove.h"

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Actor �� �̷�� ������Ʈ�� ������ (���� add component)
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
}

// Called when the game starts or when spawned
void AShootPlayer::BeginPlay()
{
	Super::BeginPlay();
	
//	UE_LOG(Shoot, Warning, TEXT("%s"), *APPINFO);         //FString �����ʹ� ������ ���
//	PRINTLOG(TEXT("%s"), TEXT("Hello World"));            //ù��° ���ڿ� fmt, �ι�° ���ڿ��� ...�� ��ü(CPP_Shooting.h)
}

// Called every frame
void AShootPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);       //�������Ʈ ���� �������. ����� ���⿡

	// PlayerMove ������Ʈ�� SetupPlayer �Լ��� ȣ���ϰ� �ʹ�.
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);

}

