
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

 TH1F* hGen_smu_test	= new TH1F("hGen_smu_test","",3,-1.5,1.5);
 TH1F* hGen_smu_testM   = new TH1F("hGen_smu_testM","",100,-0.5,0.5);
 TH1F* hGen_smu_pt      = new TH1F("hGen_smu_pt","",50,0.,1000.);
 TH1F* hGen_smu_eta     = new TH1F("hGen_smu_eta","",50,-5.,5.);
 TH1F* hGen_smusmu_DR   = new TH1F("hGen_smusmu_DR","",100,0.,5.);
 TH1F* hGen_smusmu_dphi = new TH1F("hGen_smusmu_dphi","",33,0.,3.3);

 TH1F* hGen_muon	= new TH1F("hGen_muon","",10,-0.5,9.5);
 TH1F* hGen_muon_pt     = new TH1F("hGen_muon_pt","",50,0.,500.);
 TH1F* hGen_muon_eta    = new TH1F("hGen_muon_eta","",50,-2.5,2.5);
 TH1F* hGen_mumu_mass   = new TH1F("hGen_mumu_mass","",100,0.,400.);
 TH1F* hGen_muonsmu_DR   = new TH1F("hGen_muonsmu_DR","",100,0.,5.);
 TH1F* hGen_muonsmu_dphi = new TH1F("hGen_muonsmu_dphi","",33,0.,3.3);

 TH1F* hGen_neu         = new TH1F("hGen_neu","",5,-0.5,4.5);
 TH1F* hGen_neu_pt      = new TH1F("hGen_neu_pt","",50,0.,1000.);
 TH1F* hGen_neu_eta     = new TH1F("hGen_neu_eta","",50,-5.,5.);
 TH1F* hGen_neuneu_DR   = new TH1F("hGen_neuneu_DR","",50,0.,5.);
 TH1F* hGen_neuneu_dphi = new TH1F("hGen_neuneu_dphi","",33,0.,3.3);
 TH1F* hGen_neusmu_DR   = new TH1F("hGen_neusmu_DR","",50,0.,5.);
 TH1F* hGen_neusmu_dphi = new TH1F("hGen_neusmu_dphi","",33,0.,3.3);
 TH1F* hGen_neumu_DR    = new TH1F("hGen_neumu_DR","",100,0.,5.);
 TH1F* hGen_neumu_dphi  = new TH1F("hGen_neumu_dphi","",33,0.,3.3);
 TH1F* hGen_neu_testE   = new TH1F("hGen_neu_testE","",100,-0.5,0.5);
 TH1F* hGen_neuqtop_DR  = new TH1F("hGen_neuqtop_DR","",50,0.,5.);
 TH1F* hGen_neuqtop_dphi= new TH1F("hGen_neuqtop_dphi","",33,0.,3.3);
 TH1F* hGen_neuqtop_deta= new TH1F("hGen_neuqtop_deta","",50,0.,5.);
 TH1F* hGen_neulepW_DR  = new TH1F("hGen_neulepW_DR","",50,0.,5.);
 TH1F* hGen_neulepW_dphi= new TH1F("hGen_neulepW_dphi","",33,0.,3.3);
 TH1F* hGen_neulepW_deta= new TH1F("hGen_neulepW_deta","",50,0.,5.);
 TH1F* hGen_neusq_DR    = new TH1F("hGen_neusq_DR","",50,0.,5.);
 TH1F* hGen_neusq_dphi  = new TH1F("hGen_neusq_dphi","",33,0.,3.3);
 TH1F* hGen_neusq_deta  = new TH1F("hGen_neusq_deta","",50,0.,5.);

 TH1F* hGen_top         = new TH1F("hGen_top","",5,-0.5,4.5);
 TH1F* hGen_top_r       = new TH1F("hGen_top_r","",100,0.,100.);
 TH1F* hGen_top_z       = new TH1F("hGen_top_z","",100,0.,200.);
 TH1F* hGen_top_d       = new TH1F("hGen_top_d","",100,0.,1000.);
 TH1F* hGen_top_pt      = new TH1F("hGen_top_pt","",50,0.,500.);
 TH1F* hGen_top_eta     = new TH1F("hGen_top_eta","",50,-5.,5.);
 TH1F* hGen_top_bg      = new TH1F("hGen_top_bg","",50,0.,20.);
 TH1F* hGen_top_ctau    = new TH1F("hGen_top_ctau","",100,0.,200.);
 TH1F* hGen_top_Vphi    = new TH1F("hGen_top_Vphi","",66,-3.3,3.3);
 TH1F* hGen_top_dVphi   = new TH1F("hGen_top_dVphi","",33,0.,3.3);
 TH1F* hGen_toptop_DR   = new TH1F("hGen_toptop_DR","",100,0.,5.);
 TH1F* hGen_toptop_dV   = new TH1F("hGen_toptop_dV","",100,0.,200.);
 TH1F* hGen_toptop_dVphi = new TH1F("hGen_toptop_dVphi","",33,0.,3.3);

 TH1F* hGen_qtop	= new TH1F("hGen_qtop","",10,-0.5,9.5);
 TH1F* hGen_qtop_pt     = new TH1F("hGen_qtop_pt","",50,0.,500.);
 TH1F* hGen_qtop_eta    = new TH1F("hGen_qtop_eta","",50,-2.5,2.5);
 TH1F* hGen_qtop_dV     = new TH1F("hGen_qtop_dV","",100,0.,0.01);

 TH1F* hGen_lepW	= new TH1F("hGen_lepW","",10,-0.5,9.5);
 TH1F* hGen_lepW_pt     = new TH1F("hGen_lepW_pt","",50,0.,500.);
 TH1F* hGen_lepW_eta    = new TH1F("hGen_lepW_eta","",50,-2.5,2.5);
 TH1F* hGen_lepW_dV     = new TH1F("hGen_lepW_dV","",100,0.,0.01);

 TH1F* hGen_stoq 	= new TH1F("hGen_stoq","",10,-0.5,9.5);
 TH1F* hGen_stoq_pt	= new TH1F("hGen_stoq_pt","",50,0.,500.);
 TH1F* hGen_stoq_eta	= new TH1F("hGen_stoq_eta","",50,-2.5,2.5);
 TH1F* hGen_stoq_dV     = new TH1F("hGen_stoq_dV","",100,0.,0.01);

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

 TH1F* hData_MET           = new TH1F("hData_MET","",100,0.,1000.);
 TH1F* hData_MET_phi	   = new TH1F("hData_MET_phi","",66,-3.3,3.3);

 TH1F* hData_Jet_njet      = new TH1F("hData_Jet_njet","",20,-0.5,19.5);
 TH1F* hData_Jet_pt        = new TH1F("hData_Jet_pt","",100,0.,1000.);
 TH1F* hData_Jet_eta	   = new TH1F("hData_Jet_eta","",50,-2.5,2.5);
 TH1F* hData_Jet_phi	   = new TH1F("hData_Jet_phi","",66,-3.3,3.3);
 TH1F* hData_Jet_pt1       = new TH1F("hData_Jet_pt1","",100,0.,1000.);
 TH1F* hData_Jet_pt2       = new TH1F("hData_Jet_pt2","",100,0.,1000.);
 TH1F* hData_Jet_dRmu      = new TH1F("hData_Jet_dRmu","",66,0.,3.3);
 TH1F* hData_Jet_pt_test   = new TH1F("hData_Jet_pt_test","",100,0.,1000.);
 TH1F* hData_Jet_ntrksel   = new TH1F("hData_Jet_ntrksel","",41,-0.5,40.5);
 TH1F* hData_Jet_njet_forLLP = new TH1F("hData_Jet_njet_forLLP","",20,-0.5,19.5);

 TH1F* hData_Jet1          = new TH1F("hData_Jet1","",21,-0.5,20.5);
 TH1F* hData_Jet1_METpt    = new TH1F("hData_Jet1_METpt","",100,0.,10.);
 TH1F* hData_Jet1_METdphi  = new TH1F("hData_Jet1_METdphi","",33,0.,3.3);
 TH1F* hData_Jet1_ntrksel  = new TH1F("hData_Jet1_ntrksel","",41,-0.5,40.5);
 TH1F* hData_Jet2          = new TH1F("hData_Jet2","",21,-0.5,20.5);

//  TH1F* hData_eljet_dR      = new TH1F("hData_eljet_dR","",50,0.,5.);
//  TH1F* hData_elaxis_dR     = new TH1F("hData_elaxis_dR","",50,0.,5.);
//  TH1F* hData_mujet_dR      = new TH1F("hData_mujet_dR","",50,0.,5.);
//  TH1F* hData_muaxis_dR     = new TH1F("hData_muaxis_dR","",50,0.,5.);
//  TH1F* hData_METaxis_dphi  = new TH1F("hData_METaxis_dphi","",33,0.,3.3);

 TH1F* hDataGen_LLPrec1_dR  = new TH1F("hDataGen_LLPrec1_dR","",50,0.,5.);
 TH1F* hDataGen_LLPrec1_dphi= new TH1F("hDataGen_LLPrec1_dphi","",33,0.,3.3);
 TH1F* hDataGen_LLPrec1_deta= new TH1F("hDataGen_LLPrec1_deta","",50,0.,5.);
 TH1F* hDataGen_LLPrec2_sym_dR  = new TH1F("hDataGen_LLPrec2_sym_dR","",50,0.,5.);
 TH1F* hDataGen_LLPrec2_sym_dphi= new TH1F("hDataGen_LLPrec2_sym_dphi","",33,0.,3.3);
 TH1F* hDataGen_LLPrec2_dR  = new TH1F("hDataGen_LLPrec2_dR","",50,0.,5.);
 TH1F* hDataGen_LLPrec2_dphi= new TH1F("hDataGen_LLPrec2_dphi","",33,0.,3.3);
 TH1F* hDataGen_LLPrec2_deta= new TH1F("hDataGen_LLPrec2_deta","",50,0.,5.);
 TH1F* hDataGen_LLPrec2_dRsym  = new TH1F("hDataGen_LLPrec2_dRsym","",50,0.,5.);
 TH1F* hDataGen_LLPrec2_dphisym= new TH1F("hDataGen_LLPrec2_dphisym","",33,0.,3.3);
 TH1F* hDataGen_Jet_dpt    = new TH1F("hDataGen_Jet_dpt" ,"",100,-1.,1.);
 TH1F* hDataGen_Jet_deta   = new TH1F("hDataGen_Jet_deta","",100,-1.,1.);
 TH1F* hDataGen_Jet_dphi   = new TH1F("hDataGen_Jet_dphi","",100,-1.,1.);
 TH1F* hDataGen_Jet_pt     = new TH1F("hDataGen_Jet_pt","",100,0.,1000.);
 TH1F* hDataGen_Jet_eta	   = new TH1F("hDataGen_Jet_eta","",50,-2.5,2.5);
 TH1F* hData_Jetaxis_dR    = new TH1F("hData_Jetaxis_dR","",50,0.,5.);
 TH1F* hData_Jet_Track_dR  = new TH1F("hData_Jet_Track_dR","",50,0.,5.);
 TH1F* hData_Tracks_repart = new TH1F("hData_Tracks_repart","",4,0.,3.);
 TH1F* hData_Muon_Axis_dR4   = new TH1F("hData_Muon_Axis_dR4","",4,0.,3.);

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
 TH1F* hTkSim_z1         = new TH1F("hTkSim_z1","",210,0.,210.);
 TH1F* hTkSim_at10       = new TH1F("hTkSim_at10","",101,-0.5,100.5);
 TH1F* hTkSim_at20       = new TH1F("hTkSim_at20","",101,-0.5,100.5);
 TH1F* hTkSim_at30       = new TH1F("hTkSim_at30","",101,-0.5,100.5);
 TH1F* hTkSim_at40       = new TH1F("hTkSim_at40","",101,-0.5,100.5);
 TH1F* hTkSim_r1_PXB     = new TH1F("hTkSim_r1_PXB","",200,0.,100.);
 TH1F* hTkSim_r1_TIB     = new TH1F("hTkSim_r1_TIB","",200,0.,100.);
 TH1F* hTkSim_r1_TOB     = new TH1F("hTkSim_r1_TOB","",200,0.,100.);
 TH1F* hTkSim_z1_PXF     = new TH1F("hTkSim_z1_PXF","",210,0.,210.);
 TH1F* hTkSim_z1_TID     = new TH1F("hTkSim_z1_TID","",210,0.,210.);
 TH1F* hTkSim_z1_TEC     = new TH1F("hTkSim_z1_TEC","",210,0.,210.);
 TH1F* hTkSim_tkneu_DR   = new TH1F("hTkSim_tkneu_DR","",100,0.,5.);
 TH1F* hTkSim_tkneu_dphi = new TH1F("hTkSim_tkneu_dphi","",33,0.,3.3);
 TH1F* hTkSim_tkjet_DR   = new TH1F("hTkSim_tkjet_DR","",100,0.,5.);
 TH1F* hTkSim_tkjet_dphi = new TH1F("hTkSim_tkjet_dphi","",33,0.,3.3);
 TH1F* hTkSim_tkjet_ok_DR   = new TH1F("hTkSim_tkjet_ok_DR","",100,0.,5.);
 TH1F* hTkSim_tkjet_ok_dphi = new TH1F("hTkSim_tkjet_ok_dphi","",33,0.,3.3);
 TH1F* hTkSim_tkjet_op_DR   = new TH1F("hTkSim_tkjet_op_DR","",100,0.,5.);
 TH1F* hTkSim_tkjet_op_dphi = new TH1F("hTkSim_tkjet_op_dphi","",33,0.,3.3);

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
 TH1F* hTkOth_z1	 = new TH1F("hTkOth_z1","",210,0.,210.);
 TH1F* hTkOth_at10       = new TH1F("hTkOth_at10","",101,-0.5,100.5);
 TH1F* hTkOth_at20       = new TH1F("hTkOth_at20","",101,-0.5,100.5);
 TH1F* hTkOth_at30       = new TH1F("hTkOth_at30","",101,-0.5,100.5);
 TH1F* hTkOth_at40       = new TH1F("hTkOth_at40","",101,-0.5,100.5);
 TH1F* hTkOth_tkjet_DR   = new TH1F("hTkOth_tkjet_DR","",100,0.,5.);
 TH1F* hTkOth_tkjet_dphi = new TH1F("hTkOth_tkjet_dphi","",33,0.,3.3);

 //ADDED by Paul


TH1F* hData_FakeRate_vs_pt= new TH1F("hData_FakeRate_vs_pt","1-FakeRate_vs_pt",101,0.,100.);
TH1F* hData_isMatched_dR_0= new TH1F("hData_isMatched_dR_0","dR BkgTracks_Axis",101,0.,5.);
TH1F* hData_isMatched_dR_1= new TH1F("hData_isMatched_dR_1","dR SignalTracks_Axis1",100,0.,5.);
TH1F* hData_isMatched_dR_2= new TH1F("hData_isMatched_dR_2","dR SignalTracks_Axis2",100,0.,5.);
TH1F* hData_isMVA_Matched_dR_0= new TH1F("hData_isMVA_Matched_dR_0","dR_MVA_BkgTracks_Axis",100,0.,5.);
TH1F* hData_isMVA_Matched_dR_1= new TH1F("hData_isMVA_Matched_dR_1","dR_IsMVA_SignalTracks_Axis1",100,0.,5.);
TH1F* hData_isMVA_Matched_dR_2= new TH1F("hData_isMVA_Matched_dR_2","dR_IsMVA_SignalTracks_Axis2",100,0.,5.);
TH1F* hData_dR_isMissMatched= new TH1F("hData_dR_isMissMatched","dR_Signal_isMissMatched",100,0.,5.);
TH1F* hData_isMVA_dR_MissMatched= new TH1F("hData_isMVA_dR_MissMatched","dR_IsMVA_Signal_isMissMatched",100,0.,5.);
hData_isMatched_dR_0->SetXTitle("dR");
hData_isMatched_dR_1->SetXTitle("dR");
hData_isMatched_dR_2->SetXTitle("dR");
hData_dR_isMissMatched->SetXTitle("dR");
hData_isMVA_Matched_dR_0->SetXTitle("dR");
hData_isMVA_Matched_dR_1->SetXTitle("dR");
hData_isMVA_Matched_dR_2->SetXTitle("dR");
hData_isMVA_dR_MissMatched->SetXTitle("dR");  



TH1F *h1 = new TH1F("h1","Blue: isSimMatched / Red:All tracks// Cuts applied",101,0.,100.);
// TH2F *hData_FakeRate = new TH2F("hData_FakeRate","hData_FakeRate",51,0.,50.,100,0.,1.);
TH1F *hData_Mu_Axis_dR = new TH1F("hData_Mu_Axis_dR","hData_Mu_Axis_dR",100,0.,5.);
TH1F *hData_Matched_bdtvalue = new TH1F("hData_Matched_bdtvalue","hData_Matched_bdtvalue",51,-1.,1.);
TH1F *hData_NotMatched_bdtvalue = new TH1F("hData_NotMatched_bdtvalue","hData_NotMatched_bdtvalue",51,-1.,1.);
TH1F *h_DataHSCP = new TH1F("h_DataHSCP","h_DataHSCP",101,0.,100.);
TH1F *hData_NTracks_1 = new TH1F("hData_NTracks_1","hData_NTracks_1",101,0.,100.);
TH1F *hData_NTracks_2 = new TH1F("hData_NTracks_2","hData_NTracks_2",101,0.,100.);



TH1F *hData_BothHemi_SB_dR = new TH1F("hData_BothHemi_SB_dR","dR_Hemis /S&B/2Hemis",100,0.,5.);
TH1F *hData_SB_isMissMatched = new TH1F("hData_SB_isMissMatched","hData_SB_isMissMatched",100,0.,5.);
TH1F *hData_BothHemi_S_dR = new TH1F("hData_BothHemi_S_dR","dR_Hemis /S/2Hemis",100,0.,5.);
TH1F *hData_S_isMissMatched = new TH1F("hData_S_isMissMatched","dR_S_isMissMatched/2Hemis",100,0.,5.);
hData_BothHemi_SB_dR->SetXTitle("dR");
hData_SB_isMissMatched->SetXTitle("dR");
hData_BothHemi_S_dR->SetXTitle("dR");
hData_S_isMissMatched->SetXTitle("dR");

       
//Daniel more compact code for event axis
//  TH1F* hData_Jet_njet1     = new TH1F("hData_Jet_njet1","",21,-0.5,20.5);
//  TH1F* hData_Jet_njet2     = new TH1F("hData_Jet_njet2","",21,-0.5,20.5);
//  TH1F* hDataGen_jetseed_dR     = new TH1F("hDataGen_jetseed_dR","",50,0.,5.);
///////////////////////////////////////////////////////////////////

 if (fChain == 0) return;

 Long64_t nentries = fChain->GetEntriesFast();
 std::cout << "Total Entries : " << nentries << std::endl;
  
 Long64_t nbytes = 0, nb = 0;

//  int nRecoTracks=0;
//  int maxSize=0;
 int nJets=0; 

 int allevents = 0;
 int itest = 0;

 float deltaR;
 float mu_mass = 0.1057, smu_mass = 0.;
 TLorentzVector v1, v2, v;

float nSignalTracks=0, nBkgTracks=0;
float n_Mva_SignalTracks=0,n_Mva_BkgTracks=0;
float SignalEff=0, BkgEff=0;
// float Mva_SignalEff=0, Mva_BkgEff=0;
float nTrackingPerfSignal=0;
float nTrackingPerfBkg=0;
////////////////
// Event loop //
////////////////

 for (Long64_t jentry=0; jentry<nentries; jentry++) {
   Long64_t ientry = LoadTree(jentry);
 if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   allevents++;
   if ( allevents%1000 == 0 ) std::cout << "events : " << allevents << std::endl;
   
// //$$
//   itest++;
//   if ( itest > 10 ) break;
//  std::cout << " " << std::endl;
//  std::cout << " Event " << eventNumber << std::endl;
// //$$

///////////////////////
// ZMu filter

   int ngenpart =  tree_genParticle_pt->size();

   hDataAll_nZMu->Fill( tree_NbrOfZCand );
   bool ZMu = false;
   if ( tree_NbrOfZCand > 0 ) ZMu = true;
//$$
 if ( ngenpart > 0 && !ZMu ) continue; // only for MC at the moment
//$$


///////////////////////already computed in the newest ntuple
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
   TLorentzVector vmuon[2];

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
       smu_mass = tree_genParticle_mass->at(i);
       break;
     }
   }    // end Loop on GenParticle
   

///////////////////////
// reco muons with ZMu filter

   bool ZMuRec = false;
   int PFiso, MVAiso, CutBasedId;
   float dVr, dVz;
   float Mmumu = 0.;
   int nmurec = 0, imu1 = -1, imu2 = -1;
   float mupt1, mueta1, muphi1, mupt2, mueta2, muphi2;

   for (int i=0; i<nmu; i++) {	     // Loop on reco muons
   if ( !tree_slimmedmuon_isGlobalMuon->at(i) ) continue;//Need global muons
     mupt1  = tree_slimmedmuon_pt->at(i);
   if ( mupt1 < 10. ) continue;//Zmu filter
     dVr = TMath::Sqrt( (tree_slimmedmuon_vx->at(i)-PVx)*(tree_slimmedmuon_vx->at(i)-PVx) + (tree_slimmedmuon_vy->at(i)-PVy)*(tree_slimmedmuon_vy->at(i)-PVy) );
     dVz = tree_slimmedmuon_vz->at(i)-PVz;
     hData_Mu_dVr->Fill( dVr );
     hData_Mu_dVz->Fill( dVz );
   if ( dVr > 0.1 || abs(dVz) > 0.2 ) continue;// on veut un bon fit pour nos PV d'ou un seuil maximum sur les distances
     //pas forcémetn dasntracking perf

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
     vmuon[0].SetPtEtaPhiM(mupt1,mueta1,muphi1,0);
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
     if ( mupt1 < 28. && mupt2 < 28. ) continue;//Zmu FIlter
       mueta2 = tree_slimmedmuon_eta->at(j);
       muphi2 = tree_slimmedmuon_phi->at(j);
       v2.SetPtEtaPhiM(mupt2,mueta2,muphi2,mu_mass);
       vmuon[1].SetPtEtaPhiM(mupt2,mueta2,muphi2,0);
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
   if ( Mmumu < 60. ) continue;
//$$

   if ( tree_slimmedmuon_pt->at(imu2) > tree_slimmedmuon_pt->at(imu1) ) {
     int imu0 = imu2;
     imu2 = imu1;//muons reco with imu1 having the highest pt
     imu1 = imu0;
     v = vmuon[0];
     vmuon[0] = vmuon[1];
     vmuon[1] = v;
   }
   mupt1  = tree_slimmedmuon_pt->at(imu1);
   mueta1 = tree_slimmedmuon_eta->at(imu1);
   muphi1 = tree_slimmedmuon_phi->at(imu1);
   mupt2  = tree_slimmedmuon_pt->at(imu2);
   mueta2 = tree_slimmedmuon_eta->at(imu2);
   muphi2 = tree_slimmedmuon_phi->at(imu2);
   hData_Mu_pt1->Fill( mupt1 );
   hData_Mu_pt2->Fill( mupt2 );


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

   int ntop=0, nstoq=0, nqtop=0, nlepW=0, lep1=0, lep2=0;
   float Gen_neu1_pt, Gen_neu1_eta, Gen_neu1_phi, Gen_neu1_m; 
   float Gen_neu2_pt, Gen_neu2_eta, Gen_neu2_phi, Gen_neu2_m; 
   float Gen_top1_pt, Gen_top1_eta, Gen_top1_phi, Gen_top1_x, Gen_top1_y, Gen_top1_z, Gen_top1_r=-1., Gen_top1_d, Gen_top1_Vphi; 
   float Gen_top2_pt, Gen_top2_eta, Gen_top2_phi, Gen_top2_x, Gen_top2_y, Gen_top2_z, Gen_top2_r=-1., Gen_top2_d, Gen_top2_Vphi; 
   int Gen_top1_id = -1, Gen_top2_id = -1;
   float dV, dV1, dV2, Vphi, deltaPhi, Vr, Vd, Vz, Veta;

   float genpt1 = 0., geneta1 = 0., genphi1 = 0.;
   float genpt2 = 0., geneta2 = 0., genphi2 = 0.;
   
   int smu[2], neu[2], genmu[2], top[2], sq1[2], sq3[2], nneu = 0, ngenmu = 0;
   int qsmu[2], qgenmu[2]; 
   TLorentzVector vsmu[2], vneu[2], vgenmu[2], vtop[2], vsq1[2], vsq3[2]; 
   float bg1, bg2, gamma, ctau, dRneuneu = 0.; 
   for (int k=0; k<2; k++) {
     smu[k] = -1;
     neu[k] = -1;
     top[k] = -1;
     sq1[k] = -1;
     sq3[k] = -1;
     genmu[k] = -1;
   }
   
   for (int i=0; i<ngenpart; i++)    // Loop on GenParticle, ngenpart can be uo to one thousand, basically few hundreds
   {
     float pdgId = tree_genParticle_pdgId->at(i); 
     float mother_pdgId = tree_genParticle_mother_pdgId->at(i); 
     float Gen_pt  = tree_genParticle_pt->at(i);
     float Gen_eta = tree_genParticle_eta->at(i);
     float Gen_phi = tree_genParticle_phi->at(i);
     float Gen_m = tree_genParticle_mass->at(i);

//  std::cout << "id mother status " << pdgId << " " << mother_pdgId << " " << tree_genParticle_statusCode->at(i) 
//            << " pt " << tree_genParticle_pt->at(i) 
// 	   << " xyz " << tree_genParticle_vx->at(i) << " " << tree_genParticle_vy->at(i) << " " << tree_genParticle_vz->at(i) << std::endl; 

// muon from smuon
     if ( abs(pdgId) == 13 && abs(mother_pdgId) == 1000013 ) {
       hGen_muon_pt->Fill( Gen_pt );
       hGen_muon_eta->Fill( Gen_eta );
       if ( genmu[0] < 0 ) {
         genmu[0] = i;
	 vgenmu[0].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 qgenmu[0] = tree_genParticle_charge->at(i);
       }
       else if ( genmu[1] < 0 ) {
         genmu[1] = i;
	 vgenmu[1].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 qgenmu[1] = tree_genParticle_charge->at(i);
       }
       ngenmu++;
     }

// neutralino && smuon 1000013 : Si on a un neutralino qui provient d'un smuon alors...
     if ( pdgId == 1000023 && abs(mother_pdgId) == 1000013 ) {
       hGen_neu_pt->Fill( Gen_pt );
       hGen_neu_eta->Fill( Gen_eta );
       if ( neu[0] < 0 ) {
         neu[0] = i;
	 vneu[0].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 Gen_neu1_pt = Gen_pt;
	 Gen_neu1_eta = Gen_eta;
	 Gen_neu1_phi = Gen_phi;
	 Gen_neu1_m = Gen_m;
       }
       else if ( neu[1] < 0 ) {
         neu[1] = i;
	 vneu[1].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 Gen_neu2_pt = Gen_pt;
	 Gen_neu2_eta = Gen_eta;
	 Gen_neu2_phi = Gen_phi;
	 Gen_neu2_m = Gen_m;
       }
       nneu++;
     }

// top quark from neutralino
     if ( abs(pdgId) == 6 && abs(mother_pdgId) == 1000023 ) {
       if ( top[0] < 0 ) {
         top[0] = i;
	 vtop[0].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
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
         top[1] = i;
	 vtop[1].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
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
       hGen_top_z->Fill( abs(Vz) );
       hGen_top_r->Fill( Vr );
       hGen_top_d->Fill( Vd );
       hGen_top_pt->Fill( tree_genParticle_pt->at(i) );
       hGen_top_eta->Fill( Veta );
       hGen_top_Vphi->Fill( Vphi );
       deltaPhi = DeltaPhi( Vphi, tree_genParticle_phi->at(i) );
       hGen_top_dVphi->Fill( abs(deltaPhi) );
     }

// quarks from top or W+
     if ( abs(pdgId) >= 1 && abs(pdgId) <= 5 
          && (abs(mother_pdgId) == 6 || abs(mother_pdgId) == 24) ) {
       dV = 10000.;
       int iLLP = -1;
       for (int k=0; k<2; k++) {
       if ( top[k] < 0 ) continue;
         dV1 = (tree_genParticle_vx->at(i) - tree_genParticle_vx->at(top[k]))*(tree_genParticle_vx->at(i) - tree_genParticle_vx->at(top[k]))
             + (tree_genParticle_vy->at(i) - tree_genParticle_vy->at(top[k]))*(tree_genParticle_vy->at(i) - tree_genParticle_vy->at(top[k]))
             + (tree_genParticle_vz->at(i) - tree_genParticle_vz->at(top[k]))*(tree_genParticle_vz->at(i) - tree_genParticle_vz->at(top[k]));
         if ( dV1 < dV ) {
	   iLLP = k;
	   dV = dV1;
	 }
       }
       if ( iLLP >= 0 ) {
         dV = TMath::Sqrt( dV );
         hGen_qtop_dV->Fill( dV );
         hGen_qtop_pt->Fill( Gen_pt );
         hGen_qtop_eta->Fill( Gen_eta );

         deltaR = DeltaR( vneu[iLLP].Eta(), vneu[iLLP].Phi(), Gen_eta, Gen_phi );
         deltaPhi = DeltaPhi( vneu[iLLP].Phi(), Gen_phi );
         hGen_neuqtop_DR->Fill( deltaR );//gap between quakr from top or W decay and neutralino
         hGen_neuqtop_dphi->Fill( abs(deltaPhi) );
         hGen_neuqtop_deta->Fill( abs( Gen_eta - vneu[iLLP].Eta() ) );
         nqtop++;
       }
     }

// leptons from W
     if ( (abs(pdgId) == 11 || abs(pdgId) == 13 || abs(pdgId) == 15) && abs(mother_pdgId) == 24 ) {
       dV = 10000.;
       int iLLP = -1;
       for (int k=0; k<2; k++) {
       if ( top[k] < 0 ) continue;
         dV1 = (tree_genParticle_vx->at(i) - tree_genParticle_vx->at(top[k]))*(tree_genParticle_vx->at(i) - tree_genParticle_vx->at(top[k]))
             + (tree_genParticle_vy->at(i) - tree_genParticle_vy->at(top[k]))*(tree_genParticle_vy->at(i) - tree_genParticle_vy->at(top[k]))
             + (tree_genParticle_vz->at(i) - tree_genParticle_vz->at(top[k]))*(tree_genParticle_vz->at(i) - tree_genParticle_vz->at(top[k]));
         if ( dV1 < dV ) {
	   iLLP = k;

	   dV = dV1;
	 }
       }
       if ( iLLP >= 0 ) {
         dV = TMath::Sqrt( dV );
         hGen_lepW_dV->Fill( dV );
         hGen_lepW_pt->Fill( Gen_pt );
         hGen_lepW_eta->Fill( Gen_eta );

         deltaR = DeltaR( vneu[iLLP].Eta(), vneu[iLLP].Phi(), Gen_eta, Gen_phi );
         deltaPhi = DeltaPhi( vneu[iLLP].Phi(), Gen_phi );
         hGen_neulepW_DR->Fill( deltaR );
         hGen_neulepW_dphi->Fill( abs(deltaPhi) );
         hGen_neulepW_deta->Fill( abs( Gen_eta - vneu[iLLP].Eta() ) );
         nlepW++;
         	 if ( iLLP == 0 ) lep1 = abs(pdgId);
	       if ( iLLP == 1 ) lep2 = abs(pdgId);
       }
     }

// quarks from stop
     if ( (abs(pdgId) == 1 || abs(pdgId) == 3) && abs(mother_pdgId) == 1000023 ) {
       if ( abs(pdgId) == 1 ) {
         if ( sq1[0] < 0 ) {
           sq1[0] = i;
	   vsq1[0].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 }
	 else if ( sq1[1] < 0 ) {
           sq1[1] = i;
	   vsq1[1].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 }
       }
       if ( abs(pdgId) == 3 ) {
         if ( sq3[0] < 0 ) {
           sq3[0] = i;
	   vsq3[0].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 }
	 else if ( sq3[1] < 0 ) {
           sq3[1] = i;
	   vsq3[1].SetPtEtaPhiM( Gen_pt, Gen_eta, Gen_phi, Gen_m );
	 }
       }
       hGen_stoq_pt->Fill( Gen_pt );
       hGen_stoq_eta->Fill( Gen_eta );
       nstoq++;
     }

   }    // End Loop on GenParticle

   hGen_muon->Fill( ngenmu );
   hGen_neu->Fill( nneu );
   hGen_top->Fill( ntop );
   hGen_qtop->Fill( nqtop );
   hGen_stoq->Fill( nstoq );
   hGen_lepW->Fill( nlepW );

// smuon
   int itest_smu = -1;
   if ( ngenmu == 2 && nneu == 2 ) {
     itest_smu = 0;
     vsmu[0] = vgenmu[0] + vneu[0];//conservation of genreated quadrivector
     vsmu[1] = vgenmu[1] + vneu[1];
     float test_Msmu0 = vsmu[0].Mag() / smu_mass - 1.;
     float test_Msmu1 = vsmu[1].Mag() / smu_mass - 1.;
     hGen_smu_testM->Fill( test_Msmu0 );//LOOKAT: 0-peak
     hGen_smu_testM->Fill( test_Msmu1 );//LOOKAT: 0-peak
     if ( abs(test_Msmu0) > 0.1 || abs(test_Msmu1) > 0.1 ) {
       itest_smu = 1;
       vsmu[0] = vgenmu[1] + vneu[0];
       vsmu[1] = vgenmu[0] + vneu[1];
       v = vgenmu[0];
       vgenmu[0] = vgenmu[1];
       vgenmu[1] = v;
     }
     for (int i=0; i<2; i++) {
       hGen_smu_pt->Fill( vsmu[i].Pt() );
       hGen_smu_eta->Fill( vsmu[i].Eta() );
     }
     deltaR = DeltaR( vsmu[0].Eta(), vsmu[0].Phi(), vsmu[1].Eta(), vsmu[1].Phi() );
     deltaPhi = DeltaPhi( vsmu[0].Phi(), vsmu[1].Phi() );
     hGen_smusmu_DR->Fill( deltaR );
     hGen_smusmu_dphi->Fill( abs(deltaPhi) );
   }
   hGen_smu_test->Fill( itest_smu );    //LOOKAT :0
   
   if ( ngenmu == 2 ) {
     v = vgenmu[0] + vgenmu[1];
     hGen_mumu_mass->Fill( v.Mag() );//LOOKAT should be sup to 60 GeV with ZMu filter (true)
     for (int i=0; i<2; i++) {
       deltaR = DeltaR( vgenmu[i].Eta(), vgenmu[i].Phi(), vsmu[i].Eta(), vsmu[i].Phi() );
       deltaPhi = DeltaPhi( vgenmu[i].Phi(), vsmu[i].Phi() );
       hGen_muonsmu_DR->Fill( deltaR );//LOOKAT "^\" <2
       hGen_muonsmu_dphi->Fill( abs(deltaPhi) );//LOOKAT "^\"<2
     }
   }

   if ( nneu == 2 ) {
     dRneuneu = DeltaR( Gen_neu1_eta, Gen_neu1_phi, Gen_neu2_eta, Gen_neu2_phi );
     deltaPhi = DeltaPhi( Gen_neu1_phi, Gen_neu2_phi );
     hGen_neuneu_DR->Fill( dRneuneu );
     hGen_neuneu_dphi->Fill( abs(deltaPhi) );
     for (int i=0; i<2; i++) {
       deltaR = DeltaR( vneu[i].Eta(), vneu[i].Phi(), vsmu[i].Eta(), vsmu[i].Phi() );
       deltaPhi = DeltaPhi( vneu[i].Phi(), vsmu[i].Phi() );
       hGen_neusmu_DR->Fill( deltaR );
       hGen_neusmu_dphi->Fill( abs(deltaPhi) );
       deltaR = DeltaR( vgenmu[i].Eta(), vgenmu[i].Phi(), vneu[i].Eta(), vneu[i].Phi() );
       deltaPhi = DeltaPhi( vgenmu[i].Phi(), vneu[i].Phi() );
       hGen_neumu_DR->Fill( deltaR );//LOOKAT "^\"<2
       hGen_neumu_dphi->Fill( abs(deltaPhi) );//LOOKAT "^\"<2
     }
   }

   if ( ntop == 2 ) {
     deltaR = DeltaR( Gen_top1_eta, Gen_top1_phi, Gen_top2_eta, Gen_top2_phi );
     hGen_toptop_DR->Fill( deltaR );
     dV = (Gen_top2_x - Gen_top1_x)*(Gen_top2_x - Gen_top1_x)
        + (Gen_top2_y - Gen_top1_y)*(Gen_top2_y - Gen_top1_y)
        + (Gen_top2_z - Gen_top1_z)*(Gen_top2_z - Gen_top1_z);
     dV = TMath::Sqrt(dV);
     hGen_toptop_dV->Fill( dV );//LOOKAT "^\\\\\" -> 200 cm
     deltaPhi = DeltaPhi( Gen_top2_Vphi, Gen_top1_Vphi );
     hGen_toptop_dVphi->Fill( abs(deltaPhi) );//LOOKAT: close to 3 rad (pi)
   }

   if ( nstoq == 4 ) {
     for (int i=0; i<2; i++) {
       deltaR = DeltaR( vneu[i].Eta(), vneu[i].Phi(), vsq1[i].Eta(), vsq1[i].Phi() );
       deltaPhi = DeltaPhi( vneu[i].Phi(), vsq1[i].Phi() );
       hGen_neusq_DR->Fill( deltaR );
       hGen_neusq_dphi->Fill( abs(deltaPhi) );
       hGen_neusq_deta->Fill( abs(vsq1[i].Eta() - vneu[i].Eta()) );
       deltaR = DeltaR( vneu[i].Eta(), vneu[i].Phi(), vsq3[i].Eta(), vsq3[i].Phi() );
       deltaPhi = DeltaPhi( vneu[i].Phi(), vsq3[i].Phi() );
       hGen_neusq_DR->Fill( deltaR );
       hGen_neusq_dphi->Fill( abs(deltaPhi) );
       hGen_neusq_deta->Fill( abs(vsq3[i].Eta() - vneu[i].Eta()) );

       if ( top[i] >= 0 ) {
         dV = (tree_genParticle_vx->at(sq1[i]) - tree_genParticle_vx->at(top[i]))*(tree_genParticle_vx->at(sq1[i]) - tree_genParticle_vx->at(top[i]))
            + (tree_genParticle_vy->at(sq1[i]) - tree_genParticle_vy->at(top[i]))*(tree_genParticle_vy->at(sq1[i]) - tree_genParticle_vy->at(top[i]))
            + (tree_genParticle_vz->at(sq1[i]) - tree_genParticle_vz->at(top[i]))*(tree_genParticle_vz->at(sq1[i]) - tree_genParticle_vz->at(top[i]));
         dV = TMath::Sqrt( dV );
         hGen_stoq_dV->Fill( dV );
         dV = (tree_genParticle_vx->at(sq3[i]) - tree_genParticle_vx->at(top[i]))*(tree_genParticle_vx->at(sq3[i]) - tree_genParticle_vx->at(top[i]))
            + (tree_genParticle_vy->at(sq3[i]) - tree_genParticle_vy->at(top[i]))*(tree_genParticle_vy->at(sq3[i]) - tree_genParticle_vy->at(top[i]))
            + (tree_genParticle_vz->at(sq3[i]) - tree_genParticle_vz->at(top[i]))*(tree_genParticle_vz->at(sq3[i]) - tree_genParticle_vz->at(top[i]));
         dV = TMath::Sqrt( dV );
         hGen_stoq_dV->Fill( dV );
       }
     }
   }

// neutralino beta gamma and ctau
   if ( neu[0]>=0 && neu[1]>=0 && top[0]>=0 && top[1]>=0 && ntop == 2 && nstoq == 4 ) {
     v = vtop[0] + vsq1[0] + vsq3[0];
     float testE = v.E() / vneu[0].E() - 1.;
     hGen_neu_testE->Fill( testE );//LOOKAT 0-peak
     gamma = vneu[0].E() / Gen_neu1_m;
     bg1 = TMath::Sqrt( gamma*gamma - 1 );
     gamma = vneu[1].E() / Gen_neu2_m;
     bg2 = TMath::Sqrt( gamma*gamma - 1 );
     hGen_top_bg->Fill( bg1 );//LOOKAT: mean 2.3 (same as neutralino)
     hGen_top_bg->Fill( bg2 );//LOOKAT: mean 2.3 (same as neutralino)
     if ( abs(testE) < 0.1 ) {  // neu0 gives top0
       ctau = Gen_top1_d / bg1;
       hGen_top_ctau->Fill( ctau );// 0 to 100 Cm "decreasing exponential", mean 20 cm
       ctau = Gen_top2_d / bg2;
       hGen_top_ctau->Fill( ctau );
     } 
   }
 

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
// MET

  //  int nMET = tree_PFMet_et->size();
  //  float MET = -10., METphi = -10.;
  //  if ( nMET > 0 ) {
  //    MET = tree_PFMet_et->at(0);
  //    METphi = tree_PFMet_phi->at(0);
  //  }
  //  hData_MET->Fill( MET );
  //  hData_MET_phi->Fill( METphi );


///////////////////////
// Jets for axis reco
   int njet_forLLP = 0,ijet1 = -1;
   int njet = 0, njet1 = 0, njet2 = 0;
   bool isjet[99], isjet1[99], isjet2[99];
   TLorentzVector vaxis1, vaxis2, vjet[99];
   float PtMin = 20; //GeV 
   float EtaMax = 2.4;

 // int njetall = ak4slimmedJets->size();
   int ntrack =  tree_track_pt->size();
   hData_nTk->Fill(ntrack);
   
// genJet AK4
   int ngenjet = tree_genJet_pt->size();

// Jets PF AK4
   for (int i=0; i<njetall; i++)    // Loop on jet
   {
     float jet_pt  = tree_AK4Slimmedjet_pt->at(i);
     float jet_eta = tree_AK4Slimmedjet_eta->at(i);
     float jet_phi = tree_AK4Slimmedjet_phi->at(i);
//$$
     isjet[i]  = false;
 //$$    
     isjet1[i] = false; //first neutralino jets
     isjet2[i] = false; //second neutralino jets
     v.SetPtEtaPhiM( jet_pt, jet_eta, jet_phi, 0. ); //set the axis

   if ( jet_pt < PtMin ) continue;
   if ( abs(jet_eta) > EtaMax ) continue;

   if ( i>=0 && i<njetall-1 ) hData_Jet_pt_test->Fill( jet_pt - tree_AK4Slimmedjet_pt->at(i+1) );//check if the first jet has the highest pt
      
// look if prompt muon inside
     float deltaR1 = 1000., deltaR2 = 1000.;
     if ( imu1 >= 0 ) deltaR1 = DeltaR( jet_eta, jet_phi, tree_slimmedmuon_eta->at(imu1), tree_slimmedmuon_phi->at(imu1) );
     hData_Jet_dRmu->Fill( deltaR1 );
     if ( imu2 >= 0 ) deltaR2 = DeltaR( jet_eta, jet_phi, tree_slimmedmuon_eta->at(imu2), tree_slimmedmuon_phi->at(imu2) );
     hData_Jet_dRmu->Fill( deltaR2 );
     if ( deltaR1 < 0.4 || deltaR2 < 0.4 ) {
       if ( deltaR1 < 0.4 ) { //if muon is inside, we remove the muons infomation from the jet
         v1.SetPtEtaPhiM( tree_slimmedmuon_pt->at(imu1), 
	                  tree_slimmedmuon_eta->at(imu1), 
			  tree_slimmedmuon_phi->at(imu1), 0 );
	 v -= v1; //v TLorentzFactor being just above, defined by jet data
       }
       if ( deltaR2 < 0.4 ) {
         v2.SetPtEtaPhiM( tree_slimmedmuon_pt->at(imu2), 
	                  tree_slimmedmuon_eta->at(imu2), 
			  tree_slimmedmuon_phi->at(imu2), 0 );
	 v -= v2;
       }
       jet_pt  = v.Pt(); //Update jet data by removing the muons information (muons that could be in the jet)
       jet_eta = v.Eta(); //+ we do not want muons data to build the two axis since they come from the PV
       jet_phi = v.Phi(); 
     }  

     hData_Jet_pt->Fill( jet_pt );//FInal jet data without muons
     hData_Jet_eta->Fill( jet_eta );//FInal jet datawithout muons
     hData_Jet_phi->Fill( jet_phi );//FInal jet datawithout muons
     
     njet++;
//$$
     njet_forLLP++;//same as njet
    //  isjet1[i] = true;
      isjet[i] = true;
      vjet[i] = v; //Only jet data (with  possible muons being removed)

        //$$

    //  if ( njet_forLLP == 1 ) {
    //    vaxis1 = v;//////////////////////////
    //    ijet1 = i;//////////////////////////
    //    njet1 = 1;//////////////////////////
    //    isjet2[i] = true;//LOOKAT
    //  }


    //  if ( njet == 1 ) hData_Jet_pt1->Fill( jet_pt );
    //  if ( njet == 2 ) hData_Jet_pt2->Fill( jet_pt );

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
     }	   // end Loop on genJet recomatched
     if ( isMatched ) {//gen is recomatched
       hDataGen_Jet_pt->Fill( jet_pt );
       hDataGen_Jet_eta->Fill( jet_eta );
     }
     	if ( njet1 == 0 && jet_pt > PtMin && abs(jet_eta) < EtaMax ) 
        {
            njet1 = 1;
            isjet1[i] = true;
            vaxis1 = v;
        }
   }	   // end Loop on jet

   hData_Jet_njet->Fill( njet );//njet being the number of jets to go trough the conditions defined line 1000
   hData_Jet_njet_forLLP->Fill( njet_forLLP );//both should be the same


  //////////////////
  //------------------------------
  //Event Axis
  //------------------------------
  //////////////////

  //$$
   int iLLPrec1 = 1, iLLPrec2 = 2;
   float dR, dR1 = 10., dR2 = 10., deta, dphi;

   float dRcut = 1;//subjectif choice: pi/2

  //  if ( ijet1 >= 0 && ijet1 < njetall ) {
  for (int i=0; i<njetall; i++) // Loop on jet
    { 
     if ( !isjet[i] ) continue;//verifies the pt and eta cuts on jets
       // float jet_pt  = vjet[i].Pt();
       float jet_eta = vjet[i].Eta();
       float jet_phi = vjet[i].Phi();
       if ( njet1 > 0 ) dR1 = DeltaR( jet_eta, jet_phi, vaxis1.Eta(), vaxis1.Phi() );
       if ( njet2 > 0 ) dR2 = DeltaR( jet_eta, jet_phi, vaxis2.Eta(), vaxis2.Phi() );
// axis 1
          if ( njet1 > 0 && !isjet2[i] && dR1 < dRcut ) {          //
          njet1++;
          vaxis1 += vjet[i];
          isjet1[i] = true;
        }      
// axis 2
        if (   njet2 == 0 && !isjet1[i] ) {
          njet2 = 1;
          vaxis2 = vjet[i];
          isjet2[i] = true;
        }
        else if ( njet2 > 0 && !isjet1[i] && !isjet2[i] && dR2 < dRcut ) {//
          njet2++;
          vaxis2 += vjet[i];
          isjet2[i] = true;
        }
        //std::cout<<"njet1 "<< njet1 <<"njet2 "<< njet2 <<"isjet1[i] "<< isjet1[i] <<"isjet2[i] "<<isjet2[i] <<std::endl;
     }	   // end Loop on jet
   hData_Jet1->Fill( njet1 );
   hData_Jet2->Fill( njet2 );
   //std::cout<<"vaxis2.pt "<< vaxis2.Pt() <<"vaxis2.eta "<<vaxis2.Eta()  <<"vaxis2.phi "<< vaxis2.Phi()<<std::endl;
   
  /////////////////////////////// 
  // compare with neutralino axis
  /////////////////////////////// 

//$$
   float axis1_eta = vaxis1.Eta();
   float axis1_phi = vaxis1.Phi();
     if ( neu[0] >= 0 ) dR1 = DeltaR( axis1_eta, axis1_phi, Gen_neu1_eta, Gen_neu1_phi );//dR between reco axis of jets and gen neutralino
     if ( neu[1] >= 0 ) dR2 = DeltaR( axis1_eta, axis1_phi, Gen_neu2_eta, Gen_neu2_phi );
     dR = dR1;
     if ( dR2 < dR1 ) 
     { //make sure that the reco axis defined meshes well with the axis of the gen neutralino, if not it is swapped
       iLLPrec1 = 2;
       iLLPrec2 = 1;
       dR = dR2;
     }
    float axis1_dR = dR;
    float axis2_eta = vaxis2.Eta();
    float axis2_phi = vaxis2.Phi();
    if ( njet2 == 0 ) 
    {  // compute an axis 2 even without jet, by taking the opposite in phi to axis 1
      axis2_eta = axis1_eta;
      axis2_phi = axis1_phi - 3.14159;
      if ( axis1_phi < 0 ) axis2_phi = axis1_phi + 3.14159;
      // vaxis2.SetPtEtaPhiM( vaxis1.Pt(), axis2_eta, axis2_phi, 0 );
    }
  if ( iLLPrec2 == 1 ) dR = DeltaR( axis2_eta, axis2_phi, Gen_neu1_eta, Gen_neu1_phi );
  else                 dR = DeltaR( axis2_eta, axis2_phi, Gen_neu2_eta, Gen_neu2_phi ); 


     if ( iLLPrec1 == 1 ) {
       dphi = abs(DeltaPhi( axis1_phi, Gen_neu1_phi ));
       deta = abs(axis1_eta - Gen_neu1_eta);
     }
     else {
       dphi = abs(DeltaPhi( axis1_phi, Gen_neu2_phi ));
       deta = abs(axis1_eta - Gen_neu2_eta);
     }
     hDataGen_LLPrec1_dR->Fill( dR );//si on ajoute met, on dégrade <2
     hDataGen_LLPrec1_deta->Fill( deta );//comparison between reco and gen <0.5
     hDataGen_LLPrec1_dphi->Fill( dphi );  // <1.5, association works well
  //  }


  ////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////
   if ( dRneuneu > dRcut && ijet1 >= 0 && ijet1 < njetall ) {
     float axis2_phi = 0.;
     //Hypothesis: both neutralinos are back to back
     if ( axis1_phi >= 0 ) axis2_phi = axis1_phi - 3.14159;//phi has to be between (-pi/+pi)
     else                 axis2_phi = axis1_phi + 3.14159;//phi has to be between (-pi/+pi)
     //Thisis a first assessment on the axis of the other neutralino wrt the first one
     float axis1sym_phi = axis2_phi;
     
     if ( iLLPrec2 == 1 ) {
       dR = DeltaR( axis1_eta, axis2_phi, Gen_neu1_eta, Gen_neu1_phi );//reco vs gen
       dphi = abs(DeltaPhi( axis2_phi, Gen_neu1_phi ));//check if the neutralino is within the axis previously defined, we would like dR<0.4
       //with the assumption that both neutralinos are back to back
     }
     else {
       dR = DeltaR( axis1_eta, axis2_phi, Gen_neu2_eta, Gen_neu2_phi );//reco vs gen
       dphi = abs(DeltaPhi( axis2_phi, Gen_neu2_phi ));//check if the neutralino is within the axis previously defined, we would like dR<0.4
       //with the assumption that both neutralinos are back to back
     }
     hDataGen_LLPrec2_sym_dR->Fill( dR );//LOOKAT: these two distributions shouldn't be that great as the assumptions is made that both (true)
     hDataGen_LLPrec2_sym_dphi->Fill( dphi );//LOOKAT: neutralions are back to back
    //############################"END OF Hypothesis: both neutralinos are back to back##################################

	


     
     if ( njet2 >= 1 ) {
       float axis2_eta = vaxis2.Eta();
       float axis2_phi = vaxis2.Phi();
       float dRsym, dphisym;
       if ( iLLPrec2 == 1) {
         dR = DeltaR( axis2_eta, axis2_phi, Gen_neu1_eta, Gen_neu1_phi );
         dphi = abs(DeltaPhi( axis2_phi, Gen_neu1_phi ));
         deta = abs(axis2_eta - Gen_neu1_eta);
         dRsym = DeltaR( axis2_eta, axis1sym_phi, Gen_neu1_eta, Gen_neu1_phi );
         dphisym = abs(DeltaPhi( axis1sym_phi, Gen_neu1_phi ));
       }
       else {
         dR = DeltaR( axis2_eta, axis2_phi, Gen_neu2_eta, Gen_neu2_phi );
         dphi = abs(DeltaPhi( axis2_phi, Gen_neu2_phi ));
         deta = abs(axis2_eta - Gen_neu2_eta);
         dRsym = DeltaR( axis2_eta, axis1sym_phi, Gen_neu2_eta, Gen_neu2_phi );
         dphisym = abs(DeltaPhi( axis1sym_phi, Gen_neu2_phi ));
       }
       //look at the dR between the two reconstructed axis
       float dRaxis1_2 = DeltaR( axis1_eta, axis1_phi, axis2_eta, axis2_phi);
       std::cout<<"dR between the two axis is computed"<<std::endl;
       hData_Jetaxis_dR->Fill(dRaxis1_2);// pi-peak

       hDataGen_LLPrec2_dR->Fill( dR );//this should be a better axis2 reco //LOOKAT (true)
       hDataGen_LLPrec2_deta->Fill( deta );//LOOKAT (true)
       hDataGen_LLPrec2_dphi->Fill( dphi );//LOOKAT
       hDataGen_LLPrec2_dRsym->Fill( dRsym );//LOOKAT
       hDataGen_LLPrec2_dphisym->Fill( dphisym );//LOOKAT : same as hDataGen_LLPrec2_sym_dphi
     }
   }
//regarder comment se comporte les traces par rapport aux acxes consutris précédemment
//axe dR trace et axis avec dr plsu petit(done below)
//dR entre les deux vaxis1(done above)
//caractéristique de straces par raport à l'association aux neutralions
//code sans bdt, réudction du bdf?? signal?? perte de traces (later)
      //CHeck if the muon is inside of one of the cone defined by the axis
          //  std::cout<<"nmu per event : "<<nmu<<std::endl;
        for (int j=0; j<nmu; j++) //loop on reco muons
          {	   
            if ( !tree_slimmedmuon_isGlobalMuon->at(j) ) continue;//Need global muons
            int IsInside=0;
            // float mupt = tree_slimmedmuon_pt->at(i);
	          float mueta = tree_slimmedmuon_eta->at(j);
			      float muphi = tree_slimmedmuon_phi->at(j);
            float eta1 = vaxis1.Eta();
            float phi1 = vaxis1.Phi();
            float eta2 = vaxis2.Eta();
            float phi2 = vaxis2.Phi();
            float dR_Mu_Axis1 = DeltaR( mueta, muphi, eta1, phi1);
            float dR_Mu_Axis2 = DeltaR( mueta, muphi, eta2, phi2);
            hData_Mu_Axis_dR->Fill(dR_Mu_Axis1);
            hData_Mu_Axis_dR->Fill(dR_Mu_Axis2);
            // std::cout<<"dR_Mu_Axis1: "<<dR_Mu_Axis1<<" & dR_Mu_Axis2: "<<dR_Mu_Axis2<<std::endl;
            if (dR_Mu_Axis1 < dRcut || dR_Mu_Axis2  < dRcut)//the 0.4 limit is arbitrary
              {
                IsInside=1;
              }
              hData_Muon_Axis_dR4->Fill(IsInside);//LOOKAT: A non-negligeable amount of muons are in the cone defined by the axis of the two hemispheres
          }
//////////////////////////////////////////////////
//HSCP conditions on the tracks (plots for Dylan)
//plot FakeRate as a function of pt (upto 2 TeV)
//////////////////////////////////////////////////

for (int i=0; i<ntrack; i++)
  {
    // maxSize=maxSize+tree_track_isSimMatched->size();
     float q   = tree_track_charge->at(i);
     float pt  = tree_track_pt->at(i);
     float eta = tree_track_eta->at(i);
     float phi = tree_track_phi->at(i);
     float dr = abs(tree_track_dxy->at(i));
     float drSig = -1., dzSig = -1., ddSig = -1.;
     if ( tree_track_dxyError->at(i) > 0 ) drSig = dr / tree_track_dxyError->at(i);
     float dz = abs(tree_track_dz->at(i));
     if ( tree_track_dzError->at(i) > 0 )  dzSig = dz / tree_track_dzError->at(i);
     float dd = TMath::Sqrt( dr*dr + dz*dz );
     if ( drSig>0 && dzSig>0 ) ddSig = TMath::Sqrt( drSig*drSig + dzSig*dzSig );
     float pix = tree_track_numberOfValidPixelHits->at(i);
     float hit = tree_track_nhits->at(i);
     float chi = tree_track_NChi2->at(i);
     bool HighQuality=tree_track_isHighQuality->at(i);
     float algo = tree_track_algo->at(i);
    //  int lost_hits = tree_track_numberOfLostHits->at(i);
     int  valid_hits= tree_track_numberOfValidHits->at(i);
     float FracValidHits = valid_hits/hit;
     if ((tree_track_isSimMatched->at(i)==true || tree_track_isSimMatched->at(i)==false) &&  abs(eta)<2.1 && chi <= 5 && dz<=0.5 && dr<=0.02  && pix>=2 && hit>=8 && HighQuality==true && FracValidHits>0.8 ) {h1->Fill(pt);}
     //  std::cout<<"nhit="<<hit<<" just to check if hit is !=0"<<std::endl;//if != 0, remove the conditions below (ok)
     
     if (tree_track_isSimMatched->at(i)==true  && abs(eta)<2.1 && chi <= 5 && dz<=0.5 && dr<=0.02  && pix>=2 && hit>=8 && HighQuality==true && FracValidHits>0.8 )
       {
          hData_FakeRate_vs_pt->Fill(pt);//à normaliser par le nombre de track
          h_DataHSCP->Fill(pt);
       }
        
  }
      
///////////////////////
// Track or TrackSim + Track data wrt the two axis
      // int nMatch_0=0;
      int nMatch_1=0;
      int nMatch_2=0;
      // int nMissMatch=0;

   int nTkSim = 0, nTkOth = 0;
   int ntracksim = tree_track_simtrack_pt->size();
   if ( ngenpart > 0 && ntrack != ntracksim ) std::cout << " ##### ERROR ntrack ntracksim ##### " << ntrack << " " << ntracksim << std::endl;
   int track_isfromLLP[1000], track_SEL40[1000];
   bool track_SELEC[1000];
   if ( ntrack >= 1000 ) std::cout << " ##### ERROR ntrack ##### " << ntrack << std::endl;

   for (int i=0; i<ntrack; i++)    // Loop on Track or TrackSim
   {
     track_isfromLLP[i] = -1;
     int iV = -1;
     int ntrk10 = 0, ntrk20 = 0, ntrk30 = 0, ntrk40 = 0;
     track_SEL40[i] = 0;
     track_SELEC[i] = false;

     float q   = tree_track_charge->at(i);
     float pt  = tree_track_pt->at(i);
     float eta = tree_track_eta->at(i);
     float phi = tree_track_phi->at(i);
     float dr = abs(tree_track_dxy->at(i));
     float drSig = -1., dzSig = -1., ddSig = -1.;
     if ( tree_track_dxyError->at(i) > 0 ) drSig = dr / tree_track_dxyError->at(i);
     float dz = abs(tree_track_dz->at(i));
     if ( tree_track_dzError->at(i) > 0 )  dzSig = dz / tree_track_dzError->at(i);
     float dd = TMath::Sqrt( dr*dr + dz*dz );
     if ( drSig>0 && dzSig>0 ) ddSig = TMath::Sqrt( drSig*drSig + dzSig*dzSig );
     float pix = tree_track_numberOfValidPixelHits->at(i);
     float hit = tree_track_nhits->at(i);
     float chi = tree_track_NChi2->at(i);
     float x1 = tree_track_firsthit_X->at(i);
     float y1 = tree_track_firsthit_Y->at(i);
     float z1 = tree_track_firsthit_Z->at(i);
     float r1 = TMath::Sqrt( x1*x1 + y1*y1 );

     int inJet = 0;
     int jet = tree_track_recoAK4SlimmedJet_idx->at(i);
     if ( jet >= 0 ) inJet = 1;

     if ( pt > 1. && chi < 5. && drSig > 5. ) track_SELEC[i] = true;//cut included in the Ntuple code generator

    float dR=0;
    int Tracks_axis=0;//flag to check which axis is the closest from the track
    float dR1  = DeltaR( eta, phi, axis1_eta, axis1_phi);//axis1_phi and axis1_eta for the first axis
    float axis2_eta = -10;
    float axis2_phi = -10;
    int isFromLLP=tree_track_simtrack_isFromLLP->at(i);
    float bdtval=tree_track_MVAval->at(i);
    //std::cout<<"nbre jet2= "<<njet2<<" has to be >=1"<<std::endl;
    // if ( njet2 >= 1 ) 
      // {
    axis2_eta = vaxis2.Eta();
    axis2_phi = vaxis2.Phi();
    //check the dR between the tracks and the second axis (without any selection on the tracks)
    float dR2  = DeltaR( eta, phi, axis2_eta, axis2_phi);

    if (dR1>dR2)//a restriction could be added on the value of dR to assign the value Tracks_axis  (avoid some background???)
      //++ you could have a track that belongs to the two hemispheres ...
        {
          dR=dR2;
          if (dR < dRcut)
            {
              Tracks_axis=2;//belongs to second axis (second neutralino)
            }

        }
    else
        {
          dR=dR1;
          if (dR < dRcut)
            {
              Tracks_axis=1;//belongs to second axis (second neutralino)
            }
        }
      // }
      // std::cout<<"dR1= "<<dR1<<";dR2= "<<dR2<<";Track_axis= "<<Tracks_axis<<std::endl;
    float bdtcut=-0.0401;//optimal value w/o track association to axis: -0.0401

    //Check if the hemisphere association matches the ntuple assosication with neutralinos 1 and 2
    if(track_SELEC[i] == true)//apply pre-cut to reduce bkg by 90%
        {
         hData_Jet_Track_dR->Fill( dR );//LOOKAT : gap between tracks and the axis (both of them)  /^\\ pi/2-peak
         hData_Tracks_repart->Fill(Tracks_axis);//LOOKAT : repartition of the tracks wrt to each axis //ok 50/50 between the two neutralinos
          if ( iLLPrec1==1)
            {
              if (Tracks_axis==1 && isFromLLP==1 )//belongs to first hemisphere//1-1
                {
                  // nMatch_1++;
                  hData_isMatched_dR_1->Fill(dR);//nMatch_1
                  nSignalTracks++;
                  nTrackingPerfSignal++;
                  hData_Matched_bdtvalue->Fill(bdtval);
                  if ( bdtval > bdtcut )//signal selection
                    {
                      nMatch_1++;
                      hData_isMVA_Matched_dR_1->Fill(dR);//nMatch_1
                      n_Mva_SignalTracks++;
                      hData_NTracks_1->Fill(nMatch_1);
                    }
                }
              else if(Tracks_axis==2 && isFromLLP==2)//belongs to second hemisphere//2-2
                {
                  
                  hData_isMatched_dR_2->Fill(dR);//nMatch_2
                  nSignalTracks++;
                  nTrackingPerfSignal++;
                  hData_Matched_bdtvalue->Fill(bdtval);
                  if ( bdtval > bdtcut )//signal selection
                    {
                      nMatch_2++;
                      hData_isMVA_Matched_dR_2->Fill(dR);//nMatch_2
                      hData_NTracks_2->Fill(nMatch_2);
                      n_Mva_SignalTracks++;
                    }
                }
              else if( isFromLLP==0)//does not belong to a displaced track (not from neutralino)//2-0 or 1-0
                {//since all tracks are asigned to an hemisphere and considered as signal(Tracks_Axis=1 or 2), some of them could be in reality be not asigned to an 
                  //hemisphere (Tracks_Axis=0 not included yet) and IsFromLLP:: This would be truly reconstructed background.
                  //A distinction should be made between 0-0 (true reco bkg) and (2-0)/(1-0) which are misidentified tracks (next "else") but IsFromLLP=0 give 
                  //them the status of bkg. H/e, all the tracks are well-distinguished atm. Therefore,  precautions sould be taken for this part when changing the 
                  //association between tracks and axis (Track_axis=0 possibility)
                  //CARE: For a 100% Signal Efficiency of the BDT (0%Bkg eff), the missmatch after applying the bdt is between real signal tracks 
                  //(Tracks_axis=0 does not exist hypothetically). Since it is not the case, 0-0 has a probability of happening. This is  where the signal(bkg) efficiency
                  //of the BDT is important.
                    // nMatch_0++;
                    hData_isMatched_dR_0->Fill(dR);////nMatch_0
                    nBkgTracks++;
                    nTrackingPerfBkg++;
                    hData_Matched_bdtvalue->Fill(bdtval);
                    if ( bdtval > bdtcut )//signal selection
                      {
                        hData_isMVA_Matched_dR_0->Fill(dR);//nMatch_0
                        n_Mva_BkgTracks++;
                      }
                }
              else//miss-association of signal: tracks lost for reco?2-1/1-2/
                {
                  // nMissMatch++;
                  hData_dR_isMissMatched->Fill(dR);//nMissMatch
                  nBkgTracks++;
                  nTrackingPerfSignal++;
                  if ( bdtval > bdtcut )//signal selection
                    {
                      hData_isMVA_dR_MissMatched->Fill(dR);//nMissMatch
                      n_Mva_BkgTracks++;
                      hData_NotMatched_bdtvalue->Fill(bdtval);//follows signal BDT distribution
                    } // end if (bdt cut)
                } //  end else
            } // end if illPrec1

          if ( iLLPrec1==2)
            {
              if (Tracks_axis==2 && isFromLLP==1 )//belongs to first hemisphere//1-1//testre avec illp1 ou 2
                {
                  // nMatch_1++;
                  hData_isMatched_dR_1->Fill(dR);//nMatch_1
                  nSignalTracks++;
                  nTrackingPerfSignal++;
                  hData_Matched_bdtvalue->Fill(bdtval);
                  if ( bdtval > bdtcut )//signal selection
                    { nMatch_1++;
                      hData_NTracks_1->Fill(nMatch_1);
                      hData_isMVA_Matched_dR_1->Fill(dR);//nMatch_1
                      n_Mva_SignalTracks++;
                    }
                }
              else if(Tracks_axis==1 && isFromLLP==2)//belongs to second hemisphere//2-2
                {
                  // nMatch_2++;
                  hData_isMatched_dR_2->Fill(dR);//nMatch_2
                  nSignalTracks++;
                  nTrackingPerfSignal++;
                  hData_Matched_bdtvalue->Fill(bdtval);
                  if ( bdtval > bdtcut )//signal selection
                    {
                      nMatch_2++;
                      hData_NTracks_2->Fill(nMatch_2);
                      hData_isMVA_Matched_dR_2->Fill(dR);//nMatch_2
                      n_Mva_SignalTracks++;
                    }
                }
              else if( isFromLLP==0)//does not belong to a displaced track (not from neutralino)//2-0 or 1-0
                {//since all tracks are asigned to an hemisphere and considered as signal(Tracks_Axis=1 or 2), some of them could be in reality be not asigned to an 
                  //hemisphere (Tracks_Axis=0 not included yet) and IsFromLLP:: This would be truly reconstructed background.
                  //A distinction should be made between 0-0 (true reco bkg) and (2-0)/(1-0) which are misidentified tracks (next "else") but IsFromLLP=0 give 
                  //them the status of bkg. H/e, all the tracks are well-distinguished atm. Therefore,  precautions sould be taken for this part when changing the 
                  //association between tracks and axis (Track_axis=0 possibility)
                  //CARE: For a 100% Signal Efficiency of the BDT (0%Bkg eff), the missmatch after applying the bdt is between real signal tracks 
                  //(Tracks_axis=0 does not exist hypothetically). Since it is not the case, 0-0 has a probability of happening. This is  where the signal(bkg) efficiency
                  //of the BDT is important.
                  // nMatch_0++;
                  hData_isMatched_dR_0->Fill(dR);////nMatch_0
                  nBkgTracks++;
                  nTrackingPerfBkg++;
                  hData_Matched_bdtvalue->Fill(bdtval);
                  if ( bdtval > bdtcut )//signal selection
                    {
                      hData_isMVA_Matched_dR_0->Fill(dR);//nMatch_0
                      n_Mva_BkgTracks++;
                    }
                }
              else//miss-association of signal: tracks lost for reco?1-1/2-2/
                {
                  // nMissMatch++;
                  hData_dR_isMissMatched->Fill(dR);//nMissMatch
                  nBkgTracks++;
                  nTrackingPerfSignal++;
                  if ( bdtval > bdtcut )//signal selection
                    {
                      hData_isMVA_dR_MissMatched->Fill(dR);//nMissMatch
                      n_Mva_BkgTracks++;
                      hData_NotMatched_bdtvalue->Fill(bdtval);//follows signal BDT distribution
                    } // end if (bdt cut)
                } //  end else
            } // end if illPrec2
    if(dR1<dRcut && dR2<dRcut)//The considreed track could be associated to both hemis.
      {
        float dRaxis = DeltaR( axis1_eta, axis1_phi, axis2_eta, axis2_phi);
        hData_BothHemi_SB_dR->Fill(dRaxis);//dR between the axis in such a case
	//hData_SB_isMissMatched->Fill(dR);
        if ( iLLPrec1==1 || iLLPrec1==2)
          {
            if( isFromLLP!=0 && (isFromLLP != iLLPrec1 || isFromLLP != iLLPrec2) )
              {
                hData_S_isMissMatched->Fill(dR);
		hData_BothHemi_S_dR->Fill(dRaxis);
              }
            
          }
      }

        }// end Track Selec loop  

// sim tracks associated to reco tracks
     float ptSim  = -1.;
     if ( ntracksim > 0 ) ptSim = tree_track_simtrack_pt->at(i);
     if ( ntracksim > 0 && ptSim > 0. && tree_track_isSimMatched->at(i) ) {
      //can build fakerate with tree_track_isSimMatched above
       float qSim   = tree_track_simtrack_charge->at(i);
       float etaSim = tree_track_simtrack_eta->at(i);
       float phiSim = tree_track_simtrack_phi->at(i);
       float vxgen  = tree_track_genVertexPos_X->at(i);
       float vygen  = tree_track_genVertexPos_Y->at(i);
       float vzgen  = tree_track_genVertexPos_Z->at(i);
       float qR = tree_track_simtrack_charge->at(i) * ptSim * 100 / 0.3 / 3.8;
       float sin0 = qR * sin( phiSim ) + vxgen;
       float cos0 = qR * cos( phiSim ) - vygen;
       float phi0 = TMath::ATan2( sin0, cos0 ); // but note that it can be wrong by +_pi ! 

       dV1= 1000000.;
       dV2= 1000000.;
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
       if ( dV < 0.1 ) track_isfromLLP[i] = iV;//1 or 2
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
       if ( genLLP >= 1 ) hTkGenLLP_test->Fill( iV - genLLP );
       else               hTkGenLLPnot_test->Fill( iV );
       if ( genLLP >= 1 ) hTkGenLLP_dV->Fill( dV );
       else               hTkGenLLPnot_dV->Fill( dV );
       
       if ( track_SELEC[i] ) {
         hTkSim_dV->Fill( dV );
         hTkSim_dV_big->Fill( dV );

         if ( iV >= 1 ) {
           hTkSim_dphiTop->Fill( abs(deltaPhi) );
           float dpt = (pt - ptSim) / pt;
           float deta = eta - etaSim;
           float dphi0 = phi - phi0;
	   if      ( dphi0 < -3.14159 / 2. ) dphi0 = dphi0 + 3.14159;
	   else if ( dphi0 >  3.14159 / 2. ) dphi0 = dphi0 - 3.14159;
           hTkSim_dq->Fill( q - qSim ); // why half of the reco tracks have a wrong charge ?
           hTkSim_dpt->Fill( dpt );
           hTkSim_deta->Fill( deta );
           hTkSim_dphi->Fill( phi - phiSim );
           hTkSim_dphi0->Fill( dphi0 );
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
     if ( !(pt2 >= 1. && chi2 <= 5. && drSig2 >= 5.) ) continue;
       float x2 = tree_track_firsthit_X->at(k);
       float y2 = tree_track_firsthit_Y->at(k);
       float z2 = tree_track_firsthit_Z->at(k);
       float dist = TMath::Sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) );
       if ( dist < 10. ) ntrk10++; 
       if ( dist < 20. ) ntrk20++; 
       if ( dist < 30. ) ntrk30++; 
       if ( dist < 40. ) ntrk40++;
     }  // end Loop on other Tracks

     if ( track_isfromLLP[i] > 0 ) {
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
       hTkSim_z1->Fill( abs(z1) );
       hTkSim_at10->Fill( ntrk10 );
       hTkSim_at20->Fill( ntrk20 );
       hTkSim_at30->Fill( ntrk30 );
       hTkSim_at40->Fill( ntrk40 );
       
       if ( tree_track_numberOfValidPixelBarrelHits->at(i) > 0 )         hTkSim_r1_PXB->Fill( r1 );
       if ( tree_track_numberOfValidStripTIBHits->at(i) > 0 && tree_track_numberOfValidPixelBarrelHits->at(i) == 0 ) hTkSim_r1_TIB->Fill( r1 );
       if ( tree_track_numberOfValidStripTOBHits->at(i) > 0 && tree_track_numberOfValidStripTIBHits->at(i) == 0 ) hTkSim_r1_TOB->Fill( r1 );
       if ( tree_track_numberOfValidPixelEndcapHits->at(i) > 0 )         hTkSim_z1_PXF->Fill( abs(z1) );
       if ( tree_track_numberOfValidStripTIDHits->at(i) > 0 && tree_track_numberOfValidPixelEndcapHits->at(i) == 0 ) hTkSim_z1_TID->Fill( abs(z1) );
       if ( tree_track_numberOfValidStripTECHits->at(i) > 0 && tree_track_numberOfValidStripTIDHits->at(i) == 0 ) hTkSim_z1_TEC->Fill( abs(z1) );

       float deltaR_neu, deltaPhi_neu;
       deltaR   = DeltaR( eta, phi, vaxis1.Eta(), vaxis1.Phi() );//eta phi from the reco tracks, vaxis1 from the first axis defined by reco jets w/o muons in it
       deltaPhi = DeltaPhi( phi, vaxis1.Phi() );
       float deltaRop   = DeltaR( eta, phi, vaxis2.Eta(), vaxis2.Phi() );//same for the other axis
       float deltaPhiop = DeltaPhi( phi, vaxis2.Phi() );
       if ( track_isfromLLP[i] == 1 ) {
         deltaR_neu = DeltaR( eta, phi, vneu[0].Eta(), vneu[0].Phi() );
         deltaPhi_neu = DeltaPhi( phi, vneu[0].Phi() );
	 if ( -vaxis1*vneu[0] > 0 ) {//track could/couldnot be from LLP
           hTkSim_tkjet_ok_DR->Fill( deltaR );
           hTkSim_tkjet_ok_dphi->Fill( abs(deltaPhi) );
	 }
	 else {
           hTkSim_tkjet_op_DR->Fill( deltaRop );
           hTkSim_tkjet_op_dphi->Fill( abs(deltaPhiop) );
	 }
       }
       else {//track isfromLLP
         deltaR_neu = DeltaR( eta, phi, vneu[1].Eta(), vneu[1].Phi() );
         deltaPhi_neu = DeltaPhi( phi, vneu[1].Phi() );
	 if ( -vaxis1*vneu[1] > 0 ) {//memberwise product:pt{axis}*pt{neu}-eta{axis}*eta{neu}-phi{axis}*phi{neu}>0
      // check if the neutralino and axis (jet defined) are close are not depending on the sign
      // compute -(-dR)
           hTkSim_tkjet_ok_DR->Fill( deltaR );//LOOKAT
           hTkSim_tkjet_ok_dphi->Fill( abs(deltaPhi) );//LOOKAT
         }
	 else {
           hTkSim_tkjet_op_DR->Fill( deltaRop );
           hTkSim_tkjet_op_dphi->Fill( abs(deltaPhiop) );
	 }
       }
       hTkSim_tkneu_DR->Fill( deltaR_neu );
       hTkSim_tkneu_dphi->Fill( abs(deltaPhi_neu) );
       hTkSim_tkjet_DR->Fill( deltaR );
       hTkSim_tkjet_dphi->Fill( abs(deltaPhi) );
     }

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
       hTkOth_z1->Fill( abs(z1) );
       hTkOth_at10->Fill( ntrk10 );
       hTkOth_at20->Fill( ntrk20 );
       hTkOth_at30->Fill( ntrk30 );
       hTkOth_at40->Fill( ntrk40 );

       deltaR = DeltaR( eta, phi, vaxis1.Eta(), vaxis1.Phi() );
       deltaPhi = DeltaPhi( phi, vaxis1.Phi() );
       hTkOth_tkjet_DR->Fill( deltaR );
       hTkOth_tkjet_dphi->Fill( abs(deltaPhi) );
     }

   }  // end Loop on Track or TrackSim
    
   hTkSim->Fill( nTkSim );
   hTkOth->Fill( nTkOth );
   hTkAll->Fill( nTkSim + nTkOth );

 } // end loop on events 

 std::cout << "number of events  "<< allevents << std::endl; 
//  std::cout << "number of tracks  "<< nRecoTracks << std::endl; 
//  std::cout << "number of jets    "<< nJets << std::endl; 
//################################################
// float ratioHSCP = nRecoTracks/maxSize;//1-fakerate
// Output Postscript
// std::cout << "Recoefficiency  "<< ratioHSCP << std::endl; 
//   TCanvas* c = new TCanvas("c");
  // hData_nPV -> Draw();
  h1->SetLineColor(kRed);
  hData_FakeRate_vs_pt->SetLineColor(kBlue);
  //h1->Draw("");
  hData_FakeRate_vs_pt->Divide(h1);
  // hData_FakeRate_vs_pt->Draw();
  h1->SetTitle("Blue: isSimMatched / Red:All tracks// Cuts applied");
  // h1->Draw();
  // h_DataHSCP->Draw("SAME");
//   c->Print("output.ps(");



//####################
// SignalEff=nSignalTracks/;
// BkgEff=nBkgTracks/;
float Mva_SignalEff=n_Mva_SignalTracks/nTrackingPerfSignal;//nTrackingPerfSignal contains the mismatch of signal tracks//n-Mva_SignalTracks does not
float Mva_BkgEff=n_Mva_BkgTracks/nTrackingPerfBkg;//nTrackingPerfBkg contains the mismatch of signal tracks//n-Mva_BkgTracks does not
float Significance=nSignalTracks/sqrt(nSignalTracks+nBkgTracks);//nBkgTracks contains the mismacth of signal tracks
float MVA_Significance=n_Mva_SignalTracks/sqrt(n_Mva_SignalTracks+n_Mva_BkgTracks);//n_Mva_BkgTracks contains the mismacth of signal tracks
 std::cout << "n_Mva_SignalTracks  "<< n_Mva_SignalTracks << std::endl; 
 std::cout << "nTrackingPerfSignal "<<nTrackingPerfSignal << std::endl; 
 std::cout << "n_Mva_BkgTracks  "<< n_Mva_BkgTracks << std::endl; 
 std::cout << "nTrackingPerfBkg  "<< nTrackingPerfBkg << std::endl; 
 std::cout << "Mva_SignalEff  "<< Mva_SignalEff << std::endl; //86
 std::cout << "Mva_BkgEff  "<< Mva_BkgEff << std::endl; //21
 std::cout << "Significance   "<< Significance << std::endl; 
 std::cout << "MVA_Significance   "<< MVA_Significance << std::endl; //228
//################################################
  HistogramManager h ;

  h.WriteAllHistogramsInFile(filename.Data(),"recreate");
//################################################
}   


