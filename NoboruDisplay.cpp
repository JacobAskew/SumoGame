//---------------------------------------------------------------------------
#include <fmx.h>
#include <FMX.Dialogs.hpp>
#include <System.UITypes.hpp>  // For colors
#include <map>  // If you still want to use maps
#include <FMX.Graphics.hpp>   // For TBitmap
#include <System.SysUtils.hpp>  // Required for UnicodeString conversion
#include <regex>
//---------------------------------------------------------------------------
#include "NoboruDisplay.h"
#include "Noboru.h"
#include "Street.h" // Include after Noboru.h
#include "Beya.h" // Include after Noboru.h to avoid issues
#include "Banzuke.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
//---------------------------------------------------------------------------
TNoboruDisplayForm *NoboruDisplayForm;
//---------------------------------------------------------------------------
void SetupNoboruDisplay() {

}
//---------------------------------------------------------------------------
__fastcall TNoboruDisplayForm::TNoboruDisplayForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNoboruDisplayForm::ButtonReturnClick(TObject *Sender)
{
	NoboruForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
