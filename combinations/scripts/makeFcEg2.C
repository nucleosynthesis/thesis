{

TH1F *ht2 = _file0->Get("hToys_x=2.28_y=1.00");
TH1F *hd2 = _file0->Get("hData_x=2.28_y=1.00");
TCanvas *can = new TCanvas("c","c",600,600);
ht2->Draw();
can->SetLogy();
 //ht2->Rebin(2);
 ht2->SetFillColor(kWhite);
 ht2->SetLineColor(1);
 //ht2->SetLineWidth(2);
 ht2->Scale(1./ht2->Integral());
 ht2->GetYaxis()->SetRangeUser(10E-5,1);
 ht2->SetTitle("");
 hd2->SetLineColor(1);
 hd2->SetLineWidth(2);
 ht2->GetYaxis()->SetTitle("Probability");
 ht2->GetYaxis()->SetTitleSize(0.045);
 ht2->GetXaxis()->SetTitleSize(0.045);
 ht2->GetXaxis()->SetTitle("q_{#mu}");
 int nbins = ht2->GetNbinsX();
 int bin68=1;
 int bin95=1;
 for (int bin=1;bin<=nbins;bin++){
	if (ht2->Integral(1,bin) < .95 )bin95=bin;
	if (ht2->Integral(1,bin) < .68 )bin68=bin;
 }
 TH1F *h68 = (TH1F*)ht2->Clone();
 TH1F *h95 = (TH1F*)ht2->Clone();
 for (int bin = 1;bin<nbins;bin++){
	if (bin>bin68)	h68->SetBinContent(bin,0);
	if (bin>bin95)	h95->SetBinContent(bin,0);	
 }

 TLegend *leg = new TLegend(0.6,0.7,0.89,0.89);
 leg->SetFillColor(10);
 leg->SetTextFont(42);
 leg->SetTextSize(0.05);
 h68->SetFillColor(kGreen+1);
 h95->SetFillColor(kYellow);
 leg->AddEntry(h68,"68% Toys","F");
 leg->AddEntry(h95,"95% Toys","F");
 leg->AddEntry(hd2,"Data","L");
 

 ht2->Draw("");
 h95->Draw("same");
 h68->Draw("same");
 hd2->Draw("samehist");
 ht2->GetXaxis()->SetRangeUser(0,8);
gPad->RedrawAxis();

 TLatex *lat = new TLatex();
 lat->SetNDC();
 lat->SetTextSize(0.045);
 lat->SetTextFont(42);
 lat->DrawLatex(0.1,0.92,"H#rightarrow #tau#tau (0/1 jet)");
 lat->DrawLatex(0.58,0.92,"m_{H}=125.8, #mu=2.28");
 leg->Draw();


}
