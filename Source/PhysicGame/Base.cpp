// Fill out your copyright notice in the Description page of Project Settings.


#include "Base.h"

Base::Base(FString Path, ESQLiteDatabaseOpenMode OpenMode)
{
	Database = new FSQLiteDatabase();

	if (!Database->Open(*Path, OpenMode) || !Database->IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to open database: %s"), *Database->GetLastError());
	}

	const TCHAR* SaveQuery = TEXT("replace into perfiles (id_usr, nom_usr, pass) values ()");
	SaveStatement.Create(*Database, SaveQuery, ESQLitePreparedStatementFlags::Persistent);

	const TCHAR* LoadQuery = TEXT("select * from perfiles where id_usr = $id_usr");
	LoadStatement.Create(*Database, LoadQuery, ESQLitePreparedStatementFlags::Persistent);
}

Base::~Base()
{
	SaveStatement.Destroy();
	LoadStatement.Destroy();
	
	if (!Database->Close())
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to close database: %s"), *Database->GetLastError());
	}
	else
	{
		delete Database;
	}
}
