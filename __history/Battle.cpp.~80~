//---------------------------------------------------------------------------
#include <fmx.h>
#include <algorithm> // for std::swap
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
#include <Windows.h>
//---------------------------------------------------------------------------
#include "Battle.h"
#include "Dohyo.h"
#include "Street.h"
#include "Banzuke.h"
#include "Noboru.h"
#include "Training.h"
#include "Beya.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
//---------------------------------------------------------------------------
TBattleForm *BattleForm;
String ChatBoxPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\ChatBox_";
String WinnerPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\End_Left";
String WinnerPath2 = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\End_Right";
String TextBoxPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\TextBox.png";
String RingPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\Sumo_Ring.png";

int BattleStep = 0;

int TempSkillValue1 = 0;
int TempSkillValue2 = 0;
int TempSkillLimit1 = 0;
int TempSkillLimit2 = 0;
TAlphaColor TempSkillColor1 = TAlphaColorRec::Black;
TAlphaColor TempSkillColor2 = TAlphaColorRec::Black;

//int winner = -1;
//std::string TempSkillColor1 = "";
//std::string TempSkillColor2 = "";

struct Skill {
	const char* name;
	int value;
	int limit;
	TAlphaColor color;
};
//---------------------------------------------------------------------------


void TBattleForm::UpdateTempBoutValues(std::string InputBout1, std::string InputBout2) {
	if (InputBout1 == "Strength") {
		TempSkillValue1 = globalFighter1->strength;
		TempSkillLimit1 = globalFighter1->strengthLimit;
		TempSkillColor1 = TAlphaColorRec::Red;
	}
	else if (InputBout1 == "Weight") {
		TempSkillValue1 = globalFighter1->weight;
		TempSkillLimit1 = globalFighter1->weightLimit;
		TempSkillColor1 = TAlphaColorRec::Black;
	}
	else if (InputBout1 == "Technique") {
		TempSkillValue1 = globalFighter1->technique;
		TempSkillLimit1 = globalFighter1->techniqueLimit;
		TempSkillColor1 = TAlphaColorRec::Blue;
	}
	else if (InputBout1 == "Endurance") {
		TempSkillValue1 = globalFighter1->endurance;
		TempSkillLimit1 = globalFighter1->enduranceLimit;
		TempSkillColor1 = (TAlphaColor)0xFF00FF00;
	}
	else if (InputBout1 == "Speed") {
		TempSkillValue1 = globalFighter1->speed;
		TempSkillLimit1 = globalFighter1->speedLimit;
		TempSkillColor1 = TAlphaColorRec::Yellow;
	}

	if (InputBout2 == "Strength") {
		TempSkillValue2 = globalFighter2->strength;
		TempSkillLimit2 = globalFighter2->strengthLimit;
		TempSkillColor2 = TAlphaColorRec::Red;
	}
	else if (InputBout2 == "Weight") {
		TempSkillValue2 = globalFighter2->weight;
		TempSkillLimit2 = globalFighter2->weightLimit;
		TempSkillColor2 = TAlphaColorRec::Black;
	}
	else if (InputBout2 == "Technique") {
		TempSkillValue2 = globalFighter2->technique;
		TempSkillLimit2 = globalFighter2->techniqueLimit;
		TempSkillColor2 = TAlphaColorRec::Blue;
	}
	else if (InputBout2 == "Endurance") {
		TempSkillValue2 = globalFighter2->endurance;
		TempSkillLimit2 = globalFighter2->enduranceLimit;
		TempSkillColor2 = (TAlphaColor)0xFF00FF00;
	}
	else if (InputBout2 == "Speed") {
		TempSkillValue2 = globalFighter2->speed;
		TempSkillLimit2 = globalFighter2->speedLimit;
		TempSkillColor2 = TAlphaColorRec::Yellow;
	}
}

void SetupImages(Rikishi* fighter1, Rikishi* fighter2, TForm *form) {


	// Scenario 1: There are two computers and the player watches them battle
	// OR TWO PLAYERS SAME SAME, and auto-resolve
	// Scenario 2: There is one player and one cpu the player chooses actions
	// Scenario 3: Multiplayer (not set up yet)

	// Condition where PX is on the right and CPU is on the left
	if (AnsiString(fighter1->owner.c_str()) == "CPU" && AnsiString(fighter2->owner.c_str()) != "CPU") {
		std::swap(*globalFighter1, *globalFighter2);
	}

	// Update all of the images
	std::regex numRegex(R"(\d+)");

	TImage* imagering = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBackground"));
	AnsiString fullPathRing = RingPath;
	imagering->Bitmap->LoadFromFile(fullPathRing);

	// Update Fighter 1 images
	TImage* imageRikishi1 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageRikishi1"));
	if (!imageRikishi1) {
		ShowMessage("Error: ImageRikishi1 component not found.");
		return;
	}
	if (imageRikishi1) {
		AnsiString fullPath1 = RikishiPath + "_Behind.png";
		imageRikishi1->Bitmap->LoadFromFile(fullPath1);
	}
	TImage* imageBelt1 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBelt1"));
	if (imageBelt1) {
		AnsiString fullPathBelt1 = BeltPath + "_Behind.png";
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
	TImage* imageYokozuna1 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageYokozuna1"));
	if (imageYokozuna1) {
		imageYokozuna1->Visible = (fighter1->rank == "Yokozuna");
		if (fighter1->rank == "Yokozuna") {
			AnsiString fullPathYokozuna1 = YokozunaPath + "_Behind.png";
			imageYokozuna1->Bitmap->LoadFromFile(fullPathYokozuna1);
        }
	}
    // Update Fighter 2 images
	TImage* imageRikishi2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageRikishi2"));
	if (imageRikishi2) {
		AnsiString fullPath2 = RikishiPath + IntToStr(fighter2->spirit) + ".png";
		imageRikishi2->Bitmap->LoadFromFile(fullPath2);
	}
	TImage* imageBelt2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBelt2"));
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
	TImage* imageYokozuna2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageYokozuna2"));
	if (imageYokozuna2) {
		imageYokozuna2->Visible = (fighter2->rank == "Yokozuna");
		if (fighter2->rank == "Yokozuna") {
			AnsiString fullPathYokozuna2 = YokozunaPath + ".png";
			imageYokozuna2->Bitmap->LoadFromFile(fullPathYokozuna2);
		}
	}

	// Combat
	if (AnsiString(fighter1->owner.c_str()) == "CPU" && AnsiString(fighter2->owner.c_str()) == "CPU") {
		// AUTOBOTS Images
//		BattleForm->TextBattleQuestion->Visible=false;
		TImage* imagetext = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageTextBox"));
		AnsiString fullPathText = TextBoxPath;
		imagetext->Visible = false;

		Skill skills[] = {
			{"Weight", fighter1->weight, fighter1->weightLimit, TAlphaColorRec::Black},
			{"Endurance", fighter1->endurance, fighter1->enduranceLimit, (TAlphaColor)0xFF00FF00},
			{"Technique", fighter1->technique, fighter1->techniqueLimit, TAlphaColorRec::Blue},
			{"Speed", fighter1->speed, fighter1->speedLimit, TAlphaColorRec::Yellow},
			{"Strength", fighter1->strength, fighter1->strengthLimit, TAlphaColorRec::Red}
		};

		for (const Skill& skill : skills) {
			TImage* skillImage = dynamic_cast<TImage*>(form->FindComponent("Image" + AnsiString(skill.name) + "1"));
			if (skillImage) {
				AnsiString fullPathSkill = SkillPath + IntToStr(skill.value) + IntToStr(skill.limit) + ".png";
				skillImage->Bitmap->LoadFromFile(fullPathSkill);
				TintNoTransparent(skillImage->Bitmap, skill.color);
				skillImage->Visible = false;
			}
		}
	}
	else {
		// Player COMBAT Images
		TImage* imagetext = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageTextBox"));
		AnsiString fullPathText = TextBoxPath;
		imagetext->Bitmap->LoadFromFile(fullPathText);
		imagetext->Visible = true;
		// Load and tint skill images
		Skill skills[] = {
			{"Weight", fighter1->weight, fighter1->weightLimit, TAlphaColorRec::Black},
			{"Endurance", fighter1->endurance, fighter1->enduranceLimit, (TAlphaColor)0xFF00FF00},
			{"Technique", fighter1->technique, fighter1->techniqueLimit, TAlphaColorRec::Blue},
			{"Speed", fighter1->speed, fighter1->speedLimit, TAlphaColorRec::Yellow},
			{"Strength", fighter1->strength, fighter1->strengthLimit, TAlphaColorRec::Red}
		};

		for (const Skill& skill : skills) {
			TImage* skillImage = dynamic_cast<TImage*>(form->FindComponent("Image" + AnsiString(skill.name) + "1"));
			if (skillImage) {
				AnsiString fullPathSkill = SkillPath + IntToStr(skill.value) + IntToStr(skill.limit) + ".png";
				skillImage->Bitmap->LoadFromFile(fullPathSkill);
				TintNoTransparent(skillImage->Bitmap, skill.color);
				skillImage->Visible = true;
			}
		}

	}


}

//void __fastcall TBattleForm::Timer1Timer(TObject *Sender)
//{
//	switch (BattleStep)
//	{
//	case 0:
//		PopulateLeaderboardGrid();
//		AssignFightersFromGrid();
//		BattleStep++;
//		break;
//
//	case 1:
//		// Setup tactics and chat images
//		if (fighter1Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter1->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//		}
//		if (fighter2Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter2->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//		}
//
//		UpdateTempBoutValues(fighter1Tactic, fighter2Tactic);
//
//		// Text box 1
//		TImage* imagechat = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox1"));
//		AnsiString fullPathChat = ChatBoxPath + "1" + ".png";
//		imagechat->Bitmap->LoadFromFile(fullPathChat);
//		if (imagechat) {
//			imagechat->Visible = true;
//		}
//
//		BattleForm->TextChat1->Visible=true;
//		TImage* boutImage = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//		BattleForm->Timer1->Enabled = true;
//		// Text box 2
//
//		TImage* imagechat2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox2"));
//		AnsiString fullPathChat2 = ChatBoxPath + "2" + ".png";
//		imagechat2->Bitmap->LoadFromFile(fullPathChat2);
//		if (imagechat2) {
//			imagechat2->Visible = true;
//		}
//
//		BattleForm->TextChat2->Visible=true;
//		TImage* boutImage2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor1);
//			boutImage2->Visible = true;
//		}
//		//
//		BattleStep++;
//		break;
//
//	case 2:
//		GetBoutTactic();
//		FighterSkillValue(*globalFighter1, fighter1SkillValue);
//		FighterSkillValue(*globalFighter2, fighter2SkillValue);
//		BattleStep++;
//		break;
//
//	case 3:
//		UpdateTempBoutValues(boutTactic, boutTactic);
//
////		TImage* boutImage = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//
//		BattleForm->Timer1->Enabled = true;
//
////		TImage* boutImage2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor2);
//			boutImage2->Visible = true;
//		}
//
//
//		BattleStep++;
//		break;
//
//	case 4:
//		// Calculate results and injuries
//		fighter1Total = fighter1SkillValue;
//		HandleInjury(*globalFighter1, fighter1Total);
//
//		fighter2Total = fighter2SkillValue;
//		HandleInjury(*globalFighter2, fighter2Total);
//
//		// Show any injuries
//
//		//
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
//			Victory(0, players);
//		} else if (fighter1Total < fighter2Total) {
//			Victory(1, players);
//		} else {
//			if (globalFighter1->weight > globalFighter2->weight) {
//				Victory(0, players);
//			} else if (globalFighter1->weight < globalFighter2->weight) {
//				Victory(1, players);
//			} else {
//				if (globalFighter1->technique > globalFighter2->technique) {
//					Victory(0, players);
//				} else if (globalFighter1->technique < globalFighter2->technique) {
//					Victory(1, players);
//				} else {
//					winner = std::rand() % 2;
//					Victory(winner, players);
//				}
//			}
//		}
//
//		BattleStep++;
//		break;
//
//	case 5:
//		TImage* boutWinner = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame1"));
//		if (boutWinner) {
//			AnsiString fullPathWinner = WinnerPath + IntToStr(winner) + ".png";
//			boutWinner->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner->Visible = true;
//		}
//		TImage* boutWinner2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame2"));
//		if (boutWinner) {
//			AnsiString fullPathWinner = WinnerPath2 + IntToStr(winner) + ".png";
//			boutWinner2->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner2->Visible = true;
//		}
//		BattleStep++;
//		break;
//
//	case 6:
////		TImage* boutWinner = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame1"));
//		if (boutWinner) {
//			boutWinner->Visible = false;
//		}
////		TImage* boutWinner2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame2"));
//		if (boutWinner2) {
//			boutWinner2->Visible = false;
//		}
//		if (boutImage) {
//			boutImage->Visible = false;
//		}
//		if (boutImage2) {
//			boutImage2->Visible = false;
//		}
//		if (imagechat) {
//			imagechat->Visible = false;
//		}
//		if (imagechat2) {
//			imagechat2->Visible = false;
//		}
//		//
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
////		ShowMessage(IntToStr(currentBoutIndex));
//		currentBoutIndex++;
//		AssignFightersFromGrid();
////		BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
//		fighter1SkillValue = 0;
//		fighter2SkillValue = 0;
//		fighter1Tactic = "";
//		fighter2Tactic = "";
//		BattleStep++;
//		break;
//
//	case 7:
//		if (currentBoutIndex == 49)
//		{
//			EndBanzuke();
////			DohyoForm->Show();
////			this->Hide();
//		}
//		Timer1->Enabled = false; // Done
//		break;
//	}
//}
//
//void __fastcall TBattleForm::Timer1Timer(TObject *Sender)
//{
//	switch (BattleStep) {
//	case 0:
//		PopulateLeaderboardGrid();
//		AssignFightersFromGrid();
//		BattleStep++;
//		break;
//
//	case 1:
//		// Setup tactics and chat images
//		if (fighter1Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter1->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//		}
//		if (fighter2Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter2->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//		}
//
//		UpdateTempBoutValues(fighter1Tactic, fighter2Tactic);
//
//		// Text box 1
//		TImage* imagechat = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox1"));
//		AnsiString fullPathChat = ChatBoxPath + "1" + ".png";
//		imagechat->Bitmap->LoadFromFile(fullPathChat);
//		if (imagechat) {
//			imagechat->Visible = true;
//		}
//
//		BattleForm->TextChat1->Visible=true;
//		TImage* boutImage = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//
//		// Text box 2
//		TImage* imagechat2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox2"));
//		AnsiString fullPathChat2 = ChatBoxPath + "2" + ".png";
//		imagechat2->Bitmap->LoadFromFile(fullPathChat2);
//		if (imagechat2) {
//			imagechat2->Visible = true;
//		}
//
//		BattleForm->TextChat2->Visible=true;
//		TImage* boutImage2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic2"));
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor2);
//			boutImage2->Visible = true;
//		}
//		BattleStep++;
//		break;
//
//	case 2:
//		GetBoutTactic();
//		FighterSkillValue(*globalFighter1, fighter1SkillValue);
//		FighterSkillValue(*globalFighter2, fighter2SkillValue);
//		BattleStep++;
//		break;
//
//	case 3:
//		UpdateTempBoutValues(boutTactic, boutTactic);
//
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor2);
//			boutImage2->Visible = true;
//		}
//
//		BattleStep++;
//		break;
//
//	case 4:
//		// Calculate results and injuries
//		fighter1Total = fighter1SkillValue;
//		HandleInjury(*globalFighter1, fighter1Total);
//
//		fighter2Total = fighter2SkillValue;
//		HandleInjury(*globalFighter2, fighter2Total);
//
//		// Show any injuries
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
//			Victory(0, players);
//		} else if (fighter1Total < fighter2Total) {
//			Victory(1, players);
//		} else {
//			if (globalFighter1->weight > globalFighter2->weight) {
//				Victory(0, players);
//			} else if (globalFighter1->weight < globalFighter2->weight) {
//				Victory(1, players);
//			} else {
//				if (globalFighter1->technique > globalFighter2->technique) {
//					Victory(0, players);
//				} else if (globalFighter1->technique < globalFighter2->technique) {
//					Victory(1, players);
//				} else {
//					winner = std::rand() % 2;
//					Victory(winner, players);
//				}
//			}
//		}
//
//		BattleStep++;
//		break;
//
//	case 5:
//		// Display winner images
//		TImage* boutWinner = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame1"));
//		if (boutWinner) {
//			AnsiString fullPathWinner = WinnerPath + IntToStr(winner) + ".png";
//			boutWinner->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner->Visible = true;
//		}
//
//		TImage* boutWinner2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame2"));
//		if (boutWinner2) {
//			AnsiString fullPathWinner = WinnerPath2 + IntToStr(winner) + ".png";
//			boutWinner2->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner2->Visible = true;
//		}
//		BattleStep++;
//		break;
//
//	case 6:
//		// Hide images
//		if (boutWinner) {
//			boutWinner->Visible = false;
//		}
//		if (boutWinner2) {
//			boutWinner2->Visible = false;
//		}
//		if (boutImage) {
//			boutImage->Visible = false;
//		}
//		if (boutImage2) {
//			boutImage2->Visible = false;
//		}
//		if (imagechat) {
//			imagechat->Visible = false;
//		}
//		if (imagechat2) {
//			imagechat2->Visible = false;
//		}
//
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
//		currentBoutIndex++;
//		AssignFightersFromGrid();
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
//		fighter1SkillValue = 0;
//		fighter2SkillValue = 0;
//		fighter1Tactic = "";
//		fighter2Tactic = "";
//		BattleStep++;
//		break;
//
//	case 7:
//		if (currentBoutIndex == 49) {
//			EndBanzuke();
//		}
//		Timer1->Enabled = false; // Done
//		break;
//	}
//}


void __fastcall TBattleForm::Timer1Timer(TObject *Sender)
{
	switch (BattleStep) {
	default:
		Timer1->Enabled = false;
		break;
	case 0:
		Timer1->Enabled = false;
		PopulateLeaderboardGrid();
		AssignFightersFromGrid();
		BattleStep++;
		Timer1->Enabled = true;
		break;

	case 1:
		Timer1->Enabled = false;
		// Setup tactics and chat images
		if (fighter1Tactic.empty()) {
			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter1->name.c_str()) + ")"));
			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
		}
		if (fighter2Tactic.empty()) {
			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter2->name.c_str()) + ")"));
			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
		}

		UpdateTempBoutValues(fighter1Tactic, fighter2Tactic);

		// Update ImageChat and Bout Tactics
		LoadAndDisplayImage("ImageChatBox1", ChatBoxPath + "1.png");
		LoadAndDisplayImage("ImageChatBox2", ChatBoxPath + "2.png");

		BattleForm->TextChat1->Visible = true;
		BattleForm->TextChat2->Visible = true;

		UpdateBoutImage("ImageBoutTactic1", TempSkillValue1, TempSkillLimit1, TempSkillColor1);
		UpdateBoutImage("ImageBoutTactic2", TempSkillValue2, TempSkillLimit2, TempSkillColor2);

		BattleStep++;
		Timer1->Enabled = true;
		break;

	case 2:
		Timer1->Enabled = false;
		GetBoutTactic();
		FighterSkillValue(*globalFighter1, fighter1SkillValue);
		FighterSkillValue(*globalFighter2, fighter2SkillValue);
		BattleStep++;
		Timer1->Enabled = true;
		break;

	case 3:
		Timer1->Enabled = false;
		UpdateTempBoutValues(boutTactic, boutTactic);

		UpdateBoutImage("ImageBoutTactic1", TempSkillValue1, TempSkillLimit1, TempSkillColor1);
		UpdateBoutImage("ImageBoutTactic2", TempSkillValue2, TempSkillLimit2, TempSkillColor2);

		BattleStep++;
		Timer1->Enabled = true;
		break;

	case 4:
		// Calculate results and injuries
		Timer1->Enabled = false;
		fighter1Total = fighter1SkillValue;
		HandleInjury(*globalFighter1, fighter1Total);

		fighter2Total = fighter2SkillValue;
		HandleInjury(*globalFighter2, fighter2Total);

		// Adjust totals based on spirit
		AdjustTotalsForSpirit();

		// Adjust totals based on bout-specific conditions
		AdjustTotalsForBoutConditions();

		// Determine winner
		DetermineWinner();

		BattleStep++;
		Timer1->Enabled = true;
		break;

	case 5:
		// Display winner images
		Timer1->Enabled = false;
		DisplayWinnerImage("ImageEndGame1", WinnerPath, winner);
		DisplayWinnerImage("ImageEndGame2", WinnerPath2, winner);

		BattleStep++;
        Timer1->Enabled = true;
		break;

	case 6:
		// Hide images
		Timer1->Enabled = false;
		HideImage("ImageEndGame1");
		HideImage("ImageEndGame2");
		HideImage("ImageBoutTactic1");
		HideImage("ImageBoutTactic2");
		HideImage("ImageChatBox1");
		HideImage("ImageChatBox2");

		// Finalize bout
		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
		SetupImages(globalFighter1, globalFighter2, BattleForm);
		UpdateTournamentGrid();
		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
		ResetBattlePhase();
		if (currentBoutIndex == 49) {
			EndBanzuke();
		}
		Timer1->Enabled = false; // Done
		break;
	}
}

void TBattleForm::LoadAndDisplayImage(const AnsiString& imageName, const AnsiString& filePath)
{
	TImage* image = dynamic_cast<TImage*>(BattleForm->FindComponent(imageName));
	if (image) {
		if (FileExists(filePath)) {
			image->Bitmap->LoadFromFile(filePath);
			image->Visible = true;
		} else {
			ShowMessage("Error: " + filePath + " not found.");
		}
	}
}

void TBattleForm::UpdateBoutImage(const AnsiString& imageName, int skillValue, int skillLimit, TAlphaColor skillColor)
{
	TImage* image = dynamic_cast<TImage*>(BattleForm->FindComponent(imageName));
	if (image) {
		AnsiString filePath = SkillPath + IntToStr(skillValue) + IntToStr(skillLimit) + ".png";
		if (FileExists(filePath)) {
			image->Bitmap->LoadFromFile(filePath);
			TintNoTransparent(image->Bitmap, skillColor);
			image->Visible = true;
		} else {
			ShowMessage("Error: " + filePath + " not found.");
		}
	}
}

void TBattleForm::AdjustTotalsForSpirit()
{
	if (globalFighter1->spirit == 4) {
		fighter1Total += 1;
	}
	if (globalFighter2->spirit == 4) {
		fighter2Total += 1;
	}
}

void TBattleForm::AdjustTotalsForBoutConditions()
{
	if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
		if (globalFighter1->wins == 3 && globalFighter1->losses == 3) {
			fighter1Total += 1;
		}
		if (globalFighter2->wins == 3 && globalFighter2->losses == 3) {
			fighter2Total += 1;
		}
	}
}

void TBattleForm::DetermineWinner()
{
	if (fighter1Total > fighter2Total) {
		Victory(0, players);
	} else if (fighter1Total < fighter2Total) {
		Victory(1, players);
	} else {
		HandleTiebreaker();
	}
}

void TBattleForm::HandleTiebreaker()
{
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
			winner = std::rand() % 2;
			Victory(winner, players);
		}
	}
}

void TBattleForm::DisplayWinnerImage(const AnsiString& imageName, const AnsiString& path, int winner)
{
	TImage* image = dynamic_cast<TImage*>(BattleForm->FindComponent(imageName));
	if (image) {
		AnsiString filePath = path + IntToStr(winner) + ".png";
		if (FileExists(filePath)) {
			image->Bitmap->LoadFromFile(filePath);
			image->Visible = true;
		} else {
			ShowMessage("Error: " + filePath + " not found.");
		}
	}
}

void TBattleForm::HideImage(const AnsiString& imageName)
{
	TImage* image = dynamic_cast<TImage*>(BattleForm->FindComponent(imageName));
	if (image) {
		image->Visible = false;
	}
}

void TBattleForm::ResetBattlePhase()
{
	currentBoutIndex++;
	AssignFightersFromGrid();
	UpdateTournamentGrid();
	UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
	SetupImages(globalFighter1, globalFighter2, BattleForm);
	Application->ProcessMessages();
	fighter1SkillValue = 0;
	fighter2SkillValue = 0;
	fighter1Tactic = "";
	fighter2Tactic = "";
}



void SetupBattle() {

	SetupImages(globalFighter1, globalFighter2, BattleForm);

}

//---------------------------------------------------------------------------
__fastcall TBattleForm::TBattleForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//void __fastcall TBattleForm::ButtonFightClick(TObject *Sender)
//{
//	bool BeginFight = false;
//
//	// Ask the player if they want to see training results
//	TDialogService::MessageDialog("Begin the bout?!?! Are you sure?",
//		TMsgDlgType::mtConfirmation, TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo,
//		TMsgDlgBtn::mbNo, 0,
//		[&BeginFight](const TModalResult AResult) {
//			BeginFight = (AResult == mrYes);
//		});
//
//	if (isBanzukeComplete == false && isTrainingComplete == true) {
//
//		Timer1->Enabled = true;
//
//		if (fighter1Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter1->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//		}
//		if (fighter2Tactic.empty()) {
//			ShowMessage(AnsiString("Random Skill and Tactic Selected! (" + AnsiString(globalFighter2->name.c_str()) + ")"));
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//		}
//
//		// Show what bout tactic each fighter has chosen with a text box
//
//		UpdateTempBoutValues(fighter1Tactic, fighter2Tactic);
//
//		// Text box 1
//		TImage* imagechat = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox1"));
//		AnsiString fullPathChat = ChatBoxPath + "1" + ".png";
//		imagechat->Bitmap->LoadFromFile(fullPathChat);
//		if (imagechat) {
//			imagechat->Visible = true;
//		}
//
//		BattleForm->TextChat1->Visible=true;
//		TImage* boutImage = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//		BattleForm->Timer1->Enabled = true;
//		// Text box 2
//
//		TImage* imagechat2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageChatBox2"));
//		AnsiString fullPathChat2 = ChatBoxPath + "2" + ".png";
//		imagechat2->Bitmap->LoadFromFile(fullPathChat2);
//		if (imagechat2) {
//			imagechat2->Visible = true;
//		}
//
//		BattleForm->TextChat2->Visible=true;
//		TImage* boutImage2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor1);
//			boutImage2->Visible = true;
//		}
//		//
//
//		GetBoutTactic();
//		FighterSkillValue(*globalFighter1, fighter1SkillValue);
//		FighterSkillValue(*globalFighter2, fighter2SkillValue);
//
//		// Show what bout tactic each fighter will use given the initial picks
//
//		UpdateTempBoutValues(boutTactic, boutTactic);
//		BattleForm->Timer1->Enabled = true;
//
////		TImage* boutImage = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage->Bitmap, TempSkillColor1);
//			boutImage->Visible = true;
//		}
//
//		BattleForm->Timer1->Enabled = true;
//
////		TImage* boutImage2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageBoutTactic1"));
//		if (boutImage2) {
//			AnsiString fullPathSkill = SkillPath + IntToStr(TempSkillValue1) + IntToStr(TempSkillLimit1) + ".png";
//			boutImage2->Bitmap->LoadFromFile(fullPathSkill);
//			TintNoTransparent(boutImage2->Bitmap, TempSkillColor2);
//			boutImage2->Visible = true;
//		}
//
//
//
//		BattleForm->Timer1->Enabled = true;
//
//		//
//
//		fighter1Total = fighter1SkillValue;
//		HandleInjury(*globalFighter1, fighter1Total);
//
//		fighter2Total = fighter2SkillValue;
//		HandleInjury(*globalFighter2, fighter2Total);
//
//		// Show any injuries
//
//		//
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
//			Victory(0, players);
//		} else if (fighter1Total < fighter2Total) {
//			Victory(1, players);
//		} else {
//			if (globalFighter1->weight > globalFighter2->weight) {
//				Victory(0, players);
//			} else if (globalFighter1->weight < globalFighter2->weight) {
//				Victory(1, players);
//			} else {
//				if (globalFighter1->technique > globalFighter2->technique) {
//					Victory(0, players);
//				} else if (globalFighter1->technique < globalFighter2->technique) {
//					Victory(1, players);
//				} else {
//					winner = std::rand() % 2;
//					Victory(winner, players);
//				}
//			}
//		}
//
//		// Show the winner and the loser etc ...
//
//		BattleForm->Timer1->Enabled = true;
//		TImage* boutWinner = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame1"));
//		if (boutWinner) {
//			AnsiString fullPathWinner = WinnerPath + IntToStr(winner) + ".png";
//			boutWinner->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner->Visible = true;
//		}
//		TImage* boutWinner2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame2"));
//		if (boutWinner) {
//			AnsiString fullPathWinner = WinnerPath2 + IntToStr(winner) + ".png";
//			boutWinner2->Bitmap->LoadFromFile(fullPathWinner);
//			boutWinner2->Visible = true;
//		}
//
//
//		BattleForm->Timer3->Enabled = true;
//
//
////		TImage* boutWinner = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame1"));
//		if (boutWinner) {
//			boutWinner->Visible = false;
//		}
////		TImage* boutWinner2 = dynamic_cast<TImage*>(BattleForm->FindComponent("ImageEndGame2"));
//		if (boutWinner2) {
//			boutWinner2->Visible = false;
//		}
//		if (boutImage) {
//			boutImage->Visible = false;
//		}
//		if (boutImage2) {
//			boutImage2->Visible = false;
//		}
//		if (imagechat) {
//			imagechat->Visible = false;
//		}
//		if (imagechat2) {
//			imagechat2->Visible = false;
//		}
//		//
//
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
////		ShowMessage(IntToStr(currentBoutIndex));
//		currentBoutIndex++;
//		AssignFightersFromGrid();
////		BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
//		UpdateTournamentGrid();
//		UpdateDohyoGUI(globalFighter1, globalFighter2, DohyoForm);
//		SetupImages(globalFighter1, globalFighter2, BattleForm);
//		Application->ProcessMessages();
//		fighter1SkillValue = 0;
//		fighter2SkillValue = 0;
//		fighter1Tactic = "";
//		fighter2Tactic = "";
//
//		// Exit the Screen
////		DohyoForm->Show();
////		this->Hide();
//		//
//
//	}
//
//	if (currentBoutIndex == 49) {
////		BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
//		EndBanzuke();
//
//		// Exit the Screen
//		DohyoForm->Show();
//		this->Hide();
//		//
//	}
//    }
//}

void __fastcall TBattleForm::ButtonFightClick(TObject *Sender)
{
	// Ask the player if they want to begin the bout
	TDialogService::MessageDialog("Begin the bout?!?! Are you sure?",
		TMsgDlgType::mtConfirmation, TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo,
		TMsgDlgBtn::mbNo, 0,
		[this](const TModalResult AResult) {
			if (AResult == mrYes && isBanzukeComplete == false && isTrainingComplete) {
				// If the player clicked Yes and conditions are met, start the fight
                BattleStep = 0;
				Timer1->Enabled = true;
			}
		});
}


//---------------------------------------------------------------------------
void __fastcall TBattleForm::ImageWeight1Click(TObject *Sender)
{
	if (fighter1Tactic == "Weight") {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = 0;
		fighter1Tactic = "None";
	}
	else {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 0.2;
		BattleForm->ImageTechnique1->Opacity = 0.2;
		BattleForm->ImageSpeed1->Opacity = 0.2;
		BattleForm->ImageStrength1->Opacity = 0.2;
		fighter1SkillValue = globalFighter1->weight;
		fighter1Tactic = "Weight";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
}
//---------------------------------------------------------------------------
void __fastcall TBattleForm::ImageStrength1Click(TObject *Sender)
{
	if (fighter1Tactic == "Strength") {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = 0;
		fighter1Tactic = "None";
	}
	else {
		BattleForm->ImageWeight1->Opacity = 0.2;
		BattleForm->ImageEndurance1->Opacity = 0.2;
		BattleForm->ImageTechnique1->Opacity = 0.2;
		BattleForm->ImageSpeed1->Opacity = 0.2;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = globalFighter1->strength;
		fighter1Tactic = "Strength";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
}
//---------------------------------------------------------------------------
void __fastcall TBattleForm::ImageEndurance1Click(TObject *Sender)
{
	if (fighter1Tactic == "Endurance") {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = 0;
		fighter1Tactic = "None";
	}
	else {
		BattleForm->ImageWeight1->Opacity = 0.2;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 0.2;
		BattleForm->ImageSpeed1->Opacity = 0.2;
		BattleForm->ImageStrength1->Opacity = 0.2;
		fighter1SkillValue = globalFighter1->endurance;
		fighter1Tactic = "Endurance";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
}
//---------------------------------------------------------------------------
void __fastcall TBattleForm::ImageTechnique1Click(TObject *Sender)
{
	if (fighter1Tactic == "Technique") {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = 0;
		fighter1Tactic = "None";
	}
	else {
		BattleForm->ImageWeight1->Opacity = 0.2;
		BattleForm->ImageEndurance1->Opacity = 0.2;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 0.2;
		BattleForm->ImageStrength1->Opacity = 0.2;
		fighter1SkillValue = globalFighter1->technique;
		fighter1Tactic = "Technique";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
}
//---------------------------------------------------------------------------
void __fastcall TBattleForm::ImageSpeed1Click(TObject *Sender)
{
	if (fighter1Tactic == "Speed") {
		BattleForm->ImageWeight1->Opacity = 1.0;
		BattleForm->ImageEndurance1->Opacity = 1.0;
		BattleForm->ImageTechnique1->Opacity = 1.0;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 1.0;
		fighter1SkillValue = 0;
		fighter1Tactic = "None";
	}
	else {
		BattleForm->ImageWeight1->Opacity = 0.2;
		BattleForm->ImageEndurance1->Opacity = 0.2;
		BattleForm->ImageTechnique1->Opacity = 0.2;
		BattleForm->ImageSpeed1->Opacity = 1.0;
		BattleForm->ImageStrength1->Opacity = 0.2;
		fighter1SkillValue = globalFighter1->speed;
		fighter1Tactic = "Speed";
		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
	}
}
//---------------------------------------------------------------------------
void __fastcall TBattleForm::ButtonBackClick(TObject *Sender)
{
	DohyoForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
