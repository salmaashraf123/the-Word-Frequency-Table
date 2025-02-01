#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<fstream>
#include<map>
using namespace std;
int main() {
   string filename;
   cout << "Enter a valid file name with exe (.txt): ";
   map<string , int>table_freq;
   while(true)
   {
      cin >> filename;
      ifstream file(filename);
      if(!file.is_open())
      {
         cout << "error opening file , please enter valid file name with exe (.txt) : ";
      }
      else{
         string input;
         while(file >> input)
         {
            string res = "";
            for(int i = 0 ; i < input.size() ; i++)
            {
               input[i] = tolower(input[i]);

               if((!ispunct(input[i]) && isalnum(input[i]))|| (input[i] == '-' && i > 0 && i < input.size() - 1 && isalnum(input[i - 1]) && isalnum(input[i + 1])))
               {
                  res +=input[i];
               }
            }
               if (!res.empty()) {
                  table_freq[res]++;
               }
         }
         file.close();
            cout << "Here's the Word Frequency Table" << endl;
            cout << "--------------------------------------------------------\n";
            cout << left << setw(20) << setfill(' ') << "Word" 
                 << right << setw(10) << "Frequency" << endl;
            cout << "--------------------------------------------------------\n";
            for (const auto& word : table_freq) {
               cout << left << setw(20) << setfill(' ')<< word.first<< right << setw(10) << word.second << endl;
            }
            cout << "--------------------------------------------------------\n";
            cout << "Thank you for using my word frequency table " << endl;
            break;
      }

   }


}