//---------------------------------------------------------------------------
#include <fmx.h>
#include <algorithm> // For std::random_shuffle (in older C++ compilers)
#include <stdexcept>
#include <iostream>
#include <filesystem>  // Required for filesystem checks
#include <windows.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <set> // For std::set
#include <cmath> // For std::floor
#include <map>
#include <functional>
#include <System.IOUtils.hpp> // For file path handling
//---------------------------------------------------------------------------
#include "Retirement.h"
#include "Street.h"
#include "Noboru.h"
#include "Beya.h"
#include "Training.h"
#include "Banzuke.h"
#include "Dohyo.h"
#include "Ryogoku.h"
#include "Endgame.h"
#include "Battle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
//---------------------------------------------------------------------------
TRetirementForm *RetirementForm;
String PathOldHome = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\.png";
//---------------------------------------------------------------------------
void SetupRetirement() {
	TImage* imageoldhome = dynamic_cast<TImage*>(RetirementForm->FindComponent("ImageBackground"));
	AnsiString fullPathHome = PathOldHome;
	imageoldhome->Bitmap->LoadFromFile(fullPathHome);
}
//---------------------------------------------------------------------------
__fastcall TRetirementForm::TRetirementForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRetirementForm::ButtonReturnClick(TObject *Sender)
{
	MainStreet->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
