// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//UE_LOG Category �߰� -> Filter ���� �� ����
DECLARE_LOG_CATEGORY_EXTERN(Shoot, Log, All);

//��𿡼� �������� ������ ��ũ��
//#define APPINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

//��𿡼� ȣ���ߴ��� ���� '�Լ�'
//#define CALLINFO() UE_LOG(Shoot, Waring, TEXT("%s"), *APPINFO)

//����ڰ� �α� ���� �� �̿��� ��ũ�� �Լ�
//#define PRINTLOG(fmt, ...) UE_LOG(Shoot, Warning, TEXT("%s, %s"), *APPINFO, *FString::Printf(fmt, ##__VA_ARGS__))