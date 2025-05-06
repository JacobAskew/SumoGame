//---------------------------------------------------------------------------

#ifndef Dohyo2H
#define Dohyo2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonEndurance1;
	TButton *ButtonEndurance2;
	TButton *ButtonFight;
	TButton *ButtonNextPlayerBout;
	TButton *ButtonReturnBanzuke;
	TButton *ButtonReturnStreet;
	TButton *ButtonSpeed1;
	TButton *ButtonSpeed2;
	TButton *ButtonStrength1;
	TButton *ButtonStrength2;
	TButton *ButtonTechnique1;
	TButton *ButtonTechnique2;
	TButton *ButtonWeight1;
	TButton *ButtonWeight2;
	TEdit *EditAge1;
	TEdit *EditAge2;
	TEdit *EditFighter1;
	TEdit *EditFighter2;
	TEdit *EditOwner1;
	TEdit *EditOwner2;
	TEdit *EditRank1;
	TEdit *EditRank2;
	TEdit *EditRecord1;
	TEdit *EditRecord2;
	TEdit *EditSpirit1;
	TEdit *EditSpirit2;
	TImage *ImageArena;
	TImage *ImageBelt1;
	TImage *ImageBelt2;
	TImage *ImageRikishi1;
	TImage *ImageRikishi2;
	TImage *ImageVS;
	TImage *ImageYokozuna1;
	TImage *ImageYokozuna2;
	TMemo *MemoFightLog;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
