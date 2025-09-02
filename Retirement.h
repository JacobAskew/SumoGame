//---------------------------------------------------------------------------

#ifndef RetirementH
#define RetirementH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Effects.hpp>
//---------------------------------------------------------------------------
class TRetirementForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonReturn;
	TImage *ImageBackground;
	TImage *ImageBelt1;
	TImage *ImageBelt2;
	TImage *ImageBelt3;
	TImage *ImageRikishi1;
	TGlowEffect *GlowEffectRikishi1;
	TImage *ImageRikishi2;
	TGlowEffect *GlowEffectRikishi2;
	TImage *ImageRikishi3;
	TGlowEffect *GlowEffectRikishi3;
	TImage *ImageYokozuna1;
	TImage *ImageYokozuna2;
	TImage *ImageYokozuna3;
	TImage *ImageWheelchair;
	void __fastcall ButtonReturnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TRetirementForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRetirementForm *RetirementForm;
//---------------------------------------------------------------------------
#endif
