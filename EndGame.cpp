//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "EndGame.h"
#include "Street.h"
#include "Ryogoku.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TGameOver *GameOver;

String EndGamePath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\EndGame";
//bool WinGame = false;

//---------------------------------------------------------------------------
__fastcall TGameOver::TGameOver(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGameOver::ButtonReturnClick(TObject *Sender)
{
	MainStreet->Show(); // Show the main form
	this->Hide();     // Hide the second form
}
//---------------------------------------------------------------------------


void UpdateEndScreen()
{
	if (WinGame) {
		String WhichEnd = "Win";
		TImage* imageEndGame = dynamic_cast<TImage*>(GameOver->FindComponent("ImageEndScreen"));
		AnsiString fullPathRikishi = EndGamePath + WhichEnd + ".png";
		imageEndGame->Bitmap->LoadFromFile(fullPathRikishi);
	}
	else {
		String WhichEnd = "Defeat";
		TImage* imageEndGame = dynamic_cast<TImage*>(GameOver->FindComponent("ImageEndScreen"));
		AnsiString fullPathRikishi = EndGamePath + WhichEnd + ".png";
		imageEndGame->Bitmap->LoadFromFile(fullPathRikishi);
	}


}


