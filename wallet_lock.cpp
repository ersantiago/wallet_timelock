#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string  gen_random(int len) {
    string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

string filename = gen_random(11);
string tmsrc1 = "w32tm /stripchart /computer:time.apple.com /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc2 = "w32tm /stripchart /computer:time.facebook.com /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc3 = "w32tm /stripchart /computer:time.windows.com /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc4 = "w32tm /stripchart /computer:time.cloudflare.com /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc5 = "w32tm /stripchart /computer:1.amazon.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc6 = "w32tm /stripchart /computer:ntp1.stratum1.ru /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc7 = "w32tm /stripchart /computer:1.opensuse.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc8 = "w32tm /stripchart /computer:1.android.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc9 = "w32tm /stripchart /computer:1.centos.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc10 = "w32tm /stripchart /computer:1.debian.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc11 = "w32tm /stripchart /computer:1.asia.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc12 = "w32tm /stripchart /computer:1.europe.pool.ntp.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc13 = "w32tm /stripchart /computer:ntp.nict.jp /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc14 = "w32tm /stripchart /computer:ntp1.ona.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;
string tmsrc15 = "w32tm /stripchart /computer:clock.isc.org /dataonly /samples:1 | FIND \"current time\" >> " + filename;

int fcn() {
    cout << "Subfunction\n";
    return 0;
}

string addr = "0x090cB6acE8f36F422E8432D182C5e0e3DC29B4EC";
int main() {
    cout << "\nInitialize ....................  Done\n";
    cout << "\nEth addr: " + addr + "\n";
    system(tmsrc1.c_str());
    system(tmsrc2.c_str());
    system(tmsrc3.c_str());
    system(tmsrc4.c_str());
    system(tmsrc5.c_str());
    system(tmsrc6.c_str());
    system(tmsrc7.c_str());
    system(tmsrc8.c_str());
    system(tmsrc9.c_str());
    system(tmsrc10.c_str());
    system(tmsrc11.c_str());
    cout << "Get dates from time sources ...  Done\n\n";

  string line;
  ifstream MyReadFile(filename);
  int timecount = 0;
  int sourcenum = 1;
  while (getline (MyReadFile, line)) {
    smatch m;
    regex e ("\\d{2}/\\d{2}/\\d{4}");   // matches words beginning by "sub"
    string outp;
    string temp;
    while (regex_search (line,m,e)) {
        //cout << m.str();
        cout << "\tDate Time Source ";
        cout << sourcenum;
        sourcenum++;
        string str1 = "\t=>\t" + m.str() + "\t";

        cout << str1;

        string str = m.str();
        regex reg("\/");
        sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
        sregex_token_iterator end;
        vector<string> vec(iter, end);
        for (auto a : vec)
        {
            temp = a + temp;
        }
        int fulldate = stoi(temp);
        if (fulldate > 20210905) {
            cout << "=>\tDate requirement met.\n";
            timecount++;
        } else {
            cout << "=>\tDate requirement not met.\n";
        }
        for (auto x:m){
            line = m.suffix().str();
        }
      }
  }
  MyReadFile.close();
  cout << "\nNumber of valid dates: ";
  cout << timecount;

  if (timecount >= 3) {
      cout << "\n\nDate consensus requirement is met. Here's your seed phrase bonitosan : \n";
      cout << "\t\n" ;
      timecount++;
  } else {
      cout << "\nDate requirement not yet met.\n";
  }
    const int result = remove( filename.c_str() );
    if( result == 0 ){
        printf( "\n" );
    } else {
        printf( "%s\n", strerror( errno ) ); // No such file or directory
    }

  system("PAUSE");
}

