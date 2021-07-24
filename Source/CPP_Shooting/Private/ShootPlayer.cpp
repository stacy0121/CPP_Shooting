// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
//#include "CPP_Shooting.h"
#include "PlayerMove.h"
#include "PlayerFire.h"
#include <Components/ArrowComponent.h>
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AShootPlayer::AShootPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// �����ڿ��� - Actor �� �̷�� ������Ʈ�� ������ (���� add component). �̸��� �ٸ���
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	// root �� �ڽ�����
	firePosition->SetupAttachment(RootComponent);

	//******************************************************************************
	// Box Collision Component �߰�
	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	// Hit event ���� root��
	RootComponent = boxCollision;
	// �浹 �ɼ� Block ���� ����. profile name : collision - preset - name
	boxCollision->SetCollisionProfileName(TEXT("BlockAll"));


	// Body Mesh Component �߰�
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);                   // boxCollison or RootComponent
	// �浹 ���� �ʵ���
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// �ڵ����� ��Ʈ�ѷ� ��� ���� �� �ֵ��� ����
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);

}

