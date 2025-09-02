//---------------------------------------------------------------------------

#ifndef BanzukeH
#define BanzukeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <vector>

//---------------------------------------------------------------------------

//bool IsBanzukeComplete;
//---------------------------------------------------------------------------
class TBanzukeForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonReturnStreet;
	TImage *ImageBackGround;
	TButton *ButtonBanzuke;
	TButton *ButtonNewspaper;
	void __fastcall ButtonReturnStreetClick(TObject *Sender);
//	void __fastcall ButtonDohyoClick(TObject *Sender);
//	void __fastcall ButtonAutomateAllClick(TObject *Sender);
//	void __fastcall BanzukeGridDrawCell(TObject *Sender, TCanvas * const Canvas,
//		TGridDrawStates State, int Col, int Row, const TRectF &Bounds);
//	void __fastcall StringGridTournamentDrawColumnCell(TObject *Sender, TCanvas * const Canvas,
//		  TColumn * const Column, const TRectF &Bounds, const int Row,
//          const TValue &Value, const TGridDrawStates State);
//	void __fastcall ButtonNextBoutClick(TObject *Sender);
//	void __fastcall ButtonNextHumanBoutClick(TObject *Sender);
	void __fastcall ButtonNewspaperClick(TObject *Sender);
	void __fastcall ButtonBanzukeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBanzukeForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TBanzukeForm *BanzukeForm;
//---------------------------------------------------------------------------
#endif

