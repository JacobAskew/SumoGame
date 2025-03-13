// Street.h

#ifndef StreetH
#define StreetH

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Objects.hpp>

// Forward declaration for TNoboruForm to avoid circular dependency
class TNoboruForm;
class TYourBeya;

void UpdateBanzukeGrid();
void BiddingPhaseComplete();
void TrainingPhaseComplete();
void BanzukePhaseComplete();

// Define the Rikishi struct here so it can be accessed everywhere in the file
struct Rikishi {
	std::string name;
    int id;
	int strength = 0;
	int weight = 0;
	int technique = 0;
	int endurance = 0;
	int speed = 0;
	int strengthLimit = 4;
	int weightLimit = 4;
	int techniqueLimit = 4;
	int enduranceLimit = 4;
	int speedLimit = 4;
	int spirit = 0;
    bool isShaken = false;
	int age = 21;
	std::string rank;
	int minBid = 1;
	int currentBid = 1;
	int score = 0;
    int retirementScore = 0;
	String colour;
	int wins = 0;
	int losses = 0;
    int tournamentWins = 0;
    std::string RandomString;
	std::string owner = "Nobody"; // Defaults to "Computer"
	bool isInitialized = false; // Defaults to false
	bool isInjuredEndurance = false; // Defaults to false
	bool isInjuredSpeed = false; // Defaults to false
	bool isInjuredStrength = false; // Defaults to false
	std::string preferredSkill;
};

	// Default constructor
//	Rikishi()
//		: strength(0), weight(0), technique(0), endurance(0), speed(0),
//		  strengthLimit(0), weightLimit(0), techniqueLimit(0), enduranceLimit(0), speedLimit(0),
//		  spirit(0), age(0), minBid(0), currentBid(0), score(0) {}

// Class to represent a Player
//class Player {
//public:
//    std::string name;
//	int AP;
//	int VP;
//
//    // Method to add 7 AP each year
//    void AddAP() {
//        AP += 7;
//    }
//
//    // Method to deduct AP when placing a bid
//    void DeductAP(int amount) {
//        if (AP >= amount) {
//            AP -= amount;
//        } else {
//            AP = 0;  // If AP is less than the bid amount, set it to 0
//        }
//    }
//
//    std::vector<Rikishi> rikishiList;
//    int numberRikishi;
//
//    Player(const std::string& n = "", int ap = 0) : name(n), AP(ap) {}
//};

// Class to represent a Player
class Player {
public:
    std::string name;
    int AP;
    int VP;
    std::vector<Rikishi> rikishiList;
    int numberRikishi;

    // Constructor with default AP and VP set to 0
    Player(const std::string& n = "", int ap = 0, int vp = 0)
        : name(n), AP(ap), VP(vp), numberRikishi(0) {}

    // Method to add 7 AP each year
    void AddAP() {
        AP += 7;
    }

    // Method to deduct AP when placing a bid
    void DeductAP(int amount) {
        if (AP >= amount) {
            AP -= amount;
        } else {
            AP = 0;  // If AP is less than the bid amount, set it to 0
        }
    }
};


class TMainStreet : public TForm
{
__published:    // IDE-managed Components
    TButton *ButtonNoboru;
	TButton *ButtonBeya;
	TButton *ButtonBanzuke;
	TButton *ButtonDohyo;
	TButton *ButtonRyogoku;
	TEdit *EditAbilityPoints;
	TEdit *EditVictoryPoints;
	TImage *ImageBackground;
    void __fastcall ButtonNoboruClick(TObject *Sender);
	void __fastcall ButtonBeyaClick(TObject *Sender);
	void __fastcall ButtonBanzukeClick(TObject *Sender);
	void __fastcall ButtonDohyoClick(TObject *Sender);
	void __fastcall ButtonRyogokuClick(TObject *Sender);

private:    // User declarations
	void __fastcall CheckNamesFile();
//    void ReadAndProcessNames(); // Declare the method here

public:        // User declarations
    __fastcall TMainStreet(TComponent* Owner);
};

extern PACKAGE TMainStreet *MainStreet;
extern std::vector<Rikishi> rikishiVector;  // Declare the vector as extern
extern std::vector<Player> players;
extern std::string Ranks[];
extern void UpdatePoints();
#endif

