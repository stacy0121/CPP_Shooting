


#include "PlayerMove.h"
#include "ShootPlayer.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;       //�ҽ� �ڵ� tick ����

	// ...
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AShootPlayer>(GetOwner());           //���⼭ �ʱ�ȭ
	
}


// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ����� �Է¿� ���� ��ȭ�¿�� �̵��ϰ� �ʹ�.
	//1. ������ �ʿ�
//	FVector dir = FVector::RightVector;                    // y �� ������
	FVector dir = FVector(0, h, v);                        // �Է� ��� ���� �ؾ� ��
	//2. �̵��ϰ� �ʹ�. P = P0 + vt
	//�� ������Ʈ�� �����ϰ� �ִ� Actor �� ��ȯ. �θ�(GetOwner)�� �ڽ�(ShootPlayer)�� ���� �� ����(�Ϲ��� ����ȯX) -> ����� ����ȯ �ؾ� ��(�θ� �ڽ� ���迡 �ִ���)
	//AActor* me = GetOwner();
//	AShootPlayer* me = Cast<AShootPlayer>(GetOwner());            //�Ӽ����� �߰��Ͽ� �� ���� �ε�
	//�ִ��� ����. ��� �ڵ�
	if (me) {
		FVector P0 = me->GetActorLocation();
		FVector P = P0 + (dir * speed) * DeltaTime;
		me->SetActorLocation(P);
	}
}

//����� �Է�
void UPlayerMove::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMove::Horizontal);            //����, ���ε�. call by reference. Horizontal �Է��� ������ �� �Ҽ�(this) Horizontal �Լ� ȣ��
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMove::Vertical);
}

//�Լ� ����
void UPlayerMove::Horizontal(float value)
{
	h = value;
}

void UPlayerMove::Vertical(float value)
{
	v = value;
}

