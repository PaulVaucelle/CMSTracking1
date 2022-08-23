#include <iostream>
#include <TROOT.h>
#include "TVectorD.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TMath.h" 
#include "TString.h"
#include "TF1.h"

void Vertex()
{
//     nbr vertex reconsutrctibles: 
// ttree->Draw("tree_LLP1_x","tree_passesHTFilter")
// ttree->Draw("tree_Vtx_LLP1_x-tree_LLP1_x","tree_Vtx_LLP1_nTrks>=2 && tree_Vtx_LLP1_NChi2>0 && tree_passesHTFilter && abs(tree_Vtx_LLP1_x-tree_LLP1_x)<0.1") pour la résolution

// //Pour efficiencies:

// ttree->Draw("tree_Vtx_mva_LLP1_x","tree_Vtx_mva_LLP1_nTrks>=2 && tree_Vtx_mva_LLP1_NChi2>0 && tree_passesHTFilter") 4661 (4654 par daniel)
// ttree->Draw("tree_Vtx_LLP1_z","tree_Vtx_LLP1_nTrks>=2 && tree_Vtx_LLP1_NChi2>0 && tree_passesHTFilter && tree_Vtx_LLP1_NChi2<5")

//#######################Parameters to be changed depending on what you want#############################//
bool MVA = false;

//===================File PATH=============================//
TFile *f1;

// f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
// f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/CMSSW_10_6_20_LLP2/src/test_MC/step3/UDD_bgctau50_smu275_snu225/2018_step3_test/0000/Ntuplebgctau50.root");
// f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau30_smu300_snu250.root");
// f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");

//////////------------Main Histograms-------//////////

TString htitle_resx = "hData_Vtx_reco_dx";
TString htitle_resz = "hData_Vtx_reco_dz";
TString htitleBDT_resx = "hData_Vtx_mva_dx";
TString htitleBDT_resz = "hData_Vtx_mva_dz";
// TString htitlegen_resx = "hData_Vtx_x";
// TString htitle_HTFilter = "hData_passesHTFilter";
TString xtitle = "deltaX (cm)"; 
TString ytitle = "# nbr of vertices";
int nbin = 101; 
float xmin = -0.1;
float xmax = 0.1;

//////////////-----W/o MVA HISTOGRAMS----------///////////
TString htitle_nTrks = "hData_Vtx_reco_Ntrk";
TString htitle_NChi2 = "hData_Vtx_reco_Chi2";

//////////////-----MVA HISTOGRAMS----------///////////
TString htitle_MVA_nTrks = "hData_Vtx_mva_Ntrk";
TString htitle_MVA_NChi2 = "hData_Vtx_mva_Chi2";

//////////------------CANVAS-----------//////////

   auto c1 = new TCanvas(); 
//    c1->DrawFrame(0.,0.,1.,1.);
   auto c2 = new TCanvas(); 
//    c2->DrawFrame(0.,0.,2.,2.);
   auto c3 = new TCanvas(); 
//    c3->DrawFrame(0.,0.,3.,3.);
   auto c4 = new TCanvas(); 
//    c4->DrawFrame(0.,0.,4.,4.);
   auto FourPads = new TCanvas("FourPads","Plots for the filter only");
   FourPads->Divide(2,2);
   FourPads->cd(1) ; c1->DrawClonePad();
   
// c1->SetFillColor(10);
// c1->SetFillStyle(4000);
// c1->SetBorderSize(0);

/////////////----------gStyle----------///////////
gStyle->SetOptDate(0);
gStyle->SetStatColor(0);
gStyle->SetTitleFont(62);
gStyle->SetTitleColor(1);
gStyle->SetTitleTextColor(1);
gStyle->SetTitleFillColor(10);
gStyle->SetTitleFontSize(0.05);
gStyle->SetTitleW(0.4);
gStyle->SetTitleH(0.09);

/////////-----------Get histograms---------------//////////
//########################################################//
f1->cd();
TH1F* gRecox = (TH1F*)gROOT->FindObject(htitle_resx);
TH1F* gRecoz = (TH1F*)gROOT->FindObject(htitle_resz);
TH1F* gBDTx = (TH1F*)gROOT->FindObject(htitleBDT_resx);
TH1F* gBDTz = (TH1F*)gROOT->FindObject(htitleBDT_resz);
// TH1F* gGen = (TH1F*)gROOT->FindObject(htitlegen_resx);
TH1F* g3 = (TH1F*)gROOT->FindObject(htitle_nTrks);      
TH1F* g4 = (TH1F*)gROOT->FindObject(htitle_NChi2);
//////////////-----MVA HISTOGRAMS----------///////////
TH1F* g5 = (TH1F*)gROOT->FindObject(htitle_MVA_nTrks);
TH1F* g6 = (TH1F*)gROOT->FindObject(htitle_MVA_NChi2);
//########################################################//
/////////-------------Histogram to store resolution
TH1F* h1 = new TH1F("h1","res_x",nbin,xmin,xmax);
h1->SetLineColor(kBlue);
h1->SetLineStyle(1);
h1->SetLineWidth(2);
h1->SetMarkerColor(kBlue);
h1->SetMarkerStyle(22);
h1->SetMarkerSize(0.7);
h1->SetTickLength(0.03, "YZ");
h1->SetTickLength(0.03,"X");
h1->SetLabelOffset(0.01,"XYZ");
h1->SetLabelSize(0.05, "XYZ");
h1->SetLabelFont(42, "XYZ"); 
h1->SetTitleFont(42, "XYZ");
h1->SetTitleSize(0.05, "XYZ"); 
h1->SetTitleOffset(1.2,"XYZ"); 
h1->GetXaxis()->SetTitle(xtitle);
h1->GetXaxis()->SetTitleColor(1);
h1->GetXaxis()->SetNdivisions(509);
h1->GetYaxis()->SetTitle(ytitle);
h1->GetYaxis()->SetTitleColor(1);
h1->GetYaxis()->SetNdivisions(509);
h1->SetNdivisions(509,"XYZ");
//////////////////
// pad1->cd();

h1->Add(gRecox,h1,1,0);
h1->Draw("");
// TF1 *func1 = new TF1("func1","[0]*exp(-0.5*((x-[1])/[2])^2)",-0.1,0.1);
// func1->SetParameter(0,1300);
// func1->SetParameter(1,0);
// func1->SetParameter(2,0.003);
// func1->SetLineColor(kBlue);
// func1->Draw("same");
// h1->Fit(func1);//,"L","",xmin,xmax


/////////////////////////Canvas 2//////////////////////////
FourPads->cd(2) ; c2->DrawClonePad();
/////////-------------Histogram to store resolution
TH1F* h2 = new TH1F("h2","res_z",nbin,xmin,xmax);
h2->SetLineColor(kBlue);
h2->SetLineStyle(1);
h2->SetLineWidth(2);
h2->SetMarkerColor(kBlue);
h2->SetMarkerStyle(22);
h2->SetMarkerSize(0.7);
h2->SetTickLength(0.03, "YZ");
h2->SetTickLength(0.03,"X");
h2->SetLabelOffset(0.01,"XYZ");
h2->SetLabelSize(0.05, "XYZ");
h2->SetLabelFont(42, "XYZ"); 
h2->SetTitleFont(42, "XYZ");
h2->SetTitleSize(0.05, "XYZ"); 
h2->SetTitleOffset(1.2,"XYZ"); 
h2->GetXaxis()->SetTitle(xtitle);
h2->GetXaxis()->SetTitleColor(1);
h2->GetXaxis()->SetNdivisions(509);
h2->GetYaxis()->SetTitle(ytitle);
h2->GetYaxis()->SetTitleColor(1);
h2->GetYaxis()->SetNdivisions(509);
h2->SetNdivisions(509,"XYZ");

//########################################################//
h2->Add(gRecoz,h2,1,0);
h2->Draw("");
// TF1 *func2 = new TF1("func2","[0]*exp(-0.5*((x-[1])/[2])^2)",-0.1,0.1);
// func2->SetParameter(0,900);
// func2->SetParameter(1,0);
// func2->SetParameter(2,0.005);
// func2->SetLineColor(kBlue);
// func2->Draw("same");
///----Canvas 3------------//
FourPads->cd(3) ; c3->DrawClonePad();

TH1F* h3 = new TH1F("h3","# of Tracks per Vertex",101,0,100);
h3->SetLineColor(kGreen);
h3->SetLineStyle(1);
h3->SetLineWidth(2);
h3->SetMarkerColor(kGreen);
h3->SetMarkerStyle(22);
h3->SetTickLength(0.03, "YZ");
h3->SetTickLength(0.03,"X");
h3->SetLabelOffset(0.01,"XYZ");
h3->SetLabelSize(0.05, "XYZ");
h3->SetLabelFont(42, "XYZ"); 
h3->SetTitleFont(42, "XYZ");
h3->SetTitleSize(0.05, "XYZ"); 
h3->SetTitleOffset(1.2,"XYZ"); 
h3->GetXaxis()->SetTitle("# of tracks");
h3->GetXaxis()->SetTitleColor(1);
h3->GetXaxis()->SetNdivisions(509);
h3->GetYaxis()->SetTitle("# of vertices");
h3->GetYaxis()->SetTitleColor(1);
h3->GetYaxis()->SetNdivisions(509);
h3->SetNdivisions(509,"XYZ");

//########################################################//
h3->Add(g3,h3,1,0);
h3->Draw("");

///----Canvas 4---------//
FourPads->cd(4) ; c4->DrawClonePad();

TH1F* h4 = new TH1F("h4","CHi2 distribution",101,0,100);
h4->SetLineColor(kBlack);
h4->SetLineStyle(1);
h4->SetLineWidth(2);
h4->SetMarkerColor(kBlack);
h4->SetMarkerStyle(22);
h4->SetMarkerSize(0.7);
h4->SetTickLength(0.03, "YZ");
h4->SetTickLength(0.03,"X");
h4->SetLabelOffset(0.01,"XYZ");
h4->SetLabelSize(0.05, "XYZ");
h4->SetLabelFont(42, "XYZ"); 
h4->SetTitleFont(42, "XYZ");
h4->SetTitleSize(0.05, "XYZ"); 
h4->SetTitleOffset(1.2,"XYZ"); 
h4->GetXaxis()->SetTitle("Chi2");
h4->GetXaxis()->SetTitleColor(1);
h4->GetXaxis()->SetNdivisions(509);
h4->GetYaxis()->SetTitle(ytitle);
h4->GetYaxis()->SetTitleColor(1);
h4->GetYaxis()->SetNdivisions(509);
h4->SetNdivisions(509,"XYZ");

//########################################################//
h4->Add(g4,h4,1,0);
h4->Draw("");

//////////////////---MVA-CANVAS-------------///
//////////------------CANVAS-----------//////////

   auto c5 = new TCanvas(); 
//    c5->DrawFrame(0.,0.,1.,1.);
   auto c6 = new TCanvas(); 
//    c6->DrawFrame(0.,0.,2.,2.);
   auto c7 = new TCanvas(); 
//    c7->DrawFrame(0.,0.,3.,3.);
   auto c8 = new TCanvas(); 
//    c8->DrawFrame(0.,0.,4.,4.);
   auto FourPads2 = new TCanvas("FourPads2","Plots for filter+BDT");
   FourPads2->Divide(2,2);
   FourPads2->cd(1) ; c5->DrawClonePad();


/////////-------------Histogram to store resolution
TH1F* h5 = new TH1F("h5","res_x",nbin,xmin,xmax);
h5->SetLineColor(kBlue);
h5->SetLineStyle(1);
h5->SetLineWidth(2);
h5->SetMarkerColor(kBlue);
h5->SetMarkerStyle(22);
h5->SetMarkerSize(0.7);
h5->SetTickLength(0.03, "YZ");
h5->SetTickLength(0.03,"X");
h5->SetLabelOffset(0.01,"XYZ");
h5->SetLabelSize(0.05, "XYZ");
h5->SetLabelFont(42, "XYZ"); 
h5->SetTitleFont(42, "XYZ");
h5->SetTitleSize(0.05, "XYZ"); 
h5->SetTitleOffset(1.2,"XYZ"); 
h5->GetXaxis()->SetTitle(xtitle);
h5->GetXaxis()->SetTitleColor(1);
h5->GetXaxis()->SetNdivisions(509);
h5->GetYaxis()->SetTitle(ytitle);
h5->GetYaxis()->SetTitleColor(1);
h5->GetYaxis()->SetNdivisions(509);
h5->SetNdivisions(509,"XYZ");
//########################################################//
h5->Add(gBDTx,h5,1,0);
h5->Draw("");

// TF1 *func3 = new TF1("func3","[0]*exp(-0.5*((x-[1])/[2])^2)",-0.1,0.1);
// func3->SetParameter(0,1275);
// func3->SetParameter(1,0);
// func3->SetParameter(2,0.004);
// func3->SetLineColor(kBlue);
// func3->Draw("same");
////////------------///////////////////
FourPads2->cd(2) ; c6->DrawClonePad();

TH1F* h6 = new TH1F("h6","res_z",nbin,xmin,xmax);
h6->SetLineColor(kBlue);
h6->SetLineStyle(1);
h6->SetLineWidth(2);
h6->SetMarkerColor(kBlue);
h6->SetMarkerStyle(22);
h6->SetMarkerSize(0.7);
h6->SetTickLength(0.03, "YZ");
h6->SetTickLength(0.03,"X");
h6->SetLabelOffset(0.01,"XYZ");
h6->SetLabelSize(0.05, "XYZ");
h6->SetLabelFont(42, "XYZ"); 
h6->SetTitleFont(42, "XYZ");
h6->SetTitleSize(0.05, "XYZ"); 
h6->SetTitleOffset(1.2,"XYZ"); 
h6->GetXaxis()->SetTitle("deltaZ (cm)");
h6->GetXaxis()->SetTitleColor(1);
h6->GetXaxis()->SetNdivisions(509);
h6->GetYaxis()->SetTitle(ytitle);
h6->GetYaxis()->SetTitleColor(1);
h6->GetYaxis()->SetNdivisions(509);
h6->SetNdivisions(509,"XYZ");
//########################################################//
h6->Add(gBDTz,h6,1,0);
h6->Draw("");

// TF1 *func4 = new TF1("func4","[0]*exp(-0.5*((x-[1])/[2])^2)",-0.1,0.1);
// func4->SetParameter(0,890);
// func4->SetParameter(1,0);
// func4->SetParameter(2,0.0055);
// func4->SetLineColor(kBlue);
// func4->Draw("same");
// h6->Fit("gaus","","",-0.1,0.1);
////////------------///////////////////
FourPads2->cd(3) ; c7->DrawClonePad();
TH1F* h7 = new TH1F("h7","res_x",101,0,100);
h7->SetLineColor(kBlue);
h7->SetLineStyle(1);
h7->SetLineWidth(2);
h7->SetMarkerColor(kBlue);
h7->SetMarkerStyle(22);
h7->SetMarkerSize(0.7);
h7->SetTickLength(0.03, "YZ");
h7->SetTickLength(0.03,"X");
h7->SetLabelOffset(0.01,"XYZ");
h7->SetLabelSize(0.05, "XYZ");
h7->SetLabelFont(42, "XYZ"); 
h7->SetTitleFont(42, "XYZ");
h7->SetTitleSize(0.05, "XYZ"); 
h7->SetTitleOffset(1.2,"XYZ"); 
h7->GetXaxis()->SetTitle("# of tracks");
h7->GetXaxis()->SetTitleColor(1);
h7->GetXaxis()->SetNdivisions(509);
h7->GetYaxis()->SetTitle("# of vertices");
h7->GetYaxis()->SetTitleColor(1);
h7->GetYaxis()->SetNdivisions(509);
h7->SetNdivisions(509,"XYZ");
//########################################################//
h7->Add(g5,h7,1,0);
h7->Draw("");

////////------------///////////////////
FourPads2->cd(4) ; c8->DrawClonePad();
TH1F* h8 = new TH1F("h8","Chi2 ",101,0,100);
h8->SetLineColor(kBlue);
h8->SetLineStyle(1);
h8->SetLineWidth(2);
h8->SetMarkerColor(kBlue);
h8->SetMarkerStyle(22);
h8->SetMarkerSize(0.7);
h8->SetTickLength(0.03, "YZ");
h8->SetTickLength(0.03,"X");
h8->SetLabelOffset(0.01,"XYZ");
h8->SetLabelSize(0.05, "XYZ");
h8->SetLabelFont(42, "XYZ"); 
h8->SetTitleFont(42, "XYZ");
h8->SetTitleSize(0.05, "XYZ"); 
h8->SetTitleOffset(1.2,"XYZ"); 
h8->GetXaxis()->SetTitle("Chi2");
h8->GetXaxis()->SetTitleColor(1);
h8->GetXaxis()->SetNdivisions(509);
h8->GetYaxis()->SetTitle("# of vertices");
h8->GetYaxis()->SetTitleColor(1);
h8->GetYaxis()->SetNdivisions(509);
h8->SetNdivisions(509,"XYZ");
//########################################################//
h8->Add(g6,h8,1,0);
h8->Draw("");

//-----Update-------/
c8->Draw();
c1->Update();
c2->Update();
c3->Update();
c4->Update();
c5->Update();
c6->Update();
c7->Update();
c8->Update();
}