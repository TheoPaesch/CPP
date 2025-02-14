/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:07:39 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/14 18:07:18 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <set>
#include <stdexcept>
#include <climits>

class PmergeMe {
public:
	PmergeMe() = default;
	~PmergeMe() = default;

	void parseInputVec(char** input);
	void parseInputDeq(char** input);

	void sortVec();
	void sortDeq();

	const std::vector<int>& getVec() const;
	const std::deque<int>& getDeq() const;

private:
	template<typename Container>
	void parseInput(Container& container, char** input);

	template<typename Container>
	static void buildPairs(Container& container, std::vector<Container>& pairs);

	template<typename Container>
	void fordJohnsonSort(Container& container, int left, int right);

	template<typename Container>
	static void insertPend(Container& mainChain, const Container& pendChain);

	template<typename Container>
	void binaryInsert(Container& container, int value, int pos);

	std::vector<int> _vec;
	std::deque<int> _deq;
};

#endif