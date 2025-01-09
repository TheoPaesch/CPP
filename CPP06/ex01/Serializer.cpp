/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:35:19 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 18:49:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Private constructors make the class non-initializable by the user
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(const Serializer &) { return *this; }
Serializer::~Serializer() {}

// Static method: convert pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Static method: convert uintptr_t back to pointer
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}