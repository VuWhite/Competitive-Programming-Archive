#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Sieve of Eratosthenes to find all prime numbers up to max_num
std::vector<bool> sieve_of_eratosthenes(int max_num) {
    std::vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

// Build the graph using XOR and prime check
std::unordered_map<int, std::vector<int>> build_graph(int n, const std::vector<bool>& is_prime) {
    std::unordered_map<int, std::vector<int>> graph;
    int max_num = 2 * 100000;
    
    for (int u = 1; u <= n; ++u) {
        for (int p = 2; p <= max_num; ++p) {
            if (is_prime[p]) {
                int v = u ^ p;
                if (v >= 1 && v <= n && u != v) {
                    graph[u].push_back(v);
                }
            }
        }
    }
    return graph;
}

// Greedy algorithm for graph coloring
std::pair<int, std::vector<int>> greedy_coloring(const std::unordered_map<int, std::vector<int>>& graph, int n) {
    std::vector<int> result(n + 1, -1);
    std::vector<bool> available(n + 1, false);
    
    for (int u = 1; u <= n; ++u) {
        if (result[u] == -1) {
            result[u] = 0;
        }
        
        for (int v : graph.at(u)) {
            if (result[v] != -1) {
                available[result[v]] = true;
            }
        }
        
        int cr = 0;
        while (cr < n && available[cr]) {
            ++cr;
        }
        
        for (int v : graph.at(u)) {
            if (result[v] != -1) {
                available[result[v]] = false;
            }
        }
        
        for (int v : graph.at(u)) {
            if (result[v] == -1) {
                result[v] = cr;
                available[cr] = true;
            }
        }
    }
    
    int max_color = *std::max_element(result.begin(), result.end());
    return {max_color + 1, std::vector<int>(result.begin() + 1, result.end())};
}

// Main function for minimum graph coloring
std::pair<int, std::vector<int>> minimum_graph_coloring(int n) {
    int max_num = 2 * 100000;
    std::vector<bool> is_prime = sieve_of_eratosthenes(max_num);
    std::unordered_map<int, std::vector<int>> graph = build_graph(n, is_prime);
    return greedy_coloring(graph, n);
}

int main() {
    int t;
    //std::cout << "Enter the number of test cases: ";
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        //std::cout << "Enter the number of vertices for test case " << (i + 1) << ": ";
        std::cin >> n;
        auto [num_colors, coloring] = minimum_graph_coloring(n);
        std::cout <<  num_colors << '\n';
        for (int color : coloring) {
            std::cout << color << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
