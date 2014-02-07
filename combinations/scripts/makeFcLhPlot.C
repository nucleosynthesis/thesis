{
	gROOT->SetBatch(1);
	//file0 = LH, 1 = FC
	TH2F *hlh = (TH2F*)_file0->Get("hall");
	TH2F *hfc = (TH2F*)_file1->Get("h2_cl");

	double cl = 0.75;
	// Likelihood Contour
	//hlh->Smooth();
	//hlh->Smooth();
	hlh->GetYaxis()->SetRangeUser(0,8);
	hlh->GetXaxis()->SetRangeUser(0,3.5);
	hlh->SetLineColor(1);
	TH2F *hlh95 = (TH2F*)hlh->Clone();
	hlh->SetContour(2);
	hlh->SetContourLevel(1,1-cl);
	hlh95->SetContour(2);
	hlh95->SetContourLevel(1,1-.50);
	hlh95->SetLineStyle(1);

	// FC Contour
	hfc->Smooth();
	//hfc->Smooth();
	hfc->SetContour(2);
	hfc->SetLineColor(1);
	hfc->SetLineStyle(2);
	hfc->SetLineWidth(2);
	TH2F *hfc95 = (TH2F*)hfc->Clone();
	hfc->SetContourLevel(1,cl);

	hfc95->SetContour(2);
	hfc95->SetContourLevel(1,.50);
	hfc95->SetLineStyle(2);
	
	TH1F *hist = new TH1F("h","",35,0,3.5);
	hist->SetMaximum(8);

	TCanvas *can = new TCanvas("c","c",600,600);

	hist->GetXaxis()->SetTitleSize(0.045);
	hist->GetYaxis()->SetTitleSize(0.045);
	hist->SetTitle("");
	hist->GetXaxis()->SetTitle("#mu_{ggH+ttH}");
	hist->GetYaxis()->SetTitle("#mu_{VH+qqH}");

	hist->Draw("AXIS");
	hfc->Draw("CONT3same");
	hlh->Draw("CONT3same");
	hfc95->Draw("CONT3same");
	hlh95->Draw("CONT3same");

	gStyle->SetOptStat(0);
	TLegend *leg = new TLegend(0.48,0.7,0.89,0.89);
	leg->SetFillColor(10);
	leg->SetTextFont(42);
	leg->SetTextSize(0.035);
	//leg->AddEntry(hfc95,"Feldman-Cousins 50% CL","L");
	//leg->AddEntry(hlh95,"Likelihood Scan 50% CL","L");
	leg->AddEntry(hfc,"Feldman-Cousins","L");
	leg->AddEntry(hlh,"Likelihood Scan","L");
	leg->Draw();

 TLatex *lat = new TLatex();
 lat->SetNDC();
 lat->SetTextSize(0.045);
 lat->SetTextFont(42);
 lat->DrawLatex(0.1,0.92,"H#rightarrow #gamma#gamma");
 lat->DrawLatex(0.66,0.92,"m_{H}=125 GeV");
 leg->Draw();
	
	can->SaveAs("compare-fc-lh.pdf");

}
