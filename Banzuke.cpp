//---------------------------------------------------------------------------
#include <fmx.h>
#include <FMX.Dialogs.hpp>
#include <System.UITypes.hpp>  // For colors
#include <FMX.DialogService.hpp> // Required for TDialogService
#include <map>  // If you still want to use maps
#include <FMX.Graphics.hpp>   // For TBitmap
#include <System.SysUtils.hpp>  // Required for UnicodeString conversion
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <random>
//---------------------------------------------------------------------------
#include "Banzuke.h"
#include "Street.h"
#include "Noboru.h"
#include "Beya.h"
#include "Dohyo.h"
#include "NoboruDisplay.h"
#include "Newspaper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma hdrstop
//---------------------------------------------------------------------------
TBanzukeForm *BanzukeForm;

//---------------------------------------------------------------------------
__fastcall TBanzukeForm::TBanzukeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBanzukeForm::ButtonReturnStreetClick(TObject *Sender)
{
	MainStreet->Show(); // Show the main form
	this->Hide();     // Hide the second form
}
//---------------------------------------------------------------------------
void __fastcall TBanzukeForm::ButtonNewspaperClick(TObject *Sender)
{
	NewspaperForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TBanzukeForm::ButtonBanzukeClick(TObject *Sender)
{
	SetupNoboruDisplay();
	NoboruDisplayForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

//void __fastcall TBanzukeForm::ButtonDohyoClick(TObject *Sender)
//{
//	if (isTrainingComplete) {
//		DohyoForm->Show(); // Show the main form
//		DohyoForm->DohyoSetup();
//		this->Hide();     // Hide the second form
//	}
//	else {
//		ShowMessage("The Dohyo is not open yet! Come back Later!");
//	}
//}
////---------------------------------------------------------------------------
//void __fastcall TBanzukeForm::ButtonBanzukeClick(TObject *Sender)
//{
//	NoboruDisplayForm->Show();
//	this->Hide();
//}

//String VSPath = "C:\\Users\\zx123\\OneDrive\\Documents\\Embarcadero\\Studio\\Projects\\Images\\Vs.png";





//std::map<int, std::pair<int, int>> currentBoutResults; // Maps bout index to (winnerIdx, loserIdx)
//int currentBoutIndex = 0;  // The index of the current bout (for cyan highlighting)



//void PopulateLeaderboardGrid() {
//	// Create a copy of rikishiVector for sorting (leaves the original unchanged)
//    std::vector<Rikishi> sortedRikishi = rikishiVector;
//
//	// Sort the copy by wins in descending order
//	std::sort(sortedRikishi.begin(), sortedRikishi.end(), [](const Rikishi& a, const Rikishi& b) {
//		return a.wins > b.wins;
//	});
//
//	// Populate the grid with the sorted data
//	for (int x = 0; x < 14; ++x) {
//		if (x < sortedRikishi.size()) {
//			std::string fullRank = sortedRikishi[x].rank; // Get full rank
//			std::string shortRank; // Will store the extracted rank
//
//			if (!fullRank.empty()) {
//				shortRank += fullRank[0]; // Always take the first character
//
//				// Check if the last character is a digit
//				if (std::isdigit(fullRank.back())) {
//					// Find the last space to extract the full number
//					size_t lastSpace = fullRank.find_last_of(' ');
//					if (lastSpace != std::string::npos) {
//						shortRank += fullRank.substr(lastSpace + 1); // Append the full number
//					} else {
//                        shortRank += fullRank.back(); // Default case if no space is found
//					}
//				}
//			}
//
//            // Convert to AnsiString if needed
//            AnsiString ansiShortRank = AnsiString(shortRank.c_str());
//
//            // Combine the name, wins, and losses in a single string for each rikishi
//            AnsiString fighterInfo = ansiShortRank + ":" +
//                                     AnsiString(sortedRikishi[x].name.c_str()) + " (" +
//                                     AnsiString(sortedRikishi[x].wins) + " / " +
//                                     AnsiString(sortedRikishi[x].losses) + ")";
//
//			// Determine the column based on the index (0 for first 7, 1 for next 7)
//			int column = (x < 7) ? 0 : 1;
//			int row = x % 7;  // Row index is 0-6 for both columns
//
//			// Fill the grid cell with the combined string
////            BanzukeForm->StringGridLeaderboard->Cells[column][row] = fighterInfo;
//		} else {
//			// In case there are fewer than 14 rikishi, clear the remaining cells
////            BanzukeForm->StringGridLeaderboard->Cells[0][x] = "";
////            BanzukeForm->StringGridLeaderboard->Cells[1][x] = "";
//		}
//	}
//}



//void UpdateBoutGUI(Rikishi* fighter1, Rikishi* fighter2, TForm *form)
//{
//
//	std::regex numRegex(R"(\d+)");
//    // Update Fighter 1 images
//	TImage* imageFighter1 = dynamic_cast<TImage*>(form->FindComponent("ImageRikishi1"));
//	if (!imageFighter1) {
//		ShowMessage("Error: ImageRikishi1 component not found.");
//		return;
//	}
//	if (imageFighter1) {
//		AnsiString fullPath1 = RikishiPath + IntToStr(fighter1->spirit) + ".png";
//		imageFighter1->Bitmap->LoadFromFile(fullPath1);
//	}
//
//    TImage* imageBelt1 = dynamic_cast<TImage*>(form->FindComponent("ImageBelt1"));
//    if (imageBelt1) {
//        AnsiString fullPathBelt1 = BeltPath + ".png";
//        imageBelt1->Bitmap->LoadFromFile(fullPathBelt1);
//
//		std::string colorStr1 = AnsiString(fighter1->colour).c_str();
//		std::smatch match1;
////        std::regex numRegex(R"(\d+)");
//        if (std::regex_search(colorStr1, match1, numRegex)) {
//            UnicodeString extractedNumber1 = UnicodeString(match1.str().c_str());
//            TAlphaColor color1 = (TAlphaColor)StrToUInt(extractedNumber1);
//            TintNoTransparent(imageBelt1->Bitmap, color1);
//        } else {
//			ShowMessage("Invalid color format: " + fighter1->colour);
//        }
//    }
//
//    TImage* imageYokozuna1 = dynamic_cast<TImage*>(form->FindComponent("ImageYokozuna1"));
//    if (imageYokozuna1) {
//		imageYokozuna1->Visible = (fighter1->rank == "Yokozuna");
//		if (fighter1->rank == "Yokozuna") {
//			AnsiString fullPathYokozuna1 = YokozunaPath + ".png";
//            imageYokozuna1->Bitmap->LoadFromFile(fullPathYokozuna1);
//        }
//    }
//
//    // Update Fighter 2 images
//	TImage* imageFighter2 = dynamic_cast<TImage*>(form->FindComponent("ImageRikishi2"));
//    if (imageFighter2) {
//		AnsiString fullPath2 = RikishiPath + IntToStr(fighter2->spirit) + ".png";
//        imageFighter2->Bitmap->LoadFromFile(fullPath2);
//	}

//    TImage* imageBelt2 = dynamic_cast<TImage*>(form->FindComponent("ImageBelt2"));
//	if (imageBelt2) {
//		AnsiString fullPathBelt2 = BeltPath + ".png";
//        imageBelt2->Bitmap->LoadFromFile(fullPathBelt2);
//
//		std::string colorStr2 = AnsiString(fighter2->colour).c_str();
//		std::smatch match2;
//        if (std::regex_search(colorStr2, match2, numRegex)) {
//            UnicodeString extractedNumber2 = UnicodeString(match2.str().c_str());
//            TAlphaColor color2 = (TAlphaColor)StrToUInt(extractedNumber2);
//			TintNoTransparent(imageBelt2->Bitmap, color2);
//		} else {
//			ShowMessage("Invalid color format: " + fighter2->colour);
//		}
//	}
//
//	TImage* imageYokozuna2 = dynamic_cast<TImage*>(form->FindComponent("ImageYokozuna2"));
//	if (imageYokozuna2) {
//		imageYokozuna2->Visible = (fighter2->rank == "Yokozuna");
//		if (fighter2->rank == "Yokozuna") {
//			AnsiString fullPathYokozuna2 = YokozunaPath + ".png";
//			imageYokozuna2->Bitmap->LoadFromFile(fullPathYokozuna2);
//		}
//	}
//}
//
//


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//void __fastcall TBanzukeForm::ButtonNextHumanBoutClick(TObject *Sender)
//{
//
//	PopulateLeaderboardGrid();
//
//	for (int i = 0; i < 49; i++) {
//		if (isBanzukeComplete == false && isTrainingComplete == true && currentBoutIndex != 49) {
//
//
//			AssignFightersFromGrid();
//
//			if (globalFighter1->owner == "P1" && globalFighter2->owner == "P1") {
////				ShowMessage("Both sumo are owned by the same player, automatically resolving the bout!");
//			}
//			else if (globalFighter1->owner == "P1" || globalFighter2->owner == "P1") {
//				ShowMessage("The current bout features one of your sumo! Head to the Dohyo!");
//				break;
//			}
//			else {
////				ShowMessage("Neither sumo are owned by the same player, automatically resolving the bout!");
//			}
//
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//
//			GetBoutTactic();
//			FighterSkillValue(*globalFighter1, fighter1SkillValue);
//			FighterSkillValue(*globalFighter2, fighter2SkillValue);
//
//			fighter1Total = fighter1SkillValue;
//			HandleInjury(*globalFighter1, fighter1Total);
//
//			fighter2Total = fighter2SkillValue;
//			HandleInjury(*globalFighter2, fighter2Total);
//
//			if (globalFighter1->spirit == 4) {
//				fighter1Total += 1;
//			}
//			if (globalFighter2->spirit == 4) {
//				fighter2Total += 1;
//			}
//
//			if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
//				if (globalFighter1->wins == 3 && globalFighter1->losses == 3) {
//					fighter1Total += 1;
//				}
//				if (globalFighter2->wins == 3 && globalFighter2->losses == 3) {
//					fighter2Total += 1;
//				}
//			}
//
//			if (fighter1Total > fighter2Total) {
//				Victory(0, players);
//			} else if (fighter1Total < fighter2Total) {
//				Victory(1, players);
//			} else {
//				if (globalFighter1->weight > globalFighter2->weight) {
//					Victory(0, players);
//				} else if (globalFighter1->weight < globalFighter2->weight) {
//					Victory(1, players);
//				} else {
//					if (globalFighter1->technique > globalFighter2->technique) {
//						Victory(0, players);
//					} else if (globalFighter1->technique < globalFighter2->technique) {
//						Victory(1, players);
//					} else {
//						winner = std::rand() % 2;
//						Victory(winner, players);
//					}
//				}
//			}
//
//			PopulateLeaderboardGrid();
//			SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
////			UpdateTournamentGrid();
////			UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//			Application->ProcessMessages();
//			currentBoutIndex++;
//			AssignFightersFromGrid();
////			BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
////			UpdateTournamentGrid();
//			if (currentBoutIndex == 49) {
////				BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
//				EndBanzuke();
//				break;
//			}
//
//		}
////		else if (currentBoutIndex == 49) {
//////			BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
////			EndBanzuke();
////			break;
////		}
//		else {
//			ShowMessage("The training phase is not complete. The sumo are not ready.");
//			break;
//		}
//	}
//}

//---------------------------------------------------------------------------

//void __fastcall TBanzukeForm::ButtonAutomateAllClick(TObject *Sender)
//{
//	bool AutoTournament = false;
//
//	// Ask the player if they want to see training results
//	TDialogService::MessageDialog("Are you sure you want to automate the tournament?",
//		TMsgDlgType::mtConfirmation, TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo,
//		TMsgDlgBtn::mbNo, 0,
//		[&AutoTournament](const TModalResult AResult) {
//			AutoTournament = (AResult == mrYes);
//		});
//
//	if (isBanzukeComplete == false && isTrainingComplete == true && AutoTournament == true) {
//
//		PopulateLeaderboardGrid();
//
//		for (int i = 0; i < 49; i++) {
//			// Select skills
//			AssignFightersFromGrid();
//
//	//        ShowMessage("Current Bout: " + IntToStr(i));
//
//			if (globalFighter1->wins > 7 || globalFighter1->wins < 0) {
//				ShowMessage("Error: rikishi.wins has an invalid value: " + IntToStr(globalFighter1->wins));
//			}
//			if (globalFighter1->losses > 7 || globalFighter1->losses < 0) {
//				ShowMessage("Error: rikishi.losses has an invalid value: " + IntToStr(globalFighter1->losses));
//			}
//			if (globalFighter2->wins > 7 || globalFighter2->wins < 0) {
//				ShowMessage("Error: rikishi.wins has an invalid value: " + IntToStr(globalFighter2->wins));
//			}
//			if (globalFighter2->losses > 7 || globalFighter2->losses < 0) {
//				ShowMessage("Error: rikishi.losses has an invalid value: " + IntToStr(globalFighter2->losses));
//			}
//
//	//        auto it = std::find_if(rikishiVector.begin(), rikishiVector.end(),
//	//            [](const Rikishi& r) { return r.name == globalFighter1->name; });
//	//
//	//        if (it == rikishiVector.end()) {
//	//            ShowMessage("Error: globalFighter1 points to an invalid Rikishi.");
//	//        }
//	//
//	//        if (!globalFighter1) {
//	//            ShowMessage("Error: globalFighter1 is nullptr.");
//	//        }
//
//			RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//			RandomSkillForFighter(*globalFighter2, fighter2Tactic);
//
//	//		ShowMessage(AnsiString(fighter1Tactic.c_str()));
//	//        ShowMessage(AnsiString(fighter2Tactic.c_str()));
//
//			GetBoutTactic();
//			FighterSkillValue(*globalFighter1, fighter1SkillValue);
//			FighterSkillValue(*globalFighter2, fighter2SkillValue);
//
//			fighter1Total = fighter1SkillValue;
//			HandleInjury(*globalFighter1, fighter1Total);
//
//			fighter2Total = fighter2SkillValue;
//			HandleInjury(*globalFighter2, fighter2Total);
//
//			if (globalFighter1->spirit == 4) {
//				fighter1Total += 1;
//	//            ShowMessage("Rikishi 1 has high spirits!");
//			}
//			if (globalFighter2->spirit == 4) {
//				fighter2Total += 1;
//	//			ShowMessage("Rikishi 2 has high spirits!");
//			}
//
//			if (currentBoutIndex >= 42 && currentBoutIndex < 49) {
//				if (globalFighter1->wins == 3 && globalFighter1->losses == 3 && globalFighter1->owner == "CPU") {
//					fighter1Total += 1;
//				}
//				if (globalFighter2->wins == 3 && globalFighter2->losses == 3 && globalFighter2->owner == "CPU") {
//					fighter2Total += 1;
//				}
//			}
//
//			if (fighter1Total > fighter2Total) {
//				Victory(0, players);
//			} else if (fighter1Total < fighter2Total) {
//				Victory(1, players);
//			} else {
//	//            ShowMessage("Weight tiebreaker!");
//				if (globalFighter1->weight > globalFighter2->weight) {
//					Victory(0, players);
//				} else if (globalFighter1->weight < globalFighter2->weight) {
//					Victory(1, players);
//				} else {
//	//				ShowMessage("Technique tiebreaker!");
//					if (globalFighter1->technique > globalFighter2->technique) {
//						Victory(0, players);
//					} else if (globalFighter1->technique < globalFighter2->technique) {
//						Victory(1, players);
//					} else {
////						ShowMessage("O...M...G... Chance tiebreaker!");
//						winner = std::rand() % 2;
//						Victory(winner, players);
//					}
//				}
//			}
//			PopulateLeaderboardGrid();
//			SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
////			UpdateTournamentGrid();
////			UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//			Application->ProcessMessages();
//			currentBoutIndex++;
////			BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
//			if (currentBoutIndex==49) {
//				PopulateLeaderboardGrid();
//				SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
////				UpdateTournamentGrid();
////				UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
////				BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
//				EndBanzuke();
//				break;
//			}
////            ShowMessage("Test");
//		}  // <-- Correctly closed loop here
//
////		PopulateLeaderboardGrid();
////		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
////		UpdateTournamentGrid();
////		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//////		BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
////		EndBanzuke();
//	}
//	else {
//		if (AutoTournament) {
//			ShowMessage("The training phase is not complete. The sumo are not ready.");
//		}
//	}
//}


//void __fastcall TBanzukeForm::ButtonNextBoutClick(TObject *Sender)
//{
//	if (isBanzukeComplete == false && isTrainingComplete == true) {
//
//		PopulateLeaderboardGrid();
//		AssignFightersFromGrid();
//
//		RandomSkillForFighter(*globalFighter1, fighter1Tactic);
//		RandomSkillForFighter(*globalFighter2, fighter2Tactic);
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
//		PopulateLeaderboardGrid();
//		SetBoutResult(currentBoutIndex, winnerIdx, loserIdx);
//		UpdateTournamentGrid();
////		UpdateBoutGUI(globalFighter1, globalFighter2, BanzukeForm);
//		Application->ProcessMessages();
//		currentBoutIndex++;
//		AssignFightersFromGrid();
////		BanzukeForm->MemoBoutLog->Lines->Add("Battle over ...");
//		UpdateTournamentGrid();
//
//		}
//
//		if (currentBoutIndex == 49) {
////			BanzukeForm->MemoBoutLog->Lines->Add("The fighting has finished.");
//			EndBanzuke();
//		}
//}




//void __fastcall TBanzukeForm::StringGridTournamentDrawColumnCell(TObject *Sender,
//	TCanvas * const Canvas, TColumn * const Column, const TRectF &Bounds,
//	const int Row, const TValue &Value, const TGridDrawStates State)
//{
//
//	// Remove the grid border (set stroke to transparent)
//	Canvas->Stroke->Color = TAlphaColorRec::Null;
//	Canvas->Stroke->Thickness = 0;
//
//	// Define colors
//	TAlphaColor SemiTransparentCyan = TAlphaColorF::Create(0, 1, 1, 0.75).ToAlphaColor(); // Current bout
//	TAlphaColor Green = TAlphaColorF::Create(0, 1, 0).ToAlphaColor();  // Winner color
//	TAlphaColor Red = TAlphaColorF::Create(1, 0, 0).ToAlphaColor();    // Loser color
//
//	// Ensure row and column indices are valid
//	if (Row >= 7 || Column->Index >= 7) return;
//
//	// Get column index (Day) and row index (Bout)
//	int colIndex = Column->Index;
//	int boutIndex = Row;
//
//	// Get current bout ID
//	int currentBout = colIndex * 7 + boutIndex;
//
//	// **Highlight the current bout in cyan** (background highlight)
//	if (currentBout == currentBoutIndex) {
//		Canvas->Fill->Color = SemiTransparentCyan;
//		Canvas->FillRect(Bounds, 0, 0, AllCorners, 1);
//	}
//
//	// Retrieve the cell text
//	UnicodeString cellText = BanzukeForm->StringGridTournament->Cells[colIndex][boutIndex];
//
//	// Convert UnicodeString to std::string
//    std::string text = std::string(reinterpret_cast<const char*>(cellText.c_str()));
//	size_t vsPos = text.find(" vs ");
//    if (vsPos == std::string::npos) return;
//
//    std::string rank1 = text.substr(0, vsPos);
//	std::string rank2 = text.substr(vsPos + 4); // Skip " vs "
//
//    // Convert std::string to UnicodeString for compatibility
//	UnicodeString rank1U = UnicodeString(rank1.c_str());
//	UnicodeString rank2U = UnicodeString(rank2.c_str());
//
//    // **Highlight the previous bout's winner and loser** (color highlight)
//	TAlphaColor rank1Color = TAlphaColorRec::Black;
//	TAlphaColor rank2Color = TAlphaColorRec::Black;
//
//	if (currentBoutResults.find(currentBout) != currentBoutResults.end()) {
//		int winnerIdx = currentBoutResults[currentBout].first;
//		int loserIdx = currentBoutResults[currentBout].second;
//
//		if (rank1U == UnicodeString(Ranks[winnerIdx].c_str())) rank1Color = Green;
//		if (rank1U == UnicodeString(Ranks[loserIdx].c_str())) rank1Color = Red;
//		if (rank2U == UnicodeString(Ranks[winnerIdx].c_str())) rank2Color = Green;
//		if (rank2U == UnicodeString(Ranks[loserIdx].c_str())) rank2Color = Red;
//	}
//
//	// **Calculate text and rectangle widths**
//	float textWidth = Canvas->TextWidth(cellText);  // Ensure function is called
//	float vsWidth = Canvas->TextWidth(" vs ");
//    float rank1Width = Canvas->TextWidth(rank1U);
//	float rank2Width = Canvas->TextWidth(rank2U);
//
//    // Calculate the total width of all text
//    float totalWidth = rank1Width + vsWidth + rank2Width;
//
//	// Calculate position to center the text
//	float width = Bounds.Right - Bounds.Left; // Calculate width directly
//	float startX = Bounds.Left + ((width - textWidth) / 2); // Center alignment
//
//    // **Draw background rectangle around the text (highlight)**
//	// Draw a rectangle for rank1, " vs ", and rank2 areas (with padding)
//	Canvas->Fill->Color = SemiTransparentCyan;
//	Canvas->FillRect(TRectF(startX, Bounds.Top, startX + rank1Width, Bounds.Bottom), 0, 0, AllCorners, 1);
//	Canvas->FillRect(TRectF(startX + rank1Width + vsWidth, Bounds.Top, startX + rank1Width + vsWidth + rank2Width, Bounds.Bottom), 0, 0, AllCorners, 1);
//
//	// **Draw the text on top of the highlighted background**
//	// Draw rank1
//	Canvas->Fill->Color = rank1Color;
//	Canvas->FillText(TRectF(startX, Bounds.Top, startX + rank1Width, Bounds.Bottom),
//					 rank1U, false, 1.0, TFillTextFlags(),
//					 TTextAlign::Leading, TTextAlign::Center);
//
//	// Draw " vs " in black
//	Canvas->Fill->Color = TAlphaColorRec::Black;
//	Canvas->FillText(TRectF(startX + rank1Width, Bounds.Top, startX + rank1Width + vsWidth, Bounds.Bottom),
//					 " vs ", false, 1.0, TFillTextFlags(),
//					 TTextAlign::Leading, TTextAlign::Center);
//
//	// Draw rank2
//	Canvas->Fill->Color = rank2Color;
//	Canvas->FillText(TRectF(startX + rank1Width + vsWidth, Bounds.Top, startX + rank1Width + vsWidth + rank2Width, Bounds.Bottom),
//					 rank2U, false, 1.0, TFillTextFlags(),
//					 TTextAlign::Leading, TTextAlign::Center);
//}
//








//void __fastcall TBanzukeForm::StringGridTournamentDrawColumnCell(TObject *Sender,
//	TCanvas * const Canvas, TColumn * const Column, const TRectF &Bounds,
//	const int Row, const TValue &Value, const TGridDrawStates State)
//{
//    // Define colors
//    TAlphaColor Green = TAlphaColorF::Create(0, 1, 0).ToAlphaColor();  // Winner color
//	TAlphaColor Red = TAlphaColorF::Create(1, 0, 0).ToAlphaColor();    // Loser color
//    TAlphaColor Black = TAlphaColorRec::Black;  // Default text color
//    TAlphaColor Cyan = TAlphaColorF::Create(0, 1, 1, 0.75).ToAlphaColor(); // Highlight current bout
//
//    // Ensure row and column indices are valid
//    if (Row >= 7 || Column->Index >= 7) return;
//
//    // Get column index (Day) and row index (Bout)
//    int colIndex = Column->Index;
//	int boutIndex = Row;
//
//    // Get current bout ID
//    int currentBout = colIndex * 7 + boutIndex;
//
//    // Retrieve the cell text
//    UnicodeString cellText = BanzukeForm->StringGridTournament->Cells[colIndex][boutIndex];
//
//    // Convert UnicodeString to std::string
//	std::string text = std::string(reinterpret_cast<const char*>(cellText.c_str()));
//    size_t vsPos = text.find(" vs ");
//    if (vsPos == std::string::npos) return;
//
//    std::string rank1 = text.substr(0, vsPos);
//    std::string rank2 = text.substr(vsPos + 4); // Skip " vs "
//
//    // Convert std::string to UnicodeString for compatibility
//    UnicodeString rank1U = UnicodeString(rank1.c_str());
//	UnicodeString rank2U = UnicodeString(rank2.c_str());
//
//    // **Determine text color for winner and loser**
//    TAlphaColor rank1Color = Black;
//    TAlphaColor rank2Color = Black;
//
//    if (currentBoutResults.find(currentBout) != currentBoutResults.end()) {
//        int winnerIdx = currentBoutResults[currentBout].first;
//        int loserIdx = currentBoutResults[currentBout].second;
//
//        if (rank1U == UnicodeString(Ranks[winnerIdx].c_str())) rank1Color = Green;
//        if (rank1U == UnicodeString(Ranks[loserIdx].c_str())) rank1Color = Red;
//        if (rank2U == UnicodeString(Ranks[winnerIdx].c_str())) rank2Color = Green;
//        if (rank2U == UnicodeString(Ranks[loserIdx].c_str())) rank2Color = Red;
//    }
//
//    // Highlight the current bout in cyan
//    if (currentBout == currentBoutIndex) {
//		Canvas->Fill->Color = Cyan;
//        Canvas->FillRect(Bounds, 0, 0, AllCorners, 1);
//    }
//
//    // **Calculate text widths for alignment**
//    float vsWidth = Canvas->TextWidth(" vs ");
//    float rank1Width = Canvas->TextWidth(rank1U);
//    float rank2Width = Canvas->TextWidth(rank2U);
//
//	// Calculate position to center the text
//	float width = Bounds.Right - Bounds.Left;
//	float startX = Bounds.Left + ((width - (rank1Width + vsWidth + rank2Width)) / 2);
//
//	// **Draw the text with respective colors**
//	// Draw rank1
//	Canvas->Fill->Color = rank1Color;
//	Canvas->FillText(TRectF(startX, Bounds.Top, startX + rank1Width, Bounds.Bottom),
//					 rank1U, false, 1.0, TFillTextFlags(),
//					 TTextAlign::Leading, TTextAlign::Center);
//
//	// Draw " vs " in black
//	Canvas->Fill->Color = Black;
//	Canvas->FillText(TRectF(startX + rank1Width, Bounds.Top, startX + rank1Width + vsWidth, Bounds.Bottom),
//                     " vs ", false, 1.0, TFillTextFlags(),
//					 TTextAlign::Leading, TTextAlign::Center);
//
//	// Draw rank2
//    Canvas->Fill->Color = rank2Color;
//	Canvas->FillText(TRectF(startX + rank1Width + vsWidth, Bounds.Top, startX + rank1Width + vsWidth + rank2Width, Bounds.Bottom),
//					 rank2U, false, 1.0, TFillTextFlags(),
//                     TTextAlign::Leading, TTextAlign::Center);
//}





