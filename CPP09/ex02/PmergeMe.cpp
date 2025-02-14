/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:33 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/12 14:30:13 by tpaesch          ###   ########.fr       */
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
        if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
            throw std::invalid_argument("Each input must be a positive integer and unique.");
        }
        if (!seenNumbers.insert(static_cast<int>(val)).second) {
            throw std::invalid_argument("Duplicate numbers are not allowed.");
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

// Core Ford-Johnson (merge-insertion) sorting steps (simplified).
template<typename Container>
void PmergeMe::fordJohnsonSort(Container& container, int left, int right) {
    // If the range is too small, nothing to do
    if (right - left <= 1)
        return;

    // 1. Split into pairs (b, a) recursively
    //    For brevity, we operate on the whole container here.
    std::vector<Container> pairs;
    Container subContainer(container.begin() + left, container.begin() + right);
    buildPairs(subContainer, pairs);

    // 2. Recursively sort higher-level pairs if possible (pairs of pairs, etc.)
    //    In a more complete solution, you'd group pairs again and call
    //    fordJohnsonSort on those subgroups. This is a simplified placeholder.
    //    For example:
    //    if (pairs.size() > 1) {
    //        // Create larger "pairs of pairs" and recurse
    //    }

    // 3. Build main (first b and all a's) and pend (remaining b's)
    Container mainChain;
    Container pendChain;
    // For simplicity, assume pairs[0] is b1, a1; others are b2.., a2.. etc.
    if (!pairs.empty()) {
        // mainChain starts with b1
        if (!pairs[0].empty())
            mainChain.push_back(pairs[0][0]);
        // also add a1 if it exists
        if (pairs[0].size() > 1)
            mainChain.push_back(pairs[0][1]);
    }

    // fill mainChain with all other 'a' and pendChain with all other 'b'
    for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].size() == 2) {
            // (b, a) both exist
            pendChain.push_back(pairs[i][0]); // b
            mainChain.push_back(pairs[i][1]); // a
        } else {
            // odd leftover case: treat as b alone
            pendChain.push_back(pairs[i][0]);
        }
    }

    // 4. Insert pend elements into main using the special approach:
    //    - Possibly use Jacobsthal-based ordering
    //    - Bound comparisons with known 'a' elements
    insertPend(mainChain, pendChain);

    // 5. Copy sorted result back into container
    //    The final mainChain should be in ascending order if the full steps
    //    (including deeper recursion) are done.
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
