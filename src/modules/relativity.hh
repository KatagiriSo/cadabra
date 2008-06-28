/* 

   $Id: relativity.hh,v 1.22 2007/03/09 00:23:56 peekas Exp $

	Cadabra: an extendable open-source symbolic tensor algebra system.
	Copyright (C) 2001-2006  Kasper Peeters <kasper.peeters@aei.mpg.de>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, version 2.
	 
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
	
*/

#ifndef relativity_hh_
#define relativity_hh_

#include <string>
#include "algorithm.hh"
#include "props.hh"
#include "algebra.hh"
#include "dummies.hh"

/// General relativity and curved geometry
namespace relativity {
	void register_properties();
};

class Metric : public TableauSymmetry, virtual public property {
	public:
		Metric();
		virtual std::string name() const;
		virtual bool        parse(exptree&, exptree::iterator, exptree::iterator, keyval_t&);

		int signature;
};

class InverseMetric : public TableauSymmetry, virtual public property {
	public:
		InverseMetric();
		virtual std::string name() const;
		virtual bool        parse(exptree&, exptree::iterator, exptree::iterator, keyval_t&);
};

class WeylTensor : public TableauSymmetry, public Traceless, virtual public property {
	public:
		WeylTensor();
		virtual std::string name() const;
		virtual bool        parse(exptree&, exptree::iterator, exptree::iterator, keyval_t&);
		virtual void        display(std::ostream&) const;
};

class Vielbein : virtual public property {
	public:
		virtual std::string name() const;
};

class InverseVielbein : virtual public property {
	public:
		virtual std::string name() const;
};

class RiemannTensor : public TableauSymmetry, virtual public property {
	public:
		RiemannTensor();
		virtual std::string name() const;
		virtual bool        parse(exptree&, exptree::iterator, exptree::iterator, keyval_t&);
};

class eliminate_vielbein : public algorithm {
	public:
		eliminate_vielbein(exptree&, iterator);
		
		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class eliminate_metric : public algorithm {
	public:
		eliminate_metric(exptree&, iterator);
		
		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class rewrite_indices : public algorithm {
	public:
		rewrite_indices(exptree&, iterator);

		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class ricci_identity : public algorithm {
	public:
		ricci_identity(exptree&, iterator);
		
		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class weyl_index_order : public algorithm {
	public:
		weyl_index_order(exptree&, iterator);

		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class riemann_index_regroup : public algorithm {
	public:
		riemann_index_regroup(exptree&, iterator it);
		
		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class remove_weyl_traces : public algorithm {
	public:
		remove_weyl_traces(exptree&, iterator it);

		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
};

class split_index : public algorithm {
	public:
		split_index(exptree&, iterator it);

		virtual void     description() const;
		virtual bool     can_apply(iterator);
		virtual result_t apply(iterator&);
	private:
		const Indices *full_class, *part1_class, *part2_class;
		bool     part1_is_number, part2_is_number;
		long     num1, num2;
};

#endif
