/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/12 15:27:45 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <deque>

long long getCurrentTime() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long microseconds = te.tv_sec * 1000000LL + te.tv_usec;
    return microseconds;
}

int main(int argc, char **argv) {
    // Default input if no command-line arguments are provided.
    const char *defaultInput[] = {"5", "2", "8", "1", "9", nullptr};

    PmergeMe pMerger;

    // Use command-line arguments starting at index 1 if available, otherwise the default input.
    if (argc > 1)
        pMerger.parseInputVec(argv + 1);
    else
        pMerger.parseInputVec(const_cast<char**>(defaultInput));

    // Test sorting for vector.
    long long startVec = getCurrentTime();
    pMerger.sortVec();
    long long endVec = getCurrentTime();

    std::cout << GREEN << "Sorted vector: " << RESET;
    const std::vector<int>& sortedVec = pMerger.getVec();
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        std::cout << CYAN << sortedVec[i] << " " << RESET;
    }
    std::cout << std::endl;
    std::cout << YELLOW << "Vector sort time: " << (endVec - startVec) << " µs" << RESET << std::endl;

    // Test sorting for deque.
    // Parse input into deque.
    PmergeMe dequeMerger;
    if (argc > 1)
        dequeMerger.parseInputDeq(argv + 1);
    else
        dequeMerger.parseInputDeq(const_cast<char**>(defaultInput));

    long long startDeq = getCurrentTime();
    dequeMerger.sortDeq();
    long long endDeq = getCurrentTime();

    std::cout << GREEN << "Sorted deque: " << RESET;
    const std::deque<int>& sortedDeq = dequeMerger.getDeq();
    for (size_t i = 0; i < sortedDeq.size(); ++i) {
        std::cout << BRIGHT_CYAN << sortedDeq[i] << " " << RESET;
    }
    std::cout << std::endl;
    std::cout << YELLOW << "Deque sort time: " << (endDeq - startDeq) << " µs" << RESET << std::endl;

    return 0;
}