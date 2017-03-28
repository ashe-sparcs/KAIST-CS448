/* Student Number & Name: 20140679 Jae Sung Kim */
/* 
	 In order to compile, type "./compile.sh" on your terminal. main.cpp and compile.sh should be in same folder.
	 If compile.sh is not willing to be executed, "chmod 700 compile.sh" first. 
	 Run the executable by "./a.out" and you'll get output.txt which is result file. 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

int s4_box[4][16] = {
  {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
  {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
  {10,  6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
  {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
};

bitset<4> s4(bitset<6> x) {
	bitset<4> s4_result;
	bitset<2> row;
	bitset<4> col;
	row.set(0, x[0]);
	row.set(1, x[5]);
	col.set(0, x[1]);
	col.set(1, x[2]);
	col.set(2, x[3]);
	col.set(3, x[4]);
	s4_result = s4_box[(int)row.to_ulong()][(int)col.to_ulong()];
	return s4_result;
}

int s4_diff(bitset<6> x) {
	bitset<6> temp (string("001100"));
	return (s4(x)^s4(x^temp)).count();
}

string s4_check(bitset<6> x) {
	if (s4_diff(x) >= 2) {
		return "Y";
	}
	return "N";
}

int main() {

  int i;
  ofstream outfile;
  outfile.open("output.txt");
  bitset<6> temp (string("001100"));
  outfile << "x\t\tS4(x)\tS4(x xor 001100)\t# of different bits\tproperty holds (Y/N)" << endl;
  for (i = 0; i < 64; i++) {
  	bitset<6> temp_x = i;
  	outfile 
  	<< temp_x.to_string()
  	<< "\t"
  	<< s4(temp_x).to_string()
  	<< "\t"
  	<< (s4(temp_x)^s4(temp_x^temp)).to_string()
  	<< "\t\t\t\t"
  	<< s4_diff(temp_x)
  	<< "\t\t\t\t\t"
  	<< s4_check(temp_x)
  	<< endl;
  }
  outfile.close();
  return 0;
}
