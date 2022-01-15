#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
//declare functions
void monthOrder(double monthsAndValues[][3], int startMonth);
//precondition: monthsAndValues is a 2D array meant to hold 2 values correlated to their month at index [x][0]
//and startMonth is the integer code for a month (i.e. 1 for january)
// postcondition: fills the array in order with the 12 months preceding startMonth.
std::string monthCodeToName(int monthCode);
//precondition: monthCode is the integer code for a month
//postcondition: returns the three-letter name of the month corresponding to the month code
void fillArray(double multiArray[][3], const int size, const int secondIndex, std::istream& inStream);
//precondition: multiArray is a multidimensional array of size [size][3], and the indexes [x][secondIndex] 
//are the desired storage locations. inStream is attached to an open stream.
//postcondition: fills multiArray[x < size][secondIndex] with values from inStream.
void rainTable(const double rainData[][3], std::ostream& outStream);
//precondition: rainData contains the following information in order: month code, average rainfall, actual rainfall
//postcondition: outputs a table to outStream showing the difference in actual rainfall from average rainfall per the data.
void rainGraph(const double rainData[][3], std::ostream& outStream);
//precondition: rainData contains the following information in order: month code, average rainfall, actual rainfall
//postcondition: outputs a bar graph to outStream showing the difference between actual and average rainfall

//main
int main()
{
	using namespace std;
	//initialize variables
	double monthlyRainfall[12][3];
	int startMonth;
	ifstream rainData("raindata.txt");
	ofstream tableGraph("rainoutput.txt");
	//fill data
	if (rainData.fail())
		exit(1);
	if (tableGraph.fail())
		exit(1);
	rainData >> startMonth;
	monthOrder(monthlyRainfall, startMonth);
	fillArray(monthlyRainfall, 12, 1, rainData);
	fillArray(monthlyRainfall, 12, 2, rainData);
	rainData.close();
	//output
	rainTable(monthlyRainfall, tableGraph);
	tableGraph << endl;
	rainGraph(monthlyRainfall, tableGraph);
	//end
	tableGraph.close();
	cout << "Files successfully edited.\n";
	return 0;
}

//define functions
void monthOrder(double monthsAndValues[][3], int startMonth)
{
	int counter = 0;
	for (int currentMonth = startMonth - 1; currentMonth > 0 && counter < 12; currentMonth--, counter++)
	{
		monthsAndValues[counter][0] = currentMonth;
	}
	for (int currentMonth = 12; currentMonth >= startMonth && counter < 12; currentMonth--, counter++)
	{
		monthsAndValues[counter][0] = currentMonth;
	}
	return;
}
//uses <string?
std::string monthCodeToName(int monthCode)
{
	using namespace std;
	switch (monthCode)
	{
	case 1:
		return "JAN";
	case 2:
		return "FEB";
	case 3:
		return "MAR";
	case 4:
		return "APR";
	case 5:
		return "MAY";
	case 6:
		return "JUN";
	case 7:
		return "JUL";
	case 8:
		return "AUG";
	case 9:
		return "SEP";
	case 10:
		return "OCT";
	case 11:
		return "NOV";
	case 12:
		return "DEC";
	default:
		return "ERROR";
	}
}
//uses iostream/fstream and iomanip
void rainTable(const double rainData[][3], std::ostream& outStream)
{
	using namespace std;
	//format output
	outStream.setf(ios::showpoint);
	outStream.setf(ios::left);
	outStream.setf(ios::fixed);
	outStream.precision(1);
	//output table
	outStream << setw(8) << "Month" << "Rain (in.) " << "Diff." << endl;
	for (int i = 0; i < 12; i++)
	{
		outStream << setw(8) << monthCodeToName(static_cast<int>(rainData[i][0]))
			<< setw(12) << rainData[i][1] << showpos << rainData[i][1] - rainData[i][2]
			<< noshowpos << endl;
	}
	return;
}
//uses iostream/fstream, cmath
void rainGraph(const double rainData[][3], std::ostream& outStream)
{
	using namespace std;
	for (int i = 0; i < 12; i++)
	{
		outStream << monthCodeToName(rainData[i][0]) << endl;
		outStream << "Avg. Rainfall: ";
		for (int j = 0; j < floor(rainData[i][1] + 0.5); j++)
			outStream << "*";
		outStream << "\nAct. Rainfall: ";
		for (int j = 0; j < floor(rainData[i][2] + 0.5); j++)
			outStream << "*";
		outStream << endl;
	}
	return;
}
void fillArray(double multiArray[][3], const int size, const int secondIndex, std::istream& inStream)
{
	double next;
	for (int i = 0; i < size && inStream >> next; i++)
	{
		multiArray[i][secondIndex] = next;
	}
	return;
}