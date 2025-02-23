//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Dohyo.h"
#include "Street.h"
#include "Banzuke.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TDohyoForm *DohyoForm;
//---------------------------------------------------------------------------
__fastcall TDohyoForm::TDohyoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDohyoForm::ButtonReturnBanzukeClick(TObject *Sender)
{
	BanzukeForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TDohyoForm::ButtonReturnStreetClick(TObject *Sender)
{
	MainStreet->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
