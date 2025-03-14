// Noboru.h

#ifndef NoboruH
#define NoboruH

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <System.Rtti.hpp>

void EndBidding();
void PlaceBid(int bidAmount);
bool IsBiddingComplete();  // Declare this function to check if bidding is complete
bool AreAllPlayersOutOfAP();
void UpdateBidding();

class TMainStreet;

class TNoboruForm : public TForm
{
__published:    // IDE-managed Components
    TButton *ReturnStreet;
    TMemo *MemoLogNoboru;
    TEdit *EditBidInput;
    TLabel *BidLabel;
	TButton *NextBidButton;
    TEdit *EditCurrentRikishiBid;
	TImage *ImageRikishi;
    TStringGrid *BanzukeGrid;
    TStringColumn *RankColumn;
    TStringColumn *NameColumn;
    TStringColumn *OyakataColumn;
    TStringColumn *AgeColumn;
    TStringColumn *SpiritColumn;
    TStringColumn *WeightColumn;
    TStringColumn *EnduranceColumn;
    TStringColumn *TechniqueColumn;
    TStringColumn *SpeedColumn;
    TStringColumn *StrengthColumn;
    TStringColumn *MinBidColumn;
	TButton *ButtonMinBid;
	TButton *ButtonSubmitBid;
	TButton *ButtonSkipAllBids;
	TImage *ImageBelt;
	TImage *ImageYokozuna;

    void __fastcall ReturnStreetClick(TObject *Sender);
	void __fastcall ButtonMinBidClick(TObject *Sender);
	void __fastcall NextBidButtonClick(TObject *Sender);
	void __fastcall ButtonSkipAllBidsClick(TObject *Sender);
	void __fastcall ButtonSubmitBidClick(TObject *Sender);
	void __fastcall BanzukeGridDrawColumnCell(TObject *Sender, TCanvas * const Canvas,
          TColumn * const Column, const TRectF &Bounds, const int Row,
          const TValue &Value, const TGridDrawStates State);

private:    // User declarations

public:     // User declarations
	__fastcall TNoboruForm(TComponent* Owner);
    void StartBidding();  // This is the declaration of the StartBidding function
};

extern PACKAGE TNoboruForm *NoboruForm;
extern void UpdateBanzukeGrid();
extern String RikishiPath;
extern String BeltPath;
extern String YokozunaPath;
extern bool isBiddingComplete;
extern bool TrainedRikishi1;
extern bool TrainedRikishi2;
extern bool TrainedRikishi3;

#endif

