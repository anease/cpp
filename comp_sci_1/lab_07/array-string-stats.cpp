/*
Name: Andrew Nease
Date: 10/18/2018
Assignment: Lab 07
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;


bool itExists(int array[], int length, int value){
    for (int i = 0; i < (length); i++) {
        if (array[i] == value) return true;
    }
    return false;
}

bool isSorted(int array[], int length){
    for (int i = 0; i < (length-1); i++) {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}

void reverse(vector <int> &reverse_me) {
    for (unsigned int i = 0; i < (reverse_me.size() / 2); ++i) {
          int tmpValue = reverse_me.at(i);  // These 3 statements swap
          reverse_me.at(i) = reverse_me.at(reverse_me.size() - 1 - i);
          reverse_me.at(reverse_me.size() - 1 - i) = tmpValue;
       }
}

float mean(const vector <float> values) {
    if (values.size() == 0 ) return 0;

    float sum = 0;

    for (unsigned int i = 0; i < values.size(); i++) {
        sum = sum +  values.at(i);
  }
    float mean = (sum / values.size());
    return mean;
}

float stddev(const vector <float> values) {
    if (values.size() == 0 ) return 0;

    float m = mean(values);
    float sum = 0;
    float diff = 0;
    float m2;
    int size =  values.size();

    for (unsigned int i = 0; i < size; ++i) {
        diff  = values.at(i) - m;
        diff = diff*diff;
        sum = sum + diff; }

    m2 = sum / size;

    return sqrt(m2);
}

vector<int> removeDups(vector<int> array){

    vector<int> n = array;

    sort(n.begin(), n.end());
    n.erase(unique(n.begin(), n.end()), n.end());

    return n;
}

// Strings - You need to a add the rest listed in the google doc
unsigned int countUpperCaseChars(const string &countme){
    unsigned int count = 0;

    for (unsigned int i = 0; i < countme.length(); i++) {
        if (isupper(countme[i]) ) count++; }

    return count;
}

unsigned int countPunctChars(const string &countme){
    unsigned int count = 0;

    for (unsigned int i = 0; i < countme.length(); i++) {
        if (ispunct(countme[i]) ) count++; }

    return count;
}

unsigned int countLowerCaseChars(const string &countme){
    unsigned int count = 0;

    for (unsigned int i = 0; i < countme.length(); i++) {
        if (islower(countme[i]) ) count++; }

    return count;
}

string convertToUpper(string to_be_converted){
    if (to_be_converted.length() == 0) return to_be_converted;

    for (unsigned int i = 0; i < to_be_converted.length(); i++) {
        if (islower(to_be_converted[i])) {
            to_be_converted[i] = toupper(to_be_converted[i]);
        }
    }
    return to_be_converted;
}

string convertToLower(string to_be_converted){
    if (to_be_converted.length() == 0) return to_be_converted;

    for (unsigned int i = 0; i < to_be_converted.length(); i++) {
        if (isupper(to_be_converted[i])) {
            to_be_converted[i] = tolower(to_be_converted[i]);
        }
    }
    return to_be_converted;
}

int positionOfMaxAsciiValue( string value){
    if (value.length() == 0) return -1;

    unsigned int max_position = 0;

    for (unsigned int i = 1; i < value.length(); i++) {
        if ( (int)value[i] > (int)value[i-1] ) max_position = i;
    }

    return max_position;
}

string removeSpaces(string input){
    if (input.length() == 0) return input;

    input.erase(std::remove(input.begin(),input.end(),' '),input.end());
    return input;
}

vector <int> characterCounts(string countme){
    countme = convertToLower(countme);

    int counta = 0;
    int countb = 0;
    int countc = 0;
    int countd = 0;
    int counte = 0;
    int countf = 0;
    int countg = 0;
    int counth = 0;
    int counti = 0;
    int countj = 0;
    int countk = 0;
    int countl = 0;
    int countm = 0;
    int countn = 0;
    int counto = 0;
    int countp = 0;
    int countq = 0;
    int countr = 0;
    int counts = 0;
    int countt = 0;
    int countu = 0;
    int countv = 0;
    int countw = 0;
    int countx = 0;
    int county = 0;
    int countz = 0;

    for (unsigned int i = 0; i < countme.length(); i++) {
        if (countme[i] == 'a') counta++;
        else if (countme[i] == 'b') countb++;
        else if (countme[i] == 'c') countc++;
        else if (countme[i] == 'd') countd++;
        else if (countme[i] == 'e') counte++;
        else if (countme[i] == 'f') countf++;
        else if (countme[i] == 'g') countg++;
        else if (countme[i] == 'h') counth++;
        else if (countme[i] == 'i') counti++;
        else if (countme[i] == 'j') countj++;
        else if (countme[i] == 'k') countk++;
        else if (countme[i] == 'l') countl++;
        else if (countme[i] == 'm') countm++;
        else if (countme[i] == 'n') countn++;
        else if (countme[i] == 'o') counto++;
        else if (countme[i] == 'p') countp++;
        else if (countme[i] == 'q') countq++;
        else if (countme[i] == 'r') countr++;
        else if (countme[i] == 's') counts++;
        else if (countme[i] == 't') countt++;
        else if (countme[i] == 'u') countu++;
        else if (countme[i] == 'v') countv++;
        else if (countme[i] == 'w') countw++;
        else if (countme[i] == 'x') countx++;
        else if (countme[i] == 'y') county++;
        else if (countme[i] == 'z') countz++; }

    vector <int> count;
    count.push_back(counta);
    count.push_back(countb);
    count.push_back(countc);
    count.push_back(countd);
    count.push_back(counte);
    count.push_back(countf);
    count.push_back(countg);
    count.push_back(counth);
    count.push_back(counti);
    count.push_back(countj);
    count.push_back(countk);
    count.push_back(countl);
    count.push_back(countm);
    count.push_back(countn);
    count.push_back(counto);
    count.push_back(countp);
    count.push_back(countq);
    count.push_back(countr);
    count.push_back(counts);
    count.push_back(countt);
    count.push_back(countu);
    count.push_back(countv);
    count.push_back(countw);
    count.push_back(countx);
    count.push_back(county);
    count.push_back(countz);

    return count;
}

template<typename T>
string print(vector<T> vec);

template<typename T>
string print(T array[], int length);


int main(){
  srand(time(0));

  cout << "find:" << endl;
  int x1[10] = {1,2,3,5,5,6,7,8,9,0};

  cout << "false/0 = " << itExists(x1, 10, 4) << endl;
  cout << "false/0 = " << itExists(x1, 10, 99) << endl;
  cout << "true/1 = " << itExists(x1, 10, 5) << endl;
  cout << "true/1 = " << itExists(x1, 10, 0) << endl;
  cout << "true/1 = " << itExists(x1, 10, 1) << endl;
  cout << "true/1 = " << itExists(x1, 10, 6) << endl;
  cout << endl;
  cout << endl;
  cout << "reverse:" << endl;
  vector <int> v1 = {1,2,3,4,5};
  reverse(v1);
  cout << "[5,4,3,2,1] = " << print(v1) << endl;
  reverse(v1);
  cout << "[1,2,3,4,5] = " << print(v1) << endl;
  vector <int> v2 = {5};
  cout << "[5] = " << print(v2) << endl;
  vector <int> v3 = {1,2,4,5};
  reverse(v3);
  cout << "[5,4,2,1] = " << print(v3) << endl;
  vector <int> v4(100);
  v4[0]  = 4;
  v4[1]  = 2;
  reverse(v4);
  cout << "0 = " << v4[0] << endl;
  cout << "2 = " << v4[98] << endl;
  cout << "4 = " << v4[99] << endl;

  cout << endl << "mean:" << endl;
  vector <float> f1 = {1.2, 2.4, 3.4};
  vector <float> f2 = {5.6, 5.6, 5.6, 5.6, 5.6, 5.6};
  cout << "2.33 = " << mean(f1) << endl;
  cout << "5.6 = " << mean(f2) << endl;

  cout << endl << "stddev:" << endl;
  cout << "0.899 = " << stddev(f1) << endl;
  cout << "0 = " << stddev(f2) << endl;

  cout << endl << "removedups:" << endl;
  vector<int> v5;
  v5.push_back(1);
  v5.push_back(2);
  v5.push_back(3);
  v5.push_back(3);
  v5.push_back(4);
  v5.push_back(5);
  v5.push_back(1);
  vector<int> v12 = removeDups(v5);
  cout << "[1,2,3,4,5] = " << print(v12) << endl;
  cout << "5 = " << v12.size() << endl;
  vector<int> v6;
  for(int i = 0; i < 100; i++){
    v6.push_back(i%17 + i %7);
  }
  vector<int> v22 = removeDups(v6);
  cout << "22 = " << v22.size() << endl;

  cout << "\nString Functions: " << endl;
  string upper_test = "aaABCdeFG";
  cout << "countUpperCase" << endl;
  cout << "5 = " << countUpperCaseChars(upper_test) << endl;
  cout << "5 = " << countUpperCaseChars("AAAAA") << endl;
  cout << "0 = " << countUpperCaseChars("aaaaa") << endl;
  string no_upper_case = "aaaa";
  cout << "0 = " << countUpperCaseChars(no_upper_case) << endl;

  cout << "RemoveSpaces:" << endl;
  string test1 = "aa AB Cd e FG";
  string test2 = "aaAB Cd e FG ";
  string test3 = " rrAB Cd e FG";
  string test4 = " rrAB Cd e FG ";

  cout << "aaABCdeFG = " << removeSpaces(test1) << endl;
  cout << "aaABCdeFG = " << removeSpaces(test2) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test3) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test4) << endl;

  return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!

template<typename T>
string print(vector<T> vect) {
  stringstream out;
  out << '[';
  for(int i = 0; i < vect.size(); i++){
    out << vect[i];
    if(i != vect.size()-1)out << ',';
  }
  out << ']';
  return out.str();
}


template<typename T>
string print(T array[], int length){
  stringstream out;
  out << '[';
  for(int i = 0; i < length; i++){
    out << array[i];
    if(i != length-1)out << ',';
  }
  out << ']';
  return out.str();
}

