void norm2(unsigned nArg=0) {
  gROOT->SetStyle("Plain");
  TCanvas *c1(new TCanvas());
  //gStyle->SetOptStat(0);

  const std::string window("02");

  const unsigned nFcn(12);
  const unsigned maxFcn(13);

  std::string sNumber[maxFcn]={"00","01","02","03","04","05","06","07","08","09","10","11","12"};

  const unsigned usedFcn(4); // Pow2
  //const unsigned usedFcn(11); // Pol5

  int loFcn(0),hiFcn(nFcn);
  if(nArg==1) {
    loFcn=usedFcn;
    hiFcn=loFcn+1;
  }

  TFile *file[nFcn][nFcn];
  for(int i(loFcn);i<hiFcn;i++) {
    for(int k(0);k<nFcn;k++) {
      file[i][k]=TFile::Open((std::string("norm")+window+sNumber[k]+sNumber[i]+".root").c_str());
    }
  }
  TFile *file9999=TFile::Open((std::string("norm")+window+"9999.root").c_str());

  unsigned nColor[3]={4,2,3};
  unsigned nMarker[4]={20,21,22,23};

  double prob[nFcn];

  /*
  // 95-185
  prob[ 0]=5.61719e-16;
  prob[ 1]=0.0114708;
  prob[ 2]=0.00878861;
  prob[ 3]=0.0197673;
  prob[ 4]=0.0126985;
  prob[ 5]=0.00789481;
  prob[ 6]=0.01975;
  prob[ 7]=0.0126419;
  prob[ 8]=0.00778173;
  prob[ 9]=0.0;
  prob[10]=9.92458e-05;
  prob[11]=0.00338298;
  */

  /*
  // 100-180, PreReco
  prob[ 0]=5.1773e-06;
  prob[ 1]=0.0645791;
  prob[ 2]=0.0450679;
  prob[ 3]=0.0739873;
  prob[ 4]=0.057889;
  prob[ 5]=0.0395999;
  prob[ 6]=0.0756213;
  prob[ 7]=0.0604952;
  prob[ 8]=0.043789;
  prob[ 9]=1.34225e-258;
  prob[10]=0.0408407;
  prob[11]=0.041207;
  */

  /*
  // 100-180, ReReco
  prob[ 0]=2.02976e-06;
  prob[ 1]=0.0517279;
  prob[ 2]=0.035315;
  prob[ 3]=0.0683249;
  prob[ 4]=0.0508256;
  prob[ 5]=0.0345198;
  prob[ 6]=0.0694819;
  prob[ 7]=0.0504602;
  prob[ 8]=0.0353084;
  prob[ 9]=5.30968e-265;
  prob[10]=0.0179445;
  prob[11]=0.0364024;
  */

  /*
  // 100-180, UCSD
  prob[ 0]=3.72367e-26;
  prob[ 1]=0.0689864;
  prob[ 2]=0.0542086;
  prob[ 3]=0.0713879;
  prob[ 4]=0.0499451;
  prob[ 5]=0.0438637;
  prob[ 6]=0.0857392;
  prob[ 7]=0.0717464;
  prob[ 8]=0.051323;
  prob[ 9]=0;
  prob[10]=1.3644e-07;
  prob[11]=0.0451862;
  */
  /*
  // 100-180, MIT
  prob[ 0]=9.96679e-17;
  prob[ 1]=0.207856;
  prob[ 2]=0.173047;
  prob[ 3]=0.207118;
  prob[ 4]=0.158695;
  prob[ 5]=0.162687;
  prob[ 6]=0.23971;
  prob[ 7]=0.214199;
  prob[ 8]=0.167224;
  prob[ 9]=0;
  prob[10]=0.000224249;
  prob[11]=0.125873;
  */
  /*
  // 100-180, MIT 25/01/12
  prob[ 0]=1.23454e-09;
  prob[ 1]=0.373219;
  prob[ 2]=0.294438;
  prob[ 3]=0.398599;
  prob[ 4]=0.333781;
  prob[ 5]=0.278596;
  prob[ 6]=0.376076;
  prob[ 7]=0.341433;
  prob[ 8]=0.275072;
  prob[ 9]=0;
  prob[10]=0.0713116;
  prob[11]=0.318719;
  */
  /*
  // 100-180, MIT 25/01/12 V2
  prob[ 0]=2.4885e-06;
  prob[ 1]=0.223809;
  prob[ 2]=0.17233;
  prob[ 3]=0.166652;
  prob[ 4]=0.125056;
  prob[ 5]=0.14563;
  prob[ 6]=0.164199;
  prob[ 7]=0.136557;
  prob[ 8]=0.19783;
  prob[ 9]=2.15882e-283;
  prob[10]=0.191252;
  prob[11]=0.19369;
  */
  /*
  // 100-180, 09/02/12
  prob[ 0]=5.04987e-06;
  prob[ 1]=0.203095;
  prob[ 2]=0.154777;
  prob[ 3]=0.183836;
  prob[ 4]=0.145767;
  prob[ 5]=0.151491;
  prob[ 6]=0.173347;
  prob[ 7]=0.154231;
  prob[ 8]=0.160965;
  prob[ 9]=0;
  prob[10]=0.173101;
  prob[11]=0.129853;
  */
  /*
  // 100-180, 19/02/12
  prob[ 0]=2.13748e-05;
  prob[ 1]=  0.415919;
  prob[ 2]=  0.343875;
  prob[ 3]=  0.425056;
  prob[ 4]=  0.355072;
  prob[ 5]=  0.287651;
  prob[ 6]=  0.416514;
  prob[ 7]=  0.367597;
  prob[ 8]=  0.346779;
  prob[ 9]=  1.40544e-303;
  prob[10]=  0.339444;
  prob[11]=  0.364612;
  */

  // 100-180, 2011 reload
  prob[ 0]=0.00550015;
  prob[ 1]=0.844525;
  prob[ 2]=0.784478;
  prob[ 3]=0.863647;
  prob[ 4]=0.839708;
  prob[ 5]=0.786905;
  prob[ 6]=0.845337;
  prob[ 7]=0.839223;
  prob[ 8]=0.788596;
  prob[ 9]=1.88428e-293;
  prob[10]=0.83168;
  prob[11]=0.723152;

  /*
  // 100-180, 2012 early ICHEP
  prob[ 0]=1.16237e-09;
  prob[ 1]=0.048619;
  prob[ 2]=0.0328706;
  prob[ 3]=0.03608744;
  prob[ 4]=0.0420953;
  prob[ 5]=0.0301229;
  prob[ 6]=0.0644582;
  prob[ 7]=0.0450875;
  prob[ 8]=0.0304847;
  prob[ 9]=0;
  prob[10]=0.00695224;
  prob[11]=0.04552;
  */
  /*
  // 100-180, 2012 ICHEP
  prob[ 0]=3.52482e-05;
  prob[ 1]=0.180625;
  prob[ 2]=0.136088;
  prob[ 3]=0.207053;
  prob[ 4]=0.175099;
  prob[ 5]=0.131411;
  prob[ 6]=0.188651;
  prob[ 7]=0.175572;
  prob[ 8]=0.132867;
  prob[ 9]=0;
  prob[10]=0.130807;
  prob[11]=0.1627;
  */
  /*
  // 100-180, 2012 ICHEP topup
  prob[ 0]=2.53276e-08;
  prob[ 1]=0.441221;
  prob[ 2]=0.366429;
  prob[ 3]=0.497056;
  prob[ 4]=0.422544;
  prob[ 5]=0.349802;
  prob[ 6]=0.490375;
  prob[ 7]=0.424779;
  prob[ 8]=0.363089;
  prob[ 9]=0;
  prob[10]=0.0764675;
  prob[11]=0.354286;
  */
  /*
  // 100-180, 2012 HCP
  prob[ 0]=3.21706e-26;
  prob[ 1]=0.813912;
  prob[ 2]=0.756353;
  prob[ 3]=0.813353;
  prob[ 4]=0.757064;
  prob[ 5]=0.693044;
  prob[ 6]=0.809608;
  prob[ 7]=0.806208;
  prob[ 8]=0.750278;
  prob[ 9]=0;
  prob[10]=0.00130352;
  prob[11]=0.66869;
  */
  
  TGraphErrors *pTGE[2][nFcn][4];

  const unsigned nMHg(9);
  unsigned mh[nMHg]={110,115,120,125,130,135,140,145,150};
  std::string sMH[nMHg]={"110","115","120","125","130","135","140","145","150"};
  std::string sFn[nFcn]={"Exp1","Exp2","Exp3","Pow1","Pow2","Pow3",
			 "Lau2","Lau4","Lau6","Pol1","Pol3","Pol5"};
  std::string AB[2]={"F","B"}
  std::string SS[4]={"Stat","SysA","SysB","SysC"};
  std::string FB[2]={"Full","Background"};

  bool use[nFcn]={false,true ,true ,
		  true ,true ,true ,
		  true ,true ,true ,
		  false,false,true};

  std::cout << "Used function = " << sFn[usedFcn] << std::endl;

  TH1F *h;
  TH1F *hAdd[4];
  hAdd[0]=new TH1F("hAdd0","hAdd0",500,-500,500);
  hAdd[1]=new TH1F("hAdd1","hAdd1",500,-500,500);
  hAdd[2]=new TH1F("hAdd2","hAdd2",500,-500,500);
  hAdd[3]=new TH1F("hAdd3","hAdd3",500,-500,500);

  TH1F *dNum=(TH1F*)file9999->Get("SigRegionNumber");

  int loFcn(0),hiFcn(nFcn);
  if(nArg==1) {
    loFcn=usedFcn;
    hiFcn=loFcn+1;
  }

  for(unsigned p(1);p<2;p++) {
    for(int i(loFcn);i<hiFcn;i++) {
      for(unsigned l(0);l<4;l++) pTGE[p][i][l]=new TGraphErrors(9);
    
      for(unsigned j(0);j<nMHg;j++) {
	for(unsigned l(0);l<4;l++) hAdd[l]->Reset();

	for(int k(0);k<nFcn;k++) {
	  //std::string stub=std::string("MHg")+sMH[j]+"Gen"+sFn[k]+"Fit"+sFn[i]+FB[p]+"NormAverageMinuitGood";
	  std::string stub=std::string("MHg")+sMH[j]+"Gen"+sFn[k]+"Fit"+sFn[i]+FB[p]+"NormAverageMinuitAll";
	  h=(TH1F*)file[i][k]->Get((stub+"DeltaN").c_str());
	  if(h==0) std::cout << "NULL HIST" << std::endl;

	  if(k==i) {
	    hAdd[0]->Add(h);
	    //double err=sqrt(h->GetMean()*h->GetMean()+h->GetRMS()*h->GetRMS());
	    //pTGE[p][i][0]->SetPoint(j,mh[j]+0.1*(i-5.5),err);
	    //pTGE[p][i][0]->SetPointError(j,0,h->GetRMS()/sqrt(2.0*h->GetEntries()));
	    //if(i==1) std::cout << mh[j] << " " << h->GetRMS() << " " << h->GetRMS()/sqrt(2.0*hAdd->GetEntries()) << std::endl;
	  }

	  hAdd[1]->Add(h);
	  if(use[k]) hAdd[2]->Add(h);
	  hAdd[3]->Add(h,prob[k]);
	}

	hAdd[0]->SetTitle((std::string("Higgs ")+sMH[j]+" Fit "+sFn[i]+" Statistical spread;Normalisation residual").c_str());
	hAdd[1]->SetTitle((std::string("Higgs ")+sMH[j]+" Fit "+sFn[i]+" Systematic spread;Normalisation residual").c_str());
	hAdd[2]->SetTitle((std::string("Higgs ")+sMH[j]+" Fit "+sFn[i]+" Systematic spread;Normalisation residual").c_str());
	hAdd[3]->SetTitle((std::string("Higgs ")+sMH[j]+" Fit "+sFn[i]+" Systematic spread;Normalisation residual").c_str());
      
	for(unsigned l(0);l<4;l++) {
	  if(i==usedFcn) {
	    hAdd[l]->Draw();
	    c1->Update();
	    //c1->Print((std::string("MHg")+sMH[j]+"Fit"+sFn[i]+SS[l]+"Spread"+AB[p]+".png").c_str());
	  }

	  double err=sqrt(hAdd[l]->GetMean()*hAdd[l]->GetMean()+hAdd[l]->GetRMS()*hAdd[l]->GetRMS());
	  pTGE[p][i][l]->SetPoint(j,mh[j]+0.1*(i-5.5),err);	
	  pTGE[p][i][l]->SetPointError(j,0,hAdd[l]->GetRMS()/sqrt(2.0*hAdd[l]->GetEntries()));

	  //if(i==usedFcn && l==0) std::cout << mh[j] << " " << dNum->GetBinContent(j+1) << " " << err << " " << (dNum->GetBinContent(j+1)+err)/dNum->GetBinContent(j+1);
	  if(i==usedFcn && l==0) std::cout << mh[j] << " " << dNum->GetBinContent(j+1) << " " << hAdd[l]->GetRMS() << " " << (dNum->GetBinContent(j+1)+hAdd[l]->GetRMS())/dNum->GetBinContent(j+1);
	  if(i==usedFcn && l==3) std::cout << " " << err << " " << (dNum->GetBinContent(j+1)+err)/dNum->GetBinContent(j+1) << std::endl;
	}
      }
    }
  }

  if(nArg==0) {
  gStyle->SetOptStat(0);

  //TH1F *hAxis=new TH1F("Axis","Axis",900,110,155);
  TH1F *hAxis=new TH1F("Axis","Axis",800,112.5,152.5);
  TH1F *dErr=(TH1F*)file9999->Get("SigRegionError");
  
  TLatex t;
  std::cout << "text size = " << t.GetTextSize() << std::endl;

  for(unsigned p(1);p<2;p++) {
    for(unsigned m(0);m<5;m++) {
      for(int k(0);k<4;k++) {
	unsigned il(3*m);
	if(m==4) il=0;
	unsigned ih(3*(m+1));
	if(m==4) ih=nFcn;

	for(int i(il);i<ih;i++) {
	  pTGE[p][i][k]->SetMarkerStyle(nMarker[i/3]);
	  pTGE[p][i][k]->SetMarkerColor(nColor[i%3]);
	  pTGE[p][i][k]->SetLineColor(nColor[i%3]);
	  //pTGE[p][i][k]->SetPoint(nMHg,133+6*(i/3),91-15*(i%3));
	  pTGE[p][i][k]->SetPoint(nMHg,150,92-8*(i%3));
	}
    
	if(k==0) hAxis->SetTitle("Statistical error only;Higgs mass (GeV);Normalisation error (events)");
	else     hAxis->SetTitle("Statistical and systematic error;Higgs mass (GeV);Normalisation error (events)");

	hAxis->GetYaxis()->SetRangeUser(0,100);
	hAxis->Draw();
	dErr->Draw("same");

	for(int i(il);i<ih;i++) {
	  //if(k==0 || i!=9) pTGE[p][i][k]->Draw("same P");
	  pTGE[p][i][k]->Draw("same P");
	  t.SetTextColor(nColor[i%3]);
	  //t.DrawLatex(128+6*(i/3),84-15*(i%3),sFn[i].c_str());
	  t.DrawLatex(145,90-8*(i%3),sFn[i].c_str());
	}
	
	c1->Update();
	if(m==0) c1->Print((SS[k]+"Exp"+AB[p]+".png").c_str());
	if(m==1) c1->Print((SS[k]+"Pow"+AB[p]+".png").c_str());
	if(m==2) c1->Print((SS[k]+"Lau"+AB[p]+".png").c_str());
	if(m==3) c1->Print((SS[k]+"Pol"+AB[p]+".png").c_str());
	if(m==4) c1->Print((SS[k]+"All"+AB[p]+".png").c_str());
      }
    }
  }
  }
}
