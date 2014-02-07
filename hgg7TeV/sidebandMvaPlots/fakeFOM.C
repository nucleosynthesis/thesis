{

	TGraph *g115 = new TGraph();
	TGraph *g130 = new TGraph();
	TGraph *g150 = new TGraph();
	
	// 115 Point 
	double pg115[7] = {0.56,0.62,0.57,0.5,0.44,0.39,0.33};
	double pg130[7] = {0.62,0.69,0.65,0.58,0.52,0.46,0.4};
	double pg150[7] = {0.39,0.44,0.4,0.36,0.32,0.28,0.24};
	
	for (int i=0;i<7;i++){
		g115->SetPoint(i,0.01+i*0.01,pg115[i]);
		g130->SetPoint(i,0.01+i*0.01,pg130[i]);
		g150->SetPoint(i,0.01+i*0.01,pg150[i]);
	}

	g115->SetMarkerStyle(21);	
	g115->SetMarkerSize(1.2);	
	g115->SetMarkerColor(1);	
	g115->SetLineColor(1);	
	g115->SetLineWidth(2);
	
	g130->SetMarkerStyle(21);	
	g130->SetMarkerSize(1.2);	
	g130->SetMarkerColor(kBlue);	
	g130->SetLineColor(1);	
	g130->SetLineWidth(2);	

	g150->SetMarkerStyle(21);	
	g150->SetMarkerSize(1.2);	
	g150->SetMarkerColor(kGreen+1);	
	g150->SetLineColor(1);	
	g150->SetLineWidth(2);	

	TCanvas *can = new TCanvas("c","c",800,600);
	can->SetGrid(1);
	g115->Draw("ALP");	
	g115->GetYaxis()->SetRangeUser(0,1);	
	g115->GetYaxis()->SetTitle("Figure of merit");	
	g115->GetYaxis()->SetTitleSize(0.045);	
	g115->GetYaxis()->SetTitleOffset(0.8);	
	g115->GetXaxis()->SetTitleSize(0.045);	
	g115->GetXaxis()->SetTitle("Signal region cut");	
	
	g130->Draw("LP");
	g150->Draw("LP");

	TLegend *leg = new TLegend(0.65,0.58,0.89,0.89);
	leg->SetFillColor(10);
	leg->SetTextFont(42);
	leg->SetTextSize(0.05);
	leg->AddEntry(g115,"m_{H}=115 GeV","P");
	leg->AddEntry(g130,"m_{H}=130 GeV","P");
	leg->AddEntry(g150,"m_{H}=150 GeV","P");
	leg->Draw();
}

