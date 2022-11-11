#include <iostream>
using namespace std;

namespace MubbleWhomp{
	int flerple = 100;
}

namespace Bob {
	int flerple = 1234567890;
}

// Global veriables
int flerple = 200;

int main() {
	// Local variables
	int flerple = 300;

	cout << flerple << endl; // it will print 300
	cout << MubbleWhomp::flerple << endl; // it will print 100
	cout << Bob::flerple << endl;
}


/*

1) Were you correct with your guess? Why does the code print out what it does?
	Yes   It prints 100 because when you say MubbleWhomp it takes over the variable.

2) What happens if you have a global and local variable with the same name? Does this have anything to do with namespaces?
	At first the variable is set to the value of the globe so in this case 200 but
	when it gets to the local it changes in this code it becomes 300. For the 
	namespace it is similar but the variable only changes when it is called.

3) What do namespaces allow you to do? What problems might this cause? Why might some profs consider it bad practice to include namespace std?
	I think that name spaces allow you to stop variables and data to use at specific 
	times. Some problems could be that in some situations they could overlap and 
	mess things up. Some professionals might say that include namespace std is bad 
	because then that could overlap weirdly with other namespaces.

4) What else can go into a namespace? Experiment with code or google
	Many other variables like bools, chars, and strings. Also according to google 
	names of the types and functions as well.

*/
