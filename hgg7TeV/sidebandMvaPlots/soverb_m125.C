{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Mar 27 20:47:17 2013) by ROOT version5.32/00
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(-1,-0.08532647,9,0.7679382);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *gghClonenew = new TH1F("gghClonenew","",8,0,8);
   gghClonenew->SetBinContent(1,0.01932436);
   gghClonenew->SetBinContent(2,0.03459434);
   gghClonenew->SetBinContent(3,0.04703593);
   gghClonenew->SetBinContent(4,0.06805188);
   gghClonenew->SetBinContent(5,0.09676992);
   gghClonenew->SetBinContent(6,0.1282782);
   gghClonenew->SetBinContent(7,0.1850881);
   gghClonenew->SetBinContent(8,0.381279);
   gghClonenew->SetBinError(1,0.004902993);
   gghClonenew->SetBinError(2,0.01012325);
   gghClonenew->SetBinError(3,0.01842335);
   gghClonenew->SetBinError(4,0.02423354);
   gghClonenew->SetBinError(5,0.03599073);
   gghClonenew->SetBinError(6,0.0597341);
   gghClonenew->SetBinError(7,0.09207094);
   gghClonenew->SetBinError(8,0.2688274);
   gghClonenew->SetEntries(10.64377);
   gghClonenew->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ff0000");
   gghClonenew->SetLineColor(ci);
   gghClonenew->SetLineWidth(2);
   gghClonenew->SetMarkerStyle(20);
   gghClonenew->GetXaxis()->SetBinLabel(1,"BDT Bin 1 ");
   gghClonenew->GetXaxis()->SetBinLabel(2,"BDT Bin 2 ");
   gghClonenew->GetXaxis()->SetBinLabel(3,"BDT Bin 3 ");
   gghClonenew->GetXaxis()->SetBinLabel(4,"BDT Bin 4 ");
   gghClonenew->GetXaxis()->SetBinLabel(5,"BDT Bin 5 ");
   gghClonenew->GetXaxis()->SetBinLabel(6,"BDT Bin 6 ");
   gghClonenew->GetXaxis()->SetBinLabel(7,"BDT Bin 7 ");
   gghClonenew->GetXaxis()->SetBinLabel(8," Dijet ");
   gghClonenew->GetXaxis()->SetNdivisions(8);
   gghClonenew->GetXaxis()->SetLabelFont(42);
   gghClonenew->GetXaxis()->SetLabelSize(0.055);
   gghClonenew->GetXaxis()->SetTitleFont(42);
   gghClonenew->GetYaxis()->SetTitle("Signal / Background");
   gghClonenew->GetYaxis()->SetLabelFont(42);
   gghClonenew->GetYaxis()->SetLabelSize(0.05);
   gghClonenew->GetYaxis()->SetTitleSize(0.05);
   gghClonenew->GetYaxis()->SetTitleFont(42);
   
   gghClonenew->SetLineColor(2);
   gghClonenew->SetMarkerColor(2);
   gghClonenew->SetMaximum(0.7);
   gghClonenew->Draw("P");
   TLatex *   tex = new TLatex(0.15,0.82,"H#rightarrow#gamma#gamma");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.75,"#sqrt{s} = 7 TeV L = 5.1 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
