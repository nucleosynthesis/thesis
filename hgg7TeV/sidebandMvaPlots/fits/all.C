{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Dec 10 17:56:44 2012) by ROOT version5.33/03
   TCanvas *c1 = new TCanvas("c1", "c1",67,46,700,500);
   gStyle->SetOptStat(0);
   c1->Range(107.5,-12.5,157.5,112.5);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *Axis = new TH1F("Axis","Statistical and systematic error",800,112.5,152.5);
   Axis->SetMinimum(5);
   Axis->SetMaximum(30);
   Axis->SetStats(0);
   Axis->GetXaxis()->SetTitle("m_{H} (GeV)");
   Axis->GetYaxis()->SetTitle("Normalisation error (events)");
   Axis->Draw("");
   
   TH1F *SigRegionError = new TH1F("SigRegionError","Signal region",8,112.5,152.5);
   SigRegionError->SetBinContent(1,48.43552);
   SigRegionError->SetBinContent(2,45.55217);
   SigRegionError->SetBinContent(3,42.23742);
   SigRegionError->SetBinContent(4,40.42277);
   SigRegionError->SetBinContent(5,36.19392);
   SigRegionError->SetBinContent(6,35.4542);
   SigRegionError->SetBinContent(7,32.48076);
   SigRegionError->SetBinContent(8,30.54505);
   SigRegionError->SetBinContent(9,29.35984);
   SigRegionError->SetEntries(8);
   SigRegionError->GetXaxis()->SetTitle("m_{H} (GeV)");
   SigRegionError->GetYaxis()->SetTitle("Statistical error on signal region");
   //SigRegionError->Draw("same");
   
   TGraphErrors *gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,109.45,30.564);
   gre->SetPointError(0,0,0.3097998);
   gre->SetPoint(1,114.45,48.32883);
   gre->SetPointError(1,0,0.2859935);
   gre->SetPoint(2,119.45,74.93054);
   gre->SetPointError(2,0,0.235928);
   gre->SetPoint(3,124.45,84.86395);
   gre->SetPointError(3,0,0.1814336);
   gre->SetPoint(4,129.45,83.51373);
   gre->SetPointError(4,0,0.1547867);
   gre->SetPoint(5,134.45,73.89684);
   gre->SetPointError(5,0,0.1577219);
   gre->SetPoint(6,139.45,58.74783);
   gre->SetPointError(6,0,0.167813);
   gre->SetPoint(7,144.45,40.25453);
   gre->SetPointError(7,0,0.1666267);
   gre->SetPoint(8,149.45,20.54428);
   gre->SetPointError(8,0,0.1524382);
   gre->SetPoint(9,150,92);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,105.395,154.055);
   Graph_Graph1->SetMinimum(13.23103);
   Graph_Graph1->SetMaximum(99.16082);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   gre->SetHistogram(Graph_Graph1);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,109.55,28.01306);
   gre->SetPointError(0,0,0.3434002);
   gre->SetPoint(1,114.55,26.60773);
   gre->SetPointError(1,0,0.3260831);
   gre->SetPoint(2,119.55,22.06094);
   gre->SetPointError(2,0,0.2723593);
   gre->SetPoint(3,124.55,18.88605);
   gre->SetPointError(3,0,0.2338386);
   gre->SetPoint(4,129.55,17.66333);
   gre->SetPointError(4,0,0.2166505);
   gre->SetPoint(5,134.55,17.86633);
   gre->SetPointError(5,0,0.2179603);
   gre->SetPoint(6,139.55,17.69082);
   gre->SetPointError(6,0,0.2165472);
   gre->SetPoint(7,144.55,17.05038);
   gre->SetPointError(7,0,0.2098745);
   gre->SetPoint(8,149.55,15.20479);
   gre->SetPointError(8,0,0.1882677);
   gre->SetPoint(9,150,84);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,105.505,154.045);
   Graph_Graph2->SetMinimum(8.118176);
   Graph_Graph2->SetMaximum(90.89835);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
   gre->SetHistogram(Graph_Graph2);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,109.65,28.17956);
   gre->SetPointError(0,0,0.3407673);
   gre->SetPoint(1,114.65,26.79528);
   gre->SetPointError(1,0,0.3259065);
   gre->SetPoint(2,119.65,22.09607);
   gre->SetPointError(2,0,0.2728556);
   gre->SetPoint(3,124.65,18.86519);
   gre->SetPointError(3,0,0.2331561);
   gre->SetPoint(4,129.65,17.6747);
   gre->SetPointError(4,0,0.2142346);
   gre->SetPoint(5,134.65,17.80097);
   gre->SetPointError(5,0,0.2144098);
   gre->SetPoint(6,139.65,17.56875);
   gre->SetPointError(6,0,0.2136218);
   gre->SetPoint(7,144.65,16.90298);
   gre->SetPointError(7,0,0.207964);
   gre->SetPoint(8,149.65,15.15516);
   gre->SetPointError(8,0,0.1876037);
   gre->SetPoint(9,150,76);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,105.615,154.035);
   Graph_Graph3->SetMinimum(8.86431);
   Graph_Graph3->SetMaximum(82.10324);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   gre->SetHistogram(Graph_Graph3);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,109.75,25.7904);
   gre->SetPointError(0,0,0.3080385);
   gre->SetPoint(1,114.75,25.50221);
   gre->SetPointError(1,0,0.2786465);
   gre->SetPoint(2,119.75,21.63957);
   gre->SetPointError(2,0,0.2283753);
   gre->SetPoint(3,124.75,16.48027);
   gre->SetPointError(3,0,0.1749039);
   gre->SetPoint(4,129.75,13.03089);
   gre->SetPointError(4,0,0.1495711);
   gre->SetPoint(5,134.75,12.6083);
   gre->SetPointError(5,0,0.1541519);
   gre->SetPoint(6,139.75,13.31841);
   gre->SetPointError(6,0,0.1649129);
   gre->SetPoint(7,144.75,13.26209);
   gre->SetPointError(7,0,0.1636058);
   gre->SetPoint(8,149.75,12.08184);
   gre->SetPointError(8,0,0.1486953);
   gre->SetPoint(9,150,92);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,105.725,154.025);
   Graph_Graph4->SetMinimum(3.926456);
   Graph_Graph4->SetMaximum(100.0067);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);
   gre->SetHistogram(Graph_Graph4);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,109.85,25.15964);
   gre->SetPointError(0,0,0.3054318);
   gre->SetPoint(1,114.85,22.75919);
   gre->SetPointError(1,0,0.2791801);
   gre->SetPoint(2,119.85,18.92084);
   gre->SetPointError(2,0,0.2342814);
   gre->SetPoint(3,124.85,16.65081);
   gre->SetPointError(3,0,0.2030871);
   gre->SetPoint(4,129.85,16.16515);
   gre->SetPointError(4,0,0.1889553);
   gre->SetPoint(5,134.85,16.41952);
   gre->SetPointError(5,0,0.189459);
   gre->SetPoint(6,139.85,16.02853);
   gre->SetPointError(6,0,0.1872795);
   gre->SetPoint(7,144.85,14.50166);
   gre->SetPointError(7,0,0.1730377);
   gre->SetPoint(8,149.85,12.1719);
   gre->SetPointError(8,0,0.1494403);
   gre->SetPoint(9,150,84);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,105.835,154.015);
   Graph_Graph5->SetMinimum(4.824702);
   Graph_Graph5->SetMaximum(91.19775);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);
   gre->SetHistogram(Graph_Graph5);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,109.95,25.02023);
   gre->SetPointError(0,0,0.3096543);
   gre->SetPoint(1,114.95,23.843);
   gre->SetPointError(1,0,0.2950275);
   gre->SetPoint(2,119.95,20.91236);
   gre->SetPointError(2,0,0.2583634);
   gre->SetPoint(3,124.95,18.85073);
   gre->SetPointError(3,0,0.232643);
   gre->SetPoint(4,129.95,16.88896);
   gre->SetPointError(4,0,0.2074992);
   gre->SetPoint(5,134.95,15.55256);
   gre->SetPointError(5,0,0.1916796);
   gre->SetPoint(6,139.95,14.52085);
   gre->SetPointError(6,0,0.1797558);
   gre->SetPoint(7,144.95,13.77152);
   gre->SetPointError(7,0,0.1701155);
   gre->SetPoint(8,149.95,12.98518);
   gre->SetPointError(8,0,0.1571067);
   gre->SetPoint(9,150,76);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,105.945,154.005);
   Graph_Graph6->SetMinimum(6.51088);
   Graph_Graph6->SetMaximum(82.31719);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);
   gre->SetHistogram(Graph_Graph6);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetPoint(0,110.05,26.09246);
   gre->SetPointError(0,0,0.3092546);
   gre->SetPoint(1,115.05,27.19167);
   gre->SetPointError(1,0,0.2779173);
   gre->SetPoint(2,120.05,24.1186);
   gre->SetPointError(2,0,0.2276383);
   gre->SetPoint(3,125.05,19.0806);
   gre->SetPointError(3,0,0.1749115);
   gre->SetPoint(4,130.05,14.97373);
   gre->SetPointError(4,0,0.1505611);
   gre->SetPoint(5,135.05,13.56941);
   gre->SetPointError(5,0,0.155904);
   gre->SetPoint(6,140.05,13.64234);
   gre->SetPointError(6,0,0.1668281);
   gre->SetPoint(7,145.05,13.35945);
   gre->SetPointError(7,0,0.1654203);
   gre->SetPoint(8,150.05,12.17215);
   gre->SetPointError(8,0,0.1499168);
   gre->SetPoint(9,150,92);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","Graph",100,106.05,154.05);
   Graph_Graph7->SetMinimum(4.024455);
   Graph_Graph7->SetMaximum(99.99778);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);
   gre->SetHistogram(Graph_Graph7);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(22);
   gre->SetPoint(0,110.15,26.53928);
   gre->SetPointError(0,0,0.3176569);
   gre->SetPoint(1,115.15,24.37476);
   gre->SetPointError(1,0,0.2900387);
   gre->SetPoint(2,120.15,20.5925);
   gre->SetPointError(2,0,0.2501565);
   gre->SetPoint(3,125.15,18.20254);
   gre->SetPointError(3,0,0.2252786);
   gre->SetPoint(4,130.15,17.5755);
   gre->SetPointError(4,0,0.2146885);
   gre->SetPoint(5,135.15,17.90047);
   gre->SetPointError(5,0,0.2146314);
   gre->SetPoint(6,140.15,17.37911);
   gre->SetPointError(6,0,0.2073004);
   gre->SetPoint(7,145.15,15.5847);
   gre->SetPointError(7,0,0.1866614);
   gre->SetPoint(8,150.15,12.96267);
   gre->SetPointError(8,0,0.1582485);
   gre->SetPoint(9,150,84);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","Graph",100,106.15,154.15);
   Graph_Graph8->SetMinimum(5.684861);
   Graph_Graph8->SetMaximum(91.11956);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);
   gre->SetHistogram(Graph_Graph8);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(22);
   gre->SetPoint(0,110.25,25.19999);
   gre->SetPointError(0,0,0.3103062);
   gre->SetPoint(1,115.25,24.00197);
   gre->SetPointError(1,0,0.2960563);
   gre->SetPoint(2,120.25,20.79159);
   gre->SetPointError(2,0,0.2573352);
   gre->SetPoint(3,125.25,18.70765);
   gre->SetPointError(3,0,0.2314296);
   gre->SetPoint(4,130.25,17.43812);
   gre->SetPointError(4,0,0.2137157);
   gre->SetPoint(5,135.25,16.99783);
   gre->SetPointError(5,0,0.2073134);
   gre->SetPoint(6,140.25,16.20341);
   gre->SetPointError(6,0,0.1986047);
   gre->SetPoint(7,145.25,14.70978);
   gre->SetPointError(7,0,0.181432);
   gre->SetPoint(8,150.25,13.11881);
   gre->SetPointError(8,0,0.1623523);
   gre->SetPoint(9,150,76);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","Graph",100,106.25,154.25);
   Graph_Graph9->SetMinimum(6.6521);
   Graph_Graph9->SetMaximum(82.30435);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);
   gre->SetHistogram(Graph_Graph9);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(23);
   gre->SetPoint(0,110.35,467.7521);
   gre->SetPointError(0,0,0.1917338);
   gre->SetPoint(1,115.35,169.933);
   gre->SetPointError(1,0,0.2509527);
   gre->SetPoint(2,120.35,62.82778);
   gre->SetPointError(2,0,0.2294553);
   gre->SetPoint(3,125.35,227.0525);
   gre->SetPointError(3,0,0.1923259);
   gre->SetPoint(4,130.35,340.0529);
   gre->SetPointError(4,0,0.1714206);
   gre->SetPoint(5,135.35,406.6745);
   gre->SetPointError(5,0,0.1682742);
   gre->SetPoint(6,140.35,433.2981);
   gre->SetPointError(6,0,0.1675083);
   gre->SetPoint(7,145.35,425.4146);
   gre->SetPointError(7,0,0.1542305);
   gre->SetPoint(8,150.35,387.4412);
   gre->SetPointError(8,0,0.131856);
   gre->SetPoint(9,150,92);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","Graph",100,106.35,154.35);
   Graph_Graph10->SetMinimum(22.06378);
   Graph_Graph10->SetMaximum(508.4784);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);
   gre->SetHistogram(Graph_Graph10);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(23);
   gre->SetPoint(0,110.45,39.63232);
   gre->SetPointError(0,0,0.3238234);
   gre->SetPoint(1,115.45,50.48627);
   gre->SetPointError(1,0,0.3024998);
   gre->SetPoint(2,120.45,44.00135);
   gre->SetPointError(2,0,0.2742556);
   gre->SetPoint(3,125.45,28.72203);
   gre->SetPointError(3,0,0.2456203);
   gre->SetPoint(4,130.45,18.79061);
   gre->SetPointError(4,0,0.2324687);
   gre->SetPoint(5,135.45,24.56937);
   gre->SetPointError(5,0,0.2245285);
   gre->SetPoint(6,140.45,31.47932);
   gre->SetPointError(6,0,0.2176535);
   gre->SetPoint(7,145.45,31.4693);
   gre->SetPointError(7,0,0.2110771);
   gre->SetPoint(8,150.45,25.2198);
   gre->SetPointError(8,0,0.2003554);
   gre->SetPoint(9,150,84);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","Graph",100,106.45,154.45);
   Graph_Graph11->SetMinimum(12.01396);
   Graph_Graph11->SetMaximum(90.54419);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);
   gre->SetHistogram(Graph_Graph11);
   
   gre->Draw(" p");
   
   gre = new TGraphErrors(10);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(23);
   gre->SetPoint(0,110.55,27.90935);
   gre->SetPointError(0,0,0.3153866);
   gre->SetPoint(1,115.55,25.38346);
   gre->SetPointError(1,0,0.2944078);
   gre->SetPoint(2,120.55,22.59622);
   gre->SetPointError(2,0,0.2782915);
   gre->SetPoint(3,125.55,21.22073);
   gre->SetPointError(3,0,0.2579687);
   gre->SetPoint(4,130.55,20.08759);
   gre->SetPointError(4,0,0.2365243);
   gre->SetPoint(5,135.55,18.81729);
   gre->SetPointError(5,0,0.2212989);
   gre->SetPoint(6,140.55,18.06741);
   gre->SetPointError(6,0,0.2201426);
   gre->SetPoint(7,145.55,18.84637);
   gre->SetPointError(7,0,0.2330507);
   gre->SetPoint(8,150.55,18.58676);
   gre->SetPointError(8,0,0.2248205);
   gre->SetPoint(9,150,76);
   gre->SetPointError(9,0,0);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,106.55,154.55);
   Graph_Graph12->SetMinimum(12.032);
   Graph_Graph12->SetMaximum(81.81527);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);
   gre->SetHistogram(Graph_Graph12);
   
   gre->Draw(" p");
   
   TPaveText *pt = new TPaveText(0.01,0.9390678,0.4998276,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
//   text = pt->AddText("Statistical and systematic error");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->SetGrid();

   // make 12 dummy hists:
   TLegend* leg[3]; // 
   leg[0] = new TLegend(0.1,0.1,0.35,0.3);
   leg[1] = new TLegend(0.36,0.1,0.61,0.3);
   leg[2] = new TLegend(0.62,0.1,0.87,0.3);

   TH1F* dum[12];
   std::string cla[4] = {"Laurent","Exponential","Power-Law", "Polynomial"};
   int np[3] = {1,3,5};	
   int mc_np[3]={4,2,kGreen+1};
   int ms_cla[4]={22,20,21,23};
   for (int i=0;i<4;i++){ // class
     for (int j=0;j<3;j++){ // num params
		dum[3*i+j] = new TH1F(Form("%s%d",cla[i].c_str(),np[j]),"",10,0,1);
		//dum[3*i+j] = new TH1F("kweh","",10,0,1);
		dum[3*i+j]->SetMarkerColor(mc_np[j]);
		dum[3*i+j]->SetMarkerStyle(ms_cla[i]);
		dum[3*i+j]->SetMarkerSize(0.8);
		leg[j]->AddEntry(dum[3*i+j],Form("%s (%d pars)",cla[i].c_str(),np[j]),"P");
     }	
   }
	
   leg[0]->SetFillColor(10);
   leg[0]->SetTextFont(42);
   leg[0]->Draw();
   leg[1]->SetFillColor(10);
   leg[1]->SetTextFont(42);
   leg[1]->Draw();
   leg[2]->SetFillColor(10);
   leg[2]->SetTextFont(42);
   leg[2]->Draw();
}
