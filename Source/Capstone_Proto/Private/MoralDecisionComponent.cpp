#include "MoralDecisionComponent.h"

UMoralDecisionComponent::UMoralDecisionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMoralDecisionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMoralDecisionComponent::StartDecisionMoment()
{
	// 게임 속도를 10%로 낮춤 (슬로우 모션)
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
	UE_LOG(LogTemp, Warning, TEXT("Decision Moment Started - Time Dilated"));
}

void UMoralDecisionComponent::MakeDecision(EChoiceType SelectedChoice)
{
	// 선택 기록 저장
	PlayerDecisionHistory.Add(SelectedChoice);

	// 스테이지 번호 증가
	CurrentStageIndex++;

	// 시간 정상화
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);

	UE_LOG(LogTemp, Warning, TEXT("Choice Made: %d, Next Stage: %d"), (int32)SelectedChoice, CurrentStageIndex);
}

FString UMoralDecisionComponent::GetFinalAnalysis()
{
	if (PlayerDecisionHistory.Num() < 5)
	{
		return TEXT("아직 모든 스테이지를 완료하지 않았습니다.");
	}

	// 실무적인 분석 알고리즘 (간단한 예시)
	int32 LeftCount = 0;
	for (EChoiceType Choice : PlayerDecisionHistory)
	{
		if (Choice == EChoiceType::Left) LeftCount++;
	}

	// 선택 결과에 따른 결과 리포트 생성
	if (LeftCount >= 4)
	{
		return TEXT("당신의 선택은 '의무론적 윤리'에 가깝습니다. 법률적으로는 결과보다 행위 자체의 정당성을 중시하는 경향이 있습니다.");
	}
	else if (LeftCount <= 1)
	{
		return TEXT("당신의 선택은 '공리주의'에 가깝습니다. 최대 다수의 최대 행복을 위해 소수의 희생을 감수하는 법적 판단을 선호합니다.");
	}
	else
	{
		return TEXT("당신의 선택은 상황에 따른 '비례의 원칙'을 중시합니다. 법률적으로 각 케이스의 형량과 가치를 개별적으로 판단하려 노력합니다.");
	}
}