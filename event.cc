#include "event.hh"
#include "G4Event.hh"
#include "G4RootAnalysisManager.hh"
extern int Nphoton1;


MyEventAction::MyEventAction(MyRunAction* runAction)
 : G4UserEventAction(),
 fRunAction(runAction)
{
	fEdep=0.;
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	Nphoton1=0;
	fEdep=0.;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
	//G4cout << "Energy deposition: " << fEdep << G4endl;
	G4RootAnalysisManager *analysisManager = G4RootAnalysisManager::Instance();
	
	if (Nphoton1>0) {	
	
	//G4cout << Nphoton1 << G4endl;
	
	analysisManager->FillNtupleIColumn(0, 0, Nphoton1);
	analysisManager->FillH1(0, Nphoton1);
	
	analysisManager->FillNtupleDColumn(1, 0, (fEdep));
	analysisManager->AddNtupleRow(1);
	
	analysisManager->AddNtupleRow(0);}
}
