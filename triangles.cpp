/*
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: To complete this project I read chapters 8 and 9 from the book. 8 helped me with reference and 9 with classes. 
 *             I also followed some of your suggestions in the readme such as sort() function. 
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 5 hours thinking 5  hours programming 
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"
unsigned long triangle::perimeter() {
	return s1+s2+s3;
}

unsigned long triangle::area() {
	// TODO: write this function.
	// Note: why is it okay to return an integer here?  Recall that
	// all of our triangles have integer sides, and are right triangles...
	vector<int> mytri;
	
	mytri.push_back(s1);
	mytri.push_back(s2);
	mytri.push_back(s3);
	
	sort(mytri.begin(), mytri.end());

	return ((mytri[0] * mytri[1]) / 2) ;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2)
{
	// TODO: write this function.
	
	vector<int> tri1;
	vector<int> tri2;
	
	tri1.push_back(t1.s1);
	tri1.push_back(t1.s2);
	tri1.push_back(t1.s3);
	
	tri2.push_back(t2.s1);
	tri2.push_back(t2.s2);
	tri2.push_back(t2.s3);
	
	sort(tri1.begin(), tri1.end());
	sort(tri2.begin(), tri2.end());
	
	if( tri1[0] == tri2[0] && tri1[1] == tri2[1] && tri1[2] == tri2[2])
	{
        return true;
	}
	else
	{
	   return false;
	}
}

bool similar(triangle t1, triangle t2)
{
	// TODO: write this function.
	vector<int> tri1;
	vector<int> tri2;
	
	tri1.push_back(t1.s1);
	tri1.push_back(t1.s2);
	tri1.push_back(t1.s3);
	
	tri2.push_back(t2.s1);
	tri2.push_back(t2.s2);
	tri2.push_back(t2.s3);
	
	sort(tri1.begin(), tri1.end());
	sort(tri2.begin(), tri2.end());
	
	double side1 = tri1[0];
	double side2 = tri1[1];
	double side3 = tri1[2];
	
	double side11 = tri2[0];
	double side22 = tri2[1];
	double side33 = tri2[2];
	
	//cout<<side1/side11<<'\n';
	//cout<<side2/side22<<'\n'; Just to output the proportions of similar triangels
	//cout<<side3/side33<<'\n';
	
	if( (side1/side11 == side2/side22) && (side2/side22 == side3/side33) && (side1/side11 == side3/side33) )
	{
        return true;
	}
	else
	{
	   return false;
	}
}

vector<triangle> findRightTriangles(unsigned long l, unsigned long h) 
{
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.
	int i = 1;
	
	while(i < h)
	{
	   int j = 1;
	   
	   while(j <h)
	   {
	      int k = 1;
		  
	      while(k<h)
		  {
		     int si1= 0;
			 int si2 = 0;
			 int si3 = 0;
			 
			 if(k>= j && k>=i && j>= i)
			 {
			    si3 = k;
				si2 = j;
				si1 = i;
			 }
			 else if(k>=j && k>= i && i>=j)
			 {
			    si3 = k;
				si2 = i;
				si1 = j;
			 }
			 else if(j>=k && j>=i && k>=i)
			 {
			    si3 = j;
				si2 = k;
				si1 = i;
			 }
			 else if(j>=k && j>=i && i>=k)
			 {
			    si3 = j;
				si2 = i;
				si1 = k;
			 }
			 else if( i>=k && i>=j && k>=j)
			 {
			    si3 = i;
				si2 = k;
				si1 = j;
			 }
			 else if( i>=k && i>=j && j>=k)
			 {
			    si3 = i;
				si2 = j;
				si1 = k;
			 }
			 
		     if( (si1*si1)+(si2*si2) == (si3*si3) && si1+si2+si3 >= l && si1+si2+si3 <= h)   //Perimeter Bound and Pyto
			 {
			    triangle found(si1,si2,si3);
				int x = 0;
				bool decide = false;
				while(x < retval.size() && retval.size()>0)
				{
				   if ( (retval[x].s1 + retval[x].s2 + retval[x].s3) == (found.s1 + found.s2 + found.s3) && retval[x].s1 == si1 && retval[x].s2 == si2 && retval[x].s3 == si3)
				   {
				      decide = true;
				      break;
				   }
				   else
				   {
				      ++x;
				   }
				}
				
				if(decide == false)
				{
				   //cout<<"A: " << i << "   B: " <<j<<"  C: "<<k << '\n';  to see what triangles are being inserted
				   retval.push_back(found);
				}
				
				
				++k;
			 }
			 else
			 {
			    ++k;
			 }
		  }
		  
		  ++j;
	   }
	   
	   ++i;
	}
	
	
	return retval;
}

