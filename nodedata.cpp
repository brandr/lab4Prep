#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() { data = NULL; }                         // default

NodeData::~NodeData() {}            // needed so strings are deleted properly

NodeData::NodeData(const NodeData& nd) { data = nd.data; }  // copy

NodeData::NodeData(const Movie* m) { data = m; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
   if (this != &rhs) {
      data = rhs.data;
   }
   return *this;
}


//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
   return *data == *(rhs.data);
}

bool NodeData::operator!=(const NodeData& rhs) const {
   return *data != *(rhs.data);
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
   return *data < *(rhs.data);
}

bool NodeData::operator>(const NodeData& rhs) const {
   return *data > *(rhs.data);
}
//TODO: as operators get more complex, add *s to propely access movies.
bool NodeData::operator<=(const NodeData& rhs) const {
   return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs) const {
   return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

//TODO: write a new setdata
/*
bool NodeData::setData(istream& infile) { 
   getline(infile, data);
   return !infile.eof();       // eof function is true when eof char is read
}
*/

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
   output << *(nd.data);   //TODO: change how this is done.
   return output;
}

string NodeData::genre(){
   if(data == NULL) return "";
   return data -> genre();
}