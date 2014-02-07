{
//=========Macro generated from canvas: c/c
//=========  (Thu Jan 17 01:31:50 2013) by ROOT version5.33/03
   TCanvas *c = new TCanvas("c", "c",500,113,600,600);
   c->Range(-0.1258384,-0.3,1.132545,2.7);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);

   TGraph *graph = (TGraph*)_file0->Get("confcurve");
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineWidth(2);
//   graph->SetLineColor(4);
   graph->SetMarkerStyle(20);
/*   
   TGraph *graph = new TGraph(30);
   graph->SetPoint(0,0.9164383562,0);
   graph->SetPoint(1,0.8849315068,0.103448);
   graph->SetPoint(2,0.7397260274,0.206897);
   graph->SetPoint(3,0.5945205479,0.310345);
   graph->SetPoint(4,0.4561643836,0.413793);
   graph->SetPoint(5,0.3821917808,0.517241);
   graph->SetPoint(6,0.2547945205,0.62069);
   graph->SetPoint(7,0.1328767123,0.724138);
   graph->SetPoint(8,0.02739726027,0.827586);
   graph->SetPoint(9,0.09315068493,0.931034);
   graph->SetPoint(10,0.2164383562,1.03448);
   graph->SetPoint(11,0.3383561644,1.13793);
   graph->SetPoint(12,0.4369863014,1.24138);
   graph->SetPoint(13,0.5150684932,1.34483);
   graph->SetPoint(14,0.6068493151,1.44828);
   graph->SetPoint(15,0.7136986301,1.55172);
   graph->SetPoint(16,0.7767123288,1.65517);
   graph->SetPoint(17,0.797260274,1.75862);
   graph->SetPoint(18,0.8561643836,1.86207);
   graph->SetPoint(19,0.8589041096,1.96552);
   graph->SetPoint(20,0.9150684932,2.06897);
   graph->SetPoint(21,0.9424657534,2.17241);
   graph->SetPoint(22,0.9383561644,2.27586);
   graph->SetPoint(23,0.9602739726,2.37931);
   graph->SetPoint(24,0.9890410959,2.48276);
   graph->SetPoint(25,0.9904109589,2.58621);
   graph->SetPoint(26,0.9863013699,2.68966);
   graph->SetPoint(27,0.9917808219,2.7931);
   graph->SetPoint(28,0.9931506849,2.89655);
   graph->SetPoint(29,0.997260274,3);
*/
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,1.094247);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(2.4);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("1-CL_{s+b}");
   Graph_Graph1->GetXaxis()->SetRange(1,92);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#mu");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0.7);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);

   graph->Draw("alp");
   TLine *line = new TLine(0.68,0,0.68,2.4);
   line->SetLineColor(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.1,0.92,"H#rightarrow#tau#tau (0/1 jet)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
//      tex = new TLatex(0.7,0.92,"m_{H}=125.8 GeV");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.62,0.92,"m_{H}=125.8 GeV");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   line = new TLine(0,0.249447,1,0.249447);
   line->SetLineColor(2);
   line->SetLineWidth(2);
   line->Draw();
   line = new TLine(0,1.519097,1,1.519097);
   line->SetLineColor(2);
   line->SetLineWidth(2);
   line->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
