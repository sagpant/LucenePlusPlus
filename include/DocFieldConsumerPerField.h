/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LuceneObject.h"

namespace Lucene
{
	class LPPAPI DocFieldConsumerPerField : public LuceneObject
	{
	public:
		virtual ~DocFieldConsumerPerField();
		
		LUCENE_CLASS(DocFieldConsumerPerField);
	
	public:
		/// Processes all occurrences of a single field
		virtual void processFields(Collection<FieldablePtr> fields, int32_t count) = 0;
		
		virtual void abort() = 0;
	};
}
