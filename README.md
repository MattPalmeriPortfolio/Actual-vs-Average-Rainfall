# Actual-vs-Average-Rainfall

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Actual_VS_Average_Rainfall.cpp  (program file containing code)
	raindata.txt                    (text file containing rain data for both avg and expected rainfall)
	rainoutput.txt                  (text file containing the output difference between avg and expected rainfall in a graph)

## Introduction
Book practice project from Problem Solving With C++ Chapter 7. Project 1.
Program reads in the average monthly rainfall vs. the actual, and outputs a graph and the difference. Demonstrates ability to read in a file, write to a file, and to use multiple functions in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. receive input from file of actual vs. expected rainfall for past 12 months
		1a. first, receive month code to know the starting month
			1aa. the start month is not included in the previous 12 months
		1b. from there, determine the sequence of the previous 12 months
			1ba. must wrap around - if start month is february, must store january, then december, etc. to prev february
		1c. then, receive input of expected rainfall followed by actual rainfall
	2. store expected rainfall and actual rainfall together with their month in multidimensional array
		2a. first get expected rainfall, store in array[x][1]
		2b. then get actual rainfall, store in array[x][2]
	3. output formatted table to file
		3a. use setw of 10 to make it look nice
		3b. include month name, actual rainfall, and difference from average in table
	4. output formatted graph to file
		4a. iterate through expected and actual rainfall, adding 1 * for 1 inch of rainfall

## Requirements
No requirements or modules needed for running this program.
