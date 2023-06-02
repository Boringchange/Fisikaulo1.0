// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SQLiteDatabase.h"

/**
 * 
 */
class PHYSICGAME_API Base
{
public:
	Base(FString Path, ESQLiteDatabaseOpenMode OpenMode);
	~Base();

	bool SavePlayerCond(int32 PlayerId, FString PlayerName);
private:
	FSQLiteDatabase* Database;

	FSQLitePreparedStatement SaveStatement;
	FSQLitePreparedStatement LoadStatement;
};

