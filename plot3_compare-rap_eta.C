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

void plot()
{
       //Test: change from VSCode
int stati=0;
bool fit= 0;
bool logx=0;
bool logy=0;

 TFile *f1, *f2, *f3, *f4;
 
 f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
 f2 = new  TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
 
//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
//  f2 = new  TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
 
//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau30_smu300_snu250.root");
//  f2 = new  TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau30_smu300_snu250.root");

//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");
//  f2 = new  TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

//$$
 int nfiles = 2;
//$$

 int color1 = kGray+2;
 int color2 = kBlue;
 int color3 = kGreen+1;
 int color4 = kRed;
 int mark1 = 22; int markc1 = mark1+4;
 int mark2 = 21; int markc2 = mark2+4;
 int mark3 = 23; int markc3 = 32;
 int mark4 = 20; int markc4 = mark4+4;

 if ( nfiles == 2 ) {
   color1 = kBlue;
   color2 = kRed;
   mark1 = 20; markc1 = mark1+4;
   mark2 = 21; markc2 = mark2+4;
 } 

 if ( nfiles == 3 ) {
   color1 = kBlue;
   color2 = kGreen+1;
   color3 = kRed;
   mark1 = 22; int markc1 = mark1+4;
   mark2 = 20; int markc2 = mark2+4;
   mark3 = 21; int markc3 = mark3+4;
 } 

 //TString htflav = "hCFlav";  

//##################BDT VARIABLES######################## 
// TString htitle = "hTkOth_pt";  
// TString htitle2 = "hTkSim_pt";
// TString xtitle = "track p_T [GeV]"; 
// int nbin = 100; 
// float xmin =  0.;
// float xmax = 100.;
// float ymin = 0.00001; 
// float ymax = 2.; // logy

//  TString htitle = "hTkOth_eta"; 
//  TString htitle2 = "hTkSim_eta";
//  TString xtitle = "eta"; 
//  int nbin = 50; 
//  float xmin = -2.5;
//  float xmax = 2.5;
//  float ymin = 0.00001; // logy
//  float ymax = 0.045; 

 
//  TString htitle = "hTkOth_dr";
//  TString htitle2= "hTkSim_dr";
//  TString xtitle = "dr"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 10;
//  float ymin = 0.0006; 
//  float ymax = 0.08; //logy

//  TString htitle = "hTkOth_dz";
//  TString htitle2 = "hTkSim_dz";
//  TString xtitle = "dz"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 50;
//  float ymin = 0.00001; 
//  float ymax = 0.07; //,log x and log y (everything works for it)
 
//  TString htitle = "hTkOth_dd";
//  TString htitle2 = "hTkSim_dd";
//  TString xtitle = "dd"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 50;
//  float ymin = 0.; 
//  float ymax = 0.07;  // logy and not log x 

 
//  TString htitle = "hTkOth_drSig";
//  TString htitle2 = "hTkSim_drSig";
//  TString xtitle = "drSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.1; //not ymin not ymax, logy and not log x 


//  TString htitle = "hTkOth_dzSig";
//  TString htitle2 = "hTkSim_dzSig";
//  TString xtitle = "dzSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.1;//not ymin not ymax, logy and not log x 
 
//  TString htitle = "hTkOth_ddSig";
//  TString htitle2 = "hTkSim_ddSig";
//  TString xtitle = "ddSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.07;//not ymin not ymax, logy and not log x 

 TString htitle = "hTkOth_inJet";
 TString htitle2 = "hTkSim_inJet";
 TString xtitle = "inJet"; 
 int nbin = 2; 
 float xmin = -0.5;
 float xmax = 1.5;
 float ymin = 0.; 
 float ymax = 1;//not ymin not ymax, not logy and not log x
 
//  TString htitle = "hTkOth_pix";
//  TString htitle2 = "hTkSim_pix";
//  TString xtitle = "pix"; 
//  int nbin = 30; 
//  float xmin = -0.5;
//  float xmax = 25;
//  float ymin = 0.; 
//  float ymax = 0.5;//not ymin not ymax,  logy and not log x
 
//  TString htitle = "hTkOth_hit";
//  TString htitle2 = "hTkSim_hit";
//   TString xtitle = "hit"; 
//  int nbin = 30; 
//  float xmin = -0.5;
//  float xmax = 29.5;
//  float ymin = 0.; 
//  float ymax = 0.2;//not ymin not ymax,  logy and not log x
 
//  TString htitle = "hTkOth_chi";
//  TString htitle2 = "hTkSim_chi";
//  TString xtitle = "chi"; 
//  int nbin = 50; 
//  float xmin = 0.;
//  float xmax = 10.;
//  float ymin = 0.; 
//  float ymax = 0.65;//not ymin not ymax,  logy and not log x
 
//  TString htitle = "hTkOth_r1";
//  TString htitle2 = "hTkSim_r1";
//  TString xtitle = "r1"; 
//  int nbin = 200; 
//  float xmin = 0.;
//  float xmax = 100.;
//  float ymin = 0.; 
//  float ymax = 0.07;// logy and not log x
 
//  TString htitle = "hTkOth_z1";
//  TString htitle2 = "hTkSim_z1";
//  TString xtitle = "z1"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 100;
//  float ymin = 0.; 
//  float ymax = 0.07;// logy and not log x
 
//  TString htitle = "hTkOth_at10";  
//  TString htitle2 = "hTkSim_at10";
//  TString xtitle = "at10"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;// logy and not log x
 
//  TString htitle = "hTkOth_at20";
//  TString htitle2 = "hTkSim_at20";
//  TString xtitle = "at20"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;// logy and not log x 
 
//  TString htitle = "hTkOth_at30";
//  TString htitle2 = "hTkSim_at30";
//  TString xtitle = "at30"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;// logy and not log x 
 
//  TString htitle = "hTkOth_at40";
//  TString htitle2 = "hTkSim_at40";
//  TString xtitle = "at40"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;

 //TString htitle = htflav+htit; 
 //if ( ymin == 0. ) logy = 0; 

// *****************************************************************************

 TCanvas *c1 = new TCanvas("c1", "plots",100,10,1050,400);
//  TCanvas *c1 = new TCanvas("c1", "plots",100,10,1050,800);
 c1->SetFillColor(10);
 c1->SetFillStyle(4000);
 c1->SetBorderSize(2);

TPad* pad1 = new TPad("pad1","This is pad1",0.03,0.28,0.75,0.96,21);
TPad* pad2 = new TPad("pad2","This is pad2",0.85,0.28,0.89,0.96,21);
TPad* pad3 = new TPad("pad3","This is pad3",0.9,0.28,0.99,0.96,21);

TPad* rap1 = new TPad("rap1","This is rap1",0.03,0.04,0.75,0.28,21);
TPad* rap2 = new TPad("rap2","This is rap2",0.8,0.04,0.89,0.28,21);//0.36,..,0.69
TPad* rap3 = new TPad("rap3","This is rap3",0.9,0.04,0.99,0.28,21);//0.69,..,0.99

 pad1->SetFillColor(0);
 pad1->SetBorderMode(0);
 pad1->SetFrameFillColor(10);
 pad1->Draw();
 pad1->SetLogx(logx);
 pad1->SetLogy(logy);
 pad1->SetGrid();
 pad1->SetTopMargin(0.03);
 pad1->SetBottomMargin(0.12);
 pad1->SetRightMargin(0.01);
 pad1->SetLeftMargin(0.12);

 pad2->SetFillColor(0);
 pad2->SetBorderMode(0);
 pad2->SetFrameFillColor(10);
 pad2->Draw();
 pad2->SetLogx(logx);
 pad2->SetLogy(logy);
 pad2->SetGrid();
 pad2->SetTopMargin(0.03);
 pad2->SetBottomMargin(0.12);
 pad2->SetRightMargin(0.01);
 pad2->SetLeftMargin(0.12);

 pad3->SetFillColor(0);
 pad3->SetBorderMode(0);
 pad3->SetFrameFillColor(10);
 pad3->Draw();
 pad3->SetLogx(logx);
 pad3->SetLogy(logy);
 pad3->SetGrid();
 pad3->SetTopMargin(0.03);
 pad3->SetBottomMargin(0.12);
 pad3->SetRightMargin(0.01);
 pad3->SetLeftMargin(0.12);

 rap1->SetFillColor(0);
 rap1->SetBorderMode(0);
 rap1->SetFrameFillColor(10);
 rap1->Draw();
 rap1->SetGrid();
 rap1->SetTopMargin(0.03);
 rap1->SetBottomMargin(0.12);
 rap1->SetRightMargin(0.01);
 rap1->SetLeftMargin(0.12);

 rap2->SetFillColor(0);
 rap2->SetBorderMode(0);
 rap2->SetFrameFillColor(10);
 rap2->Draw();
 rap2->SetGrid();
 rap2->SetTopMargin(0.03);
 rap2->SetBottomMargin(0.12);
 rap2->SetRightMargin(0.01);
 rap2->SetLeftMargin(0.12);

 rap3->SetFillColor(0);
 rap3->SetBorderMode(0);
 rap3->SetFrameFillColor(10);
 rap3->Draw();
 rap3->SetGrid();
 rap3->SetTopMargin(0.03);
 rap3->SetBottomMargin(0.12);
 rap3->SetRightMargin(0.01);
 rap3->SetLeftMargin(0.12);

gStyle->SetOptDate(0);
gStyle->SetStatColor(0);
gStyle->SetTitleFont(62);
gStyle->SetTitleColor(1);
gStyle->SetTitleTextColor(1);
gStyle->SetTitleFillColor(10);
gStyle->SetTitleFontSize(0.05);
gStyle->SetTitleW(0.4);
gStyle->SetTitleH(0.09);
// gStyle->SetTitleX(0); // Set the position of the title box
// gStyle->SetTitleY(0.985); // Set the position of the title box
// gStyle->SetTitleStyle(Style_t style = 1001);
// gStyle->SetTitleBorderSize(2);
gStyle->SetOptStat(stati);
// gStyle->SetPadTickX(1); gStyle->SetPadTickY(1);
// gStyle->SetPadGridX(true); gStyle->SetPadGridY(true);

// if (fit) {
// gStyle->SetStatW(0.3);
// gStyle->SetStatH(0.1);
// gStyle->SetOptFit(111);
// } else {
// gStyle->SetStatW(0.3);
// gStyle->SetStatH(0.2);
// gStyle->SetOptFit(0);
// }

// *****************************************************************************

  pad1->cd();

       f1->cd();
 TH1F* g1 = (TH1F*)gROOT->FindObject(htitle);
       g1->Sumw2();
 TH1F* h1 = new TH1F("h1","",nbin,xmin,xmax);
       h1->Add(g1,h1,1/g1->Integral(0,nbin+1),0);
//        h1->Draw("EHF"); 
       h1->Draw("E"); 
       h1->SetLineColor(color1);
//        h1->SetFillColor(color1);
//        h1->SetFillStyle(3345);
       h1->SetLineStyle(1);
       h1->SetLineWidth(3);
       h1->SetMarkerColor(color1);
       h1->SetMarkerStyle(mark1);
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
       h1->GetYaxis()->SetTitle("a.u");
       h1->GetYaxis()->SetTitleColor(1);
       h1->GetYaxis()->SetNdivisions(509);
       h1->SetNdivisions(509,"XYZ");
       //  h1->SetMinimum(ymin); 
       //  h1->SetMaximum(ymax); 

       f2->cd();
 TH1F* g2 = (TH1F*)gROOT->FindObject(htitle2);
       g2->Sumw2();
 TH1F* h2 = new TH1F("h2","",nbin,xmin,xmax);
       h2->Add(g2,h2,1/g2->Integral(0,nbin+1),0);
//        h2->Draw("EHFsame"); 
       h2->Draw("Esame"); 
       h2->SetLineColor(color2);
//        h2->SetFillColor(color2);
//        h2->SetFillStyle(3354);
       h2->SetLineStyle(1);
       h2->SetLineWidth(3);
       h2->SetMarkerColor(color2);
       h2->SetMarkerStyle(mark2);
       h2->SetMarkerSize(0.7);
/*
       f3->cd();
 TH1F* g3 = (TH1F*)gROOT->FindObject(htitle);
       g3->Sumw2();
 TH1F* h3 = new TH1F("h3","",nbin,xmin,xmax);
       h3->Add(g3,h3,1/g3->Integral(0,nbin+1),0);
       h3->Draw("Esame"); 
       h3->SetLineColor(color3);
       h3->SetLineStyle(1);
       h3->SetLineWidth(3);
       h3->SetMarkerColor(color3);
       h3->SetMarkerStyle(mark3);
       h3->SetMarkerSize(0.7);
*/
//        f4->cd();
//  TH1F* g4 = (TH1F*)gROOT->FindObject(htitle+"_etaLT17");
//        g4->Sumw2();
//  TH1F* h4 = new TH1F("h4","",nbin,xmin,xmax);
//        h4->Add(g4,h4,1/g4->Integral(0,nbin+1),0);
//        h4->Draw("Esame"); 
//        h4->SetLineColor(color4);
//        h4->SetLineStyle(1);
//        h4->SetLineWidth(3);
//        h4->SetMarkerColor(color4);
//        h4->SetMarkerStyle(mark4);
//        h4->SetMarkerSize(0.7);
  
  TLegend* leg;
  
  leg = new TLegend(0.16,0.20,0.25,0.25);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("Reco Track");
  leg->Draw();
  
  leg = new TLegend(0.16,0.15,0.40,0.20);
  leg->SetBorderSize(0);
  //leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("pt >= 1. && chi2 <= 5. && drSig >= 5.");
  leg->Draw();

  leg = new TLegend(0.8,0.74,0.99,0.95);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader(" LLP // !LLP");
  leg->AddEntry(h1," notFromLLP","P");
  leg->AddEntry(h2," isFromLLP","P");
  
// leg->AddEntry(h3," D81 (T26)","P");
//   leg->AddEntry(h1," 111X T15","P");
//   leg->AddEntry(h2," 113X T21","P");
//   leg->AddEntry(h3," 113X T25","P");
//   leg->AddEntry(h4," 113X T26","P");
  leg->Draw();
  
// *************************
 rap1->cd();

 TH1F* r2= new TH1F("r2","",nbin,xmin,xmax);
       r2->Divide(h2,h1,1,1);//isFromLLP / notFromLLP
       r2->Draw("E"); 
       r2->SetLineColor(color2);
       r2->SetLineStyle(1);
       r2->SetLineWidth(1);
       r2->SetMarkerColor(color2);
       r2->SetMarkerStyle(mark2);
       r2->SetMarkerSize(0.4);
       r2->SetTickLength(0.03, "XYZ");
       r2->SetLabelOffset(0.03,"XYZ");
       r2->SetLabelSize(0.14, "Y");
       r2->SetLabelSize(0.  , "XZ");
       r2->SetLabelFont(42, "XYZ"); 
       r2->SetTitleFont(42, "XYZ");
       r2->SetTitleSize(0.14, "XYZ"); 
       r2->SetTitleOffset(0.4,"XYZ");
       r2->GetXaxis()->SetTitleColor(1);
       r2->GetXaxis()->SetNdivisions(509);
       r2->GetYaxis()->SetTitle("LLP / !LLP");
       r2->GetYaxis()->SetTitleColor(1);
       r2->GetYaxis()->SetNdivisions(509);
       r2->SetNdivisions(509,"XYZ");
       r2->SetMinimum(0.); 
       //r2->SetMaximum(4.);  
/*
 TH1F* r3= new TH1F("r3","",nbin,xmin,xmax);
       r3->Divide(h3,h1,1,1);
       r3->Draw("Esame"); 
       r3->SetLineColor(color3);
       r3->SetLineStyle(1);
       r3->SetLineWidth(1);
       r3->SetMarkerColor(color3);
       r3->SetMarkerStyle(mark3);
       r3->SetMarkerSize(0.4);
*/
//  TH1F* r4= new TH1F("r4","",nbin,xmin,xmax);
//        r4->Divide(h4,h1,1,1);
//        r4->Draw("Esame"); 
//        r4->SetLineColor(color4);
//        r4->SetLineStyle(1);
//        r4->SetLineWidth(1);
//        r4->SetMarkerColor(color4);
//        r4->SetMarkerStyle(mark4);
//        r4->SetMarkerSize(0.4);
/*
// *****************************************************************************

  pad2->cd();

       f1->cd();
       g1 = (TH1F*)gROOT->FindObject(htitle);
       h1 = new TH1F("h1","",nbin,xmin,xmax);
       h1->Add(g1,h1,1/g1->Integral(0,nbin+1),0);
//        h1->Draw("EHF"); 
       h1->Draw("E"); 
       h1->SetLineColor(color1);
//        h1->SetFillColor(color1);
//        h1->SetFillStyle(3345);
       h1->SetLineStyle(1);
       h1->SetLineWidth(3);
       h1->SetMarkerColor(color1);
       h1->SetMarkerStyle(mark1);
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
       h1->GetYaxis()->SetTitle("a.u");
       h1->GetYaxis()->SetTitleColor(1);
       h1->GetYaxis()->SetNdivisions(509);
       h1->SetNdivisions(509,"XYZ");
       h1->SetMinimum(ymin); 
       h1->SetMaximum(ymax); 

       f2->cd();
       g2 = (TH1F*)gROOT->FindObject(htitle2);
       g2->Sumw2();
       h2 = new TH1F("h2","",nbin,xmin,xmax);
       h2->Add(g2,h2,1/g2->Integral(0,nbin+1),0);
//        h2->Draw("EHFsame"); 
       h2->Draw("Esame"); 
       h2->SetLineColor(color2);
//        h2->SetFillColor(color2);
//        h2->SetFillStyle(3354);
       h2->SetLineStyle(1);
       h2->SetLineWidth(3);
       h2->SetMarkerColor(color2);
       h2->SetMarkerStyle(mark2);
       h2->SetMarkerSize(0.7);

       f3->cd();
       g3 = (TH1F*)gROOT->FindObject(htitle);
       g3->Sumw2();
       h3 = new TH1F("h3","",nbin,xmin,xmax);
       h3->Add(g3,h3,1/g3->Integral(0,nbin+1),0);
       h3->Draw("Esame"); 
       h3->SetLineColor(color3);
       h3->SetLineStyle(1);
       h3->SetLineWidth(3);
       h3->SetMarkerColor(color3);
       h3->SetMarkerStyle(mark3);
       h3->SetMarkerSize(0.7);

//        f4->cd();
//        g4 = (TH1F*)gROOT->FindObject(htitle+"_17eta30");
//        g4->Sumw2();
//        h4 = new TH1F("h4","",nbin,xmin,xmax);
//        h4->Add(g4,h4,1/g4->Integral(0,nbin+1),0);
//        h4->Draw("Esame"); 
//        h4->SetLineColor(color4);
//        h4->SetLineStyle(1);
//        h4->SetLineWidth(3);
//        h4->SetMarkerColor(color4);
//        h4->SetMarkerStyle(mark4);
//        h4->SetMarkerSize(0.7);
  
  leg = new TLegend(0.16,0.90,0.60,0.95);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("Phase-2 t#bar{t} Sim., PU200");
  leg->Draw();
  
  leg = new TLegend(0.16,0.83,0.72,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("jet p_{T} > 15 GeV, 1.7 < |#eta| < 3.0");
  leg->Draw();
  
  leg = new TLegend(0.72,0.55,0.94,0.80);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("c jets");
  leg->AddEntry(h1," D76 (T21)","P");
  leg->AddEntry(h2," D80 (T25)","P");
  leg->AddEntry(h3," D81 (T26)","P");
//   leg->AddEntry(h1," 111X T15","P");
//   leg->AddEntry(h2," 113X T21","P");
//   leg->AddEntry(h3," 113X T25","P");
//   leg->AddEntry(h4," 113X T26","P");
  leg->Draw();
  
// *************************
 rap2->cd();

       r2= new TH1F("r2","",nbin,xmin,xmax);
       r2->Divide(h2,h1,1,1);
       r2->Draw("E"); 
       r2->SetLineColor(color2);
       r2->SetLineStyle(1);
       r2->SetLineWidth(1);
       r2->SetMarkerColor(color2);
       r2->SetMarkerStyle(mark2);
       r2->SetMarkerSize(0.4);
       r2->SetTickLength(0.03, "XYZ");
       r2->SetLabelOffset(0.03,"XYZ");
       r2->SetLabelSize(0.14, "Y");
       r2->SetLabelSize(0.  , "XZ");
       r2->SetLabelFont(42, "XYZ"); 
       r2->SetTitleFont(42, "XYZ");
       r2->SetTitleSize(0.14, "XYZ"); 
       r2->SetTitleOffset(0.4,"XYZ");
       r2->GetXaxis()->SetTitleColor(1);
       r2->GetXaxis()->SetNdivisions(509);
       r2->GetYaxis()->SetTitle("Txx / T21");
       r2->GetYaxis()->SetTitleColor(1);
       r2->GetYaxis()->SetNdivisions(509);
       r2->SetNdivisions(509,"XYZ");
       r2->SetMinimum(0.); 
       r2->SetMaximum(2.);  

       r3= new TH1F("r3","",nbin,xmin,xmax);
       r3->Divide(h3,h1,1,1);
       r3->Draw("Esame"); 
       r3->SetLineColor(color3);
       r3->SetLineStyle(1);
       r3->SetLineWidth(1);
       r3->SetMarkerColor(color3);
       r3->SetMarkerStyle(mark3);
       r3->SetMarkerSize(0.4);

//        r4= new TH1F("r4","",nbin,xmin,xmax);
//        r4->Divide(h4,h1,1,1);
//        r4->Draw("Esame"); 
//        r4->SetLineColor(color4);
//        r4->SetLineStyle(1);
//        r4->SetLineWidth(1);
//        r4->SetMarkerColor(color4);
//        r4->SetMarkerStyle(mark4);
//        r4->SetMarkerSize(0.4);
  
// *****************************************************************************

  pad3->cd();

       f1->cd();
       g1 = (TH1F*)gROOT->FindObject(htitle);
       g1->Sumw2();
       h1 = new TH1F("h1","",nbin,xmin,xmax);
       h1->Add(g1,h1,1/g1->Integral(0,nbin+1),0);
//        h1->Draw("EHF"); 
       h1->Draw("E"); 
       h1->SetLineColor(color1);
//        h1->SetFillColor(color1);
//        h1->SetFillStyle(3345);
       h1->SetLineStyle(1);
       h1->SetLineWidth(3);
       h1->SetMarkerColor(color1);
       h1->SetMarkerStyle(mark1);
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
       h1->GetYaxis()->SetTitle("a.u");
       h1->GetYaxis()->SetTitleColor(1);
       h1->GetYaxis()->SetNdivisions(509);
       h1->SetNdivisions(509,"XYZ");
       h1->SetMinimum(ymin); 
       h1->SetMaximum(ymax); 

       f2->cd();
       g2 = (TH1F*)gROOT->FindObject(htitle2);
       g2->Sumw2();
       h2 = new TH1F("h2","",nbin,xmin,xmax);
       h2->Add(g2,h2,1/g2->Integral(0,nbin+1),0);
//        h2->Draw("EHFsame"); 
       h2->Draw("Esame"); 
       h2->SetLineColor(color2);
//        h2->SetFillColor(color2);
//        h2->SetFillStyle(3354);
       h2->SetLineStyle(1);
       h2->SetLineWidth(3);
       h2->SetMarkerColor(color2);
       h2->SetMarkerStyle(mark2);
       h2->SetMarkerSize(0.7);

       f3->cd();
       g3 = (TH1F*)gROOT->FindObject(htitle+"_30eta40");
       g3->Sumw2();
       h3 = new TH1F("h3","",nbin,xmin,xmax);
       h3->Add(g3,h3,1/g3->Integral(0,nbin+1),0);
       h3->Draw("Esame"); 
       h3->SetLineColor(color3);
       h3->SetLineStyle(1);
       h3->SetLineWidth(3);
       h3->SetMarkerColor(color3);
       h3->SetMarkerStyle(mark3);
       h3->SetMarkerSize(0.7);

//        f4->cd();
//        g4 = (TH1F*)gROOT->FindObject(htitle+"_30eta40");
//        g4->Sumw2();
//        h4 = new TH1F("h4","",nbin,xmin,xmax);
//        h4->Add(g4,h4,1/g4->Integral(0,nbin+1),0);
//        h4->Draw("Esame"); 
//        h4->SetLineColor(color4);
//        h4->SetLineStyle(1);
//        h4->SetLineWidth(3);
//        h4->SetMarkerColor(color4);
//        h4->SetMarkerStyle(mark4);
//        h4->SetMarkerSize(0.7);
  
  leg = new TLegend(0.16,0.90,0.60,0.95);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("Phase-2 t#bar{t} Sim., PU200");
  leg->Draw();
  
  leg = new TLegend(0.16,0.83,0.72,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("jet p_{T} > 15 GeV, 3.0 < |#eta| < 4.0");
  leg->Draw();
  
  leg = new TLegend(0.72,0.55,0.94,0.80);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  leg->SetHeader("c jets");
  leg->AddEntry(h1," D76 (T21)","P");
  leg->AddEntry(h2," D80 (T25)","P");
  leg->AddEntry(h3," D81 (T26)","P");
//   leg->AddEntry(h1," 111X T15","P");
//   leg->AddEntry(h2," 113X T21","P");
//   leg->AddEntry(h3," 113X T25","P");
//   leg->AddEntry(h4," 113X T26","P");
  leg->Draw();
  
// *************************
 rap3->cd();

       r2= new TH1F("r2","",nbin,xmin,xmax);
       r2->Divide(h2,h1,1,1);
       r2->Draw("E"); 
       r2->SetLineColor(color2);
       r2->SetLineStyle(1);
       r2->SetLineWidth(1);
       r2->SetMarkerColor(color2);
       r2->SetMarkerStyle(mark2);
       r2->SetMarkerSize(0.4);
       r2->SetTickLength(0.03, "XYZ");
       r2->SetLabelOffset(0.03,"XYZ");
       r2->SetLabelSize(0.14, "Y");
       r2->SetLabelSize(0.  , "XZ");
       r2->SetLabelFont(42, "XYZ"); 
       r2->SetTitleFont(42, "XYZ");
       r2->SetTitleSize(0.14, "XYZ"); 
       r2->SetTitleOffset(0.4,"XYZ");
       r2->GetXaxis()->SetTitleColor(1);
       r2->GetXaxis()->SetNdivisions(509);
       r2->GetYaxis()->SetTitle("Txx / T21");
       r2->GetYaxis()->SetTitleColor(1);
       r2->GetYaxis()->SetNdivisions(509);
       r2->SetNdivisions(509,"XYZ");
       r2->SetMinimum(0.); 
       r2->SetMaximum(2.);  

       r3= new TH1F("r3","",nbin,xmin,xmax);
       r3->Divide(h3,h1,1,1);
       r3->Draw("Esame"); 
       r3->SetLineColor(color3);
       r3->SetLineStyle(1);
       r3->SetLineWidth(1);
       r3->SetMarkerColor(color3);
       r3->SetMarkerStyle(mark3);
       r3->SetMarkerSize(0.4);

//        r4= new TH1F("r4","",nbin,xmin,xmax);
//        r4->Divide(h4,h1,1,1);
//        r4->Draw("Esame"); 
//        r4->SetLineColor(color4);
//        r4->SetLineStyle(1);
//        r4->SetLineWidth(1);
//        r4->SetMarkerColor(color4);
//        r4->SetMarkerStyle(mark4);
//        r4->SetMarkerSize(0.4);
  
// *****************************************************************************
*/
  c1->Update();
}
