#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
	cout<<"\t********WORD SEARCH PUZZLE********\n";
	string ch;
	string given_words[10];
	cout<<"Following words are given in file"<<endl;
	ifstream fin("input1.txt",ios::in);
	for (int i=0; i<10; i++){
	fin>>ch;
	given_words[i]=ch;
	cout<<given_words[i];
	cout<<endl;}
	fin.close();
	cout<<"\nTHE REQUIRED PUZZLE IS : "<<endl;
	ofstream fout("output1.txt",ios::out);
	int rand_no;
	char randomLetter;
	char req_puzzle[10][10];
	for (int i=0; i<10; i++){
	for (int j=0; j<10; j++){
	req_puzzle[i][j]=' ';}}
	for (int term=0; term<10; term++){
	if (term==0){					
	int row=3;
	int col=1;
	for (int i=0; given_words[term][i]!='\0'; i++,row++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==1){					
	int row=1;
	int col=4;
	for (int i=0; given_words[term][i]!='\0'; i++,row++,col++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==2){					
	int row=1;
	int col=0;
	for (int i=0; given_words[term][i]!='\0'; i++,row++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==3){				
	int row=9;
	int col=4;
	for (int i=0; given_words[term][i]!='\0'; i++,col++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==4){					
	int row=1;
	int col=9;
	for (int i=0; given_words[term][i]!='\0'; i++,row++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==5){					
	int row=0;
	int col=1;
	for (int i=0; given_words[term][i]!='\0'; i++,col++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==6){				
	int row=8;
	int col=6;
	for (int i=0; given_words[term][i]!='\0'; i++,row--){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==7){					
	int row=9;
	int col=3;
	for (int i=0; given_words[term][i]!='\0'; i++,row--){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==8){				
	int row=9;
	int col=0;
	for (int i=0; given_words[term][i]!='\0'; i++,row--,col++){
	req_puzzle[row][col]=given_words[term][i];
	}}
	else if (term==9){					
	int row=0;
	int col=0;
	for (int i=0; given_words[term][i]!='\0'; i++,row++,col++){
	req_puzzle[row][col]=given_words[term][i];
	}}}
	for (int i=0; i<10; i++){
	for (int j=0; j<10; j++){
	if (req_puzzle[i][j]==' '){
	rand_no=rand()%26;
	randomLetter='a'+rand_no;
	req_puzzle[i][j]=randomLetter;}
	fout<<req_puzzle[i][j]<<" ";
	cout<<req_puzzle[i][j]<<" ";}
	fout<<endl;
	cout<<endl;}
	fout.close();
	return 0;
}
