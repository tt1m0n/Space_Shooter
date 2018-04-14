/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenElement.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/29 16:35:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCREENELEMENT_HPP
#define ASCREENELEMENT_HPP

class AScreenElement {
public:
// ------------------------------- Coplien Form ----------------------------- //

	AScreenElement();
	AScreenElement(int x, int y);
	virtual ~AScreenElement();
	AScreenElement &operator= (const AScreenElement &element);

// ------------------------------------------------------------------------- //
// ------------------------------- Constructor ----------------------------- //

	AScreenElement (const AScreenElement &element);

// ------------------------------------------------------------------------- //
// --------------------------- Member Function ----------------------------- //

	int				getX () 	const;
	int 			getY ()	const;
	int 			getMinX ()	const;
	int 			getMinY ()	const;
	int 			getMaxX ()	const;
	int 			getMaxY ()	const;
	virtual bool	collision (AScreenElement *element);
	virtual bool 	move () = 0;
	virtual void	printElement () const = 0;

// ------------------------------------------------------------------------- //	

protected:
	int 			x_;
	int 			y_;
	int 			minX_;
	int 			minY_;
	int				maxX_;
	int 			maxY_;
};

#endif
