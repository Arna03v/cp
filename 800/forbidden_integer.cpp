#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;
        
        if (x != 1) {
            std::cout << "YES" << std::endl;
            std::cout << n << std::endl;
            for (int i = 0; i < n; ++i) {
                std::cout << 1 << " ";
            }
            std::cout << std::endl;
        } else if (k == 1 || (k == 2 && n % 2 == 1)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            std::cout << n / 2 << std::endl;
            if (n % 2 == 1) {
                std::cout << 3 << " ";
            }
            for (int i = 0; i < n / 2 - 1; ++i) {
                std::cout << 2 << " ";
            }
            if (n % 2 == 0) {
                std::cout << 2;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}