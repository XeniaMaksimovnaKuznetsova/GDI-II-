#include "generator.hh"
#include "G4RandomDirection.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	//G4String particleName="e";
	G4ParticleDefinition *particle = particleTable->FindParticle("gamma");
	
	G4ThreeVector pos(0.,0. *mm,0.);
	G4ThreeVector mom(0.,1.,0.);
	
	fParticleGun->SetParticlePosition(pos);
	//fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentumDirection(G4RandomDirection());
	//fParticleGun->SetParticleMomentum(*MeV);
	fParticleGun->SetParticleEnergy(0.3 *MeV);// 1.46 MeV (Ka) 2.62 MeV (Tl) _________ 100 KeV ... 5 MeV (step:100 KeV)
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->GeneratePrimaryVertex(anEvent);
}
