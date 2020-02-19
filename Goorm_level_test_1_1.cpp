#include <iostream>
int main() {
	bool a, b;
	std::cin >> a >>  b;
	if (a && b) std::cout << 1 << '\n';
	else std::cout << 0 << '\n';
	if (a || b) std::cout << 1 << '\n';
	else std::cout << 0 << '\n';
	if (a != b) std::cout << 1 << '\n';
	else std::cout << 0 << '\n';
	return 0; 
}
