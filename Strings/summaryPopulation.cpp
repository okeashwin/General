#include<iostream>
#include<cstring>
#include<cstdlib>
#include<dirent.h>
#include<fstream>
#include<string>

/*
# 1. Compute the occurrence frequency of the characters {'A', 'T', 'G', 'C'}.
# 
#   The 'summary.txt' file should contain the following format for each file:
# 
#   Example (for one file):
#
#       {
#           'filename'      : 'DV-S2_ACTTGA_L008_R1_001.fastq',
#           'flowcell'      : 'DV',
#           'project'       : 'S2',
#           'subproject'    : 'ACTTGA',
#           'method'        : 'L008',
#           'id'            : 'R1',
#           'code'          : 1,
#           'A_freq'        : 69,
#           'T_freq'        : 70,
#           'G_freq'        : 51,
#           'C_freq'        : 59
#       }
 
# 2. Generalize your script to receive a directory path that contains multiple '.fastq' files as input, from command line.
 
# 3. Parallelize your code.

Generalized as per the requirements, can be executed as : <executable> <dir_to_scan>
For parallelizing this, we can easily create different threads - one thread responsible for processing a single file


*/

using namespace std;
void populateResults(char *dirPath);
void processFile(char *dirPath, char *fName);
ofstream summary("summary.txt");

void processFile(char *dirPath, char *fName) {
	if(strlen(dirPath)==0 || strlen(fName)==0) {
		return;
	}

	string fileName;
	fileName.append(dirPath);fileName.append(fName);
    string line;
    int lineNumber=0;
    int a_freq=0, t_freq=0, c_freq=0, g_freq=0; 
  	ifstream file(fileName.c_str());
  	if (file.is_open()) {
    	while(getline(file,line) ) {
    		lineNumber++;
    		if(lineNumber%4==2) {
    			cout<<line<<endl;
      			int n=line.length();
      			for(int i=0;i<n;i++) {
      				if(line[i]=='A') a_freq++;
      				else if(line[i]=='C') c_freq++;
      				else if(line[i]=='G') g_freq++;
      				else if(line[i]=='T') t_freq++;
      			}
      		}
    	}
    	char *tok, *tok1;
    	char *temp=(char *)malloc((strlen(fName)+1)*sizeof(char));
    	char *temp2=(char *)malloc((strlen(fName)+1)*sizeof(char));
    	char *temp3=(char *)malloc((strlen(fName)+1)*sizeof(char));
    	strcpy(temp,fName);
    	strcpy(temp2,fName);
    	summary<<"{"<<endl;
    	summary<<'\t'<<"'filename' : " << "'"<<fName<<"',"<<endl;
    	tok1=strtok(temp2,"_");
    	tok=strtok(temp,"-");
    	
    	strcpy(temp3, tok1);

    	tok=strtok(temp2,"-");
    	summary<<'\t'<<"'flowcell' : " << "'"<<tok<<"',"<<endl;

    	tok=strtok(temp3,"-");
    	tok=strtok(NULL,"-");
    	summary<<'\t'<<"'project' : " << "'"<<tok<<"',"<<endl;

    	strcpy(temp,fName);
    	tok=strtok(temp,"_");
    	tok=strtok(NULL,"_");
    	summary<<'\t'<<"'subproject' : " << "'"<<tok<<"',"<<endl;

    	tok=strtok(NULL,"_");
    	summary<<'\t'<<"'method' : " << "'"<<tok<<"',"<<endl;

    	tok=strtok(NULL,"_");
    	summary<<'\t'<<"'id' : " << "'"<<tok<<"',"<<endl;

    	tok=strtok(NULL,"_");
    	summary<<'\t'<<"'code' : " <<atoi(tok)<<","<<endl;

    	summary<<'\t'<<"'A_freq' : " << a_freq<<","<<endl;
    	summary<<'\t'<<"'T_freq' : " << t_freq<<","<<endl;
    	summary<<'\t'<<"'G_freq' : " << g_freq<<","<<endl;
    	summary<<'\t'<<"'C_freq' : " << c_freq<<","<<endl;
    	summary<<"}"<<endl;
    	summary<<endl;
  	}
  	file.close();
}

void populateResults(char *dirPath) {

   DIR *dirp = opendir(dirPath);
   struct dirent *dp;
   while ((dp = readdir(dirp)) != NULL) {
   		char *tokExt=NULL;
   		char *tempFilename=(char *)malloc((strlen(dp->d_name)+1)*sizeof(char));
   		strcpy(tempFilename, dp->d_name);
   		tokExt=strtok(tempFilename, ".");
   		tokExt=strtok(NULL, ".");

   		if(tokExt!=NULL && strcmp(tokExt,"fastq")==0) {
   			// cout<<"Processing file : "<<dp->d_name<<endl;
   			processFile(dirPath,dp->d_name);	
   		}
   }
   closedir(dirp);
}

int main(int argc, char *argv[]) {

	if(argc<2) {
		cout<<"No directory received"<<endl;
		return -1;
	}
	populateResults(argv[1]);
	summary.close();
	return 0;
}