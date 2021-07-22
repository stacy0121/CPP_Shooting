// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
//#include "CPP_Shooting.h"
#include "PlayerMove.h"

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Actor 를 이루는 컴포넌트를 붙이자 (실제 add component)
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
}

// Called when the game starts or when spawned
void AShootPlayer::BeginPlay()
{
	Super::BeginPlay();
	
//	UE_LOG(Shoot, Warning, TEXT("%s"), *APPINFO);         //FString 데이터는 포인터 사용
//	PRINTLOG(TEXT("%s"), TEXT("Hello World"));            //첫번째 문자열 fmt, 두번째 문자열이 ...로 대체(CPP_Shooting.h)
}

// Called every frame
void AShootPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);       //블루프린트 전에 만들어짐. 골격은 여기에

	// PlayerMove 컴포넌트의 SetupPlayer 함수를 호출하고 싶다.
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);

}

