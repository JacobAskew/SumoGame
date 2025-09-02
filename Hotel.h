//---------------------------------------------------------------------------

#ifndef HotelH
#define HotelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class THotelForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonReturn;
	TImage *ImageBackground;
	TImage *ImageBook;
	TImage *ImageFish;
	TImage *ImageHat;
	TImage *ImageDoormat;
	TImage *ImageMoney;
	TImage *ImagePinboard;
	TImage *ImageBlanket;
	void __fastcall ButtonReturnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THotelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THotelForm *HotelForm;
//---------------------------------------------------------------------------
#endif
