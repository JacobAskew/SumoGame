//---------------------------------------------------------------------------
#include <fmx.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Newspaper.h"
#include "Banzuke.h"
#include "Street.h"
//---------------------------------------------------------------------------

TNewspaperForm *NewspaperForm;
//---------------------------------------------------------------------------
__fastcall TNewspaperForm::TNewspaperForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewspaperForm::ButtonGoBackClick(TObject *Sender)
{
	BanzukeForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
