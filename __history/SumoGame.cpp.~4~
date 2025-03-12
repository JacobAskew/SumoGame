//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Street.cpp", MainStreet);
USEFORM("Training.cpp", TrainingPopup);
USEFORM("Dohyo.cpp", DohyoForm);
USEFORM("Beya.cpp", YourBeya);
USEFORM("Banzuke.cpp", BanzukeForm);
USEFORM("Noboru.cpp", NoboruForm);
USEFORM("Storage.cpp", StorageForm);
USEFORM("Ryogoku.cpp", RyogokuForm);
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
