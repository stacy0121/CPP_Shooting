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

	// 생성자에서 - Actor 를 이루는 컴포넌트를 붙이자 (실제 add component). 이름은 다르게
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	// root 의 자식으로
	firePosition->SetupAttachment(RootComponent);

	//******************************************************************************
	// Box Collision Component 추가
	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	// Hit event 위해 root로
	RootComponent = boxCollision;
	// 충돌 옵션 Block 으로 설정. profile name : collision - preset - name
	boxCollision->SetCollisionProfileName(TEXT("BlockAll"));


	// Body Mesh Component 추가
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);                   // boxCollison or RootComponent
	// 충돌 되지 않도록
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 자동으로 컨트롤러 제어를 받을 수 있도록 설정
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);

}

