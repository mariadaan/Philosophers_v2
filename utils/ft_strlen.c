/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:12 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/14 14:25:10 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Description:
**	The strlen() function computes the length of the string s.
**
**	Returns:
**	number of characters in string, excluding the terminating NULL character
*/

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
