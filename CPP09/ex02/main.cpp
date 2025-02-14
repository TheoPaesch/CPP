/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/14 19:40:43 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <deque>

static long long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (static_cast<long long>(tv.tv_sec) * 1000000LL + tv.tv_usec);
}

int main(int argc, char **argv) {
	// Print error if no input
	if (argc < 2) {
		std::cerr << RED << "Error: no input provided." << RESET << std::endl;
		return 1;
	}

	// Prepare the data
	PmergeMe pMerger;
	try {
		// Store the original inputs for printing
		std::cout << YELLOW << "Before: " << RESET;
		for (int i = 1; i < argc; ++i) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;

		// Parse input into both containers
		pMerger.parseInputVec(argv + 1);
		pMerger.parseInputDeq(argv + 1);

		// Sort using vector
		long long startVec = getCurrentTime();
		pMerger.sortVec();
		long long endVec = getCurrentTime();
		double vecTime = static_cast<double>(endVec - startVec);

		// Sort using deque
		long long startDeq = getCurrentTime();
		pMerger.sortDeq();
		long long endDeq = getCurrentTime();
		double deqTime = static_cast<double>(endDeq - startDeq);

		// Print the result for vector
		const std::vector<int>& sortedVec = pMerger.getVec();
		std::cout << GREEN << "After (vector): " << RESET;
		for (size_t i = 0; i < sortedVec.size(); ++i) {
			std::cout << CYAN << sortedVec[i] << " " << RESET;
		}
		std::cout << std::endl;

		// Print the result for deque
		const std::deque<int>& sortedDeq = pMerger.getDeq();
		std::cout << GREEN << "After (deque): " << RESET;
		for (size_t i = 0; i < sortedDeq.size(); ++i) {
			std::cout << CYAN << sortedDeq[i] << " " << RESET;
		}
		std::cout << std::endl;

		// Print sorting times
		std::cout << MAGENTA << "Time to process a range of "
				<< sortedVec.size() << " elements with std::vector: "
				<< vecTime << " us" << RESET << std::endl;

		std::cout << BLUE << "Time to process a range of "
				<< sortedDeq.size() << " elements with std::deque: "
				<< deqTime << " us" << RESET << std::endl;

	} catch (const std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}