{
 gROOT->Reset() ; 

 // Compile user's analysis class //
   gROOT->ProcessLine(".L HistogramManager.C+g") ;
   gROOT->ProcessLine(".L LLTopAna.C+g") ;
  
 if (gROOT->GetClass("LLTopTree")==0) return;
 
 TChain c("trackingPerf/ttree");

////////////////////////////////////////////////////////////////////////////////

c.Add("./CMSSW_10_6_20/MC/2018/UDD_bgctau10_smu250_snu200.root");
// c.Add("./CMSSW_10_6_20/MC/2018/UDD_bgctau30_smu300_snu250.root");
// c.Add("./CMSSW_10_6_20/MC/2018/UDD_bgctau50_smu275_snu225.root");
// c.Add("./CMSSW_10_6_20/MC/2018/UDD_bgctau70_smu250_snu200.root");//done

////////////////////////////////////////////////////////////////////////////////

 LLTopTree* t = new LLTopTree(&c);

t->Loop(0,180.,20.,2999.,0.0,2.4,0.,1,"output/h_UDD_bgctau10_smu250_snu200.root");
// t->Loop(0,180.,20.,2999.,0.0,2.4,0.,1,"output/h_UDD_bgctau30_smu300_snu250.root");
// t->Loop(0,180.,20.,2999.,0.0,2.4,0.,1,"output/h_UDD_bgctau50_smu275_snu225.root");
// t->Loop(0,180.,20.,2999.,0.0,2.4,0.,1,"output/h_UDD_bgctau70_smu250_snu200.root");// 0 arb, 180 coupur en HT,20 coupurs jets, 2999 energie max jets, 0. et 2.4 et eta max et min, 0 et 1 param�tres libres

////////////////////////////////////////////////////////////////////////////////

}
