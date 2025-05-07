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
//---------------------------------------------------------------------------
class TRetirementForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonReturn;
	void __fastcall ButtonReturnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TRetirementForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRetirementForm *RetirementForm;
//---------------------------------------------------------------------------
#endif
