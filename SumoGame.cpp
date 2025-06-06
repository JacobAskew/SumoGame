//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Ryogoku.cpp", RyogokuForm);
USEFORM("Noboru2.cpp", Storage_2);
USEFORM("Storage.cpp", StorageForm);
USEFORM("Training.cpp", TrainingPopup);
USEFORM("Street.cpp", MainStreet);
USEFORM("Dohyo.cpp", DohyoForm);
USEFORM("Beya.cpp", YourBeya);
USEFORM("Battle.cpp", BattleForm);
USEFORM("Banzuke.cpp", BanzukeForm);
USEFORM("Dohyo2.cpp", Form2);
USEFORM("Noboru.cpp", NoboruForm);
USEFORM("EndGame.cpp", GameOver);
USEFORM("Retirement.cpp", RetirementForm);
USEFORM("NoboruDisplay.cpp", NoboruDisplayForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainStreet), &MainStreet);
		Application->CreateForm(__classid(TYourBeya), &YourBeya);
		Application->CreateForm(__classid(TTrainingPopup), &TrainingPopup);
		Application->CreateForm(__classid(TBanzukeForm), &BanzukeForm);
		Application->CreateForm(__classid(TDohyoForm), &DohyoForm);
		Application->CreateForm(__classid(TStorageForm), &StorageForm);
		Application->CreateForm(__classid(TRyogokuForm), &RyogokuForm);
		Application->CreateForm(__classid(TGameOver), &GameOver);
		Application->CreateForm(__classid(TStorage_2), &Storage_2);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TBattleForm), &BattleForm);
		Application->CreateForm(__classid(TRetirementForm), &RetirementForm);
		Application->CreateForm(__classid(TNoboruDisplayForm), &NoboruDisplayForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
