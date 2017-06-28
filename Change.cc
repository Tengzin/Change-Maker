#include <iostream>
using namespace std;
using std::atoi;

int main(int num, char *args[]) {
	const int minimum = 2;
	if ((num - 1) < minimum) {
		cout << "Usage: change [denominations] [amount]" << endl;
	}
	else {
			  
		int denoms[num - 2];
		for (int i = 1; i < (num - 1); i++) {
			denoms [i - 1] = atoi(args[i]);
		}
		
		for (int i = 0; i < (num - 2); ++i)
		{
			for (int j = i + 1; j < (num - 2); ++j)
			{
				if (denoms[i] < denoms[j])
				{
					int temp = denoms[i];
					denoms[i] = denoms[j];
					denoms[j] = temp;
				}
			}
		}
				
		const int sum = atoi(args[num - 1]);		
		
		int current = sum;
		int quotient, divisor;
		int result[num];
		int match [num];
		int count = 0;
		
		for (int i = 0; i < (num - 2); ++i) {
			divisor = denoms[i];
			//cout << "divisor is " << divisor << endl;
			quotient = current / divisor;		
			//cout << "quotient is " << quotient << endl;
			current = current - (divisor * quotient);
			//cout << "current: " << current << endl;
			result [i] = quotient;
			match [i] = divisor;
			count++;
			if (current == 0) break;			
		}
		if (current != 0) cout << "Impossible" << endl;
		else {
			for (int i = 0; i < count; ++i) {
				if (result [i] != 0) {
				cout << result[i] << " x " << match[i] << endl;
				}
			}
		}
	}
}