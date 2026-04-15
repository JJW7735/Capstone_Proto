#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MoralDecisionComponent.generated.h"

// 1. 선택 타입 정의 (왼쪽/오른쪽)
UENUM(BlueprintType)
enum class EChoiceType : uint8
{
	Left  UMETA(DisplayName = "Left Choice"),
	Right UMETA(DisplayName = "Right Choice")
};

// 2. 스테이지별 텍스트 데이터를 담는 구조체
USTRUCT(BlueprintType)
struct FStageData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage")
	FString StageTitle;      // 예: "Stage 1"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage")
	FString LeftDescription; // 왼쪽 버튼 아래 설명

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage")
	FString RightDescription;// 오른쪽 버튼 아래 설명
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CAPSTONE_PROTO_API UMoralDecisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMoralDecisionComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- 데이터 관리 ---

	// 에디터에서 직접 5개 스테이지의 설명을 입력할 수 있는 배열
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trolley|Data")
	TArray<FStageData> StageConfigs;

	// 플레이어가 선택한 기록들이 순서대로 저장됨
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trolley|Data")
	TArray<EChoiceType> PlayerDecisionHistory;

	// 현재 진행 중인 스테이지 번호 (0 ~ 4)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trolley|Data")
	int32 CurrentStageIndex = 0;

	// --- 핵심 기능 ---

	// 갈림길 진입 시 호출: 시간을 0.1배속으로 느리게 만듦
	UFUNCTION(BlueprintCallable, Category = "Trolley|Logic")
	void StartDecisionMoment();

	// 버튼 클릭 시 호출: 선택을 기록하고 시간을 다시 1.0배속으로 돌림
	UFUNCTION(BlueprintCallable, Category = "Trolley|Logic")
	void MakeDecision(EChoiceType SelectedChoice);

	// 5스테이지 종료 후 최종 분석 결과를 가져옴
	UFUNCTION(BlueprintCallable, Category = "Trolley|Logic")
	FString GetFinalAnalysis();
};