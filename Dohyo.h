//---------------------------------------------------------------------------

#ifndef DohyoH
#define DohyoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Effects.hpp>
//---------------------------------------------------------------------------

struct Rikishi;

//---------------------------------------------------------------------------

class TDohyoForm : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageBelt1;
	TImage *ImageBelt2;
	TImage *ImageRikishi1;
	TImage *ImageRikishi2;
	TImage *ImageVS;
	TImage *ImageYokozuna1;
	TImage *ImageYokozuna2;
	TButton *ButtonReturnStreet;
	TButton *ButtonNextPlayerBout;
	TImage *ImageEndurance1;
	TGlowEffect *GlowEffectEndurance1;
	TImage *ImageSpeed1;
	TGlowEffect *GlowEffectSpeed1;
	TImage *ImageStrength1;
	TGlowEffect *GlowEffectStrength1;
	TImage *ImageTechnique1;
	TGlowEffect *GlowEffectTechnique1;
	TImage *ImageWeight1;
	TGlowEffect *GlowEffectWeight1;
	TImage *ImageEndurance2;
	TGlowEffect *GlowEffectEndurance2;
	TImage *ImageSpeed2;
	TGlowEffect *GlowEffectSpeed2;
	TImage *ImageStrength2;
	TGlowEffect *GlowEffectStrength2;
	TImage *ImageTechnique2;
	TGlowEffect *GlowEffectTechnique2;
	TImage *ImageWeight2;
	TGlowEffect *GlowEffectWeight2;
	TImage *ImageFightBackground;
	TText *TextFighter1;
	TText *TextFighter2;
	TText *TextOwner1;
	TText *TextOwner2;
	TText *TextDateTime;
	TButton *ButtonDohyo;
	void __fastcall ButtonReturnBanzukeClick(TObject *Sender);
	void __fastcall ButtonReturnStreetClick(TObject *Sender);
	void __fastcall ButtonWeight1Click(TObject *Sender);
	void __fastcall ButtonEndurance1Click(TObject *Sender);
	void __fastcall ButtonTechnique1Click(TObject *Sender);
	void __fastcall ButtonSpeed1Click(TObject *Sender);
	void __fastcall ButtonStrength1Click(TObject *Sender);
	void __fastcall ButtonWeight2Click(TObject *Sender);
	void __fastcall ButtonEndurance2Click(TObject *Sender);
	void __fastcall ButtonTechnique2Click(TObject *Sender);
	void __fastcall ButtonSpeed2Click(TObject *Sender);
	void __fastcall ButtonStrength2Click(TObject *Sender);
	void __fastcall ButtonFightClick(TObject *Sender);
	void __fastcall ButtonNextPlayerBoutClick(TObject *Sender);
	void __fastcall ButtonDohyoClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TDohyoForm(TComponent* Owner);
	void DohyoSetup();
};
//---------------------------------------------------------------------------
extern PACKAGE TDohyoForm *DohyoForm;
extern void UpdateDohyoGUI(Rikishi* fighter1, Rikishi* fighter2, TForm *form);
//---------------------------------------------------------------------------
#endif
