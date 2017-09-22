/*
A simple exercise for testing a stack is determining whether a set of html tags are “well formed” or not.
What exactly is meant by that? In the case of a pair of html tags (<html>, </html>) for an expression to be well formed, consider the following table.
<html><title></title></html> <- Well formed and balanced
<html><title><title></html> <- Not Balanced

Warning: This program is not designed to handle unclosing tags like <br>
*/

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <stack>

using namespace std;

int main()
{   

ifstream t("sample_html_file.html"); //opening the file
string file_data, html_without_text, html_style_removal; //creating string str
getline (t, file_data, (char) t.eof()); //getting all the line in html file

file_data.erase(std::remove(file_data.begin(), file_data.end(), '\n'), file_data.end()); // removing new lines and making whole html file a single line

regex e(">(.*?)<"); // regular expression to replace text between > TEXT < with > <
html_without_text = regex_replace(file_data, e, "> <");

regex f("\\b\\s(.*?)>"); // regular expression to replace tags like <font size=16> with <font>
html_style_removal = regex_replace(html_without_text, f, ">");

string tags_array[50]; // String Array of 50 items
int i=0;
stringstream ssin(html_style_removal); // Tokenization on the basis of spaces

cout << html_style_removal << endl;

while (ssin.good() && i < 50) // Adding the HTML Tags in Array
	{
	        ssin >> tags_array[i];
	        ++i;
	}

std::stack<string> mystack; // String stack initialization 

//Function for push and pop of HTML tags and checking the balancing 
for (i=0; i<50;i++) 
{
string current_string;
current_string = tags_array[i];
if (current_string == "")
	{
	}
else
	{
	int string_length = current_string.length();
	//cout << string_length << " " << current_string << endl;
		if (current_string.substr(0,2)=="</")
			{
			string str1 = current_string.substr(2,string_length-3);
			string top_element  = mystack.top();
			string str2 = top_element.substr(1,string_length-3);
			//cout << str1 << "	" << str2 << endl;
				if (str1 == str2)
					{
					mystack.pop();
					cout << current_string << " matched and popped" << endl;	
					}
			}
		else
			{
			mystack.push(current_string);
			cout << current_string << " pushed" << endl;
			}			
		
	}
}

if(mystack.size() == 0)
	{
	cout << "HTML TAGS ARE BALANCED :)" << endl;
	}
else 
	{
	cout << "HTML TAGS ARE NOT BALANCED" << endl;
	}

return 0;
}
