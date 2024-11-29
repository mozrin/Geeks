// Stuff I use to make things prettier in console C++ mode.

#define PE_WI(p,w) setprecision(p) << setw(w) << fixed
#define AL_PE_WI(a,p,w) (a?left:right) << setprecision(p) << setw(w) << fixed

// Helper Functions

std::string str_tolower(std::string s);
std::string str_toupper(std::string s);