{
//=========Macro generated from canvas: csig/
//=========  (Wed Oct 30 14:52:01 2013) by ROOT version5.34/03
   TCanvas *csig = new TCanvas("csig", "",0,0,600,600);
   gStyle->SetOptStat(0);
   csig->Range(0.2499999,3.375,10.75,4.625);
   csig->SetFillColor(0);
   csig->SetBorderMode(0);
   csig->SetBorderSize(2);
   csig->SetFrameBorderMode(0);
   csig->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(8);
   graph->SetName("Optimization");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,2,3.760584385);
   graph->SetPoint(1,3,3.935356327);
   graph->SetPoint(2,4,4.010742014);
   graph->SetPoint(3,5,4.047965895);
   graph->SetPoint(4,6,4.068854836);
   graph->SetPoint(5,7,4.082156519);
   graph->SetPoint(6,8,4.089884269);
   graph->SetPoint(7,9,4.09647585);
   
   TH1F *Graph_Optimization2 = new TH1F("Graph_Optimization2","",100,1.3,9.7);
   Graph_Optimization2->SetMinimum(3.5);
   Graph_Optimization2->SetMaximum(4.5);
   Graph_Optimization2->SetDirectory(0);
   Graph_Optimization2->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Optimization2->SetLineColor(ci);
   Graph_Optimization2->GetXaxis()->SetTitle("Number of Bins");
   Graph_Optimization2->GetXaxis()->SetLabelFont(42);
   Graph_Optimization2->GetXaxis()->SetLabelSize(0.035);
   Graph_Optimization2->GetXaxis()->SetTitleSize(0.035);
   Graph_Optimization2->GetXaxis()->SetTitleFont(42);
   Graph_Optimization2->GetYaxis()->SetTitle("#sigma_{exp}");
   Graph_Optimization2->GetYaxis()->SetLabelFont(42);
   Graph_Optimization2->GetYaxis()->SetLabelSize(0.035);
   Graph_Optimization2->GetYaxis()->SetTitleSize(0.035);
   Graph_Optimization2->GetYaxis()->SetTitleFont(42);
   Graph_Optimization2->GetZaxis()->SetLabelFont(42);
   Graph_Optimization2->GetZaxis()->SetLabelSize(0.035);
   Graph_Optimization2->GetZaxis()->SetTitleSize(0.035);
   Graph_Optimization2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Optimization2);
   
   graph->Draw("alp");
   csig->Modified();
   csig->cd();
   csig->SetSelected(csig);
}
