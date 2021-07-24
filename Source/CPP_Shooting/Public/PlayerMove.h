
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"                                    //UPROPERTY - ���⿡ �Ӽ� ���

// ����� �Է¿� ���� ��ȭ�¿�� �̵��ϰ� �ʹ�. - Tick
// �ʿ� �Ӽ� : �̵� �ӵ�

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )    //������Ʈ Ŭ���� �׷� �̸� Custom. �������Ʈ ���� ����
class CPP_SHOOTING_API UPlayerMove : public UActorComponent          //Actor Component ���
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;                //�ڽĿ��� ������

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;       //Alt+G �ҽ� ���Ϸ�

	//����� �Է�
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);           //ShootPlayer.h

	// �Է� �Լ� ����
	void Horizontal(float value);
	void Vertical(float value);

public:
	// �ʿ� '�Ӽ�' : �̵� �ӵ�
	UPROPERTY(EditAnywhere, Category="Setting", BlueprintReadOnly)    // 1. �����Ϳ� �����ϴ� ��ũ�� �Լ�(Edit / Visible DefaultsOnly & Instance & Anywhere)
	float speed = 500;                                                //�ҽ� �ڵ忡 �ᵵ ��

private:
	UPROPERTY()                                      // 2. �޸� ����
	class AShootPlayer* me;                          //���� ����. �а� �Ѿ. �ҽ� �ڵ忡�� ���

	//����Ű �Է� ����� ���� �Ӽ�
	float h;
	float v;
};
