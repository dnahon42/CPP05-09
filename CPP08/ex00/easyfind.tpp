/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:30:23 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 14:57:22 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void easyfind(const T &container, int n)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NumberNotFoundException();
	std::cout << "The number : " << n << " is in the container" << std::endl;
}