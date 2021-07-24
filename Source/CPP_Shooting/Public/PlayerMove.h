
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"                                    //UPROPERTY - 여기에 속성 등록

// 사용자 입력에 따라 상화좌우로 이동하고 싶다. - Tick
// 필요 속성 : 이동 속도

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )    //컴포넌트 클래스 그룹 이름 Custom. 블루프린트 스폰 가능
class CPP_SHOOTING_API UPlayerMove : public UActorComponent          //Actor Component 상속
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;                //자식에서 재정의

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;       //Alt+G 소스 파일로

	//사용자 입력
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);           //ShootPlayer.h

	// 입력 함수 선언
	void Horizontal(float value);
	void Vertical(float value);

public:
	// 필요 '속성' : 이동 속도
	UPROPERTY(EditAnywhere, Category="Setting", BlueprintReadOnly)    // 1. 에디터에 노출하는 매크로 함수(Edit / Visible DefaultsOnly & Instance & Anywhere)
	float speed = 500;                                                //소스 코드에 써도 됨

private:
	UPROPERTY()                                      // 2. 메모리 관리
	class AShootPlayer* me;                          //전방 선언. 읽고 넘어감. 소스 코드에서 사용

	//방향키 입력 기억을 위한 속성
	float h;
	float v;
};
