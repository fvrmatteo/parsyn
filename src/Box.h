// Box class implements a generic n dimensional box
// where each dimension is a partial sum of a random variable
//
// @author: Fedor Shmarov
// @e-mail: f.shmarov@ncl.ac.uk
#ifndef BOX_H  
#define BOX_H 
#include<capd/capdlib.h>
#include<capd/intervals/lib.h>
#include<string>

using namespace std;
using namespace capd;

// Box class declaration
class Box
{ 
	private:

		// Box dimensions
		vector<DInterval> dimensions;

		// Dimensions names
		vector<string> vars;

		// Width of the shortest interval in the box 
		// dimensions
		DInterval min_dimension;

		// Width of the longest interval in the box 
		// dimensions
		DInterval max_dimension;

		DInterval volume;

		// Method for calculating parameters such as
		// box value and width of the shortest and
		// the longest intervals
		void calculate_params();

		// at most 2^32 boxes. Default value -1
		long int id = -1;

	public:

		// Constructor of the class
		//
		// @param the dimensions of the box	
		Box(vector<DInterval>, vector<string>);

		Box();

		// The method returns the box dimensions
		vector<Interval> get_dimensions();

		vector<string> get_vars();

		// The methods return the box value
		DInterval get_volume();

		// The method returns the width of the shortest
		// interval in the box dimensions
		DInterval get_min_dimension();

		// The method returns the width of the longest
		// interval in the box dimensions
		DInterval get_max_dimension();

		// The method returns the dimension
		// 
		// @param dimension index
		DInterval get_dimension(int);

		string get_var(int);

		int get_dimension_size();

		bool equals(Box);

		friend ostream& operator<<(ostream&, Box&);

}; 
#endif  