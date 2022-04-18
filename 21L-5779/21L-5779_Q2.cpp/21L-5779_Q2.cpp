#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;
bool search_H_L_to_R(char box[18][19], char searchword[]);
bool search_R_to_L(char box[18][19], char searchword[]);
bool search_V_bottom(char box[18][19], char searchword[]);
bool search_V_top(char box[18][19], char searchword[]);
bool search_D_topL_to_BottomR(char box[18][19], char searchword[]);
bool search_D_BottomR_to_TopL(char box[18][19], char searchword[]);
bool search_D_topR_to_bottomL(char box[18][19], char searchword[]);
bool search_D_bottomL_to_topR(char box[18][19], char searchword[]);
int  startingR_I, starting_C_I, ending_R_I, ending_C_I;
int main()
{
	cout<<"\t********WORD SEARCH********\t"<<'\n';
	char ch;
	char box[18][19];
	cout<<"\n\n";
	ifstream fin("input2.txt",ios::in);
	ofstream fout("output2.txt",ios::out);
	for (int i=0; i<18; i++){
	for (int j=0; j<19; j++){
	fin>>ch;
	box[i][j]=ch;
	cout<<ch<<" ";}
	cout<<endl;}
	fin.close();
	cout<<"\n Enter 0 to end the word search";
	char searchword[20]=" ";
	while(!0){
	bool input=false;
	while (!input){
	cout<<"\nEnter word: ";
	cin>>searchword;
	cin.ignore();
	if (searchword[0]=='0')
	system("pause");
	for (int i=0; searchword[i]!='\0'; i++){
	if (!(searchword[i]>=97 && searchword[i]<=122) && !(searchword[i]>=65 && searchword[i]<=90)){
	cout<<"Wrong Input enter a correct word! ";
	input=false;
	break;}
	else
	input=true;}}
	for (int i=0; searchword[i]!='\0'; i++){
	if (searchword[i]>=97 && searchword[i]<=122){
	searchword[i]=searchword[i]-32;}}
	cout<<"Seaching for "<<searchword<<endl;
	fout<<"Entered word is: "<<searchword<<"\nIndices are: ";
	if (search_H_L_to_R(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_R_to_L(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_V_bottom(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_V_top(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_D_topL_to_BottomR(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_D_BottomR_to_TopL(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_D_topR_to_bottomL(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else if (search_D_bottomL_to_topR(box, searchword)){
	cout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;
	fout<<"("<<startingR_I<<","<<starting_C_I<<")"<<"("<<ending_R_I<<","<<ending_C_I<<")"<<endl;}
	else{
	cout<<"Word not found"<<endl;
	fout<<"Word not found"<<endl;}}
	fout.close();
	return 0;		 
}
bool search_H_L_to_R(char box[18][19], char searchword[])
{
	char word_F[20]=" ";		
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (row=0; row<18; row++){
	for (col=0; col<19; col++){
	if (searchword[0]==box[row][col]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	col++;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,col++){
	if (searchword[i]!=box[row][col]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_C_I++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	ending_R_I=startingR_I;
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_R_to_L(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (row=0; row<18; row++){
	for (col=18; col>=0; col--){
	if (searchword[0]==box[row][col]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	col--;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,col--){
	if (searchword[i]!=box[row][col]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_C_I--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	ending_R_I=startingR_I;
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_V_bottom(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=0; col<19; col++){
	for (row=0; row<18; row++){
	if (searchword[0]==box[row][col]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	row++;
	ending_R_I=startingR_I;
	for (int i=1; searchword[i]!='\0'; i++,row++){
	if (searchword[i]!=box[row][col]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_V_top(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=0; col<19; col++){
	for (row=17; row>=0; row--){
	if (searchword[0]==box[row][col]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	row--;
	ending_R_I=startingR_I;
	for (int i=1; searchword[i]!='\0'; i++,row--){
	if (searchword[i]!=box[row][col]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_D_topL_to_BottomR(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=0; col<19; col++){
	for (row=0; row<18; row++){
	int r=row;
	int c=col;
	if (searchword[0]==box[r][c]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	r++;
	c++;
	ending_R_I=startingR_I;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,r++,c++){
	if (searchword[i]!=box[r][c]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I++;
	ending_C_I++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_D_BottomR_to_TopL(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=18; col>=0; col--){
	for (row=17; row>=0; row--){
	int r=row;
	int c=col;
	if (searchword[0]==box[r][c]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	r--;
	c--;
	ending_R_I=startingR_I;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,r--,c--){
	if (searchword[i]!=box[r][c]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I--;
	ending_C_I--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_D_topR_to_bottomL(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=18; col>=0; col--){
	for (row=0; row<18; row++){
	int r=row;
	int c=col;
	if (searchword[0]==box[r][c]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	r++;
	c--;
	ending_R_I=startingR_I;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,r++,c--){
	if (searchword[i]!=box[r][c]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I++;
	ending_C_I--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}
bool search_D_bottomL_to_topR(char box[18][19], char searchword[])
{
	char word_F[20]=" ";
	bool first_I_F=false, found=false;
	int row, col;
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	for (col=0; col<19; col++){
	for (row=17; row>=0; row--){
	int r=row;
	int c=col;
	if (searchword[0]==box[r][c]){
	first_I_F=true;
	word_F[0]=searchword[0];
	startingR_I=row, starting_C_I=col;
	r--;
	c++;
	ending_R_I=startingR_I;
	ending_C_I=starting_C_I;
	for (int i=1; searchword[i]!='\0'; i++,r--,c++){
	if (searchword[i]!=box[r][c]){
	first_I_F=false;
	found=false;
	break;}
	else{
	word_F[i]=searchword[i];
	ending_R_I--;
	ending_C_I++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; searchword[i]!='\0'; i++){
	if (word_F[i]!=searchword[i]){
	startingR_I=0, starting_C_I=0, ending_R_I=0, ending_C_I=0;
	break;}}
	if (startingR_I==0 && starting_C_I==0 && ending_R_I==0 && ending_C_I==0)
	return false;
	else
	return true;
}

