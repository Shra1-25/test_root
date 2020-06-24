#include <vector>
 
 #include "TFile.h"
 #include "TTree.h"
 #include "TCanvas.h"
 #include "TFrame.h"
 #include "TH1F.h"
 #include "TBenchmark.h"
 #include "TRandom.h"
 #include "TSystem.h"
using namespace std;

void root_read()
 {
 
    TFile *f1 = TFile::Open("temp_file.root","READ");
    if (!f1) { return; }
 
    std::vector<float> *temp_vec = 0;
    TTree *t1 = (TTree*)f1->Get("tvec");
    t1->SetBranchAddress("tvec",&temp_vec);
    for (int i=0;i<10;i++){
      t1->GetEntry(i);
    } 
    for (int j=0;j<10;j++){
     std::cout<<temp_vec->at(j)<<" ";
    }
    std::cout<<endl;
    t1->ResetBranchAddresses();
    f1->Close();
 }
