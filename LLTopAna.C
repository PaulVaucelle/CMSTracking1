#define LLTopTree_cxx
#include "LLTopAna.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "HistogramManager.h"
#include "TLorentzVector.h"
#include "TRandom.h"
#include <iostream>
//distance in cm (sometimes you will see *100 to go in meters, E en GeV

void SetSebStyle()
{
 gStyle->SetTitleFillColor(42);
 gStyle->SetTitleFont(1);
 gStyle->SetStatColor(29);
 gStyle->SetCanvasColor(25);   
 gStyle->SetOptStat(1111111);
 gStyle->SetHistFillColor(5);
}

void SaveInFile(TH1* ahisto, TFile* afile)
{
 if (!ahisto) { std::cout << "!! no histo !!" << std::endl; return ;}
 TDirectory* current = gDirectory ;
 afile->cd();
 ahisto->Write();
 current->cd();
}
//(0) aNN arbitrary, (180) aTagcut HT cut, (20) aPtmin jet cut, (2999) aPtm Max energy jets, 0. et 2.4 eta min et max, 0 (aFreeCut) et 1 (aIntCut) arbitrary
void LLTopTree::Loop(int aNN, float aTagCut, float aPtMin, float aPtMax, 
                float aEtaMin, float aEtaMax, float aFreeCut, int aIntCut, 
		TString afilename)
{
///////////////////////////////////////////////////////////////////
//                  T I T L E      C A R D S                     //

//$$
  int    NN           = aNN;      // 0/1 JP, 2/3 TC, 4/5 SSV, 6 CSV, 7 SL
  float  TagCut       = aTagCut;  // tag cut
  float  PtMin        = aPtMin;   // pt jet min
  float  PtMax        = aPtMax;   // pt jet max
  float  EtaMin       = aEtaMin;  // eta jet min
  float  EtaMax       = aEtaMax;  // eta jet max
  float  FreeCut      = aFreeCut; 
  int    IntCut       = aIntCut; 
  TString  filename   = afilename;
//$$

//$$
  float HTcut =  aTagCut; 
  float Vrcut =  FreeCut;//useless 
//$$

///////////////////////////////////////////////////////////////////
 
//$$
//$$ TH1F::SetDefaultSumw2(kTRUE);
//$$

//**********************************
// Histograms
//**********************************

////////Ajouter par Paul Vaucelle///////
TH1F* hMuonsFromSmuons = new TH1F("hMuonsFromSmuons","GenMuons From Smuons",39,-20,20);
TH1F* hTopFromNeutralino = new TH1F("hTopFromNeutralino","GenTop From Neutralino",19,-10,10);
TH1F* hQuarksFromTops = new TH1F("hQuarksFromTops","GenQuarksFromNeutralino",9,-5,5);
TH1F* hTracksCharge = new TH1F("hTracksCharge","TracksCharge",9,-5,5);
TH1F* hIsFromLLPid = new TH1F("hIsFromLLPid","hIsFromLLPid",39,-20,20);
TH1F* hr1_etasup1_5 = new TH1F("hr1_etasup1_5","r1_etasup1_5",200,0.,100.);
TH1F* hz1_etainf1_5 = new TH1F("hz1_etainf1_5","z1_etainf1_5",200,0.,100.);
TH2F* hr1_f_z1= new TH2F("hr1_f_z1","hr1_f_z1",200,0.,100.,200,0.,100.);
TH3F* h_x1_y1_z1 = new TH3F("h_x1_y1_z1","h_x1_y1_z1",200,0.,100.,200,0.,100.,200,0.,100.);


////////////////////////////////

 TH1F* hDataAll_nZMu     = new TH1F("hDataAll_nZMu","",11,-0.5,10.5);
 TH1F* hDataAll_Jet_njet = new TH1F("hDataAll_Jet_njet","",40,-0.5,29.5);
 TH1F* hDataAll_Jet_pt   = new TH1F("hDataAll_Jet_pt","",100,0.,1000.);
 TH1F* hDataAll_Jet_eta	 = new TH1F("hDataAll_Jet_eta","",50,-2.5,2.5);
 TH1F* hDataAll_Jet_phi	 = new TH1F("hDataAll_Jet_phi","",66,-3.3,3.3);
 TH1F* hDataAll_Jet_HT   = new TH1F("hDataAll_Jet_HT","",100,0.,2500.);
 TH1F* hDataAll_nMu      = new TH1F("hDataAll_nMu","",11,-0.5,10.5);
 TH1F* hDataAll_nMuGlob  = new TH1F("hDataAll_nMuGlob","",11,-0.5,10.5);
 TH1F* hDataAll_Mu_ptmax = new TH1F("hDataAll_Mu_ptmax","",100,0.,400.);
 TH1F* hDataAll_nMuGlob_ptGT28  = new TH1F("hDataAll_nMuGlob_ptGT28","",11,-0.5,10.5);

 TH1F* hData_Mu_dVr      = new TH1F("hData_Mu_dVr","",100,0.,1.);
 TH1F* hData_Mu_dVz      = new TH1F("hData_Mu_dVz","",100,-1.,1.);
 TH1F* hData_Mu_pt	 = new TH1F("hData_Mu_pt","",100,0.,400.);
 TH1F* hData_Mu_eta	 = new TH1F("hData_Mu_eta","",50,-2.5,2.5);
 TH1F* hData_Mu_phi	 = new TH1F("hData_Mu_phi","",66,-3.3,3.3);
 TH1F* hData_Mu_PFiso      = new TH1F("hData_Mu_PFiso","",5,-0.5,4.5);
 TH1F* hData_Mu_MVAiso     = new TH1F("hData_Mu_MVAiso","",5,-0.5,4.5);
 TH1F* hData_Mu_CutBasedId = new TH1F("hData_Mu_CutBasedId","",5,-0.5,4.5);
 TH1F* hData_nMuRec      = new TH1F("hData_nMuRec","",11,-0.5,10.5);
 TH1F* hData_MuMu_mass   = new TH1F("hData_MuMu_mass","",100,0.,400.);
 TH1F* hData_Mu_pt1	 = new TH1F("hData_Mu_pt1","",100,0.,400.);
 TH1F* hData_Mu_pt2	 = new TH1F("hData_Mu_pt2","",100,0.,400.);

 TH1F* hData_nPV        = new TH1F("hData_nPV","",81,-0.5,80.5);
 TH1F* hData_PVx        = new TH1F("hData_PVx","",100,-0.4,0.4);
 TH1F* hData_PVy        = new TH1F("hData_PVy","",100,-0.4,0.4);
 TH1F* hData_PVz        = new TH1F("hData_PVz","",100,-20.,20.);
 TH1F* hGen_PVx	        = new TH1F("hGen_PVx","",100,-0.4,0.4);
 TH1F* hGen_PVy	        = new TH1F("hGen_PVy","",100,-0.4,0.4);
 TH1F* hGen_PVz	        = new TH1F("hGen_PVz","",100,-20.,20.);
 TH1F* hDataGen_PV_dx	= new TH1F("hDataGen_PV_dx","",100,-0.05,0.05);
 TH1F* hDataGen_PV_dy	= new TH1F("hDataGen_PV_dy","",100,-0.05,0.05);
 TH1F* hDataGen_PV_dz	= new TH1F("hDataGen_PV_dz","",100,-0.05,0.05);

 TH1F* hGen_smu         = new TH1F("hGen_smu","",5,-0.5,4.5);
 TH1F* hGen_smu_pt      = new TH1F("hGen_smu_pt","",50,0.,1000.);
 TH1F* hGen_smu_eta     = new TH1F("hGen_smu_eta","",50,-5.,5.);

 TH1F* hGen_snu         = new TH1F("hGen_snu","",5,-0.5,4.5);
 TH1F* hGen_snu_pt      = new TH1F("hGen_snu_pt","",50,0.,1000.);
 TH1F* hGen_snu_eta     = new TH1F("hGen_snu_eta","",50,-5.,5.);
 TH1F* hGen_snu_DR      = new TH1F("hGen_snu_DR","",50,0.,5.);
 TH1F* hGen_snu_testE0  = new TH1F("hGen_snu_testE0","",100,-0.5,0.5);

 TH1F* hGen_top_DR      = new TH1F("hGen_top_DR","",100,0.,5.);
 TH1F* hGen_top         = new TH1F("hGen_top","",5,-0.5,4.5);
 TH1F* hGen_top_r       = new TH1F("hGen_top_r","",100,0.,100.);
 TH1F* hGen_top_z       = new TH1F("hGen_top_z","",100,0.,200.);
 TH1F* hGen_top_d       = new TH1F("hGen_top_d","",100,0.,1000.);
 TH1F* hGen_top_pt      = new TH1F("hGen_top_pt","",50,0.,500.);
 TH1F* hGen_top_eta     = new TH1F("hGen_top_eta","",50,-5.,5.);
 TH1F* hGen_top_phi     = new TH1F("hGen_top_phi","",66,-3.3,3.3);
 TH1F* hGen_top_bg      = new TH1F("hGen_top_bg","",50,0.,20.);
 TH1F* hGen_top_ctau    = new TH1F("hGen_top_ctau","",100,0.,200.);
 TH1F* hGen_top_Vphi    = new TH1F("hGen_top_Vphi","",66,-3.3,3.3);
 TH1F* hGen_top_dVphi   = new TH1F("hGen_top_dVphi","",33,0.,3.3);
 TH1F* hGen_toptop_DR   = new TH1F("hGen_toptop_DR","",100,0.,5.);
 TH1F* hGen_toptop_DV   = new TH1F("hGen_toptop_DV","",100,0.,200.);
 TH1F* hGen_toptop_dVphi = new TH1F("hGen_toptop_dVphi","",33,0.,3.3);

 TH1F* hGen_quark	= new TH1F("hGen_quark","",10,-0.5,9.5);
 TH1F* hGen_stoq 	= new TH1F("hGen_stoq","",10,-0.5,9.5);
 TH1F* hGen_stoq_dV     = new TH1F("hGen_stoq_dV","",100,0.,0.01);
 TH1F* hGen_stoq_pt	= new TH1F("hGen_stoq_pt","",50,0.,500.);
 TH1F* hGen_stoq_eta	= new TH1F("hGen_stoq_eta","",50,-2.5,2.5);
 TH1F* hGen_stoq_phi    = new TH1F("hGen_stoq_phi","",66,-3.3,3.3);

 TH1F* hGen_muon_pt     = new TH1F("hGen_muon_pt","",50,0.,500.);
 TH1F* hGen_muon_eta    = new TH1F("hGen_muon_eta","",50,-2.5,2.5);
 TH1F* hGen_muon_pt1    = new TH1F("hGen_muon_pt1","",50,0.,500.);
 TH1F* hGen_muon_pt2    = new TH1F("hGen_muon_pt2","",50,0.,500.);
 TH1F* hGen_mumu_mass   = new TH1F("hGen_mumu_mass","",100,0.,400.);
 TH1F* hDataGen_mu_dpt  = new TH1F("hDataGen_mu_dpt","",100,0.5,1.5);
 TH1F* hDataGen_mu_deta = new TH1F("hDataGen_mu_deta","",100,-0.1,0.1);
 TH1F* hDataGen_mu_dphi = new TH1F("hDataGen_mu_dphi","",100,-0.1,0.1);

//  TH1F* hGenTk_dv            = new TH1F("hGenTk_dv","",100,0.,0.01);
//  TH1F* hGenTk_dv_big        = new TH1F("hGenTk_dv_big","",100,0.,1.);
//  TH1F* hGenTk_phi0	    = new TH1F("hGenTk_phi0","",66,-3.3,3.3);
//  TH1F* hGenTk_pt            = new TH1F("hGenTk_pt","",100,0.,400.);
//  TH1F* hGenTk_LLP_dpt	    = new TH1F("hGenTk_LLP_dpt","",100,-0.5,0.5);
//  TH1F* hGenTk_LLP_deta      = new TH1F("hGenTk_LLP_deta","",100,-0.1,0.1);
//  TH1F* hGenTk_LLP_dphi      = new TH1F("hGenTk_LLP_dphi","",100,-0.5,0.5);
//  TH1F* hGenTk_LLP_dphi0     = new TH1F("hGenTk_LLP_dphi0","",100,-0.1,0.1);
//  TH1F* hGenTk_LLP_dpt_cut   = new TH1F("hGenTk_LLP_dpt_cut","",100,-0.5,0.5);
//  TH1F* hGenTk_LLP_dpt_cut_ss   = new TH1F("hGenTk_LLP_dpt_cut_ss","",100,-0.5,0.5);
//  TH1F* hGenTk_LLP_dpt_cut_os   = new TH1F("hGenTk_LLP_dpt_cut_os","",100,-0.5,0.5);
//  TH1F* hGenTk_Sim_dpt	    = new TH1F("hGenTk_Sim_dpt","",100,-0.5,0.5);
//  TH1F* hGenTk_Sim_deta      = new TH1F("hGenTk_Sim_deta","",100,-0.1,0.1);
//  TH1F* hGenTk_Sim_dphi0     = new TH1F("hGenTk_Sim_dphi0","",100,-0.1,0.1);
//  TH1F* hGenTk_Sim_dpt_cut   = new TH1F("hGenTk_Sim_dpt_cut","",100,-0.5,0.5);
//  TH1F* hGenTk_Oth_dpt       = new TH1F("hGenTk_Oth_dpt","",100,-0.5,0.5);
//  TH1F* hGenTk_Oth_deta      = new TH1F("hGenTk_Oth_deta","",100,-0.1,0.1);
//  TH1F* hGenTk_Oth_dphi0     = new TH1F("hGenTk_Oth_dphi0","",100,-0.1,0.1);
//  TH1F* hGenTk_Oth_dpt_cut   = new TH1F("hGenTk_Oth_dpt_cut","",100,-0.5,0.5);
//  TH1F* hGenTk_Oth_dpt_cut_ss   = new TH1F("hGenTk_Oth_dpt_cut_ss","",100,-0.5,0.5);
//  TH1F* hGenTk_Oth_dpt_cut_os   = new TH1F("hGenTk_Oth_dpt_cut_os","",100,-0.5,0.5);

 TH1F* hData_nTk        = new TH1F("hData_nTk","",501,-0.5,500.5);

 TH1F* hTkGenLLP_test	 = new TH1F("hTkGenLLP_test","",5,-2.5,2.5);
 TH1F* hTkGenLLPnot_test = new TH1F("hTkGenLLPnot_test","",5,-2.5,2.5);
 TH1F* hTkGenLLP_dV	 = new TH1F("hTkGenLLP_dV","",100,0.,1.);
 TH1F* hTkGenLLPnot_dV	 = new TH1F("hTkGenLLPnot_dV","",100,0.,1.);

 TH1F* hTkSim_dV	 = new TH1F("hTkSim_dV","",100,0.,0.01);
 TH1F* hTkSim_dV_big     = new TH1F("hTkSim_dV_big","",100,0.,1.);
 TH1F* hTkSim_dphiTop    = new TH1F("hTkSim_dphiTop","",33,0.,3.3);
 TH1F* hTkSim_dq         = new TH1F("hTkSim_dq","",5,-2.5,2.5);
 TH1F* hTkSim_dpt        = new TH1F("hTkSim_dpt","",100,-0.5,0.5);
 TH1F* hTkSim_deta       = new TH1F("hTkSim_deta","",100,-0.1,0.1);
 TH1F* hTkSim_dphi       = new TH1F("hTkSim_dphi","",100,-0.5,0.5);
 TH1F* hTkSim_dphi0      = new TH1F("hTkSim_dphi0","",100,-0.1,0.1);
 TH1F* hTkSim_dpt_cut    = new TH1F("hTkSim_dpt_cut","",100,-0.5,0.5);

 //Usefull for BDT
 TH1F* hTkAll            = new TH1F("hTkAll","",201,-0.5,200.5);
 TH1F* hTkSim            = new TH1F("hTkSim","",101,-0.5,100.5);
 TH1F* hTkSim_pt         = new TH1F("hTkSim_pt","",100,0.,100.);
 TH1F* hTkSim_eta        = new TH1F("hTkSim_eta","",50,-2.5,2.5);
 TH1F* hTkSim_dr         = new TH1F("hTkSim_dr","",200,0.,10.);
 TH1F* hTkSim_dz         = new TH1F("hTkSim_dz","",200,0.,50.);
 TH1F* hTkSim_dd         = new TH1F("hTkSim_dd","",200,0.,50.);
 TH1F* hTkSim_drSig      = new TH1F("hTkSim_drSig","",200,0.,1000.);
 TH1F* hTkSim_dzSig      = new TH1F("hTkSim_dzSig","",200,0.,1000.);
 TH1F* hTkSim_ddSig      = new TH1F("hTkSim_ddSig","",200,0.,1000.);
 TH1F* hTkSim_inJet      = new TH1F("hTkSim_inJet","",2,-0.5,1.5);
 TH1F* hTkSim_pix        = new TH1F("hTkSim_pix","",30,-0.5,29.5);
 TH1F* hTkSim_hit        = new TH1F("hTkSim_hit","",30,-0.5,29.5);
 TH1F* hTkSim_chi        = new TH1F("hTkSim_chi","",50,0.,50.);
 TH1F* hTkSim_r1         = new TH1F("hTkSim_r1","",200,0.,100.);
 TH1F* hTkSim_z1         = new TH1F("hTkSim_z1","",200,0.,100.);
 
 
 TH1F* hTkSim_at10       = new TH1F("hTkSim_at10","",101,-0.5,100.5);
 TH1F* hTkSim_at20       = new TH1F("hTkSim_at20","",101,-0.5,100.5);
 TH1F* hTkSim_at30       = new TH1F("hTkSim_at30","",101,-0.5,100.5);
 TH1F* hTkSim_at40       = new TH1F("hTkSim_at40","",101,-0.5,100.5);
//plot added by paul
TH1F* hTk_eta        = new TH1F("hTk_eta","",50,-2.5,2.5);
TH1F* hTk_pt         = new TH1F("hTk_pt","",100,0.,100.);
TH1F* hTk_dr         = new TH1F("hTk_dr","",200,0.,10.);
TH1F* hTk_dz         = new TH1F("hTk_dz","",200,0.,50.);
TH1F* hTk_dd         = new TH1F("hTk_dd","",200,0.,50.);
TH1F* hTk_drSig      = new TH1F("hTk_drSig","",200,0.,1000.);
TH1F* hTk_dzSig      = new TH1F("hTk_dzSig","",200,0.,1000.);
TH1F* hTk_ddSig      = new TH1F("hTk_ddSig","",200,0.,1000.);
TH1F* hTk_inJet      = new TH1F("hTk_inJet","",2,-0.5,1.5);
TH1F* hTk_pix        = new TH1F("hTk_pix","",30,-0.5,29.5);
TH1F* hTk_hit        = new TH1F("hTk_hit","",30,-0.5,29.5);
TH1F* hTk_chi        = new TH1F("hTk_chi","",50,0.,50.);
TH1F* hTk_r1         = new TH1F("hTk_r1","",200,0.,100.);
TH1F* hTk_z1         = new TH1F("hTk_z1","",200,0.,100.);
TH1F* hTk_at10       = new TH1F("hTk_at10","",101,-0.5,100.5);
TH1F* hTk_at20       = new TH1F("hTk_at20","",101,-0.5,100.5);
TH1F* hTk_at30       = new TH1F("hTk_at30","",101,-0.5,100.5);
TH1F* hTk_at40       = new TH1F("hTk_at40","",101,-0.5,100.5);
//
 TH1F* hTkOth            = new TH1F("hTkOth","",101,-0.5,100.5);
 TH1F* hTkOth_pt	 = new TH1F("hTkOth_pt","",100,0.,100.);
 TH1F* hTkOth_eta        = new TH1F("hTkOth_eta","",50,-2.5,2.5);
 TH1F* hTkOth_dr	 = new TH1F("hTkOth_dr","",200,0.,10.);
 TH1F* hTkOth_dz	 = new TH1F("hTkOth_dz","",200,0.,50.);
 TH1F* hTkOth_dd	 = new TH1F("hTkOth_dd","",200,0.,50.);
 TH1F* hTkOth_drSig      = new TH1F("hTkOth_drSig","",200,0.,1000.);
 TH1F* hTkOth_dzSig      = new TH1F("hTkOth_dzSig","",200,0.,1000.);
 TH1F* hTkOth_ddSig      = new TH1F("hTkOth_ddSig","",200,0.,1000.);
 TH1F* hTkOth_inJet      = new TH1F("hTkOth_inJet","",2,-0.5,1.5);
 TH1F* hTkOth_pix        = new TH1F("hTkOth_pix","",30,-0.5,29.5);
 TH1F* hTkOth_hit        = new TH1F("hTkOth_hit","",30,-0.5,29.5);
 TH1F* hTkOth_chi        = new TH1F("hTkOth_chi","",50,0.,50.);
 TH1F* hTkOth_r1	 = new TH1F("hTkOth_r1","",200,0.,100.);
 TH1F* hTkOth_z1	 = new TH1F("hTkOth_z1","",200,0.,100.);
 TH1F* hTkOth_at10       = new TH1F("hTkOth_at10","",101,-0.5,100.5);
 TH1F* hTkOth_at20       = new TH1F("hTkOth_at20","",101,-0.5,100.5);
 TH1F* hTkOth_at30       = new TH1F("hTkOth_at30","",101,-0.5,100.5);
 TH1F* hTkOth_at40       = new TH1F("hTkOth_at40","",101,-0.5,100.5);

 TH1F* hData_Jet_njet      = new TH1F("hData_Jet_njet","",20,-0.5,19.5);
 TH1F* hData_Jet_pt        = new TH1F("hData_Jet_pt","",100,0.,1000.);
 TH1F* hData_Jet_eta	   = new TH1F("hData_Jet_eta","",50,-2.5,2.5);
 TH1F* hData_Jet_phi	   = new TH1F("hData_Jet_phi","",66,-3.3,3.3);
 TH1F* hData_Jet_pt1       = new TH1F("hData_Jet_pt1","",100,0.,1000.);
 TH1F* hData_Jet_pt2       = new TH1F("hData_Jet_pt2","",100,0.,1000.);
 TH1F* hData_Jet_dRmu      = new TH1F("hData_Jet_dRmu","",66,0.,3.3);

 TH1F* hDataGen_Jet_dpt    = new TH1F("hDataGen_Jet_dpt" ,"",100,-1.,1.);
 TH1F* hDataGen_Jet_deta   = new TH1F("hDataGen_Jet_deta","",100,-1.,1.);
 TH1F* hDataGen_Jet_dphi   = new TH1F("hDataGen_Jet_dphi","",100,-1.,1.);
 TH1F* hDataGen_Jet_pt     = new TH1F("hDataGen_Jet_pt","",100,0.,1000.);
 TH1F* hDataGen_Jet_eta	   = new TH1F("hDataGen_Jet_eta","",50,-2.5,2.5);

///////////////////////////////////////////////////////////////////

 if (fChain == 0) return;

 Long64_t nentries = fChain->GetEntriesFast();
 std::cout << "Total Entries : " << nentries << std::endl;
  
 Long64_t nbytes = 0, nb = 0;

 int nRecoTracks=0; 
 int nJets=0; 
 int count=0;

 int allevents = 0;
 int itest = 0;

 float deltaR;
 float mu_mass = 0.1057;
 TLorentzVector v1, v2, v, vmurec, vjet;

////////////////
// Event loop //
////////////////

 for (Long64_t jentry=0; jentry<nentries; jentry++) {
   Long64_t ientry = LoadTree(jentry);
 if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   allevents++;
   if ( allevents%1000 == 0 ) std::cout << "events : " << allevents << std::endl;
   
//$$
//   itest++;
//   if ( itest > 40 ) break;
//  std::cout << " " << std::endl;
//  std::cout << " Event " << eventNumber << std::endl; //quand on d�passe 10 , �a s'arrete!!!
//$$

///////////////////////
// ZMu filter

   int ngenpart =  tree_genParticle_pt->size();
//Quelques centaines event
   hDataAll_nZMu->Fill( tree_NbrOfZCand );
   bool ZMu = false;
   if ( tree_NbrOfZCand > 0 ) ZMu = true;
//$$
 if ( ngenpart > 0 && !ZMu ) continue; // only for MC at the moment , 
//$$


///////////////////////d�j� calcul� dans le ntuple
// Jet for HT computation

   float HTjet = 0.;

// Jets PF AK4
   int njetall = tree_AK4Slimmedjet_pt->size();
   for (int i=0; i<njetall; i++)    // Loop on jet
   {
     float jet_pt  = tree_AK4Slimmedjet_pt->at(i);
     float jet_eta = tree_AK4Slimmedjet_eta->at(i);
     float jet_phi = tree_AK4Slimmedjet_phi->at(i);
   if ( jet_pt < PtMin ) continue;
   if ( abs(jet_eta) > EtaMax ) continue;
     hDataAll_Jet_pt->Fill( jet_pt );
     hDataAll_Jet_eta->Fill( jet_eta );
     hDataAll_Jet_phi->Fill( jet_phi );
     HTjet += jet_pt;
   }	   // end Loop on jet
   hDataAll_Jet_njet->Fill( njetall );
   hDataAll_Jet_HT->Fill( HTjet );

//$$
 if ( HTjet < TagCut ) continue; //seuil minimum sur HTjet
//$$


///////////////////////
// reco muons

   int nmu =  tree_slimmedmuon_pt->size();
   hDataAll_nMu->Fill( nmu );
   int nmuglob = 0;
   float muptmax = 0.;

   for (int i=0; i<nmu; i++) {	     // Loop on reco muons
   if ( !tree_slimmedmuon_isGlobalMuon->at(i) ) continue;//Pour avoir des muons de qualit�s
     float mupt1  = tree_slimmedmuon_pt->at(i);
   if ( mupt1 < 10. ) continue;//Minimum threshold for the pt of muons defined by other papers
     if ( mupt1 > muptmax ) muptmax = mupt1;
     nmuglob++;
   }	   // end loop on reco muons

   hDataAll_nMuGlob->Fill( nmuglob );
   hDataAll_Mu_ptmax->Fill( muptmax );
   if ( muptmax > 28. ) hDataAll_nMuGlob_ptGT28->Fill( nmuglob ); //28GeV threshold for the pt of muons defined by other papers

//$$
 if ( muptmax < 28. || nmuglob < 2 ) continue; //Il nous au moins deux muons (produits par les smuons qui respectent le seuil �nergetique)
//$$
   

///////////////////////
// Primary Vertex

   int nPV =  tree_vtx_PosX->size();
   float PVx = tree_vtx_PosX->at(0);//l'index 0 donne le PV!   
   float PVy = tree_vtx_PosY->at(0);
   float PVz = tree_vtx_PosZ->at(0);

   float GenPVx, GenPVy, GenPVz;
   
   for (int i=0; i<ngenpart; i++)    // Loop on GenParticle : ngenpart computed line 279
   {
     float pdgId = tree_genParticle_pdgId->at(i); 
// smuon 1000013, abs for AP
     if ( abs(pdgId) == 1000013 ) {
       GenPVx = tree_genParticle_vx->at(i);
       GenPVy = tree_genParticle_vy->at(i);
       GenPVz = tree_genParticle_vz->at(i);
       break;
     }
   }    // end Loop on GenParticle
   

///////////////////////
// reco muons 

   bool ZMuRec = false;
   int PFiso, MVAiso, CutBasedId;
   float dVr, dVz;
   float Mmumu = 0.;
   int nmurec = 0, imu1 = -1, imu2 = -1;
   float mupt1, mueta1, muphi1, mupt2, mueta2, muphi2;

   for (int i=0; i<nmu; i++) {	     // Loop on reco muons
   if ( !tree_slimmedmuon_isGlobalMuon->at(i) ) continue;//On retrouve la condition sur les muons globaux
     mupt1  = tree_slimmedmuon_pt->at(i);
   if ( mupt1 < 10. ) continue;//On retrouve la condition sur les muons globaux
     dVr = TMath::Sqrt( (tree_slimmedmuon_vx->at(i)-PVx)*(tree_slimmedmuon_vx->at(i)-PVx) + (tree_slimmedmuon_vy->at(i)-PVy)*(tree_slimmedmuon_vy->at(i)-PVy) );
     dVz = tree_slimmedmuon_vz->at(i)-PVz;
     hData_Mu_dVr->Fill( dVr );
     hData_Mu_dVz->Fill( dVz );
   if ( dVr > 0.1 || abs(dVz) > 0.2 ) continue;// on veut un bon fit pour nos PV d'ou un seuil minimum sur les distances

     mueta1 = tree_slimmedmuon_eta->at(i);
     muphi1 = tree_slimmedmuon_phi->at(i);
     hData_Mu_pt->Fill( mupt1 );
     hData_Mu_eta->Fill( mueta1 );
     hData_Mu_phi->Fill( muphi1 );

     PFiso = 0;
     if      ( tree_slimmedmuon_PFisoVeryTight->at(i) ) PFiso = 4;
     else if ( tree_slimmedmuon_PFisoTight->at(i) )     PFiso = 3;
     else if ( tree_slimmedmuon_PFisoMedium->at(i) )    PFiso = 2;
     else if ( tree_slimmedmuon_PFisoLoose->at(i) )     PFiso = 1;
     hData_Mu_PFiso->Fill( PFiso );
     MVAiso = 0;
     if      ( tree_slimmedmuon_MVAisoTight->at(i) )    MVAiso = 3;
     else if ( tree_slimmedmuon_MVAisoMedium->at(i) )   MVAiso = 2;
     else if ( tree_slimmedmuon_MVAisoLoose->at(i) )    MVAiso = 1;
     hData_Mu_MVAiso->Fill( MVAiso );
     CutBasedId = 0;
     if      ( tree_slimmedmuon_CutBasedIdTight->at(i) )    CutBasedId = 4;
     else if ( tree_slimmedmuon_CutBasedIdMediumPrompt->at(i) )   CutBasedId = 3;
     else if ( tree_slimmedmuon_CutBasedIdMedium->at(i) )   CutBasedId = 2;
     else if ( tree_slimmedmuon_CutBasedIdLoose->at(i) )    CutBasedId = 1;
     hData_Mu_CutBasedId->Fill( CutBasedId );

     v1.SetPtEtaPhiM(mupt1,mueta1,muphi1,mu_mass);
     nmurec++;

   if ( i == nmu-1 ) continue;
     for (int j=i+1; j<nmu; j++) {	   // Loop on other reco muons
     if ( !tree_slimmedmuon_isGlobalMuon->at(j) ) continue;
     if ( tree_slimmedmuon_charge->at(i) == tree_slimmedmuon_charge->at(j) ) continue;
       dVr = TMath::Sqrt( (tree_slimmedmuon_vx->at(j)-PVx)*(tree_slimmedmuon_vx->at(j)-PVx) + (tree_slimmedmuon_vy->at(j)-PVy)*(tree_slimmedmuon_vy->at(j)-PVy) );
       dVz = tree_slimmedmuon_vz->at(j)-PVz;
     if ( dVr > 0.1 || abs(dVz) > 0.2 ) continue;
       mupt2  = tree_slimmedmuon_pt->at(j);
     if ( mupt2 < 10. ) continue;
     if ( mupt1 < 28. && mupt2 < 28. ) continue;
       mueta2 = tree_slimmedmuon_eta->at(j);
       muphi2 = tree_slimmedmuon_phi->at(j);
       v2.SetPtEtaPhiM(mupt2,mueta2,muphi2,mu_mass);
       v = v1 + v2;
       if ( v.Mag() > Mmumu ) {//Mag pour masse invariante (magnitude)
         Mmumu = v.Mag();
	 imu1 = i;
	 imu2 = j;
       }
     }	     // end loop on other reco muons
   }	   // end loop on reco muons

   hData_nMuRec->Fill( nmurec );
   hData_MuMu_mass->Fill( Mmumu );
//$$
   if ( Mmumu < 60. ) continue;//� regarder BG
//$$

   if ( tree_slimmedmuon_pt->at(imu2) > tree_slimmedmuon_pt->at(imu1) ) {
     int imu0 = imu2;
     imu2 = imu1;
     imu1 = imu0;
   }
   mupt1  = tree_slimmedmuon_pt->at(imu1);
   mueta1 = tree_slimmedmuon_eta->at(imu1);
   muphi1 = tree_slimmedmuon_phi->at(imu1);
   mupt2  = tree_slimmedmuon_pt->at(imu2);
   mueta2 = tree_slimmedmuon_eta->at(imu2);
   muphi2 = tree_slimmedmuon_phi->at(imu2);
   hData_Mu_pt1->Fill( mupt1 );
   hData_Mu_pt2->Fill( mupt2 );
   v1.SetPtEtaPhiM(mupt1,mueta1,muphi1,mu_mass);
   v2.SetPtEtaPhiM(mupt2,mueta2,muphi2,mu_mass);
   vmurec = v1 - v2;//plus besoin

   hData_nPV->Fill(nPV);
   hData_PVx->Fill( PVx );
   hData_PVy->Fill( PVy );
   hData_PVz->Fill( PVz );

   hGen_PVx->Fill( GenPVx );
   hGen_PVy->Fill( GenPVy );
   hGen_PVz->Fill( GenPVz );

   hDataGen_PV_dx->Fill( PVx - GenPVx );//gives gaussian centered on 0
   hDataGen_PV_dy->Fill( PVy - GenPVy );//gives gaussian centered on 0
   hDataGen_PV_dz->Fill( PVz - GenPVz );//gives gaussian centered on 0


///////////////////////
// GenParticle

//  std::cout << std::endl; 

   int ntop=0, nstoq=0;
   float Gen_top1_pt, Gen_top1_eta, Gen_top1_phi, Gen_top1_x, Gen_top1_y, Gen_top1_z, Gen_top1_r=-1., Gen_top1_d, Gen_top1_Vphi; 
   float Gen_top2_pt, Gen_top2_eta, Gen_top2_phi, Gen_top2_x, Gen_top2_y, Gen_top2_z, Gen_top2_r=-1., Gen_top2_d, Gen_top2_Vphi; 
   int Gen_top1_id = -1, Gen_top2_id = -1;
   int nq1 = 0, nq2 = 0;
   float dV, dV1, dV2, Vphi, deltaPhi, Vr, Vd, Vz, Veta;

   float genpt1 = 0., geneta1 = 0., genphi1 = 0.;
   float genpt2 = 0., geneta2 = 0., genphi2 = 0.;
   
   int snu[2], top[2], nsnu = 0, nsmu = 0;
   float bg1, bg2, gamma, ctau; 
   for (int k=0; k<2; k++) {
     snu[k] = -1;
     top[k] = -1;
   }
   TLorentzVector vsnu[2], vtop[2], vsq1[2], vsq2[2]; 
   
   for (int i=0; i<ngenpart; i++)    // Loop on GenParticle, ngenpart can be uo to one thousand, basically few hundreds
   {
     float pdgId = tree_genParticle_pdgId->at(i); 
     float mother_pdgId = tree_genParticle_mother_pdgId->at(i); 

//  std::cout << "id mother status " << pdgId << " " << mother_pdgId << " " << tree_genParticle_statusCode->at(i) 
//            << " pt " << tree_genParticle_pt->at(i) 
// 	   << " xyz " << tree_genParticle_vx->at(i) << " " << tree_genParticle_vy->at(i) << " " << tree_genParticle_vz->at(i) << std::endl; 

// smuon 1000013 cr��s lors de l'interaction
     if ( abs(pdgId) == 1000013 && mother_pdgId != pdgId ) {
       GenPVx = tree_genParticle_vx->at(i);
       GenPVy = tree_genParticle_vy->at(i);
       GenPVz = tree_genParticle_vz->at(i);
       hGen_smu_pt->Fill( tree_genParticle_pt->at(i) );
       hGen_smu_eta->Fill( tree_genParticle_eta->at(i) );
       nsmu++;
     }

// neutralino && smuon 1000013 : Si on a un neutralino qui provient d'un smuon alors...
     if ( abs(pdgId) == 1000023 && abs(mother_pdgId) == 1000013 ) {
       if ( snu[0] < 0 ) {
         snu[0] = i;//numero de la particule i<ngenpart
	 vsnu[0].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         nsnu++;
       }
       else if ( snu[1] < 0 ) {
         deltaR = DeltaR( tree_genParticle_eta->at(i), tree_genParticle_phi->at(i), tree_genParticle_eta->at(snu[0]), tree_genParticle_phi->at(snu[0]) );//snu[0]=i donc deltaR devrait donner 0 mais apr�s verif, i et snu[0� dans cette boucle sont bien differents ce qui am�ne deltaR != 0 comme on peut l'observer sur l'histo ci-dessous
         hGen_snu_DR->Fill( deltaR );
         snu[1] = i;
	 vsnu[1].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         nsnu++;
       }
       hGen_snu_pt->Fill( tree_genParticle_pt->at(i) );
       hGen_snu_eta->Fill( tree_genParticle_eta->at(i) );
     }

// top quark from neutralino
     if ( abs(pdgId) == 6 && abs(mother_pdgId) == 1000023 ) {
     
       if ( top[0] < 0 ) {
         top[0] = i;
	
	 vtop[0].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         Gen_top1_id  = abs(pdgId);
         Gen_top1_pt  = tree_genParticle_pt->at(i);
         Gen_top1_eta = tree_genParticle_eta->at(i);
         Gen_top1_phi = tree_genParticle_phi->at(i);
         Gen_top1_x   = tree_genParticle_vx->at(i);
         Gen_top1_y   = tree_genParticle_vy->at(i);
         Gen_top1_z   = tree_genParticle_vz->at(i);
         Gen_top1_r = TMath::Sqrt( (Gen_top1_x-GenPVx)*(Gen_top1_x-GenPVx) 
	                         + (Gen_top1_y-GenPVy)*(Gen_top1_y-GenPVy) );
         Gen_top1_d = TMath::Sqrt( Gen_top1_r*Gen_top1_r + (Gen_top1_z-GenPVz)*(Gen_top1_z-GenPVz) );
	 Vphi = TMath::ATan2( Gen_top1_y-GenPVy, Gen_top1_x-GenPVx );
         Gen_top1_Vphi = Vphi;
	 Vr = Gen_top1_r;
	 Vd = Gen_top1_d;
         Vz  = Gen_top1_z;
         Veta = Gen_top1_eta;
         ntop++;
//  std::cout << " Top " << ntop << " pdgId " << pdgId
//            << "  pt eta phi " << tree_genParticle_pt->at(i) << " " << tree_genParticle_eta->at(i) << " " << tree_genParticle_phi->at(i)
//            << "  x y z " << tree_genParticle_vx->at(i) << " " << tree_genParticle_vy->at(i) << " " << tree_genParticle_vz->at(i)
//            << std::endl;
       }
       else if ( top[1] < 0 ) {
         deltaR = DeltaR( tree_genParticle_eta->at(i), tree_genParticle_phi->at(i), tree_genParticle_eta->at(top[0]), tree_genParticle_phi->at(top[0]) );
         hGen_top_DR->Fill( deltaR );
         top[1] = i;
	 vtop[1].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         Gen_top2_id  = abs(pdgId);
         Gen_top2_pt  = tree_genParticle_pt->at(i);
         Gen_top2_eta = tree_genParticle_eta->at(i);
         Gen_top2_phi = tree_genParticle_phi->at(i);
         Gen_top2_x   = tree_genParticle_vx->at(i);
         Gen_top2_y   = tree_genParticle_vy->at(i);
         Gen_top2_z   = tree_genParticle_vz->at(i);
         Gen_top2_r = TMath::Sqrt( (Gen_top2_x-GenPVx)*(Gen_top2_x-GenPVx) 
	 			 + (Gen_top2_y-GenPVy)*(Gen_top2_y-GenPVy) );
         Gen_top2_d = TMath::Sqrt( Gen_top2_r*Gen_top2_r + (Gen_top2_z-GenPVz)*(Gen_top2_z-GenPVz) );
	 Vphi = TMath::ATan2( Gen_top2_y-GenPVy, Gen_top2_x-GenPVx );
         Gen_top2_Vphi = Vphi;
	 Vr = Gen_top2_r;
	 Vd = Gen_top2_d;
         Vz   = Gen_top2_z;
         Veta = Gen_top2_eta;
         ntop++;
//  std::cout << " Top " << ntop << " pdgId " << pdgId
//            << "  pt eta phi " << tree_genParticle_pt->at(i) << " " << tree_genParticle_eta->at(i) << " " << tree_genParticle_phi->at(i)
//            << "  x y z " << tree_genParticle_vx->at(i) << " " << tree_genParticle_vy->at(i) << " " << tree_genParticle_vz->at(i)
//            << std::endl;
       }
       hTopFromNeutralino->Fill(pdgId);//should be a displaced vertex here since smuon->neutralino->top
       hGen_top_z->Fill( abs(Vz) );
       hGen_top_r->Fill( Vr );
       hGen_top_d->Fill( Vd );
       hGen_top_pt->Fill( tree_genParticle_pt->at(i) );
       hGen_top_eta->Fill( Veta );
       hGen_top_phi->Fill( tree_genParticle_phi->at(i) );
       hGen_top_Vphi->Fill( Vphi );
       deltaPhi = DeltaPhi( Vphi, tree_genParticle_phi->at(i) );
       hGen_top_dVphi->Fill( deltaPhi );
     }
   }    // End Loop on GenParticle

   hGen_smu->Fill( nsmu );//Avec le diagramme de Feynmann considéré, les trois histo  
   hGen_snu->Fill( nsnu );//doivent et sont bien égaux
   hGen_top->Fill( ntop );
   
   if ( ntop == 2 ) {//si l'on regarde pour qq events, soit ntop==2 soit ==0
     deltaR = DeltaR( Gen_top1_eta, Gen_top1_phi, Gen_top2_eta, Gen_top2_phi );
     hGen_toptop_DR->Fill( deltaR );
     dV = (Gen_top2_x - Gen_top1_x)*(Gen_top2_x - Gen_top1_x)
        + (Gen_top2_y - Gen_top1_y)*(Gen_top2_y - Gen_top1_y)
        + (Gen_top2_z - Gen_top1_z)*(Gen_top2_z - Gen_top1_z);//ecart dans l'esapce entre les points d ed�sint�gration des neutralions
     dV = TMath::Sqrt(dV);
     hGen_toptop_DV->Fill( dV );
     deltaPhi = DeltaPhi( Gen_top2_Vphi, Gen_top1_Vphi );
     hGen_toptop_dVphi->Fill( deltaPhi );
   }

   for (int i=0; i<ngenpart; i++)    // Loop on GenParticle
   {
     float pdgId = tree_genParticle_pdgId->at(i); 
     float mother_pdgId = tree_genParticle_mother_pdgId->at(i); 
     float Gen_pt  = tree_genParticle_pt->at(i);
     float Gen_eta = tree_genParticle_eta->at(i);
     float Gen_phi = tree_genParticle_phi->at(i);

// quarks from stop and neutralino: stop 2 quarks while top 3 quarks: (1 down ; 3 strange ; 1000023 neutralino)
     if ( (abs(pdgId) == 1 || abs(pdgId) == 3) && abs(mother_pdgId) == 1000023) {//Pourquoi pas de condition motherpdgid= stop?
       dV1= 1000000.;
       dV2= 1000000.;
       if ( Gen_top1_r >= 0. ) 
       dV1 = (tree_genParticle_vx->at(i) - Gen_top1_x)*(tree_genParticle_vx->at(i) - Gen_top1_x)//Not sure how it works
           + (tree_genParticle_vy->at(i) - Gen_top1_y)*(tree_genParticle_vy->at(i) - Gen_top1_y)
           + (tree_genParticle_vz->at(i) - Gen_top1_z)*(tree_genParticle_vz->at(i) - Gen_top1_z);
       dV1 = TMath::Sqrt(dV1);
       if ( Gen_top2_r >= 0. ) 
       dV2 = (tree_genParticle_vx->at(i) - Gen_top2_x)*(tree_genParticle_vx->at(i) - Gen_top2_x)
           + (tree_genParticle_vy->at(i) - Gen_top2_y)*(tree_genParticle_vy->at(i) - Gen_top2_y)
           + (tree_genParticle_vz->at(i) - Gen_top2_z)*(tree_genParticle_vz->at(i) - Gen_top2_z);
       dV2 = TMath::Sqrt(dV2);
       dV = dV1;
       if ( dV2 < dV1 ) dV = dV2;//We take dV as the smallest distance between the two point calculated

       if ( dV1 < dV2 ) {
         if ( abs(pdgId) == 1 ) {//down quark
	   vsq1[0].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         }
         if ( abs(pdgId) == 3 ) {//strange quark
	   vsq2[0].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         }
         nq1++;
       }
       else {
         if ( abs(pdgId) == 1 ) {//down quark
	   vsq1[1].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         }
         if ( abs(pdgId) == 3 ) {//strange quark
	   vsq2[1].SetPtEtaPhiM(tree_genParticle_pt->at(i),tree_genParticle_eta->at(i),tree_genParticle_phi->at(i),tree_genParticle_mass->at(i));
         }
         nq2++;
       }
       hQuarksFromTops->Fill(pdgId);
       hGen_stoq_pt->Fill( Gen_pt );
       hGen_stoq_eta->Fill( Gen_eta );
       hGen_stoq_phi->Fill( Gen_phi );
       hGen_stoq_dV->Fill( dV );
       nstoq++;//nombre de stops?
     } // endif quarks from stop and neutralino

// muon from smuon : the one we want (13 muons )
   if ( abs(tree_genParticle_pdgId->at(i)) != 13 ) continue;
   if ( abs(tree_genParticle_mother_pdgId->at(i)) != 1000013 ) continue;
     float pdg_id = tree_genParticle_pdgId->at(i);
    //  std::cout << " pdgid " << pdg_id << std::endl;
     hGen_muon_pt->Fill( Gen_pt );
     hGen_muon_eta->Fill( Gen_eta );
     hMuonsFromSmuons->Fill(pdg_id);
     
     if ( Gen_pt > genpt1 ) {
       genpt2  = genpt1;
       geneta2 = geneta1;
       genphi2 = genphi1;
       genpt1  = Gen_pt;
       geneta1 = Gen_eta;
       genphi1 = Gen_phi;
     }
     else if ( Gen_pt > genpt2 ) {
       genpt2  = Gen_pt;
       geneta2 = Gen_eta;
       genphi2 = Gen_phi;
     }

   }    // End Loop on GenParticle

   hGen_stoq->Fill( nstoq );
   hGen_quark->Fill( nq1+nq2 );
   
// neutralino beta gamma and ctau
   if ( snu[0]>=0 && snu[1]>=0 && top[0]>=0 && top[1]>=0 && ntop == 2 && nstoq == 4 ) {
     v = vtop[0] + vsq1[0] + vsq2[0];
     float testE0 = v.E() / vsnu[0].E() - 1.;
     hGen_snu_testE0->Fill( testE0 );
     gamma = vsnu[0].E() / vsnu[0].Mag();
     bg1 = TMath::Sqrt( gamma*gamma - 1 );
     gamma = vsnu[1].E() / vsnu[1].Mag();
     bg2 = TMath::Sqrt( gamma*gamma - 1 );
     hGen_top_bg->Fill( bg1 );
     hGen_top_bg->Fill( bg2 );
     if ( abs(testE0) < 0.1 ) {  // snu0 gives top0
       ctau = Gen_top1_d / bg1;//effet de seuil du au bg 
       hGen_top_ctau->Fill( ctau );
       ctau = Gen_top2_d / bg2;
       hGen_top_ctau->Fill( ctau );
     } 
   }

   hGen_muon_pt1->Fill( genpt1 );
   hGen_muon_pt2->Fill( genpt2 );
   v1.SetPtEtaPhiM(genpt1,geneta1,genphi1,mu_mass);
   v2.SetPtEtaPhiM(genpt2,geneta2,genphi2,mu_mass);
   v = v1 + v2;
   float genMmumu = v.Mag();
   hGen_mumu_mass->Fill( genMmumu );
   
   //Comparaison entre g�n�r� et reco
   hDataGen_mu_dpt->Fill( mupt1 / genpt1 );
   hDataGen_mu_deta->Fill( mueta1 - geneta1 );
   hDataGen_mu_dphi->Fill( DeltaPhi( muphi1, genphi1 ) );
   hDataGen_mu_dpt->Fill( mupt2 / genpt2 );
   hDataGen_mu_deta->Fill( mueta2 - geneta2 );
   hDataGen_mu_dphi->Fill( DeltaPhi( muphi2, genphi2 ) );


// ///////////////////////
// // Compute GenParticle from LLP at PV
// 
//    int gen_fromLLP[5000];
//    float gen_phi0[5000];
//    if ( ngenpart >= 5000 ) std::cout << " ##### ERROR ngenpart ##### " << ngenpart << std::endl;
// 
//    for (int i=0; i<ngenpart; i++)    // RERE Loop on GenParticle
//    {
//      gen_fromLLP[i]= -1;
//      float pdgId = tree_genParticle_pdgId->at(i); 
//    if ( pdgId != 11 && pdgId != 13 && pdgId != 211 && pdgId != 321 && pdgId != 2212 ) continue;   
//      float Gen_vx  = tree_genParticle_vx->at(i);
//      float Gen_vy  = tree_genParticle_vy->at(i);
//      float Gen_vz  = tree_genParticle_vz->at(i);
//      float dv1= 1000000.;
//      float dv2= 1000000.;
//      if ( Gen_top1_r >= 0. ) 
//      dv1 = (Gen_vx - Gen_top1_x)*(Gen_vx - Gen_top1_x)
//      	 + (Gen_vy - Gen_top1_y)*(Gen_vy - Gen_top1_y)
//      	 + (Gen_vz - Gen_top1_z)*(Gen_vz - Gen_top1_z);
//      if ( Gen_top2_r >= 0. ) 
//      dv2 = (Gen_vx - Gen_top2_x)*(Gen_vx - Gen_top2_x)
//      	 + (Gen_vy - Gen_top2_y)*(Gen_vy - Gen_top2_y)
//      	 + (Gen_vz - Gen_top2_z)*(Gen_vz - Gen_top2_z);
//      float dv = TMath::Sqrt(dv1);
//      if ( dv2 < dv1 ) dv = TMath::Sqrt(dv2);
//      hGenTk_dv->Fill( dv );
//      hGenTk_dv_big->Fill( dv );
//    if ( dv > 0.1 ) continue;
// 
//      if (dv1 <= dv2 ) gen_fromLLP[i]= 1;
//      else             gen_fromLLP[i]= 2;
//      float Gen_pt  = tree_genParticle_pt->at(i);
//      float Gen_eta = tree_genParticle_eta->at(i);
//      float Gen_phi = tree_genParticle_phi->at(i);
//      float Gen_q   = tree_genParticle_charge->at(i);
//      float qR = Gen_q * Gen_pt * 100 / 0.3 / 3.8;
//      float sin0 = qR * sin( Gen_phi ) + Gen_vx;
//      float cos0 = qR * cos( Gen_phi ) - Gen_vy;
//      float phi0 = TMath::ATan2( sin0, cos0 ); // but note that it can be wrong by +_pi !
//      hGenTk_phi0->Fill( phi0 );
//      gen_phi0[i] = phi0;
//    }


///////////////////////
// Track or TrackSim

   int ntrack =  tree_track_pt->size();//basically 200 == ntrack
   hData_nTk->Fill(ntrack);
   
   int nTkSim = 0, nTkOth = 0;
   int ntracksim = tree_track_simtrack_pt->size();
   if ( ngenpart > 0 && ntrack != ntracksim ) std::cout << " ##### ERROR ntrack ntracksim ##### " << ntrack << " " << ntracksim << std::endl;

   int track_isfromLLP[1000], track_SEL40[1000];
   bool track_SELEC[1000];
   if ( ntrack >= 1000 ) std::cout << " ##### ERROR ntrack ##### " << ntrack << std::endl;//Dasn le cas actuel, ne sert  � rien car environ 200 tracks en moyenne 

   for (int i=0; i<ntrack; i++)    // Loop on Track or TrackSim
   {
     track_isfromLLP[i] = -1;
     int iV = -1;
     int ntrk10 = 0, ntrk20 = 0, ntrk30 = 0, ntrk40 = 0;
     track_SEL40[i] = 0;//ça n'sert à rien 
     track_SELEC[i] = false;
    //variables used for the GBT are here : #############################################
     float q   = tree_track_charge->at(i);
     float pt  = tree_track_pt->at(i);
     float eta = tree_track_eta->at(i);
     float phi = tree_track_phi->at(i);
     float dr = abs(tree_track_dxy->at(i));
     float drSig = -1., dzSig = -1., ddSig = -1.;
     if ( tree_track_dxyError->at(i) > 0 ) drSig = dr / tree_track_dxyError->at(i);//If thisis done..
     float dz = abs(tree_track_dz->at(i));
     if ( tree_track_dzError->at(i) > 0 )  dzSig = dz / tree_track_dzError->at(i);//... and this is also done
     float dd = TMath::Sqrt( dr*dr + dz*dz );
     if ( drSig>0 && dzSig>0 ) ddSig = TMath::Sqrt( drSig*drSig + dzSig*dzSig );//Therefore, it is also done
     float pix = tree_track_numberOfValidPixelHits->at(i);
     float hit = tree_track_nhits->at(i);
     float chi = tree_track_NChi2->at(i);//chi2 per dof
     float x1 = tree_track_firsthit_X->at(i);
     float y1 = tree_track_firsthit_Y->at(i);
     float z1 = abs(tree_track_firsthit_Z->at(i));
     float r1 = TMath::Sqrt( x1*x1 + y1*y1 );
     int inJet = 0;
     int jet = tree_track_recoAK4SlimmedJet_idx->at(i);
     //End of Variables used for GBT ####################################################
     if ( jet >= 0 ) inJet = 1;

     if ( pt >= 1. && chi <= 5. && drSig >= 5. ) track_SELEC[i] = true;//selection de potentielles traces secondaires

// sim tracks associated to reco tracks
     float ptSim  = -1.;
     
     if ( ntracksim > 0 ) ptSim = tree_track_simtrack_pt->at(i);//Normalement toujours v�rifi� => condition if (ngenpart >0 && ntrack != ntracksim) au-dessus
     if ( ntracksim > 0 && ptSim > 0. && tree_track_isSimMatched->at(i) ) {
       
       float qSim   = tree_track_simtrack_charge->at(i);
       float etaSim = tree_track_simtrack_eta->at(i);
       float phiSim = tree_track_simtrack_phi->at(i);
       float vxgen  = tree_track_genVertexPos_X->at(i);//most of them are at 0 (gaussian distri but some are at -1000 Heavyside function, ??
       float vygen  = tree_track_genVertexPos_Y->at(i);
       float vzgen  = tree_track_genVertexPos_Z->at(i);
       float qR = tree_track_simtrack_charge->at(i) * ptSim * 100 / 0.3 / 3.8;//besoin de la courbre: tesla pour 3,8 100 pour les cm en m
       float sin0 = qR * sin( phiSim ) + vxgen;
       float cos0 = qR * cos( phiSim ) - vygen;
       float phi0 = TMath::ATan2( sin0, cos0 ); // but note that it can be wrong by +_pi ! 

       dV1= 1000000.;
       dV2= 1000000.;
       //comparison between sim associated with reco and gen
       if ( Gen_top1_r >= 0. ) 
       dV1 = (vxgen - Gen_top1_x)*(vxgen - Gen_top1_x)
       	   + (vygen - Gen_top1_y)*(vygen - Gen_top1_y)
           + (vzgen - Gen_top1_z)*(vzgen - Gen_top1_z);
       if ( Gen_top2_r >= 0. ) 
       dV2 = (vxgen - Gen_top2_x)*(vxgen - Gen_top2_x)
           + (vygen - Gen_top2_y)*(vygen - Gen_top2_y)
           + (vzgen - Gen_top2_z)*(vzgen - Gen_top2_z);
       dV = TMath::Sqrt(dV1);
       if ( dV2 < dV1 ) dV = TMath::Sqrt(dV2);
//$$
       if ( dV < 0.1 && dV1 <= dV2 ) iV = 1;
       if ( dV < 0.1 && dV2 < dV1 )  iV = 2;
       if ( dV < 0.1 ) track_isfromLLP[i] = iV;
//$$

       if ( iV == 1 ) {
         deltaPhi = DeltaPhi( Gen_top1_Vphi, phiSim );
         Vr = Gen_top1_r;
       }
       if ( iV == 2 ) {
         deltaPhi = DeltaPhi( Gen_top2_Vphi, phiSim );
         Vr = Gen_top2_r;
       }

       int genLLP = tree_track_simtrack_isFromLLP->at(i);
       if ( genLLP >= 1 ) hTkGenLLP_test->Fill( iV - genLLP );//doit valoir 0 et vaut bien 0
       else               hTkGenLLPnot_test->Fill( iV );//on doit obtenir -1: valeur initiale de iV
       if ( genLLP >= 1 ) hTkGenLLP_dV->Fill( dV );
       else               hTkGenLLPnot_dV->Fill( dV );
       
       if ( track_SELEC[i] ) {
         hTkSim_dV->Fill( dV );
         hTkSim_dV_big->Fill( dV );

         if ( iV >= 1 ) {//true si vient d'un neutralino
           hTkSim_dphiTop->Fill( deltaPhi );
           float dpt = (pt - ptSim) / pt;
           float deta = eta - etaSim;
           float dphi0 = phi - phi0;
	   int genLLPid = tree_track_simtrack_pdgId->at(i);
	   if      ( dphi0 < -3.14159 / 2. ) dphi0 = dphi0 + 3.14159;
	   else if ( dphi0 >  3.14159 / 2. ) dphi0 = dphi0 - 3.14159;
           hTkSim_dq->Fill( q - qSim ); // why half of the reco tracks have a wrong charge ? qSim ? 
           hTkSim_dpt->Fill( dpt );
           hTkSim_deta->Fill( deta );
           hTkSim_dphi->Fill( phi - phiSim );
           hTkSim_dphi0->Fill( dphi0 );
          count=count+1;
	        hIsFromLLPid->Fill(genLLPid);
	   if ( abs(deta) < 0.1 && abs(dphi0) < 0.1 ) hTkSim_dpt_cut->Fill( dpt );
         }
       }
     }
 
   if ( !track_SELEC[i] ) continue;

//      for (int k=0; k<ngenpart; k++)    // Loop on GenParticle
//      {
//      if ( gen_fromLLP[k] < 0 ) continue; 
// //$$     if ( tree_genParticle_charge->at(k) != tree_track_charge->at(i) ) continue;
//        hGenTk_pt->Fill( pt );
// 
//        float Gen_pt  = tree_genParticle_pt->at(k);
//        float Gen_eta = tree_genParticle_eta->at(k);
//        float Gen_phi = tree_genParticle_phi->at(k);
//        float dpt  = pt / Gen_pt -1.;
//        float deta = eta - Gen_eta;
//        float dphi = phi - Gen_phi;
//        float dphi0 = phi - gen_phi0[k];
//        if      ( dphi0 < -3.14159 / 2. ) dphi0 = dphi0 + 3.14159;
//        else if ( dphi0 >  3.14159 / 2. ) dphi0 = dphi0 - 3.14159;
//        if ( iV >= 1 ) {
//          hGenTk_LLP_dpt->Fill( dpt );
//          hGenTk_LLP_deta->Fill( deta );
//          hGenTk_LLP_dphi->Fill( dphi );
//          hGenTk_LLP_dphi0->Fill( dphi0 );
// 	 if ( abs(deta) < 0.1 && abs(dphi0) < 0.1 ) {
//            hGenTk_LLP_dpt_cut->Fill( dpt );
//            if ( tree_genParticle_charge->at(k) == tree_track_charge->at(i) ) hGenTk_LLP_dpt_cut_ss->Fill( dpt );
//            else hGenTk_LLP_dpt_cut_os->Fill( dpt );
// 	 }
//        }
//        else if ( ntracksim > 0 && ptSim > 0. && tree_track_isSimMatched->at(i) ) {
//          hGenTk_Sim_dpt->Fill( dpt );
//          hGenTk_Sim_deta->Fill( deta );
//          hGenTk_Sim_dphi0->Fill( dphi0 );
// 	 if ( abs(deta) < 0.1 && abs(dphi0) < 0.1 ) {
//            hGenTk_Sim_dpt_cut->Fill( dpt );
// 	 }
//        }
//        else {
//          hGenTk_Oth_dpt->Fill( dpt );
//          hGenTk_Oth_deta->Fill( deta );
//          hGenTk_Oth_dphi0->Fill( dphi0 );
// 	 if ( abs(deta) < 0.1 && abs(dphi0) < 0.1 ) {
//            hGenTk_Oth_dpt_cut->Fill( dpt );
//            if ( tree_genParticle_charge->at(k) == tree_track_charge->at(i) ) hGenTk_Oth_dpt_cut_ss->Fill( dpt );
//            else hGenTk_Oth_dpt_cut_os->Fill( dpt );
//            if ( abs(dpt) < 0.1 ) track_isfromLLP[i] = gen_fromLLP[k];
// 	 }
//        }
//      }  // end Loop on GenParticle

     for (int k=0; k<ntrack; k++)    // Loop on other Tracks
     {
     if ( k == i ) continue;
       float pt2  = tree_track_pt->at(k);
       float dr2 = abs(tree_track_dxy->at(k));
       float drSig2 = -1.;
       if ( tree_track_dxyError->at(k) > 0 ) drSig2 = dr2 / tree_track_dxyError->at(k);
       float chi2 = tree_track_NChi2->at(k);
     if ( !(pt2 >= 1. && chi2 <= 5. && drSig2 >= 5.) ) continue;//On regarde les autres track_selec[i] qui sont True donc de potnetielles tracks secondaires
       float x2 = tree_track_firsthit_X->at(k);
       float y2 = tree_track_firsthit_Y->at(k);
       float z2 = abs(tree_track_firsthit_Z->at(k));
       float dist = TMath::Sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) );//pour chaque reconstuite, on regarde les autres tracks, 
       if ( dist < 10. ) ntrk10++; 
       if ( dist < 20. ) ntrk20++; 
       if ( dist < 30. ) ntrk30++; 
       if ( dist < 40. ) ntrk40++;//used in BDT, peut �tre une variable discriminante
     }  // end Loop on other Tracks

    //added by Paul
    hTk_eta->Fill(eta);
    hTk_pt->Fill(pt);
    hTk_dr         ->Fill(dr);
    hTk_dz         ->Fill(dz);
    hTk_dd         ->Fill(dd);
    hTk_drSig      ->Fill(drSig);
    hTk_dzSig      ->Fill(dzSig);
    hTk_ddSig      ->Fill(ddSig);
    hTk_inJet      ->Fill(inJet);
    hTk_pix        ->Fill(pix);
    hTk_hit        ->Fill(hit);
    hTk_chi        ->Fill(chi);
    hTk_r1         ->Fill(r1);
    hTk_z1         ->Fill(z1);
    hTk_at10       ->Fill(ntrk10);
    hTk_at20       ->Fill(ntrk20);
    hTk_at30       ->Fill(ntrk30);
    hTk_at40       ->Fill(ntrk40);
     if ( track_isfromLLP[i] > 0 ) {
     //Dans cette partie, les tracks simul�es sont associ�es � des tracks reconstruites qui sont potentiellement de tracks secondaires qui viennent d'un neutralino
       nTkSim++;
       
       hTkSim_pt->Fill( pt );
       hTkSim_eta->Fill( eta );
       hTkSim_dr->Fill( dr );
       hTkSim_dz->Fill( dz );
       hTkSim_dd->Fill( dd );
       hTkSim_drSig->Fill( drSig );
       hTkSim_dzSig->Fill( dzSig );
       hTkSim_ddSig->Fill( ddSig );
       hTkSim_inJet->Fill( inJet );
       hTkSim_pix->Fill( pix );
       hTkSim_hit->Fill( hit );
       hTkSim_chi->Fill( chi );
       hTkSim_r1->Fill( r1 );
       hTkSim_z1->Fill( z1 );
       //fin de ce que prend en entr�e le BDT
       //efficace peu importe les valeurs: dur�e de vie du neutralino, distance avant decay 10-50 ==> indepednant des valeurs en entr�e
       hTkSim_at10->Fill( ntrk10 );
       hTkSim_at20->Fill( ntrk20 );
       hTkSim_at30->Fill( ntrk30 );
       hTkSim_at40->Fill( ntrk40 );
       ///Implémentation Paul
       hr1_f_z1->Fill(r1,z1);
       h_x1_y1_z1->Fill(x1,y1,z1);
       hTracksCharge->Fill(q);
       if (eta>1.5)
        {hr1_etasup1_5->Fill(r1);}
       else
        {hz1_etainf1_5->Fill(z1);}
     }
//BDT, prend en entr�e les variables discriminantes, rend une proba d'�tre d'un neutralino ou non
     else {
       nTkOth++;
       hTkOth_pt->Fill( pt );
       hTkOth_eta->Fill( eta );
       hTkOth_dr->Fill( dr );
       hTkOth_dz->Fill( dz );
       hTkOth_dd->Fill( dd );
       hTkOth_drSig->Fill( drSig );
       hTkOth_dzSig->Fill( dzSig );
       hTkOth_ddSig->Fill( ddSig );
       hTkOth_inJet->Fill( inJet );
       hTkOth_pix->Fill( pix );
       hTkOth_hit->Fill( hit );
       hTkOth_chi->Fill( chi );
       hTkOth_r1->Fill( r1 );
       hTkOth_z1->Fill( z1 );
       hTkOth_at10->Fill( ntrk10 );
       hTkOth_at20->Fill( ntrk20 );
       hTkOth_at30->Fill( ntrk30 );
       hTkOth_at40->Fill( ntrk40 );
     }

   }  // end Loop on Track or TrackSim

   hTkSim->Fill( nTkSim );
   hTkOth->Fill( nTkOth );
   hTkAll->Fill( nTkSim + nTkOth );


///////////////////////
// genJet AK4
   int ngenjet = tree_genJet_pt->size();

///////////////////////
// Jet

   int njet = 0;
   float jetpt1 = 0., jetpt2 = 0.;

   float njetsim = 0;
   int nTkSimJetAll = 0;

   int ntksel1 = 0, ntksel2 = 0, ntkselo = 0;
   TLorentzVector vtop1, vtop2;

// Jets PF AK4
   for (int i=0; i<njetall; i++)    // Loop on jet
   {
     float jet_pt  = tree_AK4Slimmedjet_pt->at(i);
     float jet_eta = tree_AK4Slimmedjet_eta->at(i);
     float jet_phi = tree_AK4Slimmedjet_phi->at(i);

   if ( jet_pt < PtMin ) continue;
   if ( abs(jet_eta) > EtaMax ) continue;
     hData_Jet_pt->Fill( jet_pt );
     hData_Jet_eta->Fill( jet_eta );
     hData_Jet_phi->Fill( jet_phi );
     
     if ( jet_pt > jetpt1 ) {
       jetpt2 = jetpt1;
       jetpt1 = jet_pt;
     }
     else if ( jet_pt > jetpt2 ) {
       jetpt2 = jet_pt;
     }
     njet++;

     bool isMatched = false;
     for (int j=0; j<ngenjet; j++)    // Loop on genJet
     {
       float genjet_pt  = tree_genJet_pt->at(j);
       float genjet_eta = tree_genJet_eta->at(j);
       float genjet_phi = tree_genJet_phi->at(j);

       hDataGen_Jet_deta->Fill( jet_eta - genjet_eta );
       hDataGen_Jet_dphi->Fill( jet_phi - genjet_phi );
       if ( abs(jet_eta - genjet_eta)<0.1 && abs(jet_phi - genjet_phi)<0.1 ) {
         hDataGen_Jet_dpt->Fill( jet_pt/genjet_pt - 1. );
	 isMatched = true;
       }
     }	   // end Loop on genJet
     if ( isMatched ) {
       hDataGen_Jet_pt->Fill( jet_pt );
       hDataGen_Jet_eta->Fill( jet_eta );
     }

// look if prompt muon inside
     float deltaR1 = 1000., deltaR2 = 1000.;
     if ( imu1 >= 0 ) deltaR1 = DeltaR( jet_eta, jet_phi, tree_slimmedmuon_eta->at(imu1), tree_slimmedmuon_phi->at(imu1) );
     if ( imu2 >= 0 ) deltaR2 = DeltaR( jet_eta, jet_phi, tree_slimmedmuon_eta->at(imu2), tree_slimmedmuon_phi->at(imu2) );
     hData_Jet_dRmu->Fill( deltaR1 );
     hData_Jet_dRmu->Fill( deltaR2 );
      
   }	   // end Loop on jet

   hData_Jet_njet->Fill( njet );
   hData_Jet_pt1->Fill( jetpt1 );
   hData_Jet_pt2->Fill( jetpt2 );

 } // end loop on events 

 std::cout << "number of events  "<< allevents << std::endl; 
 std::cout << "number of tracks  "<< nRecoTracks << std::endl; //nRecoTracks is not modified in the current version 
 std::cout << "number of jets    "<< nJets << std::endl; //nJets is not modified in the current version
std::cout << "number of particles coming from LLP "<< count << std::endl; 
//################################################

// Output Postscript

//   TCanvas* c = new TCanvas("c");
  hData_nPV -> Draw(); 
//   c->Print("output.ps(");
  
//################################################
  HistogramManager h ;
  
  h.WriteAllHistogramsInFile(filename.Data(),"recreate");
//################################################
}   
