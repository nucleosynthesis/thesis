{
//=========Macro generated from canvas: c/
//=========  (Mon Jan 14 15:04:39 2013) by ROOT version5.33/03
   TCanvas *c = new TCanvas("c", "",415,107,800,600);
   c->Range(-5.000001,-0.075,127,0.675);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetGridx();
   c->SetGridy();
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(13);
   graph->SetName("resgr");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(22);
   graph->SetMarkerColor(1);
   graph->SetMarkerSize(1.35);
   graph->SetPoint(0,17,0.5452139936);
   graph->SetPoint(1,22.5,0.4464503257);
   graph->SetPoint(2,27.5,0.3780000554);
   graph->SetPoint(3,32.5,0.3299833061);
   graph->SetPoint(4,37.5,0.2900448305);
   graph->SetPoint(5,42.5,0.2724169767);
   graph->SetPoint(6,47.5,0.2497903821);
   graph->SetPoint(7,55,0.2293877054);
   graph->SetPoint(8,65,0.2061897277);
   graph->SetPoint(9,75,0.2020197628);
   graph->SetPoint(10,85,0.1884238164);
   graph->SetPoint(11,95,0.1726717273);
   graph->SetPoint(12,105,0.1632105666);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,8.2,113.8);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(0.6);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("E_{T}^{L1}");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#sigma_{E_{T}}/E_{T}");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("alp");
   
   
   graph = new TGraph(13);
   graph->SetName("resgrC");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(21);
   graph->SetPoint(0,17,0.2948154824);
   graph->SetPoint(1,22.5,0.2364727651);
   graph->SetPoint(2,27.5,0.2023519726);
   graph->SetPoint(3,32.5,0.1748041961);
   graph->SetPoint(4,37.5,0.1539028154);
   graph->SetPoint(5,42.5,0.1418624004);
   graph->SetPoint(6,47.5,0.1284889103);
   graph->SetPoint(7,55,0.1140754437);
   graph->SetPoint(8,65,0.09830214547);
   graph->SetPoint(9,75,0.08638947435);
   graph->SetPoint(10,85,0.07697198127);
   graph->SetPoint(11,95,0.06951905253);
   graph->SetPoint(12,105,0.06337991215);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,8.2,113.8);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(0.317959);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetTitle("L1 Jet E_{T}");
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("#sigma_{E^{L1}_{T}}/E^{L1}_{T}");
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("p");
   
   graph = new TGraph(13);
   graph->SetName("resgrC");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(21);
   graph->SetPoint(0,17,0.2948154824);
   graph->SetPoint(1,22.5,0.2364727651);
   graph->SetPoint(2,27.5,0.2023519726);
   graph->SetPoint(3,32.5,0.1748041961);
   graph->SetPoint(4,37.5,0.1539028154);
   graph->SetPoint(5,42.5,0.1418624004);
   graph->SetPoint(6,47.5,0.1284889103);
   graph->SetPoint(7,55,0.1140754437);
   graph->SetPoint(8,65,0.09830214547);
   graph->SetPoint(9,75,0.08638947435);
   graph->SetPoint(10,85,0.07697198127);
   graph->SetPoint(11,95,0.06951905253);
   graph->SetPoint(12,105,0.06337991215);
   
   TH1F *Graph_Graph_Graph23 = new TH1F("Graph_Graph_Graph23","",100,8.2,113.8);
   Graph_Graph_Graph23->SetMinimum(0);
   Graph_Graph_Graph23->SetMaximum(0.317959);
   Graph_Graph_Graph23->SetDirectory(0);
   Graph_Graph_Graph23->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph23->SetLineColor(ci);
   Graph_Graph_Graph23->GetXaxis()->SetTitle("L1 Jet E_{T}");
   Graph_Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph23->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph23->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph23->GetYaxis()->SetTitle("#sigma_{E^{L1}_{T}}/E^{L1}_{T}");
   Graph_Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph23->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph23->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph23->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph23->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph23);
   
   graph->Draw("pl");
   TLegend *leg = new TLegend(0.5,0.6,0.89,0.89,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(10);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("resgr","Uncorrected","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.25);
   TLegendEntry *entry2=leg->AddEntry("resgrC","Corrected","P");
   entry2->SetLineColor(1);
   entry2->SetLineStyle(1);
   entry2->SetLineWidth(1);
   entry2->SetMarkerColor(2);
   entry2->SetMarkerStyle(21);
   entry2->SetMarkerSize(1);
   leg->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
