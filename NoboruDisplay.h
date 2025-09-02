//---------------------------------------------------------------------------

#ifndef NoboruDisplayH
#define NoboruDisplayH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Effects.hpp>
//---------------------------------------------------------------------------
class TNoboruDisplayForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonReturn;
	TImage *ImageBelt1;
	TImage *ImageBelt2;
	TImage *ImageBelt3;
	TImage *ImageRikishi1;
	TImage *ImageRikishi2;
	TImage *ImageRikishi3;
	TImage *ImageYokozuna1;
	TImage *ImageYokozuna2;
	TImage *ImageYokozuna3;
	TImage *ImageRikishi4;
	TImage *ImageBelt4;
	TImage *ImageYokozuna4;
	TImage *ImageRikishi6;
	TImage *ImageBelt6;
	TImage *ImageYokozuna6;
	TImage *ImageRikishi7;
	TImage *ImageBelt7;
	TImage *ImageYokozuna7;
	TImage *ImageRikishi8;
	TImage *ImageBelt8;
	TImage *ImageYokozuna8;
	TImage *ImageRikishi5;
	TImage *ImageYokozuna5;
	TImage *ImageBelt5;
	TImage *ImageYokozuna9;
	TImage *ImageBelt9;
	TImage *ImageRikishi9;
	TImage *ImageRikishi10;
	TImage *ImageBelt10;
	TImage *ImageYokozuna10;
	TImage *ImageRikishi11;
	TImage *ImageBelt11;
	TImage *ImageYokozuna11;
	TImage *ImageRikishi12;
	TImage *ImageBelt12;
	TImage *ImageYokozuna12;
	TImage *ImageRikishi13;
	TImage *ImageBelt13;
	TImage *ImageYokozuna13;
	TImage *ImageRikishi14;
	TImage *ImageBelt14;
	TImage *ImageYokozuna14;
	TImage *ImageRikishi15;
	TImage *ImageBelt15;
	TImage *ImageYokozuna15;
	TImage *ImageRikishi16;
	TImage *ImageBelt16;
	TImage *ImageYokozuna16;
	TImage *ImageRikishi;
	TImage *ImageBelt;
	TImage *ImageYokozuna;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TRectangle *Rectangle3;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TRectangle *Rectangle6;
	TRectangle *Rectangle7;
	TRectangle *Rectangle8;
	TRectangle *Rectangle9;
	TRectangle *Rectangle10;
	TRectangle *Rectangle11;
	TRectangle *Rectangle12;
	TRectangle *Rectangle13;
	TRectangle *Rectangle14;
	TRectangle *Rectangle15;
	TRectangle *Rectangle16;
	void __fastcall ButtonReturnClick(TObject *Sender);
//	void __fastcall ImageRikishi5Click(TObject *Sender);
//	void __fastcall ImageYokozuna5Click(TObject *Sender);
	void __fastcall SharedYokozunaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TNoboruDisplayForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNoboruDisplayForm *NoboruDisplayForm;
extern void SetupNoboruDisplay();
//---------------------------------------------------------------------------
#endif
