//---------------------------------------------------------------------------
#include <fmx.h>
#include <FMX.Dialogs.hpp>
#include <System.UITypes.hpp>  // For colors
#include <map>  // If you still want to use maps
#include <FMX.DialogService.hpp> // Required for TDialogService
#include <FMX.Graphics.hpp>   // For TBitmap
#include <System.SysUtils.hpp>  // Required for UnicodeString conversion
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <random>
//---------------------------------------------------------------------------
#include "Dohyo.h"
#include "Street.h"
#include "Banzuke.h"
#include "Noboru.h"
#include "Training.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
TDohyoForm *DohyoForm;
//---------------------------------------------------------------------------
String VSPath2 = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\Vs.png";
String ArenaPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\temp_arena.png";
//---------------------------------------------------------------------------
void UpdateDohyoGUI(Rikishi* fighter1, Rikishi* fighter2, TForm *form)
{
	// Update all of the stats and buttons
	// Fighter 1
	DohyoForm->ButtonWeight1->Text = "Weight: " + IntToStr(fighter1->weight);
	DohyoForm->ButtonEndurance1->Text = "Endurance: " + IntToStr(fighter1->endurance);
	DohyoForm->ButtonTechnique1->Text = "Technique: " + IntToStr(fighter1->technique);
	DohyoForm->ButtonSpeed1->Text = "Speed: " + IntToStr(fighter1->speed);
	DohyoForm->ButtonStrength1->Text = "Strength: " + IntToStr(fighter1->strength);
	DohyoForm->EditAge1->Text = "Age: " + IntToStr(fighter1->age);
	DohyoForm->EditSpirit1->Text = "Spirit: " + IntToStr(fighter1->spirit);
	DohyoForm->EditOwner1->Text = AnsiString("Owner: " + AnsiString(fighter1->owner.c_str()));
	DohyoForm->EditRank1->Text = AnsiString("Rank: " + AnsiString(fighter1->rank.c_str()));
	DohyoForm->EditFighter1->Text = AnsiString(fighter1->name.c_str());
	DohyoForm->EditRecord1->Text = "Standing: " + IntToStr(fighter1->wins) + " / " + IntToStr(fighter1->losses);
	// Fighter 2
	DohyoForm->ButtonWeight2->Text = "Weight: " + IntToStr(fighter2->weight);
	DohyoForm->ButtonEndurance2->Text = "Endurance: " + IntToStr(fighter2->endurance);
	DohyoForm->ButtonTechnique2->Text = "Technique: " + IntToStr(fighter2->technique);
	DohyoForm->ButtonSpeed2->Text = "Speed: " + IntToStr(fighter2->speed);
	DohyoForm->ButtonStrength2->Text = "Strength: " + IntToStr(fighter2->strength);
	DohyoForm->EditAge2->Text = "Age: " + IntToStr(fighter2->age);
	DohyoForm->EditSpirit2->Text = "Spirit: " + IntToStr(fighter2->spirit);
	DohyoForm->EditOwner2->Text = AnsiString("Owner: " + AnsiString(fighter2->owner.c_str()));
	DohyoForm->EditRank2->Text = AnsiString("Rank: " + AnsiString(fighter2->rank.c_str()));
	DohyoForm->EditFighter2->Text = AnsiString(fighter2->name.c_str());
	DohyoForm->EditRecord2->Text = "Standing: " + IntToStr(fighter2->wins) + " / " + IntToStr(fighter2->losses);

	// Update all of the images
	std::regex numRegex(R"(\d+)");
	// VS symbol
	TImage* imagevs = dynamic_cast<TImage*>(form->FindComponent("ImageVS"));
	AnsiString fullPathVS = VSPath2;
	imagevs->Bitmap->LoadFromFile(fullPathVS);
	// Arena
	TImage* imagearena = dynamic_cast<TImage*>(form->FindComponent("ImageArena"));
	AnsiString fullPathArena = ArenaPath;
	imagearena->Bitmap->LoadFromFile(fullPathArena);
	// Update Fighter 1 images
	TImage* imageRikishi1 = dynamic_cast<TImage*>(form->FindComponent("ImageRikishi1"));
	if (!imageRikishi1) {
		ShowMessage("Error: ImageRikishi1 component not found.");
		return;
	}
	if (imageRikishi1) {
		AnsiString fullPath1 = RikishiPath + IntToStr(fighter1->spirit) + ".png";
		imageRikishi1->Bitmap->LoadFromFile(fullPath1);
	}
	TImage* imageBelt1 = dynamic_cast<TImage*>(form->FindComponent("ImageBelt1"));
    if (imageBelt1) {
        AnsiString fullPathBelt1 = BeltPath + ".png";
        imageBelt1->Bitmap->LoadFromFile(fullPathBelt1);

		std::string colorStr1 = AnsiString(fighter1->colour).c_str();
		std::smatch match1;
//        std::regex numRegex(R"(\d+)");
        if (std::regex_search(colorStr1, match1, numRegex)) {
            UnicodeString extractedNumber1 = UnicodeString(match1.str().c_str());
            TAlphaColor color1 = (TAlphaColor)StrToUInt(extractedNumber1);
            TintNoTransparent(imageBelt1->Bitmap, color1);
        } else {
			ShowMessage("Invalid color format: " + fighter1->colour);
        }
    }
	TImage* imageYokozuna1 = dynamic_cast<TImage*>(form->FindComponent("ImageYokozuna1"));
    if (imageYokozuna1) {
		imageYokozuna1->Visible = (fighter1->rank == "Yokozuna");
		if (fighter1->rank == "Yokozuna") {
			AnsiString fullPathYokozuna1 = YokozunaPath + ".png";
            imageYokozuna1->Bitmap->LoadFromFile(fullPathYokozuna1);
        }
	}
    // Update Fighter 2 images
	TImage* imageRikishi2 = dynamic_cast<TImage*>(form->FindComponent("ImageRikishi2"));
	if (imageRikishi2) {
		AnsiString fullPath2 = RikishiPath + IntToStr(fighter2->spirit) + ".png";
		imageRikishi2->Bitmap->LoadFromFile(fullPath2);
	}
	TImage* imageBelt2 = dynamic_cast<TImage*>(form->FindComponent("ImageBelt2"));
	if (imageBelt2) {
		AnsiString fullPathBelt2 = BeltPath + ".png";
        imageBelt2->Bitmap->LoadFromFile(fullPathBelt2);

		std::string colorStr2 = AnsiString(fighter2->colour).c_str();
		std::smatch match2;
        if (std::regex_search(colorStr2, match2, numRegex)) {
            UnicodeString extractedNumber2 = UnicodeString(match2.str().c_str());
            TAlphaColor color2 = (TAlphaColor)StrToUInt(extractedNumber2);
			TintNoTransparent(imageBelt2->Bitmap, color2);
		} else {
			ShowMessage("Invalid color format: " + fighter2->colour);
		}
	}
	TImage* imageYokozuna2 = dynamic_cast<TImage*>(form->FindComponent("ImageYokozuna2"));
	if (imageYokozuna2) {
		imageYokozuna2->Visible = (fighter2->rank == "Yokozuna");
		if (fighter2->rank == "Yokozuna") {
			AnsiString fullPathYokozuna2 = YokozunaPath + ".png";
			imageYokozuna2->Bitmap->LoadFromFile(fullPathYokozuna2);
		}
	}
}

//---------------------------------------------------------------------------
void TDohyoForm::DohyoSetup(){
	UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
}
//---------------------------------------------------------------------------
void __fastcall TDohyoForm::ButtonReturnBanzukeClick(TObject *Sender)
{
	BanzukeForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TDohyoForm::ButtonReturnStreetClick(TObject *Sender)
{
	MainStreet->Show();
	this->Hide();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TDohyoForm::TDohyoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonWeight1Click(TObject *Sender)
{
	if (globalFighter1->owner == "P1" && globalFighter2->owner != "P1") {
		fighter1SkillValue = globalFighter1->weight;
		fighter1Tactic = "Weight";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonEndurance1Click(TObject *Sender)
{
	if (globalFighter1->owner == "P1" && globalFighter2->owner != "P1") {
		fighter1SkillValue = globalFighter1->endurance;
		fighter1Tactic = "Endurance";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonTechnique1Click(TObject *Sender)
{
	if (globalFighter1->owner == "P1" && globalFighter2->owner != "P1") {
		fighter1SkillValue = globalFighter1->technique;
		fighter1Tactic = "Technique";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonSpeed1Click(TObject *Sender)
{
	if (globalFighter1->owner == "P1" && globalFighter2->owner != "P1") {
		fighter1SkillValue = globalFighter1->speed;
		fighter1Tactic = "Speed";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonStrength1Click(TObject *Sender)
{
	if (globalFighter1->owner == "P1" && globalFighter2->owner != "P1") {
		fighter1SkillValue = globalFighter1->strength;
		fighter1Tactic = "Strength";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonWeight2Click(TObject *Sender)
{
	if (globalFighter2->owner == "P1" && globalFighter1->owner != "P1") {
		fighter2SkillValue = globalFighter2->weight;
		fighter2Tactic = "Weight";
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonEndurance2Click(TObject *Sender)
{
	if (globalFighter2->owner == "P1" && globalFighter1->owner != "P1") {
		fighter2SkillValue = globalFighter2->endurance;
		fighter2Tactic = "Endurance";
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonTechnique2Click(TObject *Sender)
{
	if (globalFighter2->owner == "P1" && globalFighter1->owner != "P1") {
		fighter2SkillValue = globalFighter2->technique;
		fighter2Tactic = "Technique";
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonSpeed2Click(TObject *Sender)
{
	if (globalFighter2->owner == "P1" && globalFighter1->owner != "P1") {
		fighter2SkillValue = globalFighter2->speed;
		fighter2Tactic = "Speed";
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonStrength2Click(TObject *Sender)
{
	if (globalFighter2->owner == "P1" && globalFighter1->owner != "P1") {
		fighter2SkillValue = globalFighter2->strength;
		fighter2Tactic = "Strength";
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
	}
	else if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		ShowMessage("You own both Rikishi!");
	}
	else {
		ShowMessage("You do not own this Rikishi!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonFightClick(TObject *Sender)
{
	bool BeginFight = false;

	// Ask the player if they want to see training results
	TDialogService::MessageDialog("Begin the bout?!?! Are you sure?",
		TMsgDlgType::mtConfirmation, TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo,
		TMsgDlgBtn::mbNo, 0,
		[&BeginFight](const TModalResult AResult) {
			BeginFight = (AResult == mrYes);
		});

	if (isBanzukeComplete == false && isTrainingComplete == true) {
		PopulateLeaderboardGrid();
		AssignFightersFromGrid();

		if (fighter1Tactic.empty()) {
			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter1->name.c_str()) + ")"));
			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		}
		if (fighter2Tactic.empty()) {
			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter2->name.c_str()) + ")"));
			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		}

		GetBoutTactic();
		FighterSkillValue(*globalFighter1, fighter1SkillValue);
		FighterSkillValue(*globalFighter2, fighter2SkillValue);

		fighter1Total = fighter1SkillValue;
		HandleInjury(*globalFighter1, fighter1Total);

		fighter2Total = fighter2SkillValue;
		HandleInjury(*globalFighter2, fighter2Total);

		if (globalFighter1->spirit == 4) {
			fighter1Total += 1;
		}
		if (globalFighter2->spirit == 4) {
			fighter2Total += 1;
		}

		if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
			if (globalFighter1->wins == 3 && globalFighter1->losses == 3) {
				fighter1Total += 1;
			}
			if (globalFighter2->wins == 3 && globalFighter2->losses == 3) {
				fighter2Total += 1;
			}
		}

		if (fighter1Total > fighter2Total) {
			Victory(0, players);
		} else if (fighter1Total < fighter2Total) {
			Victory(1, players);
		} else {
			if (globalFighter1->weight > globalFighter2->weight) {
				Victory(0, players);
			} else if (globalFighter1->weight < globalFighter2->weight) {
				Victory(1, players);
			} else {
				if (globalFighter1->technique > globalFighter2->technique) {
					Victory(0, players);
				} else if (globalFighter1->technique < globalFighter2->technique) {
					Victory(1, players);
				} else {
					int winner = std::rand() % 2;
					Victory(winner, players);
				}
			}
		}

		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
		UpdateTournamentGrid();
//		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
		Application->ProcessMessages();
//		ShowMessage(IntToStr(currentBoutIndex));
		currentBoutIndex++;
        AssignFightersFromGrid();
//		BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
		UpdateTournamentGrid();
//		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
		Application->ProcessMessages();
		fighter1SkillValue = 0;
		fighter2SkillValue = 0;
		fighter1Tactic = "";
		fighter2Tactic = "";
	}

	if (currentBoutIndex == 49) {
//		BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
		EndBanzuke();
	}

//	else {
//		if (BeginFight) {
//			ShowMessage("The training phase is not complete. The sumo are not ready.");
//		}
//	}

//	if (isBanzukeComplete == false && isTrainingComplete == true && BeginFight == true && currentBoutIndex != 49) {
//
//		PopulateLeaderboardGrid();
//
//		AssignFightersFromGrid();
//
//		if (globalFighter1->wins > 7 || globalFighter1->wins < 0) {
//			ShowMessage("Error: rikishi.wins has an invalid value: " + IntToStr(globalFighter1->wins));
//		}
//		if (globalFighter1->losses > 7 || globalFighter1->losses < 0) {
//			ShowMessage("Error: rikishi.losses has an invalid value: " + IntToStr(globalFighter1->losses));
//		}
//		if (globalFighter2->wins > 7 || globalFighter2->wins < 0) {
//			ShowMessage("Error: rikishi.wins has an invalid value: " + IntToStr(globalFighter2->wins));
//		}
//		if (globalFighter2->losses > 7 || globalFighter2->losses < 0) {
//			ShowMessage("Error: rikishi.losses has an invalid value: " + IntToStr(globalFighter2->losses));
//		}
//
//		if (fighter1Tactic.empty()) {
//			ShowMessage("Random Skill and Tactic Selected! (Rikishi 1)");
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//		}
//		if (fighter2Tactic.empty()) {
//			ShowMessage("Random Skill and Tactic Selected! (Rikishi 2)");
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//		}
//
//		GetBoutTactic();
//		FighterSkillValue(*globalFighter1, fighter1SkillValue);
//		FighterSkillValue(*globalFighter2, fighter2SkillValue);
//
//		fighter1Total = fighter1SkillValue;
//		HandleInjury(*globalFighter1, fighter1Total);
//
//		fighter2Total = fighter2SkillValue;
//		HandleInjury(*globalFighter2, fighter2Total);
//
//		if (globalFighter1->spirit == 4) {
//			fighter1Total += 1;
//		}
//		if (globalFighter2->spirit == 4) {
//			fighter2Total += 1;
//		}
//
//		if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
//			if (globalFighter1->wins == 3 && globalFighter1->losses == 3) {
//				fighter1Total += 1;
//			}
//			if (globalFighter2->wins == 3 && globalFighter2->losses == 3) {
//				fighter2Total += 1;
//			}
//		}
//
//		if (fighter1Total > fighter2Total) {
//			Victory(0);
//		} else if (fighter1Total < fighter2Total) {
//			Victory(1);
//		} else {
//			if (globalFighter1->weight > globalFighter2->weight) {
//				Victory(0);
//			} else if (globalFighter1->weight < globalFighter2->weight) {
//				Victory(1);
//			} else {
//				if (globalFighter1->technique > globalFighter2->technique) {
//					Victory(0);
//				} else if (globalFighter1->technique < globalFighter2->technique) {
//					Victory(1);
//				} else {
//					int winner = std::rand() % 2;
//					Victory(winner);
//				}
//			}
//		}
//        UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		PopulateLeaderboardGrid();
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		UpdateTournamentGrid();
//		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//		Application->ProcessMessages();
//		currentBoutIndex++;
//		BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
//	}
//	else if (currentBoutIndex == 49) {
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		PopulateLeaderboardGrid();
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		UpdateTournamentGrid();
//		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//		BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
//		EndBanzuke();
//	}
}
//---------------------------------------------------------------------------

void __fastcall TDohyoForm::ButtonNextPlayerBoutClick(TObject *Sender)
{

	PopulateLeaderboardGrid();

	for (int i = 0; i < 49; i++) {
		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
		if (isBanzukeComplete == false && isTrainingComplete == true && currentBoutIndex != 49) {


			AssignFightersFromGrid();

			if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
//				ShowMessage("Both sumo are owned by the same player, automatically resolving the bout!");
			}
			else if (globalFighter1->owner == "P1" || globalFighter2->owner == "P1") {
				ShowMessage("The current bout features one of your sumo! Get ready for battle!");
				break;
			}
			else {
//				ShowMessage("Neither sumo are owned by the same player, automatically resolving the bout!");
			}

			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
			RandomSkillForFighter(*globalFighter2, fighter2Tactic);

			GetBoutTactic();
			FighterSkillValue(*globalFighter1, fighter1SkillValue);
			FighterSkillValue(*globalFighter2, fighter2SkillValue);

			fighter1Total = fighter1SkillValue;
			HandleInjury(*globalFighter1, fighter1Total);

			fighter2Total = fighter2SkillValue;
			HandleInjury(*globalFighter2, fighter2Total);

			if (globalFighter1->spirit == 4) {
				fighter1Total += 1;
			}
			if (globalFighter2->spirit == 4) {
				fighter2Total += 1;
			}

			if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
				if (globalFighter1->wins == 3 && globalFighter1->losses == 3) {
					fighter1Total += 1;
				}
				if (globalFighter2->wins == 3 && globalFighter2->losses == 3) {
					fighter2Total += 1;
				}
			}

			if (fighter1Total > fighter2Total) {
				Victory(0, players);
			} else if (fighter1Total < fighter2Total) {
				Victory(1, players);
			} else {
				if (globalFighter1->weight > globalFighter2->weight) {
					Victory(0, players);
				} else if (globalFighter1->weight < globalFighter2->weight) {
					Victory(1, players);
				} else {
					if (globalFighter1->technique > globalFighter2->technique) {
						Victory(0, players);
					} else if (globalFighter1->technique < globalFighter2->technique) {
						Victory(1, players);
					} else {
						int winner = std::rand() % 2;
						Victory(winner, players);
					}
				}
			}

			PopulateLeaderboardGrid();
			SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
			UpdateTournamentGrid();
//			UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
			Application->ProcessMessages();
			currentBoutIndex++;
			AssignFightersFromGrid();
//			BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
			UpdateTournamentGrid();
			PopulateLeaderboardGrid();
			if (currentBoutIndex == 49) {
//				BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
				PopulateLeaderboardGrid();
				EndBanzuke();
				break;
			}

		}
		else if (currentBoutIndex == 49) {
//			BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
			PopulateLeaderboardGrid();
			EndBanzuke();
			break;
		}
		else {
			ShowMessage("The training phase is not complete. The sumo are not ready.");
            break;
		}
	}
}
//---------------------------------------------------------------------------

