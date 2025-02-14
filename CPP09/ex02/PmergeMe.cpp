/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:33 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/14 19:57:54 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <set>
#include <algorithm>

template<typename Container>
void PmergeMe::parseInput(Container& container, char** input) {
	char* endptr = NULL;
	std::set<int> seenNumbers;
	while (*input) {
		long val = strtol(*input++, &endptr, 10);
		// Ensure valid integer
		if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
			throw std::invalid_argument("Each input must be a positive integer within range.");
		}
		// Check duplicates, if desired
		if (!seenNumbers.insert(static_cast<int>(val)).second) {
			throw std::invalid_argument("Duplicate numbers are not allowed (or handle otherwise).");
		}
		container.push_back(static_cast<int>(val));
	}
	if (container.empty()) {
		throw std::invalid_argument("No input provided.");
	}
}

void PmergeMe::parseInputVec(char** input) {
	parseInput(_vec, input);
}

void PmergeMe::parseInputDeq(char** input) {
	parseInput(_deq, input);
}

template<typename Container>
void PmergeMe::buildPairs(Container& container, std::vector<Container>& pairs) {
	// Example: split Container into pairs (or pairs of pairs) recursively
	// forming subgroups while preserving already formed sub-pairs.
	// This is a simplified illustration; adapt as needed.

	// Create subgroups
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		Container sub;
		sub.push_back(container[i]);
		sub.push_back(container[i + 1]);
		// Ensure sub[0] <= sub[1] (b, a)
		if (sub[0] > sub[1])
			std::swap(sub[0], sub[1]);
		pairs.push_back(sub);
	}
	// If odd element remains, store it separately (e.g., as a "b" alone)
	if (container.size() % 2 != 0) {
		Container sub;
		sub.push_back(container.back());
		pairs.push_back(sub);
	}
}

// Example: insert "pend" into "main" using a binary search approach
// respecting the idea of bounding with "a" elements and possibly
// Jacobsthal-based insertion orders.
template<typename Container>
void PmergeMe::insertPend(Container& mainChain, const Container& pendChain) {
	// Simplified example of binary insertion for each element in pendChain.
	// In a full implementation, you would handle Jacobsthal insertion logic
	// (grouping b_i’s in the correct order) for minimal comparisons.

	for (auto& elem : pendChain) {
		// Binary search for position in mainChain
		int left = 0;
		int right = static_cast<int>(mainChain.size());
		while (left < right) {
			int mid = (left + right) / 2;
			if (elem < mainChain[mid])
				right = mid;
			else
				left = mid + 1;
		}
		// Insert
		mainChain.insert(mainChain.begin() + left, elem);
	}
}

// Helper: binary insertion for groups (i.e. for nested containers)
// Compares two groups by their first element.
template<typename GroupContainer>
void binaryInsertGroup(GroupContainer& groups, const typename GroupContainer::value_type& group, int pos) {
    int i = pos - 1;
    while (i >= 0 && groups[i][0] > group[0]) {
        groups[i + 1] = groups[i];
        --i;
    }
    groups[i + 1] = group;
}

// Helper: recursively sort groups (nested containers) using binary insertion,
// comparing by the first element of each inner container.
template<typename GroupContainer>
void fordJohnsonSortGroups(GroupContainer& groups, int left, int right) {
    if (right - left > 1) {
        int mid = left + (right - left) / 2;
        fordJohnsonSortGroups(groups, left, mid);
        fordJohnsonSortGroups(groups, mid, right);
        for (int i = mid; i < right; ++i) {
            binaryInsertGroup(groups, groups[i], i);
        }
    }
}

// Updated Ford–Johnson sort that recursively groups pairs.
template<typename Container>
void PmergeMe::fordJohnsonSort(Container& container, int left, int right) {
    // Base case: one or no elements to sort.
    if (right - left <= 1)
        return;
    
    // 1. Build pairs from the subrange.
    std::vector<Container> pairs;
    Container subContainer(container.begin() + left, container.begin() + right);
    buildPairs(subContainer, pairs);
    
    // 2. If more than one pair exists, recursively sort the groups (pairs)
    //    by comparing their first element.
    if (pairs.size() > 1) {
        // Recursively sort the vector of groups (pairs)
        fordJohnsonSortGroups(pairs, 0, pairs.size());
    }
    
    // 3. Build the mainChain and pendChain:
    Container mainChain;
    Container pendChain;
    if (!pairs.empty()) {
        // Start mainChain with first element (b) of the first pair.
        if (!pairs[0].empty())
            mainChain.push_back(pairs[0][0]);
        // If available, append the second element (a) of the first pair.
        if (pairs[0].size() > 1)
            mainChain.push_back(pairs[0][1]);
    }
    // For subsequent pairs, treat the first element as pend (b) and the second as main (a).
    for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].size() == 2) {
            pendChain.push_back(pairs[i][0]); // b
            mainChain.push_back(pairs[i][1]); // a
        } else {
            // In case of an odd leftover, it's a b element.
            pendChain.push_back(pairs[i][0]);
        }
    }
    
    // 4. Insert elements from pendChain into mainChain.
    insertPend(mainChain, pendChain);
    
    // 5. Copy the sorted mainChain back into the original container.
    for (size_t i = 0; i < mainChain.size(); i++) {
        container[left + i] = mainChain[i];
    }
}

template<typename Container>
void PmergeMe::binaryInsert(Container& container, int value, int pos) {
	int i = pos - 1;
	while (i >= 0 && container[i] > value) {
		container[i + 1] = container[i];
		--i;
	}
	container[i + 1] = value;
}

void PmergeMe::sortVec() {
	fordJohnsonSort(_vec, 0, _vec.size());
}

void PmergeMe::sortDeq() {
	fordJohnsonSort(_deq, 0, _deq.size());
}

const std::vector<int>& PmergeMe::getVec() const {
	return _vec;
}

const std::deque<int>& PmergeMe::getDeq() const {
	return _deq;
}

// --------------------------------------------------------------
// Explicit instantiation for template functions used with vector and deque.
// --------------------------------------------------------------

template void PmergeMe::parseInput<std::vector<int> >(std::vector<int>&, char**);
template void PmergeMe::parseInput<std::deque<int> >(std::deque<int>&, char**);

template void PmergeMe::buildPairs<std::vector<int> >(std::vector<int>&, std::vector<std::vector<int> >&);
template void PmergeMe::buildPairs<std::deque<int> >(std::deque<int>&, std::vector<std::deque<int> >&);

template void PmergeMe::insertPend<std::vector<int> >(std::vector<int>&, const std::vector<int>&);
template void PmergeMe::insertPend<std::deque<int> >(std::deque<int>&, const std::deque<int>&);

template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int>&, int, int);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int>&, int, int);
