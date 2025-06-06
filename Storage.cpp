//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Storage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TStorageForm *StorageForm;
//---------------------------------------------------------------------------
__fastcall TStorageForm::TStorageForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



//// Function to update the GUI with the current values of the variables
//void UpdateGUI() {
//	// Update Player 1 GUI
//	MainStreet->ButtonStrength_1->Text = "Strength: " + IntToStr(strength_1);
//	MainStreet->ButtonWeight_1->Text = "Weight: " + IntToStr(weight_1);
//	MainStreet->ButtonTechnique_1->Text = "Technique: " + IntToStr(technique_1);
//	MainStreet->ButtonEndurance_1->Text = "Endurance: " + IntToStr(endurance_1);
//	MainStreet->ButtonSpeed_1->Text = "Speed: " + IntToStr(speed_1);
//	MainStreet->EditAge1->Text = "Age: " + IntToStr(Age1);
//	MainStreet->EditSpirit1->Text = "Spirit: " + IntToStr(Spirit1);
//	MainStreet->EditRank1->Text = "Rank: " + UnicodeString(Rank1.c_str());
//	MainStreet->EditName1->Text = "Rikishi: " + UnicodeString(player1Name.c_str());
//	MainStreet->EditOwner1->Text = "Oyakata: " + UnicodeString(player1Owner.c_str());
//
//	// Update Player 2 GUI
//	MainStreet->EditStrength_2->Text = "Strength: " + IntToStr(strength_2);
//	MainStreet->EditWeight_2->Text = "Weight: " + IntToStr(weight_2);
//	MainStreet->EditTechnique_2->Text = "Technique: " + IntToStr(technique_2);
//	MainStreet->EditEndurance_2->Text = "Endurance: " + IntToStr(endurance_2);
//	MainStreet->EditSpeed_2->Text = "Speed: " + IntToStr(speed_2);
//	MainStreet->EditAge2->Text = "Age: " + IntToStr(Age2);
//	MainStreet->EditSpirit2->Text = "Spirit: " + IntToStr(Spirit2);
//	MainStreet->EditRank2->Text = "Rank: " + UnicodeString(Rank2.c_str());
//	MainStreet->EditName2->Text = "Rikishi: " + UnicodeString(player2Name.c_str());
//	MainStreet->EditOwner2->Text = "Oyakata: " + UnicodeString(player2Owner.c_str());
//}

//
//// Function to initialize values for both sets of variables
//void InitializeValues() {
//
//	usedNames.clear(); // Clear previously used names at initialization
//
//	InitializeRikishi(rikishiVector[0], usedNames);
//
//	// Initialize Player 1 variables
//	strength_1 = std::rand() % SkillDiceNo;
//	weight_1 = std::rand() % SkillDiceNo;
//	technique_1 = std::rand() % SkillDiceNo;
//	endurance_1 = std::rand() % SkillDiceNo;
//	speed_1 = std::rand() % SkillDiceNo;
//	Spirit1 = std::rand() % SkillDiceNo;
//	Age1 = 21 + (std::rand() % (30 - 21));
//	Rank1 = Ranks[13];
//	GetRandomName(player1Name, usedNames); // Assign random unique name to player1Name
//
//	// Initialize Player 2 variables
//	strength_2 = std::rand() % SkillDiceNo;
//	weight_2 = std::rand() % SkillDiceNo;
//	technique_2 = std::rand() % SkillDiceNo;
//	endurance_2 = std::rand() % SkillDiceNo;
//	speed_2 = std::rand() % SkillDiceNo;
//	Spirit2 = std::rand() % SkillDiceNo;
//	Age2 = 21 + (std::rand() % (30 - 21));
//	Rank2 = Ranks[11];
//	GetRandomName(player2Name, usedNames); // Assign random unique name to player2Name
//}
//
//
//
//void GetBoutTactic() {
//	if (player1Tactic == player2Tactic) {
//		boutTactic = player1Tactic; // Both players chose the same skill
////		UpdateLogMemo("The bout tactic is " + player1Tactic + "!");
//		MainStreet->MemoLog->Lines->Add("The bout tactic is " + player1Tactic + "!");
//	}
//	// Check if either player's tactic is "Strength"
//	else if ((player1Tactic == "Strength" && (player2Tactic == "Weight" || player2Tactic == "Technique")) ||
//			 (player2Tactic == "Strength" && (player1Tactic == "Weight" || player1Tactic == "Technique"))) {
//		boutTactic = "Strength";
//		MainStreet->MemoLog->Lines->Add("The bout tactic is Strength!");
////		UpdateLogMemo("The bout tactic is Strength!");
//	}
//	// Check if either player's tactic is "Speed"
//	else if ((player1Tactic == "Speed" && (player2Tactic == "Strength" || player2Tactic == "Endurance")) ||
//			 (player2Tactic == "Speed" && (player1Tactic == "Strength" || player1Tactic == "Endurance"))) {
//		boutTactic = "Speed";
//		MainStreet->MemoLog->Lines->Add("The bout tactic is Speed!");
//	}
//	// Check if either player's tactic is "Technique"
//	else if ((player1Tactic == "Technique" && (player2Tactic == "Weight" || player2Tactic == "Speed")) ||
//			 (player2Tactic == "Technique" && (player1Tactic == "Weight" || player1Tactic == "Speed"))) {
//		boutTactic = "Technique";
//		MainStreet->MemoLog->Lines->Add("The bout tactic is Technique!");
//	}
//	// Check if either player's tactic is "Endurance"
//	else if ((player1Tactic == "Endurance" && (player2Tactic == "Strength" || player2Tactic == "Technique")) ||
//			 (player2Tactic == "Endurance" && (player1Tactic == "Strength" || player1Tactic == "Technique"))) {
//		boutTactic = "Endurance";
//		MainStreet->MemoLog->Lines->Add("The bout tactic is Endurance!");
//	}
//	// Check if either player's tactic is "Weight"
//	else if ((player1Tactic == "Weight" && (player2Tactic == "Endurance" || player2Tactic == "Speed")) ||
//			 (player2Tactic == "Weight" && (player1Tactic == "Endurance" || player1Tactic == "Speed"))) {
//		boutTactic = "Weight";
//		MainStreet->MemoLog->Lines->Add("The bout tactic is Weight!");
//	}
//	else {
//		boutTactic = "Unknown"; // Fallback if no condition is met
//		MainStreet->MemoLog->Lines->Add("Bout Tactic Error!");
//	}
//}


//void GetNewSkill() {
//	if (boutTactic == "Strength") {
//		player1Skill = strength_1;
//		player2Skill = strength_2;
//	} else if (boutTactic == "Weight") {
//		player1Skill = weight_1;
//		player2Skill = weight_2;
//	} else if (boutTactic == "Technique") {
//		player1Skill = technique_1;
//		player2Skill = technique_2;
//	} else if (boutTactic == "Endurance") {
//		player1Skill = endurance_1;
//		player2Skill = endurance_2;
//	} else if (boutTactic == "Speed") {
//		player1Skill = speed_1;
//		player2Skill = speed_2;
//	} else {
//		// Default behavior if boutTactic does not match any skill
//		player1Skill = 0;
//		player2Skill = 0;
//		MainStreet->MemoLog->Lines->Add("Unknown bout tactic. Defaulting skills to 0.");
//	}}
//
//int RandomSkillForPlayer2() {
//	int randomSkillIndex = std::rand() % SkillDiceNo;
//	switch (randomSkillIndex) {
//		case 0:
//			player2Tactic = "Strength";
//			return strength_2;
//		case 1:
//			player2Tactic = "Weight";
//			return weight_2;
//		case 2:
//			player2Tactic = "Technique";
//			return technique_2;
//		case 3:
//			player2Tactic = "Endurance";
//			return endurance_2;
//		case 4:
//			player2Tactic = "Speed";
//			return speed_2;
//		default:
//			player2Tactic = "Unknown";
//			MainStreet->MemoLog->Lines->Add("Error Returning 0.");
//			return 0;
//	}
//}




//void ReorderRikishi(std::vector<Rikishi>& rikishiVector) {
//	std::vector<std::string> rankOrder = {
//		"Yokozuna", "Ozeki", "Sekiwake", "Komusubi",
//		"Maegashira 1", "Maegashira 2", "Maegashira 3",
//		"Maegashira 4", "Maegashira 5", "Maegashira 6",
//		"Maegashira 7", "Maegashira 8", "Maegashira 9",
//		"Maegashira 10", "Juryo 1", "Juryo 2"
//	};
//
//	auto rankValue = [&](const std::string& rank) -> int {
//		auto it = std::find(rankOrder.begin(), rankOrder.end(), rank);
//		return (it != rankOrder.end()) ? std::distance(rankOrder.begin(), it) : rankOrder.size();
//	};
//
//	// Sort rikishi by initial rank order
//	std::sort(rikishiVector.begin(), rikishiVector.end(), [&](const Rikishi& a, const Rikishi& b) {
//		return rankValue(a.rank) < rankValue(b.rank);
//	});
//
//	// Debug: Print original ranking
//	MainStreet->MemoLog->Lines->Add("Original Ranking:");
//	for (const auto& r : rikishiVector) {
//		MainStreet->MemoLog->Lines->Add(AnsiString(r.name.c_str()) + " (" +
//										 AnsiString(r.rank.c_str()) + ") - Wins: " +
//										 IntToStr(r.wins) + ", Losses: " + IntToStr(r.losses));
//	}
//
//	std::vector<std::pair<Rikishi*, int>> rankAdjustments;
//
//    // Assign movement bonuses
//    for (auto& rikishi : rikishiVector) {
//        int movement = 0;
//		if (rikishi.wins == 7) movement = 6;
//        else if (rikishi.wins == 6) movement = 4;
//        else if (rikishi.wins == 5) movement = 2;
//        else if (rikishi.wins == 4) movement = 1;
//        else if (rikishi.losses == 7) movement = -6;
//		else if (rikishi.losses == 6) movement = -4;
//        else if (rikishi.losses == 5) movement = -2;
//        else if (rikishi.losses == 4) movement = -1;
//
//        // Yokozuna always gets +1
//        if (rikishi.rank == "Yokozuna") movement += 1;
//
//        int currentRankIndex = rankValue(rikishi.rank);
//        int newRankIndex = std::max(0, std::min((int)rankOrder.size() - 1, currentRankIndex - movement));
//
//        // Store rikishi with new rank index
//        rankAdjustments.push_back({ &rikishi, newRankIndex });
//	}
//
//    // Sort based on new rankIndex and maintain order within same ranks
//    std::stable_sort(rankAdjustments.begin(), rankAdjustments.end(), [&](const auto& a, const auto& b) {
//        return a.second < b.second;  // Sort by newRankIndex
//	});
//
//    // Apply final ranks and rebuild the vector
//    std::vector<Rikishi> reorderedRikishi;
//    for (auto& [rikishi, newRankIndex] : rankAdjustments) {
//        rikishi->rank = rankOrder[newRankIndex];
//        reorderedRikishi.push_back(*rikishi);
//    }
//
//	// Ensure Juryo 2 -> Juryo 1 rule
//    for (auto& rikishi : reorderedRikishi) {
//        if (rikishi.rank == "Juryo 2") {
//            rikishi.rank = "Juryo 1";  // Promote original Juryo 2 to Juryo 1
//            break;
//        }
//    }
//
//	// Debug: Print final ranking before filling gaps
//	MainStreet->MemoLog->Lines->Add("\nFinal Ranking (Before Gaps Filled):");
//	for (const auto& r : reorderedRikishi) {
//		MainStreet->MemoLog->Lines->Add(AnsiString(r.name.c_str()) + " (" + AnsiString(r.rank.c_str()) + ")");
//	}
//
//	// Fill gaps from top down
//	std::vector<Rikishi> finalRanking;
//	auto rankIterator = rankOrder.begin();
//
//	for (auto& rikishi : reorderedRikishi) {
//		while (rankIterator != rankOrder.end() && rikishi.rank != *rankIterator) {
//			// If a rank is missing, the highest available rikishi fills it
//			if (!finalRanking.empty()) {
//				finalRanking.back().rank = *rankIterator;
//			}
//			++rankIterator;
//		}
//		finalRanking.push_back(rikishi);
//		++rankIterator;
//	}
//
//	// Debug: Print final ranking after filling gaps
//	MainStreet->MemoLog->Lines->Add("\nFinal Ranking (After Gaps Filled):");
//	for (const auto& r : finalRanking) {
//		MainStreet->MemoLog->Lines->Add(AnsiString(r.name.c_str()) + " (" + AnsiString(r.rank.c_str()) + ")");
//	}
//
//	// Update rikishiVector with the new order
//    rikishiVector = finalRanking;
//}




//void __fastcall TMainStreet::ButtonResetClickClick(TObject *Sender)
//{
//	InitializeValues();
//	UpdateGUI();
//	LabelResult->Text = "";
//    MemoLog->Lines->Clear();
//}
//
//void __fastcall TMainStreet::ButtonStrength_1Click(TObject *Sender)
//{
//	player1Skill = strength_1;
//	player2Skill = RandomSkillForPlayer2();
//	player1Tactic = "Strength";
//}
//
//void __fastcall TMainStreet::ButtonSpeed_1Click(TObject *Sender)
//{
//	player1Skill = speed_1;
//	player2Skill = RandomSkillForPlayer2();
//	player1Tactic = "Speed";
//}
//
//void __fastcall TMainStreet::ButtonWeight_1Click(TObject *Sender)
//{
//	player1Skill = weight_1;
//	player2Skill = RandomSkillForPlayer2();
//	player1Tactic = "Weight";
//}
//
//void __fastcall TMainStreet::ButtonTechnique_1Click(TObject *Sender)
//{
//	player1Skill = technique_1;
//	player2Skill = RandomSkillForPlayer2();
//	player1Tactic = "Technique";
//}
//
//void __fastcall TMainStreet::ButtonEndurance_1Click(TObject *Sender)
//{
//	player1Skill = endurance_1;
//	player2Skill = RandomSkillForPlayer2();
//	player1Tactic = "Endurance";
//
//}
//
//void __fastcall TMainStreet::fight_buttonClick(TObject *Sender)
//{
//
//	// Reset player skills before each fight
//	player1Skill = 0;
//	player2Skill = 0;
//	boutTactic = "Unknown";
//	Luck1 = std::rand() % 7;
//	Luck2 = std::rand() % 7;
//
//	MemoLog->Lines->Add("Rikishi 1 chose: " + player1Tactic);
//	MemoLog->Lines->Add("Rikishi 2 chose: " + player2Tactic);
//
//	GetBoutTactic();
//
//	GetNewSkill();
//
//	MemoLog->Lines->Add("Rikishi 1 has a skill modifier = " + \
//	 IntToStr(player1Skill));
//	MemoLog->Lines->Add("Rikishi 2 has a skill modifier = " + \
//	 IntToStr(player2Skill));
//
//	Luck1 = std::rand() % 7;
//	Luck2 = std::rand() % 7;
//	player1Skill = player1Skill+Luck1;
//	player2Skill = player2Skill+Luck2;
//	MemoLog->Lines->Add("Rikishi 1 rolled a " + IntToStr(Luck1));
//	MemoLog->Lines->Add("Rikishi 2 rolled a " + IntToStr(Luck2));
//
//	if (Spirit1 == 4) {
//		player1Skill = player1Skill+Luck1;
//		MemoLog->Lines->Add("Rikishi 1 has high spirits!");
//	}
//	if (Spirit2 == 4) {
//		player2Skill = player2Skill+Luck2;
//		MemoLog->Lines->Add("Rikishi 2 has high spirits!");
//	}
//	MemoLog->Lines->Add("They Fight!");
//	MemoLog->Lines->Add("...");
//	if (player1Skill > player2Skill) {
//		MemoLog->Lines->Add("Rikishi 1 wins!");
//		LabelResult->Text = "Congratulations! You won!";
//	} else if (player1Skill < player2Skill) {
//		MemoLog->Lines->Add("Rikishi 2 wins!");
//		LabelResult->Text = "You lose this round, try again!";
//	} else {
//		MemoLog->Lines->Add("It was a draw!");
//		LabelResult->Text = "Draw! Try another round!";
//	}
//}

