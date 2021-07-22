


#include "PlayerMove.h"
#include "ShootPlayer.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;       //소스 코드 tick 조정

	// ...
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AShootPlayer>(GetOwner());           //여기서 초기화
	
}


// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 사용자 입력에 따라 상화좌우로 이동하고 싶다.
	//1. 방향이 필요
//	FVector dir = FVector::RightVector;                    // y 값 설정됨
	FVector dir = FVector(0, h, v);                        // 입력 등록 따로 해야 함
	//2. 이동하고 싶다. P = P0 + vt
	//이 컴포넌트를 소유하고 있는 Actor 를 반환. 부모(GetOwner)를 자식(ShootPlayer)에 넣을 수 없음(암묵적 형변환X) -> 명시적 형변환 해야 함(부모 자식 관계에 있는지)
	//AActor* me = GetOwner();
//	AShootPlayer* me = Cast<AShootPlayer>(GetOwner());            //속성으로 추가하여 한 번만 로드
	//있는지 검출. 방어 코드
	if (me) {
		FVector P0 = me->GetActorLocation();
		FVector P = P0 + (dir * speed) * DeltaTime;
		me->SetActorLocation(P);
	}
}

//사용자 입력
void UPlayerMove::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMove::Horizontal);            //매핑, 바인드. call by reference. Horizontal 입력이 들어오면 내 소속(this) Horizontal 함수 호출
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMove::Vertical);
}

//함수 구현
void UPlayerMove::Horizontal(float value)
{
	h = value;
}

void UPlayerMove::Vertical(float value)
{
	v = value;
}

